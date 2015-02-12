/*
//Add Lever
INSERT INTO `gameobject_template` VALUES ('460105', '0', '85', 'ograid Hebel', '', '', '', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '7000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', 'ograid_doorlevers', '16357');
INSERT INTO `gameobject_template` VALUES ('460106', '0', '85', 'ograid Hebel', '', '', '', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '7000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', 'ograid_doorlevers', '16357');
INSERT INTO `gameobject_template` VALUES ('460113', '0', '85', 'ograid Hebel', '', '', '', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '7000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', 'ograid_doorlevers', '16357');
INSERT INTO `gameobject_template` VALUES ('460114', '0', '85', 'ograid Hebel', '', '', '', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '7000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', 'ograid_doorlevers', '16357');
INSERT INTO `gameobject_template` VALUES ('460115', '0', '85', 'ograid Hebel', '', '', '', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '7000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', 'ograid_doorlevers', '16357');
INSERT INTO `gameobject_template` VALUES ('460116', '0', '85', 'ograid Hebel', '', '', '', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '7000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', 'ograid_doorlevers', '16357');

//Add Doors
INSERT INTO `gameobject_template` VALUES ('460107', '0', '79', 'ograid_CAGEDOOR01', '', '', '', '0', '32', '1', '0', '0', '0', '0', '0', '0', '0', '859', '5000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '1');
INSERT INTO `gameobject_template` VALUES ('460108', '0', '80', 'ograid_SMALL_DOOR_01', '', '', '', '0', '32', '1', '0', '0', '0', '0', '0', '0', '0', '859', '5000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '1');
INSERT INTO `gameobject_template` VALUES ('460109', '0', '81', 'ograid_LARGEDOOR01', '', '', '', '0', '32', '1', '0', '0', '0', '0', '0', '0', '0', '859', '5000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '1');
INSERT INTO `gameobject_template` VALUES ('460110', '0', '82', 'ograid_BOSSDOOR', '', '', '', '0', '32', '1', '0', '0', '0', '0', '0', '0', '0', '859', '5000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '1');
INSERT INTO `gameobject_template` VALUES ('460111', '0', '83', 'ograid_TREXDOOR01', '', '', '', '0', '32', '1', '0', '0', '0', '0', '0', '0', '0', '859', '5000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '1');
INSERT INTO `gameobject_template` VALUES ('460112', '0', '84', 'ograid_DOOR01', '', '', '', '0', '32', '1', '0', '0', '0', '0', '0', '0', '0', '859', '5000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '1');

UPDATE gameobject_template SET ScriptName='ograid_doorlevers' WHERE entry=460105;
UPDATE gameobject_template SET ScriptName='ograid_doorlevers' WHERE entry=460106;
UPDATE gameobject_template SET ScriptName='ograid_doorlevers' WHERE entry=460113;
UPDATE gameobject_template SET ScriptName='ograid_doorlevers' WHERE entry=460114;
UPDATE gameobject_template SET ScriptName='ograid_doorlevers' WHERE entry=460115;
UPDATE gameobject_template SET ScriptName='ograid_doorlevers' WHERE entry=460116;
*/

enum DoorLever{
    max_now       =  6
};

int32 ograid_lever[max_now] = 
{
460105,
460106,
460113,
460114,
460115,
460116
};

int32 ograid_door[max_now] = 
{
460107,
460108,
460109,
460110,
460111,
460112
};

class ograid_doorlevers : public GameObjectScript
{
public:
    ograid_doorlevers() : GameObjectScript("ograid_doorlevers") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        for (int i = 0; i < max_now; i++){
        if (GameObject * ograid_Door = go->FindNearestGameObject(ograid_door[i], 100.0f))
        {
                ograid_Door->UseDoorOrButton();
                go->UseDoorOrButton();
        }
        }
            return true;

    }
};

void AddSC_ograid_doorlevers()
{
	new ograid_doorlevers();
}
