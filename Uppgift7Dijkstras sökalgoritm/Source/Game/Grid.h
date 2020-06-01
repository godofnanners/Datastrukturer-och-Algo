#pragma once
#include <array>
#include "Tile.h"
#include "Dijkstra.hpp"
class Grid
{
public:
	void Init();
	std::array<Tile,40>myTiles;
	std::vector<CommonUtilities::Tile> ConvertToDijsktraVector();
	void ColorPath(std::vector<int>aPath);
	void Render();
private:
};

