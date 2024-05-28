#include "list.h"

void LTInit(LTNode* ps)
{
	assert(ps);
	ps->next = NULL;
	ps->prev = NULL;
	ps->data = 0;
}

void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;

	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}