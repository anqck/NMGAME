#include "MenuScene.h"
#include "Camera.h"
#include "SoundHelper.h"


MenuScene::MenuScene()
{
	this->mOpacity = 255;
	this->mOpacityRender = false;

	this->mSceneID = SceneID::SceneID_MenuScene;
	SoundHelper::GetInstance()->Stop();

	LoadResource();

	Camera::GetInstance()->SetPosition(0, GLOBAL::GetWindowsHeight());

	this->mSelectIndex = 0;

	
}

MenuScene::MenuScene(AladdinGame * game) :MenuScene()
{
}

MenuScene::~MenuScene()
{
}

void MenuScene::LoadResource()
{
	SoundHelper::GetInstance()->Play("MenuSelect_Background", true, 1);
	GraphicsHelper::GetInstance()->GetDirectDevice()->CreateOffscreenPlainSurface(
		100,
		100,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&_Surface,
		NULL);

	GraphicsHelper::GetInstance()->GetDirectDevice()->ColorFill(_Surface, NULL, D3DCOLOR_XRGB(0, 0, 0));

	vector<MyRECT> temp;

	//Background
	temp.push_back(MyRECT(0, 0, 320, 256));
	this->mBackground.push_back(new ObjectState(temp, 1, L"Object\\Scene\\MenuScene\\1.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft,D3DXVECTOR2(GLOBAL::GetWindowsWidth()/320.0, GLOBAL::GetWindowsHeight()/256.0)));
	temp.clear();

	temp.push_back(MyRECT(0, 0, 243, 90));
	this->mBackground.push_back(new ObjectState(temp, 1, L"Object\\Scene\\MenuScene\\2.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	temp.push_back(MyRECT(0, 0, 32, 11, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(0, 0, 32, 11, D3DXVECTOR3(2, 0, 0)));
	//temp.push_back(MyRECT(0, 0, 32, 11, D3DXVECTOR3(4, 0, 0)));
	temp.push_back(MyRECT(0, 0, 32, 11, D3DXVECTOR3(6, 0, 0)));
	temp.push_back(MyRECT(0, 0, 32, 11, D3DXVECTOR3(8, 0, 0)));
	temp.push_back(MyRECT(0, 0, 32, 11, D3DXVECTOR3(8, 0, 0)));
	temp.push_back(MyRECT(0, 0, 32, 11, D3DXVECTOR3(6, 0, 0)));
	//temp.push_back(MyRECT(0, 0, 32, 11, D3DXVECTOR3(4, 0, 0)));
	temp.push_back(MyRECT(0, 0, 32, 11, D3DXVECTOR3(2, 0, 0)));
	temp.push_back(MyRECT(0, 0, 32, 11, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(0, 0, 32, 11, D3DXVECTOR3(0, 0, 0)));

	mMenuSelect = new ObjectStateWithLoop(temp, 18, L"Object\\Scene\\MenuScene\\3.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom);

	this->mBackground.at(0)->SetPosition(0, GLOBAL::GetWindowsHeight());
	this->mBackground.at(1)->SetPosition(GLOBAL::GetWindowsWidth()/2, GLOBAL::GetWindowsHeight()/2 + 50 );

	mListString.push_back("SCENE 1");
	mListString.push_back("SCENE BOSS");
	//mListString.push_back("");

	for (int i = 0; i < mListString.size(); i++)
	{
		mString.push_back(new Alphabet(D3DXVECTOR3(GLOBAL::GetWindowsWidth() / 2 - 50, GLOBAL::GetWindowsHeight() / 2 + 10 + STRING_GAP * i, 0), mListString.at(i)));
	}


	
	mMenuSelect->SetPosition(D3DXVECTOR3(GLOBAL::GetWindowsWidth() / 2 - 130, GLOBAL::GetWindowsHeight() / 2 - 43, 0));
}

void MenuScene::Update(float DeltaTime)
{
	mMenuSelect->Update(DeltaTime);

	//mSelectIndex = ((mSelectIndex > mListString.size() - 1) ? 0 : mSelectIndex);
	//mSelectIndex = ((mSelectIndex < 0) ? (mListString.size() - 1) : mSelectIndex);

	if (mSelectIndex >((int)mListString.size() - 1))
		mSelectIndex = 0;
	else if((mSelectIndex < 0))
		mSelectIndex = (mListString.size() - 1);


	mMenuSelect->SetPosition(D3DXVECTOR3(GLOBAL::GetWindowsWidth() / 2 - 130, GLOBAL::GetWindowsHeight() / 2 - 43 - STRING_GAP * mSelectIndex, 0));

	if (mOpacityRender && mOpacity >= 5)
	{
		mOpacity -= 15;
	}
	else
	{
		if (mOpacity <= 0)
		{
			switch (mSelectIndex)
			{
			case 0:
				this->mSceneState = MenuSceneState::MenuSceneState_Scene1;
				break;
			case 1:
				this->mSceneState = MenuSceneState::MenuSceneState_SceneBoss;
				break;
			}
		}
	}
}

void MenuScene::Render(float DeltaTime)
{
	GraphicsHelper::GetInstance()->GetDirectDevice()->StretchRect(_Surface, NULL, GraphicsHelper::GetInstance()->GetBackBuffer(), NULL, D3DTEXF_NONE);

	for (int i = 0; i < mBackground.size(); i++)
	{
		this->mBackground.at(i)->OpacityRender(D3DCOLOR_ARGB(mOpacity, 255, 255, 255));
	}

	for (int i = 0; i < mString.size(); i++)
	{
		this->mString.at(i)->OpacityRender(D3DCOLOR_ARGB(mOpacity, 255, 255, 255));
	}

	mMenuSelect->OpacityRender(D3DCOLOR_ARGB(mOpacity, 255, 255, 255));
}

void MenuScene::OnKeyDown(int keyCode)
{
	switch (keyCode)
			{
			case VK_UP:
				if (!mOpacityRender)
				{
					SoundHelper::GetInstance()->Play("MenuSelect_SelectChange", false, 1);
					this->mSelectIndex--;
				}
					
				break;
			case VK_DOWN:
				if (~mOpacityRender)
				{
					SoundHelper::GetInstance()->Play("MenuSelect_SelectChange", false, 1);
					this->mSelectIndex++;
				}
				break;
			case VK_RETURN:
				switch (mSelectIndex)
				{
				case 0:
				case 1:
					SoundHelper::GetInstance()->Play("MenuSelect_Selected", false, 1);
					mOpacityRender = true;
				}
				break;
			case VK_ESCAPE:
				PostMessage(GLOBAL::GetHWND(), WM_CLOSE, 0, 0);
			}
}

void MenuScene::OnKeyUp(int keyCode)
{
}

void MenuScene::ProcessInput()
{
}

MenuSceneState MenuScene::isDone()
{
	
	return this->mSceneState;
}
