//-------------------------------WoD DG & Raid Entry script-------------------------------------//
//----------------------------------By doriangray------------------------------------------//
//-----------------------------------VER 1.0.0-------------------------------------------//

#include "ScriptMgr.h"
#include "ScriptPCH.h"


class npc_dungeonmaster : public CreatureScript
{
public:
    npc_dungeonmaster() : CreatureScript("npc_dungeonmaster") { }

    bool OnGossipHello(Player* plr, Creature* npc)
    {
        if (plr->IsInCombat())
        {
            plr->GetSession()->SendNotification("You're in combat!");
            npc->Whisper("You're in combat!", LANG_UNIVERSAL, NULL);
            return false;
        }

        plr->ADD_GOSSIP_ITEM(2, "WoD DungeonMaster", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        plr->ADD_GOSSIP_ITEM(9, "Nevermind..", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
        plr->SEND_GOSSIP_MENU(1, npc->GetGUID());
        return true;
    }
    bool OnGossipSelect(Player* plr, Creature* npc, uint32 sender, uint32 uiAction)
    {
        if (!plr)
            return false;
        //------------------------------Menus------------------------------//
        plr->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:// teleportmaster
            if (plr->GetSession()->GetSecurity() <= 2)
            {
                plr->ADD_GOSSIP_ITEM(2, "WoD Dungeons", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
                plr->ADD_GOSSIP_ITEM(9, "nevermind..", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            }
            else{
                plr->ADD_GOSSIP_ITEM(2, "WoD Dungeons", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
                plr->ADD_GOSSIP_ITEM(9, "Nevermind..", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            }
            plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12: //Dungeons
            plr->ADD_GOSSIP_ITEM(2, "Shadowmoon Dungeon", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
            plr->ADD_GOSSIP_ITEM(2, "Auchindoun Dungeon", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 31);
            plr->ADD_GOSSIP_ITEM(2, "Overgrown Outpost", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 32);
            plr->ADD_GOSSIP_ITEM(2, "Upper Blackrock Spire", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 33);
            plr->ADD_GOSSIP_ITEM(2, "BloodSlagMines", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 34);
            plr->ADD_GOSSIP_ITEM(2, "Iron Docks", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 35);
            plr->ADD_GOSSIP_ITEM(2, "Skyreach", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 36);
            plr->ADD_GOSSIP_ITEM(2, "Grimraildepot", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 37);
            plr->ADD_GOSSIP_ITEM(1, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
            break;

            //------------------------WoD Dungeons----------------------------//
        case GOSSIP_ACTION_INFO_DEF + 30: //Shadowmoon Dungeon
            plr->TeleportTo(1176, 1719.94f, 239.03f, 324.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 31: //Auchindoun Dungeon
            plr->TeleportTo(1182, 1487.94f, 2953.03f, 36.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 32: //Overgrown Outpost
            plr->TeleportTo(1279, 429.94f, 1327.03f, 126.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 33: //UpperBlackrockSpire
            plr->TeleportTo(1358, 112.94f, -318.03f, 66.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 34: //BloodSlagMines
            plr->TeleportTo(1175, 2373.94f, -215.03f, 209.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 35: //IronDocks
            plr->TeleportTo(1195, 6749.94f, -533.03f, 5.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 36: //Skyreach
            plr->TeleportTo(1209, 1226.94f, 1744.03f, 178.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 37: //Grimraildepot
            plr->TeleportTo(1208, -2361.94f, -1800.03f, 10.428f, 2.03728f);
            break;

            //------------------------close---------------------------------//
        case GOSSIP_ACTION_INFO_DEF + 5: // Close Function
            plr->CLOSE_GOSSIP_MENU();
            break;
        }
        return true;
    }
};

void AddSC_npc_dungeonmaster()
{
    new npc_dungeonmaster();
}

