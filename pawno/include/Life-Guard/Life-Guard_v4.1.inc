//================================[Include]=====================================
#include <a_samp>
#include <Life-Guard/foreach>
#include <Life-Guard/reader>
//=================================[New's]======================================
enum LInfo {
    nName[MAX_PLAYER_NAME],
	Float:nHeal,
	Float:nArm,
	nCash
};
new LifeInfo[MAX_PLAYERS][LInfo];

enum lPickInfo {
    Float: Pick[3],
};
new LifePick[MAX_PICKUPS][lPickInfo];

new LifeStr[144];
new F[3], S[3], Mes[3][144];
new Life;
new WeaponSlot[MAX_PLAYERS][13], AmmoSlot[MAX_PLAYERS][13];
new Weapons[13][2];

#define COLOR_LIGHTREDL 	0xFF6347AA
#define SendAdm         	"[A] Игрок %s [ID %d] Подозревается в читерстве!"
//===============================[Forwards]=====================================
forward LifeGuard();
forward LifeRemove(playerid);
forward Life_OnGameModeInit();
forward Life_OnPlayerSpawn(playerid);
forward Life_OnPlayerConnect(playerid);
forward Life_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
forward Life_OnPlayerPickUpPickup(playerid, pickupid);
forward Life_OnPlayerUpdate(playerid);
//================================[Public]======================================
public LifeGuard()
{
	foreach(Player, i)
	{
	    if(F[1] == 1 && IsPlayerAdmin(i)) continue;
	    if(GetPVarInt(i, "AntiBreik") > 0) SetPVarInt(i, "AntiBreik", GetPVarInt(i, "AntiBreik") -1);
	    HealthCheckL(i), ArmourCheckL(i), MoneyCheckL(i), AirBrk(i);
	}
	return true;
}

public OnGameModeInit()
{
    LoadCfg(), LoadSlap(), LoadMes();
	SetTimer("LifeGuard", 1000, 1);
	return CallLocalFunction("Life_OnGameModeInit", "");
}

public OnPlayerSpawn(playerid)
{
    SetPVarInt(playerid, "AntiBreik", 3);
    SetLifeHeal(playerid, 100.0);
	return CallLocalFunction("Life_OnPlayerSpawn", "i",playerid);
}

public OnPlayerConnect(playerid)
{
	SetPVarInt(playerid, "DialogID", -1);
    SetPVarInt(playerid, "AntiBreik", 1000);
    GetPlayerName(playerid, LifeInfo[playerid][nName], MAX_PLAYER_NAME);
    return CallLocalFunction("Life_OnPlayerConnect", "i", playerid);
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{ 
	new pwn = strlen(inputtext);
	if(S[0] != 0 && GetPVarInt(playerid,"DialogID") != dialogid && !IsPlayerAdmin(playerid)) Slap(playerid, 0);
	SetPVarInt(playerid, "DialogID", -1);
	if(!pwn) return CallLocalFunction("Life_OnDialogResponse","iiiis",playerid, dialogid, response, listitem, "#");
	return CallLocalFunction("Life_OnDialogResponse","iiiis",playerid, dialogid, response, listitem, inputtext);
}

public OnPlayerPickUpPickup(playerid, pickupid)  
{
	if(!IsPlayerInRangeOfPoint(playerid, 10.0, LifePick[pickupid][Pick][0], LifePick[pickupid][Pick][1], LifePick[pickupid][Pick][2])) return true;
	return CallLocalFunction("Life_OnPlayerPickUpPickup", "ii", playerid, pickupid);
}

public OnPlayerUpdate(playerid)
{
	for(new g; g < 13; g++)
	{
		GetPlayerWeaponData(playerid, g, Weapons[g][0], Weapons[g][1]);
		if(Weapons[g][0] != WeaponSlot[playerid][g]) Slap(playerid, 2);
		if(Weapons[g][1] > AmmoSlot[playerid][g]) Slap(playerid, 2);
		else AmmoSlot[playerid][g] = Weapons[g][1];
	}
	return CallLocalFunction("Life_OnPlayerUpdate", "i", playerid);
}
//===============================[Stock's]======================================
stock ShowDialog(playerid, dialogid, style, caption[], info[], button1[], button2[]) 
{ 
    if(GetPVarInt(playerid, "DialogID") != -1) return true; 
    SetPVarInt(playerid, "DialogID", dialogid); 
    return ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2); 
}

stock SetLifePos(playerid, Float:x, Float:y, Float:z)
{
	SetPVarFloat(playerid, "PosX", x);
	SetPVarFloat(playerid, "PosY", y);
	SetPVarFloat(playerid, "PosZ", z);
	SetPVarInt(playerid, "AntiBreik", 3);
	SetPlayerPos(playerid, x, y, z);
	return true;
}

stock SetLifeHeal(playerid, Float:Heal)
{
	LifeInfo[playerid][nHeal] = Heal;
	SetPlayerHealth(playerid, Heal);
	return true;
}

stock SetLifeArmour(playerid, Float: Arm)
{
	LifeInfo[playerid][nArm] = Arm;
	SetPlayerArmour(playerid, Arm);
	return true;
}

stock GiveLifeMoney(playerid, amount)
{
	LifeInfo[playerid][nCash] += amount;
	GivePlayerMoney(playerid, amount);
	return true;
}

stock SetLifeMoney(playerid, amount)
{
	LifeInfo[playerid][nCash] = amount;
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, amount);
	return true;
}

stock ResetLifeMoney(playerid)
{
	LifeInfo[playerid][nCash] = 0;
	ResetPlayerMoney(playerid);
	return true;
}

stock GetLifeMoney(playerid) return LifeInfo[playerid][nCash];

stock HealthCheckL(i)
{
	new Float:Heal;
 	GetPlayerHealth(i, Heal);
  	if(LifeInfo[i][nHeal] < Heal) SetPlayerHealth(i, LifeInfo[i][nHeal]);
   	else LifeInfo[i][nHeal] = Heal;
	return true;
}

stock ArmourCheckL(i)
{
	new Float:Arm;
 	GetPlayerArmour(i, Arm);
  	if(LifeInfo[i][nArm] < Arm) SetPlayerArmour(i, LifeInfo[i][nArm]);
  	else LifeInfo[i][nArm] = Arm;
	return true;
}

stock MoneyCheckL(i)
{
	if(GetPlayerMoney(i) > LifeInfo[i][nCash])
	{
		if((GetPlayerMoney(i) - LifeInfo[i][nCash]) > 1) SetLifeMoney(i,LifeInfo[i][nCash]);
	}
	return true;
}

stock SendAdminMes(color, str[])
{
    foreach(new i : Player) { if(IsPlayerAdmin(i)) SendClientMessage(i, color, str); }
	return true;
}

stock RemoveFromVehicle(playerid)
{
	SetPVarInt(playerid,"Remove", 1);
	RemovePlayerFromVehicle(playerid);
	Life = SetTimerEx("LifeRemove", 3000, 0, "i", playerid);
	return true;
}

public LifeRemove(playerid)
{
	if(IsPlayerInAnyVehicle(playerid) && GetPVarInt(playerid,"Remove") == 1)
	{
		DeletePVar(playerid,"Remove");
		KillTimer(Life);
		Kick(playerid);
	}
	else if(!IsPlayerInAnyVehicle(playerid) && GetPVarInt(playerid,"Remove") == 1)
	{
		DeletePVar(playerid,"Remove");
		KillTimer(Life);
	}
	return true;
}

stock CreatePlayerPickup(model, type, Float:X, Float:Y, Float:Z, virtualworld = 0)
{
	new LifeP = CreatePickup(model, type, X, Y, Z, virtualworld);
	LifePick[LifeP][Pick][0] = X;
	LifePick[LifeP][Pick][1] = Y;
	LifePick[LifeP][Pick][2] = Z;
	return LifeP;
}

stock GiveWeapons(playerid, weaponid, ammo)
{
	switch(weaponid)
	{
		case 1: { WeaponSlot[playerid][0] = weaponid; AmmoSlot[playerid][0] = ammo; }
		case 2..9: { WeaponSlot[playerid][1] = weaponid; AmmoSlot[playerid][1] = ammo; }
		case 22..24: { WeaponSlot[playerid][2] = weaponid; AmmoSlot[playerid][2] = ammo; }
		case 25..27: { WeaponSlot[playerid][3] = weaponid; AmmoSlot[playerid][3] = ammo; }
		case 28,29,32: { WeaponSlot[playerid][4] = weaponid; AmmoSlot[playerid][4] = ammo; }
		case 30,31: { WeaponSlot[playerid][5] = weaponid; AmmoSlot[playerid][5] = ammo; }
		case 33,34: { WeaponSlot[playerid][6] = weaponid; AmmoSlot[playerid][6] = ammo; }
		case 35..38: { WeaponSlot[playerid][7] = weaponid; AmmoSlot[playerid][7] = ammo; }
		case 16..18,39: { WeaponSlot[playerid][8] = weaponid; AmmoSlot[playerid][8] = ammo; }
		case 41..43: { WeaponSlot[playerid][9] = weaponid; AmmoSlot[playerid][9] = ammo; }
		case 10..15: { WeaponSlot[playerid][10] = weaponid; AmmoSlot[playerid][10] = ammo; }
		case 44..46: { WeaponSlot[playerid][11] = weaponid; AmmoSlot[playerid][11] = ammo; }
		default: { WeaponSlot[playerid][12] = weaponid; AmmoSlot[playerid][12] = ammo; }
	}
	GivePlayerWeapon(playerid, weaponid, ammo);
	return true;
}

stock ResetWeapon(playerid)
{
	for(new s; s < 13; s++)
	{
		WeaponSlot[playerid][s] = 0;
		AmmoSlot[playerid][s] = 0;
	}
	ResetPlayerWeapons(playerid);
	return true;
}

stock AirBrk(playerid)
{
	if(S[1] != 0 && GetPVarInt(playerid, "AntiBreik") == 0)
	{
	   	new Float:Pos[4];
	    GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
	    Pos[3] = floatround(GetPlayerDistanceFromPoint(playerid, GetPVarFloat(playerid, "PosX"), GetPVarFloat(playerid, "PosY"), GetPVarFloat(playerid, "PosZ")));
		if(GetPVarInt(playerid, "Air") > 1) Slap(playerid, 1);
		if(Pos[3] > 100) Slap(playerid, 1);
		else if(Pos[3] < 100 && Pos[3] > 70)
   		{
		   	SetPVarInt(playerid,"Air",GetPVarInt(playerid,"Air") +1);
			format(LifeStr, 70, SendAdm, LifeInfo[playerid][nName], playerid);
			SendAdminMes(COLOR_LIGHTREDL, LifeStr);
   		}
		SetPVarFloat(playerid, "PosX", Pos[0]);
		SetPVarFloat(playerid, "PosY", Pos[1]);
		SetPVarFloat(playerid, "PosZ", Pos[2]);
	}
	return true;
}

stock Slap(playerid, i)
{
    if(F[1] == 1 && IsPlayerAdmin(playerid)) return true;
	switch(S[i])
	{
		case 0: return true;
  		case 1: return SendMessage(playerid, COLOR_LIGHTREDL, "%s",Mes[0]), Kick(playerid);
    	case 2: return SendMessage(playerid, COLOR_LIGHTREDL, "%s",Mes[1]), Ban(playerid);
		case 3:
		{
			format(LifeStr, 70, SendAdm, LifeInfo[playerid][nName], playerid);
			return SendAdminMes(COLOR_LIGHTREDL, LifeStr);
		}
	}
	return true;
}

stock SendMessage(playerid, color, fstring[], {Float, _}:...)
{
    static const STATIC_ARGS = 3;
    new n = (numargs() - STATIC_ARGS) * (cellbits / 8);
    if(n)
    {
        new message[128], arg_start, arg_end;
        #emit CONST.alt         fstring
        #emit LCTRL          	5
        #emit ADD
        #emit STOR.S.pri        arg_start
        #emit LOAD.S.alt        n
        #emit ADD
        #emit STOR.S.pri        arg_end
        do
        {
            #emit LOAD.I
            #emit PUSH.pri
            arg_end -= (cellbits / 8);
            #emit LOAD.S.pri   arg_end
        }
        while (arg_end > arg_start);
        #emit PUSH.S          fstring
        #emit PUSH.C          128
        #emit PUSH.ADR        message
        n += (cellbits / 8) * 3;
        #emit PUSH.S          n
        #emit SYSREQ.C        format
        n += (cellbits / 8);
        #emit LCTRL          4
        #emit LOAD.S.alt     n
        #emit ADD
        #emit SCTRL          4
        return SendClientMessage(playerid, color, message);
    }
    else return SendClientMessage(playerid, color, fstring);
}

stock LoadCfg()
{
	if(!fexist("Life-Guard/Config.cfg")) return true;
 	new File = life_openFile("Life-Guard/Config.cfg");
	life_getInteger(File, "F[2]", F[0]);
	life_getInteger(File, "F[4]", F[1]);
	life_closeFile(File);
	return true;
}

stock LoadSlap()
{
	if(!fexist("Life-Guard/Slap.cfg")) return true;
 	new File = life_openFile("Life-Guard/Slap.cfg");
	life_getInteger(File, "S[1]", S[0]);
 	life_getInteger(File, "S[2]", S[1]);
	life_getInteger(File, "S[7]", S[2]);
  	life_closeFile(File);
	return true;
}

stock LoadMes()
{
	if(!fexist("Life-Guard/Message.cfg")) return true;
 	new File = life_openFile("Life-Guard/Message.cfg");
	life_getString(File, "Mes[0]", Mes[0]);
	life_getString(File, "Mes[1]", Mes[1]);
	life_closeFile(File);
	return true;
}

//=============================[UnDefines]======================================
#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit Life_OnGameModeInit

#if defined _ALS_OnDialogResponse
    #undef OnDialogResponse
#else
    #define _ALS_OnDialogResponse
#endif
#define OnDialogResponse Life_OnDialogResponse

#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn Life_OnPlayerSpawn

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect Life_OnPlayerConnect

#if defined _ALS_OnPlayerPickUpPickup
    #undef OnPlayerPickUpPickup
#else
    #define _ALS_OnPlayerPickUpPickup
#endif
#define OnPlayerPickUpPickup Life_OnPlayerPickUpPickup

#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate Life_OnPlayerUpdate
//===============================[Defines]======================================
#define ShowPlayerDialog ShowDialog
#define SetPlayerHealth SetLifeHeal
#define SetPlayerArmour SetLifeArmour
#define SetPlayerPos SetLifePos
#define GetPlayerMoney GetLifeMoney
#define GivePlayerMoney GiveLifeMoney
#define ResetPlayerMoney ResetLifeMoney
#define RemovePlayerFromVehicle RemoveFromVehicle
#define CreatePickup CreatePlayerPickup
#define GivePlayerWeapon GiveWeapons
#define ResetPlayerWeapons ResetWeapon