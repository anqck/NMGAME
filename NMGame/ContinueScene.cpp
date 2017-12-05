#include "ContinueScene.h"
#include "Camera.h"

ContinueScene::ContinueScene()
{
	LoadResource();

	Camera::GetInstance()->SetPosition(0, GLOBAL::GetWindowsHeight());

	mSceneState = ContinueSceneState::Nothing;

	this->mSceneID = SceneID::SceneID_ContinueScene;

	mOpacityRender = false;
	mOpacity = 255;

}

ContinueScene::ContinueScene(AladdinGame * game) : ContinueScene()
{
}

ContinueScene::~ContinueScene()
{
}

void ContinueScene::LoadResource()
{
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
	temp.push_back(MyRECT(0, 0, 226, 63));
	this->mBackground.push_back(new ObjectState(temp, 1, L"Object\\Scene\\ContinueScene\\1.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	temp.push_back(MyRECT(0, 0, 288, 16));
	this->mBackground.push_back(new ObjectState(temp, 1, L"Object\\Scene\\ContinueScene\\2.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	temp.push_back(MyRECT(0, 0, 168, 58));
	this->mBackground.push_back(new ObjectState(temp, 1, L"Object\\Scene\\ContinueScene\\3.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();
	

	//Stand
	temp.push_back(MyRECT(53, 128, 165, 103));
	temp.push_back(MyRECT(0, 90, 131, 47));
	temp.push_back(MyRECT(0, 132, 172, 52, D3DXVECTOR3(1, 0, 0)));
	temp.push_back(MyRECT(0, 0, 44, 53, D3DXVECTOR3(2.65, 0, 0)));
	temp.push_back(MyRECT(0, 0, 44, 53, D3DXVECTOR3(2.65, 0, 0)));
	temp.push_back(MyRECT(0, 0, 44, 53, D3DXVECTOR3(2.65, 0, 0)));
	temp.push_back(MyRECT(0, 0, 44, 53, D3DXVECTOR3(2.65, 0, 0)));
	temp.push_back(MyRECT(0, 0, 44, 53, D3DXVECTOR3(2.65, 0, 0)));
	temp.push_back(MyRECT(0, 0, 44, 53, D3DXVECTOR3(2.65, 0, 0)));
	temp.push_back(MyRECT(0, 173, 213, 52, D3DXVECTOR3(1, 0, 0)));
	temp.push_back(MyRECT(54, 86, 127, 105, D3DXVECTOR3(-0.5, 0, 0)));
	temp.push_back(MyRECT(54, 0, 42, 105, D3DXVECTOR3(-1.5, 0, 0)));
	temp.push_back(MyRECT(0, 45, 89, 53, D3DXVECTOR3(-2.25, 0, 0)));
	temp.push_back(MyRECT(0, 45, 89, 53, D3DXVECTOR3(-2.25, 0, 0)));
	temp.push_back(MyRECT(0, 45, 89, 53, D3DXVECTOR3(-2.25, 0, 0)));
	temp.push_back(MyRECT(0, 45, 89, 53, D3DXVECTOR3(-2.25, 0, 0)));
	temp.push_back(MyRECT(0, 45, 89, 53, D3DXVECTOR3(-2.25, 0, 0)));
	temp.push_back(MyRECT(54, 43, 85, 105, D3DXVECTOR3(-0.5, 0, 0)));

	this->mAladdin.push_back(new ObjectStateWithLoop(temp, 14, L"AladdinCharacter\\AladdinStand.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Walk
	temp.push_back(MyRECT(117, 83, 120, 167));
	temp.push_back(MyRECT(117, 42, 82, 165, D3DXVECTOR3(6, 0, 0)));
	temp.push_back(MyRECT(56, 103, 146, 107, D3DXVECTOR3(8, 0, 0)));
	temp.push_back(MyRECT(0, 0, 55, 58, D3DXVECTOR3(2, 0, 0)));
	temp.push_back(MyRECT(0, 56, 111, 55));
	temp.push_back(MyRECT(0, 159, 203, 57, D3DXVECTOR3(2, 0, 0)));
	temp.push_back(MyRECT(59, 189, 230, 112));
	temp.push_back(MyRECT(58, 147, 188, 115, D3DXVECTOR3(4, 0, 0)));
	temp.push_back(MyRECT(59, 0, 52, 116, D3DXVECTOR3(3, 0, 0)));
	temp.push_back(MyRECT(0, 112, 158, 54));
	temp.push_back(MyRECT(0, 204, 246, 58));
	temp.push_back(MyRECT(117, 0, 41, 169));
	temp.push_back(MyRECT(116, 121, 155, 170));
	temp.push_back(MyRECT(59, 53, 102, 116));

	this->mAladdin.push_back(new ObjectStateWithLoop(temp, 14, L"AladdinCharacter\\AladdinWalk.png", D3DXVECTOR2(0.40f, 0), 3, CenterArchor::CenterBottom));
	temp.clear();

	//MonkeyWait
	temp.push_back(MyRECT(43, 0, 44, 83));
	temp.push_back(MyRECT(43, 0, 44, 83));
	temp.push_back(MyRECT(43, 0, 44, 83));
	temp.push_back(MyRECT(43, 0, 44, 83));
	temp.push_back(MyRECT(43, 0, 44, 83));
	temp.push_back(MyRECT(0, 45, 89, 41));
	temp.push_back(MyRECT(84, 0, 43, 126,D3DXVECTOR3(-1,0,0)));
	temp.push_back(MyRECT(42, 45, 88, 84, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(0, 0, 44, 42, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(0, 0, 44, 42));
	temp.push_back(MyRECT(0, 0, 44, 42));
	temp.push_back(MyRECT(0, 0, 44, 42));
	temp.push_back(MyRECT(0, 0, 44, 42));
	temp.push_back(MyRECT(42, 45, 88, 84, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(84, 0, 43, 126, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(0, 45, 89, 41));

	this->mMonkey.push_back(new ObjectStateWithLoop(temp, 12, L"Object\\Monkey\\Wait.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//MonkeyRun
	temp.push_back(MyRECT(33, 0, 46, 64));
	temp.push_back(MyRECT(0, 53, 103, 34));
	temp.push_back(MyRECT(65, 0, 45, 101));
	temp.push_back(MyRECT(35, 90, 125, 71));
	temp.push_back(MyRECT(69, 46, 86, 106));
	temp.push_back(MyRECT(0, 0, 52, 32));
	temp.push_back(MyRECT(35, 47, 89, 68));
	temp.push_back(MyRECT(72, 87, 113, 105));

	this->mMonkey.push_back(new ObjectStateWithLoop(temp, 12, L"Object\\Monkey\\Run.png", D3DXVECTOR2(0.40f, 0), CenterArchor::CenterBottom));
	temp.clear();


	mAladdinAndMonkeyState = 0;
	mAladdinPosition = D3DXVECTOR3(GLOBAL::GetWindowsWidth()/2, 100, 0);
	mMonkeyPosition = D3DXVECTOR3(GLOBAL::GetWindowsWidth() / 2 + 40, 100, 0);

	this->mBackground.at(0)->SetPosition(D3DXVECTOR3(GLOBAL::GetWindowsWidth() / 2, 350, 0));
	this->mBackground.at(1)->SetPosition(D3DXVECTOR3(GLOBAL::GetWindowsWidth() / 2, 300, 0));
	this->mBackground.at(2)->SetPosition(D3DXVECTOR3(GLOBAL::GetWindowsWidth() / 2, 150, 0));

	this->mAladdin.at(0)->SetPosition(mAladdinPosition);
	this->mAladdin.at(1)->SetPosition(mAladdinPosition);

	this->mMonkey.at(0)->SetPosition(mMonkeyPosition);
	this->mMonkey.at(1)->SetPosition(mMonkeyPosition);
}

void ContinueScene::Update(float DeltaTime)
{
	this->mMonkey.at(mAladdinAndMonkeyState)->Update(DeltaTime);
	this->mAladdin.at(mAladdinAndMonkeyState)->Update(DeltaTime);


	if (this->mSceneState == ContinueSceneState::RunningToRight)
	{
		if (this->mAladdin.at(1)->GetPosition().x >= 900)
		{
			mOpacityRender = true;
		}
	}
	else if (this->mSceneState == ContinueSceneState::RunningToLeft)
	{
		if (this->mAladdin.at(1)->GetPosition().x <= - 100)
		{
			mOpacityRender = true;
		}
	}


		if (mOpacityRender && mOpacity >= 5)
		{
			mOpacity -= 15;
		}
		else
		{
			if (mOpacity <= 0)
			{
				if (this->mSceneState == ContinueSceneState::RunningToLeft)
				{
					this->mSceneState = ContinueSceneState::No;
				}

				else if (this->mSceneState == ContinueSceneState::RunningToRight)
				{
					this->mSceneState = ContinueSceneState::Yes;
				}
			}
		}
	

	
}

void ContinueScene::Render(float DeltaTime)
{
	GraphicsHelper::GetInstance()->GetDirectDevice()->StretchRect(_Surface, NULL, GraphicsHelper::GetInstance()->GetBackBuffer(), NULL, D3DTEXF_NONE);


	for (int i = 0; i < mBackground.size(); i++)
	{
		mBackground.at(i)->OpacityRender(D3DCOLOR_ARGB(mOpacity, 255, 255, 255));
	}

	this->mMonkey.at(mAladdinAndMonkeyState)->OpacityRender(D3DCOLOR_ARGB(mOpacity, 255, 255, 255));
	this->mAladdin.at(mAladdinAndMonkeyState)->OpacityRender(D3DCOLOR_ARGB(mOpacity, 255, 255, 255));

	
	
}

void ContinueScene::OnKeyDown(int keyCode)
{
}

void ContinueScene::OnKeyUp(int keyCode)
{
}

void ContinueScene::ProcessInput()
{
	if (this->mSceneState == ContinueSceneState::Nothing)
	{
		if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_RIGHT))
		{
			this->mSceneState = ContinueSceneState::RunningToRight;
			mAladdinAndMonkeyState = 1;

		}
		else if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_LEFT))
		{
			this->mSceneState = ContinueSceneState::RunningToLeft;
			mAladdinAndMonkeyState = 1;
			this->mAladdin.at(mAladdinAndMonkeyState)->SetFlipVertical(true);
			this->mMonkey.at(mAladdinAndMonkeyState)->SetFlipVertical(true);
		}
	}
	
}

ContinueSceneState ContinueScene::isDone()
{
	return mSceneState;
}
