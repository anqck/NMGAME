#pragma once
#include "AladdinCharacter.h"
#include "Camera.h"
#include "Alphabet.h"

class SceneInformation
{
public:
	SceneInformation();
	SceneInformation(AladdinCharacter* aladdinChar);

	void						LoadResource();

	void						Render();
	void						Update(float DeltaTime);

private:
	AladdinCharacter*		mAladdin;

	vector<ObjectState*>	mHeathBar;
	int						mHP;

	ObjectState*				mAppleSprite;
	Alphabet*					mStringAppleCount;

	int						mScore;

	//ObjectState				mLifeSprite;
	int						mLife;

	bool					mAppleOpacityRendered;
	int						mApplemOpacityTime;

};