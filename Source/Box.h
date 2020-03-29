#ifndef Box_H
#define Box_H
#include "Map.h"

namespace game_framework
{
class Box
{
    public:
        Box();
        void LoadBitmap();			// 載入圖形
        void OnShow();				// 圖案貼到螢幕上
        void OnMove(Map* map);		// 讓箱子有慣性動作
        void SetIstake(bool flag);	// 設定是否被拿起
        bool Istake();				// 取得是否被拿起
        //~Box();
    private:
        CMovingBitmap bmp;

        int x, y;		//位置
        bool is_take;	//狀態
        int	velocity, initial_velocity;	//初速度

};

}
#endif