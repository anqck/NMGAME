
#pragma once

#ifndef MenuScene_H
#define MenuScene_H
#include "IScene.h"
#include "AladdinGame.h"
#include "Alphabet.h"

using namespace std;

enum MenuSceneState
{
	MenuSceneState_Nothing,
	MenuSceneState_Scene1,
	MenuSceneState_SceneBoss,
	MenuSceneState_Exit
};

#define STRING_GAP 45

class MenuScene : public IScene
{
public:
	MenuScene();
	MenuScene(AladdinGame *game);
	~MenuScene();

	void					LoadResource();

	void					Update(float DeltaTime);
	void					Render(float DeltaTime);


	void					OnKeyDown(int keyCode);
	void					OnKeyUp(int keyCode);
	void					ProcessInput();

	MenuSceneState			isDone();


protected:
	bool					mOpacityRender;
	int						mOpacity;

	vector<ObjectState*>	mBackground;
	
	ObjectState*			mMenuSelect;
	int						mSelectIndex;

	vector<string>			mListString;
	vector<Alphabet*>		mString;

	MenuSceneState			mSceneState;

	LPDIRECT3DSURFACE9			_Surface;

};

#endif
