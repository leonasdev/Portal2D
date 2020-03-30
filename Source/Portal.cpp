#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Portal.h"
namespace game_framework
{
	int Portal::color = 0;
	Portal::Portal()
	{
	}
	void Portal::LoadBitmap()
	{

	}
	void Portal::OnShow()
	{
		/*animation[0].SetTopLeft(x[0], y[0]);
		animation[1].SetTopLeft(x[1], y[1]);
		animation[0].OnShow();
		animation[1].OnShow();*/
	}
	void Portal::ClosePortal()
	{
		//animation->SelectBitmap(0);
	}
	void Portal::OpenPortal(Map* map, int nx, int ny)
	{
		x[color] = nx;
		y[color] = ny;
		//map->CreateMap(color + 2, nx, ny, nx + animation[color].Width(), ny + animation[color].Height());
		map->CreateMap(color + 2, nx, ny, nx + 80, ny + 200);
		if (color == 0) color = 1;
		else color = 0;
	}

}
