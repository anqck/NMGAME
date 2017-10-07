#include "DemoScene.h"

DemoScene::DemoScene()
{
}

DemoScene::DemoScene(AladdinGame * game)
{
	this->mGame = game;
	allowAttack = true;
}

DemoScene::~DemoScene()
{
}

void DemoScene::Update(float DeltaTime)
{
	this->mAladdinHelper->Render(DeltaTime);
}

void DemoScene::LoadResource()
{
	D3DXVECTOR3 imagepos; //vector for the position of the sprite

	imagepos.x = 40.0f; //coord x of our sprite
	imagepos.y = 480.0f; //coord y of out sprite
	imagepos.z = 0.0f; //coord z of out sprite

	this->mAladdinHelper = new AladdinHelper(GLOBAL::GetSpriteHandler(), imagepos);
}

void DemoScene::OnKeyDown(int keyCode)
{
	switch (keyCode)
	{
	case VK_SPACE:
		if (allowAttack)
		{
			allowAttack = false;

			if (this->mAladdinHelper->getAladdinState() == AladdinState::Sit)
				this->mAladdinHelper->setAladdinState(AladdinState::SitAttack);
			else
  				this->mAladdinHelper->setAladdinState(AladdinState::Attack1);
		}
		break;
	}
}

void DemoScene::OnKeyUp(int keyCode)
{

	if (keyCode == VK_SPACE)
	{
		allowAttack = true;
		
	}
}

void DemoScene::ProcessInput()
{
	if (this->mGame->IsKeyDown(DIK_RIGHT))
	{
	 this->mAladdinHelper->setAladdinState(AladdinState::Walk);
	 this->mAladdinHelper->setDirection(Direction::Right);
	 this->mAladdinHelper->setAllowStateChange(true);
	 // this->mAladdin->SetVelocity(0.5f, .0f);
	}
	else if (this->mGame->IsKeyDown(DIK_LEFT))
	{
	 this->mAladdinHelper->setAladdinState(AladdinState::Walk);
	 this->mAladdinHelper->setDirection(Direction::Left);
	 this->mAladdinHelper->setAllowStateChange(true);
	// this->mAladdin->SetVelocity(-0.5f, .0f);

	}
	else if (this->mGame->IsKeyDown(DIK_UP))
	{
	 this->mAladdinHelper->setAladdinState(AladdinState::LookUp);
	}
	else if (this->mGame->IsKeyDown(DIK_DOWN))
	{
		
			this->mAladdinHelper->setAladdinState(AladdinState::Sit);
	}
	else if (this->mGame->IsKeyDown(VK_SPACE))
	{
		
		
	}
	else
	{
	 this->mAladdinHelper->setAladdinState(AladdinState::DoNothing);

	}
}
