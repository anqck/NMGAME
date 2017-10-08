#include "DemoMap.h"

DemoMap::DemoMap()
{
	this->LoadResource();
}

void DemoMap::Render(float DeltaTime)
{
	GLOBAL::GetDirectDevice()->StretchRect(
		this->mBackground,			// from 
		NULL,				// which portion?
		GLOBAL::GetBackBuffer(),		// to 
		NULL,				// which portion?
		D3DTEXF_NONE);
}

void DemoMap::LoadResource()
{
	this->mBackground = CreateSurfaceFromFile(GLOBAL::GetDirectDevice(), L"Map\\Map1.PNG");
}
