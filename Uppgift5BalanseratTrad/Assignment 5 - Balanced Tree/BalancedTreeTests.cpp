#include "stdafx.h"
#include "CppUnitTest.h"

#include <algorithm>
#include <vector>
#include"Assignment 5 - Balanced Tree/Common/UtilityFunctions.hpp"
#include <assert.h>
#include "BSTSet.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using BSTSeti = CommonUtilities::BSTSet<int>;
//using BSTSeti = CommonUtilities::BinaryTree<int>;
using BSTNodei = CommonUtilities::BSTSetNode<int>;

namespace Assignment5BalancedTree
{		
	TEST_CLASS(BalancedBSTSetTests)
	{
	public:
		TEST_METHOD(ManualTest)
		{
			BSTSeti tree;

			for (int i = 0; i < 13; ++i)
				tree.Insert(rand() % 100);

			tree.DSWBalance();
		}
		

		TEST_METHOD(BalanceSmallTree)
		{
			BSTSeti tree;

			Assert::IsTrue(IsBalanced(tree.GetRoot()), L"Empty tree should be balanced.");
			tree.Insert(6);
			Assert::IsTrue(IsBalanced(tree.GetRoot()), L"Tree with one element should be balanced.");
			tree.Insert(9);
			Assert::IsTrue(IsBalanced(tree.GetRoot()), L"Tree with two elements should be balanced.");
			tree.Insert(8);
			Assert::IsFalse(IsBalanced(tree.GetRoot()), L"Tree with elements inserted as (6, 9, 8) should not be balanced.");
			
			std::vector<int> vec = GetInOrderVector(tree.GetRoot());

			tree.DSWBalance();
			Assert::IsTrue(IsBalanced(tree.GetRoot()), L"Tree is not balanced as it should be after calling DSWBalance().");
			Assert::AreEqual(8, tree.GetRoot()->GetData(), L"Tree with elements inserted as (6, 9, 8) should have 8 at the root after balancing.");
			Assert::AreEqual(6, tree.GetRoot()->GetLeft()->GetData(), L"Tree with elements inserted as (6, 9, 8) should have 6 as left child after balancing.");
			Assert::AreEqual(9, tree.GetRoot()->GetRight()->GetData(), L"Tree with elements inserted as (6, 9, 8) should have 9 as right child after balancing.");
		}

		TEST_METHOD(BalanceLargeTree)
		{
			BSTSeti tree;

			for (int i = 0; i < 3000; ++i)
			{
				tree.Insert(TestUtility::GetRandomInt(-2000, 2000));
			}

			std::vector<int> vecBefore = GetInOrderVector(tree.GetRoot());
			for (int j = 1; j < vecBefore.size(); ++j)
			{
				Assert::IsTrue(vecBefore[j - 1] < vecBefore[j], L"Error in tree makeup - in-order tree traversal sequence is not in order");
			}

			tree.DSWBalance();
			Assert::IsTrue(IsBalanced(tree.GetRoot()), L"Tree is not balanced as it should be after calling DSWBalance().");

			std::vector<int> vecAfter = GetInOrderVector(tree.GetRoot());
			for (int j = 0; j < vecAfter.size(); ++j)
			{
				if (j > 0)
				{
					Assert::IsTrue(vecAfter[j - 1] < vecAfter[j], L"Error in balanced tree makeup - in-order tree traversal sequence is not in order");
				}
				Assert::AreEqual(vecBefore[j], vecAfter[j], L"The balanced tree does not have the same in-order tree traversal sequence as the tree had before balancing.");
			}
		}

	private:
		bool IsBalanced(const BSTNodei* const aNode)
		{
			if (aNode == nullptr)
				return true;

			int leftHeight = GetHeight(aNode->GetLeft());
			int rightHeight = GetHeight(aNode->GetRight());

			if (std::abs(leftHeight - rightHeight) <= 1 && IsBalanced(aNode->GetLeft()) && IsBalanced(aNode->GetRight()))
				return true;

			return false;
		}

		int GetHeight(const BSTNodei* const aNode)
		{
			if (aNode == nullptr)
				return 0;

			return 1 + std::max(GetHeight(aNode->GetLeft()), GetHeight(aNode->GetRight()));
		}

		std::vector<int> GetInOrderVector(const BSTNodei* const aRoot)
		{
			std::vector<int> returnVec = {};

			if (aRoot == nullptr)
				return returnVec;

			if (aRoot->GetLeft() != nullptr)
			{
				std::vector<int> leftVec = GetInOrderVector(aRoot->GetLeft());
				for (int i = 0; i < leftVec.size(); ++i)
				{
					returnVec.push_back(leftVec[i]);
				}
			}
			
			returnVec.push_back(aRoot->GetData());

			if (aRoot->GetRight() != nullptr)
			{
				std::vector<int> rightVec = GetInOrderVector(aRoot->GetRight());
				for (int i = 0; i < rightVec.size(); ++i)
				{
					returnVec.push_back(rightVec[i]);
				}
			}

			return returnVec;
		}
	};
}