#pragma once

#ifndef LevelCompleteScene_H
#define LevelCompleteScene_H
#include "IScene.h"
#include "AladdinGame.h"

using namespace std;

class LevelCompleteScene : public IScene
{
public:
	LevelCompleteScene();
	LevelCompleteScene(AladdinGame *game);
	~LevelCompleteScene();

	void					Update(float DeltaTime);
	void					Render(float DeltaTime);
	void					LoadResource();

	void					OnKeyDown(int keyCode);
	void					OnKeyUp(int keyCode);
	void					ProcessInput();

	//bool					isDone();


protected:
	vector<ObjectState*>	mObject;
	bool					mOpacityRender;
	int						mOpacity;

	//bool					mDone;

	LPDIRECT3DSURFACE9			_Surface;
};

#endif