#include "stdafx.h"
#include "Grid.h"

void Grid::Init()
{
	for (int i = 0; i < 20; i++)
	{
			myTiles[i].Init(Tga2D::Vector2f(i,static_cast<int>(i/20)), "sprites/tga_logo.dds");
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
		if (i != 0 || i == aPath.size() - 1)
		{
			myTiles[aPath[i]].ChangeColor({ 1,1,0,1 });
		}
	}
}

void Grid::Render()
{
	for (int i = 0; i < myTiles.size(); i++)
	{
		myTiles[i].Render();
	}
}
