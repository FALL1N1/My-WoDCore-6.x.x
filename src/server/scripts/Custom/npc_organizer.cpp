//-------------------------------WoD DG & Raid Entry script-------------------------------------//
//----------------------------------By doriangray------------------------------------------//
//-----------------------------------VER 1.0.0-------------------------------------------//

#include "ScriptMgr.h"
#include "ScriptPCH.h"


class npc_organizer : public CreatureScript
{
public:
    npc_organizer() : CreatureScript("npc_organizer") { }

    bool OnGossipHello(Player* plr, Creature* npc)
    {
        if (plr->IsInCombat())
        {
            plr->GetSession()->SendNotification("You're in combat!");
            npc->Whisper("You're in combat!", LANG_UNIVERSAL, NULL);
            return false;
        }

        plr->ADD_GOSSIP_ITEM(2, "WoD CombatMaster", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
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
                plr->ADD_GOSSIP_ITEM(3, "WoD Main", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                plr->ADD_GOSSIP_ITEM(2, "WoD Dungeons", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
                plr->ADD_GOSSIP_ITEM(3, "WoD Raids", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
                plr->ADD_GOSSIP_ITEM(9, "nevermind..", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            }
            else{
                plr->ADD_GOSSIP_ITEM(2, "WoD Main", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                plr->ADD_GOSSIP_ITEM(2, "WoD Dungeons", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
                plr->ADD_GOSSIP_ITEM(3, "WoD Raids", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
                plr->ADD_GOSSIP_ITEM(9, "Nevermind..", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            }
            plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11: //WoD Main
            plr->ADD_GOSSIP_ITEM(2, "ShadowmoonValley", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 40);
            plr->ADD_GOSSIP_ITEM(2, "ShadowmoonValley TheCursedWoods", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 41);
            plr->ADD_GOSSIP_ITEM(2, "ShadowmoonValley EmbaariVillage", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 42);
            plr->ADD_GOSSIP_ITEM(2, "FrostfireRidge", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 43);
            plr->ADD_GOSSIP_ITEM(2, "FrostfireRidge ThunderPass", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 44);
            plr->ADD_GOSSIP_ITEM(2, "FrostfireRidge CircleOfBlood", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 45);
            plr->ADD_GOSSIP_ITEM(2, "Talador", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 46);
            plr->ADD_GOSSIP_ITEM(2, "Talador Shattrath", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 47);
            plr->ADD_GOSSIP_ITEM(2, "Talador Auchindoun", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 48);
            plr->ADD_GOSSIP_ITEM(2, "Talador Tuurem", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 49);
            plr->ADD_GOSSIP_ITEM(2, "Talador Tangarra", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 50);
            plr->ADD_GOSSIP_ITEM(2, "Talador KhadagarsTower", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 51);
            plr->ADD_GOSSIP_ITEM(2, "Talador ShatariAnchorage", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 52);
            plr->ADD_GOSSIP_ITEM(2, "SpiresOfArak", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 53);
            plr->ADD_GOSSIP_ITEM(2, "SpiresOfArak HarvestingPits", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 54);
            plr->ADD_GOSSIP_ITEM(2, "SpiresOfArak PinchwhistlePoint", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 55);
            plr->ADD_GOSSIP_ITEM(2, "SpiresOfArak BloodmanePridelands", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 56);
            plr->ADD_GOSSIP_ITEM(2, "SpiresOfArak ShadowGlade", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 57);
            plr->ADD_GOSSIP_ITEM(2, "SpiresOfArak TerrokarPass", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 58);
            plr->ADD_GOSSIP_ITEM(2, "Nagrand", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 59);
            plr->ADD_GOSSIP_ITEM(2, "Nagrand GatesOfGrommash", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 60);
            plr->ADD_GOSSIP_ITEM(2, "Nagrand SpiritWoods", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 61);
            plr->ADD_GOSSIP_ITEM(2, "Nagrand Highmaul", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 62);
            plr->ADD_GOSSIP_ITEM(2, "Gorgrond", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 63);
            plr->ADD_GOSSIP_ITEM(2, "Gorgrond SteamburstCauldron", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 64);
            plr->ADD_GOSSIP_ITEM(2, "Gorgrond EverbloomWilds", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 65);
            plr->ADD_GOSSIP_ITEM(2, "Gorgrond CrimsonFen", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 66);
            plr->ADD_GOSSIP_ITEM(2, "Gorgrond Razorbloom", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 67);
            plr->ADD_GOSSIP_ITEM(2, "Gorgrond GorgrondPass", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 68);
            plr->ADD_GOSSIP_ITEM(2, "tanaanjunngle BarrierSea", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 69);
            plr->ADD_GOSSIP_ITEM(1, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
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
        case GOSSIP_ACTION_INFO_DEF + 13: // Raids
            plr->ADD_GOSSIP_ITEM(2, "HighmaulRaid", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 38);
            plr->ADD_GOSSIP_ITEM(2, "BlackrockFoundryRaid", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 39);
            plr->ADD_GOSSIP_ITEM(1, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
            break;

            //---------------------------WoD Mains----------------------------//
        case GOSSIP_ACTION_INFO_DEF + 40: //ShadowmoonValley
            plr->TeleportTo(1116, -10.72f, -11.69f, 132.447f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 41: //ShadowmoonValley TheCursedWoods
            plr->TeleportTo(1116, 1868.25f, 543.88f, 36.88f, 2.03728f);	
            break;
        case GOSSIP_ACTION_INFO_DEF + 42: //ShadowmoonValley EmbaariVillage
            plr->TeleportTo(1116, 792.97f, -661.44f, -34.44f, 2.03728f);	
            break;
        case GOSSIP_ACTION_INFO_DEF + 43: //FrostfireRidge
            plr->TeleportTo(1116, 6277.09f, 4661.2f, 164.15f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 44: //FrostfireRidge ThunderPass
            plr->TeleportTo(1116, 6035.97f, 2747.9f, 204.46f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 45: //FrostfireRidge CircleOfBlood
            plr->TeleportTo(1116, 7201.84f, 6143.85f, 118.18f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 46: //Talador
            plr->TeleportTo(1116, 2434.15f, 2375.28f, 126.58f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 47: //Talador Shattrath
            plr->TeleportTo(1116, 2892.45f, 3496.2f, 60.26f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 48: //Talador Auchindoun
            plr->TeleportTo(1116, 1904.64f, 2748.87f, 133.65f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 49: //Talador Tuurem
            plr->TeleportTo(1116, 3046.93f, 2259.74f, 119.86f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 50: //Talador Tangarra
            plr->TeleportTo(1116, 3250.92f, 1007.09f, 39.56f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 51: //Talador KhadagarsTower
            plr->TeleportTo(1116, 3205.78f, 832.33f, 81.90f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 52: //Talador ShatariAnchorage
            plr->TeleportTo(1116, 3444.42f, 3122.29f, 20.40f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 53: //SpiresOfArak
            plr->TeleportTo(1116, -587.87f, 1080.18f, 32.30f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 54: //SpiresOfArak HarvestingPits
            plr->TeleportTo(1116, 261.10f, 1306.36f, 0.37f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 55: //SpiresOfArak PinchwhistlePoint
            plr->TeleportTo(1116, -2117.71f, 1255.85f, 14.11f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 56: //SpiresOfArak BloodmanePridelands
            plr->TeleportTo(1116, -1243.2f, 1948.67f, 22.56f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 57: //SpiresOfArak ShadowGlade
            plr->TeleportTo(1116, -166.49f, 1862.79f, 34.13f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 58: //SpiresOfArak TerrokarPass
            plr->TeleportTo(1116, 596.59f, 2410.67f, 196.98f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 59: //Nagrand
            plr->TeleportTo(1116, 3324.23f, 4759.55f, 124.41f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 60: //Nagrand GatesOfGrommash
            plr->TeleportTo(1116, 2000.47f, 5057.39f, 193.49f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 61: //Nagrand SpiritWoods
            plr->TeleportTo(1116, 2693.53f, 6341.21f, 48.83f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 62: //Nagrand Highmaul
            plr->TeleportTo(1116, 3659.56f, 7226.28f, 10.44f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 63: //Gorgrond
            plr->TeleportTo(1116, 6803.53f, 1219.95f, 69.68f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 64: //Gorgrond SteamburstCauldron
            plr->TeleportTo(1116, 7242.45f, 902.16f, 76.85f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 65: //Gorgrond EverbloomWilds
            plr->TeleportTo(1116, 6847.86f, 418.13f, 79.43f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 66: //Gorgrond CrimsonFen
            plr->TeleportTo(1116, 6126.31f, 528.01f, 16.22f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 67: //Gorgrond Razorbloom
            plr->TeleportTo(1116, 5536.02f, 1189.81f, 93.15f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 68: //Gorgrond GorgrondPass
            plr->TeleportTo(1116, 5406.03f, 1922.05f, 171.85f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 69: //tanaanjunngle BarrierSea
            plr->TeleportTo(1116, 3549.03f, -2126.4f, 17.74f, 2.03728f);
            break;

            //---------------------------dungeons----------------------------//
        case GOSSIP_ACTION_INFO_DEF + 30: //Shadowmoon Dungeon
            plr->TeleportTo(1176, 1719.94f, 239.03f, 324.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 31: //Auchindoun Dungeon
            plr->TeleportTo(1182, 1487.94f, 2953.03f, 36.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 32: //Overgrown Outpost
            plr->TeleportTo(1279, 429.94f, 1327.03f, 126.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 33: //Upper Blackrock Spire
            plr->TeleportTo(1358, 112.94f, -318.03f, 66.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 34: //Blutschlaegermine
            plr->TeleportTo(1175, 2373.94f, -215.03f, 209.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 35: //Eisendocks
            plr->TeleportTo(1195, 6749.94f, -533.03f, 5.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 36: //Skyreach
            plr->TeleportTo(1209, 1226.94f, 1744.03f, 178.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 37: //Grimmgleisdepot
            plr->TeleportTo(1208, -2361.94f, -1800.03f, 10.428f, 2.03728f);
            break;

            //-------------------------raid dungeons-------------------------//
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

void AddSC_npc_organizer()
{
    new npc_organizer();
}

