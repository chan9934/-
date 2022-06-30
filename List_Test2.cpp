#include "List_Test2.h"
#include <iostream>

void Initialize(tList* Ptr)
{
	Ptr->ListPtr = nullptr;
	Ptr->Count = 0;
}



void Release(tList* Ptr)
{
	tNode* DeletePtr = Ptr->ListPtr;
	while (DeletePtr)
	{
		tNode* NewPtr = DeletePtr->NodePtr;
		free(DeletePtr);
		DeletePtr = NewPtr;
	}
}

void Push_Back(tList* Ptr, int iData)
{
	tNode* NewPtr = (tNode*)malloc(sizeof(NewPtr));
	NewPtr->Data = iData;
	NewPtr->NodePtr = nullptr;
	if (0 == Ptr->Count)
	{
		Ptr->ListPtr = NewPtr;
		
	}

	tNode* FoundPtr = Ptr->ListPtr;
	while (FoundPtr->NodePtr)
	{
		
		FoundPtr = FoundPtr->NodePtr;

	}
	FoundPtr->NodePtr = NewPtr;
	++Ptr->Count;


}

void Push_Front(tList* Ptr, int iData)
{
	tNode* NewPtr = (tNode*)malloc(sizeof(tNode));
	NewPtr->Data = iData;

	NewPtr = Ptr->ListPtr;
	Ptr->ListPtr = NewPtr;

		
	++Ptr->Count;
	

}