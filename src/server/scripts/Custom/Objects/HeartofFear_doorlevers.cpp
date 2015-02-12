/*
UPDATE gameobject_template SET ScriptName='HeartofFear_doorlevers' WHERE entry=460100;
UPDATE gameobject_template SET ScriptName='HeartofFear_doorlevers' WHERE entry=460101;
*/

enum DoorLever{
    max_now       =  2
};

int32 HeartofFear_lever[max_now] = 
{
460100,
460101
};

int32 HeartofFear_door[max_now] = 
{
4707,
4760
};

class HeartofFear_doorlevers : public GameObjectScript
{
public:
    HeartofFear_doorlevers() : GameObjectScript("HeartofFear_doorlevers") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        for (int i = 0; i < max_now; i++){
        if (GameObject * HeartofFear_Door = go->FindNearestGameObject(HeartofFear_door[i], 100.0f))
        {
                HeartofFear_Door->UseDoorOrButton();
                go->UseDoorOrButton();
        }
        }
            return true;

    }
};

void AddSC_HeartofFear_doorlevers()
{
	new HeartofFear_doorlevers();
}
