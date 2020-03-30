#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
namespace game_framework
{
Map::Map() : x(0), y(0), MW(20), MH(20) //給予地圖左上角座標及每張小圖寬高
{
    for (int i = 0; i < MAP_WIDTH; i++)	//初始化陣列
        for (int j = 0; j < MAP_HEIGHT; j++)
            map[i][j] = 0;

    CreateMap(1,0, 0, 87, 892);			// 左牆壁
    CreateMap(1,1505, 0, 1591, 891);	// 右牆壁
    CreateMap(1,0, 827, 1591, 897);		// 一樓
    CreateMap(1,90, 295, 590, 533);		// 二樓_左
    CreateMap(1,607, 453, 1131, 491);	// 二樓_中
    CreateMap(1,1095, 228, 1488, 492);	// 二樓_右

}
int Map::IsWhat(int x, int h, int y, int w)	//x y左上角 h 圖高 w 圖寬
{
    int gx, gy;	//格座標
	int type;

    for (int i = x; i < x + w; i++)
        for (int j = y; j < y + h; j++)
        {
            gx = i / TIMES;	//將點座標轉換成格座標
            gy = j / TIMES;

            if (map[gx][gy] == 1)	return 1;		// 回傳1:牆壁
			else if (map[gx][gy] == 2) type = 2;	// Portal color 為 0
			else if (map[gx][gy] == 3) type = 3;	// Portal color 為 1
        }
	if (type != 2 && type != 3)
		return 0;		// 回傳0:空的
	else
		return type;	//回傳type:哪種Portal
}
int Map::Find_PortalLoc(char xy, int type)
{
	for (int i = 0; i < MAP_WIDTH; i++)
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			if (map[i][j] == type)	// 找到地圖是type的格座標了 (由上至下 由左至右 找到的第一個)
			{
				if (xy == 'x') return i * TIMES;
				else if (xy == 'y')	return j * TIMES;
			}
		}
	return 0;
}
//void Map::LoadBitmap()
//{
//
//}
void Map::CreateMap(int type, int x1, int y1, int x2, int y2)
{
    int gx1 = x1 / TIMES;
    int gy1 = y1 / TIMES;
    int gx2 = x2 / TIMES;
    int gy2 = y2 / TIMES;

    for (int i = gx1; i < gx2; i++)
    {
        for (int j = gy1; j < gy2; j++)
        {
            map[i][j] = type;
        }
    }
}
}