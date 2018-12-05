// StringAllPermutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

static int g_iCount = 0;

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

//void ReversePermutate(char* _String, int x, int y, int iCount)
//{
//	int i;
//	if (x == y) {
//		printf("\n %d- %s", iCount, _String);
//	}
//	else {
//		for (i = y, i >= x; i--) {
//			swap( _String + x, _String + i );
//			ReversePermutate( _String, )
//		}
//	}
//}

int main()
{
    std::cout << "Hello World!\n";

	char String[] = "ABC";
	int Count = strlen(String);

	Permutate(String, 0, Count - 1, g_iCount++);

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
