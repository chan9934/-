#pragma once

typedef struct TagNode
{

	struct TagNode* NextPtr;
	int Data;


}TNode;

typedef struct TagList
{
	TNode* HeadPtr;
	int Count;

}TList;



void Initialize(TList* Ptr);

void Release(TList* Ptr);

void Push_Back(TList* Ptr, int iData);