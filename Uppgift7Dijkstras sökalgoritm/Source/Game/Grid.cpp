#include "stdafx.h"
#include "Grid.h"

void Grid::Init()
{
	float posY=0;
	float posX=0;
	for (int i = 0; i < myTiles.size(); i++)
	{
		posY = static_cast<int>(i / 20);
		posX++;
		if (posX>19)
		{
			posX = 0;
		}
		myTiles[i].Init(Tga2D::Vector2f(posX, posY), "sprites/tga_logo.dds");
	}
}

std::vector<CommonUtilities::Tile> Grid::ConvertToDijsktraVector()
{
	std::vector<CommonUtilities::Tile>map;
	for (size_t i = 0; i < myTiles.size(); i++)
	{
		if (myTiles[i].myPassable == true)
		{
			map.insert(map.begin(), CommonUtilities::Tile::Passable);
		}
		else
		{
			map.insert(map.begin(), CommonUtilities::Tile::Impassable);
		}
	}
	return map;
}

void Grid::ColorPath(std::vector<int> aPath)
{
	for (int i = 0; i < aPath.size(); i++)
	{
		myTiles[aPath[i]].ChangeColor({ 1,1,0,1 });
	}
}

void Grid::Render()
{
	for (int i = 0; i < myTiles.size(); i++)
	{
		myTiles[i].Render();
	}
}
