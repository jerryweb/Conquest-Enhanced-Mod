[CmdletBinding(SupportsShouldProcess = $true, ConfirmImpact = 'Medium')]
param()

Set-StrictMode -Version Latest
    # Set-Mode I fucking hate powershell
$ErrorActionPreference = 'Stop'

function Get-FullPath {
    param([Parameter(Mandatory = $true)][string]$Path)

    return [System.IO.Path]::GetFullPath($Path)
}

function Assert-Directory {
    param(
        [Parameter(Mandatory = $true)][string]$Path,
        [Parameter(Mandatory = $true)][string]$Label
    )

    if (-not (Test-Path -LiteralPath $Path -PathType Container)) {
        throw "$Label does not exist or is not a directory: $Path"
    }
}

function Get-DefaultFiles {
    param(
        [Parameter(Mandatory = $true)][string]$Path,
        [switch]$ExcludePowerShell
    )

    # Old backup copies are ignored here. They are safety copies, not live
    # defaults that should be refreshed.
    return @(Get-ChildItem -LiteralPath $Path -File -Force |
        Where-Object {
            $_.Name -notlike '*.cecfg.bak*' -and
            (-not $ExcludePowerShell -or $_.Extension -ine '.ps1')
        })
}

$target = Get-FullPath $PSScriptRoot
$modRoot = Get-FullPath (Join-Path $PSScriptRoot '..\..\..\..')
$resourceRoot = Join-Path $modRoot 'resource'
Assert-Directory $target 'CEv2 defaults directory'
Assert-Directory $resourceRoot 'Real source resource directory'

# The files already in this folder are the complete list we will refresh.
# Their current versions live in the normal resource folders below.
$sourceDirectories = @(
    (Join-Path $resourceRoot 'set\dynamic_campaign'),
    (Join-Path $resourceRoot 'set\multiplayer\games'),
    (Join-Path $resourceRoot 'set\multiplayer\games\presets'),
    (Join-Path $resourceRoot 'set'),
    (Join-Path $resourceRoot 'conquest_configuration')
)

# Look up each filename in these folders only. We do not search their
# subfolders.
$sourceByName = @{}
foreach ($sourceDirectory in $sourceDirectories) {
    if (-not (Test-Path -LiteralPath $sourceDirectory -PathType Container)) {
        continue
    }

    foreach ($file in @(Get-ChildItem -LiteralPath $sourceDirectory -File -Force |
        Where-Object { $_.Name -notlike '*.cecfg.bak*' })) {
        if (-not $sourceByName.ContainsKey($file.Name)) {
            $sourceByName[$file.Name] = @()
        }
        $sourceByName[$file.Name] = @($sourceByName[$file.Name]) + $file
    }
}

$targetFiles = @(Get-DefaultFiles -Path $target -ExcludePowerShell)
$plan = @(
    foreach ($targetFile in $targetFiles) {
        $candidates = @()
        if ($sourceByName.ContainsKey($targetFile.Name)) {
            $candidates = @($sourceByName[$targetFile.Name])
        }

        if ($candidates.Count -eq 0) {
            [PSCustomObject]@{
                Status = 'SKIP_NO_SOURCE'
                Name = $targetFile.Name
                Source = $null
                Target = $targetFile.FullName
                Detail = 'no source found'
            }
            continue
        }

        if ($candidates.Count -gt 1) {
            [PSCustomObject]@{
                Status = 'SKIP_AMBIGUOUS'
                Name = $targetFile.Name
                Source = $null
                Target = $targetFile.FullName
                Detail = "ambiguous source: $($candidates.Count) matches"
            }
            continue
        }

        [PSCustomObject]@{
            Status = 'UPDATE'
            Name = $targetFile.Name
            Source = $candidates[0].FullName
            Target = $targetFile.FullName
            Detail = $null
        }
    }
)

Write-Host 'Plan:'
foreach ($item in $plan) {
    if ($item.Status -eq 'UPDATE') {
        Write-Host "UPDATE: $($item.Name) <- $($item.Source)"
    }
    else {
        Write-Host "$($item.Status): $($item.Name) ($($item.Detail))"
    }
}

$updated = 0
$skippedNoSource = @($plan | Where-Object { $_.Status -eq 'SKIP_NO_SOURCE' }).Count
$skippedAmbiguous = @($plan | Where-Object { $_.Status -eq 'SKIP_AMBIGUOUS' }).Count

foreach ($item in $plan | Where-Object { $_.Status -eq 'UPDATE' }) {
    if ($PSCmdlet.ShouldProcess($item.Target, "Refresh default from $($item.Source)")) {
        Copy-Item -LiteralPath $item.Source -Destination $item.Target -Force
        $updated++
    }
}

if ($WhatIfPreference) {
    Write-Host "Summary (WhatIf): Would update: $(@($plan | Where-Object { $_.Status -eq 'UPDATE' }).Count)"
    Write-Host "Skipped (no source): $skippedNoSource"
    Write-Host "Skipped (ambiguous): $skippedAmbiguous"
}
else {
    Write-Host "Summary: Updated: $updated"
    Write-Host "Skipped (no source): $skippedNoSource"
    Write-Host "Skipped (ambiguous): $skippedAmbiguous"
}

Write-Host 'Whitelisted default refresh complete, Cowboy. No files were added or removed.'
