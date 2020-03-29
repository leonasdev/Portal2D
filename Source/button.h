namespace game_framework
{
class Button
{
    public:
        Button();
        bool HitCharacter(CCharacter* character);		// 是否碰到擦子
        bool IsClick();									// 是否觸碰
        void LoadBitmap();								// 載入圖形
        void OnShow();									// 將圖形貼到畫面
        void SetXY(int nx, int ny);						// 設定圓心的座標
        void SetIsClick(bool click);					// 設定是否活著
    protected:
        CAnimation bmp;		// 球的圖
        int x, y;			// 圓心的座標
        bool is_click;		// 是否觸發
    private:
        bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	// 是否碰到參數範圍的矩形
};
}