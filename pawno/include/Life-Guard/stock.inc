//===================================[Инклюды]==================================
#include <a_samp>
#include <Life-Guard/foreach>
#include <Life-Guard/reader>
//================================[Переменные]==================================
new animlib[30], animname[30];
new F[5], S[10], M[3];
new Mes[3][144];
new string[144];

enum pInfo {
	pIP,
    pName[MAX_PLAYER_NAME]
};
new PlayerInfo[MAX_PLAYERS][pInfo];

//==================================[define]====================================
#define COLOR_LIGHTRED 		0xFF6347AA
#define SendAdm         	"[A] Игрок %s [ID %d] Подозревается в читерстве!"
#define SendConnect     	"[A] Игрок %s [ID %d] авторизировался(ась) на сервере!"
#define SendDisConnect  	"[A] Игрок %s [ID %d] отсоеденился(ась) от сервера [%s]"
#define D_CFG				921
//=================================[Функции]====================================
forward SecTimer();

public OnFilterScriptInit()
{
	new msg[64];
 	format(msg, sizeof(msg), "Loading...\n%s!", "Life-Guard v4.1 Loaded!");
  	print(msg);
	print("\n*--------------------------------------------------------*");
	print("*               Life-Guard Has Been Loaded!              *");
	print("*                 AntiCheat v 4.1 R3 Pro                 *");
	print("*                   Powered By Kazon!                    *");
	print("*--------------------------------------------------------*\n");
	return true;
}

public SecTimer()
{
	foreach(new i : Player)
	{
	    if(F[4] == 1 && IsPlayerAdmin(i)) continue;
   		if(F[1] == 1 && GetPlayerPing(i) > M[1])
		{
	 		SetPVarInt(i,"Ping", GetPVarInt(i,"Ping") +1);
	 		if(GetPVarInt(i,"Ping") >= 3)
	 		{
	 			SendMes(i, COLOR_LIGHTRED, "%s", Mes[2]);
			 	Kick(i);
	 		}
	 	}
		if(!IsPlayerInAnyVehicle(i) && GetPlayerState(i) == PLAYER_STATE_ONFOOT)
		{
		    GetAnimationName(GetPlayerAnimationIndex(i), animlib, sizeof(animlib), animname, sizeof(animname));
		    if(S[3] != 0 && SpeedVehicle(i) / 2 > 40) Slap(i, 3);
		    if(S[4] != 0) { if(strcmp(animlib, "PED", true) == 0 && strcmp(animname, "RUN_PLAYER", true) == 0) Slap(i, 4); }
    	}
    	if(S[4] != 0 && GetPlayerSpecialAction(i) == SPECIAL_ACTION_USEJETPACK) Slap(i, 4);
    	if(S[7] != 0 && GetPlayerWeapon(i) == 0 && GetPlayerAmmo(i) > 3)
    	{
  			ResetPlayerWeapons(i);
   			Slap(i, 7);
		}
		if(S[5] != 0 && GetPlayerState(i) == 2 && SpeedVehicle(i) / 2 > M[2]) Slap(i, 5);
		if(IsPlayerInAnyVehicle(i) && GetPlayerState(i) == 2)
		{
			if(GetPVarInt(i, "VehicleID") > 0 && GetPlayerVehicleID(i) != GetPVarInt(i, "VehicleID")) Kick(i);
			if(GetPVarInt(i, "PlayerCar") > 0 && GetPlayerVehicleID(i) != GetPVarInt(i, "PlayerCar")) Kick(i);
		}	
	}
    return true;
}

stock SendAdminMessage(color, str[])
{
    foreach(new i : Player) { if(IsPlayerAdmin(i)) SendClientMessage(i, color, str); }
	return true;
}

stock SpeedVehicle(playerid)
{
    new Float:ST[4];
	if(IsPlayerInAnyVehicle(playerid)) GetVehicleVelocity(GetPlayerVehicleID(playerid),ST[0],ST[1],ST[2]);
	else GetPlayerVelocity(playerid,ST[0],ST[1],ST[2]);
    ST[3] = floatsqroot(floatpower(floatabs(ST[0]), 2.0) + floatpower(floatabs(ST[1]), 2.0) + floatpower(floatabs(ST[2]), 2.0)) * 213.3;
    return floatround(ST[3]);
}

stock Slap(playerid, i)
{
	switch(S[i])
	{
		case 0: return true;
  		case 1: return SendMes(playerid, COLOR_LIGHTRED, "%s",Mes[0]), Kick(playerid);
    	case 2: return SendMes(playerid, COLOR_LIGHTRED, "%s",Mes[1]), Ban(playerid);
     	case 3: return SendAdmin(COLOR_LIGHTRED, SendAdm, PlayerInfo[playerid][pName], playerid);
     	default: return true;
	}
	return true;
}

stock SendMes(playerid, color, fstring[], {Float, _}:...)
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

stock SendAdmin(color, fstring[], {Float, _}:...)
{
    static const STATIC_ARGS = 2;
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
        return SendAdminMessage(color, message);
    }
    else return SendAdminMessage(color, fstring);
}
//================================[Загрузка]====================================
stock LoadMode()
{
    LoadCfg(), LoadSlap(), LoadMax(), LoadMes();
	SetTimer("SecTimer", 1000, 1);
    if(F[0] == 1) SendRconCommand("rcon 0");
    return true;
}

stock LoadCfg()
{
	if(!fexist("Life-Guard/Config.cfg")) return true;
 	new File = life_openFile("Life-Guard/Config.cfg");
	life_getInteger(File, "F[0]", F[0]);
	life_getInteger(File, "F[1]", F[1]);
	life_getInteger(File, "F[2]", F[2]);
	life_getInteger(File, "F[3]", F[3]);
	life_getInteger(File, "F[4]", F[4]);
	life_closeFile(File);
	return true;
}

stock LoadSlap()
{
	if(!fexist("Life-Guard/Slap.cfg")) return true;
 	new File = life_openFile("Life-Guard/Slap.cfg");
  	life_getInteger(File, "S[0]", S[0]);
	life_getInteger(File, "S[1]", S[1]);
 	life_getInteger(File, "S[2]", S[2]);
  	life_getInteger(File, "S[3]", S[3]);
  	life_getInteger(File, "S[4]", S[4]);
  	life_getInteger(File, "S[5]", S[5]);
  	life_getInteger(File, "S[6]", S[6]);
  	life_getInteger(File, "S[7]", S[7]);
	life_getInteger(File, "S[8]", S[8]);
	life_getInteger(File, "S[9]", S[9]);
  	life_closeFile(File);
	return true;
}

stock LoadMax()
{
    if(!fexist("Life-Guard/Max.cfg")) return true;
    new File = life_openFile("Life-Guard/Max.cfg");
    life_getInteger(File, "M[0]", M[0]);
    life_getInteger(File, "M[1]", M[1]);
    life_getInteger(File, "M[2]", M[2]);
    life_closeFile(File);
	return true;
}

stock LoadMes()
{
	if(!fexist("Life-Guard/Message.cfg")) return true;
 	new File = life_openFile("Life-Guard/Message.cfg");
	life_getString(File, "Mes[0]", Mes[0]);
	life_getString(File, "Mes[1]", Mes[1]);
	life_getString(File, "Mes[2]", Mes[2]);
	life_closeFile(File);
	return true;
}

stock SaveCfg()
{
    new File = life_openFile("Life-Guard/Config.cfg");
    life_setInteger(File, "F[0]", F[0]);
    life_setInteger(File, "F[1]", F[1]);
    life_setInteger(File, "F[2]", F[2]);
    life_setInteger(File, "F[3]", F[3]);
    life_setInteger(File, "F[4]", F[4]);
    life_closeFile(File);
	return true;
}

stock SaveSlap()
{
	new File = life_openFile("Life-Guard/Slap.cfg");
  	life_setInteger(File, "S[0]", S[0]);
	life_setInteger(File, "S[1]", S[1]);
 	life_setInteger(File, "S[2]", S[2]);
  	life_setInteger(File, "S[3]", S[3]);
  	life_setInteger(File, "S[4]", S[4]);
  	life_setInteger(File, "S[5]", S[5]);
  	life_setInteger(File, "S[6]", S[6]);
  	life_setInteger(File, "S[7]", S[7]);
	life_setInteger(File, "S[8]", S[8]);
	life_setInteger(File, "S[9]", S[9]);
  	life_closeFile(File);
	return true;
}

stock SaveMax()
{
	new File = life_openFile("Life-Guard/Max.cfg");
    life_setInteger(File, "M[0]", M[0]);
    life_setInteger(File, "M[1]", M[1]);
    life_setInteger(File, "M[2]", M[2]);
    life_closeFile(File);
	return true;
}

stock SaveMes()
{
	new File = life_openFile("Life-Guard/Message.cfg");
	life_setString(File, "Mes[0]", Mes[0]);
	life_setString(File, "Mes[1]", Mes[1]);
	life_setString(File, "Mes[2]", Mes[2]);
	life_closeFile(File);
	return true;
}

stock SaveAll()
{
	SaveCfg();
	SaveSlap();
	SaveMax();
	SaveMes();
	return true;
}

stock Cfg(playerid)
{
    new strin[350];
    format(strin, sizeof(strin), "Защита от взлома Rcon\t\t%s\nЗащита от Пинга\t\t\t%s\nЗащита от GodMod'a\t\t\t%s\nВывод логов Админам\t\t%s\nИгнорирование Админов\t\t%s",
    (!F[0]) ? ("{9ACD32}Включить") : ("{FF6347}Выключить"),(!F[1]) ? ("{9ACD32}Включить") : ("{FF6347}Выключить"),(!F[2]) ? ("{9ACD32}Включить") : ("{FF6347}Выключить"),
	(!F[3]) ? ("{9ACD32}Включить") : ("{FF6347}Выключить"),(!F[4]) ? ("{9ACD32}Включить") : ("{FF6347}Выключить"));
	return ShowPlayerDialog(playerid,D_CFG+2,DIALOG_STYLE_LIST,"Life-Guard",strin,"Принять","<< Назад");
}	

stock Maxs(playerid)
{
	new strin[250];
 	format(strin, 250, "Максимум неверных Rcon паролей\t\t{FF6347}%i\nМаксимальный пинг\t\t\t\t{FF6347}%i\nМаксимальная скорость\t\t\t{FF6347}%i",M[0],M[1],M[2]);
    return ShowPlayerDialog(playerid,D_CFG+3,DIALOG_STYLE_LIST,"Life-Guard",strin,"Принять","<< Назад");
}

stock Slaps(playerid)
{
	new strin[400];
	new aaa[15], bbb[15], vvv[15], lll[15], eee[15], www[15], ggg[15], ooo[15], ppp[15], mmm[15];
	switch(S[0]) { case 0: aaa = "Бездействие"; case 1: aaa = "Кик"; case 2: aaa = "Бан"; case 3: aaa = "Сообщение"; }
	switch(S[1]) { case 0: bbb = "Бездействие"; case 1: bbb = "Кик"; case 2: bbb = "Бан"; case 3: bbb = "Сообщение"; }
	switch(S[2]) { case 0: vvv = "Бездействие"; case 1: vvv = "Кик"; case 2: vvv = "Бан"; case 3: vvv = "Сообщение"; }
	switch(S[3]) { case 0: lll = "Бездействие"; case 1: lll = "Кик"; case 2: lll = "Бан"; case 3: lll = "Сообщение"; }
	switch(S[4]) { case 0: eee = "Бездействие"; case 1: eee = "Кик"; case 2: eee = "Бан"; case 3: eee = "Сообщение"; }
	switch(S[5]) { case 0: www = "Бездействие"; case 1: www = "Кик"; case 2: www = "Бан"; case 3: www = "Сообщение"; }
	switch(S[6]) { case 0: ggg = "Бездействие"; case 1: ggg = "Кик"; case 2: ggg = "Бан"; case 3: ggg = "Сообщение"; }
	switch(S[7]) { case 0: ooo = "Бездействие"; case 1: ooo = "Кик"; case 2: ooo = "Бан"; case 3: ooo = "Сообщение"; }
	switch(S[8]) { case 0: ppp = "Бездействие"; case 1: ppp = "Кик"; case 2: ppp = "Бан"; case 3: ppp = "Сообщение"; }
	switch(S[9]) { case 0: mmm = "Бездействие"; case 1: mmm = "Кик"; case 2: mmm = "Бан"; case 3: mmm = "Сообщение"; }
	format(strin, sizeof(strin), "За взлом Rcon\t\t\t{FF6347}%s\nЗа подмену диалогов\t\t{FF6347}%s\nЗа Air Breik\t\t\t{FF6347}%s\
	\nЗа Fly Hack\t\t\t{FF6347}%s\nЗа Sobeit\t\t\t{FF6347}%s\nЗа Speed Hack\t\t\t{FF6347}%s\nЗа тюнинг\t\t\t{FF6347}%s\nЗа оружие\t\t\t{FF6347}%s\nЗа краш цветом\t\t{FF6347}%s\
    \nЗа DriveBy\t\t\t{FF6347}%s",aaa,bbb,vvv,lll,eee,www,ggg,ooo,ppp,mmm);
    return ShowPlayerDialog(playerid,D_CFG+5,DIALOG_STYLE_LIST,"Life-Guard",strin,"Принять","<< Назад");
}

stock Mess(playerid)
{
    new strin[200];
    format(strin, 200, "%s\n%s\n%s",Mes[0],Mes[1],Mes[2]);
	return ShowPlayerDialog(playerid,D_CFG+7,DIALOG_STYLE_LIST,"Life-Guard",strin,"Принять","<< Назад");
}