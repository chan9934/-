#pragma once
typedef struct TagArr
{
	int* pInt;
	int iCount;
	int iMaxCount;

	
}tArr;

void InitArr(tArr* _pArr);

void ReleaseArr(tArr*_pArr);

void Reallocate(tArr* _pArr);

void PushBack(tArr* _pArr, int _iData);