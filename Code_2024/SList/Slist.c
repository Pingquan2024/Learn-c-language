#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include "SList.h"

void SLTPrint(SLTNode* phead)
{
	assert(phead);
	SLTNode* cur = phead;
	while (cur!=NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SLPushFront(SLTNode** pphead,SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	newnode->next = *pphead;
	*pphead = newnode;
}