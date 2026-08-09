CE Configurator baseline files for the current CE data layout.

Do not copy this folder wholesale into the mod. These files map to several
different live locations and CE Configurator restores only the settings owned
by each feature.

Live file mappings:
- bot.conquest_configuration.lua
  -> resource/conquest_configuration/bot.conquest_configuration.lua
- campaign_capture_the_flag.set and CTF preset files
  -> resource/set/multiplayer/games/campaign_capture_the_flag.set
- entitymanager.set
  -> resource/set/entitymanager.set
- duration_*.set and resources_*.set
  -> resource/set/dynamic_campaign/

The macev2 subfolder contains branch-specific baselines for the currently
supported MaCEv2 build.
