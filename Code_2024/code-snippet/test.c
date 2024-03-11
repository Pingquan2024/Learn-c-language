#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include <stdio.h>
#include <string.h>

//合并两个有序数组
void merge(int* nums1, int numsSize, int m, int* nums2, int nums2Size, int n)
{
	int end1 = m - 1;
	int end2 = n - 1;
	int i = m + n - 1;
	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1] > nums2[end2])
		{
			nums1[i--] = nums1[end1--];
		}
		else
		{
			nums1[i--] = nums2[end1--];
		}
	}

	while (end2 >= 0)
	{
		nums1[i--] = nums2[end2--];
	}
}


//三段逆置的方法解决右轮数组
void reverse(int* a, int left, int right)
{
	while (left < right)
	{
		int tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left++;
		right--;
	}
}

void rotate(int* nums, int numsSize, int k)
{
	if (k > numsSize)
	{
		k %= numsSize;
	}

	reverse(nums, 0, numsSize - k-1);
	reverse(nums, numsSize - k, numsSize - 1);
	reverse(nums, 0, numsSize - 1);
}


void rotate2(int* nums, int numsSize, int k)
{
	if (k > numsSize)
	{
		k %= numsSize;
	}
	int* tmp = malloc(sizeof(int) * numsSize);
	memcpy(tmp + k, nums, sizeof(int) * (numsSize - k));
	memcpy(tmp , nums+numsSize-k, sizeof(int) * (k));
	memcpy(nums, tmp, sizeof(int) * (numsSize));
	free(tmp);
	tmp = NULL;
}


//消失的数字
int missingNumber(int* nums, int numsSize)
{
	int i = 0;
	int sum = 0;

	for (i = 1; i <= numsSize; i++)
	{
		sum ^= i;
	}

	for (i = 0; i < numsSize; i++)
	{
		sum ^= nums[i];
	}
	return sum;
}

//移除元素
int removeElement(int* nums, int numsSize, int val)
{
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst++] = nums[src++];
		}
		else
		{
			src++;
		}
	}

	return dst;
}


//尾插
void SLPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyLTNode(x);

	//1.空链表
	//2.非空链表
	if (*phead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}