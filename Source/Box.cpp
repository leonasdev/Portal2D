#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Box.h"
namespace game_framework
{

Box::Box()
{
    const int INITIAL_VELOCITY = 10;

    x = 300;	//��l��m
    y = 500;
    is_take = FALSE;	//��l�S�Q���_��
    initial_velocity = INITIAL_VELOCITY;
    velocity = 1;
}
void Box::OnMove(Map* map)
{
    if (map->IsWhat(x, 1, y + bmp.Height() + 1, bmp.Width()) == 0)    // ��y�y���٨S�I��a�O
    {
        y += velocity;	// y�b�U��(����velocity���I�Avelocity����쬰 �I/��)

        if (velocity <= 10)	//�U���t�׳̧֨�10
            velocity++;		// �����O�v�T�A�U�����U���t�׼W�[
        else
            velocity = 10;
    }
    else
    {
        y = y / TIMES;
        y = y * TIMES;
        //velocity = initial_velocity; // ���]�W�ɪ�l�t��
    }
}
void Box::LoadBitmap()
{
    bmp.LoadBitmap(IDB_BALL);
}
void Box::SetIstake(bool flag)
{
    is_take = flag;
}
bool Box::Istake()
{
    return is_take;
}
void Box::OnShow()
{
    bmp.SetTopLeft(x, y);
    bmp.ShowBitmap();
}
}