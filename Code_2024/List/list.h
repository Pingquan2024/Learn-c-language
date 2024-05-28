#pragma once

#include <stdio.h>
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