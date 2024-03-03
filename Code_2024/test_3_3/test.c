#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include <stdio.h>

#if 0
//前插
void SLPushFront(SL*PS1,SLDataType x)
{
	SLCheckCapacity(ps1);

	//挪动数据
	int end = ps1->size - 1;
	while (end > 0)
	{
		ps1->a[end + 1] = ps1->a[end];
		end--;
	}

	ps1->a[0] = 'x';
	ps1->size++;
}
#endif


//时间复杂度O(N),空间复杂度O(1)
int removeElement(int* nums, int numsSize, int val)
{
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst++] = nums[src++];  //不等于val的值放到dst;
		}
		else
		{
			src++;
		}
	}
	return dst;
}