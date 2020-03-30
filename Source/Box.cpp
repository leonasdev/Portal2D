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

    x = 300;	//初始位置
    y = 500;
    is_take = FALSE;	//初始沒被拿起來
    initial_velocity = INITIAL_VELOCITY;
    velocity = 1;
}
void Box::OnMove(Map* map)
{
    if (map->IsWhat(x, 1, y + bmp.Height() + 1, bmp.Width()) == 0)    // 當y座標還沒碰到地板
    {
        y += velocity;	// y軸下降(移動velocity個點，velocity的單位為 點/次)

        if (velocity <= 10)	//下降速度最快到10
            velocity++;		// 受重力影響，下次的下降速度增加
        else
            velocity = 10;
    }
    else
    {
        y = y / TIMES;
        y = y * TIMES;
        //velocity = initial_velocity; // 重設上升初始速度
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