#ifndef MAP_H
#define MAP_H
namespace game_framework 
{
	class Map
	{
	public:
		Map();
		void LoadBitmap();	// 載入地圖
		void OnShow();		// 顯示地圖
		bool IsEmpty(int, int);
	protected:
		//CMovingBitmap blue, green;
		int map[64][48];		// 建立地圖矩陣的index
		const int x, y;		// 大地圖的左上角x,y座標
		const int MW, MH;	// 每張小地圖的寬高度
	};
}
#endif