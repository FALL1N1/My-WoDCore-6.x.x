# Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# file(GLOB_RECURSE sources_Custom Custom/*.cpp Custom/*.h)

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  Custom/GossipNpc.cpp
  Custom/npc_organizer.cpp
  Custom/npc_battlemaster.cpp
  Custom/npc_dungeonmaster.cpp
  Custom/npc_raidmaster.cpp
  Custom/npcscripts/npc_shop.cpp
  Custom/Objects/go_scripts2.cpp
  Custom/Objects/Arena_Gobjects.cpp
  Custom/Objects/GateOfTheSettingSun_doorlevers.cpp
  Custom/Objects/go_generic_lever.cpp
  Custom/Objects/HeartofFear_doorlevers.cpp
  Custom/Objects/ograid_doorlevers.cpp
  Custom/Objects/shadopan_monastery_doorlevers.cpp
  Custom/Objects/TempleOfTheJadeSerpent_doorlevers.cpp
  Custom/cs_world_chat.cpp
)

message("  -> Prepared: Custom")
