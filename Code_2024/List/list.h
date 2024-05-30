#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>



typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	int data;
}LTNode;

//LTInit LTPrint  LTEmpty  LTPushBack LTPopBack 
//LTPushFront LTPopFront LTFind LTInsert  LTErase  LTDestroy

LTNode* BuyLTNode(LTDataType x);

LTNode* LTInit();

void LTPrint(LTNode* phead);

bool LTEmpty(LTNode* phead);

void LTPushBack(LTNode* phead, LTDataType x);

void LTPushFront(LTNode* phead, LTDataType x);

void LTPopBack(LTNode* phead);

void LTPopFront(LTNode* phead);

void LTDestroy(LTNode* phead);

LTNode* LTFind(LTNode* head, LTDataType val);

void LTInsert(LTNode* pos, LTDataType val);
