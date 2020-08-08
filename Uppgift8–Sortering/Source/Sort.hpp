#pragma once
#include "SelectionSort.hpp"
#include "MergeSort.hpp"
#include "BubbleSort.hpp"
#include "QuickSort.hpp"

namespace CommonUtilities
{
	template<typename T>
	void SelectionSort(std::vector<T>& aVector); 
	template<typename T>
	void QuickSort(std::vector<T>& aVector); 
	template<typename T>
	void MergeSort(std::vector<T>& aVector);
}