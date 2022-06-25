#include "arr.h"
#include <iostream>

void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
	
}

void ReleaseArr(tArr* _pArr)
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void Reallocate(tArr* _pArr)
{

	int* pNew = (int*) malloc(_pArr->iMaxCount * 2 * sizeof(int));
	for (int i = 0; i < _pArr->iCount; ++i)
	{
		pNew[i] = _pArr->pInt[i];

	}

	free(_pArr->pInt);

	_pArr->pInt = pNew;

	_pArr->iMaxCount *= 2;
}






void PushBack(tArr* _pArr, int _iData)
{
	if (_pArr->iMaxCount <= _pArr->iCount)
	{
		Reallocate(_pArr);
	}

	_pArr->pInt[_pArr -> iCount++] = _iData;

}

