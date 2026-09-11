[CmdletBinding(SupportsShouldProcess = $true, ConfirmImpact = 'Medium')]
param()

Set-StrictMode -Version Latest
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
    param([Parameter(Mandatory = $true)][string]$Path)

    return @(Get-ChildItem -LiteralPath $Path -File -Force |
        Where-Object { $_.Name -notlike '*.cecfg.bak*' })
}

function Replace-ByteSequence {
    param(
        [Parameter(Mandatory = $true)][byte[]]$Bytes,
        [Parameter(Mandatory = $true)][byte[]]$Search,
        [Parameter(Mandatory = $true)][byte[]]$Replacement
    )

    $matchIndex = -1
    for ($i = 0; $i -le $Bytes.Length - $Search.Length; $i++) {
        $matches = $true
        for ($j = 0; $j -lt $Search.Length; $j++) {
            if ($Bytes[$i + $j] -ne $Search[$j]) {
                $matches = $false
                break
            }
        }
        if ($matches) {
            $matchIndex = $i
            break
        }
    }

    if ($matchIndex -lt 0) {
        throw 'The expected CEv2 fingerprint was not found in the source Lua file.'
    }

    $result = New-Object byte[] ($Bytes.Length - $Search.Length + $Replacement.Length)
    [Array]::Copy($Bytes, 0, $result, 0, $matchIndex)
    [Array]::Copy($Replacement, 0, $result, $matchIndex, $Replacement.Length)
    [Array]::Copy(
        $Bytes,
        $matchIndex + $Search.Length,
        $result,
        $matchIndex + $Replacement.Length,
        $Bytes.Length - $matchIndex - $Search.Length
    )
    return $result
}

$sourceDefaults = Get-FullPath $PSScriptRoot
$targetDefaults = Join-Path $sourceDefaults 'macev2'
$maceFingerprint = '--BigNubCow111'
$ceFingerprint = '--BigNubCow101'

Assert-Directory $sourceDefaults 'CEv2 defaults directory'
Assert-Directory $targetDefaults 'MaCEv2 defaults directory'

$ceFingerprintPath = Join-Path $sourceDefaults 'bot.conquest_configuration.lua'
$maceFingerprintPath = Join-Path $targetDefaults 'bot.conquest_configuration.lua'
if (-not (Test-Path -LiteralPath $ceFingerprintPath -PathType Leaf)) {
    throw "The CEv2 fingerprint source is missing: $ceFingerprintPath. No files were changed."
}
if (-not (Test-Path -LiteralPath $maceFingerprintPath -PathType Leaf)) {
    throw "The MaCEv2 fingerprint target is missing: $maceFingerprintPath. No files were changed."
}

$ceFingerprintText = [System.IO.File]::ReadAllText($ceFingerprintPath)
if (-not $ceFingerprintText.Contains($ceFingerprint)) {
    throw "The CEv2 fingerprint source must contain '$ceFingerprint': $ceFingerprintPath. No files were changed."
}
if ($ceFingerprintText.Contains($maceFingerprint)) {
    throw "The CEv2 fingerprint source is invalid because it contains '$maceFingerprint' instead of only '$ceFingerprint': $ceFingerprintPath. No files were changed."
}

$maceFingerprintText = [System.IO.File]::ReadAllText($maceFingerprintPath)
if (-not $maceFingerprintText.Contains($maceFingerprint)) {
    throw "The existing MaCEv2 fingerprint target must contain '$maceFingerprint': $maceFingerprintPath. No files were changed."
}

# The files already in the MaCEv2 folder are the complete list we will
# refresh. Check the whole list before changing anything.
$sourceFiles = @(Get-DefaultFiles $sourceDefaults)
$targetFiles = @(Get-DefaultFiles $targetDefaults)
$sourceByName = @{}
$targetNames = @{}

foreach ($file in $sourceFiles) {
    $sourceByName[$file.Name] = $file
}
foreach ($file in $targetFiles) {
    $targetNames[$file.Name] = $true
    if (-not $sourceByName.ContainsKey($file.Name)) {
        throw "The whitelisted MaCEv2 default '$($file.Name)' has no corresponding direct CEv2 default in $sourceDefaults. No files were changed."
    }
}

$plan = @(
    foreach ($targetFile in $targetFiles) {
        [PSCustomObject]@{
            Source = $sourceByName[$targetFile.Name].FullName
            Target = $targetFile.FullName
            Name = $targetFile.Name
            UpdatedBytes = $null
        }
    }
)

# Check and prepare the special fingerprint file first. If it cannot be kept
# safely, stop before changing any other file.
foreach ($item in $plan) {
    if ($item.Name -ieq 'bot.conquest_configuration.lua') {
        $existingMaceText = [System.IO.File]::ReadAllText($item.Target)
        if (-not $existingMaceText.Contains($maceFingerprint)) {
            throw "The existing whitelisted MaCEv2 file does not contain '$maceFingerprint': $($item.Target). No files were changed."
        }

        $sourceBytes = [System.IO.File]::ReadAllBytes($item.Source)
        $sourceText = [System.Text.Encoding]::UTF8.GetString($sourceBytes)
        if ($sourceText.Contains($maceFingerprint)) {
            throw "The CEv2 fingerprint source is invalid because it contains '$maceFingerprint': $($item.Source). No files were changed."
        }
        if (-not $sourceText.Contains($ceFingerprint)) {
            throw "The CEv2 source '$($item.Source)' does not contain the required '$ceFingerprint' fingerprint. No files were changed."
        }
        $item.UpdatedBytes = Replace-ByteSequence `
            -Bytes $sourceBytes `
            -Search ([System.Text.Encoding]::ASCII.GetBytes($ceFingerprint)) `
            -Replacement ([System.Text.Encoding]::ASCII.GetBytes($maceFingerprint))
    }
}

foreach ($item in $plan) {
    if (-not $PSCmdlet.ShouldProcess($item.Target, "Refresh whitelisted MaCEv2 default from $($item.Source)")) {
        continue
    }

    if ($item.Name -ieq 'bot.conquest_configuration.lua') {
        [System.IO.File]::WriteAllBytes($item.Target, $item.UpdatedBytes)
        Write-Host "Updated with MaCEv2 fingerprint preserved: $($item.Target)"
    }
    else {
        Copy-Item -LiteralPath $item.Source -Destination $item.Target -Force
        Write-Host "Updated: $($item.Target)"
    }
}

$maceDefaultFingerprintPath = Join-Path $targetDefaults 'bot.conquest_configuration.lua'
$maceDefaultFingerprintText = [System.IO.File]::ReadAllText($maceDefaultFingerprintPath)
if (-not $maceDefaultFingerprintText.Contains($maceFingerprint)) {
    throw "MaCEv2 fingerprint invariant failed in $maceDefaultFingerprintPath"
}

$extraSourceFiles = @($sourceFiles | Where-Object { -not $targetNames.ContainsKey($_.Name) })
if ($extraSourceFiles.Count -gt 0) {
    Write-Host "Ignored CEv2 files outside the MaCEv2 target whitelist: $($extraSourceFiles.Name -join ', ')"
}

$ignoredDirectories = @(Get-ChildItem -LiteralPath $sourceDefaults -Directory -Force)
if ($ignoredDirectories.Count -gt 0) {
    Write-Host "Ignored CEv2 source subdirectories: $($ignoredDirectories.Name -join ', ')"
}

Write-Host 'Whitelisted MaCEv2 default refresh complete. No files were added or removed.'
