#include "Map.h"
#ifndef Portal_H
#define Portal_H
namespace game_framework
{
class Portal
{
    public:
		Portal();
		void LoadBitmap();
		void OnShow();
		void ClosePortal();
		void OpenPortal(Map*, int, int);
    private:
        static int color;	//�ثe�O��0 �٬O��1
		CAnimation animation[2];
		int x[2], y[2];
        
};
}
#endif