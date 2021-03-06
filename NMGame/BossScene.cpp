﻿#include "BossScene.h"

#include "Ground.h"
#include "Wall.h"
#include "Apple.h"
#include "Jafar.h"
#include "JafarBullet.h"
#include "BossFire.h"
#include "FireGround.h"

BossScene::BossScene()
{
	this->mSceneID = SceneID::SceneID_GameSceneBoss;
	SoundHelper::GetInstance()->Stop();
	this->LoadResource();

	mScore = 0;

	mSceneInformation = new SceneInformation(this->mAladdin);
}

BossScene::BossScene(AladdinGame * game) : BossScene()
{
	//this->mGame = game;
}

BossScene::~BossScene()
{
}

void BossScene::LoadResource()
{
	SoundHelper::GetInstance()->Play("BossScene_Background", true, 1);
	
	this->mMap = new BossMap();
	this->mScore = 0;

	this->mAladdin = new AladdinCharacter(D3DXVECTOR3(620, WORLD_Y - 980 +20 , 0));
	this->mJafar = new Jafar(D3DXVECTOR3(1225 -100, WORLD_Y - 1082 + 130, 0), mAladdin);
	//this->mJafar = new Jafar(D3DXVECTOR3(730, WORLD_Y - 980 + 130, 0), mAladdin);
	
	mListObjectInViewPort.push_back(new Ground(MyRECT(WORLD_Y - 1082 + 75, 300, 1955, WORLD_Y - 1085)));

	mListObjectInViewPort.push_back(new Ground(MyRECT(WORLD_Y - 1085 + 240, 500 - 110,710 - 110, WORLD_Y - 1085 +220)));
	mListObjectInViewPort.push_back(new Ground(MyRECT(WORLD_Y - 1085 + 240, 920 - 110, 1130 - 110, WORLD_Y - 1085 + 220)));
	mListObjectInViewPort.push_back(new Ground(MyRECT(WORLD_Y - 1085 + 240, 1345 - 110, 1555 - 110, WORLD_Y - 1085 + 220)));
	mListObjectInViewPort.push_back(new Ground(MyRECT(WORLD_Y - 1085 + 240, 1760 - 110, 1980 - 110, WORLD_Y - 1085 + 220)));

	mListObjectInViewPort.push_back(new FireGround(MyRECT(WORLD_Y - 1085 + 260, 500 - 110, 710 - 110, WORLD_Y - 1085 + 220)));
	mListObjectInViewPort.push_back(new FireGround(MyRECT(WORLD_Y - 1085 + 260, 920 - 110, 1130 - 110, WORLD_Y - 1085 + 220)));
	mListObjectInViewPort.push_back(new FireGround(MyRECT(WORLD_Y - 1085 + 260, 1345 - 110, 1555 - 110, WORLD_Y - 1085 + 220)));
	mListObjectInViewPort.push_back(new FireGround(MyRECT(WORLD_Y - 1085 + 260, 1760 - 110, 1980 - 110, WORLD_Y - 1085 + 220)));
	//mListObjectInViewPort.push_back(new Ground(MyRECT(WORLD_Y - 980 + 240, 500, 710, WORLD_Y - 980 + 220)));
	//mListObjectInViewPort.push_back(new Ground(MyRECT(WORLD_Y - 980 + 240, 500, 710, WORLD_Y - 980 + 220)));

	mListObjectInViewPort.push_back(new Wall(MyRECT(WORLD_Y - 1085 + 1000, 400 - 100, 500 - 110, WORLD_Y - 1085)));
	mListObjectInViewPort.push_back(new Wall(MyRECT(WORLD_Y - 1085 + 1000, 1980 - 110, 2080 - 110, WORLD_Y - 1085)));

	//TempWall
	mListObjectInViewPort.push_back(new Wall(MyRECT(WORLD_Y - 1085 + 1000, 400 - 100, 450 - 110, WORLD_Y - 1085)));
	mListObjectInViewPort.push_back(new Wall(MyRECT(WORLD_Y - 1085 + 1000, 2030 - 110, 2080 - 110, WORLD_Y - 1085)));

	//mListFlyingObject.push_back(new BossFire(D3DXVECTOR3(620, WORLD_Y - 980 + 20, 0), Direction::Left));
	//mListLeftApple.push_back(new Apple(D3DXVECTOR3(955 - 110, WORLD_Y - 1085 + 280,0)));
	//mListLeftApple.push_back(new Apple(D3DXVECTOR3(1007 - 110, WORLD_Y - 1085 + 280, 0)));
	//mListLeftApple.push_back(new Apple(D3DXVECTOR3(981 - 110, WORLD_Y - 1085 + 255, 0)));
	//mListLeftApple.push_back(new Apple(D3DXVECTOR3(981 - 110, WORLD_Y - 1085 + 305, 0)));


	//mListRightApple.push_back(new Apple(D3DXVECTOR3(955 + 400, WORLD_Y - 1085 + 280, 0)));
	//mListRightApple.push_back(new Apple(D3DXVECTOR3(1007 + 400, WORLD_Y - 1085 + 280, 0)));
	//mListRightApple.push_back(new Apple(D3DXVECTOR3(981 + 400, WORLD_Y - 1085 + 255, 0)));
	//mListRightApple.push_back(new Apple(D3DXVECTOR3(981 + 400, WORLD_Y - 1085 + 305, 0)));
	//mListFlyingObject.push_back(new JafarBullet(D3DXVECTOR3(955, WORLD_Y - 980 + 280, 0),this->mAladdin));


}

void BossScene::Update(float DeltaTime)
{
	this->mMap->Update(DeltaTime);

	CheckCollision(DeltaTime);

	this->mAladdin->Update(DeltaTime);
	this->mJafar->Update(DeltaTime);
	for (int i = 0; i < mListObjectInViewPort.size(); i++)
	{
		if (mListObjectInViewPort.at(i)->isDone() == true)
		{
			delete (mListObjectInViewPort.at(i));
			mListObjectInViewPort.erase(mListObjectInViewPort.begin() + i);
			i--;
		}
		else
		{
			if (this->mListObjectInViewPort.at(i)->GetID() == EObjectID::FIREGROUND)
			{
				if (mJafar->GetCurrentStateID() == JafarState::JafarState_Snake)
				{
					mListObjectInViewPort.at(i)->Update(DeltaTime);
				}
			}
			else
				mListObjectInViewPort.at(i)->Update(DeltaTime);
			
		}
			
	}

	for (int i = 0; i < mListFlyingObject.size(); i++)
	{
		if (mListFlyingObject.at(i)->isDone() == true)
		{
			delete (mListFlyingObject.at(i));
			mListFlyingObject.erase(mListFlyingObject.begin() + i);
			i--;
		}
		else
			mListFlyingObject.at(i)->Update(DeltaTime);
	}

	for (int i = 0; i < mListLeftApple.size(); i++)
	{
		if (mListLeftApple.at(i)->isDone() == true)
		{
			delete (mListLeftApple.at(i));
			mListLeftApple.erase(mListLeftApple.begin() + i);
			i--;
		}
		else
			mListLeftApple.at(i)->Update(DeltaTime);
	}

	for (int i = 0; i < mListRightApple.size(); i++)
	{
		if (mListRightApple.at(i)->isDone() == true)
		{
			delete (mListRightApple.at(i));
			mListRightApple.erase(mListRightApple.begin() + i);
			i--;
		}
		else
			mListRightApple.at(i)->Update(DeltaTime);
	}

	Camera::GetInstance()->Update(this->mAladdin);

	mSceneInformation->Update(DeltaTime);

	if ((Camera::GetInstance()->GetPosition().x >= 1007 + 40 || Camera::GetInstance()->GetPosition().x + GLOBAL::GetWindowsWidth() <= 955 - 40) && mListLeftApple.size() == 0 && this->mAladdin->GetAppleCount() == 0)
	{
		mListLeftApple.push_back(new Apple(D3DXVECTOR3(955 - 110, WORLD_Y - 1085 + 280, 0)));
		mListLeftApple.push_back(new Apple(D3DXVECTOR3(1007 - 110, WORLD_Y - 1085 + 280, 0)));
		mListLeftApple.push_back(new Apple(D3DXVECTOR3(981 - 110, WORLD_Y - 1085 + 255, 0)));
		mListLeftApple.push_back(new Apple(D3DXVECTOR3(981 - 110, WORLD_Y - 1085 + 305, 0)));
	}

	if ((Camera::GetInstance()->GetPosition().x >= 1407 + 40 || Camera::GetInstance()->GetPosition().x + GLOBAL::GetWindowsWidth() <= 955 + 400 - 40) && mListRightApple.size() == 0 && this->mAladdin->GetAppleCount() == 0)
	{
		mListRightApple.push_back(new Apple(D3DXVECTOR3(955 + 400, WORLD_Y - 1085 + 280, 0)));
		mListRightApple.push_back(new Apple(D3DXVECTOR3(1007 + 400, WORLD_Y - 1085 + 280, 0)));
		mListRightApple.push_back(new Apple(D3DXVECTOR3(981 + 400, WORLD_Y - 1085 + 255, 0)));
		mListRightApple.push_back(new Apple(D3DXVECTOR3(981 + 400, WORLD_Y - 1085 + 305, 0)));
	}

	
}

void BossScene::Render(float DeltaTime)
{
	

	this->mMap->Render(DeltaTime, MapLevel::MapBackground);
	this->mMap->Render(DeltaTime, MapLevel::MapLevel1);

	this->mJafar->Render(DeltaTime);
	this->mAladdin->Render(DeltaTime);	

	for (int i = 0; i < mListObjectInViewPort.size(); i++)
	{
		mListObjectInViewPort.at(i)->Render(DeltaTime);
	}

	for (int i = 0; i < mListFlyingObject.size(); i++)
	{

		mListFlyingObject.at(i)->Render(DeltaTime);
	}

	for (int i = 0; i < mListLeftApple.size(); i++)
	{
		mListLeftApple.at(i)->Render(DeltaTime);
	}

	for (int i = 0; i < mListRightApple.size(); i++)
	{
		mListRightApple.at(i)->Render(DeltaTime);
	}

	mSceneInformation->Render();
}

void BossScene::OnKeyDown(int keyCode)
{
	this->mAladdin->OnKeyDown(keyCode);
}

void BossScene::OnKeyUp(int keyCode)
{
	this->mAladdin->OnKeyUp(keyCode);
}

void BossScene::ProcessInput()
{
	this->mAladdin->ProcessInput();
}

void BossScene::CheckCollision(float DeltaTime)
{
	//Reset Aladdin Colission flag
	mAladdin->ResetFlagCollision();

	for (int i = 0; i < mListObjectInViewPort.size(); i++)
	{

		//Check collision with Object interact with InteractBB
		if (mListObjectInViewPort.at(i)->GetInteractWithInteractBB())
		{
			mListObjectInViewPort.at(i)->processCollisionAABB(this->mAladdin, this->mAladdin->GetBoundingBox().Intersects(mListObjectInViewPort.at(i)->GetInteractBoundingBox()), CollisionWith::InteractBoundingBox);
		}

		//Check collision with other Object interact with InteractBB
		for (int j = i + 1; j < mListObjectInViewPort.size(); j++)
		{
			if (mListObjectInViewPort.at(j)->GetInteractWithInteractBB() || mListObjectInViewPort.at(i)->GetInteractWithInteractBB())
			{

				//if (Collision::GetSweptBoardphaseBox(mListObjectInViewPort.at(i)->GetBoundingBox(), mListObjectInViewPort.at(i)->GetVelocity(), DeltaTime).Intersects(mListObjectInViewPort.at(j)->GetBoundingBox()) == true)
				{
					CollisionResult res = Collision::SweptAABB(DeltaTime, mListObjectInViewPort.at(i)->GetBoundingBox(), this->mListObjectInViewPort.at(i)->GetVelocity(), mListObjectInViewPort.at(j)->GetBoundingBox(), mListObjectInViewPort.at(j)->GetVelocity());
					if (res.EntryTime < 1 && res.EntryTime >= 0)
					{
						mListObjectInViewPort.at(i)->processCollision(DeltaTime, mListObjectInViewPort.at(j), res);
						mListObjectInViewPort.at(j)->processCollision(DeltaTime, mListObjectInViewPort.at(i), res);
					}
				}
			}

			if (mListObjectInViewPort.at(i)->GetInteractWithInteractBB())
			{
				mListObjectInViewPort.at(i)->processCollisionAABB(this->mAladdin, this->mAladdin->GetBoundingBox().Intersects(mListObjectInViewPort.at(i)->GetInteractBoundingBox()), CollisionWith::InteractBoundingBox);
				if (mListObjectInViewPort.at(j)->GetInteractWithInteractBB())
				{
					mListObjectInViewPort.at(i)->processCollisionAABB(mListObjectInViewPort.at(j), mListObjectInViewPort.at(j)->GetInteractBoundingBox().Intersects(mListObjectInViewPort.at(i)->GetInteractBoundingBox()), CollisionWith::InteractBoundingBox);
					mListObjectInViewPort.at(j)->processCollisionAABB(mListObjectInViewPort.at(i), mListObjectInViewPort.at(j)->GetInteractBoundingBox().Intersects(mListObjectInViewPort.at(i)->GetInteractBoundingBox()), CollisionWith::InteractBoundingBox);
				}
			}
		}



		//Check collision with Object can be attack and Aladdin when attack
		if (this->mListObjectInViewPort.at(i)->GetCanBeAttack())
		{
			if (mAladdin->getCurrentState() == AState::Attack1 || mAladdin->getCurrentState() == AState::SitAttack || mAladdin->getCurrentState() == AState::JumpAttack || mAladdin->getCurrentState() == AState::RunAttack || mAladdin->getCurrentState() == AState::LookUpAttack || mAladdin->getCurrentState() == AState::RopeAttack || mAladdin->getCurrentState() == AState::SwingAttack)
				mListObjectInViewPort.at(i)->processCollisionAABB(this->mAladdin, this->mAladdin->GetAttackBoundingBox().Intersects(mListObjectInViewPort.at(i)->GetBoundingBox()), CollisionWith::SwordBoundingBox);
		}

		//Check collision with Object can Attack Aladdin
		if (this->mListObjectInViewPort.at(i)->GetCanAttack())
		{
			mAladdin->processCollisionAABB(this->mListObjectInViewPort.at(i), this->mListObjectInViewPort.at(i)->GetAttackBoundingBox().Intersects(mAladdin->GetBoundingBox()), CollisionWith::SwordBoundingBox);
		}

		//Check collision with Aladdin

		if (Collision::GetSweptBoardphaseBox(mAladdin->GetBoundingBox(), mAladdin->getCurrentObjectState()->GetVelocity(), DeltaTime).Intersects(this->mListObjectInViewPort.at(i)->GetBoundingBox()) == true)
		{

			if (this->mListObjectInViewPort.at(i)->GetID() == EObjectID::STAIR &&this->mListObjectInViewPort.at(i)->GetStairLayer() == mAladdin->GetStairLayer())
			{
				CollisionResult res = Collision::SweptAABB(DeltaTime, mAladdin->GetBoundingBox(), mAladdin->getCurrentObjectState()->GetVelocity(), this->mListObjectInViewPort.at(i)->GetBoundingBox(), D3DXVECTOR2(0, 0));
				if (res.EntryTime < 1 && res.EntryTime >= 0)
				{
					mListObjectInViewPort.at(i)->processCollision(DeltaTime, mAladdin, res);
					mAladdin->processCollision(DeltaTime, mListObjectInViewPort.at(i), res);
				}
			}

			else
			{
				CollisionResult res = Collision::SweptAABB(DeltaTime, mAladdin->GetBoundingBox(), mAladdin->getCurrentObjectState()->GetVelocity(), this->mListObjectInViewPort.at(i)->GetBoundingBox(), D3DXVECTOR2(0, 0));
				if (res.EntryTime < 1 && res.EntryTime >= 0)
				{

					mListObjectInViewPort.at(i)->processCollision(DeltaTime, mAladdin, res);
					mAladdin->processCollision(DeltaTime, mListObjectInViewPort.at(i), res);
				}
			}

		}



		if (mListObjectInViewPort.at(i)->GetID() != EObjectID::STAIR)
			mAladdin->processCollisionAABB(mListObjectInViewPort.at(i), this->mAladdin->GetBoundingBox().Intersects(mListObjectInViewPort.at(i)->GetBoundingBox()), CollisionWith::BoundingBox);
	}

	//Kiểm tra flying object với các object khác và chính nó
	for (int i = 0; i < mListFlyingObject.size(); i++)
	{
		for (int j = 0; j < mListObjectInViewPort.size(); j++)
		{
			if (mListObjectInViewPort.at(j)->GetInteractWithInteractBB())
			{
				mListFlyingObject.at(i)->processCollisionAABB(mListObjectInViewPort.at(j), mListFlyingObject.at(i)->GetInteractBoundingBox().Intersects(mListObjectInViewPort.at(j)->GetInteractBoundingBox()), CollisionWith::InteractBoundingBox);
			}

			if (mListObjectInViewPort.at(j)->GetCanBeHitByFlyingObject()) //Kiểm tra Object có thể va chạm với flying obj không, giảm số lần kt SweptAABB
			{
				if (mListObjectInViewPort.at(j)->GetCanBeAttack())
				{

					CollisionResult res = Collision::SweptAABB(DeltaTime, mListFlyingObject.at(i)->GetBoundingBox(), this->mListFlyingObject.at(i)->GetCurrentState()->GetVelocity(), mListObjectInViewPort.at(j)->GetBoundingBox(), mListObjectInViewPort.at(j)->GetCurrentState()->GetVelocity());
					if (res.EntryTime < 1 && res.EntryTime >= 0)
					{
						mListFlyingObject.at(i)->processCollision(DeltaTime, mListObjectInViewPort.at(j), res);
						mListObjectInViewPort.at(j)->processCollision(DeltaTime, mListFlyingObject.at(i), res);
					}

				}
				else
				{
					if (Collision::GetSweptBoardphaseBox(mListFlyingObject.at(i)->GetBoundingBox(), this->mListFlyingObject.at(i)->GetCurrentState()->GetVelocity(), DeltaTime).Intersects(mListObjectInViewPort.at(j)->GetBoundingBox()) == true)
					{
						CollisionResult res = Collision::SweptAABB(DeltaTime, mListFlyingObject.at(i)->GetBoundingBox(), this->mListFlyingObject.at(i)->GetCurrentState()->GetVelocity(), mListObjectInViewPort.at(j)->GetBoundingBox(), D3DXVECTOR2(0, 0));
						if (res.EntryTime < 1 && res.EntryTime >= 0)
						{
							mListFlyingObject.at(i)->processCollision(DeltaTime, mListObjectInViewPort.at(j), res);
							mListObjectInViewPort.at(j)->processCollision(DeltaTime, mListFlyingObject.at(i), res);
						}
					}
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

		//Kiểm tra vcham với Aladdin
		if (this->mListFlyingObject.at(i)->GetCanAttack())
		{
			CollisionResult res = Collision::SweptAABB(DeltaTime, this->mListFlyingObject.at(i)->GetBoundingBox(), this->mListFlyingObject.at(i)->GetCurrentState()->GetVelocity(), mAladdin->GetBoundingBox(), mAladdin->getCurrentObjectState()->GetVelocity());
			if (res.EntryTime < 1 && res.EntryTime >= 0)
			{
				mAladdin->processCollision(DeltaTime, this->mListFlyingObject.at(i), res);
				mListFlyingObject.at(i)->processCollision(DeltaTime, mAladdin, res);
			}

			mAladdin->processCollisionAABB(this->mListFlyingObject.at(i), this->mListFlyingObject.at(i)->GetAttackBoundingBox().Intersects(mAladdin->GetBoundingBox()), CollisionWith::SwordBoundingBox);

		}

		//Ktra voi Jafar
		//if (this->mListFlyingObject.at(i)->GetCanAttack())
		{
			CollisionResult res = Collision::SweptAABB(DeltaTime, this->mListFlyingObject.at(i)->GetBoundingBox(), this->mListFlyingObject.at(i)->GetCurrentState()->GetVelocity(), mJafar->GetBoundingBox(),D3DXVECTOR2(0,0));
			if (res.EntryTime < 1 && res.EntryTime >= 0)
			{
				mJafar->processCollision(DeltaTime, this->mListFlyingObject.at(i), res);
				mListFlyingObject.at(i)->processCollision(DeltaTime, mJafar, res);
			}
		}

		//Kiểm tra vc với Aladdin
		if (this->mListFlyingObject.at(i)->GetCanBeAttack())
		{
			if (mAladdin->getCurrentState() == AState::Attack1 || mAladdin->getCurrentState() == AState::SitAttack || mAladdin->getCurrentState() == AState::JumpAttack || mAladdin->getCurrentState() == AState::LookUpAttack || mAladdin->getCurrentState() == AState::RopeAttack || mAladdin->getCurrentState() == AState::SwingAttack)

				mListFlyingObject.at(i)->processCollisionAABB(this->mAladdin, this->mAladdin->GetAttackBoundingBox().Intersects(mListFlyingObject.at(i)->GetBoundingBox()), CollisionWith::SwordBoundingBox);
		}
	}


	for (int i = 0; i < mListLeftApple.size(); i++)
	{
		CollisionResult res = Collision::SweptAABB(DeltaTime, mAladdin->GetBoundingBox(), mAladdin->getCurrentObjectState()->GetVelocity(), this->mListLeftApple.at(i)->GetBoundingBox(), D3DXVECTOR2(0, 0));
		if (res.EntryTime < 1 && res.EntryTime >= 0)
		{

			mListLeftApple.at(i)->processCollision(DeltaTime, mAladdin, res);
			mAladdin->processCollision(DeltaTime, mListLeftApple.at(i), res);
		}
	}

	for (int i = 0; i < mListRightApple.size(); i++)
	{
		CollisionResult res = Collision::SweptAABB(DeltaTime, mAladdin->GetBoundingBox(), mAladdin->getCurrentObjectState()->GetVelocity(), this->mListRightApple.at(i)->GetBoundingBox(), D3DXVECTOR2(0, 0));
		if (res.EntryTime < 1 && res.EntryTime >= 0)
		{

			mListRightApple.at(i)->processCollision(DeltaTime, mAladdin, res);
			mAladdin->processCollision(DeltaTime, mListRightApple.at(i), res);
		}
	}

	mAladdin->processCollisionAABB(this->mJafar, this->mJafar->GetAttackBoundingBox().Intersects(mAladdin->GetBoundingBox()), CollisionWith::SwordBoundingBox);

}

void BossScene::GoToLastCheckPoint()
{
	this->mAladdin->GoToLastCheckPoint();
}

int BossScene::GetAladdinHP()
{
	return this->mAladdin->GetHP();
}

int BossScene::GetAladdinLife()
{
	return this->mAladdin->GetLifeCount();
}



void BossScene::SetScore(int number)
{
}

void BossScene::AddScore(int number)
{
}

void BossScene::AddFlyingObject(GameVisibleEntity * obj)
{
	this->mListFlyingObject.push_back(obj);
}

MyRECT BossScene::GetCenterRegionRECT()
{
	return this->mJafar->GetCenterRegionRECT();
}

Jafar * BossScene::GetJafar()
{
	return this->mJafar;
}
