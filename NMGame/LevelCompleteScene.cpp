#include "LevelCompleteScene.h"
#include "Camera.h"

LevelCompleteScene::LevelCompleteScene()
{
	SoundHelper::GetInstance()->Stop();
	LoadResource();

	mOpacityRender = false;
	mOpacity = 255;

	Camera::GetInstance()->SetPosition(0, GLOBAL::GetWindowsHeight());

	mDone = false;

	this->mSceneID = SceneID::SceneID_LevelComplete;
}

LevelCompleteScene::LevelCompleteScene(AladdinGame * game) :LevelCompleteScene()
{
}

LevelCompleteScene::~LevelCompleteScene()
{
}

void LevelCompleteScene::Update(float DeltaTime)
{
	for (int i = 0; i < this->mObject.size(); i++)
	{
		this->mObject.at(i)->Update(DeltaTime);
	}

	if (!mOpacityRender)
	{
		if (this->mObject.at(2)->GetPosition().x <= -480)
		{
			mOpacityRender = true;
		}
	}


}

void LevelCompleteScene::Render(float DeltaTime)
{
	GraphicsHelper::GetInstance()->GetDirectDevice()->StretchRect(_Surface, NULL, GraphicsHelper::GetInstance()->GetBackBuffer(), NULL, D3DTEXF_NONE);

	for (int i = 0; i < this->mObject.size(); i++)
	{

		this->mObject.at(i)->OpacityRender(D3DCOLOR_ARGB(mOpacity, 255, 255, 255));

		if (mOpacityRender && mOpacity >= 5)
		{
			mOpacity -= 15;
		}
		else
		{
			if (mOpacity <= 0)
				mDone = true;
		}
	}
}

void LevelCompleteScene::LoadResource()
{
	SoundHelper::GetInstance()->Play("LevelCompleteScene_Background", true, 1);

	GraphicsHelper::GetInstance()->GetDirectDevice()->CreateOffscreenPlainSurface(
		100,
		100,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&_Surface,
		NULL);

	GraphicsHelper::GetInstance()->GetDirectDevice()->ColorFill(_Surface, NULL, D3DCOLOR_XRGB(0, 0, 0));

	vector<MyRECT> temp;

	//LevelCompleteText
	temp.push_back(MyRECT(0, 0, 232, 141));

	this->mObject.push_back(new ObjectState(temp, 12, L"Object\\Scene\\LevelComplete\\0.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();
	this->mObject.at(0)->SetPosition(D3DXVECTOR3(GLOBAL::GetWindowsWidth() / 2, GLOBAL::GetWindowsHeight() / 2 - 120, 0));

	//Aladdin	
	temp.push_back(MyRECT(62, 166, 201, 119));
	temp.push_back(MyRECT(0, 204, 240, 60));
	temp.push_back(MyRECT(0, 127, 165, 63));
	temp.push_back(MyRECT(0, 50, 98, 59));
	temp.push_back(MyRECT(60, 45, 85, 121));
	temp.push_back(MyRECT(0, 166, 203, 61));
	temp.push_back(MyRECT(64, 127, 164, 123));
	temp.push_back(MyRECT(60, 0, 44, 122));
	temp.push_back(MyRECT(0, 0, 49, 59));
	temp.push_back(MyRECT(60, 86, 126, 121));


	this->mObject.push_back(new ObjectStateWithLoop(temp, 14, L"AladdinCharacter\\LevelComplete.png", D3DXVECTOR2(0.3, 0), CenterArchor::CenterBottom));
	temp.clear();
	this->mObject.at(1)->SetFlipVertical(true);
	this->mObject.at(1)->SetPosition(D3DXVECTOR3(GLOBAL::GetWindowsWidth() + 150, 100, 0));


	//Monkey
	temp.push_back(MyRECT(33, 0, 46, 64));
	temp.push_back(MyRECT(0, 53, 103, 34));
	temp.push_back(MyRECT(65, 0, 45, 101));
	temp.push_back(MyRECT(35, 90, 125, 71));
	temp.push_back(MyRECT(69, 46, 86, 106));
	temp.push_back(MyRECT(0, 0, 52, 32));
	temp.push_back(MyRECT(35, 47, 89, 68));
	temp.push_back(MyRECT(72, 87, 113, 105));

	this->mObject.push_back(new ObjectStateWithLoop(temp, 12, L"Object\\Monkey\\Run.png", D3DXVECTOR2(0.30f, 0), CenterArchor::CenterBottom));
	temp.clear();
	this->mObject.at(2)->SetFlipVertical(true);
	this->mObject.at(2)->SetPosition(D3DXVECTOR3(GLOBAL::GetWindowsWidth(), 100, 0));

	
}

void LevelCompleteScene::OnKeyDown(int keyCode)
{
}

void LevelCompleteScene::OnKeyUp(int keyCode)
{
}

void LevelCompleteScene::ProcessInput()
{
	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_S) || KeyboardHelper::GetInstance()->IsKeyDown(DIK_A) || KeyboardHelper::GetInstance()->IsKeyDown(DIK_D))
	{
		mOpacityRender = true;
	}
}

//bool LevelCompleteScene::isDone()
//{
//	return mDone;
//}
