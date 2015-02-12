//-------------------------------WoD DG & Raid Entry script-------------------------------------//
//----------------------------------By doriangray------------------------------------------//
//-----------------------------------VER 1.0.0-------------------------------------------//

#include "ScriptMgr.h"
#include "ScriptPCH.h"


class npc_raidmaster : public CreatureScript
{
public:
    npc_raidmaster() : CreatureScript("npc_raidmaster") { }

    bool OnGossipHello(Player* plr, Creature* npc)
    {
        if (plr->IsInCombat())
        {
            plr->GetSession()->SendNotification("You're in combat!");
            npc->Whisper("You're in combat!", LANG_UNIVERSAL, NULL);
            return false;
        }

        plr->ADD_GOSSIP_ITEM(2, "WoD RaidMaster", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
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
                plr->ADD_GOSSIP_ITEM(3, "WoD Raids", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
                plr->ADD_GOSSIP_ITEM(9, "nevermind..", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            }
            else{
                plr->ADD_GOSSIP_ITEM(3, "WoD Raids", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
                plr->ADD_GOSSIP_ITEM(9, "Nevermind..", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            }
            plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 13: // Raids
            plr->ADD_GOSSIP_ITEM(2, "HighmaulRaid", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 38);
            plr->ADD_GOSSIP_ITEM(2, "BlackrockFoundryRaid", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 39);
            plr->ADD_GOSSIP_ITEM(1, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
            break;

            //-------------------------Draenor Raids-------------------------//
        case GOSSIP_ACTION_INFO_DEF + 38: //HighmaulRaid
            plr->TeleportTo(1228, 3486.94f, 7603.03f, 11.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 39: //BlackrockFoundryRaid
            plr->TeleportTo(1205, 345.94f, 3429.03f, 306.428f, 2.03728f);
            break;

            //------------------------close---------------------------------//
        case GOSSIP_ACTION_INFO_DEF + 5: // Close Function
            plr->CLOSE_GOSSIP_MENU();
            break;
        }
        return true;
    }
};

void AddSC_npc_raidmaster()
{
    new npc_raidmaster();
}

