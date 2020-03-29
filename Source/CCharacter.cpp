#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CCharacter.h"
#include <iostream>

namespace game_framework
{
/////////////////////////////////////////////////////////////////////////////
// CCharacter: Eraser class
/////////////////////////////////////////////////////////////////////////////

CCharacter::CCharacter()
{
    Initialize();
}

int CCharacter::GetX1()
{
    return x;
}

int CCharacter::GetY1()
{
    return y;
}

int CCharacter::GetX2()
{
    return x + animation.Width();
}

int CCharacter::GetY2()
{
    return y + animation.Height();
}

void CCharacter::Initialize()
{
    const int INITIAL_VELOCITY = 10;	// ��l�W�ɳt��

    const int X_POS = 100;
    const int Y_POS = 0;

    x = X_POS;
    y = Y_POS;
    initial_velocity = INITIAL_VELOCITY;
    velocity = 1;
    rising = isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
}

void CCharacter::LoadBitmap()
{
    animation.AddBitmap(IDB_character, RGB(255, 255, 255));	//�쥻������
    animation.AddBitmap(IDB_moveright, RGB(255, 255, 255));	//���k
    animation.AddBitmap(IDB_moveleft, RGB(255, 255, 255));	//����
    animation.AddBitmap(IDB_moveup, RGB(255, 255, 255));
    //animation.AddBitmap(IDB_ERASER2, RGB(255, 255, 255));
}

void CCharacter::OnMove(Map* map)
{
    const int STEP_SIZE = 10;
    animation.SetDelayCount(1);

    if (isMovingRight || isMovingLeft || isMovingUp)  		//���k
    {
        if (isMovingRight)
        {
            animation.SelectBitmap(1);
			if (map->IsEmpty(x + animation.Width() + 1, animation.Height(), y, 1)) {
                x += STEP_SIZE;
            }
        }

        if (isMovingLeft)  	//����
        {
            animation.SelectBitmap(2);
			if (map->IsEmpty(x - 1, animation.Height(), y, 1)) {
                x -= STEP_SIZE;
            }
        }

        if (isMovingUp && !map->IsEmpty(x,1, y + animation.Height() + 1,animation.Width()))  			// �W�ɪ��A
        {
			rising = TRUE;
			animation.SelectBitmap(3);
        }
    }
    else
    {
        animation.Reset();
    }

    jump(map);
}

//animation.Reset();
/*  if (isMovingDown)
      y += STEP_SIZE;*/
void CCharacter::jump(Map* map)
{
    if (rising)  			// �W�ɪ��A
    {
		if (!map->IsEmpty(x, 1, y + animation.Height() + 1, animation.Width()))
		{
			velocity = initial_velocity; // ���]�W�ɪ�l�t��
		}
        if (velocity > 0)
        {
            y -= velocity;	// ��t�� > 0�ɡAy�b�W��(����velocity���I�Avelocity����쬰 �I/��)
            velocity--;		// �����O�v�T�A�U�����W�ɳt�׭��C
        }
        else
        {
            rising = false; // ��t�� <= 0�A�W�ɲפ�A�U���אּ�U��
            velocity = 1;	// �U������t(velocity)��1
        }
    }
    else  				// �U�����A
    {
        if (map->IsEmpty(x, 1, y + animation.Height() + 1, animation.Width()))    // ��y�y���٨S�I��a�O
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
}

void CCharacter::SetMovingDown(bool flag)
{
    isMovingDown = flag;
}

void CCharacter::SetMovingLeft(bool flag)
{
    isMovingLeft = flag;
}

void CCharacter::SetMovingRight(bool flag)
{
    isMovingRight = flag;
}

void CCharacter::SetMovingUp(bool flag)
{
    isMovingUp = flag;
}

void CCharacter::SetXY(int nx, int ny)
{
    x = nx;
    y = ny;
}

void CCharacter::OnShow()
{
    animation.SetTopLeft(x, y);
    animation.OnShow();
}
}
