#include "stdafx.h"
#include "Tile.h"
#include "InputHandler/InputHandler.h"
#include "Vector/Vector2.h"
#include <array>

void Tile::Init(Tga2D::Vector2f aPosition, const std::string& aPath)
{
	mySprite = Tga2D::CSprite(aPath.c_str());
	mySprite.SetSizeRelativeToScreen({0.05f,0.05f});
	myPosition.x = aPosition.x*mySprite.GetSize().x/1.75f;
	myPosition.y = aPosition.y * mySprite.GetSize().y;
	mySprite.SetPosition(myPosition);
	myHitbox.Init(&mySprite);
}

void Tile::ChangeColor(Tga2D::CColor aColor)
{
	mySprite.SetColor(aColor);
}

void Tile::Render()
{
	mySprite.Render();
	std::array<float, 2> mouseCord = CommonUtilities::InputHandler::Instance().CheckMousePosInWindow(*Tga2D::CEngine::GetInstance()->GetHWND());
	Tga2D::Vector2<float> mousePos = Tga2D::Vector2<float>(mouseCord[0]/ static_cast<float>(Tga2D::CEngine::GetInstance()->GetRenderSize().x), mouseCord[1]/ static_cast<float>(Tga2D::CEngine::GetInstance()->GetRenderSize().y));
	if (myHitbox.CheckifPointIsInside(mousePos))
	{
		myHitbox.DrawHitbox(Tga2D::CColor(1, 0.5f, 1, 1));
		ChangeColor(Tga2D::CColor(1, 0.5f, 1, 1));
	}
	else
	{
		myHitbox.DrawHitbox(Tga2D::CColor(1,1,1,1));
		ChangeColor(Tga2D::CColor(1, 1, 1, 1));
	}
}
