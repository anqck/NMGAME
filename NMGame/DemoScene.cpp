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
	

	mListObjectInViewPort = mQuadTree->GetListObjectInViewport(Camera::GetInstance()->GetBoundingBoxInWorldAxis());	

	CheckCollision(DeltaTime);

	for (int i = 0; i < mListObjectInViewPort.size(); i++)
	{

		mListObjectInViewPort.at(i)->Update(DeltaTime);
	}

	for (int i = 0; i < mListFlyingObject.size(); i++)
	{
		if (mListFlyingObject.at(i)->isDone() == true)
		{
			delete mListFlyingObject.at(i);
			mListFlyingObject.erase(mListFlyingObject.begin() + i);
			i--;
		}
		else
			mListFlyingObject.at(i)->Update(DeltaTime);
	}

	this->mAladdin->Update(DeltaTime);

	
	
	Camera::GetInstance()->Update(this->mAladdin);	

	
	
	
}

void DemoScene::Render(float DeltaTime)
{
	
	LPDIRECT3DSURFACE9			_Surface;
	GraphicsHelper::GetInstance()->GetDirectDevice()->CreateOffscreenPlainSurface(
		100,
		100,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&_Surface,
		NULL);

	GraphicsHelper::GetInstance()->GetDirectDevice()->ColorFill(_Surface, NULL, D3DCOLOR_XRGB(0, 0, 0));

	GraphicsHelper::GetInstance()->GetDirectDevice()->StretchRect(_Surface,	NULL, GraphicsHelper::GetInstance()->GetBackBuffer(),	NULL,D3DTEXF_NONE);


	this->mMap->Render(DeltaTime,MapLevel::MapLevel1);

	//this->mCamel->Render(DeltaTime);

	
	for (int i = 0; i < mListObjectInViewPort.size(); i++)
	{
		mListObjectInViewPort.at(i)->Render(DeltaTime);
	}

	for (int i = 0; i < mListFlyingObject.size(); i++)
	{
		mListFlyingObject.at(i)->Render(DeltaTime);
	}


	this->mAladdin->Render(DeltaTime);

	this->mMap->Render(DeltaTime, MapLevel::MapLevel2);

}

void DemoScene::LoadResource()
{
	this->mMap = new DemoMap();

	
	D3DXVECTOR3 imagepos; //vector for the position of the sprite

	imagepos.x = 100.0f; //coord x of our sprite
	imagepos.y = WORLD_Y - MAP_HEIGHT + 220; //coord y of out sprite
	imagepos.z = 0.0f; //coord z of out sprite

	this->mAladdin = new AladdinCharacter(imagepos);

	//mCamel = new Camel(D3DXVECTOR3(500, WORLD_Y - MAP_HEIGHT + 90,0));

	//Camera::GetInstance()->SetPosition(100.0f, WORLD_Y - MAP_HEIGHT + 90 );

	mQuadTree = new QuadTree();

	mQuadTree->LoadQuadTree("Map//1.txt");

	//this->mCamel = new Camel(imagepos);
	

}

void DemoScene::OnKeyDown(int keyCode)
{

	this->mAladdin->OnKeyDown(keyCode);

}

void DemoScene::OnKeyUp(int keyCode)
{

	this->mAladdin->OnKeyUp(keyCode);
}

void DemoScene::ProcessInput()
{
	this->mAladdin->ProcessInput();
}

void DemoScene::CheckCollision(float DeltaTime)
{


	//Kiểm tra flying object với các object khác và chính nó
		for (int i = 0; i < mListFlyingObject.size() ; i++)
		{
			for (int j = 0; j < mListObjectInViewPort.size(); j++)
			{
				if (mListObjectInViewPort.at(j)->GetCanBeHitByFlyingObject()) //Kiểm tra Object có thể va chạm với flying obj không, giảm số lần kt SweptAABB
				{
					CollisionResult res = Collision::SweptAABB(DeltaTime, mListFlyingObject.at(i)->GetBoundingBox(), this->mListFlyingObject.at(i)->GetCurrentState()->GetVelocity(), mListObjectInViewPort.at(j)->GetBoundingBox(), D3DXVECTOR2(0, 0));
					if (res.EntryTime < 1 && res.EntryTime >= 0)
					{
						mListFlyingObject.at(i)->processCollision(DeltaTime, mListObjectInViewPort.at(j), res);
						mListObjectInViewPort.at(j)->processCollision(DeltaTime, mListFlyingObject.at(i), res);
					}
				}
			}


			//Kiểm tra với các flying object khác(vd ThrowApple vs ThrowPot) 
			for (int j = 0; j < mListFlyingObject.size(); j++)
			{
				if (i == j)
					continue;

				if (mListFlyingObject.at(j)->GetCanBeHitByFlyingObject()) //Kiểm tra Object có thể va chạm với flying obj không, giảm số lần kt SweptAABB
				{
					CollisionResult res = Collision::SweptAABB(DeltaTime, mListFlyingObject.at(i)->GetBoundingBox(), this->mListFlyingObject.at(i)->GetCurrentState()->GetVelocity(), this->mListFlyingObject.at(j)->GetBoundingBox(), this->mListFlyingObject.at(j)->GetCurrentState()->GetVelocity());
					if (res.EntryTime < 1 && res.EntryTime >= 0)
					{
						mListFlyingObject.at(i)->processCollision(DeltaTime, this->mListFlyingObject.at(j), res);
						mListFlyingObject.at(j)->processCollision(DeltaTime, mListFlyingObject.at(i), res);
					}
				}
			}

			//Kiểm tra vc với Aladdin
			if (this->mListFlyingObject.at(i)->GetCanBeAttack())
			{
				if(mAladdin->getCurrentState() == AState::Attack1 || mAladdin->getCurrentState() == AState::SitAttack || mAladdin->getCurrentState() == AState::JumpAttack)
					mListFlyingObject.at(i)->processCollisionAABB(this->mAladdin, this->mAladdin->GetAttackBoundingBox().Intersects(mListFlyingObject.at(i)->GetBoundingBox()),CollisionWith::SwordBoundingBox);
			}
		}
	

		
		//Reset Aladdin Colission flag
		mAladdin->ResetFlagCollision();

		for (int i = 0; i < mListObjectInViewPort.size(); i++)
		{
			//Check collision with Object interact with InteractBB
			if (mListObjectInViewPort.at(i)->GetInteractWithInteractBB())
			{
				mListObjectInViewPort.at(i)->processCollisionAABB(this->mAladdin, this->mAladdin->GetBoundingBox().Intersects(mListObjectInViewPort.at(i)->GetInteractBoundingBox()), CollisionWith::InteractBoundingBox);
			}

			//Check collision with Object can be attack and Aladdin when attack
			if (this->mListObjectInViewPort.at(i)->GetCanBeAttack())
			{
				if (mAladdin->getCurrentState() == AState::Attack1 || mAladdin->getCurrentState() == AState::SitAttack || mAladdin->getCurrentState() == AState::JumpAttack)
					mListObjectInViewPort.at(i)->processCollisionAABB(this->mAladdin, this->mAladdin->GetAttackBoundingBox().Intersects(mListObjectInViewPort.at(i)->GetBoundingBox()), CollisionWith::SwordBoundingBox);
			}

			//Check collision with Object can Attack Aladdin
			if (this->mListObjectInViewPort.at(i)->GetCanAttack())
			{
					mAladdin->processCollisionAABB(this->mListObjectInViewPort.at(i), this->mListObjectInViewPort.at(i)->GetAttackBoundingBox().Intersects(mAladdin->GetBoundingBox()), CollisionWith::SwordBoundingBox);
			}
			
			//Check collision with Aladdin

			CollisionResult res = Collision::SweptAABB(DeltaTime, mAladdin->GetBoundingBox(), mAladdin->getCurrentObjectState()->GetVelocity(), this->mListObjectInViewPort.at(i)->GetBoundingBox(), D3DXVECTOR2(0,0));
			if (res.EntryTime < 1 && res.EntryTime >= 0)
			{
				mListObjectInViewPort.at(i)->processCollision(DeltaTime, mAladdin, res);
				mAladdin->processCollision(DeltaTime, mListObjectInViewPort.at(i), res);
			}

			mAladdin->processCollisionAABB(mListObjectInViewPort.at(i), this->mAladdin->GetBoundingBox().Intersects(mListObjectInViewPort.at(i)->GetBoundingBox()), CollisionWith::BoundingBox);
		}

		


	/*for (int i = 0; i < mListObjectInViewPort.size(); i++)
	{
		for (int j = j + 1 ; i < mListObjectInViewPort.size() - 1; i++)
		{
			
		}
	}*/
}


void DemoScene::AddFlyingObject(GameVisibleEntity *obj)
{
	mListFlyingObject.push_back(obj);
}
