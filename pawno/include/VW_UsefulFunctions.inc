/*
 *            VW_UsefulFunctions 1.2
 *       (c) Copyright 2009-2010 by Hidden -=DANGER=-
 *
 * @author    : DANGER1979 (http://dracoblue.com)
 * @date      : 8th  July 2010
 * @update    : 8th  July 2010
 *
 * This file is provided as is (no warranties).
 *
 */
/*#if defined _samp_included
	#endinput
#endif
#define _samp_included
#pragma library samp*/

#include <a_samp>
/*#if !defined _samp_included
	#tryinclude <a_samp>
	#if !defined _samp_included
		#error could not locate a_samp.inc file, please check your server includes
	#endif
#endif*/

//#define _VW_UsefulFunctions_included
//#pragma library VW_UsefulFunctions

#define MAX_STRING 256
#define COLOR_RED 0xFF0000FF//красный для запрещающих сообщений 255 0 0
#define COLOR_MAROON 0x800000FF//бордовый для админских оповещений 128 0 0

forward Float:GetDistanceBetweenPlayers(playerid, targetid);
//##############################################################################//
//                                                                              //
//                             ПЕРЕГРУЖЕННЫЕ ФУНКЦИИ                            //
//                                                                              //
//##############################################################################//
stock PlaySoundForPlayer(playerid, soundid)
{   //проигрывает звук soundid по координатам игрока  playerid
	if(IsValidSound(soundid))
	{
		new Float:pX, Float:pY, Float:pZ;
		GetPlayerPos(playerid, pX, pY, pZ);
		PlayerPlaySound(playerid, soundid, pX, pY, pZ);
	}
}
stock PlaySoundForObject(objectid, soundid)
{   //проигрывает звук soundid по координатам объекта objectid
	if(IsValidSound(soundid))
	{
		new Float:pX, Float:pY, Float:pZ;
		GetObjectPos(objectid, pX, pY, pZ);
		for(new i=0; i<GetMaxPlayers(); i++)
		{
			if(IsPlayerConnected(i) && !IsPlayerNPC(i))
			{
				if(IsPlayerInRangeOfPoint(i, 100.0, pX, pY, pZ)) PlayerPlaySound(i, soundid, pX, pY, pZ);
			}
		}
	}
}

//##############################################################################//
//                                                                              //
//                                ФУНКЦИИ ПРОВЕРКИ                              //
//                                                                              //
//##############################################################################//
stock IsValidSound(soundid)
{
	new Sounds[] = 	{ 	1002, 1009, 1027, 1035, 1036, 1039, 1052, 1053,
   					1054, 1055, 1056, 1057, 1058, 1062, 1063, 1068,
   					1069, 1076, 1077, 1083, 1084, 1085, 1097, 1098,
   					1130, 1131, 1132, 1133, 1134, 1135, 1136, 1137,
					1138, 1139, 1140, 1141, 1142, 1143, 1144, 1145,
   					1146, 1147, 1148, 1149, 1150, 1153, 1154, 1163,
   					1165, 1166, 1169, 1183, 1184, 1185, 1186, 1187,
   					1188
				};
    for(new i = 0; i < sizeof(Sounds); i++)
    {
        if(Sounds[i] == soundid) return 1;
    }
    return 0;
}

stock CheckValidWeather(wid)
{
	if(wid > 0 && wid < 50)
	{
		return 1;
	}
    return 0;
}
stock CheckValidTime(timeid)
{
	if (timeid > 1 && timeid < 24)
	{
		return 1;
	}
	return 0;
}
stock CheckValidSkin(SkinID)
{
	if( (SkinID == 0)||(SkinID == 7)||(SkinID >= 9 && SkinID <= 41)||
		(SkinID >= 43 && SkinID <= 64)||(SkinID >= 66 && SkinID <= 73)||
		(SkinID >= 75 && SkinID <= 85)||(SkinID >= 87 && SkinID <= 118)||
		(SkinID >= 120 && SkinID <= 148)||(SkinID >= 150 && SkinID <= 207)||
		(SkinID >= 209 && SkinID <= 264)||(SkinID >= 274 && SkinID <= 288)||
		(SkinID >= 290 && SkinID <= 299)
	  )
	{
		return 1;
	}
	return 0;
}
stock SetPlayerSkinEx(playerid, skinid)
{
	if(CheckValidSkin(skinid)) SetPlayerSkin(playerid, skinid);
	else
	{
	    new string[MAX_STRING];
		format(string, sizeof(string), "Error: playerid %s[%d], reason: Use Invalid Skin %d", PlayerName(playerid), playerid, skinid);
		//ABroadCast(COLOR_MAROON, string, 1);
		SendClientMessageToAll(COLOR_MAROON, string);
	}
}
stock IsNumeric(const string[])
{
	for (new i = 0, j = strlen(string); i < j; i++)
	{
		if (string[i] > '9' || string[i] < '0') return 0;
	}
	return 1;
}
/*
//Has also a fix to use "-" and "+" in the beginning of the number.
stock isNumeric(const string[])
{
	new length = strlen(string);
	if(length == 0) return false;
	for(new i = 0; i < length; i++)
    {
		if((string[i] > '9' || string[i] < '0' && string[i]!='-' && string[i]!='+') // Not a number,'+' or '-'
             || (string[i]=='-' && i!=0)                                             // A '-' but not at first.
             || (string[i]=='+' && i!=0)                                             // A '+' but not at first.
		   ) return false;
    }
	if(length==1 && (string[0]=='-' || string[0]=='+')) return false;
	return true;
}*/

/*IsAnyTrailerAttachedToVehicle(vehicleid)
{
	new trailerid = GetVehicleTrailer(vehicleid);
	new modelid = GetVehicleModel(trailerid);
	if(modelid == 435 || modelid == 450 || modelid == 591 || modelid == 606 || modelid == 607 ||
	modelid == 610 || modelid == 569 || modelid == 590 || modelid == 584 || modelid == 570 ||
        modelid == 608 || modelid == 611) return true;

	return false;
}
IsAnyTrailerAttachedToVehicle(vehicleid)
{
    new v[] = { 435, 450, 591, 606, 607, 610, 569, 590, 584, 570, 608, 611 };
    for(new i = 0; i < sizeof(v); i++)
        if(GetVehicleModel(GetVehicleTrailer(vehicleid)) == v[i])
            return true;
    return false;
}*/
stock IsAnyTrailerAttachedToVehicle( vehicleid )
{
    switch( GetVehicleModel( GetVehicleTrailer(vehicleid) ) )
    {
        case 435, 450, 591, 606, 607, 610, 569, 590, 584, 570, 608, 611: return true;
    }
    return false;
}
stock IsValidWheelAndNosVehicle(vehicleid)
{
	switch( GetVehicleModel(vehicleid) )
	{
		case 448,461,
		462,463,468,521,522,523,581,586,481,509,
		510,430,446,452,453,454,472,473,484,493,
		595,460,464,476,511,512,513,519,520,553,
		577,592,593,417,425,447,465,469,487,488,
		497,501,548,563,449,537,538,569,570,590: return 0;
	}
	return 1;
}
stock checkDate(const str[], const look = '/')
{
	new count,swt;
	while(count<strlen(str) && (str[count] >= 48 && str[count] <= 57 || str[count] == look))
	{
	    if(str[count] == look)
	    {
			if(count && !swt) swt = 1;
			else if(count == 5 && swt) swt = 2;
			else break;
	    }
        count++;
	}
	return (count == 10) ? (1) : (0);
}

stock GetSeatVehiclePlayer(vehicleid, seatid)
{   //получить ID игрока который сидит на данном месте
//не работает в одном месте с PutPlayerInVehicle, только в следующей проверке
	for(new i=0; i<GetMaxPlayers(); i++)
	{
		if(IsPlayerConnected(i) && IsPlayerInVehicle(i, vehicleid))//IsPlayerInAnyVehicle(i)
		{	//сканируем всех кто находится в данной тачке
       		if(GetPlayerVehicleSeat(i) == seatid && GetPlayerVehicleSeat(i) != -1)
       		{   //Will also return 0 if the player is not in a vehicle!
   	        	//ИНФОРМИРОВАНИЕ
				//new string[256];
				//format(string, sizeof(string), "GetPlayerVehicleSeat(playerid: %d) = %d", i, GetPlayerVehicleSeat(i));
				//SendClientMessageToAll(COLOR_YELLOW, string);
   	        	return i;
			}
	    }
	}
	return INVALID_PLAYER_ID;
}
//##############################################################################//
//                                                                              //
//                               БЛОКИ АВТОЗАМЕНЫ                               //
//                                                                              //
//##############################################################################//
stock PlayerName(playerid)
{  //для получения имя игрока
	new pName[MAX_PLAYER_NAME+1];//20+1
	GetPlayerName(playerid, pName, sizeof(pName));
	return pName;
}
stock WeaponName(weaponid)
//weaponid,const weapon[],len)
{  //для получения имя оружия
	new gunname[256];
	GetWeaponName(weaponid, gunname, sizeof(gunname));
	return gunname;
}
stock TimeConverter(seconds)//Конвертер секунды в минуты и секунды
{
	new string[6];//объявляем символьную переменную
 	new minutes = floatround(seconds/60);//кол. целых минут
	seconds -= minutes*60; 	//остаток
	format(string, sizeof(string), "%02d:%02d", minutes, seconds);//преобразовываем
	return string;//возвращаем строку символов
}
stock timeconvert(Time, &Minutes, &Seconds, &rMSeconds)//для гонок конвертор мс в мин:сек.мсек
{   //Time - кол-во процесорных тиков с момента старта, в мс
	new Float:fTime = floatdiv(Time, 60000);//Делит вещественное число на значение, указанное вещественным числом, делителем.
    Minutes = floatround(fTime, floatround_tozero);//Округляет вещественное число указанным методом.
    //Round downwards for positive values and upwards for negative values (“truncate”).
    //Округлить вниз для положительных величин и вверх для отрицательных величин
    Seconds = floatround(floatmul(fTime - Minutes, 60), floatround_tozero);
						//Перемножает два вещественных числа и возвращает произведение.
    rMSeconds = floatround(floatmul(floatmul(fTime - Minutes, 60) - Seconds, 1000), floatround_tozero);
}
stock ReturnUser(text[], playerid = INVALID_PLAYER_ID)
{
	new pos = 0;
	while(text[pos] < 0x21) // Strip out leading spaces //Удаляет свободное место
	{
		if(text[pos] == 0) return INVALID_PLAYER_ID; // No passed text //Нет текста на входе
		pos++;
	}
	new userid = INVALID_PLAYER_ID;
	if(IsNumeric(text[pos])) // Check whole passed string - Проверьте целую прошедшую строку
	{   //если строка представлена в виде числа
		// If they have a numeric name you have a problem (although names are checked on id failure)
		// Если у них есть числовое имя у вас есть проблема (хотя имена проверены в неудаче)
		userid = strval(text[pos]);
		if(userid >= 0 && userid < MAX_PLAYERS)// && !IsPlayerNPC(userid)
		{
			if(!IsPlayerConnected(userid))	userid = INVALID_PLAYER_ID;
			else return userid; // A player was found
		}
	}
	// They entered [part of] a name or the id search failed (check names just incase)
	new len = strlen(text[pos]);
	new count = 0;
	new name[MAX_PLAYER_NAME+1];
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i) && !IsPlayerNPC(i))
		{
			GetPlayerName(i, name, sizeof(name));
			if(strcmp(name, text[pos], true, len) == 0) // Check segment of name
			{   //проверяем совпадает ли введенное имя с одним из онлайн игроков
				if(len == strlen(name)) // Exact match //более Точная проверка
				{   //если длина также совпадает
					return i; // Return the exact player on an exact match
					//Возвращает точного указанного игрока ID и выходит из ф-ии
				}
				else // Partial match //Частичная проверка
				//В противном случае если есть два игрока:
				//Me и MeYou всякий раз, когда Вы ввели Me это должно найти оба
				//И никогда не быть способным возвращать просто Me id
				{   //если введена не полная часть имени, то совпадение частичное
					count++;
					userid = i;//записываем userid =
				}
			}
		}
	}
	if(count != 1)
	{
		if(playerid != INVALID_PLAYER_ID)// && !IsPlayerNPC(playerid)
		{
			if(count) ABroadCast(COLOR_RED, "Error: Multiple users found, please narrow earch", 1);
			else ABroadCast(COLOR_RED, "Error: No matching user found", 1);
		}
		userid = INVALID_PLAYER_ID;
	}
	return userid; // INVALID_USER_ID for bad return
}
//Sets the Player X,Y,Z and the facing angle, also sets the interior and virtualworld, Option to for camera behing player (use 0/1)
stock SetPlayerArea(playerid,Float:x,Float:y,Float:z,Float:angle,Interior,World,Cameraback)
{
	SetPlayerPos(playerid,x,y,z);
	SetPlayerFacingAngle(playerid,angle);
	SetPlayerInterior(playerid,Interior);
	SetPlayerVirtualWorld(playerid,World);
	if(Cameraback == 1)
	{
		SetCameraBehindPlayer(playerid);
	}
}
stock SetCarArea(vehicleid,Float:x,Float:y,Float:z,Float:angle,Interior,World)
{
	SetVehiclePos(vehicleid,x,y,z);
	SetVehicleZAngle(vehicleid,angle);
	LinkVehicleToInterior(vehicleid,Interior);
	SetVehicleVirtualWorld(vehicleid,World);
}
//------------------------------------------------------------------------------
stock GetDistanceToPoint(playerid, Float:x2, Float:y2, Float:z2)//возвращает растояние от игрока до машины
{
	new Float:x1, Float:y1, Float:z1, Float:tmpdis;
	GetPlayerPos(playerid,x1,y1,z1);
	tmpdis = floatsqroot(floatpower(floatsub(x2,x1),2)+floatpower(floatsub(y2,y1),2)+floatpower(floatsub(z2,z1),2));
	return floatround(tmpdis);
}
public Float:GetDistanceBetweenPlayers(playerid, targetid)
{   //ф-ия получения растояние между игроками
	new Float:x1,Float:y1,Float:z1, Float:x2,Float:y2,Float:z2;
	if(!IsPlayerConnected(playerid) || !IsPlayerConnected(targetid)) return -1.00;
	GetPlayerPos(playerid,x1,y1,z1);
	GetPlayerPos(targetid,x2,y2,z2);
	//new Float: fDistance =
	return floatsqroot(floatpower(floatsub(x2,x1),2)+floatpower(floatsub(y2,y1),2)+floatpower(floatsub(z2,z1),2));
			//floatsqroot - Вычисляет квадратный корень данного вещественного числа.
						//floatpower - Возводит вещественное число в степень.
								//floatabs - Возвращает абсолютное значение вещественного числа.
										//floatsub - Уменьшает первое число oper1 на число, указанное в oper2.
	//return fDistance;
}
/*stock GetDistanceBetweenPlayers(playerid, playerid2)
{
	new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
	new Float:tmpdis;
	GetPlayerPos(playerid,x1,y1,z1);
	GetPlayerPos(playerid2,x2,y2,z2);
	tmpdis = floatsqroot(floatpower(floatsub(x2,x1),2)+floatpower(floatsub(y2,y1),2)+floatpower(floatsub(z2,z1),2));
	return floatround(tmpdis);//возвращает целое
}*/
stock IsPlayerOnLine(playerid, Float:x2,Float:y2, Float:x3,Float:y3)
{   //возвращает верно когда игрок находится на линии
	new Float:x1,Float:y1,Float:z1;
	GetPlayerPos(playerid,x1,y1,z1);
	nCheck = (x2-x1)*(y2-y3)-(y2-y1)*(x2-x3);
//Значение nCheck = 0, если точка 1 лежит на прямой, проходящей через точки a и c.
//nCheck > 0, если точка 1 находится справа от прямой.
//nCheck < 0, если точка 1 находится слева от прямой.
	if(nCheck == 0) return 1;//возвращает верно если игрок на линии
	return 0;
}
new Float:xp[] = {15.0, 47.65, 81.84}; // Массив X-координат многоугольника
new Float:yp[] = {10.0, 68.9, 18.21}; // Массив Y-координат многоугольника
stock IsPointInPolygon(Float:x, Float:y)
{
	new npol = sizeof(xp);
	new j = npol - 1;
	new c = 0;
	for (new i = 0; i < npol; i++)
	{
		if(
			(
				((yp[i]<=y) && (y<yp[j])) || ((yp[j]<=y) && (y<yp[i]))
			) && (
				x > (xp[j] - xp[i]) * (y - yp[i]) / (yp[j] - yp[i]) + xp[i])
			)
		{
			c = !c;
		}
		j = i;
	}
	//Начало проверки чётности
	new value = (c+2)/2 - (c+1)/2;//результат целочисленного деления
	//Равно 1 если "c" четное, 0 - нечетное.
	//printf( "value: %d, c: %d", value, c);
	if(value == 1) return 0;//если чётное - точка не принадлежит треугольнику
	else return 1;//если нечётное - точка принадлежит треугольнику
}
stock CheckPointInTriangle( Float:x0,Float:y0,
							Float:x1,Float:y1,
							Float:x2,Float:y2,
							Float:x3,Float:y3)
{   //возвращает верно если токчка 0 находится указанном треугольнике
    new Float: ab = CheckPoint(x0,y0,x1,y1,x2,y2);
    new Float: bc = CheckPoint(x0,y0,x2,y2,x3,y3);
	new Float: cd = CheckPoint(x0,y0,x3,y3,x1,y1);
	if(ab < 0 || bc < 0 || cd < 0) return 0;
	else return 1;
}
forward Float: CalculateArea(Float:x1,Float:y1,Float:x2,Float:y2,Float:x3,Float:y3);
public Float: CalculateArea(Float:x1,Float:y1,
					Float:x2,Float:y2,
					Float:x3,Float:y3)
{   //возвращает площадь треугольника
    new Float: ab = x1*y2 - y1*x2;
    new Float: bc = x2*y3 - y2*x3;
	new Float: ca = x3*y1 - y3*x1;
	new Float: S = floatabs((ab + bc + ca)/2);
	//printf("ab:%.1f, bc:%.1f, ca:%.1f, S=%.1f",ab, bc, ca, S);
	return S;
}//Проверка: //S = 1/2 * a * h = 1921
//S = 1/2 * a * b * sin(gamma) = 1820;

/*enum FigureInfo
{
	Float:x,
	Float:y,
	Float:z
}
new Float:coords[3][FigureInfo];//3 - Triangle*/
//height - height Triangle
//alfa - Angle Triangle for height Triangle
stock IsPlayerInTriangle(playerid, targetid, Float:height, Float:alfa)
{
	GetPlayerPos(playerid, coords[0][x], coords[0][y], coords[0][z]);//Вершина A
    new Float:route;//наклон треугольника
   	GetPlayerFacingAngle(playerid, route);
  	new Float:Xt, Float:Yt, Float:Zt;//искомая точка
	GetPlayerPos(targetid, Xt, Yt, Zt);

	new Float: c = height / floatcos((alfa/2), degrees);//сторона противоположная вершине С
	new Float: b = c;

	new Float: Angle = route + alfa/2.0;
    coords[1][x] = coords[0][x] + (c * floatsin(-Angle, degrees));//координаты вершины B
    coords[1][y] = coords[0][y] + (c * floatcos(-Angle, degrees));

	Angle = route - alfa/2.0;
    coords[2][x] = coords[0][x] + (b * floatsin(-Angle, degrees));//координаты вершины C
    coords[2][y] = coords[0][y] + (b * floatcos(-Angle, degrees));

	new Float: xnew, Float: ynew;
	new Float: xold, Float: yold;
	new Float: x1, Float: y1, Float: x2, Float: y2;
	new inside = 0;
	new npoints = sizeof(coords);
	if(npoints < 3) return 0;
	xold = coords[npoints-1][x];
	yold = coords[npoints-1][y];
	for(new i=0; i<npoints; i++)
	{
		xnew = coords[i][x];
		ynew = coords[i][y];
		if(xnew > xold)
		{
			x1 = xold; y1 = yold;
			x2 = xnew; y2 = ynew;
		}
		else
		{
			x2 = xold; y2 = yold;
			x1 = xnew; y1 = ynew;
		}
		if((xnew < Xt) == (Xt <= xold)         // edge "open" at left end
           && (Yt-y1)*(x2-x1) < (y2-y1)*(Xt-x1))
		{
			inside = !inside;
		}
		xold = xnew;
		yold = ynew;
	}
	return inside;
}
/*stock IsPlayerInRangeOfPoint(playerid, Float:range, Float:x, Float:y, Float:z)
{   //оптимизированная встроенная ф-ия
	new Float:px, Float:py, Float:pz;
	GetPlayerPos(playerid, px, py, pz);
	px -= x;	py -= y;	pz -= z;
	return ((px * px) + (py * py) + (pz * pz)) < (range * range);
}*/
stock PlayerToPoint(playerid, Float:radi, Float:x, Float:y, Float:z)
{	//ф-ия проверки нахождения игрока в заданном радиусе относительно указанных координат
    if(IsPlayerConnected(playerid) && !IsPlayerNPC(playerid))//если игрок подключился
	{
		new Float:oldposx, Float:oldposy, Float:oldposz;//создаём переменный для хранения старых значений
		new Float:tempposx, Float:tempposy, Float:tempposz;//создаём переменный для временного хранения значений
		GetPlayerPos(playerid, oldposx, oldposy, oldposz);//получить позицию игрока и записать в переменные
		tempposx = (oldposx -x);//временной присвоить значение равное разности между старыми и получаемыми данными
		tempposy = (oldposy -y);
		tempposz = (oldposz -z);
		//printf("DEBUG: X:%f Y:%f Z:%f",posx,posy,posz);
		if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
		{//если временное меньше получаемых данных
			return 1;//Возвращает верно если игрок находится в указаннной зоне
		}
	}
	return 0;
}
stock IsPlayerInRangeOfPlayer(Float:radi, playerid, targetid)
{   //возвращает верно в случаи если растояние от playerid до targetid меньше указанного
	if(IsPlayerConnected(playerid) && IsPlayerConnected(targetid) &&
		!IsPlayerNPC(playerid) && !IsPlayerNPC(targetid))
	{
		new Float:posx, Float:posy, Float:posz;
		GetPlayerPos(targetid, posx, posy, posz);
		//new Float:oldposx, Float:oldposy, Float:oldposz;
		//new Float:tempposx, Float:tempposy, Float:tempposz;
		//GetPlayerPos(playerid, oldposx, oldposy, oldposz);
		//tempposx = (oldposx -posx);
		//tempposy = (oldposy -posy);
		//tempposz = (oldposz -posz);
		//if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
   		if(IsPlayerInRangeOfPoint(playerid, radi, posx, posy, posz))
		{
			return 1;
		}
	}
	return 0;
}
stock IsVehicleInRangeOfPoint(vehicleid, Float:range, Float:x, Float:y, Float:z)
{	//ф-ия проверки нахождения тачки в заданном радиусе относительно указанных координат
	new Float:px, Float:py, Float:pz;
	GetVehiclePos(vehicleid, px, py, pz);
	px -= x;   py -= y;   pz -= z;
	return ((px * px) + (py * py) + (pz * pz)) < (range * range);
}
stock IsPlayerInCube(playerid, xmin, ymin, zmin, xmax, ymax, zmax)
{	//ф-ия проверки нахождения игрока в заданном кубе
   new Float:x, Float:y, Float:z;
   GetPlayerPos(playerid, x, y, z);
   if( x > xmin && y > ymin && z > zmin && x < xmax && y < ymax && z < zmax) return 1;
   return 0;
}
//для УСТАНОВКИ КОНТРОЛЬНЫХ МЕТОК и для УСТАНОВКИ ИКОНОК НА КАРТЕ
stock IsPlayerInArea(playerid, Float:area[6])//возвращает верно каждую секунду
{   //если игрок находится в прямоугольном кубе ограниченной координатами из массива area
	if(IsPlayerConnected(playerid) && !IsPlayerNPC(playerid))
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		if (x > area[0] && x < area[3] && y > area[1] && y < area[4] && z > area[2] && z < area[5]) return 1;
		//если текущие координаты находятся между координатами из массива checkCoords
	}
	return 0;
}
stock Float:GetPointDistanceToPointEx(Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2)
{
    new Float:x, Float:y, Float:z;
    x = x1-x2;
    y = y1-y2;
    z = z1-z2;
    return floatsqroot(x*x+y*y+z*z);//возвращает растояние между 2-мя точками
}
//forward Float:Distance(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2);
stock Float:Distance(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2)
{
	new Float:result = floatsqroot(floatpower(floatsub(x2,x1),2)+floatpower(floatsub(y2,y1),2)+floatpower(floatsub(z2,z1),2));
	return result;
}

stock GetDistanceToCar(playerid, vehicleid)
//stock GetDistanceFromPlayerToVehicle(playerid, vehicleid)
{	//возвращает растояние от игрока до машины
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2, Float:tmpdis;
	GetPlayerPos(playerid,x1,y1,z1);
	GetVehiclePos(vehicleid,x2,y2,z2);
	tmpdis = floatsqroot(floatpower(floatsub(x2,x1),2)+floatpower(floatsub(y2,y1),2)+floatpower(floatsub(z2,z1),2));
						//Возводит вещественное число в степень.
											//Уменьшает первое число oper1 на число, указанное в oper2.
	return floatround(tmpdis);
}
stock GetDistanceBetweenVehicles(vehicleid, vehicleid2)
{
	new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
	new Float:tmpdis;
	GetVehiclePos(vehicleid,x1,y1,z1);
	GetVehiclePos(vehicleid2,x2,y2,z2);
	tmpdis = floatsqroot(floatpower(floatsub(x2,x1),2)+floatpower(floatsub(y2,y1),2)+floatpower(floatsub(z2,z1),2));
	return floatround(tmpdis);
}
//stock GetDistanceCarToPoint(vehicleid,Float:specialzone[3])//для антирадара
stock GetDistanceCarToPoint(vehicleid,Float:x1,Float:y1,Float:z1)//для антирадара
{   //возвращает растояние от игрока до точки
	new Float:x2, Float:y2, Float:z2;
	new Float:dist;
	GetVehiclePos(vehicleid,x2,y2,z2);
	dist = floatsqroot(floatpower(floatsub(x2,x1),2)+floatpower(floatsub(y2,y1),2)+floatpower(floatsub(z2,z1),2));
	return floatround(dist);
}
stock GetObjectToPlayerDistance(playerid, objectid)
{
	new Float:ox, Float:oy, Float:oz, Float:px, Float:py, Float:pz;
	new Float:distance;
	GetObjectPos(objectid, ox, oy, oz);
	GetPlayerPos(playerid, px, py, pz);
	distance = floatsqroot(floatpower(floatsub(ox, px)),2)+floatpower(floatsub(oy, py),2)+floatpower(floatsub(oz, pz),2));
	return floatround(distance);
}

stock GetXYInfrontOfPlayer(playerid, Float:distance, &Float:x, &Float:y)
{   //получить координаты перед игроком
    new Float:z, Float:angle;
 	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, angle);
    x += (distance * floatsin(-angle, degrees));
    y += (distance * floatcos(-angle, degrees));
}
//stock GetXYInfrontOfVehicle(vehicleid, Float:distance, &Float:x, &Float:y)
stock GetXYInfront(Float:distance, Float:angle, &Float:x, &Float:y)
{   //получить координаты перед машиной
    //new Float:z, Float:angle;
 	//GetVehiclePos(vehicleid, x, y, z);
	//GetVehicleZAngle(vehicleid, angle);
    x += (distance * floatsin(-angle, degrees));
    y += (distance * floatcos(-angle, degrees));
}
stock GetXYInrear(Float:distance, Float:angle, &Float:x, &Float:y)
{   //получить координаты за указанной точкой
    //new Float:z, Float:angle;
 	//GetPlayerPos(playerid, x, y, z);
	//GetVehicleZAngle(LastCar[playerid], A);
    x -= (distance * floatsin(-angle, degrees));
    y -= (distance * floatcos(-angle, degrees));
}
stock GetXYZInrear(Float:distance, Float:angle, Float:pitch, &Float:x, &Float:y, &Float:z)
{
    x -= (distance * floatsin(-angle, degrees));
    y -= (distance * floatcos(-angle, degrees));
    z -= (distance * floatsin(pitch, degrees));
}

stock GetAngleToXY(Float:X, Float:Y, Float:CurrentX, Float:CurrentY, &Float:Angle)
{
    Angle = atan2(Y-CurrentY, X-CurrentX);
    Angle = floatsub(Angle, 90.0);
    if(Angle < 0.0) Angle = floatadd(Angle, 360.0);
}
stock Float:GetAngleToPoint(Float:x1, Float:y1, Float:x2, Float:y2)
{
    new Float:Angle;
    Angle = atan2(y2 - y1, x2 - x1) + 270;
    return Angle < 360 ? Angle : Angle - 360;
}



/*stock GetVehicleDriver(vehicleid)
{
    for(new i=0; i<GetMaxPlayers(); i++)
    {
        if (IsPlayerInVehicle(i, vehicleid))
        {
            if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
            {
       			return i;//возвращает ID водителя
            }
		}
    }
    return -1;
}*/
stock GetDriver(vehicleid)
{
	for(new i = 0; i<GetMaxPlayers();i++)
	{
		if(IsPlayerConnected(i))
		{
			if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
			{
				if(IsPlayerInVehicle(i,vehicleid)) return i;
			}
		}
	}
	return INVALID_PLAYER_ID;
}

stock GetPlayerSpeed(playerid)
{
    new Float: v[3];
    GetPlayerVelocity(playerid, v[0], v[1], v[2]);
	return 	floatround
			(
				floatsqroot
				(
					floatpower(v[0]*100.0,2) +
					floatpower(v[1]*100.0,2) +
					floatpower(v[2]*100.0,2)
				), floatround_floor//округляем в нижнее значение
			);
}

/*
  Узнает для транспорта его текущую моментальную скорость в м/ч.
  ---
  vehicleid    игровой ИД транспорта
  ---
  Вернет скорость в М/Ч.
*/
stock getVehicleSpeed(vehicleid)
{
	new Float: v[3];
	GetVehicleVelocity(vehicleid, v[0], v[1], v[2]);
	return 	floatround
			(
				floatsqroot
				(
					floatpower(v[0]*100.0,2) +
					floatpower(v[1]*100.0,2) +
					floatpower(v[2]*100.0,2)
				), floatround_floor//округляем в нижнее значение
			);
  //return floatround( 200.0 * floatsqroot( v[0]*v[0] + v[1]*v[1] + v[2]*v[2] ), floatround_floor );//в км/ч
}

/*
  Выставит для транспорта моментальную скорость в Км/ч.

  (!) Скорость не постоянная, а моментальная и, Вам понадобится таймер,
    чтобы сделать подобие постоянной скорости с помощью этой функции.

  (?) Функция учитывает текущие углы поворота транспорта и базируется
    в основном на текущей скорости транспорта.

  (?) Если транспорт стоит и новая скорость больше 0, то он поедет вперед.

  (?) Если транспорт едет вперед/назад, а новая скорость больше/меньше текущей,
    то транспорт продолжит ехать, не меняя направление, но уже с новой скоростью.

  ---
  vehicleid    игровой ИД транспорта
  speed_mph    новая скорость транспорта в КМ/Ч

  ---
  Ничего не возвращает.
*/
stock setVehicleSpeed(vehicleid, speed_kmph)
{
	if(speed_kmph < 1) speed_kmph = 1;

	new Float: v[3], cur_speed_kmph;
	GetVehicleVelocity(vehicleid, v[0], v[1], v[2]);
	cur_speed_kmph = floatround(200.0 * floatsqroot( v[0]*v[0] + v[1]*v[1] + v[2]*v[2]), floatround_floor);

	if(cur_speed_kmph <= 0)
	{
		new Float: zAngle;
		GetVehicleZAngle(vehicleid, zAngle);

		new Float: newVelX = floatcos( (zAngle -= 270.0), degrees ) * speed_kmph / 200.0;
		SetVehicleVelocity(vehicleid, newVelX, floattan(zAngle,degrees) * newVelX, 0.0);
		return;
	}

	new Float: vMultiplier = float(speed_kmph) / float(cur_speed_kmph);
	//float - преобразовывает целое в вещественную
	SetVehicleVelocity(vehicleid, v[0] * vMultiplier, v[1] * vMultiplier, v[2] * vMultiplier);
}

stock IsVehicleAttachedToTrailer(vehicleid)
{   //получить ID тачки прицепленной к чему либо
	for(new car = 1; car<(MAX_VEHICLES-1); car++)
	{
		if(IsTrailerAttachedToVehicle(car))
		{   //работает правильно толко тогда когда в тягаче сидит человек
	     	if( vehicleid == GetVehicleTrailer(car) )
       		{
				//ИНФОРМИРОВАНИЕ
				//new string[MAX_STRING];
				//format(string, sizeof(string), "IsVehicleAttachedToTrailer(%d) - %d", vehicleid, car);
				//ABroadCast(COLOR_MAROON, string, 9);
   	        	return car;//если данная тачка к чему то прицеплена то вернуть верно
			}
	    }
	}
	return 0;
}
stock RespawnAllCars()
{
	new unoccupied[MAX_VEHICLES-1];
	for(new i=0; i<GetMaxPlayers(); i++)
	{
       	if(IsPlayerInAnyVehicle(i))	unoccupied[GetPlayerVehicleID(i)] = 1;
    }
	for(new car = 1; car<(MAX_VEHICLES-1); car++)
	{
		//VehicleName[GetVehicleModel(car)-400][Category] != Trailers)
		//ВНИМАНИЕ: трейлер не считаетс прицепленным когда игрок не сидит за рулём тягача
		if(unoccupied[car] == 1 || (unoccupied[IsVehicleAttachedToTrailer(car)] == 1)) { }
		else
		{
			SetVehicleToRespawn(car);//ВНИМАНИЕ: тачка также починится полностью и востановит здоровье на 1000
		}
	}
}
stock GetPlayersInVehicle(vehicleid)
{   //для получения кол-ва игроков в данной машине
    new amount = 0;
    for(new i = 0; i < GetMaxPlayers(); i++)
    {
        if(!IsPlayerConnected(i) || !IsPlayerInVehicle(i,vehicleid)) continue;
        amount++;
    }
    return amount;
}

//#define RemovePlayerFromVehicle removePlayerFromVehicle
stock removePlayerFromVehicle(playerid)
{
    if ( !IsPlayerInAnyVehicle(playerid) ) return 0;

    new vid = GetPlayerVehicleID(playerid);
    if ( vid == INVALID_VEHICLE_ID ) return 0;

    new Float: pos[4], Float: sideAngle;
    GetVehiclePos   ( vid, pos[0], pos[1], pos[2] );
    GetVehicleZAngle( vid, pos[3] );

    switch ( GetPlayerVehicleSeat(playerid) )
    {
        case 0,2 : sideAngle = pos[3] - 180.0;
        default  : sideAngle = pos[3];
    }
    SetPlayerPos( playerid,
        pos[0] + 2.0 * floatcos( sideAngle, degrees ),
        pos[1] + 2.0 * floatsin( sideAngle, degrees ),
        pos[2] + 0.3 );

    SetPlayerFacingAngle( playerid, pos[3] );
    return 1;
}

stock IsEvenNumber(number)
{   //узнаем, четное число или нет.
	if(number % 2 == 0) return 1;
	return 0;
}

stock Freeze(playerid, value)
{
	switch(value)
	{
		case 0:ApplyAnimation(playerid,"GYMNASIUM","Pedals_fast",4.1,0,1,1,1,value);
		case 1:ApplyAnimation(playerid,"GYMNASIUM","Pedals_fast",4.1,0,1,1,1,value);
	}
	return 1;
}

//CCreateThread(function_name[], dealy = 0, repeat = 0);
//function_name[] - название любого колбека в моде.
//dealy - время между повторениями вызова, в милисикундах
//repeat - потворять или нет

stock ReturnPreviousID(playerid,fromid)
{
	new tmp, tmp2;
	for(new i = fromid; i < GetMaxPlayers(); i--)
	{
		if(IsPlayerConnected(i) && i != playerid)
		{
			if(tmp == 0)
			{
				tmp = 1;
				tmp2 = i;
			}
		}
	}
	return tmp2;//Возвращает предыдущий ID.
}
stock ReturnNextID(playerid,fromid)
{
	new tmp, tmp2;
	for(new i = fromid; i < GetMaxPlayers(); i++)
	{
		if(IsPlayerConnected(i) && i != playerid)
		{
			if(tmp == 0)
			{
				tmp = 1;
				tmp2 = i;
			}
		}
	}
	return tmp2;//Возвращает следующий ID
}

stock GetHighestID(playerid)
{
	new tmp, tmp2;
	for(new i = GetMaxPlayers(); i >= 0; i--)
	{
		if(IsPlayerConnected(i) && PlayerSpawned[i] == 1 && i != playerid)
		{
			if(tmp == 0)
			{
				tmp = 1;
				tmp2 = i;
			}
		}
	}
	return tmp2;//самый большой ID на сервере.
}

stock GetLowestID(playerid)
{
	new tmp, tmp2;
	for(new i = 0; i < GetMaxPlayers(); i++)
	{
		if(IsPlayerConnected(i) && PlayerSpawned[i] == 1 && i != playerid)
		{
			if(tmp == 0)
			{
				tmp = 1;
				tmp2 = i;
			}
		}
	}
	return tmp2;//самый маленький ID на сервере.
}

stock IsVehicleConnected(vehicleid)
{
	new Float,Float:y,Float:z;
	GetVehiclePos(vehicleid,x,y,z);
	if(x == 0.0 && y == 0.0 && z == 0.0)
	{
		return 0;
	}
	return 1;//существует ли машина на сервере
}

stock CountServerVehicles()
{
	new c = 0;
	for(new i = 0; i < MAX_VEHICLES; i++)
	{
		if(IsVehicleConnected(i))
		{
			c++;//Считаем сколько машин на сервере
		}
	}
	return c;
}

stock CheckFireArm(weaponid)
{
	if(weaponid >= 22 && weaponid <= 39) return 1;
	return 0;
}
stock CheckValidWeapon(weaponid)
{
	if(weaponid > 0 && weaponid < 19 || weaponid > 21 && weaponid < 47) return 1;
	return 0;
}
stock IsCbugWeapon(playerid)
{
    new weaponID = GetPlayerWeapon(playerid);
    if(weaponID == 22 || weaponID == 24 || weaponID == 25 || weaponID == 27)
	{
    	return 1;
	}
    return 0;
}
stock AutoParachute(playerid)//ParachuteCheck()
{
    new Float:z;
	if(!IsPlayerInAnyVehicle(playerid))
	{
		GetPlayerVelocity(playerid,z,z,z);
		if(z < -0.7) GivePlayerWeaponEx(playerid,46,1);
	}
}
stock GetWeaponSlot(weaponid)
{
	if(weaponid == 0 || weaponid == 1) return 0;
	else if(2 <= weaponid <= 9) return 1;
	else if(22 <= weaponid <= 24) return 2;
	else if(25 <= weaponid <= 27) return 3;
	else if(weaponid == 28 || weaponid == 29 || weaponid == 32) return 4;
	else if(weaponid == 30 || weaponid == 31) return 5;
	else if(weaponid == 33 || weaponid == 34) return 6;
	else if(35 <= weaponid <= 38) return 7;
	else if(16 <= weaponid <= 18 || weaponid == 39) return 8;
	else if(41 <= weaponid <= 43) return 9;
	else if(10 <= weaponid <= 15) return 10;
	else if(44 <= weaponid <= 46) return 11;
	else if(weaponid == 40) return 12;
	else return 0;
}

stock IsPlayerBehindPlayer(playerid, targetid, Float:dOffset)
{
	new Float:pa, Float:ta;
	if(!IsPlayerConnected(playerid) || !IsPlayerConnected(targetid)) return 0;

	GetPlayerFacingAngle(playerid, pa);
	GetPlayerFacingAngle(targetid, ta);

	if(AngleInRangeOfAngle(pa, ta, dOffset) && IsPlayerFacingPlayer(playerid, targetid, dOffset)) return true;
	return false;
}

stock SetPlayerToFacePlayer(playerid, targetid)
{
	new
		Float:pX,
		Float:pY,
		Float:pZ,
		Float:X,
		Float:Y,
		Float:Z,
		Float:ang;

	if(!IsPlayerConnected(playerid) || !IsPlayerConnected(targetid)) return 0;

	GetPlayerPos(targetid, X, Y, Z);
	GetPlayerPos(playerid, pX, pY, pZ);

	if( Y > pY ) ang = (-acos((X - pX) / floatsqroot((X - pX)*(X - pX) + (Y - pY)*(Y - pY))) - 90.0);
	else if( Y < pY && X < pX ) ang = (acos((X - pX) / floatsqroot((X - pX)*(X - pX) + (Y - pY)*(Y - pY))) - 450.0);
	else if( Y < pY ) ang = (acos((X - pX) / floatsqroot((X - pX)*(X - pX) + (Y - pY)*(Y - pY))) - 90.0);

	if(X > pX) ang = (floatabs(floatabs(ang) + 180.0));
	else ang = (floatabs(ang) - 180.0);

	SetPlayerFacingAngle(playerid, ang);
	return 0;
}
stock IsPlayerFacingPlayer(playerid, targetid, Float:dOffset)
{
	new	Float:pX, Float:pY,	Float:pZ,	Float:pA,
		Float:X, Float:Y, Float:Z, Float:ang;

	if(!IsPlayerConnected(playerid) || !IsPlayerConnected(targetid)) return 0;

	GetPlayerPos(targetid, pX, pY, pZ);
	GetPlayerPos(playerid, X, Y, Z);
	GetPlayerFacingAngle(playerid, pA);

	if( Y > pY ) ang = (-acos((X - pX) / floatsqroot((X - pX)*(X - pX) + (Y - pY)*(Y - pY))) - 90.0);
	else if( Y < pY && X < pX ) ang = (acos((X - pX) / floatsqroot((X - pX)*(X - pX) + (Y - pY)*(Y - pY))) - 450.0);
	else if( Y < pY ) ang = (acos((X - pX) / floatsqroot((X - pX)*(X - pX) + (Y - pY)*(Y - pY))) - 90.0);

	if(AngleInRangeOfAngle(-ang, pA, dOffset)) return true;
	return false;
}

stock AngleInRangeOfAngle(Float:a1, Float:a2, Float:range)
{
	a1 -= a2;
	if((a1 < range) && (a1 > -range)) return true;
	return false;
}
/*stock Float:AngleBetweenPoints(Float:fX1, Float:fY1, Float:fX2, Float:fY2)
{
	new Float:angle = atan2(fY1 - fY2, fX1 - fX2) * 180.0 / 3.14;
	return angle;
}*/
//##############################################################################//
//                                                                              //
//                         ФУНКЦИИ ДЛЯ РАБОТЫ С ТЕКСТОМ                         //
//                                                                              //
//##############################################################################//
stock ini_GetKey( line[] )//вызывается из ф-ии PlayerLogin
{   //возвращает значение до разделителя "=" во входной строке line
	new keyRes[256];
	keyRes[0] = 0;
    if ( strfind(line, "=", true) == -1 ) return keyRes;
    strmid( keyRes, line, 0, strfind(line, "=", true), sizeof( keyRes) );
    return keyRes;
}
stock ini_GetValue( line[] )//вызывается из ф-ии PlayerLogin
{	//возвращает значение после разделителя "=" во входной строке line
	new valRes[256];
	valRes[0] = 0;
	if ( strfind( line , "=" , true ) == -1 ) return valRes;
	strmid( valRes, line, strfind(line, "=", true)+1 , strlen( line ) , sizeof( valRes ) );
	return valRes;
}

stock strtok(const string[], &index)//Сканирует строку на наличие символа 'пробел'
//и возвращает аргумент номер которого указан в переменной (&index).
//Применяется в основном для команд, чтобы чтобы получать параметры после пробела.
//string[] - Строка, которую нужно разделить.
//&index - Номер аргумента который вы хотите вернуть.
//Возвращает  аргумент номер которого указан в в переменной &index
//stock - блоком автозамен, жрет меньше памяти
//stock - выполняется только в пределах массива
//stock - это функция компилятора, т.е. при компиляции все функции stock, а точнее в места где вы их прописали вписывается код который в них объявлен.
//public - аппаратная функция, т.е. она компилируеться как отдельный скрипт, а в места где вы её вызываете вписываеться адрес где находиться public в памяти,
//forward - это так сказать адресная книга которая при начале обработки срипта указывает адреса на ваш public
{
   new length = strlen(string);//записали длину полученной входной строки
   while ((index < length) && (string[index] <= ' '))   index++;//подсчитали сколько символов до пробела
   //если позиция символа < длины строки и позиции символа находится до пробела, то перейти на следующий
   new offset = index;//записать позицию пробела
   new result[20];//20 объявляем новую символьную переменную с размерностью 20
   while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
   {	//покуда позиция символа меньше длины строки и символы находится за пробелом
		// и разница между позицие символа и позицией пробела < меньше покуда размера строки result, т.е. меньше 20 в данном случаи
		result[index - offset] = string[index];//записали символ в ячейку со смещением на величину позиции пробела, тем самым сформировав строку после пробела
		index++;//перешли на следующий символ
   }
   result[index - offset] = EOS;//обнулили данные в строке result начиная с позиции последнего записанного символа
   return result;//возвращаем строку из символов начиная от указаной позиции до пробела
}
stock strtoko(const string[], &index, seperator=' ')
{
	new length = strlen(string);//записали длину полученной входной строки
	new offset = index;//записать позицию пробела
	new result[128];//объявляем новую символьную переменную с размерностью 256
	while(  (index < length) && (string[index] != seperator) &&
			( (index - offset) < (sizeof(result) - 1)      )
	     )
	{   //покуда позиция символа меньше длины строки и символ не равен разделителю
		// и разница между позицие символа и позицией пробела < меньше размера строки result, т.е. меньше 256 в данном случаи
		result[index - offset] = string[index];//записали символ в ячейку со смещением на величину позиции пробела, тем самым сформировав строку после разделителя
		index++;//перешли на следующий символ
	}
	result[index - offset] = EOS;////обнулили данные в строке result начиная с позиции последнего записанного символа
	if ((index < length) && (string[index] == seperator))
	{   //если позиция символа < длины строки и строка равна разделителю
		index++;//подсчитали сколько символов до пробела
	}
	return result;//возвращаем строку из символов начиная от указаной позиции до пробела
}
//Возвращает элемент строки разделенной ' ', встроенный индекс - 0.
/*stock strtoko(const string[], &index, separator)
{   //для загрузки настроек
	new length = strlen(string);
	while ((index < length) && (string[index] <= separator)) index++;
	new offset = index;
	new result[256];//64//20
	while ((index < length) && (string[index] > separator) && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];	index++;
	}
	result[index - offset] = EOS;
	return result;
}*/
//Проверяет две строки как эквивалентые (с проверкой на регистр)
stock equal(str1[], str2[], bool:ignorecase)
{
    if (strlen(str1) != strlen(str2)) return false;
    if (strcmp(str1, str2, ignorecase) == 0) return true;
    return false;
}

// Tokenise by a delimiter
// Return string and index of the end determined by the provided delimiter in delim
stock token_by_delim(const string[], return_str[], delim, start_index)
{   //string[] - откуда считываем //return_str[] - куда заносим
	new x = 0;
	while(string[start_index] != EOS && string[start_index] != delim)
	{
	    return_str[x] = string[start_index];
	    x++;
	    start_index++;
	}
	return_str[x] = EOS;
	if(string[start_index] == EOS) start_index = (-1);
	return start_index;
}
//КРАШ СЕРВА
stock split(const strsrc[], strdest[][], delimiter)
{   //разделяет первый параметр на части и заносит их во второй параметр массив
	new i, li;
	new aNum;
	new len;
	while(i <= strlen(strsrc))//strcmp("male", tmp, true, strlen(tmp)
	{   //пока i <= длины строки strsrc
	    if(strsrc[i]==delimiter || i==strlen(strsrc))
		{   //если значение strsrc[i] == '/' или  i == длине строки strsrc
	        len = strmid(strdest[aNum], strsrc, li, i, 128);//Извлекает диапазон символов из строки.
			//li - Позиция первого символа, i - Позиция последнего символа, 128 - Максимальная длина строки-назначения для копирования.
	        //записать в strdest[aNum] значение strsrc
	        strdest[aNum][len] = 0;
	        li = i+1;//
	        aNum++;//обычный счётчик
		}
		i++;
	}
	return 1;
}
//------------------------------------------------------------------------------
stock strrest(const string[], &index)
{   //string[] - Строка, длину которой вы хотите знать в виде целого числа.
	new length = strlen(string);//Эта функция может быть использована для проверки длины указанной строки.
	while ((index < length) && (string[index] <= ' '))
	{
		index++;//Номер позиции пробела
	}
	new offset = index;//записываем позицию пробела в полученной строке
	new result[128];
	while ((index < length) && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];//в переменную result записать символы с позиции после пробела
		index++;
	}
	result[index - offset] = EOS;//обнулили данные в строке result начиная с позиции последнего записанного символа
	return result;
}
// Returns a string which has 'newstr' where 'trg' was before
stock strreplace(trg[],newstr[],src[])
{
    new f=0;
    new s1[MAX_STRING];
    new string[MAX_STRING];
    format(s1, sizeof(s1), "%s", src);
    f = strfind(s1, trg);
    tmp[0] = 0;
    while(f >= 0)
	{
        strcat(string, ret_memcpy(s1, 0, f));
        strcat(string, newstr);
        format(s1, sizeof(s1), "%s", ret_memcpy(s1, f+strlen(trg), strlen(s1)-f));
        f = strfind(s1,trg);
    }
    strcat(string,s1);
    return string;
}

//Возвращает строку с нижним регистром
stock strlower(txt[])
{
	new string[MAX_STRING];
	string[0]=0;
	if (txt[0]==0) return string;
	new i=0;
	for (i=0;i<strlen(txt);i++)
	{
		string[i]=tolower(txt[i]);
	}
	string[strlen(txt)]=0;
	return string;
}

//Возвращает строку с верхним регистром
stock strupper(txt[])
{
	new string[MAX_STRING];
	string[0]=0;
	if (txt[0]==0) return string;
	new i=0;
	for (i=0;i<strlen(txt);i++)
	{
		string[i]=toupper(txt[i]);
	}
	string[strlen(txt)]=0;
	return string;
}
stock strfind2(source[], findtext[], pos = 0)
{   //более опитмизированный
//т.к. учтено что strfind начинает каждый раз перебирать не с начала,
// а с символа идущего после последнего найденного пробела?
	new n;
	for(new i = pos;i < strlen2(source);i++)
	{
		for(new m;m < strlen2(findtext);m++)
		{
			if (source[i+m] == findtext[m] && n < strlen2(findtext)) n++;
			if (n == strlen2(findtext)) return i;
		}
		n=0;
	}
	return -1;
}
stock substr_count(substring[], string[])
{   //поиск подсторки substring в строке string
	new tmpcount;
    for( new i=0; i < strlen(string); i++)
    {
		if( strfind(string[i], substring, true) )
		{
		    tmpcount++;
		}
    }
    return tmpcount;
}

/*
Usage
printf("%s", replaceChar("hi i'm just testing my function", ' ', '+'));
This will output:
hi+i'm+just+testing+my+function
*/
/*replaceChar(string[128], findchar, replacechar)
{
    for(new i; string[i]; ++i)
    {
        if(string[i] == findchar) string[i] = replacechar;
    }
    return string;
}*/
//Better:
stock replaceChar(string[128], findchar, replacechar)
{
	new i = 0;
	while (string[i])
    {
		if (string[i] == findchar) string[i] = replacechar;
		++i;
	}
	// Don't really need this as it modifies the string passed to the function.
	return string;
}

/*Example:
new str[128] = "This is a facked string to censore!";
print(str);
replacestring(str,"facked","[censored]");
print(str); */
stock replacestring(str[], const find[],const finish[])
{
	#define MAXLEN 128
	new start = strfind(str,find);
	do
	{
		new end = start+strlen(find);
		strdel(str,start,end);
		strins(str,finish,start,MAXLEN);
		start = strfind(str,find);
	} while(start != -1);
	return str;
}

stock RusToGame(string[])
{
	new result[256];
	for(new i=0; i < 256; i++)
	{
		switch(string[i])
		{
			case 'а':result[i] = 'a';
			case 'А':result[i] = 'A';
			case 'б':result[i] = '—';
			case 'Б':result[i] = 'Ђ';
			case 'в':result[i] = 'ў';
			case 'В':result[i] = '‹';
			case 'г':result[i] = '™';
			case 'Г':result[i] = '‚';
			case 'д':result[i] = 'љ';
			case 'Д':result[i] = 'ѓ';
			case 'е':result[i] = 'e';
			case 'Е':result[i] = 'E';
			case 'ё':result[i] = 'e';
			case 'Ё':result[i] = 'E';
			case 'ж':result[i] = '›';
			case 'Ж':result[i] = '„';
			case 'з':result[i] = 'џ';
			case 'З':result[i] = '€';
			case 'и':result[i] = 'њ';
			case 'И':result[i] = '…';
			case 'й':result[i] = 'ќ';
			case 'Й':result[i] = '…';
			case 'к':result[i] = 'k';
			case 'К':result[i] = 'K';
			case 'л':result[i] = 'ћ';
			case 'Л':result[i] = '‡';
			case 'м':result[i] = 'Ї';
			case 'М':result[i] = 'M';
			case 'н':result[i] = '®';
			case 'Н':result[i] = '­';
			case 'о':result[i] = 'o';
			case 'О':result[i] = 'O';
			case 'п':result[i] = 'Ј';
			case 'П':result[i] = 'Њ';
			case 'р':result[i] = 'p';
			case 'Р':result[i] = 'P';
			case 'с':result[i] = 'c';
			case 'С':result[i] = 'C';
			case 'т':result[i] = '¦';
			case 'Т':result[i] = 'Џ';
			case 'у':result[i] = 'y';
			case 'У':result[i] = 'Y';
			case 'ф':result[i] = '';
			case 'Ф':result[i] = 'Ѓ';
			case 'х':result[i] = 'x';
			case 'Х':result[i] = 'X';
			case 'ц':result[i] = ' ';
			case 'Ц':result[i] = '‰';
			case 'ч':result[i] = '¤';
			case 'Ч':result[i] = 'Ќ';
			case 'ш':result[i] = 'Ґ';
			case 'Ш':result[i] = 'Ћ';
			case 'щ':result[i] = 'Ў';
			case 'Щ':result[i] = 'Љ';
			case 'ь':result[i] = '©';
			case 'Ь':result[i] = '’';
			case 'ъ':result[i] = 'ђ';
			case 'Ъ':result[i] = '§';
			case 'ы':result[i] = 'Ё';
			case 'Ы':result[i] = '‘';
			case 'э':result[i] = 'Є';
			case 'Э':result[i] = '“';
			case 'ю':result[i] = '«';
			case 'Ю':result[i] = '”';
			case 'я':result[i] = '¬';
			case 'Я':result[i] = '•';
			default:result[i] = string[i];
		}
	}
	return result;
}
stock ColorToHex(r,g,b,a)
{
	return((r & 0xff) << 24) | ((g & 0xff) << 16) | ((b & 0xff) << 8) | (a & 0xff);
}
stock HexToString(color)
{
	new colorhex[256];
	format(colorhex,sizeof(colorhex),"%02x%06x", color >>> 24, color & 0x00FFFFFF);
	return colorhex;
}
stock HexToInt(string[])//для конвертирования 16-ричного кода в целое
{   //Since the colors are just numbers you have to convert them sometimes from a string "RRGGBBAA" to its number.
	if(string[0] == 0) return 0;
	new i;
	new cur = 1;
	new res = 0;
	for (i = strlen(string); i > 0; i--)
	{
		if(string[i-1] < 58) res = res + cur*(string[i-1]-48);
		else res = res+cur*(string[i-1]-65+10);
		cur = cur*16;
	}
	return res;
}
stock IntToHex(number)
{
	new m=1;
	new depth=0;
	while (number>=m) {
		m = m*16;
		depth++;
	}
	depth--;
	new str[MAX_STRING];
	for (new i = depth; i >= 0; i--)
	{
		str[i] = ( number & 0x0F) + 0x30; // + (tmp > 9 ? 0x07 : 0x00)
		str[i] += (str[i] > '9') ? 0x07 : 0x00;
		number >>= 4;
	}
	str[8] = '\0';
	return str;
}
stock StrToInt(string[])
{
	return strval(string);
}
stock IntToStr(value)
{
	new string[MAX_STRING];
	valstr(string, value);
	return string;
}

/**
 *  Копирует файл (файл Источника не будет удален!)
 *  @param   oldname
 *           newname
 *  @requires WINDOWS
 */
stock fcopy(oldname[],newname[])
{
	new File:ohnd,File:nhnd;
	if (!fexist(oldname)) return false;
	ohnd = fopen(oldname,io_read);
	nhnd = fopen(newname,io_write);
	new buf2[1];
	new i;
	for (i=flength(ohnd);i>0;i--)
	{
		fputchar(nhnd, fgetchar(ohnd, buf2[0],false),false);
	}
	fclose(ohnd);
	fclose(nhnd);
	return true;
}
/**
 *  Копирует текстовый файл (файл Источника не будет удален!)
 *  @param   oldname
 *           newname
 */
stock fcopytextfile(oldname[],newname[]) {
	new File:ohnd,File:nhnd;
	if (!fexist(oldname)) return false;
	ohnd=fopen(oldname,io_read);
	nhnd=fopen(newname,io_write);
	new tmpres[MAX_STRING];
	while (fread(ohnd,tmpres)) {
		StripNewLine(tmpres);
		format(tmpres,sizeof(tmpres),"%s\r\n",tmpres);
		fwrite(nhnd,tmpres);
	}
	fclose(ohnd);
	fclose(nhnd);
	return true;
}
/**
 *  Переименовывает файл (файл Источника будет удален!)
 *  @param   oldname
 *           newname
 *  @requires WINDOWS (because fcopy does)
 */
//bool: frename(const oldname[], const newname[])         Rename or move a file
/*stock frename(oldname[], newname[])
{
    if (!fexist(oldname)) return false;
    fremove(newname);
    if (!fcopy(oldname,newname)) return false;
    fremove(oldname);
    return true;
}*/
stock bool:frename(const oldname[], const newname[])
{
    new File:oldfile = fopen(oldname, io_read);
    if(oldfile)
	{
        new File:newfile = fopen(newname, io_write);
        if(newfile)
		{
            new buffer[1024];
            while(fblockread(oldfile, buffer) != 0)
			{
                fblockwrite(newfile, buffer);
            }
            fclose(oldfile);
            fremove(oldname);
            fclose(newfile);
            return true;
        }
        fclose(oldfile);
    }
    return false;
}

//Переименовывает файл (файл Источника будет удален!)
stock frenametextfile(oldname[],newname[]) {
    if (!fexist(oldname)) return false;
    fremove(newname);
    if (!fcopytextfile(oldname,newname)) return false;
    fremove(oldname);
    return true;
}
//Копирует записи из одного массива в другой
//index (where to start, 0 is first)
//numbytes (how much)
stock ret_memcpy(source[], index=0, numbytes)
{
	new string[MAX_STRING];
	new i=0;
	string[0]=0;
	if(index >= strlen(source)) return string;
	if(numbytes+index >= strlen(source)) numbytes=strlen(source)-index;
	if(numbytes <= 0) return string;
	for (i=index; i<numbytes+index; i++)
	{
		string[i-index]=source[i];
		if (source[i]==0) return string;
	}
	string[numbytes] = 0;
	return string;
}

stock utf_decode(string[])
{
   new string[50],id,i;
   while(i < strlen(string))
   {
       if(string[i] < 128)
       {
			string[id++] = string[i];
			i++;
       }
       else if((string[i] > 191) && (string[i] < 224))
       {
            string[id++] = ((string[i] & 31) << 6) | (string[i+1] & 63);
            i+=2;
       }
       else
       {
			string[id++] = ((string[i] & 15) << 12) | ((string[i+1] & 63) << 6) | (string[i+2] & 63);
			i+=3;
       }
   }
   return string;
}
//#define DisableBadword(%1) for(new i=0; i<strlen(text); i++) if(strfind(text[i], %1, true) == 0) for(new a=0; a<256; a++) if(a >= i && a < i+strlen(%1)) text[a]='*'


//##############################################################################//
//                                                                              //
//                           НЕСТАНДАРТНЫЕ ДЕКЛАРАЦИИ                           //
//                                                                              //
//##############################################################################//
// Return if a Email is valid or not// *  @param   value
stock ValidEmail(email[])
{
	new len = strlen(email);
	new cstate = 0;
	new i;
	for(new i=0; i<len; i++)
	{
		if( (cstate==0 || cstate==1) &&
			(email[i]>='A' && email[i]<='Z') ||
			(email[i]>='a' && email[i]<='z') ||
			(email[i]=='.') || (email[i]=='-') ||
			(email[i]=='_'))
		{
		    //...
		}
		else
		{
			// Ok no A..Z,a..z,_,.,-
			if ((cstate == 0) && (email[i] == '@'))
			{
				// its an @ after the name, ok state=1;
          		cstate = 1;
			}
			else
			{
				// Its stuff which is not allowed
				return false;
			}
		}
	}
	if(cstate < 1) return false;
	if(len < 6) return false;
	// A toplevel domain has only 3 to 4 signs :-)
	if((email[len-3]=='.') || (email[len-4]=='.') || (email[len-5]=='.')) return true;
	return false;
}
//            North (0°)
//              //
//West (270°) <-|-> East (90°)
//             //
//            South (180°)
stock bool:SetPlayerForwardVelocity(playerid, Float:Velocity, Float:Z)
{
	if(!IsPlayerConnected(playerid)) return false;
	new Float:Angle;
	new Float:SpeedX, Float:SpeedY;
	GetPlayerFacingAngle(playerid, Angle);
	SpeedX = floatsin(-Angle, degrees);
	SpeedY = floatcos(-Angle, degrees);
	SetPlayerVelocity(playerid, floatmul(Velocity, SpeedX), floatmul(Velocity, SpeedY), Z);
	return true;
}
//            North (0°)
//              //
//West (270°) <-|-> East (90°)
//             //
//            South (180°)
stock bool:SetVehicleForwardVelocity(vehicleid, Float:Velocity, Float:Z)
{
	new Float:Angle;
	new Float:SpeedX, Float:SpeedY;
	GetVehicleZAngle(vehicleid, Angle);
	SpeedX = floatsin(-Angle, degrees);
	SpeedY = floatcos(-Angle, degrees);
	SetVehicleVelocity(vehicleid, floatmul(Velocity, SpeedX), floatmul(Velocity, SpeedY), Z);
	return true;
}
stock ConvertNormaQuatToEuler(Float: qw, Float: qx, Float:qy, Float:qz,
								&Float:heading, &Float:attitude, &Float:bank)
{
	new Float: test = qx*qy + qz*qw;
	if (test > 0.499)
	{ // singularity at north pole - особенность на северном полюсе
		heading = 2 * atan2(qx,qw);
		attitude = 3.141592653/2;
		bank = 0;
		return 1;
	}
	if (test < -0.499)
	{ // singularity at south pole - особенность на южном полюсе
		heading = -2 * atan2(qx,qw);
		attitude = - 3.141592653/2;
		bank = 0;
		return 1;
	}
    new Float: sqx = qx*qx;
    new Float: sqy = qy*qy;
    new Float: sqz = qz*qz;
    heading = atan2(2*qy*qw-2*qx*qz, 1 - 2*sqy - 2*sqz);
	attitude = asin(2*test);
	bank = atan2(2*qx*qw-2*qy*qz, 1 - 2*sqx - 2*sqz);
	return 1;
}
stock ConvertNonNormaQuatToEuler(Float: qw, Float: qx, Float:qy, Float:qz,
								&Float:heading, &Float:attitude, &Float:bank)
{
    new Float: sqw = qw*qw;
    new Float: sqx = qx*qx;
    new Float: sqy = qy*qy;
    new Float: sqz = qz*qz;
	new Float: unit = sqx + sqy + sqz + sqw; // if normalised is one, otherwise is correction factor
	//если normalised, - один, в противном случае - показатель коррекции
	new Float: test = qx*qy + qz*qw;
	if (test > 0.499*unit)
	{ // singularity at north pole - особенность на северном полюсе
		heading = 2*atan2(qx,qw);
		attitude = 3.141592653/2;
		bank = 0;
		return 1;
	}
	if (test < -0.499*unit)
	{ // singularity at south pole - особенность на южном полюсе
		heading = -2*atan2(qx,qw);
		attitude = -3.141592653/2;
		bank = 0;
		return 1;
	}
    heading = atan2(2*qy*qw - 2*qx*qz, sqx - sqy - sqz + sqw);
	attitude = asin(2*test/unit);
	bank = atan2(2*qx*qw - 2*qy*qz, -sqx + sqy - sqz + sqw);
	return 1;
}

stock GetVehicleRotation(vehicleid,&Float:heading, &Float:attitude, &Float:bank)
{
    new Float:quat_w,Float:quat_x,Float:quat_y,Float:quat_z;
    GetVehicleRotationQuat(vehicleid,quat_w,quat_x,quat_y,quat_z);
    /*heading = atan2(2*((quat_x*quat_y)+(quat_w+quat_z)),(quat_w*quat_w)+(quat_x*quat_x)-(quat_y*quat_y)-(quat_z*quat_z));
    attitude = asin(-2*((quat_x*quat_z)+(quat_w*quat_y)));
    bank = atan2(2*((quat_y*quat_z)+(quat_w*quat_x)),(quat_w*quat_w)-(quat_x*quat_x)-(quat_y*quat_y)+(quat_z*quat_z));*/
	//ConvertNormaQuatToEuler(quat_w,quat_x,quat_z,quat_y, heading, attitude, bank);
	ConvertNonNormaQuatToEuler(quat_w,quat_x,quat_z,quat_y, heading, attitude, bank);
	//attitude = -1*bank;
	bank = -1*bank;
	//ИНФОРМИРОВАНИЕ
	//new string[MAX_STRING];
	//new Float:angle;
	//GetVehicleZAngle(vehicleid, angle);
	//format(string, sizeof(string), "GetVehicleRotation(quat_w:%.2f, quat_x:%.2f, quat_y:%.2f, quat_z:%.2f, рыскание:%.1f, крен:%.1f, тангаж:%.1f(angle:%.1f))", quat_w,quat_x,quat_z,quat_y, heading, attitude, bank, angle);
	//ABroadCast(COLOR_GREEN, string, 1);
	//SendClientMessageToAll(COLOR_YELLOW, string);
    return 1;
}

stock RandomGenerator(amount, letterstr[])
{
	new charset[63] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	for(new i = 0; i < amount; i++)
	{
	    letterstr[i] = charset[Random(0,62)];
	}
	return 1;
}
stock Random(min, max)
{
	new a = random(max - min) + min;
	return a;
}
stock GetPlayerCameraLookAt(playerid, &Float:X, &Float:Y, &Float:Z)
{   //возвращает координаты точки наблюдения
	new	Float:Dis,
		Float:CamX, Float:CamY, Float:CamZ,
		Float:ObjX, Float:ObjY, Float:ObjZ,
		Float:FrX, Float:FrY, Float:FrZ;

	GetPlayerCameraPos(playerid, CamX, CamY, CamZ);
	GetPlayerPos(playerid, ObjX, ObjY, ObjZ);
	GetPlayerCameraFrontVector(playerid, FrX, FrY, FrZ);
	ObjX += 5.0 * floatsin(-GetAngleToPoint(CamX, CamY, ObjX, ObjY), degrees);
	ObjY += 5.0 * floatcos(-GetAngleToPoint(CamX, CamY, ObjX, ObjY), degrees);
	Dis = floatsqroot((CamX - ObjX) * (CamX - ObjX) + (CamY - ObjY) * (CamY - ObjY) + (CamZ - ObjZ) * (CamZ - ObjZ));
	X = FrX * Dis + CamX;
	Y = FrY * Dis + CamY;
	Z = FrZ * Dis + CamZ;
}
stock IsPlayerLookingAtPlayer(player1, player2)
{   //возварщает верно (1) если игрок player2 находится в поле зрения игрока player1
	// @player1 : The playerid of the player who is looking at someone.
	//playerid Игрока, который смотрит на кого-нибудь.
	// @player2 : The playerid of the player who is being seen.
	//playerid Игрока, который увиден.
	if (!IsPlayerConnected(player1) || !IsPlayerConnected(player2) || player1 == player2)	return 0;

	new
	Float: distance,
	Float: vectorX,
	Float: vectorY,
	Float: vectorZ,
	Float: plyrPos[2][3],
	Float: projPos[3];

	GetPlayerCameraFrontVector(player1, vectorX, vectorY, vectorZ);
	GetPlayerCameraPos(player1, plyrPos[0][0], plyrPos[0][1], plyrPos[0][2]);

	GetPlayerPos(player2, plyrPos[1][0], plyrPos[1][1], plyrPos[1][2]);

	#define SQUARE(%1)  ((%1)*(%1))
	// Looks like we need distance, damnit! This is the 3D distance since we are working in a 3D space.
	distance = floatsqroot(SQUARE(plyrPos[1][0]-plyrPos[0][0]) + SQUARE(plyrPos[1][1]-plyrPos[0][1]) + SQUARE(plyrPos[1][2]-plyrPos[0][2])	);

	projPos[0] = plyrPos[0][0] + vectorX * distance;
	projPos[1] = plyrPos[0][1] + vectorY * distance;
	projPos[2] = plyrPos[0][2] + vectorZ * distance;

	return 	(
				(	SQUARE(plyrPos[1][0]-projPos[0]) +
					SQUARE(plyrPos[1][1]-projPos[1]) +
					SQUARE(plyrPos[1][2]-projPos[2])
				) <= SQUARE(distance / 6)
			);
// Is the projected position within a virtual sphere around player2?
	#undef SQUARE
}

stock DeGetTime(date, bool:type)
{
   new string[128];
   new year,month,day,hour,minute,second,Float:temp;
   year = date - 1230746400;
   temp = floatabs(year/60.0);
   second = year - floatround(temp,floatround_floor)*60;
   minute = floatround(temp,floatround_floor);
   temp = floatabs(temp/60.0);
   minute -= floatround(temp,floatround_floor)*60;
   hour = floatround(temp,floatround_floor);
   temp = floatabs(temp/24.0);
   hour -= floatround(temp,floatround_floor)*24;
   day = floatround(temp,floatround_floor);
   new string = 0,string1 = 2009;
   while(string <= day)
   {
       if(floatfract(string1/4.0) == 0.0) string += 366;//floatfract - Вычисляет и возвращяет дробную часть вещественного числа.
       else string += 365;
       string1++;
   }
   year = string1-1;
   if(floatfract(year/4.0) == 0.0) string -= 366;
   else string -= 365;
   day -= string;
   string = 0; string1 = 0;
   while(string <= day)
   {
       switch(string1)
       {
           case 0:string +=31;
           case 1:
           {
               if(floatfract(year/4.0) == 0.0) string += 29;
               else string += 28;
           }
           case 2:string += 31;
           case 3:string += 30;
           case 4:string += 31;
           case 5:string += 30;
           case 6:string += 31;
           case 7:string += 31;
           case 8:string += 30;
           case 9:string += 31;
           case 10:string += 30;
           case 11:string += 31;
       }
       string1++;
   }
   month = string1;
   switch(month)
   {
      case 1:day = 31 - (string - day);
      case 2:
      {
         if(floatfract(year/4.0) == 0.0)day = 29 - (string - day);
         else day = 28 - (string - day);
      }
      case 3:day = 31 - (string - day);
      case 4:day = 30 - (string - day);
      case 5:day = 31 - (string - day);
      case 6:day = 30 - (string - day);
      case 7:day = 31 - (string - day);
      case 8:day = 31 - (string - day);
      case 9:day = 30 - (string - day);
      case 10:day = 31 - (string - day);
      case 11:day = 30 - (string - day);
      case 12:day = 31 - (string - day);
   }
   day++;
   if(type)
   {
      switch(month)
      {
         case 1:format(string, sizeof(string),"%0*d january %0*d %0*d:%0*d:%0*d",2,day,4,year,2,hour,2,minute,2,second);
         case 2:format(string, sizeof(string),"%0*d february %0*d %0*d:%0*d:%0*d",2,day,4,year,2,hour,2,minute,2,second);
         case 3:format(string, sizeof(string),"%0*d march %0*d %0*d:%0*d:%0*d",2,day,4,year,2,hour,2,minute,2,second);
         case 4:format(string, sizeof(string),"%0*d april %0*d %0*d:%0*d:%0*d",2,day,4,year,2,hour,2,minute,2,second);
         case 5:format(string, sizeof(string),"%0*d may %0*d %0*d:%0*d:%0*d",2,day,4,year,2,hour,2,minute,2,second);
         case 6:format(string, sizeof(string),"%0*d june %0*d %0*d:%0*d:%0*d",2,day,4,year,2,hour,2,minute,2,second);
         case 7:format(string, sizeof(string),"%0*d july %0*d %0*d:%0*d:%0*d",2,day,4,year,2,hour,2,minute,2,second);
         case 8:format(string, sizeof(string),"%0*d august %0*d %0*d:%0*d:%0*d",2,day,4,year,2,hour,2,minute,2,second);
         case 9:format(string, sizeof(string),"%0*d september %0*d %0*d:%0*d:%0*d",2,day,4,year,2,hour,2,minute,2,second);
         case 10:format(string, sizeof(string),"%0*d october %0*d %0*d:%0*d:%0*d",2,day,4,year,2,hour,2,minute,2,second);
         case 11:format(string, sizeof(string),"%0*d november %0*d %0*d:%0*d:%0*d",2,day,4,year,2,hour,2,minute,2,second);
         case 12:format(string, sizeof(string),"%0*d december %0*d %0*d:%0*d:%0*d",2,day,4,year,2,hour,2,minute,2,second);
      }
   }
   else format(string, sizeof(string),"%0*d.%0*d.%0*d %0*d:%0*d:%0*d",2,day,2,month,4,year,2,hour,2,minute,2,second);
   return string;
}/*Где это можно применить. Думаю у всех была проблема, сохранений даты бана и даты разбана, дак вот теперь это проще некуда и не нужно никаких таймеров:
бан на время
затычка на время
дата регистрации
при бане записываем в фаил new databana = gettime();
и срок бана в минутах new srokbana = 10080;[это неделя], все.
для получения даты бана: DeGetTime(databana,true);
для получения даты разбана: DeGetTime(databana+srokbana*60,true);*/

stock PSort(array[], source[], bool:methode = true, Loop = sizeof(array), Loop2 = sizeof(source)) // by Phento
{
	new
	t = 0,
	i = 0,
	p = Loop - 1;
	if(methode)
	{
		while(i < Loop2)
		{
		    array[i] = -cellmax;
			while(t <= p)
			{
				if(source[i] >= array[t])
				{
					while(p > t)
					{
						array[p] = array[p - 1];
						p--;
					}
					array[t] = source[i];
					break;
				}
				t++;
			}
			i++;
			t = 0;
			p = Loop - 1;
		}
	}
	else
	{
		while(i < Loop2)
		{
	    	array[i] = cellmax;
			while(t <= p)
			{
				if(source[i] <= array[t])
				{
					while(p > t)
					{
						array[p] = array[p - 1];
						p--;
					}
					array[t] = source[i];
					break;
				}
				t++;
			}
			i++;
			t = 0;
			p = Loop - 1;
		}
	}
	return 1;
}/*new
array[15],
source[] = { -12, 23, -54, 21, -4321, 65, -67 -543, 2, -12, 34, 12, -4, 23, 1, -23 };
// ¤¤¤¤¤¤¤¤¤¤¤¤¤¤
PSort(array, source, false);
for(new p; p < sizeof array; p++)
{
	if(array[p] == cellmax) continue;
	printf("array[%d]: %d", p, array[p]);
}
// ¤¤¤¤¤¤¤¤¤¤¤¤¤¤
print(" ");
PSort(array, source, true);
for(new p; p < sizeof array; p++)
{
	if(array[p] == -cellmax) continue;
	printf("array[%d]: %d", p, array[p]);
}
// ¤¤¤¤¤¤¤¤¤¤¤¤¤¤
return 1;
*/
// array[0]: -4321
// array[1]: -610
// array[2]: -54
// array[3]: -23
// array[4]: -12
// array[5]: -12
// array[6]: -4
// array[7]: 1
// array[8]: 2
// array[9]: 12
// array[10]: 21
// array[11]: 23
// array[12]: 23
// array[13]: 34
// array[14]: 65

// array[0]: 65
// array[1]: 34
// array[2]: 23
// array[3]: 23
// array[4]: 21
// array[5]: 12
// array[6]: 2
// array[7]: 1
// array[8]: -4
// array[9]: -12
// array[10]: -12
// array[11]: -23
// array[12]: -54
// array[13]: -610
// array[14]: -4321

#define SQL_CHECKER_SIZE 512

/*
Only With Stricked Kid Plugin
MySQLGet(type[],table[],getfrom[],paramwhatget[]);                                                              // Int, String, Float
MySQLAdd(type[],table[],addfrom[],paramwhatadd[],param,Float:param);                                            // Integer & Float
MySQLSet(table[128],what[128],what2[128],what3[128],what4[128],type1,Float:type2,type3[]);                      // Int, String, Or Integer

Ключевые значения. Их задавать в том случае, если вам не нужен этот тип переменных.
Code:
Ключевое значение 1 - -99999999999999
Ключевое значение 2 - 0.12153626531631
Ключевое значение 3 - NULL
*/

stock MySQLGet(table[64],what[64],what2[64],what3[64])
{
	new query[SQL_CHECKER_SIZE],fetch[256];
	format(query,sizeof(query),"SELECT %s FROM `%s` WHERE `%s` = '%s'",what,table,what2,what3);
	mysql_query(query);
	mysql_store_result();
	mysql_fetch_field(what3,fetch);
	mysql_free_result();
	return fetch; // Note: when you return Float use floatstr(), when Integer - strval().
}
stock MySQLSet(table[64],what[64],what3[64],what4[64],type1,Float:type2,type3[256])
{
	new query[SQL_CHECKER_SIZE];
	if(type1 != -99999999999999)
	{
		format(query,sizeof(query),"UPDATE `%s` SET `%s` = '%d' WHERE (`%s` = '%s')",table,what,type1,what3,what4);
		mysql_query(query);
		mysql_free_result();
	}
	if(type2 != 0.12153626531631)
	{
		format(query,sizeof(query),"UPDATE `%s` SET `%s` = '%f' WHERE (`%s` = '%s')",table,what,type2,what3,what4);
		mysql_query(query);
		mysql_free_result();
	}
	if(strcmp(type3, "NULL", true) != 0)
	{
		format(query,sizeof(query),"UPDATE `%s` SET `%s` = '%s' WHERE (`%s` = '%s')",table,what,type3,what3,what4);
		mysql_query(query);
		mysql_free_result();
	}
	return 1;
}
stock MySQLAdd(table[64],what1[64],what2[64],what3[64],type1,Float:type2)
{
	new query[SQL_CHECKER_SIZE],fetch[256],w,Float:ww;
	if(type1 != -99999999999999)
	{
		format(query,sizeof(query),"SELECT %s FROM `%s` WHERE `%s` = '%s'",what1,table,what2,what3);
		mysql_query(query);
		mysql_store_result();
		mysql_fetch_field(what3,fetch);
		w = strval(fetch)+type1;
		format(query,sizeof(query),"UPDATE `%s` SET `%s` = '%d' WHERE (`%s` = '%s')",table,what1,w,what2,what3);
		mysql_query(query);
		mysql_free_result();
	}
	if(type2 != 0.12153626531631)
	{
		format(query,sizeof(query),"SELECT %s FROM `%s` WHERE `%s` = '%s'",what1,table,what2,what3);
		mysql_query(query);
		mysql_store_result();
		mysql_fetch_field(what3,fetch);
		ww = floatstr(fetch)+type2;
		format(query,sizeof(query),"UPDATE `%s` SET `%s` = '%f' WHERE (`%s` = '%s')",table,what1,ww,what2,what3);
		mysql_query(query);
		mysql_free_result();
	}
	return 1;
}


//более мощные версии трёх моих же функций для извлечения праметров из строк, разделенных каким-то символом
//sparam - извлекает подстроку под указанным номером, по желанию и вместе с остатком строки
//iparam - извлекает подстроку под указанным номером и возвращает ее численное значение
//fparam - извлекает подстроку под указанным номером и возвращает ее дробное (Float) значение

/*
    ОПИСАНИЕ
        Строка source[] будет разделена на несколько подстрок
        с помощью символа delimiter. Нужная подстрока под номером (индексом)
        substrIndex будет помещена в строку dest[]
    ПАРАМЕТРЫ
        dest[]        сюда будет помещена нужная подстрока
        maxSize       макс. размер подстроки, которая будет помещена в dest[]
                      если длина подстроки больше maxSize, то она урежется
        source[]      исходная строка для разбиения и поиска в ней подстрок
        delimiter     символ, который будет делить исходную строку на подстроки
        substrIndex   порядковый номер (индекс) подстроки в исходной строке
        withRest      это логический флаг, если равен 1, то в dest[]
                      будут помещены все подстроки, начиная с указанного
                      индекса substrIndex. В том числе и все символы delimiter,
                      которые стоят между подстроками также будут включены в dest[]
    ВОЗВРАЩАЕТ
        ничего
    ПРИМЕРЫ
        new dest[256] = "something";
        sparam( dest, 20, "/register 123456", ' ', 0 ); // dest = "/register"
        sparam( dest, 20, "/register 123456", ' ', 1 ); // dest = "123456"
        sparam( dest,  5, "/register 123456", ' ', 0 ); // dest = "/reg"
        sparam( dest,  4, "/register 123456", ' ', 1 ); // dest = "123"

        sparam( dest, 20, "/pm 29 Как дела, бро?", ' ', 0 );    // dest = "/pm"
        sparam( dest,  4, "/pm 29 Как дела, бро?", ' ', 1 );    // dest = "29"
        sparam( dest, 10, "/pm 29 Как дела, бро?", ' ', 2 );    // dest = "Как"
        sparam( dest, 50, "/pm 29 Как дела, бро?", ' ', 2, 1 ); // dest = "Как дела, бро?"
        sparam( dest, 10, "/pm 29 Как дела, бро?", ' ', 3 );    // dest = "дела,"
        sparam( dest, 50, "/pm 29 Как дела, бро?", ' ', 3, 1 ); // dest = "дела, бро?"
        sparam( dest, 10, "/pm 29 Как дела, бро?", ' ', 4 );    // dest = "бро?"

        sparam( dest, 20, "91.235.141.89", '.', 0 );    // dest = "91"
        sparam( dest, 20, "91.235.141.89", '.', 1 );    // dest = "235"
        sparam( dest, 20, "91.235.141.89", '.', 2 );    // dest = "141"
        sparam( dest, 20, "91.235.141.89", '.', 3 );    // dest = "89"
        sparam( dest, 20, "91.235.141.89", '.', 1, 1 ); // dest = "235.141.89"
        sparam( dest, 20, "91.235.141.89", '.', 2, 1 ); // dest = "141.89"

        sparam( dest, 20, "/register 123456", ' ', -1 ); // dest = "", т.к. подстроки с таким индексом нет
        sparam( dest, 20, "/register 123456", ' ',  7 ); // dest = "", т.к. подстроки с таким индексом нет*/
stock sparam(	dest[],				maxSize		= sizeof(dest),
				const source[],		delimiter	= ' ',
				substrIndex = 0,	withRest	= 0
			)
{
	dest[0] = 0; // очистим строку назначения
	for ( new cur, pre, i = -1; ; cur++ ) // пробежимся по каждому символу в строке source
	{
		if ( source[cur] == 0 ) // если текущий символ в source - это символ конца строки
		{
			if ( ++i == substrIndex ) // если индекс текущей подстроки и есть sourceIndex
				// скопируем в dest нужную подстроку из source
				strmid( dest, source, pre, ( withRest ? strlen(source) : cur ), maxSize );
			return; // завершим работу функции
		}
		if ( source[cur] == delimiter ) // если текущий символ в source - это символ для разделения строки
		{
			if ( ++i == substrIndex ) // если индекс текущей подстроки и есть sourceIndex
			{
				// скопируем в dest нужную подстроку из source
				strmid( dest, source, pre, ( withRest ? strlen(source) : cur ), maxSize );
				return; // завершим работу функции
			}
			pre = cur + 1;
		}
	}
}
/*  ОПИСАНИЕ
        Строка source[] будет разделена на несколько подстрок
        с помощью символа delimiter. И нужная подстрока под номером (индексом)
        substrIndex будет возвращена функцией как число
    ПАРАМЕТРЫ
        source[]      исходная строка для разбиения и поиска в ней подстрок
        delimiter     символ, который будет делить исходную строку на подстроки
        substrIndex   порядковый номер (индекс) подстроки в исходной строке
    ВОЗВРАЩАЕТ
        целочисленное значение подстроки
    ПРИМЕРЫ
        new number = 555;
        number = iparam( "/givecash 23 50000", ' ', -1 ); // number = 0, т.к. подстроки с таким индексом нет
        number = iparam( "/givecash 23 50000", ' ',  0 ); // number = 0
        number = iparam( "/givecash 23 50000", ' ',  1 ); // number = 23
        number = iparam( "/givecash 23 50000", ' ',  2 ); // number = 50000
        number = iparam( "/givecash 23 50000", ' ',  3 ); // number = 0, т.к. подстроки с таким индексом нет*/
/*stock iparam(const source[], delimiter = ' ', substrIndex = 0)
{
	for(new dest[12], cur, pre, i = -1; ; cur++) // пробежимся по каждому символу в строке source
	{
		if(source[cur] == 0) // если текущий символ в source - это символ конца строки
		{
			if(++i == substrIndex)// если индекс текущей подстроки и есть sourceIndex
				strmid(dest, source, pre, cur, 12);// скопируем в dest нужную подстроку из source
			return strval(dest);// завершим работу функции и вернем целочисленное значение подстроки
		}
		if(source[cur] == delimiter)// если текущий символ в source - это символ для разделения строки
		{
			if(++i == substrIndex)// если индекс текущей подстроки и есть sourceIndex
			{
				strmid(dest, source, pre, cur, 12);// скопируем в dest нужную подстроку из source
				return strval(dest);// завершим работу функции и вернем целочисленное значение подстроки
			}
			pre = cur + 1;
		}
	}
}*/
stock iparam(const source[], delimiter = ' ', substrIndex = 0)
{
    new dest[12], cur, pre, i = -1;
    for( ; ; cur++) // пробежимся по каждому символу в строке source
    {
        if (source[cur] == 0) // если текущий символ в source - это символ конца строки
        {
            if(++i == substrIndex) // если индекс текущей подстроки и есть sourceIndex
                strmid(dest, source, pre, cur, 12); // скопируем в dest нужную подстроку из source
            goto iparam_end;
        }
        if(source[cur] == delimiter) // если текущий символ в source - это символ для разделения строки
        {
            if(++i == substrIndex) // если индекс текущей подстроки и есть sourceIndex
            {
                strmid(dest, source, pre, cur, 12);// скопируем в dest нужную подстроку из source
                goto iparam_end;
            }
            pre = cur + 1;
        }
    }
	iparam_end:
    return strval(dest);// завершим работу функции и вернем целочисленное значение подстроки
}

/*  ОПИСАНИЕ
        Строка source[] будет разделена на несколько подстрок
        с помощью символа delimiter. И нужная подстрока под номером (индексом)
        substrIndex будет возвращена функцией как дробное число
    ПАРАМЕТРЫ
        source[]      исходная строка для разбиения и поиска в ней подстрок
        delimiter     символ, который будет делить исходную строку на подстроки
		substrIndex   порядковый номер (индекс) подстроки в исходной строке
    ВОЗВРАЩАЕТ
        дробное численное значение подстроки
    ПРИМЕРЫ
        new Float: float = 555.5;
        float = iparam( "/goto -157.2 1248.25 10", ' ', -1 ); // float = 0.0, т.к. подстроки с таким индексом нет
        float = iparam( "/goto -157.2 1248.25 10", ' ',  0 ); // float = 0.0, т.к. подстрока "/goto" это не число
        float = iparam( "/goto -157.2 1248.25 10", ' ',  1 ); // float = -157.2
        float = iparam( "/goto -157.2 1248.25 10", ' ',  2 ); // float = 1248.25
        float = iparam( "/goto -157.2 1248.25 10", ' ',  3 ); // float = 10.0
        float = iparam( "/goto -157.2 1248.25 10", ' ',  4 ); // float = 0.0, т.к. подстроки с таким индексом нет
*/
/*stock Float: fparam(const source[], delimiter = ' ', substrIndex = 0)
{
	for(new dest[40], cur, pre, i = -1; ; cur++) // пробежимся по каждому символу в строке source
	{
		if(source[cur] == 0) // если текущий символ в source - это символ конца строки
		{
			if(++i == substrIndex) // если индекс текущей подстроки и есть sourceIndex
			{
				strmid( dest, source, pre, cur, 40); // скопируем в dest нужную подстроку из source
				return floatstr(dest); // завершим работу функции и вернем дробное численное значение подстроки
			}
		}
		if(source[cur] == delimiter) // если текущий символ в source - это символ для разделения строки
		{
			if (++i == substrIndex) // если индекс текущей подстроки и есть sourceIndex
			{
				strmid(dest, source, pre, cur, 40);// скопируем в dest нужную подстроку из source
				return floatstr(dest); // завершим работу функции и вернем дробное численное значение подстроки
			}
			pre = cur + 1;
		}
	}
}*/
stock Float: fparam(const source[], delimiter = ' ', substrIndex = 0)
{
    new dest[40];
    for( new cur, pre, i = -1; ; cur++) // пробежимся по каждому символу в строке source
    {
        if( source[cur] == 0) // если текущий символ в source - это символ конца строки
        {
            if(++i == substrIndex) // если индекс текущей подстроки и есть sourceIndex
                strmid( dest, source, pre, cur, 40 ); // скопируем в dest нужную подстроку из source
            break;
        }
        else if( source[cur] == delimiter) // если текущий символ в source - это символ для разделения строки
        {
            if( ++i == substrIndex) // если индекс текущей подстроки и есть sourceIndex
            {
                strmid(dest, source, pre, cur, 40);// скопируем в dest нужную подстроку из source
                break;
            }
            pre = cur + 1;
        }
    }
    return floatstr(dest);
}

/*stock GetPlayerSwimmingStyle(playerid)
{
    new animname[32];
    GetAnimationName(GetPlayerAnimationIndex(playerid),animname,32,animname,32);
    if( strfind(animname,"Swim_Breast",true) != -1 ) return 1;
    else if( strfind(animname,"SWIM_crawl",true) != -1 ) return 2;
    else if( strfind(animname,"Swim_Dive_Under",true) != -1 ) return 3;
    else if( strfind(animname,"Swim_Glide",true) != -1 ) return 4;
    else if( strfind(animname,"Swim_Tread",true) != -1 ) return 5;
    else if( strfind(animname,"Swim_Under",true) != -1 ) return 6;
    return 0;
}*/

stock detectIP(text[])
{
    new dotCount;
    for(new i; i < strlen(text); ++i)
    {
        if('0' <= text[i] <= '9')
        {
            do
            {
                if(text[i] == '.') ++dotCount;
                ++i;
            }
            while(('0' <= text[i] <= '9') || text[i] == '.' || text[i] == ':');
        }
    }
    if(dotCount >= 3) return true;
    return false;
}

/*
Tested:
printf("%s", NiceMoney(1));
printf("%s", NiceMoney(12));
printf("%s", NiceMoney(123));
printf("%s", NiceMoney(1234));
printf("%s", NiceMoney(12345));
printf("%s", NiceMoney(123456));
printf("%s", NiceMoney(1234567));
printf("%s", NiceMoney(12345678));
printf("%s", NiceMoney(123456789));
printf("%s", NiceMoney(1234567890));
printf("%s", NiceMoney(-1));
printf("%s", NiceMoney(-12));
printf("%s", NiceMoney(-123));
printf("%s", NiceMoney(-1234));
printf("%s", NiceMoney(-12345));
printf("%s", NiceMoney(-123456));
printf("%s", NiceMoney(-1234567));
printf("%s", NiceMoney(-12345678));
printf("%s", NiceMoney(-123456789));
printf("%s", NiceMoney(-1234567890));

Example:
[01:27:05] 1
[01:27:05] 12
[01:27:05] 123
[01:27:05] 1,234
[01:27:05] 12,345
[01:27:05] 123,456
[01:27:05] 1,234,567
[01:27:05] 12,345,678
[01:27:05] 123,456,789
[01:27:05] 1,234,567,890
[01:27:05] -1
[01:27:05] -12
[01:27:05] -123
[01:27:05] -1,234
[01:27:05] -12,345
[01:27:05] -123,456
[01:27:05] -1,234,567
[01:27:05] -12,345,678
[01:27:05] -123,456,789
[01:27:05] -1,234,567,890
*/
stock NiceMoney(amount, sep[] = ",")
{
    new str[16],
        negativ = 0;
    if(amount < 0) negativ = 1;
    format(str, sizeof(str), "%i", amount);
    new
        lenght = strlen(str);
    while((lenght -= 3) > negativ) strins(str, sep, lenght);
    return str;
}

//Cleaning the chosen player chat..
stock ChatCleanup(playerid, lines = 50)
{
    for(new i = 0; i < lines; i++)
    {
        SendClientMessage(playerid, 0, "\n");
    }
}
