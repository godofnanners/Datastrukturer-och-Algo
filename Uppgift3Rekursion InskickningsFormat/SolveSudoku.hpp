#pragma once
#include <array>
int sudokuHelper(std::array<int, 81>& aBoard, int aSquare);
std::array<int, 9>FindSector(int aPlaceInArray, const std::array<int, 81>& aBoard);

bool SolveSudoku(std::array<int, 81>& aBoard)
{
	if (sudokuHelper(aBoard, 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int isValid(int number, int aSquare, std::array<int, 81>& aBoard)
{
	/* Check for the value in the given row and column */
	int rest = aSquare % 9;
	int row = static_cast<int>(aSquare / 9);
	for (int i = 0; i < 9; i++)
	{
		//check column
		if (aBoard[rest + i * 9] == number) return 0;
		//check row
		if (aBoard[i + row * 9] == number) return 0;
	}
	std::array<int, 9>sector = FindSector(aSquare, aBoard);

	for (int i = 0; i < sector.size(); i++)
	{
		if (sector[i] == number) return 0;
	}
	/* Check the remaining four spaces in this sector */
	/*if (puzzle[row1 + sectorRow][col1 + sectorCol] == number) return 0;
	if (puzzle[row2 + sectorRow][col1 + sectorCol] == number) return 0;
	if (puzzle[row1 + sectorRow][col2 + sectorCol] == number) return 0;
	if (puzzle[row2 + sectorRow][col2 + sectorCol] == number) return 0;*/
	return 1;
}
int sudokuHelper(std::array<int, 81>& aBoard, int aSquare)
{
	if (aBoard[aSquare] != 0)
	{
		if (!(aSquare < 80) || sudokuHelper(aBoard, aSquare + 1)) return 1;
		else
		{
			return 0;
		}
	}
	else
	{
		int number = 1;
		/*
		 * Iterate through the possible numbers for this empty cell
		 * and recurse for every valid one, to test if it's part
		 * of the valid solution.
		 */
		for (; number < 10; number++)
		{
			if (isValid(number, aSquare, aBoard))
			{
				aBoard[aSquare] = number;

				if ((aSquare + 1) > 80 || sudokuHelper(aBoard, aSquare + 1)) return 1;

				// We failed to find a valid value for this 
				aBoard[aSquare] = 0;
			}
		}
		return 0;
	}
}

std::array<int, 9>FindSector(int aPlaceInArray, const std::array<int, 81>& aBoard)
{
	std::array<int, 9> sector = { 0 };
	int sectionSquare = 0;
	int sectioncolumn = aPlaceInArray % 9;
	//column section 1
	if (sectioncolumn < 3)
	{
		if (aPlaceInArray < 21)
		{
			for (int i = 0; i < 21; i += 9)
			{
				for (int j = 0; j < 3; j++)
				{
					sector[sectionSquare] = aBoard[i + j];
					++sectionSquare;
				}
			}
		}
		else if (aPlaceInArray > 26 && aPlaceInArray < 48)
		{
			for (int i = 3 * 9; i < 48; i += 9)
			{
				for (int j = 0; j < 3; j++)
				{
					sector[sectionSquare] = aBoard[i + j];
					++sectionSquare;
				}
			}
		}
		else if (aPlaceInArray > 53)
		{
			for (int i = 6 * 9; i < 75; i += 9)
			{
				for (int j = 0; j < 3; j++)
				{
					sector[sectionSquare] = aBoard[i + j];
					++sectionSquare;
				}
			}
		}
	}
	//column section 2
	else if (sectioncolumn > 2 && sectioncolumn < 6)
	{
		if (aPlaceInArray < 24)
		{
			for (int i = 3; i < 24; i += 9)
			{
				for (int j = 0; j < 3; j++)
				{
					sector[sectionSquare] = aBoard[i + j];
					++sectionSquare;
				}
			}
		}
		else if (aPlaceInArray > 23 && aPlaceInArray < 51)
		{
			for (int i = 3 + 3 * 9; i < 51; i += 9)
			{
				for (int j = 0; j < 3; j++)
				{
					sector[sectionSquare] = aBoard[i + j];
					++sectionSquare;
				}
			}
		}
		else if (aPlaceInArray > 56)
		{
			for (int i = 3 + 6 * 9; i < 77; i += 9)
			{
				for (int j = 0; j < 3; j++)
				{
					sector[sectionSquare] = aBoard[i + j];
					++sectionSquare;
				}
			}
		}
	}
	//column section 3
	else if (sectioncolumn > 5)
	{
		if (aPlaceInArray < 27)
		{
			for (int i = 6; i < 27; i += 9)
			{
				for (int j = 0; j < 3; j++)
				{
					sector[sectionSquare] = aBoard[i + j];
					++sectionSquare;
				}
			}
		}
		else if (aPlaceInArray > 26 && aPlaceInArray < 54)
		{
			for (int i = 6 + 3 * 9; i < 54; i += 9)
			{
				for (int j = 0; j < 3; j++)
				{
					sector[sectionSquare] = aBoard[i + j];
					++sectionSquare;
				}
			}
		}
		else if (aPlaceInArray > 59)
		{
			for (int i = 6 + 6 * 9; i < 81; i += 9)
			{
				for (int j = 0; j < 3; j++)
				{
					sector[sectionSquare] = aBoard[i + j];
					++sectionSquare;
				}
			}
		}
	}
	return sector;
}