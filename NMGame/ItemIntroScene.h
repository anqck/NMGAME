#pragma once

#ifndef ItemIntroScene_H
#define ItemIntroScene_H
#include "IScene.h"
#include "AladdinGame.h"
#include "Alphabet.h"

using namespace std;


class ItemIntroScene : public IScene
{
public:
	ItemIntroScene();
	ItemIntroScene(AladdinGame *game);
	~ItemIntroScene();

	void					LoadResource();

	void					Update(float DeltaTime);
	void					Render(float DeltaTime);

	bool					isDone();

	void					OnKeyDown(int keyCode);
	void					OnKeyUp(int keyCode);
	void					ProcessInput();

protected:
	bool					mOpacityRender;
	int						mOpacity;

	vector<ObjectState*>	mBackground;


	vector<string>			mListString;
	vector<Alphabet*>		mString;

	LPDIRECT3DSURFACE9			_Surface;

	int						mCurrentIdx;

	bool					mDone;

};

#endif