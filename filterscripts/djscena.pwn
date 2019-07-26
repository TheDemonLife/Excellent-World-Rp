#include <a_samp>
#include <streamer>
new gates[6];
new bool:vor;
new bane;
new obj[20];
new bool:load;
new bool:anim;
new bool:dj;
new Text:Textdraw0;
new dum[6];
new bool:dumka;
new bool:text;
new bool:podcasscor[MAX_PLAYERS];
new pickup_dj;
new skin_dj[MAX_PLAYERS];
new neones[28];
new bool:neons;
new golosc;
new golos;
new bool:PlayerLiked[MAX_PLAYERS];


forward open();
forward objects();
forward effects0();
forward effects00();
forward effects();
forward effects22();
forward effects33();

public OnGameModeInit()
{
    golosc = CreateObject(19325, 216.79990, -1825.08728, 6.92180,   0.00000, -2.68000, 140.00000);

	Textdraw0 = TextDrawCreate(491.500000, 422.187500, "-");
	TextDrawLetterSize(Textdraw0, 0.449999, 1.600000);
	TextDrawAlignment(Textdraw0, 1);
	TextDrawColor(Textdraw0, 16711935);
	TextDrawSetShadow(Textdraw0, 0);
	TextDrawSetOutline(Textdraw0, 1);
	TextDrawBackgroundColor(Textdraw0, 51);
	TextDrawFont(Textdraw0, 1);
	TextDrawSetProportional(Textdraw0, 1);
	
	pickup_dj = CreatePickup(1275, 2, 194.9504,-1851.3961,7.9302);

	CreateDynamicObject(19129, 181.53450, -1832.30798, 5.29660,   90.00000, 0.00000, 90.00000);
    CreateDynamicObject(19129, 181.53763, -1842.18933, 5.29660,   90.00000, 0.00000, 90.00000);
	//========================================================================================
	CreateDynamicObject(18668, 200.66731, -1848.51941, 6.88706,   0.00000, 0.00000, 0.00000); // 1
	CreateDynamicObject(18668, 200.6388, -1826.2354, 6.8871,   0.00000, 0.00000, 0.00000); // 2
//========================= танцпол ======================================
	CreateDynamicObject(18765, 221.55550, -1829.65430, 1.03570,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19129, 226.52470, -1834.60205, 3.48570,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18765, 221.53795, -1839.64197, 1.03570,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18765, 231.53970, -1839.64392, 1.03570,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18765, 231.53824, -1829.65259, 1.03570,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 236.41911, -1844.55066, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 236.42924, -1839.65930, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 236.42883, -1834.61621, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 236.41344, -1829.64465, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 236.41959, -1824.72534, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 231.51988, -1824.73950, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 226.50789, -1824.76025, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 221.50232, -1824.75439, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 216.63618, -1824.77441, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 216.65106, -1829.63232, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 216.64009, -1834.64856, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 216.65021, -1839.66309, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 216.63089, -1844.55872, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 221.51987, -1844.55640, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 226.52678, -1844.53247, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 231.53357, -1844.50757, 3.63280,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3472, 226.68008, -1824.08130, 2.25242,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3472, 226.52588, -1844.89612, 1.54417,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(16151, 225.01201, -1825.75879, 3.86893,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(14387, 237.90091, -1832.70654, 2.53840,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(983, 226.92380, -1824.62109, 4.17838,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(983, 233.30008, -1824.63318, 4.17838,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(983, 220.54388, -1824.61987, 4.17838,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(983, 219.72740, -1824.62708, 4.17840,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(983, 216.53661, -1827.81592, 4.17840,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(983, 216.52190, -1834.20911, 4.17840,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(983, 216.52696, -1840.60059, 4.17840,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(983, 216.52950, -1841.42200, 4.17840,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(983, 219.73486, -1844.63208, 4.17838,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(983, 226.13458, -1844.62891, 4.17838,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(983, 232.53519, -1844.63953, 4.17838,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(983, 233.33405, -1844.62817, 4.17838,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(983, 236.52715, -1841.43250, 4.17840,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(983, 236.50890, -1837.68555, 4.17840,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(983, 236.49251, -1827.87134, 4.17840,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(983, 234.52936, -1830.34253, 2.75609,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(983, 234.52986, -1835.04211, 2.75609,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(1703, 227.68210, -1843.96753, 3.44600,   0.00000, 0.00000, 180.00000);//
	CreateDynamicObject(1703, 231.22675, -1844.03149, 3.44597,   0.00000, 0.00000, 180.00000);//
	CreateDynamicObject(1703, 234.84177, -1843.89026, 3.44600,   0.00000, 0.00000, 180.00000);//
	CreateDynamicObject(1703, 223.99159, -1843.94934, 3.44600,   0.00000, 0.00000, 180.00000);//
	CreateDynamicObject(1703, 220.14708, -1843.95569, 3.44600,   0.00000, 0.00000, 180.00000);//
	CreateDynamicObject(2232, 217.08357, -1843.63684, 4.13731,   0.00000, 0.00000, -221.88004);
	CreateDynamicObject(2232, 217.23767, -1825.28357, 4.13731,   0.00000, 0.00000, -317.04001);
	CreateDynamicObject(2232, 235.94246, -1825.32922, 4.13731,   0.00000, 0.00000, -399.17993);
	CreateDynamicObject(2232, 235.95978, -1843.76526, 4.13731,   0.00000, 0.00000, -499.43973);
	CreateDynamicObject(18650, 223.47031, -1827.06787, 4.42690,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(18650, 225.47031, -1827.06787, 4.42690,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(18650, 226.83031, -1827.06787, 4.42690,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(19125, 236.52791, -1831.02795, 3.96592,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18691, 236.52051, -1831.13623, 3.76977,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19125, 236.53749, -1834.48242, 3.96592,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18691, 236.46060, -1831.12378, 4.22475,   0.00000, 0.00000, 0.00000);
	Create3DTextLabel("{FF0000}Подойдите к бару и нажмите ALT чтобы открыть меню", 0xFFFF0000, 225.4708,-1827.4818,4.5560, 7.0, 0, 1 );
	Create3DTextLabel("{FF0000}Нажмите H чтобы танцевать", 0xFFFF0000, 221.3413,-1833.8883,4.5560, 7.0, 0, 1 );

//=============================================================================================
	CreateDynamicObject(18765, 196.44315, -1847.21277, 4.43023,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18765, 196.44310, -1837.23462, 4.43020,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18765, 196.44310, -1827.27478, 4.43020,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18765, 186.46681, -1827.29053, 4.43020,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18765, 186.46680, -1837.26721, 4.43020,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18765, 186.46680, -1847.22021, 4.43020,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19129, 191.41943, -1837.42053, 6.88090,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(16092, 182.30600, -1844.62048, 6.95981,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(16092, 182.30711, -1829.88672, 6.95981,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(16092, 193.84319, -1851.36560, 6.95980,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(16092, 189.31009, -1851.33630, 6.95980,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(16092, 193.82904, -1823.29346, 6.95980,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(16092, 189.26979, -1823.12219, 6.95980,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(19129, 191.36386, -1832.15149, 15.23858,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19129, 191.34380, -1842.27612, 15.23858,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19129, 191.34756, -1842.27039, 15.25860,   180.00000, 0.00000, 0.00000);
	CreateDynamicObject(19129, 191.37379, -1832.19775, 15.25860,   180.00000, 0.00000, 0.00000);
	CreateDynamicObject(3437, 183.06238, -1837.30701, 9.40304,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(3437, 184.49936, -1823.94910, 9.40300,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3437, 187.09195, -1824.01746, 9.40300,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3437, 184.35568, -1850.64319, 9.40300,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3437, 186.85742, -1850.44092, 9.40300,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3437, 183.19939, -1844.68372, 13.96748,   0.00000, 90.00000, 90.00000);
	CreateDynamicObject(3437, 183.20979, -1833.91321, 13.96750,   0.00000, 90.00000, 90.00000);
	CreateDynamicObject(3437, 183.13161, -1828.90234, 13.96750,   0.00000, 90.00000, 90.00000);
	CreateDynamicObject(3437, 196.16805, -1823.89050, 9.40300,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3437, 198.52788, -1824.00415, 9.40300,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3437, 196.06190, -1850.53430, 9.40300,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3437, 198.56458, -1850.60596, 9.40300,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3437, 191.21930, -1850.88013, 13.96750,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(3437, 191.10730, -1823.56726, 13.96750,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(13646, 196.76289, -1837.77783, 7.49785,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(2232, 199.04329, -1837.84460, 7.49889,   0.00000, 0.00000, 90.42000);
	CreateDynamicObject(2232, 198.85129, -1836.55725, 7.49889,   0.00000, 0.00000, 120.54004);
	CreateDynamicObject(2232, 198.69154, -1838.91003, 7.49889,   0.00000, 0.00000, 60.54002);
	CreateDynamicObject(2232, 197.92044, -1839.76221, 7.49889,   0.00000, 0.00000, 29.63998);
	CreateDynamicObject(2232, 197.85263, -1835.68127, 7.49889,   0.00000, 0.00000, 145.62004);
	CreateDynamicObject(1957, 197.64861, -1837.20325, 8.95190,   0.00000, 0.00000, -0.90001);
	CreateDynamicObject(1957, 197.64722, -1838.28284, 8.97140,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1953, 197.59769, -1837.20520, 9.00400,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1953, 197.59140, -1838.29517, 9.02360,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1958, 197.62439, -1837.70007, 8.93590,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(2435, 197.67354, -1838.24084, 7.85690,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(2435, 197.66530, -1837.31641, 7.85690,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(18646, 199.07530, -1837.81140, 8.19520,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 198.72636, -1836.56982, 8.19520,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 197.81126, -1835.68054, 8.19520,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 198.77008, -1838.94397, 8.19520,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(18646, 197.93311, -1839.77966, 8.19520,   0.00000, 0.00000, 0.00000);
	gates[0] = CreateDynamicObject(19129, 191.40663, -1821.47424, 5.29657,   90.00000, 0.00000, 0.00000);
	gates[1] = CreateDynamicObject(19129, 201.37971, -1831.44531, 5.29660,   90.00000, 0.00000, -90.00000);
	gates[2] = CreateDynamicObject(19129, 201.39586, -1842.13770, 5.29660,   90.00000, 0.00000, -90.00000);
	gates[3] = CreateDynamicObject(19129, 191.44458, -1852.22473, 5.29660,   90.00000, 0.00000, -180.00000);
	gates[4] = CreateDynamicObject(19129, 181.47427, -1842.19629, 5.29660,   90.00000, 0.00000, 90.00000);
	gates[5] = CreateDynamicObject(19129, 181.37645, -1831.46643, 5.29660,   90.00000, 0.00000, 90.00000);
	//========================================== подарки ====================================================
	CreateDynamicObject(19058, 228.39748, -1835.00024, 4.16900,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19057, 228.27531, -1833.48169, 4.16699,   0.00000, 0.00000, 47.76001);
	CreateDynamicObject(19056, 226.59166, -1833.63831, 4.17989,   0.00000, 0.00000, 53.58001);
	CreateDynamicObject(19055, 226.43864, -1835.13184, 4.17289,   0.00000, 0.00000, 8.94000);
	CreateDynamicObject(19054, 227.43459, -1836.04126, 4.16147,   0.00000, 0.00000, 53.69999);
	Create3DTextLabel("{FF0000}Нажмите ALT!", 0xFFFF0000, 227.2603,-1834.6600,6.2117, 7.0, 0, 1 );
	//===================================// Декорация //=======================================================
	CreateDynamicObject(19076, 204.43655, -1861.70105, 1.63408,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 204.36641, -1814.81030, 3.23439,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 171.97527, -1812.67529, 3.10540,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 172.21011, -1863.17554, 1.97787,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 236.67978, -1844.92126, 1.79756,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 227.10164, -1834.64917, 3.15874,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 236.34093, -1824.35559, 2.20888,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 216.58408, -1820.55249, 2.50530,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 216.37956, -1844.90552, 1.96312,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 186.79764, -1778.92578, 1.76458,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 220.09111, -1779.39514, 2.54727,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 256.26569, -1777.43909, 2.54340,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 294.28262, -1777.73938, 3.09546,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 293.67316, -1809.66602, 2.70106,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 294.70020, -1849.07898, 1.92366,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 294.48941, -1885.46582, -2.16576,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19076, 261.32104, -1873.24341, 0.71419,   0.00000, 0.00000, 0.00000);
	return 1;
}

stock GolosUpdate()
{
    new stri[64];
    format(stri,sizeof stri,"Трек понравился\n %d игрокам",golos);
    SetObjectMaterialText(golosc,stri,0,OBJECT_MATERIAL_SIZE_256x128,"Tahoma",18,0,0xFFFFFFFF,0xFF000000, OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
}

public OnGameModeExit()
{
	return 1;
}

public OnPlayerSpawn(playerid)
{
    return 1;
}

public OnPlayerConnect(playerid)
{
    SendClientMessage(playerid, 0x919191FF, "{0077FF}Сцена v0.8 от Игоря Мартелова");
    PlayerLiked[playerid] = false;
	return 1;
}

public OnPlayerDisconnect(playerid)
{
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
//**********************************************************************
    new name[32];
    GetPlayerName(playerid, name, 32);
    new tmp[255], string[512], cmd[255], idx, giveplayerid;
    cmd = strtok(cmdtext, idx);
    //=================================================================
	if (!strcmp("/sdj",cmd))
    {
        if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, 0x919191FF, "Вы не админ."); // проверка на админство
        tmp = strtok(cmdtext, idx); // Мы объявляем что мы используем strtok для переменной 'tmp'
        if(!strlen(tmp)) return SendClientMessage(playerid, 0x919191FF, "{0077FF}[DJ]:{ff0000} Использование: /sdj [id]"); // Если ID не был указан
        giveplayerid = strval(tmp); // Связываем с переменной 'giveplayerid'
        if(dj == true) return SendClientMessage(playerid, 0x919191FF, "{ff0000} У игрока есть DJ права.");
        if(!IsPlayerConnected(giveplayerid)) return SendClientMessage(playerid, 0x919191FF, "{ff0000} Игрок с данным ID не подключен."); // если 'giveplayerid' не онлайн
        dj = true;
        SendClientMessage(giveplayerid, 0x919191FF, "{0077FF}[DJ]{ff0000}Вам выданы права DJ'я.");
        SendClientMessage(giveplayerid, 0x919191FF, "{0077FF}[DJ]{ff0000}Помощь - /hdj.");
        return 1;
    }
    if (!strcmp("/ddj",cmd))
    {
        if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, 0x919191FF, "Вы не админ."); // проверка на админство
        tmp = strtok(cmdtext, idx); // Мы объявляем что мы используем strtok для переменной 'tmp'
        if(!strlen(tmp)) return SendClientMessage(playerid, 0x919191FF, "{0077FF}[DJ]:{ff0000} Использование: /ddj [id]"); // Если ID не был указан
        giveplayerid = strval(tmp); // Связываем с переменной 'giveplayerid'
        if(dj == false) return SendClientMessage(playerid, 0x919191FF, "{ff0000} У игрока нет DJ прав.");
        if(!IsPlayerConnected(giveplayerid)) return SendClientMessage(playerid, 0x919191FF, "{ff0000} Игрок с данным ID не подключен."); // если 'giveplayerid' не онлайн
        dj = false;
        SendClientMessage(giveplayerid, 0x919191FF, "{0077FF}[DJ]{ff0000}У вас забрали права DJ'я.");
        return 1;
    }
    if (!strcmp("/stopa",cmdtext))
    {
        ClearAnimations(playerid);
		TextDrawHideForPlayer(playerid, Textdraw0);
    }
    if(!strcmp(cmd, "/tme")) // изменить время на ночь
	{
	    if(IsPlayerAdmin(playerid))
		{
		    ShowPlayerDialog(playerid,4092,DIALOG_STYLE_LIST,"Выбери время", "День\nНочь","Выбрать", "Отмена");
		}
		return 1;
	}
	
    if(!strcmp(cmd, "/sn"))
	{
	    if(IsPlayerAdmin(playerid) || dj == true)
	    {
    	    SetPlayerSkin(playerid, skin_dj[playerid]);
    	    SendClientMessage(playerid, 0x21DD00FF, "Вы сняли форму DJ'я.");
    	} else SendClientMessage(playerid, 0x21DD00FF, "{ff0000} Вы не администратор/DJ сервера.");
    	return 1;
    }
//=====================================================================
	if(!strcmp(cmdtext, "/hdj")) // помощь
	{
		if(IsPlayerAdmin(playerid) || dj == true)
		{
		    SendClientMessage(playerid, 0x21DD00FF, "Команды:");
		    SendClientMessage(playerid, 0x21DD00FF, "/gate - открыть/закрыть сцену.");
		    SendClientMessage(playerid, 0x21DD00FF, "/start - включить/выключить трек.");
		    SendClientMessage(playerid, 0x21DD00FF, "/urldj - включить трек по URL.");
		    SendClientMessage(playerid, 0x21DD00FF, "/text - написать на сцене текст.");
		    SendClientMessage(playerid, 0x21DD00FF, "{FF9900}Клавиши:");
		    SendClientMessage(playerid, 0x9933FFFF, "ALT - меню DJ'я(Нужно быть возле пульта)");
		    SendClientMessage(playerid, 0x9933FFFF, "H(англ) - открыть меню анимаций DJ'я(Нужно быть возле пульта)");
		    SendClientMessage(playerid, 0x919191FF, "_____________________________________________________________");
		    SendClientMessage(playerid, 0x919191FF, " ");
		    SendClientMessage(playerid, 0x919191FF, "{0077FF}Сцена v0.7 от Игоря Мартелова");
		    SendClientMessage(playerid, 0x919191FF, "_____________________________________________________________");
		} else SendClientMessage(playerid, 0x21DD00FF, "{ff0000} Вы не администратор/DJ сервера.");
		return 1;
	}
    if (!strcmp("/text",cmd))
    {
        if(IsPlayerAdmin(playerid) || dj == true)
	    {
			if(vor == true){ShowPlayerDialog(playerid,188,DIALOG_STYLE_INPUT,"Текст на сцену","{00FF40}Введите текст.","Ок","Отмена");}
			else SendClientMessage(playerid, 0x21DD00FF, "{FF9900}Сцена закрыта.");
            return 1;
		}
    }
	if (!strcmp("/start",cmd))
    {
        if(IsPlayerAdmin(playerid) || dj == true)
	    {
            if(IsPlayerInRangeOfPoint(playerid, 2.0, 197.6653, -1837.3164, 7.8569)) // поставим проверку на нахождение игрока возле пульта
            {
                format(string,sizeof (string),"{FFFFFF}[1]{66FF00}Dubstep\n{FFFFFF}[2]{66CCFF}Танцевальная\n{FFFFFF}[3]{6666FF}Trap Music\n{FFFFFF}[4]Дискотека 80-90х\n{FFFFFF}[5]{FFCC00}Трек по URL\n{FFFFFF}[6]{FF0000}Остановить музыку\n{FFFFFF}[7]Наушники\n[8]Спецэффекты");
                ShowPlayerDialog(playerid,2908,DIALOG_STYLE_LIST,"Выбери действие", string,"Выбрать", "Отмена");
            } else SendClientMessage(playerid,0xFFFF0000,"Вы не возле DJ пульта"); // сообщение можете поменять на своё
		} else SendClientMessage(playerid,0xFFFF0000,"Вы не DJ");
        return 1;
    }
    if (!strcmp("/urldj",cmd))
    {
        if(IsPlayerAdmin(playerid) || dj == true)
        {
            if(IsPlayerInRangeOfPoint(playerid, 2.0, 197.6653, -1837.3164, 7.8569)) // та же проверка на нахождении игрока возле пульта
            {
                ShowPlayerDialog(playerid,184,DIALOG_STYLE_INPUT,"Другой трек","{00FF40}Ведите URL трека, желательно в {FF0000}.mp3 {00FF40}формате","Ок","Отмена");
            } else SendClientMessage(playerid,0xFFFF0000,"Вы не возле DJ пульта"); // сообщение можете поменять на своё
        }
	}
    if(!strcmp(cmd, "/tps"))
	{
		SetPlayerPos(playerid, 246.3117,-1834.4229,3.2788);
		SendClientMessage(playerid,0xFFFF0000,"Вы телепортировались к сцене.");
		return 1;
	}
	if(!strcmp(cmd, "/tpa"))
	{
	    if(IsPlayerAdmin(playerid) || dj == true)
		{
		    SetPlayerPos(playerid, 196.8786,-1837.7598,9.1072);
		    SendClientMessage(playerid,0xFFFF0000,"Вы телепортировались внутрь сцены.");
		} else SendClientMessage(playerid, 0x21DD00FF, "{ff0000} Вы не администратор сервера или не DJ.");
		return 1;
	}
	if(!strcmp("/gate", cmd))
    {
        if(IsPlayerAdmin(playerid) || dj == true)
        {
		    if(vor == false)
		    {
            for(new i =0;i<MAX_PLAYERS;i++)
                switch(random(4))
                {
			        case 0: PlayAudioStreamForPlayer(i, "https://cs7-1v4.vk-cdn.net/p6/044ffe863186c0.mp3?extra=oF0wYfTshUU7-U5TVkPBIig3-lqmCuXfQubxs-S8BEHyJ-YcaELQT5UdTt9hkYTL6yfI04FdOMU1gAFgN2v62CLtMLiSOVel7PXh", 197.6653, -1837.3164, 7.8569, 100.0,true); // 1
			        case 1: PlayAudioStreamForPlayer(i, "https://cs7-2v4.vk-cdn.net/p8/16b0847b7d2bac.mp3?extra=wHS9EFxN_9kII3ugWKCz8qphozghWri6zjbrT2-7UyL-Ns3_NSgmgVbu-q1TBMABuLxe9aI7nKFeXY_IK5iq9AmV4KK9gtiJmTZ8", 197.6653, -1837.3164, 7.8569, 100.0,true); // 2
			        case 2: PlayAudioStreamForPlayer(i, "https://cs7-4v4.vk-cdn.net/p20/d7d1708a840e67.mp3?extra=UtfFoFZ_Sa6aixwUSXqqON_1Q_-RUPxuJ2am6k45EjWM0ywHP6WTtAt0yE6BRAmJLegdT7zLU8Rc7QqtCCLD0Rhg5amHR_1DyRL4", 197.6653, -1837.3164, 7.8569, 100.0,true); // 3
			        case 3: PlayAudioStreamForPlayer(i, "https://cs7-1v4.vk-cdn.net/p2/9f7ddab43c665d.mp3?extra=OSr3AUUCE8aSWHGgMH2ysNitGaHY49sAX2GZwqMlb4ivHVAjnhFmvKt3Mcr9mQgp-KfFROrcwmczPceeUIlA32mu-k3UFU1idhFc", 197.6653, -1837.3164, 7.8569, 100.0,true); // 4
				}
        	MoveDynamicObject(gates[0],191.40663, -1818.8542, 5.29657,2);
        	MoveDynamicObject(gates[1],204.0797, -1831.44531, 5.29660,2);
        	MoveDynamicObject(gates[2],204.0797, -1842.13770, 5.29660,2);
        	MoveDynamicObject(gates[3],191.44458, -1854.8047, 5.29660,2);
        	MoveDynamicObject(gates[4],179.0543, -1842.19629, 5.29660,2);
        	MoveDynamicObject(gates[5],179.0543, -1831.46643, 5.29660,2);
			SetTimer("open", 1500, 0);
        	SetTimer("effects0", 4000, 0);
        	return 1;
            }
		    if(vor == true)
		    {
		    for(new i =0;i<MAX_PLAYERS;i++)
		    StopAudioStreamForPlayer(i);
        	MoveDynamicObject(gates[0],191.40663, -1821.47424, 5.29657,4);
        	MoveDynamicObject(gates[1],201.37971, -1831.44531, 5.29660,4);
        	MoveDynamicObject(gates[2],201.39586, -1842.13770, 5.29660,4);
        	MoveDynamicObject(gates[3],191.44458, -1852.22473, 5.29660,4);
        	MoveDynamicObject(gates[4],181.47427, -1842.19629, 5.29660,4);
        	MoveDynamicObject(gates[5],181.37645, -1831.46643, 5.29660,4);
        	vor = false;
        	objects();
        	return 1;
            }
		}
    }
	return 0;
}
/////////////////////////////////////////////////////////////////////////
public effects0()
{
    CreateExplosion( 202.5555, -1850.8645, 7.8569, 12, 5.0 ); // 1
    CreateExplosion( 202.4790, -1823.3855, 7.8569, 12, 5.0 ); // 1
    CreateExplosion( 202.4790, -1823.3855, 7.8569, 4, 5.0 ); // 2
    CreateExplosion( 202.4790, -1823.3855, 7.8569, 4, 5.0 ); // 2
    SetTimer("effects00", 500, 0);
	return 1;
}

public effects00()
{
    CreateExplosion( 202.5555, -1850.8645, 12.0098, 12, 10.0 ); // 1
    CreateExplosion( 202.4790, -1823.3855, 11.9392, 12, 10.0 ); // 1
    CreateExplosion( 202.5555, -1850.8645, 12.0098, 4, 10.0 ); // 2
    CreateExplosion( 202.4790, -1823.3855, 11.9392, 4, 10.0 ); // 2
    SetTimer("effects", 500, 0);
	return 1;
}

public effects()
{
    CreateExplosion( 201.3905, -1850.8766, 15.1517, 12, 20.0 ); // 1
    CreateExplosion( 201.1851, -1823.2799, 15.1517, 12, 20.0 ); // 1
    CreateExplosion( 201.3905, -1850.8766, 15.1517, 4, 20.0 ); // 2
    CreateExplosion( 201.1851, -1823.2799, 15.1517, 4, 20.0 ); // 2
    SetTimer("effects22", 500, 0);
	return 1;
}

public effects22()
{
    CreateExplosion( 200.7015, -1845.5175, 15.1517, 12, 30.0 ); // 1
    CreateExplosion( 200.8363, -1829.1211, 15.1517, 12, 30.0 ); // 1
    CreateExplosion( 200.7015, -1845.5175, 15.1517, 4, 30.0 ); // 2
    CreateExplosion( 200.8363, -1829.1211, 15.1517, 4, 30.0 ); // 2
    SetTimer("effects33", 500, 0);
	return 1;
}

public effects33()
{
    CreateExplosion( 200.4837, -1839.6793, 25.1517, 12, 40.0 ); // 1
    CreateExplosion( 200.4228, -1834.2898, 25.1517, 12, 40.0 ); // 1
    CreateExplosion( 200.4837, -1839.6793, 25.1517, 4, 40.0 ); // 2
    CreateExplosion( 200.4228, -1834.2898, 25.1517, 4, 40.0 ); // 2
	return 1;
}
////////////////////////////////////////////////////////////////
public open()
{
    vor = true;
    MoveDynamicObject(gates[0],191.40663, -1818.8542, -10.29657,2);
    MoveDynamicObject(gates[1],204.0797, -1831.44531, -10.29660,2);
    MoveDynamicObject(gates[2],204.0797, -1842.13770, -10.29660,2);
    MoveDynamicObject(gates[3],191.44458, -1854.8047, -10.29660,2);
    MoveDynamicObject(gates[4],179.0543, -1842.19629, -10.29660,2);
    MoveDynamicObject(gates[5],179.0543, -1831.46643, -10.29660,2);
    SetTimer("objects", 1500, 0);
	return 1;
}
public objects()
{
	if(vor == true)
	{
    obj[0] = CreateDynamicObject(19128, 201.39410, -1850.20776, 4.58020,   90.00000, 90.00000, 0.00000);
    obj[1] = CreateDynamicObject(19128, 201.39410, -1846.26782, 4.58020,   90.00000, 90.00000, 0.00000);
    obj[2] = CreateDynamicObject(19128, 201.39410, -1842.32776, 4.58020,   90.00000, 90.00000, 0.00000);
    obj[3] = CreateDynamicObject(19128, 201.39410, -1838.36780, 4.58020,   90.00000, 90.00000, 0.00000);
    obj[4] = CreateDynamicObject(19128, 201.39410, -1850.20776, 0.61590,   90.00000, 90.00000, 0.00000);
    obj[5] = CreateDynamicObject(19128, 201.39410, -1846.26782, 0.61420,   90.00000, 90.00000, 0.00000);
    obj[6] = CreateDynamicObject(19128, 201.39410, -1834.38782, 4.58020,   90.00000, 90.00000, 0.00000);
    obj[7] = CreateDynamicObject(19128, 201.39410, -1830.42786, 4.58020,   90.00000, 90.00000, 0.00000);
    obj[8] = CreateDynamicObject(19128, 201.39410, -1826.46790, 4.58020,   90.00000, 90.00000, 0.00000);
    obj[9] = CreateDynamicObject(19128, 201.38640, -1824.28979, 4.58020,   90.00000, 90.00000, 0.00000);
    obj[10] = CreateDynamicObject(3437, 201.36880, -1823.41992, 9.43885,   0.00000, 0.00000, 90.00000);
    obj[11] = CreateDynamicObject(3437, 201.39244, -1823.38342, -2.21119,   0.00000, 0.00000, 90.00000);
    obj[12] = CreateDynamicObject(3437, 201.45396, -1850.88184, 9.43885,   0.00000, 0.00000, 90.00000);
    obj[13] = CreateDynamicObject(3437, 201.45396, -1850.88184, -2.24578,   0.00000, 0.00000, 90.00000);
    obj[14] = CreateDynamicObject(3461, 201.73944, -1827.67334, 5.31476,   25.00000, 0.00000, 79.01998);
    obj[15] = CreateDynamicObject(3461, 201.80475, -1831.05310, 5.31476,   25.00000, 0.00000, 79.01998);
    obj[16] = CreateDynamicObject(3461, 201.89212, -1835.07349, 5.31476,   25.00000, 0.00000, 79.01998);
    obj[17] = CreateDynamicObject(3461, 201.89447, -1839.65527, 5.31476,   25.00000, 0.00000, 79.01998);
    obj[18] = CreateDynamicObject(3461, 201.91814, -1843.53613, 5.31476,   25.00000, 0.00000, 79.01998);
    obj[19] = CreateDynamicObject(3461, 201.97372, -1847.17114, 5.31476,   25.00000, 0.00000, 79.01998);
    GolosUpdate();
    }
    if(vor == false)
    {
		for(new i = 0; i != 20; i++)
		DestroyDynamicObject(obj[i]);
		if(text == true)
		{
		    DestroyObject(bane);
		    text = false;
		}
		if(neons == true)
		{
    		for(new i = 0; i != 28; i++)
			DestroyDynamicObject(neones[i]);
		    neons = false;
		}
		if(dumka == true)
		{
			dumka = false;
    		for(new i = 0; i != 6; i++)
			DestroyDynamicObject(dum[i]);
		}
		golos = 0;
		for(new i =0;i<MAX_PLAYERS;i++){PlayerLiked[i] = false;}
        SetObjectMaterialText(golosc,"Сцена закрыта!",0,OBJECT_MATERIAL_SIZE_256x128,"Tahoma",18,0,0xFFFFFFFF,0xFF000000, OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
	}
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    new string[512];
    if(dialogid == 2908)
        {
            if(response)
            {
                for(new i =0;i<MAX_PLAYERS;i++)
                {
                    switch(listitem)
                    {
                    case 0: // Dub Step Music
                    {
                        format(string,sizeof (string),"[1] Dub Step Music vol.1\
						\n[2] Dub Step Music vol.1\
						\n[3] Dub Step Music vol.1\
						\n[4] Dub Step Music vol.1\
						\n[5] Dub Step Music vol.1\
						\n[6] Dub Step Music vol.1\
						\n[7] Dub Step Music vol.1\
						\n[8] Dub Step Music vol.1\
						\n[9] Dub Step Music vol.1\
						\n[10] Dub Step Music vol.1");
                        ShowPlayerDialog(playerid,2909,DIALOG_STYLE_LIST,"Выбери трек", string,"Выбрать", "Отмена");
                    }
                    case 1: // Танцевальня
                    {
                        format(string,sizeof (string),"[1] Dance Music vol.1\
						\n[2] Dance Music vol.1\
						\n[3] Dance Music vol.1\
						\n[4] Dance Music vol.1\
						\n[5] Dance Music vol.1\
						\n[6] Dance Music vol.1\
						\n[7] Dance Music vol.1\
						\n[8] Dance Music vol.1\
						\n[9] Dance Music vol.1\
						\n[10] Dance Music vol.1");
                        ShowPlayerDialog(playerid,2906,DIALOG_STYLE_LIST,"Выбери трек", string,"Выбрать", "Отмена");
                    }
                    case 2: // Trap Music
                    {
                        format(string,sizeof (string),"[1] Trap Music vol.1\
						\n[2] Trap Music vol.1\
						\n[3] Trap Music vol.1\
						\n[4] Trap Music vol.1\
						\n[5] Trap Music vol.1\
						\n[6] Trap Music vol.1\
						\n[7] Trap Music vol.1\
						\n[8] Trap Music vol.1\
						\n[9] Trap Music vol.1\
						\n[10] Trap Music vol.1");
                        ShowPlayerDialog(playerid,2907,DIALOG_STYLE_LIST,"Выбери трек", string,"Выбрать", "Отмена");
                    }
                    case 3: // 80-90
                    {
                        format(string,sizeof (string),"[1] Дискотека 80-90х vol.1\
						\n[2] Дискотека 80-90х vol.1\
						\n[3] Дискотека 80-90х vol.1\
						\n[4] Дискотека 80-90х vol.1\
						\n[5] Дискотека 80-90х vol.1\
						\n[6] Дискотека 80-90х vol.1\
						\n[7] Дискотека 80-90х vol.1\
						\n[8] Дискотека 80-90х vol.1\
						\n[9] Дискотека 80-90х vol.1\
						\n[10] Дискотека 80-90х vol.1");
                        ShowPlayerDialog(playerid,2912,DIALOG_STYLE_LIST,"Выбери трек", string,"Выбрать", "Отмена");
                    }
                    case 4: OnPlayerCommandText(playerid, "/urldj");
                    case 5: StopAudioStreamForPlayer(i);
                    case 6: ShowPlayerDialog(playerid,2915,DIALOG_STYLE_LIST,"Выбери наушники", "{00CCFF}Синие\n{FF3366}Красные\nЧёрные\nБелые\n{FFFF00}Снять наушники","Выбрать", "Отмена");
                    case 7: ShowPlayerDialog(playerid,2487,DIALOG_STYLE_LIST,"Спецэффекты", "Огонь\nДым\nВзрывы","Выбрать", "Отмена");
                    }
				}
            }
        }
    if(dialogid == 2915)
        {
            if(response)
            {
                switch(listitem)
                {
                case 0: SetPlayerAttachedObject(playerid, 1, 19424, 2, 0.0510, -0.0159, -0.0030, -92.50, 1.00, -97.49, 1.00, 0.84, 1.00); //синие наушники
                case 1: SetPlayerAttachedObject(playerid, 1, 19423, 2, 0.0510, -0.0159, -0.0030, -92.50, 1.00, -97.49, 1.00, 0.84, 1.00); //красные наушники
                case 2: SetPlayerAttachedObject(playerid, 1, 19422, 2, 0.0510, -0.0159, -0.0030, -92.50, 1.00, -97.49, 1.00, 0.84, 1.00); //чёрные наушники
                case 3: SetPlayerAttachedObject(playerid, 1, 19421, 2, 0.0510, -0.0159, -0.0030, -92.50, 1.00, -97.49, 1.00, 0.84, 1.00); //белые наушники
                case 4:
                {
                    for(new i=0; i<MAX_PLAYER_ATTACHED_OBJECTS; i++)
                    {
                        if(IsPlayerAttachedObjectSlotUsed(playerid, i)) RemovePlayerAttachedObject(playerid, i);
                    }
                }
                }
            }
        }
    if(dialogid == 2909)// DubStep
        {
            if(response)
            {
                for(new i =0;i<MAX_PLAYERS;i++)
                {
                    switch(listitem)
                    {
                    case 0: PlayAudioStreamForPlayer(i, "https://cs7-1v4.vk-cdn.net/p18/cc41e69f80bc09.mp3?extra=LPvKNboTm8RsKm_ZRtWWm2_LEYxlTGFtZ4pRDoGhYL8QYOHKtYEUJBooFzKLGur6sEOBSSwFjJZcCJGGvtWhjs8ZUievlP6DFE0", 197.6653, -1837.3164, 7.8569, 100.0,true); // 1
                    case 1: PlayAudioStreamForPlayer(i, "https://cs7-4v4.vk-cdn.net/p5/53a50da07027cd.mp3?extra=cMWIw6IzijyEaqSLwwAf7d3ITE9RE95rIzU52OQ9uY_23luuc1A8-cy9T7lyH7HOHz8GQjC4hv1CeIntW5HwHIZbYm7xQEY4IOOy", 197.6653, -1837.3164, 7.8569, 100.0,true); // 2
                    case 2: PlayAudioStreamForPlayer(i, "https://cs7-4v4.vk-cdn.net/p11/cd228cdd5313cf.mp3?extra=V42BQ3kI58pcMXqCG17_EDBnJIuIJtaPdCeSjz3njRpo4IdnNp1L1QleABdW2eQ6nJJEULoOStoI9dR7VKckevkUBcDksrXPnCVP", 197.6653, -1837.3164, 7.8569, 100.0,true); // 3
                    case 3: PlayAudioStreamForPlayer(i, "https://cs7-1v4.vk-cdn.net/p16/2ca42ceb909a83.mp3?extra=RZwIHW4hGlVIyDZffHu6XHOMcqH_YFubxg-0iy43SZ0fM-OyY9NwRE01rCphaDz3dLPYnfDhhshTc30Tm1yu40WHsZoH3Xq29jQ9", 197.6653, -1837.3164, 7.8569, 100.0,true); // 4
                    case 4: PlayAudioStreamForPlayer(i, "https://psv4.vk.me/c536209/u732506/audios/005c583dfacc.mp3?extra=D1KPJ5qdNTJw4SDEjW2wdHhlPEiciU_r1XfNbFLmB5inM2pSxRVe8Dc9E2oTtiSXiLnkDXtW3KqrXMX2hiFZ7MQ-PBNIGxz-dnvn", 197.6653, -1837.3164, 7.8569, 100.0,true); // 5
                    case 5: PlayAudioStreamForPlayer(i, "https://cs7-2v4.vk-cdn.net/p2/11035656150138.mp3?extra=Zk5ObboBuimLpdSrraGbislOKyeR0lGofsZ4n6g9vxrJgkYb4hC3bpRhQ6q5NaExtyWKGFlCNO-iER7JmzTz4r32ZthknVsUhZGu", 197.6653, -1837.3164, 7.8569, 100.0,true); // 6
                    case 6: PlayAudioStreamForPlayer(i, "https://psv4.vk.me/c536603/u7153300/audios/cdf73f8ddea0.mp3?extra=hE_CJAgdrEOwuELn9yjyx3b_kO3lK5TUCyfDjIAT7PBKxIwBlbJVrmUX4OGm4_vUmzb1Xx_LI3EIQKHM5u6Lgb-o-_O5E1exnJen", 197.6653, -1837.3164, 7.8569, 100.0,true); // 7
                    case 7: PlayAudioStreamForPlayer(i, "https://cs7-5v4.vk-cdn.net/p24/f48d1c081c33f5.mp3?extra=inIaeoU-kzApHRWSkflPJ15U_FI_7jnIfmbH8vJxJ7YcBriuELNivw_N4X3dL0WDpWxtAdG0J-g0pYW-XJYqibExbZ6m0GdWE7X9", 197.6653, -1837.3164, 7.8569, 100.0,true); // 8
                    case 8: PlayAudioStreamForPlayer(i, "https://cs7-5v4.vk-cdn.net/p13/d5e1702913bf32.mp3?extra=5ukYyBqHV2oNm-1Visec4rL58w4fynNsmv_dVK-vPxgzmiHOhxSB2tO_BiEqImq-tfRmcCVNUfYjb7tPP-M9FjGaN61v3hbbYosb", 197.6653, -1837.3164, 7.8569, 100.0,true); // 9
                    case 9: PlayAudioStreamForPlayer(i, "https://cs7-5v4.vk-cdn.net/p13/f2f9517361bdaa.mp3?extra=wN90cooCpLPnce9pW9aOHxUEIYj1z3ZfV5N78VvaGueYRMcZ_ryXe40aDE4BxHw9Sd06QQKvdRWDzkEt2mT9K8-tpffxgCQMNjiU", 197.6653, -1837.3164, 7.8569, 100.0,true); // 10
                    }
                    if(golos > 0)
                    {
					    golos = 0;
					    PlayerLiked[i] = false;
					    GolosUpdate();
					}
                }
            }
        }
    if(dialogid == 2906) // Танцевальная
        {
            if(response)
            {
                for(new i =0;i<MAX_PLAYERS;i++)
                {
                    switch(listitem)
                    {
                    case 0: PlayAudioStreamForPlayer(i, "https://cs7-5v4.vk-cdn.net/p24/4cd64cbe7f3a8f.mp3?extra=k9ZSNhv9yBPmN86P1FlmFpifSQ-Aw-hQ1jMKnrWtdXn-8xPB5vNsFgP5INMipLsVOuFFu8WLcSSquWnd9gZqO_g_MKPQBFpvoRI", 197.6653, -1837.3164, 7.8569, 100.0,true); // 1
                    case 1: PlayAudioStreamForPlayer(i, "https://cs7-2v4.vk-cdn.net/p9/7d2d94651e9922.mp3?extra=-UbN6X62r8UrLqtHMlZdwjfV7cZ2YQms33mF_AM0kFBKJ31GbXGVcq3GwbJ2Wyo35o5kZowg_NGb6W4Ogi3x2qselYgofy_WPwU", 197.6653, -1837.3164, 7.8569, 100.0,true); // 2
                    case 2: PlayAudioStreamForPlayer(i, "https://psv4.vk.me/c611327/u44171/audios/4bcd2b47cfe5.mp3?extra=ZExyXp-H9fF-11V6gHCqo5gcxd31yiYM3eYZs3GMuDg_IknKzLWjqwbDHOSIG5JocElAruJx5Ugx3ZImTFfQVOs-KEgjIfOQ5kM", 197.6653, -1837.3164, 7.8569, 100.0,true); // 3
                    case 3: PlayAudioStreamForPlayer(i, "https://cs7-3v4.vk-cdn.net/p18/c5dde1f0225e73.mp3?extra=5-Se_MmGfytqALvZw1FTPBlJqhPJS86P8lbXP3V8XTJj2V1Ot67IcNAUTFJZ9zKvXO6qgi7fHa0FvOWnaenbHcQutIYxO3vT-t4", 197.6653, -1837.3164, 7.8569, 100.0,true); // 4
                    case 4: PlayAudioStreamForPlayer(i, "https://cs7-5v4.vk-cdn.net/p20/c67cecc5bd6695.mp3?extra=AGTRoi_V8cnD21RNQIF8_KUIdkHYCIb9ucJT5lu6pf6LH8J-7IWMIVtdZ3rNlTa3FEMq3bWl4m-cCLVTfjzolXZrThWqOi6Y-cQ", 197.6653, -1837.3164, 7.8569, 100.0,true); // 5
                    case 5: PlayAudioStreamForPlayer(i, "https://cs7-4v4.vk-cdn.net/p16/b22574783e8cf2.mp3?extra=Mczqy2Wvor9aBIOpEPaTOE5sNUnlO_uPp1AK5cV3eK60T47MnTUD8vS7X5h_Gct1F63ZSitFJQ6N2nKUGnC0N-_pKH6003eAa2c", 197.6653, -1837.3164, 7.8569, 100.0,true); // 6
                    case 6: PlayAudioStreamForPlayer(i, "https://cs7-2v4.vk-cdn.net/p12/ffca3c9154e530.mp3?extra=otX0YAz6BbEDDcs-bRRnhOd5JA1lsDvYc1hO6FAZnLtpshCtzoDEtvIiyjJSaYwOKbgoz5ZKQrD3O2fQIc-4dyr6Pyz8YpC8ex8", 197.6653, -1837.3164, 7.8569, 100.0,true); // 7
                    case 7: PlayAudioStreamForPlayer(i, "https://cs7-5v4.vk-cdn.net/p1/9910ddca5b2df3.mp3?extra=eUuhTmCjLOWsA-BLc_qrW8S8d5jPbB3kRcQcDvzZWQbvy8INERxIrGwnZPC2ft4ac2luAsOLSgdBHg06MPgpEwTSq3cdPJP1WbE", 197.6653, -1837.3164, 7.8569, 100.0,true); // 8
                    case 8: PlayAudioStreamForPlayer(i, "https://cs7-2v4.vk-cdn.net/p11/a92035a7cb119b.mp3?extra=k5NuMsez3XUAHc9CEmIIGU7iZcX6VrFyvBypPXABvP1pHEOhB125BFoVPhAMQ9HZw7eIgd3Zy-Zk0rFe-X1JudDZggRWxtHg3VY", 197.6653, -1837.3164, 7.8569, 100.0,true); // 9
                    case 9: PlayAudioStreamForPlayer(i, "https://cs7-2v4.vk-cdn.net/p17/1c9d96a78f45f0.mp3?extra=EtXHf2jCyfYcH4OWILDqf55YKNA-5-2gKSUlQxmL5Vfv8fOC9-6ma3OZpXE0WC9CJtrP4ZN-L29e3siF4DDxlVhqORcArGLkrvQ", 197.6653, -1837.3164, 7.8569, 100.0,true); // 10
                    }
                    if(golos > 0)
                    {
					    golos = 0;
					    PlayerLiked[i] = false;
					    GolosUpdate();
					}
                }
            }
        }
    if(dialogid == 2907) // Trap Music
        {
            if(response)
            {
                for(new i =0;i<MAX_PLAYERS;i++)
                {
                    switch(listitem)
                    {
                    case 0: PlayAudioStreamForPlayer(i, "https://cs7-2v4.vk-cdn.net/p7/a8c5bd3709190b.mp3?extra=jhkKi5SQb8xa_1UJI3UDLwRr1qBvfq5WkH7MbhONIKuzO0oey1do6_BZHVFgnWSSRxEyI3s6iznyzkqgyT-UMZLoCn66hPKBVek", 197.6653, -1837.3164, 7.8569, 100.0,true); // 1
                    case 1: PlayAudioStreamForPlayer(i, "https://cs7-2v4.vk-cdn.net/p18/c118d26b4bf7f8.mp3?extra=KzrjPYEyLNzs94KHS6OYG2sFHWjBbRVqNKtEAVIje3ghGENIJfm2-y1V-LQy6vfztRHvT17Z9wSaILywJLOBOH6m_LNfS8oGDXo", 197.6653, -1837.3164, 7.8569, 100.0,true); // 2
                    case 2: PlayAudioStreamForPlayer(i, "https://cs7-1v4.vk-cdn.net/p20/a0849d190d4ed5.mp3?extra=B2B0XT4OHt_E5AackKsRDd3HMxYvFzG_JzAMGkGM5iKW7vqRRVOREfR5tWkwhofE8KTjACOY5Cl3bJmiVdOtnL-LI3SxrE8MJ4E", 197.6653, -1837.3164, 7.8569, 100.0,true); // 3
                    case 3: PlayAudioStreamForPlayer(i, "https://cs7-2v4.vk-cdn.net/p8/da86ec7defbdc2.mp3?extra=38gk3uLKIKBqHlCHdgESQIdUUjkWSgYm9ekLbK4pG3_mLZskhQqJo1ejRg7d9Ef4FhaeM38Bg29jZm-4UOKtuSY2jOF3iJHtMuk", 197.6653, -1837.3164, 7.8569, 100.0,true); // 4
                    case 4: PlayAudioStreamForPlayer(i, "https://cs7-5v4.vk-cdn.net/p16/8a2fc1a9224936.mp3?extra=7BrzMpw7X1dhBw9Rny_m7KJRTLQj4G01TI_WIdvQcVQ8YERnrnY_Y1z7N4BQVW-mxcN1gevDh3xRFv-Y_iWx-bibHun2uoSN3RE", 197.6653, -1837.3164, 7.8569, 100.0,true); // 5
                    case 5: PlayAudioStreamForPlayer(i, "https://cs7-5v4.vk-cdn.net/p7/a7871dbff3fde7.mp3?extra=vC1k7f7G4FmJzfap-RNN7gH-5Bx__yCO1l5L7GpacK1utFLpqwNvk9On8hNW0f6r72goGkl9NaP_dcKCOUHt8naQL1UKgo8RUKk", 197.6653, -1837.3164, 7.8569, 100.0,true); //6
                    case 6: PlayAudioStreamForPlayer(i, "https://cs7-1v4.vk-cdn.net/p15/a2b25c7d49cf15.mp3?extra=3vNiPEE1rZhcUoL4dLj5E7jttpcTpRUXzl_DFOfjDsfx8IUGb3N3sjIf8A66OZnh3wMv0Q6BdMaKNLaWsfdE3PqJ-NIiON9mP9g", 197.6653, -1837.3164, 7.8569, 100.0,true); // 7
                    case 7: PlayAudioStreamForPlayer(i, "https://cs7-4v4.vk-cdn.net/p14/0b928ea1a87c4c.mp3?extra=ybOzROXtprJliarjZL9GE_ek11bdcgiyl1HHsWI4ZQEiAsdobCXGM9iaXb-JycMD8AULMSjPhU5ioCPExDlHlxbqzR3d59Au4Dk", 197.6653, -1837.3164, 7.8569, 100.0,true); // 8
                    case 8: PlayAudioStreamForPlayer(i, "https://cs7-2v4.vk-cdn.net/p14/88df224fa3ef48.mp3?extra=gULKmCE6YtgRPU8_NA0mnNOH_M4vpDvVeJEOvMn7Wy3UuquntXqLd-RXPwBEhMbCO9j0PtqQAISF9OsXkWLr5yqWHv3B8mPIfCo", 197.6653, -1837.3164, 7.8569, 100.0,true); // 9
                    case 9: PlayAudioStreamForPlayer(i, "https://cs7-4v4.vk-cdn.net/p16/50bfeb2189901d.mp3?extra=lohB5nXxshmuIyorRq_Yb3-bCN48Q5kYUd5xQn_njuKfBIh41D14NedwbdhWbVoHAn6w27SBj6C_zVrFnpUPQErMHvKZbMRz0s0", 197.6653, -1837.3164, 7.8569, 100.0,true); // 10
                    }
                    if(golos > 0)
                    {
					    golos = 0;
					    PlayerLiked[i] = false;
					    GolosUpdate();
					}
                }
            }
        }
    if(dialogid == 2912) // 80-90
        {
            if(response)
            {
                for(new i =0;i<MAX_PLAYERS;i++)
                {
                    switch(listitem)
                    {
                    case 0: PlayAudioStreamForPlayer(i, "https://cs7-5v4.vk-cdn.net/p17/26ddeff82b13af.mp3?extra=ZxeUA2RleywO3BASsqdY-fVTZ3-CJeSPFk7Oppg_PJHg5cLD5aws1vG2xY_rRH7A5LLBiCFLl0-6BPDUj0gnU_Kr2xWpLQSC", 197.6653, -1837.3164, 7.8569, 100.0,true); // 1
                    case 1: PlayAudioStreamForPlayer(i, "https://cs7-2v4.vk-cdn.net/p19/e4dfeb99ac9f50.mp3?extra=eJS0jhU1yePUbNeiqmz_0qcZgotqOA3rjqfF7Zjbal52cDQdCDjOI_0P82KoYbRqyCCiqPAIirn8AHFkhdOFUbvNhMnAz06uUiE", 197.6653, -1837.3164, 7.8569, 100.0,true); // 2
                    case 2: PlayAudioStreamForPlayer(i, "https://cs7-1v4.vk-cdn.net/p18/089cd5b2cef376.mp3?extra=eSNvskXKlA4jqXPlefsHaifaWno9zFIVRgfrAobi8MXh9Vk_sFhskm2D6Em1F9UPaU9TupnE9zp_b4Sr6cAfq-ao2cqjbkQMiQ", 197.6653, -1837.3164, 7.8569, 100.0,true); // 3
                    case 3: PlayAudioStreamForPlayer(i, "https://cs7-3v4.vk-cdn.net/p20/e2d7f6ec4e55dd.mp3?extra=vjARoAE83yYYWS4nMpnuBxW-gPbW_fq2tiO-eRBwv2KWJhQGas0CbmYCKWw-mxst2FUYiSz4fkXdgx_e255sxadu1ehrujfH", 197.6653, -1837.3164, 7.8569, 100.0,true); // 4
                    case 4: PlayAudioStreamForPlayer(i, "https://cs7-5v4.vk-cdn.net/p11/6dae6e9d3aadb2.mp3?extra=RmWdnNbK_74mXOtOxSkCFxydhaLGoY1-CjrEVwi1CRNVEbUeS8IbpqdYXQa-cNEbjH4jmi_jJ4H-zNHL8KfJ-yID8O7wmWUw", 197.6653, -1837.3164, 7.8569, 100.0,true); // 5
                    case 5: PlayAudioStreamForPlayer(i, "https://cs7-1v4.vk-cdn.net/p22/919a4d833a803c.mp3?extra=7zQVJ9W7dHMBVVBX5_UTvgsez2RDQ2WjrWhpGGoI8WpvJE1SPem-tu9E7xeq-EdU-KLiv7dUQis8KMvGCzfrxACh8EaVot7V", 197.6653, -1837.3164, 7.8569, 100.0,true); //6
                    case 6: PlayAudioStreamForPlayer(i, "https://cs7-1v4.vk-cdn.net/p19/30a3c1c63abf7d.mp3?extra=wv6qTwhUn-obgEBMbLksQm1uvzdMIVzMBopKVRdC3ncA74zlvTyJCbwb9np10-lPP2jeWsH1clOp9zegnn9qskpWRt1LMYUa", 197.6653, -1837.3164, 7.8569, 100.0,true); // 7
                    case 7: PlayAudioStreamForPlayer(i, "https://cs7-2v4.vk-cdn.net/p6/810a94b7c5cafd.mp3?extra=OSkyfTAW00hUgDfyRHiBE-5d3XlWVk5Mq92hJEcUsCbaPmspBNysgaSylMJrHFxZCuFKRi97roG_MKbwhu5yLU5--K_pjRJfYA", 197.6653, -1837.3164, 7.8569, 100.0,true); // 8
                    case 8: PlayAudioStreamForPlayer(i, "https://cs7-3v4.vk-cdn.net/p16/35f851610aa50c.mp3?extra=87cX8zXdV25lp-H1tWKVIjjmihd2ElGyoDL9VTxMfzWcjnHM26mpzlAVQjEzYFE8w-e5Fcbd9kRU-VyLgJsdVEnmqqztfvM1", 197.6653, -1837.3164, 7.8569, 100.0,true); // 9
                    case 9: PlayAudioStreamForPlayer(i, "https://cs7-3v4.vk-cdn.net/p10/7ed7541932abd8.mp3?extra=c9OAUusC41MMgDyp3or_Xo08ocpVlex5Eg5e_jR8RIjaMhf9UjOGusaFxJ_6blrPqYAkHvwip6Klj5Fbe2Qhye3Tl8ynmu8tsGQ", 197.6653, -1837.3164, 7.8569, 100.0,true); // 10
                    }
                    if(golos > 0)
                    {
					    golos = 0;
					    PlayerLiked[i] = false;
					    GolosUpdate();
					}
                }
            }
        }
    if(dialogid == 184)
        {
             for(new i =0;i<MAX_PLAYERS;i++)
             {
                if(!strlen(inputtext)){
                    SendClientMessage(playerid,0xFF99FFFF,"Вы не вписали URL!");
                    return 1;
                }else{
                    PlayAudioStreamForPlayer(i,inputtext, 197.6653, -1837.3164, 7.8569, 100.0,true);// координаты где будет воспроизводится звук и в каком радиусе
                    if(golos > 0)
                    {
					    golos = 0;
					    PlayerLiked[i] = false;
					    GolosUpdate();
					}
            }
        }
    }
    if(dialogid == 188)
        {
            if(!strlen(inputtext))
			{
                SendClientMessage(playerid,0xFF99FFFF,"Вы не написали текст!");
                return 1;
			}
			if(strlen(inputtext))
			{
			    bane = CreateObject(4238, 201.47980, -1836.83240, 15.80642,   0.00000, 0.00000, 120.42000);
                SetObjectMaterialText(bane,inputtext,0,OBJECT_MATERIAL_SIZE_256x128,"Comic Sans MS",30,0,0xFFFFFFFF,0xFF000000, OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
                text = true;
                //_________________________________// UP | RED //__________________________________________
                neones[0] = CreateDynamicObject(18647, 201.52022, -1846.53345, 18.69659,   0.00000, 0.00000, 0.00000);
                neones[1] = CreateDynamicObject(18647, 201.53716, -1844.55310, 18.69659,   0.00000, 0.00000, 0.00000);
                neones[2] = CreateDynamicObject(18647, 201.52229, -1842.55750, 18.69659,   0.00000, 0.00000, 0.00000);
                neones[3] = CreateDynamicObject(18647, 201.52713, -1840.56812, 18.69659,   0.00000, 0.00000, 0.00000);
                neones[4] = CreateDynamicObject(18647, 201.53699, -1838.59314, 18.69659,   0.00000, 0.00000, 0.00000);
                neones[5] = CreateDynamicObject(18647, 201.53618, -1836.63586, 18.69659,   0.00000, 0.00000, 0.00000);
                neones[6] = CreateDynamicObject(18647, 201.53331, -1834.65100, 18.69659,   0.00000, 0.00000, 0.00000);
                neones[7] = CreateDynamicObject(18647, 201.54128, -1832.65161, 18.69659,   0.00000, 0.00000, 0.00000);
                neones[8] = CreateDynamicObject(18647, 201.52556, -1830.71167, 18.69659,   0.00000, 0.00000, 0.00000);
                neones[9] = CreateDynamicObject(18647, 201.50916, -1828.73169, 18.69659,   0.00000, 0.00000, 0.00000);
                neones[10] = CreateDynamicObject(18647, 201.49695, -1827.13684, 18.69659,   0.00000, 0.00000, 0.00000);
                //_________________________________// DOWN | RED //__________________________________________
                neones[11] = CreateDynamicObject(18647, 201.52022, -1846.53345, 12.97464,   0.00000, 0.00000, 0.00000);
                neones[12] = CreateDynamicObject(18647, 201.53716, -1844.55310, 12.97464,   0.00000, 0.00000, 0.00000);
                neones[13] = CreateDynamicObject(18647, 201.52229, -1842.55750, 12.97464,   0.00000, 0.00000, 0.00000);
                neones[14] = CreateDynamicObject(18647, 201.52713, -1840.56812, 12.97464,   0.00000, 0.00000, 0.00000);
                neones[15] = CreateDynamicObject(18647, 201.53699, -1838.59314, 12.97464,   0.00000, 0.00000, 0.00000);
                neones[16] = CreateDynamicObject(18647, 201.53618, -1836.63586, 12.97464,   0.00000, 0.00000, 0.00000);
                neones[17] = CreateDynamicObject(18647, 201.53331, -1834.65100, 12.97464,   0.00000, 0.00000, 0.00000);
                neones[18] = CreateDynamicObject(18647, 201.54128, -1832.65161, 12.97464,   0.00000, 0.00000, 0.00000);
                neones[19] = CreateDynamicObject(18647, 201.52556, -1830.71167, 12.97464,   0.00000, 0.00000, 0.00000);
                neones[20] = CreateDynamicObject(18647, 201.50916, -1828.73169, 12.97464,   0.00000, 0.00000, 0.00000);
                neones[21] = CreateDynamicObject(18647, 201.49695, -1827.13684, 12.97464,   0.00000, 0.00000, 0.00000);
                //_________________________________// LEFT | BLUE //__________________________________________
                neones[22] = CreateDynamicObject(18648, 201.54056, -1847.51367, 17.66767,   90.00000, 0.00000, 0.00000);
                neones[23] = CreateDynamicObject(18648, 201.54056, -1847.51367, 15.67738,   90.00000, 0.00000, 0.00000);
                neones[24] = CreateDynamicObject(18648, 201.54056, -1847.51367, 13.97896,   90.00000, 0.00000, 0.00000);
                //_________________________________// RIGHT | BLUE //__________________________________________
                neones[25] = CreateDynamicObject(18648, 201.54056, -1826.1489, 17.66767,   90.00000, 0.00000, 0.00000);
                neones[26] = CreateDynamicObject(18648, 201.54056, -1826.1489, 15.67738,   90.00000, 0.00000, 0.00000);
                neones[27] = CreateDynamicObject(18648, 201.54056, -1826.1489, 13.97896,   90.00000, 0.00000, 0.00000);
                
                neons = true;
			}
        }
    if(dialogid == 15)//anim buhlo
	{
		if(response)
		{
			if(listitem == 0)
			{
				SetPlayerSpecialAction (playerid, SPECIAL_ACTION_DRINK_BEER );
    	        SendClientMessage(playerid, 0xFFFFFFAA, "Пивка для рывка");
			}
			if(listitem == 1)
			{
				SetPlayerSpecialAction (playerid, SPECIAL_ACTION_SMOKE_CIGGY );
    	        SendClientMessage(playerid, 0xFFFFFFAA, "Пыхни пару раз");
			}
			if(listitem == 2)
			{
			    SetPlayerSpecialAction (playerid, SPECIAL_ACTION_DRINK_WINE );
    	        SendClientMessage(playerid, 0xFFFFFFAA, "Водочки для розводочки");
			}
			if(listitem == 3)
			{
				SetPlayerSpecialAction (playerid, SPECIAL_ACTION_DRINK_SPRUNK );
    	        SendClientMessage(playerid, 0xFFFFFFAA, "Пойди Отдохни");
			}
			PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
   		}
    }
    if(dialogid == 17)//anim dance
	{
		if(response)
		{
			if(listitem == 0)
			{
				SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE1);
			}
			if(listitem == 1)
			{
				SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE2);
			}
			if(listitem == 2)
			{
			    SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE3);
			}
			if(listitem == 3)
			{
				SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE4);
			}
			if(listitem == 4)
			{
				ApplyAnimation( playerid, "DANCING", "bd_clap", 4.1, 1, 0, 0, 1, 0 );
			}
			if(listitem == 5)
			{
				ApplyAnimation( playerid, "DANCING", "bd_clap1", 4.1, 1, 0, 0, 1, 0 );
			}
			if(listitem == 6)
			{
				ApplyAnimation( playerid, "DANCING", "dance_loop", 4.1, 1, 0, 0, 1, 0 );
			}
			if(listitem == 7)
			{
				ApplyAnimation( playerid, "DANCING", "DAN_Down_A", 4.1, 1, 0, 0, 1, 0 );
			}
			PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
			TextDrawShowForPlayer(playerid,Textdraw0);
			TextDrawSetString(Textdraw0, "ПРОБЕЛ STOP ANIM");
			anim = true;
   		}
    }
    if(dialogid == 18)//anim SCRATCHING
	{
		if(response)
		{
			if(listitem == 0)
			{
				ApplyAnimation( playerid, "SCRATCHING", "scdldlp", 4.1, 1, 0, 0, 1, 0 );
			}
			if(listitem == 1)
			{
				ApplyAnimation( playerid, "SCRATCHING", "scdlulp", 4.1, 1, 0, 0, 1, 0 );
			}
			if(listitem == 2)
			{
			    ApplyAnimation( playerid, "SCRATCHING", "scdrdlp", 4.1, 1, 0, 0, 1, 0 );
			}
			if(listitem == 3)
			{
				ApplyAnimation( playerid, "SCRATCHING", "scdrulp", 4.1, 1, 0, 0, 1, 0 );
			}
			if(listitem == 4)
			{
				ApplyAnimation( playerid, "SCRATCHING", "sclng_l", 4.1, 1, 0, 0, 1, 0 );
			}
			if(listitem == 5)
			{
				ApplyAnimation( playerid, "SCRATCHING", "sclng_r", 4.1, 1, 0, 0, 1, 0 );
			}
			if(listitem == 6)
			{
				ApplyAnimation( playerid, "SCRATCHING", "scmid_l", 4.1, 1, 0, 0, 1, 0 );
			}
			if(listitem == 7)
			{
				ApplyAnimation( playerid, "SCRATCHING", "scmid_r", 4.1, 1, 0, 0, 1, 0 );
			}
			if(listitem == 8)
			{
				ApplyAnimation( playerid, "SCRATCHING", "scshrtl", 4.1, 1, 0, 0, 1, 0 );
			}
			if(listitem == 9)
			{
				ApplyAnimation( playerid, "SCRATCHING", "scshrtr", 4.1, 1, 0, 0, 1, 0 );
			}
			if(listitem == 10)
			{
				ApplyAnimation( playerid, "SCRATCHING", "sc_ltor", 4.1, 1, 0, 0, 1, 0 );
			}
			if(listitem == 11)
			{
				ApplyAnimation( playerid, "SCRATCHING", "sc_rtol", 4.1, 1, 0, 0, 1, 0 );
			}
			PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
			TextDrawShowForPlayer(playerid,Textdraw0);
			TextDrawSetString(Textdraw0, "ПРОБЕЛ STOP ANIM");
			anim = true;
   		}
    }
    if(dialogid == 2487)
	{
		if(response)
		{
			switch(listitem)
            {
                case 0:
			    {
			        switch(random(2))
			        {
			            case 0:
			            {
                            CreateExplosion(201.2888, -1847.2943, 8.2862, 4, 3.0);
                            CreateExplosion(201.3107, -1827.5277, 8.2862, 4, 3.0);
                        }
                        case 1:
                        {
                            CreateExplosion(201.2888, -1847.2943, 8.2862, 5, 3.0);
                            CreateExplosion(201.3107, -1827.5277, 8.2862, 5, 3.0);
                        }
                    }
			    }
			    case 1:
				{
				    ShowPlayerDialog(playerid, 2488, DIALOG_STYLE_LIST, "Дым", "Добавить дым\n{FF0000}Выкл {FFFFFF}дым", "OK", "Назад");
				}
				case 2:
				{
				    SetTimer("effects0", 1000, 0);
				}
            }
   		}
    }
    if(dialogid == 2488)
	{
		if(response)
		{
			switch(listitem)
            {
			    case 0:
                {
                    if(dumka == false) dumka = true;
                    dum[0] = CreateDynamicObject(18728, 201.2888, -1847.2943, 5.9512,   0.00000, 0.00000, 0.00000);
				    dum[1] = CreateDynamicObject(18728, 201.3107, -1827.5277, 5.9512,   0.00000, 0.00000, 0.00000);
				    dum[2] = CreateDynamicObject(18728, 201.2980, -1842.4142, 5.9512,   0.00000, 0.00000, 0.00000);
                    dum[3] = CreateDynamicObject(18728, 201.2935, -1832.4043, 5.9512,   0.00000, 0.00000, 0.00000);
                    dum[4] = CreateDynamicObject(18728, 201.2915, -1839.9193, 5.9512,   0.00000, 0.00000, 0.00000);
				    dum[5] = CreateDynamicObject(18728, 201.2715, -1834.9403, 5.9512,   0.00000, 0.00000, 0.00000);
			    }
			    case 1:
                {
                    if(dumka == true) dumka = false;
                    for(new i = 0; i != 6; i++)
	                DestroyDynamicObject(dum[i]);
			    }
            }
   		}
    }
    if(dialogid == 4092) // Время
    {
        if(response)
        {
            switch(listitem)
            {
                case 0: SetWorldTime(12);
                case 1: SetWorldTime(0);
            }
        }
	}
	if(dialogid == 2016)
    {
        if(response)
        {
			new stir[64];
            if(PlayerLiked[playerid] == false){
                golos = golos+1;
			    format(stir, sizeof(stir), "{FFFFFF}Этот трек понравился %d игрокам.\n{B1E2F2}Like добавлен", golos);
			}
            else SendClientMessage(playerid, 0x919191FF, "Вы уже голосовали!");
            //ShowPlayerDialog(playerid, 2016, DIALOG_STYLE_MSGBOX, " ", stir, "Лайкнуть", "Закрыть");
            PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
            PlayerLiked[playerid] = true;
            GolosUpdate();
        }
	}
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	//------------------------------------------------------------------------------
	if ((newkeys==1024)) // Клавиша ALT
	{
	    if(IsPlayerInRangeOfPoint(playerid, 2.0, 197.6653, -1837.3164, 7.8569)) // поставим проверку на нахождение игрока возле пульта
        {
		    OnPlayerCommandText(playerid, "/start");
		}
		if(IsPlayerInRangeOfPoint(playerid, 2.0, 225.4708,-1827.4818,4.5560))
        {
		    ShowPlayerDialog(playerid, 15, DIALOG_STYLE_LIST, "Напитки и Cигареты", "Пивко\nКурево\nВодка\nСпрайт", "OK", "Назад");
		}
		if(IsPlayerInRangeOfPoint(playerid, 3.0, 227.8394, -1834.4072, 3.2969))
        {
		    if(podcasscor[playerid] == false)
			{
  	            switch(random(10))
              	{
  	                case 0:
				    {
					    GivePlayerMoney(playerid, 1000);
					    SetPlayerScore(playerid,GetPlayerScore(playerid)+82);
						SendClientMessage(playerid, 0x919191FF, "Вы получили 1000$ и 82 очков опыта, поздравляем!");
					}
    	            case 1:
				    {
				        GivePlayerMoney(playerid, 5000);
				        SetPlayerScore(playerid,GetPlayerScore(playerid)+220);
				        SendClientMessage(playerid, 0x919191FF, "Вы получили 5000$ и 220 очков опыта, поздравляем!");
	                }
       	            case 2:
				    {
					    GivePlayerMoney(playerid, 10000);
					    SetPlayerScore(playerid,GetPlayerScore(playerid)+60);
					    SendClientMessage(playerid, 0x919191FF, "Вы получили 10000$ и 60 очков опыта, поздравляем!");
					}
				    case 3:
       	            {
					    GivePlayerMoney(playerid, 22000);
					    SetPlayerScore(playerid,GetPlayerScore(playerid)+34);
					    SendClientMessage(playerid, 0x919191FF, "Вы получили 22000$ и 34 очков опыта, поздравляем!");
					}
				    case 4:
				    {
					    GivePlayerMoney(playerid, 57000);
					    SetPlayerScore(playerid,GetPlayerScore(playerid)+87);
					    SendClientMessage(playerid, 0x919191FF, "Вы получили 57000$ и 87 очков опыта, поздравляем!");
					}
				    case 5:
				    {
					    GivePlayerMoney(playerid, 17000);
					    SetPlayerScore(playerid,GetPlayerScore(playerid)+45);
					    SendClientMessage(playerid, 0x919191FF, "Вы получили 17000$ и 45 очков опыта, поздравляем!");
			        }
				    case 6:
				    {
					    GivePlayerMoney(playerid, 90000);
					    SetPlayerScore(playerid,GetPlayerScore(playerid)+975);
					    SendClientMessage(playerid, 0x919191FF, "Вы получили 90000$ и 975 очков опыта, поздравляем!");
					}
				    case 7:
				    {
					    GivePlayerMoney(playerid, 37000);
					    SetPlayerScore(playerid,GetPlayerScore(playerid)+235);
					    SendClientMessage(playerid, 0x919191FF, "Вы получили 37000$ и 235 очков опыта, поздравляем!");
					}
				    case 8:
				    {
					    GivePlayerMoney(playerid, 50000);
					    SetPlayerScore(playerid,GetPlayerScore(playerid)+231);
					    SendClientMessage(playerid, 0x919191FF, "Вы получили 50000$ и 231 очков опыта, поздравляем!");
					}
		            case 9:
					{
					    GivePlayerMoney(playerid, 2000);
					    SetPlayerScore(playerid,GetPlayerScore(playerid)+553);
					    SendClientMessage(playerid, 0x919191FF, "Вы получили 2000$ и 553 очков опыта, поздравляем!");
				    }
				}
			    podcasscor[playerid] = true;
			}
		    if(podcasscor[playerid] == true){SendClientMessage(playerid, 0x919191FF, "Вы уже брали подарок!");}
		}
		if(IsPlayerInRangeOfPoint(playerid, 3.0, 216.79990, -1825.08728, 6.92180))
        {
            if(vor == true)
			{
            new stir[64];
            if(PlayerLiked[playerid] == true) SendClientMessage(playerid, 0x919191FF, "Вы уже голосовали!");
            else
		    format(stir, sizeof(stir), "{FFFFFF}Этот трек понравился %d {FFFFFF}игрокам.", golos);
            ShowPlayerDialog(playerid, 2016, DIALOG_STYLE_MSGBOX, " ", stir, "Лайкнуть", "Закрыть");
            } else SendClientMessage(playerid, 0x919191FF, "Сцена закрыта!");
		}
	}
	if ((newkeys==262144)) // Клавиша H
	{
		if(IsPlayerInRangeOfPoint(playerid, 9.0, 227.8394, -1834.4072, 3.2969))
        {
            if(load == false)
		    {
		        ShowPlayerDialog(playerid,736,DIALOG_STYLE_MSGBOX,"Уведомление","Список анмаций загружен.\nНажмите H ещё раз.","Закрыть","");
				PreloadAllAnimLibs(playerid);
				load = true;
			}
		    else ShowPlayerDialog(playerid, 17, DIALOG_STYLE_LIST, "Анимации танцев", "Танец 1\nТанец 2\nТанец 3\nТанец 4\nТанец 5\nТанец 6\nТанец 7\nТанец 8", "OK", "Назад");
		}
		if(IsPlayerInRangeOfPoint(playerid, 2.0, 197.6653, -1837.3164, 7.8569)) // поставим проверку на нахождение игрока возле пульта
        {
            if(IsPlayerAdmin(playerid) || dj == true)
            {
                new Float:Angle;
                GetPlayerFacingAngle(playerid, Angle);
                if(Angle < 260.0 || Angle > 280.0)
				{
				    SendClientMessage(playerid, 0xFFFFFFFF, "Встаньте лицом к зрителям.");
				}
				else
				{
				    if(load == false)
				    {
				        ShowPlayerDialog(playerid,736,DIALOG_STYLE_MSGBOX,"Уведомление","Список анмаций загружен.\nНажмите H ещё раз.","Закрыть","");
				        PreloadAllAnimLibs(playerid);
					    load = true;
				    }
				    else ShowPlayerDialog(playerid, 18, DIALOG_STYLE_LIST, "Для DJ", "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12", "OK", "Назад");
				}
			}
			else SendClientMessage(playerid,0xFFFF0000,"Вы не DJ/Администратор");
		}
	}
	if ((newkeys==8)) // Клавиша пробел
	{
		if(anim == true)
		{
		    OnPlayerCommandText(playerid, "/stopa");
		    anim = false;
		}
	}
	//------------------------------------------------------------------------------
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
    if(pickupid == pickup_dj)
    {
        if(IsPlayerAdmin(playerid) || dj == true)
        {
            skin_dj[playerid] = GetPlayerSkin(playerid);
            SetPlayerSkin(playerid, 217);
            SendClientMessage(playerid,0xFFFF0000,"Вы переоделись в форму DJ'я");
            SendClientMessage(playerid,0xFFFF0000,"Снять форму - команда: /sn");
		}
		else SendClientMessage(playerid,0xFFFF0000,"Вы не DJ/Администратор");
    }
	return 1;
}

stock PreloadAnimLib(playerid, animlib[]) // Подгрузка анимаций, чтоб с первого раза она воспроизводилась
{
   ApplyAnimation(playerid,animlib,"null",0.0,0,0,0,0,0);
   return 1;
}

stock PreloadAllAnimLibs(playerid)
{
        PreloadAnimLib(playerid,"SCRATCHING");
        PreloadAnimLib(playerid,"DANCING");
        return 1;
}

strtok(const string[], &index) // для команд
{
new length = strlen(string);
while ((index < length) && (string[index] <= ' '))
{
index++;
}

new offset = index;
new result[20];
while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
{
result[index - offset] = string[index];
index++;
}
result[index - offset] = EOS;
return result;
}
