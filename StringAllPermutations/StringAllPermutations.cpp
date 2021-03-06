// StringAllPermutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <unordered_map>

static int g_iCount = 0;
char Temp[256];
std::unordered_map<std::string, std::string> HashMap;
std::unordered_map<std::string, std::string> AllStringsMap;


void swap(char* x, char* y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void Permutate(char* _String, int x, int y, int iCount)
{
	int i;
	if (x == y) {
		printf("\n %d- %s", iCount, _String);
	}
	else {
		for (i = x; i <= y; i++) {
			swap(_String + x, _String + i);
			Permutate(_String, x + 1, y, g_iCount++);
 			swap(_String + x, _String + i);
		}
	}
}

void Permutate2(char* _pString, int _iStart, int _iEnd)
{

	if (_iStart == _iEnd ) {
		// this is the end of this permutation string
		// output current string
		printf("\n %s", _pString);
		auto Result = AllStringsMap.find( std::string(_pString) );
		if (Result == AllStringsMap.end()) {
			AllStringsMap.insert({ std::string(_pString),std::string(_pString) });
			HashMap.insert({ std::string(_pString), std::string(_pString) });
		}
	}
	else {
		for (int i = _iStart; i <= _iEnd; i++) {
			swap(_pString + _iStart, _pString + i);
			Permutate2(_pString, _iStart + 1, _iEnd);
			swap(_pString + _iStart, _pString + i);
		}
	}
}

void PermutateWithSubstrings(char* _pString, int _iCount)
{
	char Temp[256];

	for (int y = 0; y <= _iCount; y++) {
		Permutate2(_pString + y, 0, _iCount - y);

		int iSlot = 0;
		for (int i = 0; i <= _iCount; i++) {
			if (i != y) {
				Temp[iSlot++] = _pString[i];
			}
		}
		Temp[iSlot] = '\0';
		PermutateWithSubstrings(Temp, iSlot - 1);
	}
}


void PermutateWithSubStringsWithTable(char* _pString, int _iCount)
{
	for (int y = 0; y <= _iCount; y++) {

		Permutate2(_pString + y, 0, _iCount - y);

		int iSlot = 0;
		for (int i = 0; i <= _iCount; i++) {
			if (i != y) {
				Temp[iSlot++] = _pString[i];
			}
		}
		Temp[iSlot] = '\0';

		PermutateWithSubstrings(Temp, iSlot - 1);
	}



}

// O(n!)
void PermutateIterative(char* _pString, int _iStart, int _iEnd)
{
	// set up control array
	int* CntrlArray = (int*) malloc(sizeof(int) * _iEnd);
	memset(CntrlArray, 0, sizeof(int)*_iEnd);
	int x = 1; 
	int y = 0;


	printf("\nString = %s", _pString);
	while (x < _iEnd) {
		if (CntrlArray[x] < x) {
			y = (x % 2) * CntrlArray[x];
			swap(_pString+y, _pString+x);
			printf("\nString = %s", _pString);
			CntrlArray[x]++;
			x = 1;
		}
		else {
			CntrlArray[x] = 0;
			x++;
		}
	}

}

int main()
{
    std::cout << "Hello World!\n";

	char String[] = "ABC";
	int Count = strlen(String);

	Permutate(String, 0, Count - 1, g_iCount++);
	printf("\n Method 2");
	Permutate2(String, 0, Count - 1);
	printf("\n With Substrings");
	PermutateWithSubstrings(String, Count - 1);
	printf("\n With Substrings and Table to prevent duplication");
	PermutateWithSubStringsWithTable(String, Count - 1);
	
	//output hashmap
	printf("\n Hash Map");
	for (auto itMap = HashMap.begin(); itMap != HashMap.end(); itMap++) {
		printf("\n Key: %s. Value: %s", (itMap->first).c_str(), (itMap->second).c_str());
	}

	// all strings
	printf("\n All Strings");
	for (auto itMap = AllStringsMap.begin(); itMap != AllStringsMap.end(); itMap++) {
		printf("\n Key: %s. Value: %s", (itMap->first).c_str(), (itMap->second).c_str());
	}

	// iterative approach
	printf("\n Iterative Approach");
	PermutateIterative(String, 0, Count);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
