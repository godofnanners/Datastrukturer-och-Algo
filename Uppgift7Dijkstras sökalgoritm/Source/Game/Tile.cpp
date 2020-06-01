#include "stdafx.h"
#include "Tile.h"

void Tile::Init(Tga2D::Vector2f aPosition, const std::string& aPath)
{
	myPosition = aPosition*0.01f;
	mySprite = Tga2D::CSprite(aPath.c_str());
	mySprite.SetPosition(myPosition);
	mySprite.SetSizeRelativeToImage({0.01f,0.01f});
	mySprite.SetPosition(myPosition);
}

void Tile::ChangeColor(Tga2D::CColor aColor)
{
	mySprite.SetColor(aColor);
}



void Tile::Render()
{
	mySprite.Render();
}
