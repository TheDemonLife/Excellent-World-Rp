#if !defined _samp_included
#error Include 'antidos.inc' after 'a_samp.inc' !
#endif
stock LGHideMenuForPlayer(Menu:menuid, playerid) return CallRemoteFunction("OnHideMenuForPlayer", "dd", _:menuid, playerid);
stock LGShowMenuForPlayer(Menu:menuid, playerid) return CallRemoteFunction("OnShowMenuForPlayer", "dd", _:menuid, playerid);
//stock SetPlayerNameR(playerid, changenam[]) return CallRemoteFunction("SetPlayerNameAC", "ds", playerid, changenam);
#define HideMenuForPlayer LGHideMenuForPlayer
#define ShowMenuForPlayer LGShowMenuForPlayer
//#define SetPlayerName SetPlayerNameR