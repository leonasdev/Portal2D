namespace game_framework
{
class Button
{
    public:
        Button();
        bool HitCharacter(CCharacter* character);		// �O�_�I�����l
        bool IsClick();									// �O�_Ĳ�I
        void LoadBitmap();								// ���J�ϧ�
        void OnShow();									// �N�ϧζK��e��
        void SetXY(int nx, int ny);						// �]�w��ߪ��y��
        void SetIsClick(bool click);					// �]�w�O�_����
    protected:
        CAnimation bmp;		// �y����
        int x, y;			// ��ߪ��y��
        bool is_click;		// �O�_Ĳ�o
    private:
        bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	// �O�_�I��Ѽƽd�򪺯x��
};
}