#pragma once
#include <vector>
#include <map>
#include <set>
#include "MinHeap.hpp"
namespace CommonUtilities
{
	static bool CheckIfInsideMap(int aIndex);
	static bool CheckIfVerticeRealyIsNeighbour(int aNeighbourIndex, int aCurrentIndex);


	struct DijNode
	{
		int myVertice;
		int myDistanceValue;
		int myPrevNode;

		DijNode() = default;

		DijNode(int aVertice, int aDistanceValue,int aPrevNode)
		{
			myVertice = aVertice;
			myDistanceValue = aDistanceValue;
			myPrevNode = aPrevNode;
		}

		bool operator< (const DijNode& aNode) const
		{
			if (myDistanceValue < aNode.myDistanceValue)
			{
				return true;
			}
			return false;
		}
		
	};
	static const int MapWidth = 20; static const int MapHeight = 20; static const int TileCount = MapWidth * MapHeight;
	enum class Tile { Impassable, Passable };
	static std::vector<int> Dijkstra(const std::vector<Tile>& aMap, int aStartIndex, int anEndIndex)
	{	
		std::vector<int>MyPath;
		std::array<DijNode, MapWidth* MapHeight> myNodes;
		MinHeap<DijNode> minHeap;
		std::array<bool, MapWidth* MapHeight> visited = {false};
		
		for (size_t i = 0; i < aMap.size(); i++)
		{
			myNodes[i].myVertice = i;
			myNodes[i].myDistanceValue = 999;
			myNodes[i].myPrevNode = -1;
		}
		
		myNodes[aStartIndex].myVertice = aStartIndex;
		myNodes[aStartIndex].myDistanceValue = 0;
		myNodes[aStartIndex].myPrevNode = aStartIndex;
		
		visited.fill(false);
		

		minHeap.Enqueue(myNodes[aStartIndex]);

		while (minHeap.GetSize() > 0)
		{
			DijNode newSmallest = minHeap.Dequeue();
			if (newSmallest.myVertice==anEndIndex)
			{
				
				int currentNode =newSmallest.myVertice;
				do
				{
					MyPath.push_back(currentNode);
					currentNode = myNodes[currentNode].myPrevNode;
				} while (currentNode != aStartIndex);
				MyPath.push_back(aStartIndex);
				std::reverse(MyPath.begin(), MyPath.end());
				return MyPath;
			}
			visited[newSmallest.myVertice] = true;
			std::array<int,4> neighbours;
			neighbours[0]= newSmallest.myVertice - MapWidth;
			neighbours[1] = newSmallest.myVertice + MapWidth;
			neighbours[2] = newSmallest.myVertice + 1;
			neighbours[3] = newSmallest.myVertice - 1;

			for (int i = 0; i < neighbours.size(); i++)
			{
				if ( CheckIfInsideMap(neighbours[i]) 
					&& visited[neighbours[i]] == false 
					&& aMap[neighbours[i]] == Tile::Passable 
					&& CheckIfVerticeRealyIsNeighbour(neighbours[i],newSmallest.myVertice))
				{
					
					int altPath= 1+ newSmallest.myDistanceValue;
					
					if (altPath<myNodes[neighbours[i]].myDistanceValue)
					{
						myNodes[neighbours[i]].myDistanceValue = altPath;
						myNodes[neighbours[i]].myPrevNode = newSmallest.myVertice;
						minHeap.Enqueue(myNodes[neighbours[i]]);
					}
				}
			}
		}

		return MyPath;
	}
	static bool CheckIfInsideMap(int aIndex)
	{
		if (aIndex < MapWidth * MapHeight && aIndex >= 0)
		{
			return true;
		}
		return false;
	}
	static bool CheckIfVerticeRealyIsNeighbour(int aNeighbourIndex, int aCurrentIndex)
	{
			if (abs((aCurrentIndex % MapWidth) - (aNeighbourIndex % MapWidth)) != 1 && abs(aCurrentIndex - aNeighbourIndex) != MapWidth )
			{
				return false;
			}

		return true;
	}
	
}