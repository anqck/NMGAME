#pragma once
#include "GameVisibleEntity.h"

class Camel : public GameVisibleEntity
{
public:
	Camel() { this->Initialize(); };
	Camel(D3DXVECTOR3 Position) : GameVisibleEntity( Position) { this->Initialize(); };
	Camel( int X, int Y) : GameVisibleEntity( X, Y) { this->Initialize(); };
	~Camel();

	

	void	Render(float DeltaTime);
	void	Update(float DeltaTime);
	//void	nextFrame();

protected:
	void			Initialize();
	void			LoadResource();

	int					mStartIdx;		//Index bắt đầu của các Rect chứa các Sprite
	int					mEndIdx;		//
	int					mCurrentIdx;	//Index hiện tại
	DWORD last_time;
	//void			Update(float DeltaTime);
	//void			nextFrame();
};