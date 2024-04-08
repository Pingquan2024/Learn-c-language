#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//Á´±í
typedef int SLTDataType;

typedef struct SListNode
{
	struct SListNode* next;
	SLTDataType data;
}SLTNode;

void SLTPrint(SLTNode* phead);
void SLPushFront(SLTNode** pphead, SLTDataType x);
void SLPushBack(SLTNode** pphead, SLTDataType x);

void SLPopFront(SLTNode** pphead);
void SLPopBack(SLTNode** pphead);