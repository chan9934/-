#pragma once

typedef struct TagArr
{
	int* IPtr;
	int Count;
	int MaxCount;

}tArr;

void Initialize(tArr* Ptr);

void Release(tArr* Ptr);

void Push_Back(tArr* Ptr, int Num);

//void sort(tArr* Ptr, void(*SortFunc)(int*, int));
//

void sort(tArr* Ptr, void(*Func)(int*, int));