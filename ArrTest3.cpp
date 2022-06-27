#include "ArrTest3.h"
#include <iostream>

void Initialize(tArr* Ptr)
{
	
	Ptr->IPtr = (int*)malloc(sizeof(int) * 2);
	Ptr->Count = 0;
	Ptr->MaxCount = 2;
}

void Release(tArr* Ptr)
{
	free(Ptr->IPtr);
	Ptr->Count = 0;
	Ptr->MaxCount = 0;
}

void Reallocate(tArr* Ptr)
{
	int* Nptr = (int*)malloc(Ptr->MaxCount * 2 * sizeof(int));

	for (int i = 0; i < Ptr->Count; ++i)
	{
		Nptr[i] = Ptr->IPtr[i];
	}

	free(Ptr->IPtr);

	Ptr->IPtr = Nptr;

	Ptr->MaxCount *= 2;

}

void Push_Back(tArr* Ptr, int Num)
{
	if (Ptr->Count >= Ptr->MaxCount)
		Reallocate(Ptr);
	Ptr->IPtr[Ptr->Count++] = Num;
	
}

//void sort(tArr* Ptr, void(*SortFunc)(int*, int))
//{
//
//	SortFunc(Ptr->IPtr, Ptr->Count);
//}

void sort(tArr* Ptr, void(*Func)(int*, int))
{
	Func(Ptr->IPtr, Ptr->Count);
}