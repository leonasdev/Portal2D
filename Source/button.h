namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class����¶��骺�y
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////

	class button
	{
	public:
		button();
		bool HitCharacter(CCharacter *eraser);						// �O�_�I�����l
		bool IsClick();											// �O�_����
		void LoadBitmap();										// ���J�ϧ�
		//void OnMove();											// ����
		void OnShow();											// �N�ϧζK��e��
		void SetXY(int nx, int ny);								// �]�w��ߪ��y��
		void SetIsClick(bool click);							// �]�w�O�_����
		//void SetDelay(int d);									// �]�w���઺�t��
	protected:
		CMovingBitmap bmp;			// �y����
		int x, y;					// ��ߪ��y��
		bool is_click;				// �O�_����

		//CMovingBitmap bmp_center;	// ��ߪ���			
		//int dx, dy;					// �y�Z����ߪ��첾�q
		//int index;					// �y���u���סv�A0-17���0-360��
		//int delay_counter;			// �վ����t�ת��p�ƾ�
		//int delay;					// ���઺�t��
	private:
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	// �O�_�I��Ѽƽd�򪺯x��
	};
}