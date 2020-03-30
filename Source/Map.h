#ifndef MAP_H
#define MAP_H
#define TIMES 20
#define MAP_HEIGHT 45
#define MAP_WIDTH 80
namespace game_framework
{
class Map
{
    public:
        Map();
        //void LoadBitmap();	// ���J�a��
        //void OnShow();		// ��ܦa��
        int IsWhat(int, int, int, int);		
		int Find_PortalLoc(char, int);
        void CreateMap(int, int, int, int, int);
    protected:
        int map[MAP_WIDTH][MAP_HEIGHT];		// �إߦa�ϯx�}��index
        const int x, y;		// �j�a�Ϫ����W��x,y�y��
        const int MW, MH;	// �C�i�p�a�Ϫ��e����
};
}
#endif