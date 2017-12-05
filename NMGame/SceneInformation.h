#pragma once
#include "AladdinCharacter.h"
#include "Camera.h"
#include "Alphabet.h"
#include "ScoreFont.h"
#include "ShopText.h"

class SceneInformation
{
public:
	SceneInformation();
	SceneInformation(AladdinCharacter* aladdinChar);

	void						LoadResource();

	void						Render();
	void						Update(float DeltaTime);

private:
	AladdinCharacter*			mAladdin;

	vector<ObjectState*>		mHeathBar;
	int							mHP;

	ObjectState*				mAppleSprite;
	Alphabet*					mStringAppleCount;

	//Alphabet*					mString;

	ObjectState*				mGemSprite;
	Alphabet*					mStringGemCount;

	ObjectState*				mLifeSprite;
	Alphabet*					mStringLifeCount;

	int							mScore;
	ScoreFont*					mStringScore;


	int							mLife;

	bool					mAppleOpacityRendered;
	int						mApplemOpacityTime;

};