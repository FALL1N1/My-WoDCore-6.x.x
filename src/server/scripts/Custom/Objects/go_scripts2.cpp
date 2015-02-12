

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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "GameObjectAI.h"
#include "Spell.h"
#include "Player.h"
#include "WorldSession.h"

/*######
## go_target_ashran
######*/

class go_target_ashran : public GameObjectScript
{
public:
    go_target_ashran() : GameObjectScript("go_target_ashran") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
            player->TeleportTo(1116, 3046.93f, 2259.74f, 119.86f, 2.03728f);

        return true;
    }
};

enum DoorLever{
    max_now       =  6
};

int32 thunder_lever[max_now] = 
{
126112,
126113,
126114,
126115,
126116,
126117
};

int32 thunder_door[max_now] = 
{
218841,
218842,
218844,
218933,
218939,
218980
};

class thunder_doorlevers : public GameObjectScript
{
public:
    thunder_doorlevers() : GameObjectScript("thunder_doorlevers") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        for (int i = 0; i < max_now; i++){
        if (GameObject * thunder_Door = go->FindNearestGameObject(thunder_door[i], 100.0f))
        {
                thunder_Door->UseDoorOrButton();
                go->UseDoorOrButton();
        }
        }
            return true;

    }
};

void AddSC_go_scripts2()
{
    new go_target_ashran();
    new thunder_doorlevers();
}

