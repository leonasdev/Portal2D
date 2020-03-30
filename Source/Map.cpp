#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
namespace game_framework
{
Map::Map() : x(0), y(0), MW(20), MH(20) //�����a�ϥ��W���y�ФΨC�i�p�ϼe��
{
    for (int i = 0; i < MAP_WIDTH; i++)	//��l�ư}�C
        for (int j = 0; j < MAP_HEIGHT; j++)
            map[i][j] = 0;

    CreateMap(1,0, 0, 87, 892);			// �����
    CreateMap(1,1505, 0, 1591, 891);	// �k���
    CreateMap(1,0, 827, 1591, 897);		// �@��
    CreateMap(1,90, 295, 590, 533);		// �G��_��
    CreateMap(1,607, 453, 1131, 491);	// �G��_��
    CreateMap(1,1095, 228, 1488, 492);	// �G��_�k

}
int Map::IsWhat(int x, int h, int y, int w)	//x y���W�� h �ϰ� w �ϼe
{
    int gx, gy;	//��y��
	int type;

    for (int i = x; i < x + w; i++)
        for (int j = y; j < y + h; j++)
        {
            gx = i / TIMES;	//�N�I�y���ഫ����y��
            gy = j / TIMES;

            if (map[gx][gy] == 1)	return 1;		// �^��1:���
			else if (map[gx][gy] == 2) type = 2;	// Portal color �� 0
			else if (map[gx][gy] == 3) type = 3;	// Portal color �� 1
        }
	if (type != 2 && type != 3)
		return 0;		// �^��0:�Ū�
	else
		return type;	//�^��type:����Portal
}
int Map::Find_PortalLoc(char xy, int type)
{
	for (int i = 0; i < MAP_WIDTH; i++)
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			if (map[i][j] == type)	// ���a�ϬOtype����y�ФF (�ѤW�ܤU �ѥ��ܥk ��쪺�Ĥ@��)
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