#pragma once
typedef struct TagNode
{
	struct TagNode* NodePtr;
	int Data;
}tNode;

typedef struct TagList
{
	tNode* ListPtr;
	int Count;
}tList;

void Initialize(tList* Ptr);
void Release(tList* Ptr);
void Push_Back(tList* Ptr, int iData);
