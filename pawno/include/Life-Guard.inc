//==================================[Native's]=========================================
native gpci(playerid, serial[], len);

native OnPluginInit();
native OnUserSpawn(playerid);
native OnUserUpdate(playerid);
native OnUserConnect(playerid);
//native PluginOnRconLogin(playerid, type);
native OnUserDisconnect(playerid);
//native PluginOnDialogResponse(playerid, dialogid);
//native PluginShowPlayerDialog(playerid, dialogid);
native OnVehStreamIn(playerid, forplayerid);
native OnUserExitVehicle(playerid, vehicleid);
native OnUserPickUpPickup(playerid, pickupid);
native OnUserDeath(playerid, killerid, reason);
native OnUserEnterVehicle(playerid, vehicleid);
native OnVehMod(playerid, vehicleid, componentid);
native OnUserStateChange(playerid, newstate, oldstate);
native OnUnoccupiedVehUpdate(vehicleid, passenger_seat);
native OnUserGiveDamage(playerid, damagedid, Float:amount);
//==================================[Native's]=========================================
native GetUserMoney(playerid);
native ResetUserMoney(playerid);
native ResetUserWeapons(playerid);
native GetUserAdmin(playerid, type);
native SetUserMoney(playerid, amount);
native GiveUserMoney(playerid, amount);
native RemoveUserFromVehicle(playerid);
native SetUserHealth(playerid, Float:HP);
native SetUserArmour(playerid, Float:AR);
//native SetPlayerLifeAction(playerid, actionid);
native GiveUserWeapon(playerid, weaponid, ammo);
native SetUserPos(playerid, Float:x, Float:y, Float:z);
native LSetVehiclePos(vehicleid, Float:x, Float:y, Float:z);
native CreateUserPickup(model, type, Float:x, Float:y, Float:z, world = 0);
native AddUserClass(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
//==================================[Forward's]=========================================
forward InvokeFunction();
forward Life_OnGameModeInit();
forward Life_OnPlayerSpawn(playerid);
forward Life_OnPlayerUpdate(playerid);
forward Life_OnPlayerConnect(playerid);
forward Life_OnPlayerDisconnect(playerid, reason);
forward Life_OnPlayerPickUpPickup(playerid, pickupid);
forward Life_OnPlayerExitVehicle(playerid, vehicleid);
forward Life_OnPlayerDeath(playerid, killerid, reason);
forward Life_OnVehicleStreamIn(vehicleid, forplayerid);
//forward Life_OnRconLoginAttempt(ip[], password[], success);
forward Life_OnVehicleMod(playerid, vehicleid, componentid);
forward Life_OnPlayerStateChange(playerid, newstate, oldstate);
forward Life_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
forward Life_OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat); 
forward Life_OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid);
//forward Life_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
//==================================[Public's]=========================================
public OnGameModeInit()
{
	OnPluginInit();
	if(funcidx("Life_OnGameModeInit") != -1) return CallLocalFunction("Life_OnGameModeInit", "");
	else return true;
}

public OnPlayerConnect(playerid)
{
	OnUserConnect(playerid);
	if(funcidx("Life_OnPlayerConnect") != -1) return CallLocalFunction("Life_OnPlayerConnect", "i", playerid);
	else return true;
}

public OnPlayerDisconnect(playerid, reason)
{
	OnUserDisconnect(playerid);
	if(funcidx("Life_OnPlayerDisconnect") != -1) return CallLocalFunction("Life_OnPlayerDisconnect", "ii", playerid, reason);
	else return true;
}

public OnPlayerSpawn(playerid)
{
	OnUserSpawn(playerid);
	if(funcidx("Life_OnPlayerSpawn") != -1) return CallLocalFunction("Life_OnPlayerSpawn", "i", playerid);
	else return true;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	OnUserDeath(playerid, killerid, reason);
	if(funcidx("Life_OnPlayerDeath") != -1) return CallLocalFunction("Life_OnPlayerDeath", "iii", playerid, killerid, reason);
	else return true;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	OnUserEnterVehicle(playerid, vehicleid);
	if(funcidx("Life_OnPlayerEnterVehicle") != -1) return CallLocalFunction("Life_OnPlayerEnterVehicle", "iii", playerid, vehicleid, ispassenger);
	else return true;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	OnUserExitVehicle(playerid, vehicleid);
	if(funcidx("Life_OnPlayerExitVehicle") != -1) return CallLocalFunction("Life_OnPlayerExitVehicle", "ii", playerid, vehicleid);
	else return true;
}

/*public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{ 
	if(PluginOnDialogResponse(playerid, dialogid) && funcidx("Life_OnDialogResponse") != -1)
	{
		if(!strlen(inputtext))
		{
			strmid(inputtext, "", 0, strlen(""), 16);
			return CallLocalFunction("Life_OnDialogResponse", "iiiis", playerid, dialogid, response, listitem, inputtext);
		}	
		else return CallLocalFunction("Life_OnDialogResponse", "iiiis", playerid, dialogid, response, listitem, inputtext);
	}
	else return true;
}*/

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid)
{
	OnUserGiveDamage(playerid, damagedid, amount);
	if(funcidx("Life_OnPlayerGiveDamage") != -1) return CallLocalFunction("Life_OnPlayerGiveDamage", "iifi", playerid, damagedid, amount, weaponid);
	else return true;
}

public OnPlayerUpdate(playerid)
{
	OnUserUpdate(playerid);
	if(funcidx("Life_OnPlayerUpdate") != -1) return CallLocalFunction("Life_OnPlayerUpdate", "i", playerid);
	else return true;
}

public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat) 
{
	OnUnoccupiedVehUpdate(vehicleid, passenger_seat);
	if(funcidx("Life_OnUnoccupiedVehicleUpdate") != -1) return CallLocalFunction("Life_OnUnoccupiedVehicleUpdate", "iii", vehicleid, playerid, passenger_seat);
	else return true;
}

public OnVehicleStreamIn(vehicleid, forplayerid) 
{
	OnVehStreamIn(vehicleid, forplayerid);
	if(funcidx("Life_OnVehicleStreamIn") != -1) return CallLocalFunction("Life_OnVehicleStreamIn", "ii", vehicleid, forplayerid);
	else return true;
}

/*public OnRconLoginAttempt(ip[], password[], success)
{	
    if(success) return true;
	new ips[16], Error[MAX_PLAYERS];
	for(new i; i <= GetMaxPlayers(); ++i)
	{
		GetPlayerIp(i, ips, sizeof(ips));
		if(strcmp(ip, ips, true)) break;
		Error[i]++;
		PluginOnRconLogin(i, Error[i]);
		break;
	}
    if(funcidx("Life_OnRconLoginAttempt") != -1) return CallLocalFunction("Life_OnRconLoginAttempt", "ssi", ip, password, success);
	else return true;
}*/

public OnVehicleMod(playerid, vehicleid, componentid)
{
	OnVehMod(playerid, vehicleid, componentid);
	if(funcidx("Life_OnVehicleMod") != -1) return CallLocalFunction("Life_OnVehicleMod", "iii", playerid, vehicleid, componentid);
	else return true;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	OnUserStateChange(playerid, newstate, oldstate);
	if(funcidx("Life_OnPlayerStateChange") != -1) return CallLocalFunction("Life_OnPlayerStateChange", "iii", playerid, newstate, oldstate);
	else return true;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
	if(!OnUserPickUpPickup(playerid, pickupid) && funcidx("Life_OnPlayerPickUpPickup") != -1) return CallLocalFunction("Life_OnPlayerPickUpPickup", "ii", playerid, pickupid);
	else return true;
}
//================================[Func Stock's]=======================================
/*stock ShowLifeDialog(playerid, dialogid, style, caption[], info[], button1[], button2[])
{ 
	if(PluginShowPlayerDialog(playerid, dialogid)) ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2);
	return true;
}*/
//==================================[Other's]=========================================
public InvokeFunction()
{
	new Life[144], Char[144], Float:Flt, Int;
	Kick(0);
	GetTickCount();
	GetMaxPlayers();
	GetPlayerAmmo(0);
	GetPlayerPing(0);
	GetPlayerSkin(0);
	IsPlayerAdmin(0);
	BanEx(0, "Life");
	GetPlayerMoney(0);
	GetPlayerColor(0);
	GetPlayerState(0);
	GetPlayerWeapon(0);
	GetVehicleModel(0);
	ResetPlayerMoney(0);
	GetPlayerInterior(0);
	IsPlayerConnected(0);
	ResetPlayerWeapons(0);
	GivePlayerMoney(0, 0);
	GetPlayerVehicleID(0);
	SendRconCommand("Life");
	IsPlayerInAnyVehicle(0);
	SetPlayerHealth(0, 0.0);
	SetPlayerArmour(0, 0.0);
	GetPlayerHealth(0, Flt);
	GetPlayerArmour(0, Flt);
	GivePlayerWeapon(0, 0, 0);
	GetPlayerSpecialAction(0);
	RemovePlayerFromVehicle(0);
	GetPlayerAnimationIndex(0);
	gpci(0, Life, sizeof(Life));
	SetPlayerSpecialAction(0, 0);
	RemoveVehicleComponent(0, 0);
	GetPlayerSurfingVehicleID(0);
	SetPlayerPos(0, 0.0, 0.0, 0.0);
	GetPlayerPos(0, Flt, Flt, Flt);
	SendClientMessage(0, 0, "Life");
	SetVehiclePos(0, 0.0, 0.0, 0.0);
	GetVehiclePos(0, Flt, Flt, Flt);
	SendClientMessageToAll(0, "Life");
	GetPlayerVelocity(0, Flt, Flt, Flt);
	GetPlayerWeaponData(0, 0, Int, Int);
	GetVehicleVelocity(0, Flt, Flt, Flt);
	GetPlayerName(0, Life, sizeof(Life));
	CreatePickup(0, 0, 0.0, 0.0, 0.0, 0);
	GetPlayerVersion(0, Life, sizeof(Life));
	IsPlayerInRangeOfPoint(0, 0.0, 0.0, 0.0, 0.0);
	AddPlayerClass(0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
	ShowPlayerDialog(0, 0, 0, "Life", "Life", "Life", "Life");
	GetAnimationName(0, Life, sizeof(Life), Char, sizeof(Char));
	GetVehicleRotationQuat(0, Flt, Flt, Flt, Flt);
	return true;
}

//===================================[Define's]==========================================
#define SetPlayerPos SetUserPos
#define SetVehiclePos LSetVehiclePos
#define AddPlayerClass AddUserClass
#define GetPlayerMoney GetUserMoney
#define GivePlayerMoney GiveUserMoney
#define SetPlayerHealth SetUserHealth
#define SetPlayerArmour SetUserArmour
#define CreatePickup CreateUserPickup
#define ResetPlayerMoney ResetUserMoney
//#define ShowPlayerDialog ShowLifeDialog
#define GivePlayerWeapon GiveUserWeapon
#define ResetPlayerWeapons ResetUserWeapons
//#define SetPlayerSpecialAction SetPlayerLifeAction
#define RemovePlayerFromVehicle RemoveUserFromVehicle
//==================================[UnDefine's]=========================================
#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit Life_OnGameModeInit

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect Life_OnPlayerConnect

#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect Life_OnPlayerDisconnect

#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn Life_OnPlayerSpawn

#if defined _ALS_OnPlayerDeath
    #undef OnPlayerDeath
#else
    #define _ALS_OnPlayerDeath
#endif
#define OnPlayerDeath Life_OnPlayerDeath

#if defined _ALS_OnPlayerEnterVehicle
    #undef OnPlayerEnterVehicle
#else
    #define _ALS_OnPlayerEnterVehicle
#endif
#define OnPlayerEnterVehicle Life_OnPlayerEnterVehicle

#if defined _ALS_OnPlayerExitVehicle
    #undef OnPlayerExitVehicle
#else
    #define _ALS_OnPlayerExitVehicle
#endif
#define OnPlayerExitVehicle Life_OnPlayerExitVehicle

/*#if defined _ALS_OnDialogResponse
    #undef OnDialogResponse
#else
    #define _ALS_OnDialogResponse
#endif
#define OnDialogResponse Life_OnDialogResponse*/

#if defined _ALS_OnPlayerGiveDamage
    #undef OnPlayerGiveDamage
#else
    #define _ALS_OnPlayerGiveDamage
#endif
#define OnPlayerGiveDamage Life_OnPlayerGiveDamage

#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate Life_OnPlayerUpdate

#if defined _ALS_OnVehicleStreamIn
    #undef OnVehicleStreamIn
#else
    #define _ALS_OnVehicleStreamIn
#endif
#define OnVehicleStreamIn Life_OnVehicleStreamIn

#if defined _ALS_OnUnoccupiedVehicleUpdate
    #undef OnUnoccupiedVehicleUpdate
#else
    #define _ALS_OnUnoccupiedVehicleUpdate
#endif
#define OnUnoccupiedVehicleUpdate Life_OnUnoccupiedVehicleUpdate

/*#if defined _ALS_OnRconLoginAttempt
    #undef OnRconLoginAttempt
#else
    #define _ALS_OnRconLoginAttempt
#endif
#define OnRconLoginAttempt Life_OnRconLoginAttempt*/

#if defined _ALS_OnVehicleMod
    #undef OnVehicleMod
#else
    #define _ALS_OnVehicleMod
#endif
#define OnVehicleMod Life_OnVehicleMod

#if defined _ALS_OnPlayerStateChange
    #undef OnPlayerStateChange
#else
    #define _ALS_OnPlayerStateChange
#endif
#define OnPlayerStateChange Life_OnPlayerStateChange

#if defined _ALS_OnPlayerPickUpPickup
    #undef OnPlayerPickUpPickup
#else
    #define _ALS_OnPlayerPickUpPickup
#endif
#define OnPlayerPickUpPickup Life_OnPlayerPickUpPickup