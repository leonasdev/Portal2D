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
        static int color;	//目前是門0 還是門1
		CAnimation animation[2];
		int x[2], y[2];
        
};
}
#endif