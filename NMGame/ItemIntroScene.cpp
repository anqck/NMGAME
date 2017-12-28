#include "ItemIntroScene.h"
#include "Camera.h"

ItemIntroScene::ItemIntroScene()
{
	this->mOpacity = 255;
	this->mOpacityRender = false;

	this->mSceneID = SceneID::SceneID_ItemIntro;

	SoundHelper::GetInstance()->Stop();

	LoadResource();

	Camera::GetInstance()->SetPosition(0, GLOBAL::GetWindowsHeight());


	mCurrentIdx = 0;

	mDone = false;
}

ItemIntroScene::ItemIntroScene(AladdinGame * game) : ItemIntroScene()
{
}

ItemIntroScene::~ItemIntroScene()
{
}

void ItemIntroScene::LoadResource()
{
	//SoundHelper::GetInstance()->Play("MenuSelect_Background", true, 1);
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
	temp.push_back(MyRECT(0, 0, 320, 240));
	temp.push_back(MyRECT(0, 0, 320, 240));
	temp.push_back(MyRECT(0, 0, 320, 240));
	temp.push_back(MyRECT(0, 0, 320, 240));
	temp.push_back(MyRECT(0, 0, 320, 240));
	this->mBackground.push_back(new ObjectState(temp, 5, L"Object\\Scene\\ItemIntroScene\\1.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft, D3DXVECTOR2(GLOBAL::GetWindowsWidth() / 320.0, GLOBAL::GetWindowsHeight() / 240.0)));
	temp.clear();


	temp.push_back(MyRECT(0, 0, 320, 240));
	this->mBackground.push_back(new ObjectState(temp, 1, L"Object\\Scene\\ItemIntroScene\\2.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft, D3DXVECTOR2(GLOBAL::GetWindowsWidth() / 320.0, GLOBAL::GetWindowsHeight() / 240.0)));
	temp.clear();

	
	this->mBackground.at(0)->SetPosition(0, GLOBAL::GetWindowsHeight());
	this->mBackground.at(1)->SetPosition(0, GLOBAL::GetWindowsHeight());
	//this->mBackground.at(1)->SetPosition(GLOBAL::GetWindowsWidth() / 2, GLOBAL::GetWindowsHeight() / 2 + 50);


}

void ItemIntroScene::Update(float DeltaTime)
{
	if (this->mBackground.at(mCurrentIdx)->GetCurrentIdx() == this->mBackground.at(mCurrentIdx)->GetEndIdx())
		this->mCurrentIdx = 1;

	this->mBackground.at(mCurrentIdx)->Update(DeltaTime);

	if (mOpacityRender && mOpacity >= 5)
	{
		mOpacity -= 15;
	}
	else
	{
		if (mOpacity <= 0)
		{
			mDone = true;
		}
	}
}

void ItemIntroScene::Render(float DeltaTime)
{
	GraphicsHelper::GetInstance()->GetDirectDevice()->StretchRect(_Surface, NULL, GraphicsHelper::GetInstance()->GetBackBuffer(), NULL, D3DTEXF_NONE);


	this->mBackground.at(mCurrentIdx)->OpacityRender(D3DCOLOR_ARGB(mOpacity, 255, 255, 255));
	
}

bool ItemIntroScene::isDone()
{
	return mDone;
}

void ItemIntroScene::OnKeyDown(int keyCode)
{
	
}

void ItemIntroScene::OnKeyUp(int keyCode)
{

}

void ItemIntroScene::ProcessInput()
{
	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_S) || KeyboardHelper::GetInstance()->IsKeyDown(DIK_A) || KeyboardHelper::GetInstance()->IsKeyDown(DIK_D))
	{
		mDone = true;
	}
}
