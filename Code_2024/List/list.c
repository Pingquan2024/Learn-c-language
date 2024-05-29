#include "list.h"

LTNode* BuyLTNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("BuyLTNode fail");
		return NULL;
	}

	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

LTNode* LTInit()
{
	LTNode* phead = BuyLTNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void LTPrint(LTNode* phead)
{
	assert(phead);

	printf("guard<==>");
	LTNode* cur = phead->next;
	
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

bool LTEmpty(LTNode* phead)
{
	assert(phead);

	return phead->next == phead;
}

void LTPushBack(LTNode* phead,LTDataType x)
{
	assert(phead);

	LTNode* newnode = BuyLTNode(x);

	LTNode* tail = phead->prev;

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

//void LTPushFront(LTNode* phead,LTDataType x)
//{
//	assert(phead);
//	LTNode* newnode = BuyLTNode(x);
//
//	newnode->next = phead->next;
//	phead->next->prev = newnode;
//
//	phead->next = newnode;
//	newnode->prev = phead;
//}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyLTNode(x);

	LTNode* first = phead->next;

	newnode->next = first;
	first->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;
}

void LTPopBack(LTNode* phead)
{
	assert(phead);

	LTNode* tail = phead->prev;

	LTNode* tailPrev = tail->prev;
	free(tail);

	tailPrev->next = phead;
	phead->prev = tailPrev;
}

void LTPopFront(LTNode* phead)
{
	assert(phead);

	LTNode* first = phead->next;
	LTNode* second = first->next;

	phead->next = second;
	second->prev = phead;

	free(first);
}

void LTDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
}