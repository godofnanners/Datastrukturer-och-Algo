#include "pch.h"
#include "CppUnitTest.h"
#include "BSTSet.hpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Uppgift4BinartSoktrad
{
	TEST_CLASS(Uppgift4BinartSoktrad)
	{
	public:

		TEST_METHOD(Test_BSTSetTree_Insert)
		{
			_CrtMemState memStart;
			_CrtMemState memEnd;
			_CrtMemState memDiff;
			_CrtMemCheckpoint(&memStart);
			{
				CommonUtilities::BSTSet<float> myTree;
				myTree.Insert(5);
				myTree.Insert(3);
				myTree.Insert(4);
				myTree.Insert(1);
				myTree.Insert(10);
				myTree.Insert(11);
				myTree.Insert(7);
				myTree.Insert(9);
				myTree.Insert(6);
				

				myTree.Remove(5);
				myTree.Remove(3);
				myTree.Remove(4);
				myTree.Remove(1);
				myTree.Remove(10);
				myTree.Remove(11);
				myTree.Remove(7);
				myTree.Remove(9);
				myTree.Remove(6);
			}

			_CrtMemCheckpoint(&memEnd);
			Assert::IsFalse(_CrtMemDifference(&memDiff, &memStart, &memEnd), L"Tree creates memory leak!");
		}
		TEST_METHOD(Test_BSTSetTree_Remove)
		{
			CommonUtilities::BSTSet<float> myTree;
			myTree.Insert(5);
			/*myTree.Insert(3);
			myTree.Insert(4);
			myTree.Insert(1);
			myTree.Insert(10);
			myTree.Insert(11);
			myTree.Insert(7);
			myTree.Insert(9);
			myTree.Insert(6);*/

			myTree.Remove(5);

			myTree.Insert(7);
			Assert::IsTrue(myTree.HasElement(7));

		}
	};
}
