#include "SceneInformation.h"

SceneInformation::SceneInformation()
{

}

SceneInformation::SceneInformation(AladdinCharacter * aladdinChar)
{
	this->mAladdin = aladdinChar;
	this->LoadResource();

	this->mHP = 8;

	mAppleOpacityRendered = false;
	this->mApplemOpacityTime = 0;

	this->mStringAppleCount = new Alphabet(D3DXVECTOR3(740, 540, 0), std::to_string(aladdinChar->GetAppleCount()));
	this->mStringGemCount = new Alphabet(D3DXVECTOR3(650, 540, 0), std::to_string(aladdinChar->GetGemCount()));
	this->mStringLifeCount = new Alphabet(D3DXVECTOR3(100, 540, 0), std::to_string(aladdinChar->GetLifeCount()));

	mStringScore = new ScoreFont(D3DXVECTOR3(750, 60, 0),"");


	
}

void SceneInformation::LoadResource()
{
	std::vector<MyRECT> temp;


	//0
	temp.push_back(MyRECT(0, 0, 48, 24, D3DXVECTOR3(0, -3, 0)));
	//temp.push_back(MyRECT(0, 0, 48, 24, D3DXVECTOR3(0, -3, 0)));
	this->mHeathBar.push_back(new ObjectState(temp, 13, L"Object\\SceneInformation\\HeathBar\\0.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft));
	temp.clear();


	//1
	temp.push_back(MyRECT(61, 0, 63, 90,D3DXVECTOR3(0,2,0)));
	temp.push_back(MyRECT(91, 0, 63, 120, D3DXVECTOR3(0, 2, 0)));
	temp.push_back(MyRECT(31, 0, 64, 60, D3DXVECTOR3(0, 2, 0)));
	temp.push_back(MyRECT(0, 0, 64, 30,D3DXVECTOR3(0,3,0)));
	this->mHeathBar.push_back(new ObjectStateWithLoop(temp, 13, L"Object\\SceneInformation\\HeathBar\\1.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft));
	temp.clear();

	//2
	temp.push_back(MyRECT(0, 73, 144, 32, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(33, 73, 144, 65, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(0, 0, 72, 32, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(33, 0, 72, 65, D3DXVECTOR3(0, 5, 0)));
	this->mHeathBar.push_back(new ObjectStateWithLoop(temp, 14, L"Object\\SceneInformation\\HeathBar\\2.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft));
	temp.clear();

	//3
	temp.push_back(MyRECT(0, 0, 80, 32, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(33, 0, 80, 65, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(0, 81, 160, 32, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(33, 81, 160, 65, D3DXVECTOR3(0, 5, 0)));
	this->mHeathBar.push_back(new ObjectStateWithLoop(temp, 14, L"Object\\SceneInformation\\HeathBar\\3.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft));
	temp.clear();

	//4
	temp.push_back(MyRECT(0, 0, 88, 32, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(33, 0, 88, 65, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(0, 89, 176, 32, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(33, 89, 176, 65, D3DXVECTOR3(0, 5, 0)));
	this->mHeathBar.push_back(new ObjectStateWithLoop(temp, 14, L"Object\\SceneInformation\\HeathBar\\4.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft));
	temp.clear();

	//5
	temp.push_back(MyRECT(0, 0, 96, 32, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(33, 0, 96, 65, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(0, 97, 192, 32, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(33, 97, 192, 65, D3DXVECTOR3(0, 5, 0)));
	this->mHeathBar.push_back(new ObjectStateWithLoop(temp, 14, L"Object\\SceneInformation\\HeathBar\\5.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft));
	temp.clear();

	//6
	temp.push_back(MyRECT(0, 0, 104, 32, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(33, 0, 104, 65, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(0, 105, 208, 32, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(33, 105, 208, 65, D3DXVECTOR3(0, 5, 0)));
	this->mHeathBar.push_back(new ObjectStateWithLoop(temp, 14, L"Object\\SceneInformation\\HeathBar\\6.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft));
	temp.clear();

	//7
	temp.push_back(MyRECT(0, 0, 112, 32, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(33, 0, 112, 65, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(0, 113, 224, 32, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(33, 113, 224, 65, D3DXVECTOR3(0, 5, 0)));

	this->mHeathBar.push_back(new ObjectStateWithLoop(temp, 14, L"Object\\SceneInformation\\HeathBar\\7.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft));
	temp.clear();

	//8
	temp.push_back(MyRECT(0, 0, 120, 32, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(33, 0, 120, 65, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(0, 121, 240, 32, D3DXVECTOR3(0, 5, 0)));
	temp.push_back(MyRECT(33, 121, 240, 65, D3DXVECTOR3(0, 5, 0)));

	this->mHeathBar.push_back(new ObjectStateWithLoop(temp, 14, L"Object\\SceneInformation\\HeathBar\\8.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft));
	temp.clear();


	temp.push_back(MyRECT(0, 0, 16, 16));
	this->mAppleSprite = new ObjectState(temp, 14, L"Object\\SceneInformation\\Apple.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft,D3DXVECTOR2(2.1,2.3));
	temp.clear();

	temp.push_back(MyRECT(0, 0, 16, 16));
	this->mGemSprite = new ObjectState(temp, 14, L"Object\\SceneInformation\\Gem.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft,D3DXVECTOR2(2.1, 2.1));
	temp.clear();

	temp.push_back(MyRECT(0, 0, 22, 24));
	this->mLifeSprite = new ObjectState(temp, 14, L"Object\\SceneInformation\\Life.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft, D3DXVECTOR2(2.3, 2.3));
	temp.clear();
}

void SceneInformation::Render()
{
	//Score
	if (SceneManager::GetInstance()->GetCurrentScene()->GetScore() != 0)
		mStringScore->Render();

	if(mHP >=0)
		this->mHeathBar.at(mHP )->Render();

	if (mAladdin->GetAppleCount() != 0)
	{
		if (mAladdin->GetAppleCount() <= 5)
		{
			if (mAppleOpacityRendered)
			{
				this->mAppleSprite->OpacityRender(D3DCOLOR_ARGB(0, 255, 255, 255));
				
			}
			else
			{
				this->mAppleSprite->Render();

			}
		}
		else
		{
			this->mAppleSprite->Render();
		}
		
		this->mStringAppleCount->Render();
	}
	

	//Gem Count
	if (mAladdin->GetGemCount() != 0)
	{
		
			
		this->mGemSprite->Render();
		this->mStringGemCount->Render();
	}

	//Life count
	if (mAladdin->GetLifeCount() != 0)
	{


		this->mLifeSprite->Render();
		this->mStringLifeCount->Render();
	}
}

void SceneInformation::Update(float DeltaTime)
{
	this->mStringScore->SetString(std::to_string(SceneManager::GetInstance()->GetCurrentScene()->GetScore()).c_str());

	//OpacityApple
	if (mAladdin->GetAppleCount() <= 5)
	{
		if (mApplemOpacityTime >= 7 * DeltaTime)
		{
			
			if (mAppleOpacityRendered)
			{
				mAppleOpacityRendered = false;
			}
			else
				mAppleOpacityRendered = true;

			mApplemOpacityTime = 0;
		}
		else
			mApplemOpacityTime += DeltaTime;
	}

	mHP = mAladdin->GetHP();

	this->mStringAppleCount->SetString(std::to_string(mAladdin->GetAppleCount()));
	this->mStringGemCount->SetString(std::to_string(mAladdin->GetGemCount()));
	this->mStringLifeCount->SetString(std::to_string(mAladdin->GetLifeCount()));

	if (mHP  >= 0)
	{
		this->mHeathBar.at(mHP )->Update(DeltaTime);
		this->mHeathBar.at(mHP )->SetPosition(Camera::GetInstance()->GetPosition().x + 40, Camera::GetInstance()->GetPosition().y - 45);
	}

	this->mAppleSprite->SetPosition(Camera::GetInstance()->GetPosition().x + 690, Camera::GetInstance()->GetPosition().y - 530);
	this->mGemSprite->SetPosition(Camera::GetInstance()->GetPosition().x + 600, Camera::GetInstance()->GetPosition().y - 532);
	this->mLifeSprite->SetPosition(Camera::GetInstance()->GetPosition().x + 30, Camera::GetInstance()->GetPosition().y - 513);
}


