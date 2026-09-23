# Unit Roster Schema Notes

## Purpose

Document the Lua bot unit roster schema used by the Conquest AI purchase logic.

This is **not** the same as the scene-query `.def` prop schema.

- **Scene-query schema** is a compressed battlefield-pressure readout of the player's current force.
- **Bot unit roster schema** is metadata used by the AI purchase planner to decide what the bot can buy and why it should buy it.

A unit can have several roster tags because the purchase system can evaluate multiple axes:

- Platform / family
- Rough class / size tier
- Combat role
- Tactical posture
- Special effects
- Faction flavor identity
- Quality grade
- Mobility

<br>
<br>
<br>

## Core Tagging Principles

Use tags to describe **why the bot should buy the unit**.

Do not tag every technical capability a unit has. Tags should represent purchase-relevant identity.

Effects should be signal, not noise.

Availability is a separate balancing knob from grade.

Use grade to say how good/desirable the unit is within its purchase pool.

Use availability to control how often it appears or how common it should be.

Do not use grade alone to represent rarity.

A rare but mediocre unit should not automatically be `Grade4`.

A common but strong unit can still be `Grade3`/`Grade4` if it is genuinely strong in its pool.

### Example

A normal rifle squad should not get:

```lua
effects = { "VsInfantry" }
```

just because it can fight infantry.

That would make `VsInfantry` noisy.

Reserve `VsInfantry` for units unusually good at killing infantry relative to similar units.

<br>
<br>
<br>

## General Entry Shape

Typical roster entry fields:

```lua
{
    availability = "number",
    base = { ... },
    class = { ... },
    grade = "GradeX",
    posture = { ... },
    roles = { ... },
    effects = { ... },
    mobility = { ... },
    identity = { ... },
    name = "unit_name",
}
```

Not every field is required for every unit.

Empty tables are acceptable where the unit has no useful tag for that axis.

<br>

---

<br>
<br>
<br>


# Field Reference

## Conversion: 'Priority' to 'Availability'

Priority has been converted to Availability. Here is the conversion chart used

| Old `priority` | New `availability` |
|---|---|
| `0.1` | `"1.6"` |
| `0.5` | `"1.5"` |
| `1.0` | `"1.4"` |
| `1.5` | `"1.3"` |
| `2.0` | `"1.2"` |
| `2.5` | `"1.1"` |
| `3.0` | `"1.0"` |
| `3.5` | `"0.9"` |


### `availability`

Use availability to control how often a unit appears or how common it should be.

Availability is a separate balancing knob from grade.

Do not use grade alone to represent rarity.

<br>

## `base`

Broad purchase family / platform category.

### Common Values

- `Squad`
- `Single`
- `Infantry`
- `Cannon`
- `Vehicle`
- `Tank`
- `SPG`

### Notes

- Squads use `base = { "Squad", "Infantry" }`.
- Individual and small team infantry/support use `base = { "Single", "Infantry" }`.
- Towed guns use `Cannon`.
- Tanks use `Tank`.
- Tank destroyers / assault guns / self-propelled guns generally use `SPG` when the roster treats them as self-propelled gun platforms.
- Cars, trucks, halftracks, armored cars, carriers, and similar platforms generally use `Vehicle`.

<br>

## `class`

Unit family / rough size or weight tier inside the base category.

### Values

- `Light`
- `Medium`
- `Heavy`

### Examples

- A vehicle in a historical "light tank" family may be `Light`.
- A Valentine may be treated as `Medium` because, in purchase terms, it belongs with medium armor options.
- A T-35 can remain in a `Heavy` family even if its actual armor threat is not impressive.

<br>


## `roles`

The jobs the unit can perform for the purchase planner.

### Common Values

- `Line`
- `Assault`
- `Recon`
- `AntiTank`
- `MG`
- `Mortar`
- `InfantryGun`
- `FieldGun`
- `Artillery`
- `AirDefense`
- `Breakthrough`
- `Transport`
- `Unarmed`
- `Supply`

### Notes

- Roles should represent purchase jobs.
- Do not over-tag. Use one role in most cases.
- The current purchase classifier can derive secondary purchase intent from a single authored role. Example: `FieldGun` classifies as primary `AntiArmor` and secondary `DirectFire`.
- Do not add extra roles just to describe every technical capability. Add another role only if the roster and classifier explicitly support that multi-role case and the extra role is a defining purchase reason.

<br>

## Purchase Classifier Intent Mapping

Roster roles are authored as unit metadata. The purchase classifier turns those tags into higher-level purchase buckets. Current bucket meanings:

| Classifier Bucket | Main Source Tags | Meaning |
|---|---|---|
| `InfantryLine` | `Line` infantry squads | General-purpose infantry squads used to hold ground, attack objectives, and form the body of infantry forces. |
| `Assault` | `Assault` infantry, flame vehicles, flame tanks | Close-range offensive pressure / objective-clearing tools. Flame tanks remain armor-primary in classifier output, with `Assault` as secondary intent. |
| `Recon` | `Recon` infantry, snipers, scout cars, armored cars, recon tanks | Scouting, probing, forward pressure, or recon-family flavor. Not a strict historical force-structure rule. |
| `InfantryAT` | `AntiTank` infantry singles/squads | Infantry-carried anti-vehicle / anti-armor capability. Also contributes to broader `AntiArmor`. |
| `MachineGun` | `MG` weapons/vehicles | Sustained small-arms suppression platforms. |
| `DirectFire` | `InfantryGun` | Direct HE / infantry-support weapons, support SPGs, CS/howitzer tanks, AVRE-style vehicles. |
| `AntiArmor` | `AntiTank`, `FieldGun`, infantry AT as secondary | Units the bot can buy as answers to enemy vehicles or armor. |
| `Armor` | Tank base with no overriding special role | General-purpose tank combat power. |
| `IndirectFire` | `Mortar`, `Artillery` | Mortars and artillery whose main purpose is arcing HE fire. |
| `AirDefense` | `AirDefense` | Dedicated AA / SPAA. Heavy dual-role AA/AT guns may classify primary `AntiArmor`, secondary `AirDefense`. |

`Other` is not intended as a real purchase bucket. Units with no current AI purchase purpose should be removed/commented from bot rosters until behavior exists for them.

<br>


## `posture`

Tactical purchase bias.

### Common Values

- `Flexible`
- `Offensive`
- `Defensive`

### Meaning

Posture does not mean the unit can only attack or only defend. Most units can do both.

It means which purchase plan should prefer this unit.

<br>

## `effects`

What the unit is unusually good against relative to similar units.

### Common Values

- `VsInfantry`
- `VsVehicle`
- `VsArmor`

### Important

Do not use effects as universal capability tags.

Effects should be signal, not noise.

Use `VsArmor` for units meaningfully able to answer actual armor, not just scratch light vehicles.

### Examples

- Normal rifle squad: `effects = {}`
- SMG / assault squad: `effects = { "VsInfantry" }`
- AT rifle squad: `effects = { "VsVehicle" }` or `effects = { "VsVehicle", "VsArmor" }`
- Dedicated AT gun: `effects = { "VsVehicle", "VsArmor" }`
- HE support gun: `effects = { "VsInfantry" }`
- Autocannon / light AA gun: effects may include `VsInfantry` and/or `VsVehicle` depending roster convention

<br>

## `mobility`

Optional movement / delivery tag for infantry squads whose purchase identity includes being delivered by a vehicle.

### Known Values

- `Motorized`
- `Mechanized`

### Meaning

Use `Motorized` for infantry squads delivered by unarmored or lightly protected wheeled transport such as trucks, jeeps, cars, or similar soft-skin vehicles.

Use `Mechanized` for infantry squads delivered by armored transport such as halftracks, armored personnel carriers, armored carriers, or similar protected troop vehicles.

Do not use `Vehicle` as the base for these squads. The squad remains the main purchase identity:

```lua
base = { "Squad", "Infantry" }
mobility = { "Motorized" } -- soft-skin / unarmored transport

base = { "Squad", "Infantry" }
mobility = { "Mechanized" } -- armored transport / halftrack / carrier
```

<br>


## `identity`

Faction/flavor/formation identity.

### Known Values in Soviet Roster

- `Guards`
- `NKVD`
- `Partisan`

Use identity for flavor or force-pool selection, not for combat role.

### Examples

```lua
identity = { "Guards" }
identity = { "NKVD" }
identity = { "Partisan" }
```

<br>

## `grade`

Purchase-quality tier within the unit's purchase competition pool.

### Values

- `Grade1`
- `Grade2`
- `Grade3`
- `Grade4`

### Core Rule

`grade` = quality within the unit's purchase job pool.

Do not grade every unit against every other unit in the game.

Do not grade a tank against an artillery piece.

Do not grade a towed AT gun directly against a tank destroyer unless they are truly competing for the same purchase slot.

### Useful Comparison Key

```text
base + primary role + class
```

### Examples of Grade Pools

- Infantry line squads
- Infantry assault squads
- Infantry AT squads
- Towed AT cannons
- Towed HE / mortar / artillery cannons
- AA / autocannon support weapons
- Armored cars / recon vehicles
- Light tanks
- Medium tanks
- Heavy tanks
- AT SPGs / tank destroyers
- HE SPGs / assault guns
- Support trucks / ammo / engineer units

### Grade Meanings

| Grade | Meaning |
|---|---|
| `Grade1` | Weak / obsolete / cheap / stopgap option within its pool |
| `Grade2` | Standard useful option within its pool |
| `Grade3` | Strong / improved / above-average option within its pool |
| `Grade4` | Premium / elite / top-tier option within its pool |

A `Grade4` light tank does not mean it is equal to a `Grade4` heavy tank.

It means it is a premium light tank within the light tank purchase pool.


<br>

---

<br>
<br>
<br>

# Infantry Tagging Guide

## Infantry Squad Roles

Most infantry squads should have exactly one of:

- `Line`
- `Assault`
- `Recon`
- `AntiTank`

Only use multiple roles when the dual purpose is a defining purchase reason.

Do not use these roles on normal infantry squads:

- `MG`
- `Mortar`
- `InfantryGun`
- `FieldGun`
- `AirDefense`
- `Artillery`

Those are for actual weapon teams, cannons, or vehicles, not squads that merely contain a supporting weapon.

<br>

## Infantry Squad Default

```lua
base = { "Squad", "Infantry" }
roles = { "Line" }
posture = { "Flexible" }
effects = {}
```

<br>


## `Line`

Use `Line` for general-purpose infantry mass. `Line` does not mean weak or basic; it means the squad's main purchase job is ordinary combat infantry rather than assault, recon, or anti-tank specialization.

Examples:

- Regular rifle squads
- Defensive / rear-echelon squads
- Veteran or elite rifle squads
- General-purpose guards / marine / mountain / airborne rifle squads
- Engineer or pioneer squads whose in-game loadout is still mostly general combat infantry

<br>


## `Assault`

Use `Assault` for close-range pushing or clearing:

- SMG squads
- Assault engineers
- Shock troops
- Flamethrower-heavy squads
- Explosive/satchel assault squads

<br>


## `Recon`

Use `Recon` for recon-focused / sniper squads:

- Sniper detachments
- Recon squads
- Pathfinder / scout-style squads

Recon is a gameplay purchase identity. It does not require strict historical force-structure modeling.

<br>


## `AntiTank`

Use `AntiTank` only when the squad's main purchase reason is anti-vehicle / anti-armor capability:

- AT rifle squads
- Dedicated late AT infantry
- Bazooka / PIAT / panzerschreck-style squads

If a squad has one weak AT tool but is mostly ordinary infantry, prefer `Line` and maybe no effect, rather than `AntiTank`.

<br>


## Infantry Posture Rules

Default for most infantry squads:

- `Flexible`

Use `Offensive` for units clearly biased toward pushing or close assault:

- SMG squads
- Assault engineers
- Flamethrowers
- Shock troops
- Close-combat elites

Use `Defensive` for units clearly biased toward holding, ambush, or static support:

- AT infantry
- Dedicated defensive weapon teams
- Cheap holding troops, not intended to push

<br>


## Infantry Effects Rules

- Normal rifle squad: `effects = {}`
- SMG / assault squad: `effects = { "VsInfantry" }`
- AT rifle squad: `effects = { "VsVehicle" }` or `effects = { "VsVehicle", "VsArmor" }`

<br>


## Infantry Grade Rule

Infantry can mostly follow the game's designed infantry tier system:

| Infantry Tier | Grade |
|---|---|
| T1 infantry | `Grade1` |
| T2 infantry | `Grade2` |
| T2+ / veteran T2 | `Grade3` |
| T3 infantry | `Grade3` |
| T3+ / veteran T3 | `Grade4` |
| T4 infantry | `Grade4` |

Infantry grade is mostly based on intended tier, health, weapon skill, and veteran status.

Equipment can modify the decision, but should not override the designed tier unless it strongly changes the squad's purchase identity.

<br>


## Mobility Rule

Do **not** use `Vehicle` for infantry squads that arrive in a transport. The squad is still the main purchase identity.

Use this instead:

```lua
base = { "Squad", "Infantry" }
mobility = { "Motorized" } -- soft-skin / unarmored transport

base = { "Squad", "Infantry" }
mobility = { "Mechanized" } -- armored transport / halftrack / carrier
```

<br>

# Infantry Squad Assignment Summary

## Default Normal Squad

```lua
base = { "Squad", "Infantry" }
roles = { "Line" }
posture = { "Flexible" }
effects = {}
```

## Assault Squad

```lua
base = { "Squad", "Infantry" }
roles = { "Assault" }
posture = { "Offensive" }
effects = { "VsInfantry" } -- only if close-combat/anti-infantry specialized
```

## Recon Squad

```lua
base = { "Squad", "Infantry" }
roles = { "Recon" }
posture = { "Flexible" }
effects = {}
```

## Dedicated AT Infantry Squad

```lua
base = { "Squad", "Infantry" }
roles = { "AntiTank" }
posture = { "Defensive" }
effects = { "VsVehicle" } or { "VsVehicle", "VsArmor" }
```

<br>

---

<br>
<br>
<br>

# Vehicle and Gun Tagging Guide

This section covers non-infantry purchases: towed weapons, utility vehicles, scout vehicles, tanks, SPGs, self-propelled AA, self-propelled artillery, assault guns, and tank destroyers.

The same core rule still applies:

```text
base = what broad purchase family this unit belongs to
class = rough size / purchase tier inside that family
roles = why the bot should deliberately buy it
effects = what it is unusually useful against
```

Do not classify vehicles only by historical naming. Use the classification that best matches how the AI should buy the unit.

<br>

## Base Selection

### `Cannon`

Use `Cannon` for towed or static gun-style weapons.

Examples:

- HMGs / mounted MGs
- AT guns
- infantry guns
- field guns
- AA guns
- mortars
- artillery / rocket artillery

```lua
base = { "Cannon" }
```

<br>

### `Vehicle`

Use `Vehicle` when the unit's purchase identity is mainly mobility, scouting, transport, utility, or light weapons.

Examples:

- Cars / jeeps / motorcycles
- Trucks
- Halftracks / carriers
- Scout cars / armored cars
- Light utility or transport vehicles

```lua
base = { "Vehicle" }
```

Do **not** use `Vehicle` for infantry squads that arrive in a transport. The squad is still the main purchase identity.


<br>

### `Tank`

Use `Tank` for turreted combat tanks that should consume tank/armor purchase space.

Examples:

- Light tanks
- Medium tanks
- Heavy tanks
- Flame tanks on tank chassis
- MG-only turreted tanks, if they are still treated as tanks in the roster

```lua
base = { "Tank" }
```

Do not move every weak or MG-only historical tank to `Vehicle` automatically. Use `Vehicle` only when the unit is better understood as a tankette / carrier / light utility platform for AI buying.

<br>

### `SPG`

Use `SPG` for self-propelled dedicated weapon platforms where the mounted weapon is the main purchase reason but with a fully tracked / tank chassis

Examples:

- Tank destroyers
- Assault guns
- Self-propelled artillery
- Self-propelled Rocket artillery
- Self-propelled AA

```lua
base = { "SPG" }
```

Examples:

```text
wirbelwind           -> SPG + AirDefense
marder 3 m           -> SPG + AntiTank
t60 bm8 24           -> SPG + Artillery
stug 3 b             -> SPG + InfantryGun
```

<br>

## Base Selection Examples

```text
Generic MG halftrack:
  base = Vehicle
  roles = MG

Recon armored car:
  base = Vehicle
  roles = Recon, maybe MG

AA halftrack / AA truck:
  base = Vehicle
  roles = AirDefense

AT gun halftrack:
  base = Vehicle
  roles = AntiTank

Rocket halftrack:
  base = Vehicle
  roles = Artillery

Assault gun / StuG-style platform:
  base = SPG
  roles = InfantryGun / AntiTank depending weapon and intended use

Turreted tank:
  base = Tank
  roles = usually empty unless it has a special purchase identity
```

<br>

## Class Selection

Class is always relative to the unit's purchase pool. It is not a universal power rating.
 

### For `Cannon`

For towed guns, `class` is based on weapon size / impact **inside that role**.

Examples:

```text
MG / low-caliber autocannon AA:
  usually Light

Larger autocannon / medium AA:
  usually Medium

Large AA / heavy AT / very heavy artillery:
  usually Heavy
```

Role-specific examples:

```text
AT guns:
  37-45mm class guns        -> Light
  stronger mid-war AT guns  -> Medium
  heavy late AT guns        -> Heavy

Artillery:
  <150mm caliber/older field guns    -> Light
  ~150mm caliber artillery           -> Medium
  >150mm caliber/siege/large rockets -> Heavy

Infantry guns:
  75-76mm infantry guns     -> Light
  mid-tier support guns     -> Medium
  150mm infantry guns       -> Heavy
```

Not every role pool requires all three classes. Some rosters may have no true medium infantry gun, for example.

<br>

### For `Vehicle`

For generic vehicles, class is mostly platform/chassis size.

#### Cars / armored cars

```text
Light:
  motorcycles, cars, jeeps, Kübelwagen-style vehicles, light scout cars, light armored cars

Medium:
  heavy armored cars / larger scout cars, such as Sd.Kfz. 231 / 234-style vehicles or similar

Heavy:
  avoid for most armored cars unless the roster has a truly exceptional heavy vehicle
```

#### Halftracks / carriers

```text
Light:
  small halftracks / carriers, such as Sd.Kfz. 250-style vehicles

Medium:
  medium halftracks / carriers, such as Sd.Kfz. 251-style vehicles
  larger support halftracks / medium carriers

Heavy:
  large tractor / heavy carrier platforms
```

<br>

### For `Tank`

For tanks, class is based on tank family / armor role / purchase pool.

Examples:

```text
Light:
  light tanks, tankettes treated as tanks, early scout/light combat tanks

Medium:
  standard medium tanks and premium medium tanks

Heavy:
  heavy tank families, even if some early/heavy designs are poor in practice
```

Examples:

- A vehicle in a historical light tank family may be `Light`.
- A Valentine may be treated as `Medium` because, in purchase terms, it belongs with medium armor options.
- A Panther can be `Medium` if the roster treats it as a premium medium tank.
- A T-35 can remain `Heavy` because it belongs to the heavy tank family, even if its battlefield performance is poor.

<br>


### For `SPG`

For SPGs, class is based on purchase impact of the weapon platform, not just chassis size.

Consider both:

```text
weapon role + chassis/survivability
```

Examples:

```text
Light:
  small AT carriers, early/light SPAA, weak/light self-propelled weapons

Medium:
  standard tank destroyers, standard SPAA, medium assault guns, medium rocket/artillery

Heavy:
  heavy assault guns, heavy tank destroyers, heavy AA/AT platforms, very heavy artillery
```

A light tank carrying heavy rockets may be `Medium` or `Heavy` depending on how strong it is in the artillery purchase pool. Use the AI purchase role as the deciding factor.

<br>

## Role Selection

Roles describe why the AI should buy the unit. Do not tag every technical thing the unit can do.

### `MG`

Use `MG` for mobile or static machine-gun / suppression platforms.

Examples:

- HMG teams / mounted MGs
- MG cars
- MG halftracks
- MG carriers
- MG-only tankettes or MG-only light vehicles, if they are bought as mobile suppression

Do not use `MG` on normal infantry squads merely because they contain an LMG.

<br>

### `Recon`

Use `Recon` for units the bot should buy as scout / probe / recon assets.

Examples:

- Recon squads
- Snipers
- Scout cars
- Armored cars
- Dedicated scout vehicles
- Recon-designated tanks
- Recon-family support vehicles

Do not apply `Recon` broadly to every light or fast unit. A light tank is not automatically recon.

Use `Recon` for the vehicle's purchase identity when the bot should treat it as part of the recon/probe pool, even if the vehicle also carries a useful gun.

<br>

### `AntiTank`

Use `AntiTank` only when the unit's main purchase reason is answering vehicles or armor.

Examples:

- Towed AT guns
- Dedicated AT infantry
- Tank destroyers
- AT gun halftracks / AT gun trucks
- Dedicated AT SPGs
- Anti-armor tanks whose roster purpose is to fill a tank-destroyer / armor-answer role
- Heavy AA guns only when they are intentionally used as AT/AA dual-role weapons

Do not give `AntiTank` to normal tanks just because they can fight armor. Normal tanks should usually rely on `effects = { "VsArmor" }`, not the `AntiTank` role.

Use `FieldGun` instead of `AntiTank` for generalist guns that are not dedicated AT weapons but still lean anti-armor in gameplay.

<br>

### `AirDefense`

Use `AirDefense` for dedicated AA weapons and self-propelled AA.

Examples:

- Towed AA guns
- AA trucks
- AA halftracks
- SPAA tanks
- Dual-purpose heavy AA guns, if they can actually perform AA in-game

If a weapon historically came from an AA family but cannot elevate / cannot perform AA in-game, do not give it `AirDefense`.

<br>

### `Mortar`

Use `Mortar` for mortar weapons and mortar carriers.

Examples:

- Towed/static mortars
- Mortar halftracks
- Mortar carriers

A mortar carrier may be `Vehicle` or `SPG` depending on how strongly the mounted weapon defines the purchase. Keep the convention consistent within the roster.

<br>

### `InfantryGun`

Use `InfantryGun` for HE support weapons/platforms whose purchase identity is close/direct support against infantry and positions.

Examples:

- Towed infantry guns
- Short-range HE support guns
- Self-propelled heavy infantry support guns
- CS / howitzer tanks whose main purchase reason is direct HE support
- AVRE-style vehicles
- Odd direct/short-range explosive support weapons that do not fit better elsewhere

This role does not have to mean the weapon is literally named an infantry gun, but it should behave like an HE support purchase.

Classifier result:

```text
primary = DirectFire
```

<br>

### `FieldGun`

Use `FieldGun` for general-purpose gun platforms that historically sit between dedicated anti-tank guns and infantry-support guns, but in-game behave closer to anti-armor/direct-fire weapons.

Examples:

- Dual-purpose field guns
- Generalist guns with useful AP performance
- Guns that can provide HE support but are still credible vehicle threats
- Weapons historically used in multiple roles, but represented in-game mainly through direct fire

In the purchase classifier, `FieldGun` is treated as:

```text
primary = AntiArmor
secondary = DirectFire
```

This means `FieldGun` should be used when the unit should be available as an anti-armor answer, while still being recognized as a direct-fire support option.

Use `InfantryGun` instead when the weapon's main gameplay purpose is infantry support, close-range HE, low-velocity direct fire, or medium-arc support fire.

Use `AntiTank` instead when the weapon is a dedicated anti-tank gun, tank destroyer, or anti-armor vehicle.

For turreted tanks with general-purpose guns, usually leave `roles = {}` and use effects instead. Do not pull normal tanks into field-gun plans unless that is intentional.

For special assault guns or support vehicles, classify by gameplay purpose:

- Early infantry-support assault guns, such as early StuG variants, should usually be `InfantryGun`.
- Recon-family support vehicles should usually remain `Recon`, even if they carry a short support gun.

<br>

### `Artillery`

Use `Artillery` for long-range or indirect-fire support.

Examples:

- Towed artillery
- Rocket artillery
- Self-propelled artillery
- Rocket halftracks / trucks / tanks

Rocket artillery may keep `effects = { "VsArmor" }` if it can meaningfully damage armor, but it should not get `AntiTank` unless it is actually bought as an armor answer.

<br>

### `Assault`

Use `Assault` for close-range objective-clearing units.

Examples:

- Assault infantry
- Assault engineers / assault sappers
- Flamethrower infantry
- Flame vehicles / flame carriers / flame halftracks
- Flame tanks

Do not use `Assault` as a generic synonym for “attacking.” It means close assault / objective clearing.

Classifier notes:

- Flame infantry and flame vehicles usually classify primary `Assault`.
- Flame tanks classify primary `Armor`, secondary `Assault`, because they are still armored tank-chassis threats.

<br>

### `Breakthrough`

Use `Breakthrough` for heavy shock assets used to anchor a major push or break hard resistance.

Examples:

- Heavy assault guns
- Heavy breakthrough tanks

`Assault` and `Breakthrough` are not the same tag.

```text
Assault = close-range clearing tool
Breakthrough = heavy shock / armored assault centerpiece
```

<br>

### `Transport`, `Unarmed`, `Supply`

Use these only when the current purchase logic has a clear reason to buy those units.

Examples:

- `Supply`: ammo / supply vehicles
- `Transport`: dedicated transport if it is bought as transport rather than as an infantry squad's delivery method
- `Unarmed`: noncombat vehicle if active in the roster for a specific reason

<br>

## Effects Selection

Effects describe special threat value. They are not universal capability tags.


### `VsInfantry`

Use for units unusually good against infantry relative to their role pool.

Examples:

- HE support guns
- Mortars
- Artillery / rockets
- MG platforms
- Flame units
- Assault specialists with strong close-range anti-infantry tools
- Autocannon AA / SPAA with strong ground-fire value

Normal rifle infantry does not need `VsInfantry`.

<br>

### `VsVehicle`

Use for units meaningfully able to damage light vehicles, soft vehicles, armored cars, or light armor.

Examples:

- Heavy MGs
- Autocannons
- AT rifles
- Small AT guns
- Field guns
- Tanks with vehicle-capable weapons
- Rocket/artillery weapons with meaningful vehicle damage

<br>

### `VsArmor`

Use for units meaningfully able to answer actual armor.

Examples:

- AT guns
- AT infantry with real armor capability
- Tank destroyers
- Tanks with armor-capable guns
- Heavy AA/AT guns
- Heavy assault guns / large HE weapons that can seriously threaten armor
- Rocket artillery if it is considered armor-relevant

Do not use `VsArmor` for weapons that can only scratch light vehicles.

<br>

## Vehicle / Gun Posture Rules

Default posture for most vehicles, tanks, and SPGs:

```lua
posture = { "Flexible" }
```

Use `Defensive` when the unit is best used as a holding, ambush, static, or fragile defensive tool.

Examples:

- Towed AT guns
- Fragile AT carriers / lightly armored AT SPGs
- Static or setup-heavy guns
- Defensive support weapons

Use `Offensive` when the unit is clearly biased toward pushing or close assault.

Examples:

- Flame tanks / flame vehicles
- Assault guns used as close-support push tools
- Heavy breakthrough assault assets, if the roster wants them favored in attack/counterattack plans

<br>

## Vehicle / Gun Grade Rule

Grade within the relevant purchase pool, not globally.

Use this comparison key:

```text
base + primary role + class
```

Examples:

- DShK AA is a strong MG, but weak in the AA/support-AA pool, so it is `Grade1`.
- 122mm M1910 is large globally, but weak/short-ranged in the Soviet artillery pool, so it can be `Grade1`.
- T-50 is `Grade4` because it is a top Soviet light tank, even though it is not comparable to a heavy tank.
- T-35 is low grade in the heavy tank pool because its armor and battlefield performance are poor compared with KV/IS options.
- Panther can be `Medium` + `Grade4` if it is treated as a premium medium tank.
- Tiger I can be `Heavy` + `Grade3` King Tiger / late heavies occupy the premium heavy pool.
- A rare but mediocre unit should use low availability, not inflated grade.

<br>

## Vehicle and Gun Assignment Examples

### Scout / MG armored car

```lua
base = { "Vehicle" }
class = { "Light" } -- or Medium for larger armored cars
roles = { "Recon", "MG" }
posture = { "Flexible" }
effects = { "VsInfantry" }
```

### Heavy armored car with cannon

```lua
base = { "Vehicle" }
class = { "Medium" }
roles = { "Recon" }
posture = { "Flexible" }
effects = { "VsInfantry", "VsVehicle" }
```

### Towed AT gun

```lua
base = { "Cannon" }
class = { "Light" } -- Medium / Heavy by AT-gun pool
roles = { "AntiTank" }
posture = { "Defensive" }
effects = { "VsVehicle", "VsArmor" }
```

### Towed infantry gun

```lua
base = { "Cannon" }
class = { "Light" }
roles = { "InfantryGun" }
posture = { "Defensive" }
effects = { "VsInfantry", "VsVehicle" }
```

### Self-propelled AA

```lua
base = { "SPG" }
class = { "Light" } -- Medium / Heavy by AA platform pool
roles = { "AirDefense" }
posture = { "Flexible" }
effects = { "VsInfantry", "VsVehicle" }
```

### AT halftrack / AT carrier

```lua
base = { "Vehicle" }
class = { "Light" }
roles = { "AntiTank" }
posture = { "Defensive" } -- Flexible if it is robust/mobile enough for attacks
effects = { "VsVehicle", "VsArmor" }
```

### Rocket artillery Truck

```lua
base = { "Vehicle" }
class = { "Medium" } -- or Heavy if it is top-tier in the artillery pool
roles = { "Artillery" }
posture = { "Defensive" }
effects = { "VsInfantry", "VsVehicle", "VsArmor" }
```

### Short-75 direct-fire SPG 

```lua
base = { "SPG" }
class = { "Light" } -- or Medium by platform / purchase impact
roles = { "InfantryGun" }
posture = { "Flexible" }
effects = { "VsInfantry", "VsVehicle" }
```

### Flame tank

```lua
base = { "Tank" }
class = { "Medium" }
roles = { "Assault" }
posture = { "Offensive" }
effects = { "VsInfantry" }
```

Classifier result:

```text
primary = Armor
secondary = Assault
```

### Normal medium tank

```lua
base = { "Tank" }
class = { "Medium" }
roles = {}
posture = { "Flexible" }
effects = { "VsInfantry", "VsVehicle", "VsArmor" }
```
