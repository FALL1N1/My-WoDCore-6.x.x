//-------------------------------Teleporter script-------------------------------------//
//----------------------------------By drgrpl------------------------------------------//
//-----------------------------------VER 1.0.1-------------------------------------------//
//----------thank to jadaDev for all the cordanates from his sql teleporter------------//
//---------------------thanks to Milbow for the original idea--------------------------//
//If you use this script please leave credit to me and the others who made this posible//

#include "ScriptMgr.h"
#include "ScriptPCH.h"

uint32 aurass[] = { 48074, 47440, 53307, 132, 48170, 23737, 48470, 43002, 26393, 48162, 24705 };

class GossipNpc : public CreatureScript
{
public:
    GossipNpc() : CreatureScript("GossipNpc") { }

    bool OnGossipHello(Player* plr, Creature* npc)
    {
        if (plr->IsInCombat())
        {
            plr->GetSession()->SendNotification("You're in combat!");
            npc->Whisper("You're in combat!", LANG_UNIVERSAL, NULL);
            return false;
        }

        plr->ADD_GOSSIP_ITEM(2, "Teleport Service", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        plr->ADD_GOSSIP_ITEM(3, "Buff me!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        plr->ADD_GOSSIP_ITEM(3, "Heal me!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
        plr->ADD_GOSSIP_ITEM(4, "Repair My Items (1g)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
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
        case GOSSIP_ACTION_INFO_DEF + 1:// teleport service
            if (plr->GetSession()->GetSecurity() <= 2)
            {
                plr->ADD_GOSSIP_ITEM(2, "Mall & Events", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
                plr->ADD_GOSSIP_ITEM(2, "Cities", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
                plr->ADD_GOSSIP_ITEM(2, "Eastern Kingdoms", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
                plr->ADD_GOSSIP_ITEM(2, "Kalimdor", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
                plr->ADD_GOSSIP_ITEM(2, "Outland", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
                plr->ADD_GOSSIP_ITEM(2, "Northrend", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                plr->ADD_GOSSIP_ITEM(2, "Dungeons", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
                plr->ADD_GOSSIP_ITEM(3, "Custom Instances", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
                plr->ADD_GOSSIP_ITEM(3, "Booty bay", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 19);
                plr->ADD_GOSSIP_ITEM(3, "Gurubashi arena", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 20);
                plr->ADD_GOSSIP_ITEM(9, "nevermind..", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            }
            else{
                plr->ADD_GOSSIP_ITEM(2, "Mall & Events", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
                plr->ADD_GOSSIP_ITEM(2, "Cities", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
                plr->ADD_GOSSIP_ITEM(2, "Eastern Kingdoms", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
                plr->ADD_GOSSIP_ITEM(2, "Kalimdor", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
                plr->ADD_GOSSIP_ITEM(2, "Outland", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
                plr->ADD_GOSSIP_ITEM(2, "Northrend", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
                plr->ADD_GOSSIP_ITEM(2, "Dungeons", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
                plr->ADD_GOSSIP_ITEM(3, "Custom Instances", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
                plr->ADD_GOSSIP_ITEM(3, "Booty bay", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 19);
                plr->ADD_GOSSIP_ITEM(3, "Gurubashi arena", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 20);
                plr->ADD_GOSSIP_ITEM(3, "GM Island", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
                plr->ADD_GOSSIP_ITEM(9, "Nevermind..", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            }
            plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6: //mall and event
            plr->ADD_GOSSIP_ITEM(2, "Mall", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 21);
            plr->ADD_GOSSIP_ITEM(9, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:  // cities
            plr->ADD_GOSSIP_ITEM(2, "Stormwind", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
            plr->ADD_GOSSIP_ITEM(2, "Ironforge", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
            plr->ADD_GOSSIP_ITEM(2, "Darnassus", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
            plr->ADD_GOSSIP_ITEM(2, "The Exodar", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
            plr->ADD_GOSSIP_ITEM(2, "Orgrimmar", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 26);
            plr->ADD_GOSSIP_ITEM(2, "Undercity", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 27);
            plr->ADD_GOSSIP_ITEM(2, "Thunder Bluff", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 28);
            plr->ADD_GOSSIP_ITEM(2, "Silvermoon", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 29);
            plr->ADD_GOSSIP_ITEM(2, "Dalaran", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
            plr->ADD_GOSSIP_ITEM(2, "Shattrath", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 31);
            plr->ADD_GOSSIP_ITEM(1, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            plr->SEND_GOSSIP_MENU(1, npc->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12: //Dungeons SubMenu
            plr->ADD_GOSSIP_ITEM(2, "Classic Dungeons", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 15);
            plr->ADD_GOSSIP_ITEM(2, "BC Dungeons", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
            plr->ADD_GOSSIP_ITEM(2, "Wrath Dungeons", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 17);
            plr->ADD_GOSSIP_ITEM(2, "Raids", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 18);
            plr->ADD_GOSSIP_ITEM(1, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 15: // classic dungeons
            plr->ADD_GOSSIP_ITEM(2, "Gnomeregan", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 32);
            plr->ADD_GOSSIP_ITEM(2, "The Deadmines", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 33);
            plr->ADD_GOSSIP_ITEM(2, "The Stockade", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 34);
            plr->ADD_GOSSIP_ITEM(2, "Ragefire Chasm", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 35);
            plr->ADD_GOSSIP_ITEM(2, "Razorfen Downs", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 36);
            plr->ADD_GOSSIP_ITEM(2, "Razorfen Kraul", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 37);
            plr->ADD_GOSSIP_ITEM(2, "Scarlet Monastery", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 38);
            plr->ADD_GOSSIP_ITEM(2, "Shadowfang Keep", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 39);
            plr->ADD_GOSSIP_ITEM(2, "Wailing Caverns", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 40);
            plr->ADD_GOSSIP_ITEM(2, "Blackfathom Deeps", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 41);
            plr->ADD_GOSSIP_ITEM(2, "Blackrock Depths", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 42);
            plr->ADD_GOSSIP_ITEM(2, "Blackrock Spire", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 43);
            plr->ADD_GOSSIP_ITEM(2, "Dire Maul", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 44);
            plr->ADD_GOSSIP_ITEM(2, "Maraudon", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 45);
            plr->ADD_GOSSIP_ITEM(2, "Scholomance", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 46);
            plr->ADD_GOSSIP_ITEM(2, "Stratholme", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 47);
            plr->ADD_GOSSIP_ITEM(2, "Sunken Temple", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 48);
            plr->ADD_GOSSIP_ITEM(2, "Uldaman", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 49);
            plr->ADD_GOSSIP_ITEM(2, "Zul'Farrak", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 50);
            plr->ADD_GOSSIP_ITEM(1, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
            break;
        case GOSSIP_ACTION_INFO_DEF + 16: // BC dungeons
            plr->ADD_GOSSIP_ITEM(2, "Tempest Keep", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 51);
            plr->ADD_GOSSIP_ITEM(2, "Magisters' Terrace", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 52);
            plr->ADD_GOSSIP_ITEM(2, "Hellfire Citadel", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 53);
            plr->ADD_GOSSIP_ITEM(2, "Coilfang Reservoir", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 54);
            plr->ADD_GOSSIP_ITEM(2, "Caverns of Time", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 55);
            plr->ADD_GOSSIP_ITEM(2, "Auchindoun", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 56);
            plr->ADD_GOSSIP_ITEM(1, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
            break;
        case GOSSIP_ACTION_INFO_DEF + 17: // wrath dungeons
            plr->ADD_GOSSIP_ITEM(2, "Utgarde Pinnacle", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 57);
            plr->ADD_GOSSIP_ITEM(2, "Utgarde Keep", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 58);
            plr->ADD_GOSSIP_ITEM(2, "Halls of Stone", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 59);
            plr->ADD_GOSSIP_ITEM(2, "Halls of Lightning", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 60);
            plr->ADD_GOSSIP_ITEM(2, "The Violet Hold", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 61);
            plr->ADD_GOSSIP_ITEM(2, "The Nexus Dungeons", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 62);
            plr->ADD_GOSSIP_ITEM(2, "Icecrown Citadel Dungeons", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 63);
            plr->ADD_GOSSIP_ITEM(2, "Gundrak", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 64);
            plr->ADD_GOSSIP_ITEM(2, "Drak'Tharon Keep", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 65);
            plr->ADD_GOSSIP_ITEM(2, "Trial of the Champion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 66);
            plr->ADD_GOSSIP_ITEM(2, "The Culling of Stratholme", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 67);
            plr->ADD_GOSSIP_ITEM(2, "Azjol-Nerub", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 68);
            plr->ADD_GOSSIP_ITEM(1, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
            break;
        case GOSSIP_ACTION_INFO_DEF + 18: // Raids
            plr->ADD_GOSSIP_ITEM(2, "Zul'Aman", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 69);
            plr->ADD_GOSSIP_ITEM(2, "Zul'Gurub", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 70);
            plr->ADD_GOSSIP_ITEM(2, "Vault of Archavon", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 71);
            plr->ADD_GOSSIP_ITEM(2, "Ulduar", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 72);
            plr->ADD_GOSSIP_ITEM(2, "The Obsidian Sanctum", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 73);
            plr->ADD_GOSSIP_ITEM(2, "The Eye of Eternity", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 74);
            plr->ADD_GOSSIP_ITEM(2, "Temple of Ahn'Qiraj", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 75);
            plr->ADD_GOSSIP_ITEM(2, "The Eye", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 76);
            plr->ADD_GOSSIP_ITEM(2, "Sunwell Plateau", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 77);
            plr->ADD_GOSSIP_ITEM(2, "Ruins of Ahn'Qiraj", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 78);
            plr->ADD_GOSSIP_ITEM(2, "Onyxia's Lair", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 79);
            plr->ADD_GOSSIP_ITEM(2, "Naxxramas", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 80);
            plr->ADD_GOSSIP_ITEM(2, "Molten Core", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 81);
            plr->ADD_GOSSIP_ITEM(2, "Karazhan", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 82);
            plr->ADD_GOSSIP_ITEM(2, "Icecrown Citadel", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 83);
            plr->ADD_GOSSIP_ITEM(2, "Magtheridon's Lair", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 84);
            plr->ADD_GOSSIP_ITEM(2, "Gruul's Lair", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 85);
            plr->ADD_GOSSIP_ITEM(2, "Trial of the Crusader", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 86);
            plr->ADD_GOSSIP_ITEM(2, "Serpentshrine Cavern", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 87);
            plr->ADD_GOSSIP_ITEM(2, "Hyjal Summit", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 88);
            plr->ADD_GOSSIP_ITEM(2, "Blackwing Lair", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 89);
            plr->ADD_GOSSIP_ITEM(2, "Black Temple", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 90);
            plr->ADD_GOSSIP_ITEM(1, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
            break;
        case GOSSIP_ACTION_INFO_DEF + 8: // eastern kingdoms
            plr->ADD_GOSSIP_ITEM(2, "Isle of Quel'Danas", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 91);
            plr->ADD_GOSSIP_ITEM(2, "Eastern Plaguelands", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 92);
            plr->ADD_GOSSIP_ITEM(2, "Western Plaguelands", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 93);
            plr->ADD_GOSSIP_ITEM(2, "Burning Steppes", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 94);
            plr->ADD_GOSSIP_ITEM(2, "The Blasted Lands", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 95);
            plr->ADD_GOSSIP_ITEM(2, "Searing Gorge", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 96);
            plr->ADD_GOSSIP_ITEM(2, "The Hinterlands", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 97);
            plr->ADD_GOSSIP_ITEM(2, "Swamp of Sorrows", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 98);
            plr->ADD_GOSSIP_ITEM(2, "Badlands", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 99);
            plr->ADD_GOSSIP_ITEM(2, "Stranglethorn Vale", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 100);
            plr->ADD_GOSSIP_ITEM(2, "Arathi Highlands", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 101);
            plr->ADD_GOSSIP_ITEM(2, "Alterac Mountains", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 102);
            plr->ADD_GOSSIP_ITEM(2, "Wetlands", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 103);
            plr->ADD_GOSSIP_ITEM(2, "Hillsbrad Foothills", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 104);
            plr->ADD_GOSSIP_ITEM(2, "Duskwood", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 105);
            plr->ADD_GOSSIP_ITEM(2, "Redridge mountains", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 106);
            plr->ADD_GOSSIP_ITEM(2, "Westfall", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 107);
            plr->ADD_GOSSIP_ITEM(2, "Silverpine Forest", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 108);
            plr->ADD_GOSSIP_ITEM(2, "Loch modan", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 109);
            plr->ADD_GOSSIP_ITEM(2, "Ghostlands", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 110);
            plr->ADD_GOSSIP_ITEM(2, "Tirisfal Glades", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 111);
            plr->ADD_GOSSIP_ITEM(2, "Dun Morogh", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 112);
            plr->ADD_GOSSIP_ITEM(2, "Eversong Woods", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 113);
            plr->ADD_GOSSIP_ITEM(2, "Elwynn Forest", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 114);
            plr->ADD_GOSSIP_ITEM(1, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            break;
        case GOSSIP_ACTION_INFO_DEF + 9: //kalimdor
            plr->ADD_GOSSIP_ITEM(2, "Winterspring", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 115);
            plr->ADD_GOSSIP_ITEM(2, "Silithus", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 116);
            plr->ADD_GOSSIP_ITEM(2, "Un'Goro Crater", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 117);
            plr->ADD_GOSSIP_ITEM(2, "Felwood", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 118);
            plr->ADD_GOSSIP_ITEM(2, "Azshara", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 119);
            plr->ADD_GOSSIP_ITEM(2, "Tanaris Desert", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 120);
            plr->ADD_GOSSIP_ITEM(2, "Feralas", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 121);
            plr->ADD_GOSSIP_ITEM(2, "Dustwallow Marsh", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 122);
            plr->ADD_GOSSIP_ITEM(2, "Desolace", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 123);
            plr->ADD_GOSSIP_ITEM(2, "Thousand Needles", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 124);
            plr->ADD_GOSSIP_ITEM(2, "Ashenvale Forest", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 125);
            plr->ADD_GOSSIP_ITEM(2, "Stonetalon Mountains", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 126);
            plr->ADD_GOSSIP_ITEM(2, "The Barrens", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 127);
            plr->ADD_GOSSIP_ITEM(2, "Darkshore", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 128);
            plr->ADD_GOSSIP_ITEM(2, "Bloodmyst Isle", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 129);
            plr->ADD_GOSSIP_ITEM(2, "Mulgore", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 130);
            plr->ADD_GOSSIP_ITEM(2, "Durotar", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 131);
            plr->ADD_GOSSIP_ITEM(2, "Teldrassil", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 132);
            plr->ADD_GOSSIP_ITEM(2, "Azuremyst Isle", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 133);
            plr->ADD_GOSSIP_ITEM(1, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            break;
        case GOSSIP_ACTION_INFO_DEF + 10: //outland
            plr->ADD_GOSSIP_ITEM(2, "Shadowmoon Valley", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 134);
            plr->ADD_GOSSIP_ITEM(2, "Netherstorm", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 135);
            plr->ADD_GOSSIP_ITEM(2, "Blade's Edge Mountains", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 136);
            plr->ADD_GOSSIP_ITEM(2, "Nagrand", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 137);
            plr->ADD_GOSSIP_ITEM(2, "Terokkar Forest", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 138);
            plr->ADD_GOSSIP_ITEM(2, "Zangarmarsh", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 139);
            plr->ADD_GOSSIP_ITEM(2, "Hellfire Peninsula", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 140);
            plr->ADD_GOSSIP_ITEM(1, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            break;
        case GOSSIP_ACTION_INFO_DEF + 11: //northrend
            plr->ADD_GOSSIP_ITEM(2, "Wintergrasp", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 141);
            plr->ADD_GOSSIP_ITEM(2, "Icecrown", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 142);
            plr->ADD_GOSSIP_ITEM(2, "Storm Peaks", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 143);
            plr->ADD_GOSSIP_ITEM(2, "Crystalsong Forest", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 144);
            plr->ADD_GOSSIP_ITEM(2, "Sholazar Basin", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 145);
            plr->ADD_GOSSIP_ITEM(2, "Zul'Drak", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 146);
            plr->ADD_GOSSIP_ITEM(2, "Grizzly Hills", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 147);
            plr->ADD_GOSSIP_ITEM(2, "Dragonblight", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 148);
            plr->ADD_GOSSIP_ITEM(2, "Howling Fjord", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 149);
            plr->ADD_GOSSIP_ITEM(2, "Borean Tundra", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 150);
            plr->ADD_GOSSIP_ITEM(1, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            break;

            //-----------------------teleports------------------------------//
        case GOSSIP_ACTION_INFO_DEF + 14: // GM Island Teleport
            if (plr->HasItemCount(12064, 1))
            {
                plr->TeleportTo(1, 16222.500000f, 16257.566406f, 13.127848f, 1.548749f);
            }
            else{
                plr->TeleportTo(1, 16222.500000f, 16257.566406f, 13.127848f, 1.548749f);
                plr->AddItem(12064, 1);
                plr->AddItem(2586, 1);
                plr->AddItem(11508, 1);
            }
            break;
        case GOSSIP_ACTION_INFO_DEF + 21: //mall teleport
            plr->TeleportTo(530, -1859.869995f, 5420.069824f, -10.380500f, 2.146750f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 19: //Booty bay
            plr->TeleportTo(0, -14304.2f, 511.648f, 8.66784f, 4.36641f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 20: //Gurubashi arena
            plr->TeleportTo(0, -13262.6f, 161.518f, 36.4557f, 1.09443f);
            break;
            //----------------------eastern kingdoms-------------------------------//
        case GOSSIP_ACTION_INFO_DEF + 91: // Isle of Quel'Danas
            plr->TeleportTo(530, 12942.4f, -6930.77f, 4.21306f, 2.43792f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 92: // Eastern Plaguelands
            plr->TeleportTo(0, 1728.57f, -1601.32f, 63.5187f, 1.6558f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 93: // Western Plaguelands
            plr->TeleportTo(0, 1728.57f, -1601.32f, 63.5187f, 1.6558f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 94: //Burning Steppes
            plr->TeleportTo(0, -8118.54f, -1633.83f, 132.996f, 0.089067f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 95: //The Blasted Lands
            plr->TeleportTo(0, -11182.5f, -3016.67f, 7.42235f, 4.0004f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 96: //Searing Gorge
            plr->TeleportTo(0, -7013.51f, -1065.71f, 241.788f, 5.47611f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 97: //The Hinterlands
            plr->TeleportTo(0, 119.387f, -3190.37f, 117.331f, 2.34064f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 98: //Swamp of Sorrows
            plr->TeleportTo(0, -7013.51f, -1065.71f, 241.788f, 5.47611f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 99: //Badlands
            plr->TeleportTo(0, -6779.2f, -3423.64f, 241.667f, 0.647481f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 100: //Stranglethorn Vale
            plr->TeleportTo(0, -14097.3f, 257.888f, 16.5929f, 3.28801f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 101: //Arathi Highlands
            plr->TeleportTo(0, -1508.57f, -2730.92f, 32.3782f, 3.01144f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 102: //Alterac Mountains
            plr->TeleportTo(0, 370.763f, -491.355f, 175.361f, 5.37858f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 103: //Wetlands
            plr->TeleportTo(0, -3242.81f, -2469.04f, 15.9226f, 6.03924f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 104: //Hillsbrad Foothills
            plr->TeleportTo(0, -8404.3f, -4070.62f, -208.586f, 0.237038f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 105: //Duskwood
            plr->TeleportTo(0, -10898.3f, -364.784f, 39.2681f, 3.04614f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 106: //Redridge mountains
            plr->TeleportTo(0, -9551.81f, -2204.73f, 93.473f, 5.47141f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 107: //Westfall
            plr->TeleportTo(0, -10235.2f, 1222.47f, 43.6252f, 6.2427f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 108: //Silverpine Forest
            plr->TeleportTo(0, 878.74f, 1359.33f, 50.355f, 5.89929f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 109: //Loch modan
            plr->TeleportTo(0, -5202.76f, -2855.38f, 336.73f, 0.37651f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 110: //Ghostlands
            plr->TeleportTo(530, 7363.16f, -6782.51f, 40.2869f, 5.43033f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 111: //Tirisfal Glades
            plr->TeleportTo(0, 2036.02f, 161.331f, 33.8674f, 0.143896f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 112: //Dun Morogh
            plr->TeleportTo(0, -5451.55f, -656.992f, 392.675f, 0.66789f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 113: //Eversong Woods
            plr->TeleportTo(530, 9079.92f, -7193.23f, 55.6013f, 5.94597f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 114: //Elwynn Forest
            plr->TeleportTo(0, -9616.93f, -287.606f, 57.4534f, 4.59818f);
            break;
            //------------------------kalimdor------------------------------//
        case GOSSIP_ACTION_INFO_DEF + 115: //winterspring
            plr->TeleportTo(1, 6901.25f, -2299.12f, 588.61f, 3.61667f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 116: //Silithus
            plr->TeleportTo(1, -7426.87f, 1005.31f, 1.13359f, 2.96086f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 117: //Un'Goro Crater
            plr->TeleportTo(1, -7864.93f, -2078.94f, -272.222f, 0.930319f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 118: //Felwood
            plr->TeleportTo(1, 4102.25f, -1006.79f, 272.717f, 0.790048f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 119: //Azshara
            plr->TeleportTo(1, 3343.36f, -4602.51f, 92.498f, 5.28142f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 120: //Tanaris Desert
            plr->TeleportTo(1, -7109.28f, -3825.3f, 10.1511f, 2.96557f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 121: //Feralas
            plr->TeleportTo(1, -4841.19f, 1309.44f, 84.3937f, 1.48501f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 122: //Dustwallow Marsh
            plr->TeleportTo(1, -4043.52f, -2987.02f, 36.4998f, 2.91497f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 123: //Desolace
            plr->TeleportTo(1, -606.395f, 221.75f, 92.9818f, 0.809746f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 124: //Thousand Needles
            plr->TeleportTo(1, -4969.02f, -1726.89f, -62.1269f, 3.7933f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 125: //Ashenvale Forest
            plr->TeleportTo(1, 1925.09f, -2171.5f, 94.111f, 1.20319f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 126: //Stonetalon Mountains
            plr->TeleportTo(1, 2678.38f, 1497.46f, 233.869f, 6.26038f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 127: //The Barrens
            plr->TeleportTo(1, 687.352f, -3567.89f, 93.3775f, 0.9763f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 128: //Darkshore
            plr->TeleportTo(1, 5756.25f, 298.505f, 20.6049f, 5.96504f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 129: //Bloodmyst Isle
            plr->TeleportTo(530, -1993.62f, -11475.8f, 63.9657f, 5.29437f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 130: //Mulgore
            plr->TeleportTo(1, -2192.62f, -736.317f, -13.3274f, 0.487569f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 131: //Durotar
            plr->TeleportTo(1, 1333.64f, -4375.66f, 26.2044f, 0.168631f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 132: //Teldrassil
            plr->TeleportTo(1, 10110.9f, 1556.95f, 1324.32f, 2.33415f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 133: //Azuremyst Isle
            plr->TeleportTo(530, -4222.26f, -12332.1f, 3.5036f, 1.0116f);
            break;
            //---------------------------outland-----------------------------//
        case GOSSIP_ACTION_INFO_DEF + 134: //Shadowmoon Valley
            plr->TeleportTo(530, -3450.46f, 2287.36f, 63.6056f, 6.24661f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 135: //Netherstorm
            plr->TeleportTo(530, 3830.9f, 3426.4f, 88.8403f, 5.79509f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 136: //Blade's Edge Mountains
            plr->TeleportTo(530, 3037.67f, 5962.86f, 130.774f, 1.16572f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 137: //Nagrand
            plr->TeleportTo(530, -1145.95f, 8182.35f, 3.60249f, 6.13478f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 138: //Terokkar Forest
            plr->TeleportTo(530, -2000.47f, 4451.54f, 8.37917f, 4.40447f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 139: //Zangarmarsh
            plr->TeleportTo(530, 344.017f, 6832.73f, 48.0539f, 2.92642f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 140: //Hellfire Peninsula
            plr->TeleportTo(530, -248.149f, 921.875f, 84.3798f, 1.58415f);
            break;
            //------------------------northrend------------------------------//
        case GOSSIP_ACTION_INFO_DEF + 141: //Wintergrasp
            plr->TeleportTo(571, 4760.7f, 2143.7f, 422.943f, 1.13f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 142: //Icecrown
            plr->TeleportTo(571, 7253.64f, 1644.78f, 433.68f, 4.83412f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 143: //Storm Peaks
            plr->TeleportTo(571, 7566.88f, -1240.25f, 917.775f, 2.82735f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 144: //Crystalsong Forest
            plr->TeleportTo(571, 5527.54f, 82.7464f, 151.7f, 0.799626f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 145: //Sholazar Basin
            plr->TeleportTo(571, 5323.001f, 4942.001f, -133.559f, 2.17f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 146: //Zul'Drak
            plr->TeleportTo(571, 6926.68f, -4446.53f, 450.523f, 0.801584f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 147: //Grizzly Hills
            plr->TeleportTo(571, 4391.73f, -3587.92f, 238.531f, 3.57526f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 148: //Dragonblight
            plr->TeleportTo(571, 4103.54f, 264.538f, 50.5134f, 3.09349f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 149: //Howling Fjord
            plr->TeleportTo(571, 1902.15f, -4883.91f, 171.363f, 3.11537f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 150: //Borean Tundra
            plr->TeleportTo(571, 3256.57f, 5278.23f, 40.8046f, 0.246367f);
            break;
            //-------------------------clasic dungeons------------------------//
        case GOSSIP_ACTION_INFO_DEF + 32: //Gnomeregan
            plr->TeleportTo(90, -327.577f, -4.35046f, -152.845f, 6.18894f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 33: //The Deadmines
            plr->TeleportTo(0, -11208.1f, 1671.55f, 24.6908f, 1.54879f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 34: //The Stockade
            plr->TeleportTo(0, -8799.15f, 832.718f, 97.6348f, 6.04085f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 35: //Ragefire Chasm
            plr->TeleportTo(1, 1809.17f, -4407.18f, -18.6752f, 5.23117f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 36: //Razorfen Downs
            plr->TeleportTo(1, -4655.88f, -2521.14f, 81.2055f, 4.21036f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 37: //Razorfen Kraul
            plr->TeleportTo(1, -4463.32f, -1664.49f, 82.2581f, 0.841007f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 38: //Scarlet Monastery
            plr->TeleportTo(0, 2873.03f, -764.237f, 160.332f, 5.10055f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 39: //Shadowfang Keep
            plr->TeleportTo(0, -241.881f, 1543.69f, 76.8921f, 1.1814f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 40: //Wailing Caverns
            plr->TeleportTo(1, -732.428f, -2220.71f, 17.3289f, 2.68276f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 41: //Blackfathom Deeps
            plr->TeleportTo(1, 4247.74f, 745.942f, -24.2824f, 1.07678f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 42: //Blackrock Depths
            plr->TeleportTo(0, -7182.15f, -917.016f, 165.49f, 5.06065f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 43: //Blackrock Spire
            plr->TeleportTo(0, -7534.79f, -1212.62f, 285.44f, 5.2131f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 44: //Dire Maul
            plr->TeleportTo(1, -3829.83f, 1250.34f, 160.229f, 3.12903f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 45: //Maraudon
            plr->TeleportTo(1, -1465.22f, 2617.91f, 76.9758f, 3.21067f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 46: //Scholomance
            plr->TeleportTo(0, 1265.68f, -2557.52f, 94.1264f, 0.491748f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 47: //Stratholme
            plr->TeleportTo(0, 3342.79f, -3379.33f, 144.776f, 6.26449f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 48: //Sunken Temple
            plr->TeleportTo(0, -10183.4f, -3993.19f, -109.195f, 6.03063f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 49: //Uldaman
            plr->TeleportTo(0, -6070.1f, -2955.81f, 209.778f, 0.071478f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 50: //Zul'Farrak
            plr->TeleportTo(1, -6821.2f, -2890.29f, 8.88035f, 6.24783f);
            break;
            //-------------------------BC dungeons---------------------------//
        case GOSSIP_ACTION_INFO_DEF + 51: //Tempest Keep
            plr->TeleportTo(530, 3090.54f, 1406.45f, 189.574f, 4.62382f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 52: //Magisters' Terrace
            plr->TeleportTo(530, 12886.2f, -7333.84f, 65.4884f, 4.26101f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 53: //Hellfire Citadel
            plr->TeleportTo(530, -360.681f, 3066.36f, -15.1251f, 1.78001f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 54: //Coilfang Reservoir
            plr->TeleportTo(530, 748.466f, 6882.93f, -64.1698f, 3.85811f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 55: //Caverns of Time
            plr->TeleportTo(1, -8181.85f, -4703.54f, 19.5836f, 4.95664f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 56: //Auchindoun
            plr->TeleportTo(530, -3334.63f, 4933.87f, -100.079f, 0.41726f);
            break;
            //-------------------------wrath dungeons------------------------//
        case GOSSIP_ACTION_INFO_DEF + 57: //Utgarde Pinnacle
            plr->TeleportTo(571, 1245.8f, -4856.45f, 216.813f, 3.42403f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 58: //Utgarde Keep
            plr->TeleportTo(571, 1205.7f, -4867.65f, 41.2479f, 0.234685f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 59: //Halls of Stone
            plr->TeleportTo(571, 8922.12f, -1009.16f, 1038.56f, 1.57044f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 60: //Halls of Lightning
            plr->TeleportTo(571, 9183.53f, -1385.17f, 1110.22f, 5.56943f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 61: //The Violet Hold
            plr->TeleportTo(571, 5681.5f, 488.528f, 652.45f, 4.01037f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 62: //The Nexus Dungeons
            plr->TeleportTo(571, 3771.01f, 6947.5f, 105.88f, 0.472142f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 63: //Icecrown Citadel Dungeons
            plr->TeleportTo(571, 5636.55f, 2064.03f, 798.059f, 4.62278f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 64: //Gundrak
            plr->TeleportTo(571, 6726.75f, -4637.28f, 450.605f, 3.90537f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 65: //Drak'Tharon Keep
            plr->TeleportTo(571, 4777.85f, -2046.5f, 230.01f, 1.63791f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 66: //Trial of the Champion
            plr->TeleportTo(571, 8576.16f, 792.096f, 558.234f, 3.14714f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 67: //The Culling of Stratholme
            plr->TeleportTo(1, -8756.39f, -4440.68f, -199.489f, 4.66289f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 68: //Azjol-Nerub
            plr->TeleportTo(571, 3679.4f, 2163.25f, 35.7227f, 2.28066f);
            break;
            //-------------------------raid dungeons-------------------------//
        case GOSSIP_ACTION_INFO_DEF + 69: //Zul'Aman
            plr->TeleportTo(530, 6852.09f, -7989.8f, 189.7f, 4.68225f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 70: //Zul'Gurub
            plr->TeleportTo(0, -11916.7f, -1215.72f, 92.289f, 4.72454f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 71: //Vault of Archavon
            plr->TeleportTo(571, 5454.11f, 2840.79f, 421.278f, 6.27665f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 72: //Ulduar
            plr->TeleportTo(571, 8922.35f, -1208.93f, 1025.5f, 6.03428f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 73: //The Obsidian Sanctum
            plr->TeleportTo(571, 3513.83f, 269.829f, -114.085f, 3.25168f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 74: //The Eye of Eternity
            plr->TeleportTo(530, 3088.49f, 1381.57f, 184.863f, 4.61973f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 75: //Temple of Ahn'Qiraj
            plr->TeleportTo(1, -8240.09f, 1991.32f, 129.072f, 0.941603f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 76: //The Eye
            plr->TeleportTo(530, 3088.49f, 1381.57f, 184.863f, 4.61973f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 77: //Sunwell Plateau
            plr->TeleportTo(530, 12573.2f, -6774.81f, 15.0904f, 3.13788f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 78: //Ruins of Ahn'Qiraj
            plr->TeleportTo(1, -8412.61f, 1503.58f, 29.9291f, 2.69932f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 79: //Onyxia's Lair
            plr->TeleportTo(1, -4709.97f, -3728.87f, 54.3618f, 3.77106f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 80: //Naxxramas
            plr->TeleportTo(571, 3668.72f, -1262.46f, 243.622f, 4.785f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 81: //Molten Core
            plr->TeleportTo(230, 1126.2f, -458.611f, -102.265f, 3.46095f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 82: //Karazhan
            plr->TeleportTo(0, -11120.2f, -2015.27f, 47.1869f, 1.91823f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 83: //Icecrown Citadel
            plr->TeleportTo(571, 5802.92f, 2077.74f, 636.064f, 3.58921f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 84: //Magtheridon's Lair
            plr->TeleportTo(530, -317.102f, 3094.48f, -116.43f, 5.20087f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 85: //Gruul's Lair
            plr->TeleportTo(530, 3539.19f, 5090.6f, 3.4088f, 5.93244f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 86: //Trial of the Crusader
            plr->TeleportTo(571, 8574.85f, 792.33f, 558.518f, 3.16358f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 87: //Serpentshrine Cavern
            plr->TeleportTo(530, 828.098f, 6865.51f, -63.7854f, 6.28049f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 88: //Hyjal Summit
            plr->TeleportTo(1, -8175.86f, -4175.53f, -166.181f, 0.932953f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 89: //Blackwing Lair
            plr->TeleportTo(469, -7665.66f, -1102.2f, 399.679f, 0.625119f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 90: //Black Temple
            plr->TeleportTo(530, -3637.56f, 315.554f, 35.5505f, 2.94599f);
            break;
            //------------------------cities---------------------------------//
        case GOSSIP_ACTION_INFO_DEF + 22: //Stormwind
            plr->TeleportTo(0, -8844.01f, 644.99f, 96.2429f, 5.33693f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 23: //Ironforge
            plr->TeleportTo(0, -4988.27f, -874.123f, 496.984f, 5.43054f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 24: //Darnassus
            plr->TeleportTo(1, 9949.24f, 2481.71f, 1316.2f, 2.11659f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 25: //The Exodar
            plr->TeleportTo(530, -3980.04f, -11638.001f, -138.987f, 5.77268f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 26: //Orgrimmar
            plr->TeleportTo(1, 1486.66f, -4415.39f, 24.1115f, 0.042373f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 27: //Undercity
            plr->TeleportTo(0, 1560.21f, 240.068f, -43.1026f, 0.036295f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 28: //Thunder Bluff
            plr->TeleportTo(1, -1197.09f, 29.4339f, 176.95f, 4.71385f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 29: //Silvermoon
            plr->TeleportTo(530, 9410.71f, -7277.97f, 14.1808f, 6.28265f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 30: //Dalaran
            plr->TeleportTo(571, 5807.95f, 587.651f, 660.938f, 1.69498f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 31: //Shattrath
            plr->TeleportTo(530, -1828.94f, 5361.03f, -12.428f, 2.03728f);
            break;

            //-------------------------Player tools--------------------------//
        case GOSSIP_ACTION_INFO_DEF + 2: //Buff me
            for (int i = 0; i < 11; i++)
                plr->AddAura(aurass[i], plr);
            plr->CastSpell(plr, 24705, 1);
            plr->GetSession()->SendNotification("You have been buffed!");
            plr->CLOSE_GOSSIP_MENU();
            break;
        case GOSSIP_ACTION_INFO_DEF + 4: // Repair
            plr->DurabilityRepairAll(false, 0, false);
            plr->GetSession()->SendNotification("Your items have been repaired!");
            plr->ModifyMoney(-10000);
            break;
        case GOSSIP_ACTION_INFO_DEF + 3: // Heal me
            plr->SetPower(POWER_MANA, plr->GetMaxPower(POWER_MANA));
            plr->SetHealth(plr->GetMaxHealth());
            plr->GetSession()->SendNotification("Your Health And Mana has been refilled.");
            break;

        case GOSSIP_ACTION_INFO_DEF + 5: // Close Function
            plr->CLOSE_GOSSIP_MENU();
            break;
        }
        return true;
    }
};

void AddSC_GossipNpc()
{
    new GossipNpc();
}

