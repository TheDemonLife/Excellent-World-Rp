#include <a_samp>

new Float:PlayerArmour[MAX_PLAYERS];
new Float:PlayerHealth[MAX_PLAYERS];

forward Updats();

public Updats()
{
    HealthCheck();
    ArmourCheck();
	return true;
}

stock SetHealthL(playerid, Float:Heal)
{
	PlayerHealth[playerid] = Heal;
	return SetPlayerHealth(playerid, Heal);
}
#define SetPlayerHealth SetHealthL

stock SetArmourL(playerid, Float: Arm)
{
	PlayerArmour[playerid] = Arm;
	return SetPlayerArmour(playerid, Arm);
}
#define SetPlayerArmour SetArmourL

stock HealthCheck()
{
	new Float:Heal;
    for(new i = GetMaxPlayers() - 1; i != -1; i--)
    {
        if(!IsPlayerConnected(i)) continue;
        GetPlayerHealth(i, Heal);
        if(PlayerHealth[i] < Heal) SetPlayerHealth(i, PlayerHealth[i]);
        else PlayerHealth[i] = Heal;
    }
}

stock ArmourCheck()
{
	new Float:Arm;
    for(new i = GetMaxPlayers() - 1; i != -1; i--)
    {
        if(!IsPlayerConnected(i)) continue;
        GetPlayerArmour(i, Arm);
        if(PlayerArmour[i] < Arm) SetPlayerArmour(i, PlayerArmour[i]);
        else PlayerArmour[i] = Arm;
    }
}
