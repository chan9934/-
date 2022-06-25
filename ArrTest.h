#pragma once
typedef struct _TAGArr
{
	int* IPtr;
	int Count;
	int MaxCount;
}_TArr;

void Initialize(_TArr* IPt);

void Release(_TArr* IPt);

void PushBack(_TArr* IPt, int Num);
