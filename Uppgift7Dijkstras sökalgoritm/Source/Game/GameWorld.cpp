#include "stdafx.h"
#include "GameWorld.h"
#include <tga2d/sprite/sprite.h>
#include "InputHandler/InputHandler.h"
#include "Grid.h"

CGameWorld::CGameWorld()
{
	myTga2dLogoSprite = nullptr;
	myGrid = nullptr;
}

CGameWorld::~CGameWorld() 
{
	delete myTga2dLogoSprite;
	myTga2dLogoSprite = nullptr;
}

void CGameWorld::Init()  
{
	myGrid = new Grid();
	myGrid->Init();
	/*myTga2dLogoSprite = new Tga2D::CSprite("sprites/tga_logo.dds");
	myTga2dLogoSprite->SetPivot({ 0.5f, 0.5f });
	myTga2dLogoSprite->SetPosition({ 0.8f, 0.5f });
	myTga2dLogoSprite->SetSizeRelativeToScreen({ 0.2,0.2 });*/
	CommonUtilities::InputHandler::Instance().CheckMousePos();
}


void CGameWorld::Update(float /*aTimeDelta*/)
{
	
}

void CGameWorld::Render()
{
	myGrid->Render();
	//myTga2dLogoSprite->Render();
}