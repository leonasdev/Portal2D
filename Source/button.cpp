#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CCharacter.h"
#include "button.h"

namespace game_framework
{
/////////////////////////////////////////////////////////////////////////////
// button: Ball class
/////////////////////////////////////////////////////////////////////////////

Button::Button()
{
    x = 1100;	//���s��l��m
    y = 800;
    is_click = false;	//�O�_�QĲ�o
}

bool Button::HitCharacter(CCharacter* eraser)
{
    // �˴�����Һc�����x�άO�_�I��y
    return HitRectangle(eraser->GetX1(), eraser->GetY1(),
                        eraser->GetX2(), eraser->GetY2());
}

bool Button::HitRectangle(int tx1, int ty1, int tx2, int ty2)
{
    int x1 = x;//+ dx;				// �y�����W��x�y��
    int y1 = y;// +dy;				// �y�����W��y�y��
    int x2 = x1 + bmp.Width();		// �y���k�U��x�y��
    int y2 = y1 + bmp.Height();		// �y���k�U��y�y��
    //
    // �˴��y���x�λP�ѼƯx�άO�_���涰
    //
    return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
}

bool Button::IsClick()
{
    return is_click;	//�P�w�O�_�QĲ�o
}

void Button::LoadBitmap()
{
    bmp.AddBitmap(IDB_Button, RGB(255, 255, 255));		//��l���s
    bmp.AddBitmap(IDB_ButtonDown, RGB(255, 255, 255));	//���sĲ�o
}
void Button::SetIsClick(bool click)
{
    is_click = click;
}

void Button::SetXY(int nx, int ny)	//�]�w���s��m
{
    x = nx;
    y = ny;
}

void Button::OnShow()
{
    if (is_click && !bmp.IsFinalBitmap())	//�Q���U�B���O�̫�@�i�N���Ϥ�
        bmp.OnMove();
    else if (!is_click)	//�S�QĲ�o���m���Ĥ@�i�Ϥ�
        bmp.Reset();

    bmp.SetTopLeft(x, y );
    bmp.OnShow();
}
}