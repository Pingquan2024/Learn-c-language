#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include "SList.h"

void testSList1()
{
	SLTNode* plist=NULL;
	SLPushFront(&plist,1);
	SLPushFront(&plist, 2);
	SLPushFront(&plist, 3);
	SLPushFront(&plist, 4);

	SLTPrint(plist);
}

int main()
{

	testSList1();

	return 0;
}