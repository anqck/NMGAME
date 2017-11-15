#include "AladdinCharacter.h"

#include"KeyboardHelper.h"

#include <dinput.h>
#include <string> 
#include <stdlib.h>


#pragma region Init
AladdinCharacter::AladdinCharacter()
{
}

AladdinCharacter::AladdinCharacter( D3DXVECTOR3  pos)
{
	LoadResource();


	this->mCurrentState = AState::DoNothing;
	this->mPosition = pos;
	this->mAladdinState.at(mCurrentState)->SetPosition(pos);	
	this->mDir = Direction::Right;
	
	this->mWidth = 25;
	this->mHeight = 120;

	this->mTime = 0;

	this->allowStateChange = true;
	this->allowAttack = true;
	this->allowJump = true;

	this->mIsGrounded = false;
	isClimbing = false;
	mWallCollision = false;

	this->mStoppingDust = NULL;

	mReachTopRope = false;
	
}

void AladdinCharacter::LoadResource()
{

	vector<MyRECT> temp;


	/*this->mWidth = 63 * 2;
	this->mHeight = 48 * 2.5 ;*/

	//DoNothing
	temp.push_back(MyRECT(53, 128, 165, 103));
	this->mAladdinState.push_back(new ObjectState(temp, 10, L"AladdinCharacter\\AladdinStand.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Walk
	temp.push_back(MyRECT(117, 83, 120, 167));
	temp.push_back(MyRECT(117, 42, 82, 165, D3DXVECTOR3(6,0,0)));
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

	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 13, L"AladdinCharacter\\AladdinWalk.png", D3DXVECTOR2(0.7f, 0.0f), 3, CenterArchor::CenterBottom));
	temp.clear();


	//Stop walk
	temp.push_back(MyRECT(0, 56, 110, 52));
	temp.push_back(MyRECT(62, 105, 142, 115, D3DXVECTOR3(5, 0, 0)));
	temp.push_back(MyRECT(53, 53, 104, 115, D3DXVECTOR3(0, 0.7, 0)));
	temp.push_back(MyRECT(0, 111, 154, 61, D3DXVECTOR3(-3.6,0.7,0)));
	temp.push_back(MyRECT(0, 155, 194, 59, D3DXVECTOR3(0.8, 0.7, 0)));
	temp.push_back(MyRECT(0, 0, 55, 38, D3DXVECTOR3(9, 0.8, 0)));
	temp.push_back(MyRECT(39, 0, 52, 75, D3DXVECTOR3(9, 0.8, 0)));
	temp.push_back(MyRECT(0, 195, 231, 44, D3DXVECTOR3(0.9, 0.8, 0)));
	temp.push_back(MyRECT(76, 0, 37, 126));

	//this->mAladdinState.push_back(new ObjectState(temp, 2, L"AladdinCharacter//StopWalk.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	this->mAladdinState.push_back(new ObjectState(temp, 17, L"AladdinCharacter//StopWalk.png", D3DXVECTOR2(0.1, 0), CenterArchor::CenterBottom));
	temp.clear();

	//LookUp
	temp.push_back(MyRECT(60, 39, 76, 110, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(59, 0, 38, 112, D3DXVECTOR3(0.7, - 0.3, 0)));
	temp.push_back(MyRECT(0, 50, 95, 59, D3DXVECTOR3(-1, -0.3, 0)));
	temp.push_back(MyRECT(0, 0, 49, 58, D3DXVECTOR3(-1.5, -0, 0)));

	this->mAladdinState.push_back(new ObjectState(temp, 20, L"AladdinCharacter//LookUp.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//Stand
	temp.push_back(MyRECT(53, 128, 165, 103));
	temp.push_back(MyRECT(0, 90, 131, 47));
	temp.push_back(MyRECT(0, 132, 172, 52, D3DXVECTOR3(1,0,0)));
	temp.push_back(MyRECT(0, 0, 44, 53, D3DXVECTOR3(2.65, 0, 0)));
	temp.push_back(MyRECT(0, 173, 213, 52, D3DXVECTOR3(1, 0, 0)));
	temp.push_back(MyRECT(54, 86, 127, 105, D3DXVECTOR3(-0.5, 0, 0)));
	temp.push_back(MyRECT(54, 0, 42, 105, D3DXVECTOR3(-1.5, 0, 0)));
	temp.push_back(MyRECT(0, 45, 89, 53, D3DXVECTOR3(-2.25, 0, 0)));
	temp.push_back(MyRECT(54, 43, 85, 105, D3DXVECTOR3(-0.5, 0, 0)));

	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 8, L"AladdinCharacter\\AladdinStand.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//Sit
	temp.push_back(MyRECT(36, 49, 86, 86));
	temp.push_back(MyRECT(72, 0, 41, 121, D3DXVECTOR3(-2, 0.4, 0)));
	temp.push_back(MyRECT(31, 0, 48, 71, D3DXVECTOR3(-2, 0.4, 0)));
	temp.push_back(MyRECT(0, 0, 54, 30, D3DXVECTOR3(0.5, -1.2, 0)));
	temp.push_back(MyRECT(0, 55, 108, 35, D3DXVECTOR3(5, -1.2, 0)));

	this->mAladdinState.push_back(new ObjectState(temp, 20, L"AladdinCharacter//AladdinSit.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Rest
	temp.push_back(MyRECT(498, 376, 434, 550));
	this->mAladdinState.push_back(new ObjectState(temp, 20, L"Aladdin.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//SitAttack
	temp.push_back(MyRECT(35, 85, 132, 68, D3DXVECTOR3(4.5, -1.2, 0)));
	temp.push_back(MyRECT(69, 72, 117, 100, D3DXVECTOR3(3.6, -1.2, 0)));
	temp.push_back(MyRECT(69, 0, 71, 102, D3DXVECTOR3(17, -1.2, 0)));
	temp.push_back(MyRECT(0, 0, 92, 34, D3DXVECTOR3(27, -1.2, 0)));
	temp.push_back(MyRECT(35, 0, 84, 68, D3DXVECTOR3(24, -1.2, 0)));
	temp.push_back(MyRECT(0, 93, 164, 33, D3DXVECTOR3(16.6, -1.2, 0)));
	temp.push_back(MyRECT(0, 165, 210, 31, D3DXVECTOR3(4, -1.2, 0)));

	this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinCharacter//SitAttack.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//Attack1
	temp.push_back(MyRECT(54, 204, 241, 104, D3DXVECTOR3(0.2, 0, 0)));
	temp.push_back(MyRECT(54, 106, 151, 105, D3DXVECTOR3(-3.5, 0, 0)));
	temp.push_back(MyRECT(53, 54, 105, 115, D3DXVECTOR3(-3.5, 0, 0)));
	temp.push_back(MyRECT(0, 158, 203, 74));
	temp.push_back(MyRECT(0, 0, 82, 52, D3DXVECTOR3(23, 0, 0)));
	temp.push_back(MyRECT(0, 106, 157, 53));
	temp.push_back(MyRECT(117, 0, 37, 167));
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinCharacter//AladdinAttack.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//RopeClimb
	temp.push_back(MyRECT(0, 86, 118, 63));
	temp.push_back(MyRECT(0, 0, 42, 62));
	temp.push_back(MyRECT(0, 151, 182, 76));
	temp.push_back(MyRECT(153, 29, 57, 234));
	temp.push_back(MyRECT(0, 213, 242, 86));
	temp.push_back(MyRECT(127, 0, 28, 216));
	temp.push_back(MyRECT(77, 120, 148, 156));
	temp.push_back(MyRECT(77, 149, 177, 151));
	temp.push_back(MyRECT(63, 0, 32, 126));
	temp.push_back(MyRECT(0, 43, 85, 62));
	temp.push_back(MyRECT(0, 119, 150, 76));
	temp.push_back(MyRECT(64, 62, 90, 145));
	temp.push_back(MyRECT(0, 183, 212, 86));
	temp.push_back(MyRECT(63, 33, 61, 152));
	temp.push_back(MyRECT(77, 91, 119, 156));
	temp.push_back(MyRECT(146, 62, 90, 220));


	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 13, L"AladdinCharacter//RopeClimb.png", D3DXVECTOR2(0, 0.3), CenterArchor::CenterBottom));
	temp.clear();


	//RunAndJump
	temp.push_back(MyRECT(77, 159, 196, 127));
	temp.push_back(MyRECT(59, 117, 158, 101));
	temp.push_back(MyRECT(0, 175, 220, 76));
	temp.push_back(MyRECT(54, 59, 116, 111));
	temp.push_back(MyRECT(49, 0, 58, 91));
	temp.push_back(MyRECT(49, 0, 58, 91));
	temp.push_back(MyRECT(0, 0, 61, 48));
	temp.push_back(MyRECT(0, 62, 120, 53));
	temp.push_back(MyRECT(0, 121, 174, 58));

	this->mAladdinState.push_back(new ObjectState(temp, 11, L"AladdinAction\\AladdinRunJump.png", D3DXVECTOR2(0, 0.8), D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//Throw apple
	temp.push_back(MyRECT(0, 177, 214, 50));
	temp.push_back(MyRECT(64, 0, 43, 120, D3DXVECTOR3(2.5,0,0)));
	temp.push_back(MyRECT(64, 44, 85, 123, D3DXVECTOR3(1.2, 0, 0)));
	temp.push_back(MyRECT(0, 100, 138, 58));
	temp.push_back(MyRECT(0, 0, 52, 63, D3DXVECTOR3(6.5, 0, 0)));
	temp.push_back(MyRECT(0, 53, 99, 60, D3DXVECTOR3(2.5, 0, 0)));
	temp.push_back(MyRECT(0, 139, 176, 58, D3DXVECTOR3(-1, 0, 0)));
	temp.push_back(MyRECT(61, 86, 125, 113, D3DXVECTOR3(-1, 0, 0)));

	this->mAladdinState.push_back(new ObjectState(temp, 20, L"AladdinCharacter\\Throw.png", D3DXVECTOR2(0, 0), D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Sit Throw
	temp.push_back(MyRECT(38, 58, 111, 73, D3DXVECTOR3(5, -1.2, 0)));
	temp.push_back(MyRECT(38, 0, 57, 75, D3DXVECTOR3(3, -0.2, 0)));
	temp.push_back(MyRECT(0, 150, 187, 44, D3DXVECTOR3(0, -0.2, 0)));
	temp.push_back(MyRECT(0, 112, 149, 48, D3DXVECTOR3(0, -0.2, 0)));
	temp.push_back(MyRECT(74, 58, 108, 122,  D3DXVECTOR3(7, -4.3, 0)));
	temp.push_back(MyRECT(0, 0, 82, 37, D3DXVECTOR3(12, -0.5, 0)));
	temp.push_back(MyRECT(76, 0, 57, 113, D3DXVECTOR3(3, -0.5, 0)));

	this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinCharacter\\SitThrow.png", D3DXVECTOR2(0, 0), D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//RunAttack
	temp.push_back(MyRECT(61, 112, 147, 113));
	temp.push_back(MyRECT(0, 74, 125, 60, D3DXVECTOR3(4, 8, 0)));
	temp.push_back(MyRECT(61, 61, 111, 114, D3DXVECTOR3(5, 8, 0)));
	temp.push_back(MyRECT(0, 126, 174, 60, D3DXVECTOR3(3, 6, 0)));
	temp.push_back(MyRECT(0, 0, 73, 60, D3DXVECTOR3(12, 4, 0)));
	temp.push_back(MyRECT(61, 0, 60, 111, D3DXVECTOR3(12, 2, 0)));
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinAction\\RunAttack.png", D3DXVECTOR2(0.5f, 0.0f), CenterArchor::CenterBottom));
	temp.clear();

	//StandJump
	temp.push_back(MyRECT(107, 55, 96, 154));
	temp.push_back(MyRECT(0, 60, 119, 44));
	temp.push_back(MyRECT(0, 120, 172, 62));
	temp.push_back(MyRECT(45, 55, 109, 106));
	temp.push_back(MyRECT(45, 0, 54, 114));
	temp.push_back(MyRECT(0, 173, 224, 74));
	temp.push_back(MyRECT(63, 110, 148, 129));
	temp.push_back(MyRECT(130, 97, 133, 193));
	temp.push_back(MyRECT(75, 149, 184, 154));
	temp.push_back(MyRECT(75, 185, 219, 168));
	temp.push_back(MyRECT(115, 0, 50, 200));
	temp.push_back(MyRECT(0, 0, 59, 44));
	temp.push_back(MyRECT(155, 51, 88, 205));

	this->mAladdinState.push_back(new ObjectState(temp, 11, L"AladdinCharacter\\StandJump.png", D3DXVECTOR2(0, 0.75f), D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//JumpAttack
	temp.push_back(MyRECT(0, 137, 189, 54));
	temp.push_back(MyRECT(57, 114, 164, 109));
	temp.push_back(MyRECT(0, 190, 237, 66));
	temp.push_back(MyRECT(0, 84, 136, 56));
	temp.push_back(MyRECT(0, 0, 83, 59));
	temp.push_back(MyRECT(60, 60, 113, 118));
	temp.push_back(MyRECT(60, 0, 59, 115));

	this->mAladdinState.push_back(new ObjectState(temp, 14, L"AladdinCharacter\\JumpAttack.png", D3DXVECTOR2(0, 0.8f), D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Push
	temp.push_back(MyRECT(91, 124, 161, 141));
	temp.push_back(MyRECT(90, 67, 123, 136, D3DXVECTOR3(-18, 0.6, 0)));
	temp.push_back(MyRECT(135, 0, 65, 179, D3DXVECTOR3(-24, 0.5, 0)));
	temp.push_back(MyRECT(45, 154, 224, 90, D3DXVECTOR3(-26, -0.5, 0)));
	temp.push_back(MyRECT(45, 0, 77, 89, D3DXVECTOR3(-30, 0.5, 0)));
	temp.push_back(MyRECT(0, 158, 230, 44, D3DXVECTOR3(-27, 0.5, 0)));
	temp.push_back(MyRECT(90, 0, 66, 134, D3DXVECTOR3(-24, 0.5, 0)));
	temp.push_back(MyRECT(0, 82, 157, 44, D3DXVECTOR3(-29, 0.5, 0)));
	temp.push_back(MyRECT(0, 0, 81, 44, D3DXVECTOR3(-32, 0.5, 0)));
	temp.push_back(MyRECT(45, 78, 153, 89, D3DXVECTOR3(-29, 0.5, 0)));

	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 9, L"AladdinCharacter\\Push.png", D3DXVECTOR2(0.2f, 0),2, CenterArchor::CenterBottom));
	temp.clear();

	//LookUp attack
	temp.push_back(MyRECT(141, 98, 135, 191));
	temp.push_back(MyRECT(87, 103, 145, 140));
	temp.push_back(MyRECT(87, 146, 184, 147, D3DXVECTOR3(1,0,0)));
	temp.push_back(MyRECT(0, 75, 140, 61, D3DXVECTOR3(-13.5, 0, 0)));
	temp.push_back(MyRECT(72, 55, 102, 130, D3DXVECTOR3(-4.5, 0, 0)));
	temp.push_back(MyRECT(131, 50, 97, 185, D3DXVECTOR3(-4.5, 0, 0)));
	temp.push_back(MyRECT(72, 0, 54, 120, D3DXVECTOR3(-7.5, 0, 0)));
	temp.push_back(MyRECT(0, 0, 74, 71, D3DXVECTOR3(16, 0, 0)));
	temp.push_back(MyRECT(0, 141, 195, 86, D3DXVECTOR3(5, 0, 0)));
	temp.push_back(MyRECT(121, 0, 49, 192, D3DXVECTOR3(3, 0, 0)));
	temp.push_back(MyRECT(0, 196, 247, 67, D3DXVECTOR3(3, 0, 0)));
	temp.push_back(MyRECT(0, 75, 140, 61, D3DXVECTOR3(-13.5, 0, 0)));
	temp.push_back(MyRECT(72, 55, 102, 130, D3DXVECTOR3(-4.5, 0, 0)));
	temp.push_back(MyRECT(131, 50, 97, 185, D3DXVECTOR3(-4.5, 0, 0)));
	temp.push_back(MyRECT(72, 0, 54, 120, D3DXVECTOR3(-7.5, 0, 0)));
	temp.push_back(MyRECT(0, 0, 74, 71, D3DXVECTOR3(16, 0, 0)));
	temp.push_back(MyRECT(0, 141, 195, 86, D3DXVECTOR3(5, 0, 0)));
	temp.push_back(MyRECT(121, 0, 49, 192, D3DXVECTOR3(3, 0, 0)));
	temp.push_back(MyRECT(0, 196, 247, 67, D3DXVECTOR3(3, 0, 0)));
	temp.push_back(MyRECT(0, 75, 140, 61, D3DXVECTOR3(-13.5, 0, 0)));
	temp.push_back(MyRECT(72, 55, 102, 130, D3DXVECTOR3(-4.5, 0, 0)));
	temp.push_back(MyRECT(131, 50, 97, 185, D3DXVECTOR3(-4.5, 0, 0)));
	this->mAladdinState.push_back(new ObjectState(temp, 14, L"AladdinCharacter\\LookUpAttack.png", D3DXVECTOR2(0.0f, 0.0f), CenterArchor::CenterBottom));
	temp.clear();


	//Jump Throw
	temp.push_back(MyRECT(56, 53, 102, 111));
	temp.push_back(MyRECT(0, 115, 158, 52));
	temp.push_back(MyRECT(56, 103, 142, 109));
	temp.push_back(MyRECT(0, 59, 114, 55));
	temp.push_back(MyRECT(54, 0, 52, 107));
	temp.push_back(MyRECT(0, 159, 199, 52));
	temp.push_back(MyRECT(0, 0, 58, 53));
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinCharacter\\JumpThrow.png", D3DXVECTOR2(0.0f, 0.8f), CenterArchor::CenterBottom));
	temp.clear();


	//Run Throw
	temp.push_back(MyRECT(0, 108, 145, 54));
	temp.push_back(MyRECT(63, 50, 99, 115, D3DXVECTOR3(0,5,0)));
	temp.push_back(MyRECT(63, 0, 49, 116, D3DXVECTOR3(0, 7, 0)));
	temp.push_back(MyRECT(0, 0, 57, 62, D3DXVECTOR3(3,3, 0)));
	temp.push_back(MyRECT(0, 58, 107, 62, D3DXVECTOR3(2, 2, 0)));
	temp.push_back(MyRECT(0, 146, 181, 56, D3DXVECTOR3(8, 1, 0)));
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinCharacter\\RunThrow.png", D3DXVECTOR2(0.5f, 0.0f), CenterArchor::CenterBottom));
	temp.clear();

	//Wait1
	temp.push_back(MyRECT(55, 0, 44, 110, D3DXVECTOR3(3 - 8,0,0)));
	temp.push_back(MyRECT(0, 63, 124, 53, D3DXVECTOR3(3.1 - 8, 1, 0)));
	temp.push_back(MyRECT(0, 0, 62, 54, D3DXVECTOR3(5 - 8, 1, 0)));
	temp.push_back(MyRECT(78, 107, 148, 131, D3DXVECTOR3(9 - 8, 1, 0)));
	temp.push_back(MyRECT(72, 190, 229, 125, D3DXVECTOR3(8 - 8, 1, 0)));
	temp.push_back(MyRECT(132, 165, 201, 185, D3DXVECTOR3(7 - 8, 1, 0)));
	temp.push_back(MyRECT(186, 83, 122, 239, D3DXVECTOR3(8 - 8, 1, 0)));
	temp.push_back(MyRECT(78, 149, 189, 131, D3DXVECTOR3(9 - 8, 1, 0)));
	temp.push_back(MyRECT(174, 0, 41, 229, D3DXVECTOR3(9 - 8, 1, 0)));
	temp.push_back(MyRECT(0, 211, 253, 67, D3DXVECTOR3(10 - 8, 1, 0)));
	temp.push_back(MyRECT(54, 63, 106, 127, D3DXVECTOR3(10 - 8, 1, 0)));
	temp.push_back(MyRECT(0, 125, 167, 77, D3DXVECTOR3(10 - 8, 1, 0)));
	temp.push_back(MyRECT(0, 168, 210, 71, D3DXVECTOR3(10 - 8, 1, 0)));
	temp.push_back(MyRECT(111, 0, 42, 173, D3DXVECTOR3(10 - 8, 1, 0)));
	temp.push_back(MyRECT(128, 43, 84, 182, D3DXVECTOR3(9 - 8, 1, 0)));
	temp.push_back(MyRECT(183, 42, 82, 237, D3DXVECTOR3(9 - 8, 1, 0)));
	temp.push_back(MyRECT(132, 85, 124, 185, D3DXVECTOR3(8 - 8, 1, 0)));
	temp.push_back(MyRECT(132, 125, 164, 185, D3DXVECTOR3(8 - 8, 1, 0)));
	//this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 2, L"AladdinCharacter\\Wait1.png", D3DXVECTOR2(0.0f, 0.0f), 0, CenterArchor::CenterBottom));
	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 13, L"AladdinCharacter\\Wait1.png", D3DXVECTOR2(0.0f, 0.0f),4, CenterArchor::CenterBottom));
	temp.clear();

	//Wait2

	temp.push_back(MyRECT(54, 128, 167, 107, D3DXVECTOR3(0,1,0)));
	temp.push_back(MyRECT(185, 79, 115, 238, D3DXVECTOR3(-1, 1, 0)));
	temp.push_back(MyRECT(0, 128, 168, 53, D3DXVECTOR3(1, 1, 0)));
	temp.push_back(MyRECT(63, 0, 41, 118, D3DXVECTOR3(1, 1, 0)));
	temp.push_back(MyRECT(164, 40, 78, 227, D3DXVECTOR3(0, 1, 0)));
	temp.push_back(MyRECT(0, 86, 127, 67, D3DXVECTOR3(1.2, 1, 0)));
	temp.push_back(MyRECT(0, 43, 85, 58, D3DXVECTOR3(2, 1, 0)));
	temp.push_back(MyRECT(80, 168, 206, 129, D3DXVECTOR3(1.2, 1, 0)));
	temp.push_back(MyRECT(119, 0, 39, 168, D3DXVECTOR3(1, 1, 0)));
	temp.push_back(MyRECT(114, 42, 81, 163, D3DXVECTOR3(1, 1, 0)));
	temp.push_back(MyRECT(108, 126, 164, 162, D3DXVECTOR3(3, 1, 0)));
	temp.push_back(MyRECT(123, 82, 120, 184, D3DXVECTOR3(3, 1, 0)));
	temp.push_back(MyRECT(169, 0, 38, 236, D3DXVECTOR3(3, 1, 0)));
	temp.push_back(MyRECT(163, 121, 157, 237, D3DXVECTOR3(2, 1, 0)));
	temp.push_back(MyRECT(0, 169, 208, 79, D3DXVECTOR3(1, 1, 0)));
	temp.push_back(MyRECT(0, 0, 42, 62, D3DXVECTOR3(1.5, 1, 0)));
	temp.push_back(MyRECT(59, 43, 84, 113, D3DXVECTOR3(0.5, 1, 0)));
	temp.push_back(MyRECT(68, 85, 125, 122, D3DXVECTOR3(0.5, 1, 0)));
	temp.push_back(MyRECT(0, 209, 248, 53, D3DXVECTOR3(-0.5, 1, 0)));
	temp.push_back(MyRECT(54, 209, 248, 107, D3DXVECTOR3(-0.5, 1, 0)));
	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 13, L"AladdinCharacter\\Wait2.png", D3DXVECTOR2(0.0f, 0.0f), 4, CenterArchor::CenterBottom));
	
	temp.clear();

	//Rope Jump
	temp.push_back(MyRECT(110, 0, 34, 183));
	temp.push_back(MyRECT(110, 35, 60, 187));
	temp.push_back(MyRECT(0, 214, 250, 71));
	temp.push_back(MyRECT(42, 60, 108, 106));
	temp.push_back(MyRECT(0, 0, 59, 54));
	temp.push_back(MyRECT(0, 60, 119, 41));
	temp.push_back(MyRECT(55, 0, 52, 109));
	temp.push_back(MyRECT(0, 120, 167, 67));
	temp.push_back(MyRECT(0, 168, 213, 75));
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinCharacter\\RopeJump.png", D3DXVECTOR2(0.0f, 0.8f), CenterArchor::CenterBottom));
	temp.clear();

	//Swing Wait
	temp.push_back(MyRECT(0, 181, 219, 88));
	temp.push_back(MyRECT(0, 140, 180, 88));
	temp.push_back(MyRECT(0, 98, 139, 88));
	temp.push_back(MyRECT(0, 50, 97, 87));
	temp.push_back(MyRECT(0, 0, 49, 88));
	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 13, L"AladdinCharacter\\SwingWait.png", D3DXVECTOR2(0.0f, 0.0f), CenterArchor::CenterBottom));
	temp.clear();

	//Swing Attack
	temp.push_back(MyRECT(92, 105, 153, 179));
	temp.push_back(MyRECT(90, 0, 52, 179));
	temp.push_back(MyRECT(0, 73, 134, 91));
	temp.push_back(MyRECT(92, 53, 104, 182));
	temp.push_back(MyRECT(0, 197, 251, 89));
	temp.push_back(MyRECT(0, 135, 196, 91));
	temp.push_back(MyRECT(0, 0, 72, 89));
	temp.push_back(MyRECT(92, 154, 202, 179));
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinCharacter\\SwingAttack.png", D3DXVECTOR2(0.0f, 0.0f), CenterArchor::CenterBottom));
	temp.clear();

	//Swing Throw
	temp.push_back(MyRECT(0, 152, 189, 87));
	temp.push_back(MyRECT(0, 110, 151, 87));
	temp.push_back(MyRECT(0, 58, 109, 88));
	temp.push_back(MyRECT(0, 190, 221, 89));
	temp.push_back(MyRECT(0, 0, 57, 89));
	temp.push_back(MyRECT(0, 222, 251, 89));
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinCharacter\\SwingThrow.png", D3DXVECTOR2(0.0f, 0.0f), CenterArchor::CenterBottom));
	temp.clear();



	//Swing Move
	temp.push_back(MyRECT(78, 134, 168, 156));
	temp.push_back(MyRECT(81, 0, 47, 162));
	temp.push_back(MyRECT(0, 0, 57, 80));
	temp.push_back(MyRECT(0, 166, 216, 77));
	temp.push_back(MyRECT(163, 0, 43, 246));
	temp.push_back(MyRECT(163, 44, 80, 246));
	temp.push_back(MyRECT(81, 48, 92, 161));
	temp.push_back(MyRECT(0, 113, 165, 77));
	temp.push_back(MyRECT(0, 58, 112, 72));
	temp.push_back(MyRECT(78, 93, 133, 156));

	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 9, L"AladdinCharacter\\SwingMove.png", D3DXVECTOR2(0.0f, 0.0f), CenterArchor::CenterBottom));
	temp.clear();

	//Couple
	temp.push_back(MyRECT(0, 101, 148, 60));
	temp.push_back(MyRECT(0, 149, 196, 60));
	temp.push_back(MyRECT(61, 100, 145, 121));
	temp.push_back(MyRECT(0, 197, 242, 60));
	temp.push_back(MyRECT(61, 146, 191, 120));
	temp.push_back(MyRECT(61, 192, 234, 119));
	temp.push_back(MyRECT(58, 50, 99, 114));
	temp.push_back(MyRECT(0, 51, 100, 57));
	temp.push_back(MyRECT(57, 0, 49, 114));
	temp.push_back(MyRECT(0, 0, 50, 56));

	this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinCharacter\\Couple.png", D3DXVECTOR2(0.0f, 0.0f), CenterArchor::CenterBottom));
	temp.clear();

}

#pragma endregion

#pragma region Update&Render
void AladdinCharacter::Update(float DeltaTime)
{
	this->PrintLogState();	

	this->mAladdinState.at(mCurrentState)->SetFlipVertical((mDir == Direction::Left) ? (true) : (false));

	//this->mAladdinState.at(mCurrentState)->SetVelocity(this->mAladdinState.at(mCurrentState)->GetVelocity().x, -0.5);
	if (this->mCurrentState != AState::RunAndJump && this->mCurrentState != AState::StandJump && this->mCurrentState != AState::JumpAttack && this->mCurrentState != AState::JumpThrow && this->mCurrentState != AState::RopeClimb)
	{
			this->mAladdinState.at(mCurrentState)->SetVelocity(this->mAladdinState.at(mCurrentState)->GetVelocity().x, -0.5);
	}

	if (this->mCurrentState == AState::Push)
	{
		this->mAladdinState.at(mCurrentState)->ResetDefaultVelocity();
	}
	

	switch (this->mCurrentState)
	{
	case AState::DoNothing: //Trường hợp không làm gì
	{
		if (this->mTime >= 50 * DeltaTime)
		{
			this->allowStateChange = true;
			this->setCurrentState(AState::Stand);
			this->mTime = 0;
		}
		else
		{			
			this->mTime += DeltaTime;			
		}
		break;
	}
	case AState::Stand:
		if (this->mTime >= 200 * DeltaTime)
		{
			this->allowStateChange = true;
			this->setCurrentState(AState::Wait1);
			this->mTime = 0;
		}
		else
		{
			this->mTime += DeltaTime;
		}
		break;
	case AState::Wait1:
		if (this->mAladdinState.at(mCurrentState)->isDone()) //Nếu đến frame cuối thì rand chuyển qua hành động wait2
		{
			int randNumber = rand() % 3 ; //33%
			if (randNumber == 0)
			{
				this->allowStateChange = true;
				this->setCurrentState(AState::Wait2);
			}
		}
		break;
	case AState::Wait2:
		if (this->mAladdinState.at(mCurrentState)->isDone()) //Nếu đến frame cuối thì rand chuyển qua hành động wait2
		{
			int randNumber = rand() % 3; //66%
			if (randNumber == 0 || randNumber == 1)
			{
				this->allowStateChange = true;
				this->setCurrentState(AState::Wait1);
			}
		}
		break;
	case AState::Walk: //Trường hợp đang đi
		if (this->mTime >= 30 * DeltaTime)
		{
			this->mIsStopAnimation = true;	//Cờ hiệu cho hành động dừng
		}
		else
		{
			this->mTime += DeltaTime;
		}
	break;
	case AState::RunAndJump:
	{
		//if (!mIsGrounded)
		{
			float vx = (KeyboardHelper::GetInstance()->IsKeyDown(DIK_RIGHT)
				|| KeyboardHelper::GetInstance()->IsKeyDown(DIK_LEFT)) ?
				0.36 : 0;
		

			this->mAladdinState.at(mCurrentState)->SetVelocity(vx, this->mAladdinState.at(mCurrentState)->GetVelocity().y - 0.05);
			//this->mAladdinState.at(mCurrentState)->SetAcceleration(0, -0.05);
		}
		//else
		{
			//this->mAladdinState.at(mCurrentState)->SetVelocity(0,0);
		}

	}
	break;
	case AState::StandJump:
	{
		float vx = (KeyboardHelper::GetInstance()->IsKeyDown(DIK_RIGHT)
			|| KeyboardHelper::GetInstance()->IsKeyDown(DIK_LEFT)) ?
			0.25 : 0;

		this->mAladdinState.at(mCurrentState)->SetVelocity(vx, this->mAladdinState.at(mCurrentState)->GetVelocity().y - 0.04);

	}
	break;
	case AState::JumpThrow:
	case AState::JumpAttack:
	{
		float vx = (KeyboardHelper::GetInstance()->IsKeyDown(DIK_RIGHT)
			|| KeyboardHelper::GetInstance()->IsKeyDown(DIK_LEFT)) ?
			0.3 : 0;

		this->mAladdinState.at(mCurrentState)->SetVelocity(vx, this->mAladdinState.at(mCurrentState)->GetVelocity().y - 0.0555);
		
	}
	break;
	

	
	case AState::ThrowApple:
		if (this->mAladdinState.at(mCurrentState)->GetCurrentIdx() == 3 && this->mAladdinState.at(mCurrentState)->isNextFrame == true)
		{
			mListThrowingApple.push_back(new ThrowingApple(D3DXVECTOR3(this->mAladdinState.at(mCurrentState)->GetPosition().x + ((this->mDir == Direction::Right)? 1: -1) * 40, this->mAladdinState.at(mCurrentState)->GetPosition().y +  125, 0),this->mDir));
		}			
		break;
	case AState::SitThrow:
		if (this->mAladdinState.at(mCurrentState)->GetCurrentIdx() == 3 && this->mAladdinState.at(mCurrentState)->isNextFrame == true)
		{
			mListThrowingApple.push_back(new ThrowingApple(D3DXVECTOR3(this->mAladdinState.at(mCurrentState)->GetPosition().x + ((this->mDir == Direction::Right) ? 1 : -1)* 32, this->mAladdinState.at(mCurrentState)->GetPosition().y +  95 , 0), this->mDir));
		}
		break;
	}


	//Cập nhật bụi khi dừng (nếu có)
	if (this->mStoppingDust != NULL)
	{
		if (mStoppingDust->isDone() == true)
		{
			delete mStoppingDust;
			mStoppingDust = NULL;
			

		}
		else
			this->mStoppingDust->Update(DeltaTime);
	}

	//Kiểm tra danh sách các táo đã ném ra nếu xong thì bỏ khỏi list;
	/*for (int i = 0; i < mListThrowingApple.size(); i++)
	{
		mListThrowingApple.at(i)->Update(DeltaTime);
		if (mListThrowingApple.at(i)->isDone() == true)
		{
			mListThrowingApple.erase(mListThrowingApple.begin() + i);
		}
	}*/

	this->CheckCollisionWithGround(DeltaTime, mListGround);
	this->CheckCollisionWithRope(DeltaTime, mListRope);

		if (this->mCurrentState != AState::RopeClimb)
		{

				this->mAladdinState.at(mCurrentState)->Update(DeltaTime);
		
		}
		else
		{
			if (mReachTopRope == false)
			{
				if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_UP))
				{
					this->mAladdinState.at(this->mCurrentState)->Animate(DeltaTime);
					this->mAladdinState.at(mCurrentState)->MoveVertical(DeltaTime, Direction::Up);
				}
				
			}
			if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_DOWN))
			{
				this->mAladdinState.at(this->mCurrentState)->Animate(DeltaTime);
				this->mAladdinState.at(mCurrentState)->MoveVertical(DeltaTime, Direction::Down);
			}
		}
	

	
	this->mPosition = this->mAladdinState.at(mCurrentState)->GetPosition();


}

void AladdinCharacter::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);
	//this->Transform();
	this->mAladdinState.at(this->mCurrentState)->Render();

	/*for (int i = 0; i < mListThrowingApple.size(); i++)
	{
		mListThrowingApple.at(i)->Render(DeltaTime);
		
	}*/
	

	if (this->mStoppingDust != NULL)
	{
		/*if (mStoppingDust->isDone() == true)
		{
		delete mStoppingDust;
		}*/
		this->mStoppingDust->Render(DeltaTime);
	}
}

#pragma endregion

#pragma region Keyboard
void AladdinCharacter::OnKeyDown(int keyCode)
{

	switch (keyCode)
	{
	case VK_SPACE:
		this->mPosition = D3DXVECTOR3(100, WORLD_Y - MAP_HEIGHT + 220, 0);
		this->mAladdinState.at(this->mCurrentState)->SetPosition(this->mPosition);
		break;
	case VK_RIGHT:
		this->setDirection(Direction::Right);		
		break;
	case VK_LEFT:
		this->setDirection(Direction::Left);
		break;	
	case VK_ESCAPE:
		PostMessage(GLOBAL::GetHWND(), WM_CLOSE, 0, 0);
	}
}

void AladdinCharacter::OnKeyUp(int keyCode)
{
	if(keyCode	== 83) //S
		this->allowAttack = true;

	if (keyCode == 65) //A
		this->allowAttack = true;
	
	if (keyCode == 68) //D
		this->allowJump = true;

}

void AladdinCharacter::ProcessInput()
{
	flagKeyPressed = false;
	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_RIGHT) || KeyboardHelper::GetInstance()->IsKeyDown(DIK_LEFT))
	{
		this->mAladdinState.at(mCurrentState)->SetFlipVertical((mDir == Direction::Left) ? (true) : (false));
		switch (this->mCurrentState)
		{
		case AState::Sit:
		case AState::LookUp:
			flagKeyPressed = true;
			this->setAllowStateChange(true);
			this->setCurrentState(AState::Walk);
			break;
		case AState::RopeClimb:
		case AState::RunAttack: //Chuyển từ chạy đánh sang chạy
		case AState::RunThrow:
			flagKeyPressed = true;
			if (this->mAladdinState.at(mCurrentState)->isDone())
			{				
				this->setAllowStateChange(true);
				this->setCurrentState(AState::Walk);
			}
			break;
		case AState::StandJump:
		case AState::RunAndJump:
		case AState::JumpAttack:
		case AState::JumpThrow:
			break;
		default:
			if (mWallCollision == false)
			{
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::Walk);
			}
			else
			{
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::Push);
			}

		}			
	}

	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_UP))
	{
		switch (this->mCurrentState)
		{
		case AState::Sit:
		case AState::RopeClimb:
		case AState::StandJump:
		case AState::RunAndJump:
		case AState::JumpAttack:
		case AState::JumpThrow:
			break;
		case AState::LookUpAttack:
		{
			flagKeyPressed = true;
			if (this->mAladdinState.at(mCurrentState)->isDone())
			{
				this->setAllowStateChange(true);
				this->setCurrentState(AState::LookUp);
			}
		}
			break;
		case AState::ThrowApple:
			if (this->mAladdinState.at(mCurrentState)->isDone())
			{
				this->setAllowStateChange(true);
				this->setCurrentState(AState::LookUp);
			}
			break;
		default:
			flagKeyPressed = true;
			this->setAllowStateChange(true);
			this->setCurrentState(AState::LookUp);
		}
	}

	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_DOWN))
	{
		
		switch (this->mCurrentState)
		{
		case AState::SitAttack:
		case AState::SitThrow:
			if (this->mAladdinState.at(mCurrentState)->isDone())
			{
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::Sit);
			}

			break;
		case AState::StandJump:
		case AState::RunAndJump:
		case AState::JumpThrow:
		case AState::JumpAttack:
		case AState::RopeClimb:
			break;
		default:
			flagKeyPressed = true;
			this->setAllowStateChange(true);
			this->setCurrentState(AState::Sit);
		}
	}

	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_A))
	{
		switch (this->mCurrentState)
		{
		case AState::RopeClimb:
		case AState::ThrowApple:
		case AState::SitThrow:
			break;
		case AState::RunAttack:
		case AState::Walk:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::RunThrow);
			}
			break;
		case AState::StandJump:
		case AState::JumpAttack:
		case AState::RunAndJump:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::JumpThrow);
			}
			break;
		case AState::SitAttack:
		case AState::Sit:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::SitThrow);

				break;
			}

		default:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::ThrowApple);

				break;
			}
		}
	}
	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_S))
	{
		switch (this->mCurrentState)
		{
		case AState::RunAttack:
		case AState::Attack1:
		case AState::JumpAttack:
		case AState::SitAttack:
		case AState::LookUpAttack:
		case AState::RopeClimb:
			break;
		case AState::LookUp:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::LookUpAttack);				
			}
			break;
		case AState::Walk:
		case AState::RunThrow:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::RunAttack);				
			}
			break;
		case AState::StandJump:
		case AState::JumpThrow:
		case AState::RunAndJump:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::JumpAttack);				
			}
			break;
		case AState::SitThrow:
		case AState::Sit:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::SitAttack);				
			}
			break;
		default:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::Attack1);				
			}			
			break;
		}
	}
	

	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_D))
	{
		switch (this->mCurrentState)
		{
		case AState::Stand:
		case AState::DoNothing:
			if (allowJump)
			{
				mIsGrounded = false;
				allowJump = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::StandJump);
				break;
			}
			break;
		case AState::RopeClimb:
		case AState::Walk:
		case AState::Push:
			if(allowJump)
			{
				mIsGrounded = false;
				allowJump = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::RunAndJump);
				break;
			}
		case AState::SitAttack:
			break;
		default:
	
			break;
		}
	}

	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_Z))
	{
		flagKeyPressed = true;
		this->setAllowStateChange(true);
		this->setCurrentState(AState::Couple);

	}

	if (flagKeyPressed == false)
	{
		switch (this->mCurrentState)
		{

		case AState::Attack1:
		case AState::StopWalk:
		case AState::SitAttack:
		case AState::ThrowApple:
		case AState::LookUpAttack:
		case AState::SitThrow:
			if (this->mAladdinState.at(mCurrentState)->isDone())
			{
				this->setAllowStateChange(true);
				this->setCurrentState(AState::DoNothing);
			}
			break;
		case AState::JumpThrow:
		case AState::JumpAttack:
			if (this->mAladdinState.at(mCurrentState)->isDone())
			{
				this->setAllowStateChange(true);
				this->setCurrentState(AState::RunAndJump);
			}
			else if (isGrounded() == true)
			{
				this->allowStateChange = true;
				this->setCurrentState(AState::DoNothing);
			}
			break;
		case AState::Stand:
		case AState::Wait1:
		case AState::Wait2:
			break;
		case AState::RopeClimb:
			if (mRopeIntersects == false)
			{
				this->allowStateChange = true;
				this->setCurrentState(AState::DoNothing);
			}
			break;
		case AState::StandJump:
		case AState::RunAndJump:
			if (isGrounded() == true)
			{
				this->allowStateChange = true;
				this->setCurrentState(AState::DoNothing);
			}
			else if (mRopeCollision == true)
			{
				this->allowStateChange = true;
				this->setCurrentState(AState::RopeClimb);
			}
			break;
		default:

			this->setAllowStateChange(true);
			this->setCurrentState(AState::DoNothing);
			break;
		}
	}

	
}

#pragma endregion

#pragma region StateChange
void AladdinCharacter::setCurrentState(AState state)
{
	//Kiểm tra xem state thay đổi có khác state hiện tại
	if (this->mCurrentState == state)
	{
		return;
	}
		


	//Kiểm tra biến cho phép sự thay đổi
	if (this->allowStateChange == false)
		return;
	else
		this->allowStateChange = false;

	this->_BeforeStateChange(state);

	this->mCurrentState = state;

	this->_AfterStateChange();

}

ObjectState * AladdinCharacter::getCurrentObjectState()
{
	return this->mAladdinState.at(mCurrentState);
}

void AladdinCharacter::_BeforeStateChange(AState &changeTo)
{	

	//Khi chuyển từ hành động chạy sang hành động đứng và biến cờ hiệu hành động dừng
	if ((this->mCurrentState == AState::Walk) && (changeTo == AState::DoNothing) && (this->mIsStopAnimation == true))
	{
		changeTo = AState::StopWalk;
		this->mIsStopAnimation = false;

		//Hiệu ứng bụi khi dừng chạy
		mStoppingDust = new StoppingDust(D3DXVECTOR3(this->mAladdinState.at(this->mCurrentState)->GetPosition().x + ((mDir == Direction::Right) ? (1) : (-1)) * 78, this->mAladdinState.at(this->mCurrentState)->GetPosition().y,0), this->mDir);
	}
	
	//Khi chuyển từ SitAttack qua Sit thì set frame cuối cùng
	if ((this->mCurrentState == AState::SitAttack || this->mCurrentState == AState::SitThrow) && (changeTo == AState::Sit) )
	{
		this->mAladdinState.at(AState::Sit)->GoToLastFrameIdx();
		this->allowStateChange = true;
	}

	//Khi chuyển từ RunAttack và RunThrow qua Walk thì set frame cuối cùng
	if ((this->mCurrentState == AState::RunAttack || this->mCurrentState == AState::RunThrow) && (changeTo == AState::Walk))
	{
		this->mAladdinState.at(AState::Walk)->GoToFrame(12);
	}

	//Thay vị trí hiện tại cho state khác
	this->mPosition = this->mAladdinState.at(this->mCurrentState)->GetPosition();
	this->mAladdinState.at(changeTo)->SetPosition(this->mPosition);
	
	//Reset lại frame idx của state cũ
	this->mAladdinState.at(this->mCurrentState)->resetFrame();

	/*if (mCurrentState != AState::RopeClimb)
		isClimbing = false;*/
	
	//Nếu chuyển hành động nhảy này sáng hành động nhảy khác thì lấy vận tốc của hành động nhảy trước đó
	if ((mCurrentState == AState::RunAndJump || mCurrentState == AState::StandJump || mCurrentState == AState::JumpAttack || mCurrentState == AState::JumpThrow) && (changeTo == AState::JumpAttack || changeTo == AState::JumpThrow))
		this->mAladdinState.at(changeTo)->SetVelocity(0,this->mAladdinState.at(mCurrentState)->GetVelocity().y);
	else if ((mCurrentState == AState::JumpAttack || mCurrentState == AState::JumpThrow ) && changeTo == AState::RunAndJump)
	{
		this->mAladdinState.at(changeTo)->SetVelocity(0, this->mAladdinState.at(mCurrentState)->GetVelocity().y);
		this->mAladdinState.at(changeTo)->GoToFrame(4);
	}

	//Nếu từ Wait2 chuyển lại Wait1 thì đến frame bắt đầu loop
	if (this->mCurrentState == AState::Wait2 && changeTo == AState::Wait1)
	{
		this->mAladdinState.at(changeTo)->GoToFrame(4);
	}

	this->mAladdinState.at(mCurrentState)->ResetDefaultVelocity();
}

void AladdinCharacter::_AfterStateChange()
{
	
	//this->mAladdinState.at(mCurrentState)->SetVelocity(this->mAladdinState.at(mCurrentState)->GetVelocity().x, -10);
	switch (this->mCurrentState)
	{
	case AState::DoNothing:
	case AState::Stand:
		this->mTime = 0;
		break;
	case AState::Walk:
		this->mTime = 0;
		break;
	case AState::RunAndJump:
		this->mTime = 0;
		break;
	}
}

#pragma endregion

#pragma region GetSet

Direction AladdinCharacter::getDirection()
{
	return this->mDir;
}

void AladdinCharacter::setDirection(Direction dir)
{
	mDir = dir;
}

void AladdinCharacter::setAllowStateChange(bool allow)
{
	this->allowStateChange = allow;
}

bool AladdinCharacter::isGrounded()
{
	return this->mIsGrounded;
}

void AladdinCharacter::SetGrounded(bool allow)
{
	this->mIsGrounded = allow;
}



MyRECT AladdinCharacter::GetBoundingBox()
{
	mBoundingBox.left = mPosition.x - mWidth / 2;
	mBoundingBox.right = mPosition.x + mWidth / 2;

	/*mBoundingBox.top = mPosition.y - mHeight / 2;
	mBoundingBox.bottom = mPosition.y + mHeight / 2;*/

	mBoundingBox.top = mPosition.y + mHeight;
	mBoundingBox.bottom = mPosition.y;


	return mBoundingBox;;
}

AState AladdinCharacter::getCurrentState()
{
	return this->mCurrentState;
}

#pragma endregion

#pragma region Collision

void AladdinCharacter::CheckCollision(float DeltaTime, vector<GameVisibleEntity*> mListObjectInViewPort)
{
	//vector<GameVisibleEntity*> mListGround;

	mListGround.clear();
	mListRope.clear();

	for (int i = 0; i < mListObjectInViewPort.size(); i++)
	{
		switch (mListObjectInViewPort.at(i)->GetID())
		{
		case EObjectID::GROUND: //Kiểm tra va chạm với đất
			mListGround.push_back(mListObjectInViewPort.at(i));
			break;
		case EObjectID::ROPE:
			mListRope.push_back(mListObjectInViewPort.at(i));
			break;
		case EObjectID::CAMEL:
			CollisionResult res = Collision::SweptAABB(DeltaTime, this->GetBoundingBox(), this->mAladdinState.at(mCurrentState)->GetVelocity(), mListObjectInViewPort.at(i)->GetBoundingBox(), D3DXVECTOR2(0, 0));
			if (res.EntryTime < 1 && res.EntryTime >= 0)
			{
				int c = 0;
			}
			break;
		}
	}

	//this->CheckCollisionWithGround(DeltaTime,mListGround);
	
}

void AladdinCharacter::processCollision(float DeltaTime,GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::GROUND:
	
		if (collision.dir == Direction::Up)
		{
			_yCollision = this->mAladdinState.at(mCurrentState)->GetVelocity().y*collision.EntryTime;

			this->mAladdinState.at(mCurrentState)->SetVelocity(this->mAladdinState.at(mCurrentState)->GetVelocity().x, _yCollision);
			mIsGrounded = true;
			//this->mAladdinState.at(mCurrentState)->SetPosition(this->mAladdinState.at(mCurrentState)->GetPosition().x, this->mAladdinState.at(mCurrentState)->GetPosition().y + _yCollision * DeltaTime);
			//this->mPosition = this->mAladdinState.at(mCurrentState)->GetPosition();

		}
		else  if (collision.dir == Direction::Left || collision.dir == Direction::Right)
		{
			mWallCollision = true;

			this->mAladdinState.at(mCurrentState)->SetVelocity(this->mAladdinState.at(mCurrentState)->GetVelocity().x*collision.EntryTime , this->mAladdinState.at(mCurrentState)->GetVelocity().y);
			//this->mAladdinState.at(mCurrentState)->SetPosition(this->mAladdinState.at(mCurrentState)->GetPosition().x + this->mAladdinState.at(mCurrentState)->GetVelocity().x*collision.EntryTime , this->mAladdinState.at(mCurrentState)->GetPosition().y);
			

			this->mPosition = this->mAladdinState.at(mCurrentState)->GetPosition();
		}
		break;
	
	case EObjectID::ROPE:
		if (collision.dir == Direction::Left || collision.dir == Direction::Right)
		{
			
			mRopeCollision = true;
			//(obj->GetBoundingBox().right - obj->GetBoundingBox().left) / 2
			this->mAladdinState.at(mCurrentState)->SetPosition(this->mAladdinState.at(mCurrentState)->GetPosition().x + ((mDir == Direction::Right) ? (1) : (-1))  * (this->mWidth / 2 + (obj->GetBoundingBox().right - obj->GetBoundingBox().left)/2) , this->mAladdinState.at(mCurrentState)->GetPosition().y);
			this->mAladdinState.at(mCurrentState)->SetVelocity(this->mAladdinState.at(mCurrentState)->GetVelocity().x*collision.EntryTime , this->mAladdinState.at(mCurrentState)->GetVelocity().y);
			this->mPosition = this->mAladdinState.at(mCurrentState)->GetPosition();

			this->mAladdinState.at(AState::RopeClimb)->SetPosition(this->mPosition);
		}
		break;
	}
	
}

void AladdinCharacter::CheckCollisionWithGround(float DeltaTime, vector<GameVisibleEntity*> mListGround)
{
	mIsGrounded = false;
	mWallCollision = false;

	for (int i = 0; i < mListGround.size(); i++)
	{
		CollisionResult res = Collision::SweptAABB(DeltaTime, this->GetBoundingBox(), this->getCurrentObjectState()->GetVelocity(), mListGround.at(i)->GetBoundingBox(), D3DXVECTOR2(0, 0));
		if (res.EntryTime < 1 && res.EntryTime >= 0)
		{
			this->processCollision(DeltaTime, mListGround.at(i), res);
			//_StandingGround = mListGround.at(i);
			
		}
	/*	else if (this->mBoundingBox.bottom == mListGround.at(i)->GetBoundingBox().top && this->mBoundingBox.left >= mListGround.at(i)->GetBoundingBox().left && this->mBoundingBox.right <= mListGround.at(i)->GetBoundingBox().right && this->mCurrentState != AState::RunAndJump)
		{
			mIsGrounded = true;
		}*/

	}
	
}

void AladdinCharacter::CheckCollisionWithRope(float DeltaTime, vector<GameVisibleEntity*> mListRope)
{
	mRopeCollision = false;
	mRopeIntersects = false;

	for (int i = 0; i < mListRope.size(); i++)
	{
		CollisionResult res = Collision::SweptAABB(DeltaTime, this->GetBoundingBox(), this->getCurrentObjectState()->GetVelocity(), mListRope.at(i)->GetBoundingBox(), D3DXVECTOR2(0, 0));
		if (res.EntryTime < 1 && res.EntryTime >= 0)
		{
			this->processCollision(DeltaTime, mListRope.at(i), res);
		}
		else if (this->GetBoundingBox().Intersects(mListRope.at(i)->GetBoundingBox()))
		{
			mRopeIntersects = true;
			//mRopeCollision = true;

			if (this->GetBoundingBox().top >= mListRope.at(i)->GetBoundingBox().top - 10 && this->GetBoundingBox().top <= mListRope.at(i)->GetBoundingBox().top)
			{
				mReachTopRope = true;				
			}
			else
			{
				mReachTopRope = false;
			}
		}
	}
}

#pragma endregion

#pragma region Debug

void AladdinCharacter::PrintLogState()
{
	switch (this->mCurrentState)
	{
	case AState::DoNothing:
		printLog("DoNothing");
		break;
	case AState::Walk:
		printLog("Walk");
		break;
	case AState::StopWalk:
		printLog("StopWalk");
		break;
	case AState::LookUp:
		printLog("LookUp");
		break;
	case AState::Attack1:
		printLog("Attack1");
		break;
	case AState::Stand:
		printLog("Stand");
		break;
	case AState::Sit:
		printLog("Sit");
		break;
	case AState::SitAttack:
		printLog("SitAttack");
		break;
	case AState::RunAndJump:
		printLog("RunAndJump");
		break;
	case AState::ThrowApple:
		printLog("ThrowApple");
		break;
	case AState::SitThrow:
		printLog("SitThrow");
		break;
	case AState::Push:
		printLog("Push");
		break;
	case AState::RunAttack:
		printLog("Run Attack");
		break;
	case AState::RunThrow:
		printLog("Run Throw");
		break;
	case AState::RopeClimb:
		printLog("Rope Climb");
		break;
	default:
		printLog("Else");

		break;
	}
}

#pragma endregion





