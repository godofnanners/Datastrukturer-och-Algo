#pragma once
namespace CommonUtilities
{

	template<typename T>
	void BubbleSort(std::vector<T>& aVector)
	{
		bool swapped;
		for (size_t i = 0; i < aVector.size() - 1; i++)
		{
			swapped = false;
			for (size_t j = 0; j < aVector.size()-i-1; j++)
			{
				if (aVector[j]<aVector[j+1])
				{
					Swap(aVector[j], aVector[j + 1]);
					swapped = true;
				}
			}

			if (swapped==false)
			{
				break;
			}
		}
	}

	template<typename T>
	void Swap(T& aNumber1, T& aNumber2)
	{
		int temp = aNumber1;
		aNumber1 = aNumber2;
		aNumber2 = temp;
	}
}