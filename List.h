#pragma once

typedef struct _tagNode
{
	int iData;
	tNode* pNextNode;

}tNode;




typedef struct _taglist
{
	tNode* pHeadNode;
	int iCount;

}tLinkedList;