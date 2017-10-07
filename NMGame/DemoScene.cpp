#include "DemoScene.h"

DemoScene::DemoScene()
{
}

DemoScene::DemoScene(AladdinGame * game)
{
	this->mGame = game;
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
		this->mAladdinHelper->setAladdinState(AladdinState::Attack1);
		break;
	}
}

void DemoScene::OnKeyUp(int keyCode)
{
	
}

void DemoScene::ProcessInput()
{
	if (this->mGame->IsKeyDown(DIK_RIGHT))
	{
	 this->mAladdinHelper->setAladdinState(AladdinState::Walk);
	 this->mAladdinHelper->setDirection(Direction::Right);
	// this->mAladdin->SetVelocity(0.5f, .0f);
	}
	else if (this->mGame->IsKeyDown(DIK_LEFT))
	{
	 this->mAladdinHelper->setAladdinState(AladdinState::Walk);
	 this->mAladdinHelper->setDirection(Direction::Left);
	// this->mAladdin->SetVelocity(-0.5f, .0f);

	}
	else if (this->mGame->IsKeyDown(DIK_UP))
	{
	 this->mAladdinHelper->setAladdinState(AladdinState::LookUp);

	}
	else if (this->mGame->IsKeyDown(DIK_X))
	{
	 
	}
	else
	{
	 this->mAladdinHelper->setAladdinState(AladdinState::DoNothing);

	}
}
