#include "SoundHelper.h"
#include "GameLog.h"

SoundHelper*		SoundHelper::mInstance = NULL;

SoundHelper::~SoundHelper()
{
	for (auto it = soundBufferMap.begin(); it != soundBufferMap.end(); it++)
	{
		if (it->second)
		{
			it->second->Release();
			it->second = NULL;
		}

	}
	if (primaryBuffer)
		primaryBuffer->Release();
	if (pDevice)
		pDevice->Release();
	pDevice = NULL;

	primaryBuffer = NULL;
}

SoundHelper * SoundHelper::GetInstance()
{
	if (!mInstance)
		SoundHelper::mInstance = new SoundHelper();

	return SoundHelper::mInstance;
}

void SoundHelper::Initialize()
{
	primaryBuffer = 0;
	HRESULT result;

	DSBUFFERDESC bufferDesc; //describe the buffer

	result = DirectSoundCreate8(NULL, &pDevice, NULL);

	if (FAILED(result))
	{
		printLog("Can not create device");
	}

	result = pDevice->SetCooperativeLevel(GLOBAL::GetHWND(), DSSCL_PRIORITY); // set the cooperative level.

	bufferDesc.dwSize = sizeof(DSBUFFERDESC);
	bufferDesc.dwFlags = DSBCAPS_PRIMARYBUFFER | DSBCAPS_CTRLVOLUME;
	bufferDesc.dwBufferBytes = 0;
	bufferDesc.dwReserved = 0;
	bufferDesc.lpwfxFormat = NULL;
	bufferDesc.guid3DAlgorithm = GUID_NULL;

	result = pDevice->CreateSoundBuffer(&bufferDesc, &primaryBuffer, NULL);

	if (FAILED(result))
	{
		GAMELOG("Can not create primaryBuffer");
	}
	mVolume = 100.0f;
	isMute = false;

	LoadResource();
}

void SoundHelper::LoadResource()
{
	this->LoadSound("Sound\\MenuSelect_Background.wav", "MenuSelect_Background");
	this->LoadSound("Sound\\MenuSelect_SelectChange.wav", "MenuSelect_SelectChange");
	this->LoadSound("Sound\\MenuSelect_Selected.wav", "MenuSelect_Selected");

	this->LoadSound("Sound\\Scene1_Background.wav", "Scene1_Background");
	this->SetVolume(100, "Scene1_Background");

	this->LoadSound("Sound\\BossScene_Background.wav", "BossScene_Background");
	this->SetVolume(90, "BossScene_Background");

	this->LoadSound("Sound\\LevelCompleteScene_Background.wav", "LevelCompleteScene_Background");
	this->SetVolume(100, "LevelCompleteScene_Background");

	this->LoadSound("Sound\\Apple_Throw.wav", "Apple_Throw");
	this->SetVolume(83, "Apple_Throw");
	this->LoadSound("Sound\\Apple_Splat.wav", "Apple_Splat");
	this->SetVolume(83, "Apple_Splat");
	this->LoadSound("Sound\\Apple_Slice.wav", "Apple_Slice");

	//Sword
	this->LoadSound("Sound\\Sword_Low.wav", "Sword_Low");
	this->SetVolume(90, "Sword_Low");
	this->LoadSound("Sound\\Sword_High.wav", "Sword_High");
	this->SetVolume(90, "Sword_High");

	this->LoadSound("Sound\\Aladdin_Hit.wav", "Aladdin_Hit");
	this->SetVolume(90, "Aladdin_Hit");
	this->LoadSound("Sound\\Aladdin_Oof.wav", "Aladdin_Oof");
	this->LoadSound("Sound\\Aladdin_Push.wav", "Aladdin_Push");

	this->LoadSound("Sound\\Jafar_Ooh.wav", "Jafar_Ooh");
	this->SetVolume(100, "Jafar_Ooh");
	this->LoadSound("Sound\\Jafar_Snake.wav", "Jafar_Snake");
	this->SetVolume(100, "Jafar_Snake");
	this->LoadSound("Sound\\Jafar_Hit.wav", "Jafar_Hit");
	this->SetVolume(85, "Jafar_Hit");
	//Object
	this->LoadSound("Sound\\Apple_Collect.wav", "Apple_Collect");
	this->SetVolume(80, "Apple_Collect");

	this->LoadSound("Sound\\Enemy_Hit1.wav", "Enemy_Hit1");
	this->SetVolume(85, "Enemy_Hit1");
	this->LoadSound("Sound\\Enemy_Hit2.wav", "Enemy_Hit2");
	this->SetVolume(85, "Enemy_Hit2");
	this->LoadSound("Sound\\Enemy_Aaah.wav", "Enemy_Aaah");
	this->SetVolume(85, "Enemy_Aaah");
	this->LoadSound("Sound\\Enemy_Eeeh.wav", "Enemy_Eeeh");
	this->SetVolume(85, "Enemy_Eeeh");
	this->LoadSound("Sound\\Enemy_Oooh.wav", "Enemy_Oooh");
	this->SetVolume(85, "Enemy_Oooh");
	this->LoadSound("Sound\\Enemy_Throw.wav", "Enemy_Throw");
	this->SetVolume(90, "Enemy_Throw");
	this->LoadSound("Sound\\Enemy_Attack.wav", "Enemy_Attack");
	this->SetVolume(90, "Enemy_Attack");

	this->LoadSound("Sound\\Explosion.wav", "Explosion");
	this->SetVolume(90, "Explosion");

	this->LoadSound("Sound\\Fire.wav", "Fire");
	this->SetVolume(80, "Fire");

	this->LoadSound("Sound\\ThrowingKnife_Ching.wav", "ThrowingKnife_Ching");
	this->LoadSound("Sound\\ThrowingPot_Explosion.wav", "ThrowingPot_Explosion");

	this->LoadSound("Sound\\Lamp_Explosion.wav", "Lamp_Explosion");

	this->LoadSound("Sound\\Health_Disappear.wav", "Health_Disappear");

	this->LoadSound("Sound\\Gem_Disappear.wav", "Gem_Disappear");

	this->LoadSound("Sound\\GenieToken_Disappear.wav", "GenieToken_Disappear");
	this->SetVolume(90, "GenieToken_Disappear");
	this->LoadSound("Sound\\GenieToken_Wow.wav", "GenieToken_Wow");
	this->SetVolume(90, "GenieToken_Wow");

	this->LoadSound("Sound\\CollapseGround_Collapsed.wav", "CollapseGround_Collapsed");

	this->LoadSound("Sound\\JumpBar_JumpOn.wav", "JumpBar_JumpOn");

	this->LoadSound("Sound\\Peddle_Appear.wav", "Peddle_Appear");
	this->LoadSound("Sound\\Peddle_Buy.wav", "Peddle_Buy");

	this->LoadSound("Sound\\CheckPoint_Check.wav", "CheckPoint_Check");
	this->LoadSound("Sound\\CheckPoint_Revise.wav", "CheckPoint_Revise");

	this->LoadSound("Sound\\Camel_Spit.wav", "Camel_Spit");
	this->SetVolume(90, "Camel_Spit");
}

void SoundHelper::LoadSound(char * fileName, std::string name)
{
	if (soundBufferMap.find(name) != soundBufferMap.end())
		return;
	FILE* filePtr;
	WaveHeaderStruct waveHeaderStruct;
	IDirectSoundBuffer* tempBuffer;
	DSBUFFERDESC bufferDesc;
	WAVEFORMATEX waveFormat;
	unsigned char* wavData;
	unsigned char* bufferPtr;
	unsigned long bufferSize;

	int error = fopen_s(&filePtr, fileName, "rb");
	if (error != 0)
	{
		printLog(" Can not load: %s", fileName);
		return;
	}

	fread(&waveHeaderStruct, sizeof(WaveHeaderStruct), 1, filePtr);
	//fread(&waveFileHeader, sizeof(waveFileHeader), 1, filePtr);

	if ((waveHeaderStruct.format[0] != 'W') || (waveHeaderStruct.format[1] != 'A') ||
		(waveHeaderStruct.format[2] != 'V') || (waveHeaderStruct.format[3] != 'E'))
	{
		printLog(" file format does not support: %s", fileName);
	}

	waveFormat.wFormatTag = WAVE_FORMAT_PCM;
	waveFormat.nSamplesPerSec = waveHeaderStruct.sampleRate;
	waveFormat.wBitsPerSample = waveHeaderStruct.bitsPerSample;
	waveFormat.nChannels = waveHeaderStruct.numChannels;
	waveFormat.nBlockAlign = (waveFormat.wBitsPerSample / 8) * waveFormat.nChannels;
	waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
	waveFormat.cbSize = 0;

	bufferDesc.dwSize = sizeof(DSBUFFERDESC);
	bufferDesc.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_GLOBALFOCUS;
	bufferDesc.dwBufferBytes = waveHeaderStruct.dataSize;
	bufferDesc.dwReserved = 0;
	bufferDesc.lpwfxFormat = &waveFormat;
	bufferDesc.guid3DAlgorithm = GUID_NULL;

	IDirectSoundBuffer8* secondaryBuffer = 0;
	IDirectSoundBuffer8** pSecondaryBuffer = &secondaryBuffer;
	//IDirectSoundBuffer8

	//long result = pDevice->CreateSoundBuffer(&bufferDesc, &secondaryBuffer, NULL);

	pDevice->CreateSoundBuffer(&bufferDesc, &tempBuffer, NULL);

	long result = tempBuffer->QueryInterface(IID_IDirectSoundBuffer8, (void**)&(*pSecondaryBuffer));

	tempBuffer->Release();
	tempBuffer = 0;

	if (FAILED(result))
	{
		printLog(" Can not create secondaryBuffer ");
		return;
	}

	//fseek(filePtr, sizeof(WaveHeaderStruct), SEEK_SET); // move the filePointer cursor to data section

	fseek(filePtr, sizeof(WaveHeaderStruct), SEEK_SET);


	wavData = new unsigned char[waveHeaderStruct.dataSize];



	fread(wavData, waveHeaderStruct.dataSize, 1, filePtr);

	error = fclose(filePtr);
	if (error != 0)
	{
		printLog(" Can not close file ");
	}

	result = (*pSecondaryBuffer)->Lock(0, waveHeaderStruct.dataSize, (void**)&bufferPtr, (DWORD*)&bufferSize, NULL, 0, 0);

	if (FAILED(result))
	{
		return;
	}

	memcpy(bufferPtr, wavData, waveHeaderStruct.dataSize);

	(*pSecondaryBuffer)->Unlock((void*)bufferPtr, bufferSize, NULL, 0);

	if (wavData != NULL)
		delete wavData;
	wavData = 0;
	long tempVolume = (mVolume) / 100 * (-DSBVOLUME_MIN) + DSBVOLUME_MIN;
	(*pSecondaryBuffer)->SetVolume(tempVolume);

	soundBufferMap[name] = secondaryBuffer;
}

void SoundHelper::SetVolume(float percentage, std::string name)
{
	mVolume = percentage;
	if (name == "")
	{
		long volumne = (percentage) / 100 * (-DSBVOLUME_MIN) + DSBVOLUME_MIN;
		for (std::map< std::string, IDirectSoundBuffer8*> ::iterator it = soundBufferMap.begin(); it != soundBufferMap.end(); it++)
		{
			it->second->SetVolume(volumne);
		}
	}
	else
	{
		std::map< std::string, IDirectSoundBuffer8*> ::iterator it;
		it = soundBufferMap.find(name);
		if (it == soundBufferMap.end())
			return;
		long volumne = (percentage) / 100 * (-DSBVOLUME_MIN) + DSBVOLUME_MIN;
		it->second->SetVolume(volumne);
	}
}

void SoundHelper::Play(std::string name, bool infiniteLoop, int times)
{
	if (isMute)
	{
		return;
	}
	std::map< std::string, IDirectSoundBuffer8*> ::iterator it;
	it = soundBufferMap.find(name);
	if (it == soundBufferMap.end())
		return;
	if (infiniteLoop)
	{
		it->second->Play(0, 0, DSBPLAY_LOOPING);
	}
	else
	{
		it->second->Stop();
		it->second->SetCurrentPosition(0);
		it->second->Play(0, 0, times - 1);
	}
}

void SoundHelper::Stop(std::string name)
{
	if (name == "")
	{
		for (std::map< std::string, IDirectSoundBuffer8*> ::iterator it = soundBufferMap.begin(); it != soundBufferMap.end(); it++)
		{
			it->second->Stop();
			it->second->SetCurrentPosition(0);
		}
	}
	else
	{
		std::map< std::string, IDirectSoundBuffer8*> ::iterator it;
		it = soundBufferMap.find(name);
		if (it == soundBufferMap.end())
			return;
		else it->second->Stop();
	}
}

float SoundHelper::GetVolume()
{
	return this->mVolume;
}

void SoundHelper::Mute()
{
	isMute = true;
}

void SoundHelper::Unmute()
{
	isMute = false;
	SoundHelper::GetInstance()->Stop();
}

void SoundHelper::CleanUp()
{
	delete this;
}

SoundHelper::SoundHelper()
{
}
