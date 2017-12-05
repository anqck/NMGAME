#pragma once
#include "Global.h"

enum ShopTextState
{
	ShopTextState_DoNothing,
	ShopTextState_FindsMoreGems,
	ShopTextState_ItsADeal
};
class ShopText
{
public:
	ShopText();
	~ShopText();

	void		Render();
	void		Update(float DeltaTime);

	void		PrintText(ShopTextState text);

	bool		isDone();
private:

	D3DXVECTOR3					mPosition;
	D3DXVECTOR2					mVelocity;

	ShopTextState				mCurrentState;

	LPDIRECT3DTEXTURE9			mTexture0, mTexture1;

	bool						mTextRun;
	bool						mDone;

	float						mShopTextOpacityTime;
	bool						mOpacityRendered;
};