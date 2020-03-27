#include "Map.h"
namespace game_framework
{
/////////////////////////////////////////////////////////////////////////////
// �o��class���ѥi�H����L�ηƹ�������l
// �����N�i�H��g���ۤv���{���F
/////////////////////////////////////////////////////////////////////////////

class CCharacter
{
    public:
        CCharacter();
        int  GetX1();					// ���l���W�� x �y��
        int  GetY1();					// ���l���W�� y �y��
        int  GetX2();					// ���l�k�U�� x �y��
        int  GetY2();					// ���l�k�U�� y �y��
        void Initialize();				// �]�w���l����l��
        void LoadBitmap();				// ���J�ϧ�
        void OnMove(Map*);					// �������l
        void OnShow();					// �N���l�ϧζK��e��
        void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
        void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
        void SetMovingRight(bool flag); // �]�w�O�_���b���k����
        void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
        void SetXY(int nx, int ny);		// �]�w���l���W���y��
        void jump(Map*);					//�]�w�}����D
    protected:
        CAnimation animation;		// ���l���ʵe
        int x, y;					// ���l���W���y��
        int	velocity, initial_velocity;
        bool rising;
        bool isMovingDown;			// �O�_���b���U����
        bool isMovingLeft;			// �O�_���b��������
        bool isMovingRight;			// �O�_���b���k����
        bool isMovingUp;			// �O�_���b���W����
};
}