#pragma once

typedef struct TagArr
{
	int* Iptr;
	int Count;
	int MaxCount;
}tArr;

void Initialize(tArr* _pArr);
void Release(tArr* _pArr);
void Pusb_Back(tArr* _pArr, int num);
void reallocate(tArr* _pArr)