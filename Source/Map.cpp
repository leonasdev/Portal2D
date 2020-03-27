#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
namespace game_framework
{
    Map::Map() :x(0), y(0), MW(20), MH(20)  //�����a�ϥ��W���y�ФΨC�i�p�ϼe��
    {
        for (int i = 0; i < MAP_WIDTH; i++)	//��l�ư}�C
            for (int j = 0; j < MAP_HEIGHT; j++)
                map[i][j] = 0;
        for (int i = 0; i < MAP_HEIGHT; i++)
        {
            map[3][i] = 1;	// �����
            map[75][i] = 1;	// �k���
        }
        for (int i = 0; i < MAP_WIDTH; i++)
            map[i][41] = 1;	// �a�O
		for (int i = 14; i < 25; i++)
			for (int j = 0; j < 29; j++)
				map[j][i] = 1;	// �G��
		for (int i = 30; i <= 53; i++)
		{
			map[i][22] = 1;	//�G�Ӥ���
		}
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
	/*void Map::CreateMap_1(int *map[], int , int)
	{
		for(int i=LeftTop;i<)
	}*/
}