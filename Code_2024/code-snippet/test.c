#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

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


//反转链表
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}

	struct ListNode* n1 = NULL;
	struct ListNode* n2 = head;
	struct ListNode* n3 = n2->next;

	while (n2)
	{
		n2->next = n1;

		//迭代
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}

	return n1;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//分割链表
struct ListNode* partition(struct ListNode* head, int x) {
	struct ListNode* small = malloc(sizeof(struct ListNode));
	struct ListNode* smallHead = small;
	struct ListNode* large = malloc(sizeof(struct ListNode));
	struct ListNode* largeHead = large;
	while (head != NULL) {
		if (head->val < x) {
			small->next = head;
			small = small->next;
		}
		else {
			large->next = head;
			large = large->next;
		}
		head = head->next;
	}
	large->next = NULL;
	small->next = largeHead->next;
	return smallHead->next;
}


//回文结构
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* prev = NULL;
	struct ListNode* curr = head;
	while (curr != NULL) {
		struct ListNode* nextTemp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextTemp;
	}
	return prev;
}

struct ListNode* endOfFirstHalf(struct ListNode* head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

bool isPalindrome(struct ListNode* head) {
	if (head == NULL) {
		return true;
	}

	// 找到前半部分链表的尾节点并反转后半部分链表
	struct ListNode* firstHalfEnd = endOfFirstHalf(head);
	struct ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

	// 判断是否回文
	struct ListNode* p1 = head;
	struct ListNode* p2 = secondHalfStart;
	bool result = true;
	while (result && p2 != NULL) {
		if (p1->val != p2->val) {
			result = false;
		}
		p1 = p1->next;
		p2 = p2->next;
	}

	// 还原链表并返回结果
	firstHalfEnd->next = reverseList(secondHalfStart);
	return result;
}


//搜索插入位置
int searchInsert(int* nums, int numsSize, int target)
{
	int left = 0;
	int right = numsSize - 1;
	int ans = numsSize;
	while (left <= right)
	{
		int mid = left + ((right - left) / 2);
		if (nums[mid] >= target)
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return ans;
}

//环形链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode* head)
{
	struct ListNode* slow = head, * fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			return true;
		}
	}

	return false;
}


//环形链表2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head)
{
	struct ListNode* slow = head, * fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		//带环
		if (slow == fast)
		{
			//求入点
			struct ListNode* meet = slow;
			while (head != meet)
			{
				head = head->next;
				meet = meet->next;
			}
			return meet;
		}
	}

	return NULL;
}


//单身狗1
int singleNumber(int* nums, int numsSize)
{
	int n = 0;
	for (int i = 0; i < numsSize; i++)
	{
		n ^= nums[i];
	}
	return n;
}


//66. 加一
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	for (int i = digitsSize - 1; i >= 0; --i)
	{
		digits[i] = digits[i] + 1;//最后元素+1判断是不是10
		//如果当前元素不为10，直接返回数组
		if (digits[i] != 10)
		{
			*returnSize = digitsSize;
			return digits;
		}
		//第一个元素不为10，后面元素均为10的情况
		if (digits[i] == 10)
			digits[i] = 0;
	}
	//元素全为9开辟新数组
	int* ans = malloc(sizeof(int) * (digitsSize + 1));
	memset(ans, 0, sizeof(int) * (digitsSize + 1));//全部置0
	ans[0] = 1;
	*returnSize = digitsSize + 1;
	return ans;
}


//二进制加一
void reserve(char* s) 
{
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++) 
	{
		char t = s[i];
		s[i] = s[len - i - 1], s[len - i - 1] = t;
	}
}

char* addBinary(char* a, char* b) 
{
	reserve(a);
	reserve(b);

	int len_a = strlen(a), len_b = strlen(b);
	int n = fmax(len_a, len_b), carry = 0, len = 0;
	char* ans = (char*)malloc(sizeof(char) * (n + 2));
	for (int i = 0; i < n; ++i) 
	{
		carry += i < len_a ? (a[i] == '1') : 0;
		carry += i < len_b ? (b[i] == '1') : 0;
		ans[len++] = carry % 2 + '0';
		carry /= 2;
	}

	if (carry) 
	{
		ans[len++] = '1';
	}
	ans[len] = '\0';
	reserve(ans);

	return ans;
}



