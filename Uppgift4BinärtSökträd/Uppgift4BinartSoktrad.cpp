#include "pch.h"
#include "CppUnitTest.h"
#include "BSTSet.hpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Uppgift4BinartSoktrad
{
	TEST_CLASS(Uppgift4BinartSoktrad)
	{
	public:
		
		TEST_METHOD(Test_BSTSetTree)
		{
			BSTSet<float> myTree;
			myTree.Insert(5);
			myTree.Insert(3);
			myTree.Insert(4);
			myTree.Insert(1);
			myTree.Insert(10);
			myTree.Insert(11);
			myTree.Insert(7);
			myTree.Insert(9);
			myTree.Insert(6);

			myTree.HasElement(6);
			myTree.Remove(6);
			myTree.HasElement(6);
			myTree.HasElement(12);
			myTree.Remove(12);
		}
	};
}
