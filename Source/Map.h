#ifndef MAP_H
#define MAP_H
namespace game_framework 
{
	class Map
	{
	public:
		Map();
		void LoadBitmap();	// ���J�a��
		void OnShow();		// ��ܦa��
		bool IsEmpty(int, int);
	protected:
		//CMovingBitmap blue, green;
		int map[64][48];		// �إߦa�ϯx�}��index
		const int x, y;		// �j�a�Ϫ����W��x,y�y��
		const int MW, MH;	// �C�i�p�a�Ϫ��e����
	};
}
#endif