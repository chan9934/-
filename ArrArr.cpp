#include "ArrArr.h"
#include <iostream>

void Initialize(tArr* _pArr)
{
	_pArr->Iptr = (int*)malloc(sizeof(int) * 2);
	_pArr->Count = 0;
	_pArr->MaxCount = 0;
}

void Release(tArr* _pArr)
{
	free(_pArr->Iptr);
	_pArr-> Count = 0;
	_pArr->MaxCount = 0;
}


void reallocate(tArr* _pArr)
{
	int* pNew = (int*)malloc(_pArr->MaxCount * 2 * sizeof(int));
	for (int i = 0; i < _pArr->Count; ++i)
	{

		pNew[i] = _pArr->Iptr[i];
	}

	free(_pArr->Iptr);

	_pArr->Iptr = pNew;

	_pArr->MaxCount *= 2;
}


void Pusb_Back(tArr* _pArr, int num)
{
	if (sizeof(_pArr->Count) >= sizeof(_pArr->MaxCount));
	reallocate(_pArr);

	_pArr->Iptr[_pArr->Count] = num;
	++_pArr->Count;

}

