#include "list.h"

void TestList1()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);

	LTPrint(plist);

	LTPopBack(plist);
	LTPrint(plist);

	LTPopBack(plist);
	LTPrint(plist);

	LTPopBack(plist);
	LTPrint(plist);

	LTPopBack(plist);
	LTPrint(plist);

	//LTPopBack(plist);
	//LTPrint(plist);

	LTDestroy(plist);
	plist = NULL;
}

void TestList2()
{
	LTNode* plist = LTInit();
	LTPushFront(plist, 1);
	LTPushFront(plist, 2);
	LTPushFront(plist, 3);
	LTPushFront(plist, 4);
	LTPrint(plist);

	LTPopFront(plist);
	LTPrint(plist);

	LTPopFront(plist);
	LTPrint(plist);

	LTPopFront(plist);
	LTPrint(plist);

	LTPopFront(plist);
	LTPrint(plist);

	/*LTPopFront(plist);
	LTPrint(plist);*/

	LTDestroy(plist);
	plist = NULL;
}

int main()
{
	//TestList1();
	TestList2();
	return 0;
}