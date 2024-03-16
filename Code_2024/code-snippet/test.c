#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include <stdio.h>
#include <string.h>
#include <assert.h>

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

	reverse(nums, 0, numsSize - k - 1);
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
	memcpy(tmp, nums + numsSize - k, sizeof(int) * (k));
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

#if 0
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
#endif


//删除有序数组中的重复项
int removeDuplicates(int* nums, int numsSize)
{
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		if (nums[src] != nums[dst])
		{
			nums[++dst] = nums[src++];
		}
		else
		{
			src++;
		}
	}
	return dst + 1;
}

//移除链表元素
struct ListNode {
	int val;
	struct ListNode* next;
};

//方法一：
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* prev = NULL, * cur = head;
	while (cur)
	{
		if (cur->val == val)
		{
			if (prev)
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
			else
			{
				cur = head->next;
				free(head);
				head = cur;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}

struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* cur = head;
	struct ListNode* newhead = NULL, * tail = NULL;
	while (cur)
	{
		if (cur->val != val)
		{
			if (tail==NULL)
			{
				newhead = tail = cur;
			}
			else
			{
				tail->next = cur;
				tail = tail->next;
			}
			cur = cur->next;
			tail->next = NULL;
		}
		else
		{
			struct ListNode* del = cur;
			cur = cur->next;
			free(del);
		}
	}
	return newhead;
}

#if 0
//方法二：
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* cur = head;
	struct ListNode* newhead = NULL, * tail = NULL;
	while (cur)
	{
		if (cur->val != val)
		{
			if (tail == NULL)
			{
				newhead = tail = cur;
			}
			else
			{
				tail->next = cur;
				tail = tail->next;
			}
			cur = cur->next;
			tail->next = NULL;
		}
		else
		{
			struct ListNode* del = cur;
			cur = cur->next;
			free(del);
		}
	}
	return newhead;
}
#endif


struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* slow = head, * fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

//合并两个有序链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#if 0
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (list1 == NULL) {
		return list2;
	}
	if (list2 == NULL) {
		return list1;
	}

	struct ListNode* mergedList;

	if (list1->val <= list2->val) {
		mergedList = list1;
		mergedList->next = mergeTwoLists(list1->next, list2);
	}
	else {
		mergedList = list2;
		mergedList->next = mergeTwoLists(list1, list2->next);
	}

	return mergedList;
}
#endif

//合并两个链表
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}

	struct ListNode* head = NULL, * tail = NULL;
	while (list1 && list2)
	{
		if (list1->val < list2->val)
		{
			if (tail == NULL)
			{
				head = tail = list1;
			}
			else
			{
				tail->next = list1;
				tail = tail->next;
			}

			list1 = list1->next;
		}
		else
		{
			if (tail == NULL)
			{
				head = tail = list2;
			}
			else
			{
				tail->next = list2;
				tail = tail->next;
			}

			list2 = list2->next;
		}
	}

	if (list1)
	{
		tail->next = list1;
	}

	if (list2)
	{
		tail->next = list2;
	}
	return head;
}

//链表中倒数第K个节点
struct ListNode* FindkthToTail(struct ListNode* plistHead, int k)
{
	struct ListNode* fast = plistHead, * slow = plistHead;
	while (k--)
	{
		if (fast == NULL)
			return NULL;

		fast = fast->next;
	}

	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

//返回倒数第K个节点的值
int kthToLast(struct ListNode* head, int k)
{
	struct ListNode* fast = head, * slow = head;
	while (k--)
	{
		if (fast == NULL)
			return NULL;

		fast = fast->next;
	}

	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow->val;
}