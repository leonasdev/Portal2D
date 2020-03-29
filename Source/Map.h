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
		void LoadBitmap();	// ���J�a��
		void OnShow();		// ��ܦa��
		bool IsEmpty(int, int, int, int);
	protected:
		//CMovingBitmap blue, green;
		int map[MAP_WIDTH][MAP_HEIGHT];		// �إߦa�ϯx�}��index
		const int x, y;		// �j�a�Ϫ����W��x,y�y��
		const int MW, MH;	// �C�i�p�a�Ϫ��e����
		void CreateMap_1(int, int, int, int);
	};
}
#endif