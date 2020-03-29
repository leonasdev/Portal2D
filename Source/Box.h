#ifndef Box_H
#define Box_H
#include "Map.h"

namespace game_framework
{
class Box
{
    public:
        Box();
        void LoadBitmap();			// ���J�ϧ�
        void OnShow();				// �Ϯ׶K��ù��W
        void OnMove(Map* map);		// ���c�l���D�ʰʧ@
        void SetIstake(bool flag);	// �]�w�O�_�Q���_
        bool Istake();				// ���o�O�_�Q���_
        //~Box();
    private:
        CMovingBitmap bmp;

        int x, y;		//��m
        bool is_take;	//���A
        int	velocity, initial_velocity;	//��t��

};

}
#endif