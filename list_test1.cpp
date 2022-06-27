#include "list_test1.h"
#include <iostream>

void Initialize(TList* Ptr)
{
	Ptr->HeadPtr = nullptr;
	Ptr->Count = 0;
}

void Release(TList* Ptr)
{
	TNode* NewPtr = Ptr->HeadPtr;
	while (NewPtr->NextPtr)
	{
		TNode* DeletePtr = NewPtr->NextPtr;
		free(NewPtr);
		NewPtr = DeletePtr;
	}
	Ptr->Count = 0;
}

void Push_Back(TList* Ptr, int iData)
{
	TNode* NP = (TNode*)malloc(sizeof(TNode));
	NP->Data = iData;
	NP->NextPtr = nullptr;

	if (0 == Ptr->Count)
	{
		Ptr->HeadPtr = NP;

	}

	else
	{
		TNode* New = Ptr->HeadPtr; //자료형이 같아야지

		while (New->NextPtr)
		{
			New = New->NextPtr;

		}
		New->NextPtr = NP;


	}
	++Ptr->Count;
}

