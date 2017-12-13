#pragma once
#include "dsound.h"
#include "windows.h"
#include "Global.h"
#include <map>
#include <string>
#include <iostream>
#include <mmsystem.h>
#pragma comment(lib, "dsound.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")

class SoundHelper
{
public:
	struct WaveHeaderStruct
	{
		char chunkId[4];
		unsigned long chunkSize;
		char format[4];
		char subChunkId[4];
		unsigned long subChunkSize;
		unsigned short audioFormat;
		unsigned short numChannels;
		unsigned long sampleRate;
		unsigned long bytesPerSecond;
		unsigned short blockAlign;
		unsigned short bitsPerSample;
		char dataChunkId[4];
		unsigned long dataSize;
	};

	~SoundHelper();

	static SoundHelper*		GetInstance();
	void					Initialize();
	void					LoadResource();

	void					LoadSound(char* fileName, std::string name);
	void					SetVolume(float percentage, std::string name = "");
	void					Play(std::string name, bool infiniteLoop = false, int times = 1);
	void					Stop(std::string name = "");
	float					GetVolume();
	void					Mute();
	void					Unmute();
	void					CleanUp();
private:
	SoundHelper();

	static SoundHelper*		mInstance;

	float						mVolume;
	IDirectSound8*				pDevice;
	IDirectSoundBuffer*			primaryBuffer;
	std::map<std::string, IDirectSoundBuffer8*> soundBufferMap;
	bool isMute;
};