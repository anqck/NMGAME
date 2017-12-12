#pragma once
#include "AladdinCharacter.h"
#include "Camera.h"
#include "Alphabet.h"
#include "ScoreFont.h"
#include "ShopText.h"
#include "NumberFont.h"

class SceneInformation
{
public:
	SceneInformation();
	SceneInformation(AladdinCharacter* aladdinChar);

	void						LoadResource();

	void						Render();
	void						Update(float DeltaTime);

	ShopText*					GetShopText();

private:
	AladdinCharacter*			mAladdin;

	vector<ObjectState*>		mHeathBar;
	int							mHP;

	ObjectState*				mAppleSprite;
	NumberFont*					mStringAppleCount;
	//Alphabet*					mStringAppleCount;

	//Alphabet*					mString;

	ObjectState*				mGemSprite;
	NumberFont*					mStringGemCount;

	ObjectState*				mLifeSprite;
	NumberFont*					mStringLifeCount;

	
	ScoreFont*					mStringScore;
	
	ShopText*					mShopText;

	int							mLife;

	bool					mAppleOpacityRendered;
	int						mApplemOpacityTime;

	bool					mHPOpacityRendered;
	int						mHPmOpacityTime;

};