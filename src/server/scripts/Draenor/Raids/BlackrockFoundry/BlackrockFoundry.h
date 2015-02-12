/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BLACKROCKFOUNDRY_H
#define BLACKROCKFOUNDRY_H

#define DataHeader "BRF"

uint32 const EncounterCount       = 10;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_GRUUL                    = 0,
    DATA_OREGORGER                = 1,
    DATA_THEBLASTFURNACE          = 2,
    DATA_HANSGARAND               = 3,
    DATA_FLAMEBENDERKAGRAZ        = 4,
    DATA_KROMOG                   = 5,
    DATA_BEASTLORDDARMAC          = 6,
    DATA_OPERATORTHOGAR           = 7,
    DATA_THEIRONMAIDENS           = 8,
    DATA_BLACKHAND                = 9
};

enum CreatureIds
{
    NPC_GRUUL                     = 76877,
    NPC_OREGORGER                 = 77182,
    NPC_THEBLASTFURNACE           = 76809,
    NPC_HANSGARAND                = 76973,
    NPC_FLAMEBENDERKAGRAZ         = 76814,
    NPC_KROMOG                    = 77692,
    NPC_BEASTLORDDARMAC           = 76865,
    NPC_OPERATORTHOGAR            = 76906,
    NPC_THEIRONMAIDENS            = 77477,
    NPC_BLACKHAND                 = 77325
};

enum GameObjectIds
{
};

#endif
