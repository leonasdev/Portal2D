#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
namespace game_framework
{
    Map::Map() :x(0), y(0), MW(120), MH(100)  //�����a�ϥ��W���y�ФΨC�i�p�ϼe��
    {
        for (int i = 0; i < 64; i++)
            for (int j = 0; j < 48; j++)
                map[i][j] = 0;
        for (int i = 0; i < 48; i++)
        {
            map[0][i] = 1;
            map[63][i] = 1;
        }
        for (int i = 0; i < 64; i++)
            map[i][47] = 1;
    }
    bool Map::IsEmpty(int x, int y)
    {
        int gx = x / 10;
        int gy = y / 10;
        return map[gx][gy] == 0;
    }
    void Map::LoadBitmap()
    {

    }
}