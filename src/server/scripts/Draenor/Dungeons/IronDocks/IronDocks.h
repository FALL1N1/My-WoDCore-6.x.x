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

#ifndef IRONDOCKS_H
#define IRONDOCKS_H

#define DataHeader "ID"

uint32 const EncounterCount       = 4;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_GRIMRAILENFORCERS        = 0,
    DATA_NOKGAR                   = 1,
    DATA_79852                    = 2,
    DATA_SKULLOC                  = 3
};

enum CreatureIds
{
    NPC_GRIMRAILENFORCERS         = 80805,
    NPC_NOKGAR                    = 81297,
    NPC_OSHIR                     = 79852,
    NPC_SKULLOC                   = 83612
};

enum GameObjectIds
{
};

#endif
