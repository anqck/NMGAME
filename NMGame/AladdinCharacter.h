#pragma once
#include "Global.h"
#include "Sprite.h"

class AladdinCharacter
{
public:
	AladdinCharacter();
	~AladdinCharacter();

	void				Draw();			//

	D3DXVECTOR3			GetPosition();
	void				SetPosition(D3DXVECTOR3 Position);
	void				SetPosition(int X, int Y);

	D3DXVECTOR2			GetVelocity();
	void				SetVelocity(D3DXVECTOR2 Velocity);
	void				SetVelocity(int X, int Y);

protected:
	Sprite*				mSprite;
	int					mStartIdx;		//Index bắt đầu của các Rect chứa các Sprite
	int					mEndIdx;		//
	int					mCurrentIdx;	//Index hiện tại
	D3DXVECTOR3			mPosition;		//Vị trí của Aladdin
	D3DXVECTOR2			mVelocity;		//Vận tốc của Aladdin
	
	void		LoadResource();




};