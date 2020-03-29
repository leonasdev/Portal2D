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
    x = 1100;	//按鈕初始位置
    y = 800;
    is_click = false;	//是否被觸發
}

bool Button::HitCharacter(CCharacter* eraser)
{
    // 檢測角色所構成的矩形是否碰到球
    return HitRectangle(eraser->GetX1(), eraser->GetY1(),
                        eraser->GetX2(), eraser->GetY2());
}

bool Button::HitRectangle(int tx1, int ty1, int tx2, int ty2)
{
    int x1 = x;//+ dx;				// 球的左上角x座標
    int y1 = y;// +dy;				// 球的左上角y座標
    int x2 = x1 + bmp.Width();		// 球的右下角x座標
    int y2 = y1 + bmp.Height();		// 球的右下角y座標
    //
    // 檢測球的矩形與參數矩形是否有交集
    //
    return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
}

bool Button::IsClick()
{
    return is_click;	//判定是否被觸發
}

void Button::LoadBitmap()
{
    bmp.AddBitmap(IDB_Button, RGB(255, 255, 255));		//原始按鈕
    bmp.AddBitmap(IDB_ButtonDown, RGB(255, 255, 255));	//按鈕觸發
}
void Button::SetIsClick(bool click)
{
    is_click = click;
}

void Button::SetXY(int nx, int ny)	//設定按鈕位置
{
    x = nx;
    y = ny;
}

void Button::OnShow()
{
    if (is_click && !bmp.IsFinalBitmap())	//被按下且不是最後一張就換圖片
        bmp.OnMove();
    else if (!is_click)	//沒被觸發重置為第一張圖片
        bmp.Reset();

    bmp.SetTopLeft(x, y );
    bmp.OnShow();
}
}