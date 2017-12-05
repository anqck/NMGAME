#include "ScoreFont.h"

ScoreFont::ScoreFont()
{
	mListAlphabet['0'] = MyRECT(0, 0, 15, 16);
	mListAlphabet['1'] = MyRECT(34, 25, 33, 50);
	mListAlphabet['2'] = MyRECT(34, 0, 13, 50);
	mListAlphabet['3'] = MyRECT(34, 14, 24, 50);
	mListAlphabet['4'] = MyRECT(0, 16, 30, 16);
	mListAlphabet['5'] = MyRECT(0, 31, 45, 16);
	mListAlphabet['6'] = MyRECT(0, 46, 60, 16);
	mListAlphabet['7'] = MyRECT(17, 30, 42, 33);
	mListAlphabet['8'] = MyRECT(17, 0, 14, 33);
	mListAlphabet['9'] = MyRECT(17, 15, 29, 33);


	D3DXIMAGE_INFO		AlphabetInfo;
	D3DXGetImageInfoFromFile(L"Object\\SceneInformation\\ScoreFont.png", &AlphabetInfo);
	D3DXCreateTextureFromFileEx(GraphicsHelper::GetInstance()->GetDirectDevice(), L"Object\\SceneInformation\\ScoreFont.png", AlphabetInfo.Width,
		AlphabetInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		&AlphabetInfo,
		NULL,
		&mAlphabetTexture);

}

ScoreFont::ScoreFont(D3DXVECTOR3 pos, std::string string) : ScoreFont()
{
	this->mPosition = pos;
	this->mString = string;
}

ScoreFont::~ScoreFont()
{
}

void ScoreFont::Render()
{
	for (int i = this->mString.length() - 1; i >= 0; i--)
	{
		GraphicsHelper::GetInstance()->DrawTexture(mAlphabetTexture, this->mListAlphabet[mString[i]], this->mListAlphabet[mString[i]].GetCenterArchorPosision(CenterArchor::CenterTop), D3DXVECTOR3(this->mPosition.x - 32 * (this->mString.length() - 1 - i), this->mPosition.y, 0), D3DXVECTOR2(2.1, 2.1));
	}
}

void ScoreFont::SetString(std::string string)
{
	this->mString = string;
}

void ScoreFont::SetPosition(D3DXVECTOR3 pos)
{
	this->mPosition = pos;
}
