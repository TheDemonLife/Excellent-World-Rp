/*
							English:
	Include Version 1.0 For Script 'AntiDoS_Protect'!
	You Need This Include For Function: 'AntiVehicleChit'!
	Add '#include <AntiDoSProtect>' On The TOP(after #include <a_samp>) Of Your GameMode Or Another Scripts!
	Made By [KrYpToDeN]
	Skype: net6616
	All Rights Reserved ©
*/
/*
							Russian:
	Инклуд Версии 1.0 Для Скрипта 'AntiDoS_Protect'!
	Вам Необходим Данный Инклуд Для Функций: 'AntiVehicleChit'!
	Добавьте '#include <AntiDoSProtect>' В Верхушку(После '#include <a_samp>') Вашего ГеймМода Или Других Скриптов!
	Автор: [KrYpToDeN]
	Скайп: net6616
	Все Права Защищены ©
*/


#if !defined _samp_included 
	#error Include 'AntiDoSProtect.inc' should be loaded after 'a_samp.inc'!
#endif

#if defined _KrYpToDeN_included
	#endinput
#endif

#define _KrYpToDeN_included
#pragma library KrYpToDeN

stock AntiVehicleChit(playerid,vehicleid,seatid)
{
    SetPVarInt(playerid,"ChitCar",vehicleid);
    PutPlayerInVehicle(playerid,vehicleid,seatid);
}
#define PutPlayerInVehicle AntiVehicleChit