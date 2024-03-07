#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include <stdio.h>

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