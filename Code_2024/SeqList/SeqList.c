#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include "SeqList.h"

void SLInit(SL* ps1)
{
	ps1->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps1->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	ps1->capacity = 4;
	ps1->size = 0;
}

void SLDestroy(SL* ps1)
{
	free(ps1->a);
	ps1->a = NULL;
	ps1->capacity = 0;
	ps1->size = 0;
}

void SLPrint(SL* ps1)
{
	for (int i = 0; i < ps1->size; i++)
	{
		printf("%d ", ps1->a[i]);
	}
	printf("\n");
}

void SLCheckCapacity(SL* ps1)
{
	if (ps1->size == ps1->capacity)
	{
		SLDataType* tmp = (SLDataType*)realloc(ps1->a, sizeof(SLDataType) * ps1->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps1->a = tmp;
		ps1->capacity *= 2;
	}
}

#if 0
void SLPushFront(SL* ps1, SLDataType x)
{
	SLCheckCapacity(ps1);

	//挪动数据
	int end = ps1->size - 1;
	while (end >= 0)
	{
		ps1->a[end + 1] = ps1->a[end];
		--end;
	}
	ps1->a[0] = x;
	ps1->size++;
}
#endif

void SLPushFront(SL* ps1, SLDataType x)
{
	assert(ps1);
	SLInsert(ps1, 0, x);
}

#if 0
void SLPushBack(SL* ps1, SLDataType x)
{
	SLCheckCapacity(ps1);
	ps1->a[ps1->size++] = x;
}
#endif

void SLPushBack(SL* ps1, SLDataType x)
{
	assert(ps1);
	SLInsert(ps1, ps1->size, x);
}

#if 0
void SLPopFront(SL* ps1)
{
	assert(ps1);
	assert(ps1->size > 0);
	int start = 0;
	while (start < ps1->size)
	{
		ps1->a[start] = ps1->a[start + 1];
		start++;
	}
	ps1->size--;
}
#endif

void SLPopFront(SL* ps1)
{
	assert(ps1);
	SLErase(ps1, 0);
}

#if 0
void SLPopBack(SL* ps1)
{
	assert(ps1);
	assert(ps1->size > 0);
	ps1->a[ps1->size - 1] = 0;
	ps1->size--;
}
#endif

void SLPopBack(SL* ps1)
{
	assert(ps1);
	assert(ps1->size > 0);
	SLErase(ps1, ps1->size - 1);
}


void SLInsert(SL* ps1, int pos, SLDataType x)
{
	assert(ps1);
	assert(0 <= pos && pos <= ps1->size);

	SLCheckCapacity(ps1);

	int end = ps1->size - 1;
	while (end >= pos)
	{
		ps1->a[end + 1] = ps1->a[end];
		end--;
	}
	ps1->a[pos] = x;
	ps1->size++;
}

void SLErase(SL* ps1, int pos)
{
	assert(ps1);
	assert(0 <= pos && pos < ps1->size);
	int start = pos + 1;
	while (start < ps1->size)
	{
		ps1->a[start - 1] = ps1->a[start];
		start++;
	}
	ps1->size--;
}

int SLFind(SL* ps1, SLDataType x)
{
	assert(ps1);
	for (int i = 0; i < ps1->size; i++)
	{
		if (ps1->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SLModify(SL* ps1, int pos, SLDataType x)
{
	assert(ps1);
	assert(0 < pos && pos < ps1->size);
	ps1->a[pos] = x;
}