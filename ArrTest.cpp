#include "ArrTest.h"
#include <iostream>

void Initialize(_TArr* IPt)
{
	IPt->IPtr = (int*)malloc(sizeof(int) * 2);

	IPt->Count = 0;
	IPt->MaxCount = 0;
}

void Release(_TArr* IPt)
{
	free(IPt->IPtr);

	IPt->Count = 0;
	IPt->MaxCount = 0;
}

void PushBack(_TArr* IPt, int Num)
{
	if (IPt->Count >= IPt->MaxCount)
		Reallocate(IPt);

	IPt->IPtr[IPt->Count] = Num;
	Count++
}

void Reallocate(_TArr* IPt)
{
	int* NPtr = (int*)malloc(IPt->MaxCount * 2 * sizeof(int));

	
	
	for (int i = 0; i < IPt->Count; ++i)
	{
		NPtr[i] = IPt->IPtr[i];
	}

	free(IPt->IPtr);
	
	IPt->IPtr = NPtr;

	IPt->MaxCount *= 2;

}
