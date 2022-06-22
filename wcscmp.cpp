#include <iostream>
#include "Header.h"
#include "common.h"
#include <wchar.h>


using namespace std;

unsigned int GetLength(const wchar_t* _pStr)
{
	//문자 개수 체크 용도
	int i{ 0 };
	while ('\0' != _pStr[i])
	{
		++i;
	}
	return i;

}
int compare(const wchar_t* A, const wchar_t* B)
{
	if (A == B)
		return 0;
	if (GetLength(A) >= GetLength(B))
	{
		for (int i = 0; i < GetLength(A); ++i)
		{
			if (*(A + i) < *(B + i))
			{
				return -1;
			}

			else if (*(A + i) > *(B + i))
			{
				return 1;
			}
		}
	}
	else
	{
		for (int i = 0; i < GetLength(B); ++i)
		{
			if (*(A + i) < *(B + i))
			{
				return -1;
			}

			else if (*(A + i) > *(B + i))
			{
				return 1;
			}
		}
	}

}


int main()
{
	const wchar_t* Arr1 = L"gbc";
	const wchar_t* Arr2 = L"abb";
	cout << compare(Arr1, Arr2) << endl;
	cout << wcscmp(Arr1, Arr2);

}