#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
namespace game_framework
{
    Map::Map() :x(0), y(0), MW(20), MH(20)  //給予地圖左上角座標及每張小圖寬高
    {
        for (int i = 0; i < MAP_WIDTH; i++)	//初始化陣列
            for (int j = 0; j < MAP_HEIGHT; j++)
                map[i][j] = 0;

		CreateMap_1(0, 0, 87, 892);	// 左牆壁
		CreateMap_1(1505, 0, 1591, 891);	// 右牆壁
		CreateMap_1(0, 827, 1591, 897);	// 一樓
		CreateMap_1(90, 295, 590, 533);	// 二樓_左
		CreateMap_1(607, 453, 1131, 491);	// 二樓_中
		CreateMap_1(1095, 228, 1488, 492);	// 二樓_右

    }
    bool Map::IsEmpty(int x, int h, int y, int w)
    {
		int gx, gy;
		for (int i = x; i < x + w; i++)
			for (int j = y; j < y + h; j++)
				{
					gx = i / TIMES;
					gy = j / TIMES;
					if (map[gx][gy] != 0)	return false;
				}
		return true;
    }
    void Map::LoadBitmap()
    {

    }
	void Map::CreateMap_1(int x1, int y1, int x2, int y2)
	{
		int gx1 = x1 / TIMES;
		int gy1 = y1 / TIMES;
		int gx2 = x2 / TIMES;
		int gy2 = y2 / TIMES;
		for (int i = gx1; i < gx2; i++)
		{
			for (int j = gy1; j < gy2; j++)
			{
				map[i][j] = 1;
			}
		}
	}
}