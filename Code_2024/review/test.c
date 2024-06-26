﻿#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"

void test_ascii()
{
	int i = 0;
	for (i = 32; i <= 127; i++)
	{
		printf("%c ", i);
		if (i % 16 == 15)
		{
			printf("\n");
		}
	}

	/*32是空格*/
}

void test_string()
{
	printf("%s\n", "hello c");
	printf("hello c");

	char arr1[] = { 'a','b','c' };
	char arr2[] = "abc";
	printf("%s\n", arr1);	/*没有'\0'打印发生越界*/
	printf("%s\n", arr2);

	/*字符串的末尾隐藏的放着一个'\0'*/
	/*这个是字符串的结束标志*/

	char arr3[] = { 'a','b','c','\0' };
	printf("%s\n", arr3);
	printf("%s\n", "abc\0def");
}

/*escape character(ESC) ---> 转义字符*/
void test_ESC()
{
	printf("abcndef");
	printf("abc\ndef");    /*'\n'表示换行*/
	printf("abc\\ndef");

	printf("\n");
	printf("1\a警报");
	printf("2\b退格键");
	printf("3\f换页符");
	printf("4\r回车符");
	printf("5\t制表符");
	printf("6\v垂直分隔符");

	printf("%c\n", '\132');
	/*\ddd ：d d d表⽰1~3个八进制的数字。如：\132 表⽰字符Z */
	printf("%c\n", '\30');
	/*xdd :  dd表示2个十六进制的数字。如：\30表示字符0 */
}

void test_expression_statement()
{
	int a = 10;
	int b = 9;
	b = a + 3;
	printf("%d %d\n", a, b);

	unsigned int c = 25;
	printf("% u\n", c);

	char d = 'd';
	printf("%c\n", d + 2);
}

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

void test_add()
{
	printf("函数调用语句\n");

	int ret1 = Add(12, 35);
	printf("Add:%d\n", ret1);

	int ret2 = Sub(65, 32);
	printf("Sub:%d\n", ret2);
}

void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test_compound_statement()
{
	int arr[11] = { 12,13,14,15,16,17,18,19,20,21,22 };
	print(arr, 11);

	int j = 0;
	for (j = 10; j > 0; j--)
	{
		printf("%d ", arr[j] - j);
	}

	/*for循环的循环体的⼤括号中的就是复合语句*/
}

void test_annotation()
{
	int x = 0;	//这是注释

	/*这也是注释*/

	printf("//hello/*world*/nihao\n");
	//两种注释都不能放在双引号里边，会失去注释作用

	int fopen1(char* s /*file name*/, int mode);

	//     min/*这里是一个注释*/Value;    ---> 注释会被替换成一个空格min Value
}

void test_data_type()
{
	/*int double short char _Bool  unsigned int...*/
	_Bool flag = true;
	if (flag)
	{
		printf("I like c\n");
	}

	printf("%zd\n", sizeof(long long));

	int arr1[] = { 1,2,3,4,5 };
	size_t size = sizeof arr1;			/*操作数是表达式的话，括号可省略*/
	printf("%zu\n", size);

	printf("-----------------------------------\n");
	printf("[char]:%zd\n", sizeof(char));
	printf("[_Bool]:%zd\n", sizeof(_Bool));
	printf("[short]:%zd\n", sizeof(short));
	printf("[int]:%zd\n", sizeof(int));
	printf("[long]:%zd\n", sizeof(long));
	printf("[long long]:%zd\n", sizeof(long long));
	printf("[float]:%zd\n", sizeof(float));
	printf("[double]:%zd\n", sizeof(double));
	printf("[long double]:%zd\n", sizeof(long double));
	printf("-----------------------------------\n");

	//sizeof中表达式不计算
	short s = 2;
	int b = 10;
	printf("%zu\n", sizeof(s = b + 1));    //2
	printf("s = %d\n", s);

	//数据大小
	printf("[signed short int]:%d\n", SHRT_MAX);
	printf("[signed int]:%d\n", INT_MAX);
	/*详细见limits.h*/
}

/*全局变量*/
signed global = 1970;
int n = 100;

void test_varible()
{
	/*局部变量*/
	int age = 22;
	double weight = 70.2;
	char ch = 'f';
	int n = 24;

	printf("%d\n", n);  //局部变量优先 24
}

/*栈区、堆区、静态区*/

void test_Arithmetic_operator()
{
	int x = 21 + 24;
	int y = 54 - 45;
	printf("%d %d\n", x, y);
	printf("%d\n", x * y);
	printf("%d\n", x / y);

	float a = 6 / 4;
	int b = 6 / 4;
	double c = 6.0 / 4;
	printf("%.2f %d %.2lf \n", a, b, c);  //1.0  1 1.5
	/*整数除法和小数除法*/

	int z = 6 % 4;
	puts("取模运算（取余数）");
	printf("%d ", z);
	printf("%d ", -11 % 5);
	printf("%d ", 11 % -5);
	printf("%d ", -11 % -5);
}

void test_assignment_operator()
{
	int a = 0;   //初始化
	a = 20;      //赋值

	int b = 9;
	int c = 10;
	int d = 0;
	d = b = c + a;
	printf("%d %d %d %d\n", a, b, c, d);

	a = a + 3;
	b += 2;
	c -= 3;
	printf("%d %d %d %d\n", a, b, c, d);

	int x = 2;
	x *= 3;
	int y = 100;
	y /= 10;
	printf("%d %d\n", x, y);
}

void test_monocular_operators()
{
	int a = 10;
	int b = ++a;	//++的操作数是a，是放在a的前⾯的，就是前置++ 
	printf("a=%d b=%d\n", a, b);

	int c = 10;
	c = c + 1;
	int d = a;
	printf("a=%d b=%d\n", a, b);

	int x = 10;
	int y = x++;	//++的操作数是a，是放在a的后⾯的，就是后置++ 
	printf("x=%d y=%d\n", x, y);

	int z = 10;
	int f = z;
	z = z + 1;
	printf("z=%d f=%d\n", z, f);

	/*前置--和后置--同理*/

	int e = (int)3.14;   //强制类型转换
}

void test_scanf_printf()
{
	printf("%s will come tonight\n", "zhangsan");
	printf("There are %d apples\n", 3);
	printf("%s says it is %d o'clock\n", "lisi", 21);

	/*占位符*/

	printf("%5d\n", 132);
	/*限定宽度，默认右对齐*/

	printf("%-5d\n", 132);
	printf("%12f\n", 123.45);

	printf("%+d\n", 12);
	printf("%-d\n", -12);
	printf("Number is %.2f\n", 0.5);

	//如果有 n 个占位符,printf() 的参数就应该有 n + 1 个

	/*占位符列举*/
	/*%a %A %c %d %e %E %i %f %g %G %hd %ho %hx %hu %Le %n %p %s %zd  ...*/

	printf("%6.2f\n", 0.5);
	//%*.*f 的两个星号通过 printf() 的两个参数 6 和 2 传⼊
	printf("%*.*f\n", 6, 2, 0.5);
	//可以⽤% .[m]s 指定输出的⻓度，其中[m] 代表⼀个数字
	printf("%.5s\n", "hello world");


	int score = 0;
	printf("请输入成绩：");
	scanf("%d", &score);		//将⽤⼾从键盘输⼊的整数存⼊变量score
	printf("成绩是：%d\n", score);

	//scanf("%d%d%f%f", &i, &j, &x, &y);
	int a = 0;
	int b = 0;
	float f = 0.0f;
	int r = scanf("%d %d %f", &a, &b, &f);
	printf("a=%d b=%d f=%f\n", a, b, f);
	printf("r = %d\n", r);

	//%[]  遇到不在集合之中的字符，匹配将会停⽌
	char tel[11];
	scanf("%11s\n", tel);  //读够11个字符停止
	printf("name = %s\n", tel);

	int year = 0;
	int month = 0;
	int day = 0;
	scanf("%d%*c%d%*c%d", &year, &month, &day);   //%*赋值忽略符 --%*c 表示忽略一个字符
	printf("%d-%d-%d\n", year, month, day);
}

void test_Branching_looping()
{
	int age = 0;
	scanf("%d", &age);
	if (age >= 18)
	{
		printf("成年\n");
	}
	else
	{
		printf("未成年\n");
	}

	int num = 0;
	scanf("%d", &num);
	if (num == 0)
		printf("输入的数字是0\n");
	else if (num > 0) //这⾥的if 相当于嵌套在els语句中，形成了嵌套结构 
		printf("输入的数字是正数\n");
	else
		printf("输入的数字是负数\n");

	//也可以嵌套使用
	int num1 = 0;
	scanf("%d", &num1);
	if (num1 > 0)
	{
		if (num1 % 2 == 0)
			printf("偶数\n");
		else
			printf("奇数\n");
	}
	else
	{
		printf("非正数\n");
	}

	/*悬空else问题*/
	//else 总是跟最接近的 if 匹配
	int a = 0;
	int b = 2;
	if (a == 1)
		if (b == 2)
			printf("hehe\n");
		else
			printf("haha\n");     //错误示范  改代码什么都不打印

	int a2 = 0;
	int b2 = 2;
	if (a2 == 1)
	{
		if (b2 == 2)
			printf("hehe\n");
		else
			printf("haha\n");	//好的写法避免出错 
	}

	/* or else和第一个if匹配*/

	int a3 = 0;
	int b3 = 2;
	if (a3 == 1)
	{
		if (b3 == 2)
			printf("hehe\n");
	}
	else
	{
		printf("haha\n");  //好的写法
	}
}

void test_relational_operator()
{
	//a. 0 表⽰假，所有⾮零值表⽰真
	//b. = 和 == 不要混淆
	//c. i < j < k，多个关系运算符不宜连⽤
	//d. 合理运用 注意逻辑关系

	int age = 0;
	scanf("%d", &age);
	if (age >= 18 && age <= 36)
	{
		printf("青年\n");
	}
}

void test_conditional_operator()
{
	// exp1 ? exp2 : exp3
	int a = 20;
	int b = 10;
	b = a > 5 ? 3 : -3;
	printf("%d\n", b);

	scanf("%d %d", &a, &b);
	int m = a > b ? a : b;
	printf("%d\n", m);
}

void test_logical_operator()
{
	// !非 &&与 ||或
	int flag = 0;
	if (!flag)
	{
		printf("do something\n");
	}

	int month = 4;
	if (month >= 3 && month <= 5)
	{
		printf("春季\n");
	}

	scanf("%d", &month);
	if (month == 12 || month == 1 || month == 2)
	{
		printf("冬季\n");
	}

	// 闰年
	//（year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)

	// 短路求值
	/* 对于&& 操作符来说，左边操作数的结果是0的时候，右边操作数就不再执⾏。*/

	// ||操作符的左操作数的结果不为 0 时，就无需执行右操作数

}

void test_if_else_switch()
{
	//switch (expression)
	//{
	//case value1: statement
	//	break;
	//case value2: statement
	//	break;
	//default: statement
	//	break;
	//}

	/* expression、case后面的必须为整形表达式*/

	int n = 0;
	scanf("%d", &n);
	if (n % 3 == 0)
		printf("整除，余数为0\n");
	else if (n % 3 == 1)
		printf("余数是1\n");
	else
		printf("余数是2\n");

	int n2 = 0;
	scanf("%d", &n);
	switch (n2 % 3)
	{
	case 0:
		printf("整除，余数为0\n");
		break;
	case 1:
		printf("余数是1\n");
		break;
	case 2:
		printf("余数是2\n");
		break;
	}
}

void test_while()
{
	int i = 1;
	while (i <= 10)
	{
		printf("%d ", i);
		i = i + 1;
	}
	printf("\n");


	i = 1024;
	while (i)
	{
		printf("%d ", i % 10);
		i /= 10;
	}
}

void test_for()
{
	// 1.表达式1：初始化
	// 2.表达式2：判断
	// 3.表达式3：调整
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	int i = 0;
	int sum = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
			sum += i;
	}
	printf("%d\n", sum);
}

void test_do_while()
{
	int i = 1;
	do
	{
		printf("%d ", i);
		i++;
	} while (i <= 10);

	printf("\n");

	int n = 100;
	int cnt = 0;
	do
	{
		cnt++;
		n = n / 10;
	} while (n);
	printf("%d \n", cnt);
}

/* break和continue语句 */
// break的作用是用于永久的的终止循环
// continue的作用是跳过本次循环continue后边的代码

void test_nested_loops()
{
	for (int i = 100; i <= 200; i++)
	{
		//判断是否为素数
		//循环产生2~i-1之间的数字
		int flag = 1;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			printf("%d ", i);
		}
	}
}

void test_goto()
{
	printf("hello\n");
	goto next;
	printf("ahhaha\n");

next:
	printf("跳过了ahaha的打印\n");

	//	if (err)
	//	{
	//		goto error;
	//	}
	//
	//error:
	//	//解决

		/* 多层for循环快速跳出*/
}

void test_array()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i1 = 0;
	for (i1 = 0; i1 < 10; i1++)
	{
		printf("&arr[%d] = %p\n ", i1, &arr1[i1]);
	}

	int arr2[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
	printf("%d\n", arr2[2][4]);

	//int n = 1 + 5; 
	//int arr3[n];	c99
}

void test_array_to_middle()
{
	char arr1[] = "....welcome....";
	char arr2[] = "###############";
	int left = 0;
	int right = (int)strlen(arr1) - 1;
	printf("%s\n", arr2);
	while (left <= right)
	{
		Sleep(1000);
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		left++;
		right--;
		printf("%s\n", arr2);
	}
}

void test_binary_search()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	int left = 0, right = sizeof(arr) / sizeof(arr[0]) - 1;
	int key = 12;
	int flag = 0, cnt = 0;
	while (left <= right)
	{

		int mid = left + (right - left) / 2;

		if (arr[mid] < key)
		{
			left = mid + 1;
			cnt++;
		}
		else if (arr[mid] > key)
		{
			right = mid - 1;
			cnt++;
		}
		else
		{
			flag = 1;
			cnt++;
			break;
		}
	}

	if (flag == 1)
	{
		printf("找到了%d,下标为:%d\n", key, right);
		printf("查找次数为：%d\n", cnt);
	}
	else
	{
		printf("你要找的%d,不存在\n", key);
	}
}

/* 调试 */

int Fact(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * Fact(n - 1);
	}
}

void test_recursive()
{
	int ret = Fact(10);
	printf("%d\n", ret);
}

void test1()
{
	int n = 10;
	int m = 20;
	int* p = &n;
	*p = 20;	// √     
	p = &m;		// √ 
}

void test2()
{
	//代码2 
	int n = 10;
	int m = 20;
	const int* p = &n;
	// *p = 20;	 // ×    
	p = &m;		 // √ 
}

void test3()
{
	int n = 10;
	int m = 20;
	int* const p = &n;
	*p = 20;	    // √
	// p = &m;		// ×
}

void test4()
{
	int n = 10;
	int m = 20;
	int const* const p = &n;
	// *p = 20; // ×    
	// p = &m;  // ×
}

/*模拟strlen*/
size_t mystrlen(const char* str)
{
	assert(str);
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}

	return count;
}

void test5(int arr[])
{
	int sz2 = sizeof(arr) / sizeof(arr[0]);
	printf("sz2 = %d\n", sz2);
}

void test6(int arr[])	// 参数写成数组形式，本质上还是指针 
{
	printf("%d\n", sizeof(arr));
}

void test7(int* arr)	// 参数写成数组形式，本质上还是指针 
{
	printf("%d\n", sizeof(arr));
}

void test_pointer()
{
	//test1();
	//test2();
	//test3();
	//test4();

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz1 = sizeof(arr) / sizeof(arr[0]);
	printf("sz1 = %d\n", sz1);				// 10
	test5(arr);								// 1
	test6(arr);								// 4
	test7(arr);								// 4
}

void test01(int  a[3][5], int r, int c)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void test02(int(*p)[5], int r, int c)	// p 数组指针
{
	int i = 0;
	int j = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}


void test_two_dimensional_array()
{
	int arr[3][5] = { {1,2,3,4,5}, {2,3,4,5,6},{3,4,5,6,7} };
	test01(arr, 3, 5);
	printf("\n");
	test02(arr, 3, 5);
}


/* 函数名就是函数的地址 */

void test_function_pointer()
{
	//int(*pf)(int x, int y) = Add;
	int(*pf)(int, int) = Add;
	printf("%d\n", (*pf)(2, 3));
	printf("%d\n", pf(3, 5));			// C语言会隐式地对pf3进行解引用
}

int Mul(int a, int b)
{
	return a * b;
}

int Div(int a, int b)
{
	return a / b;
}

void test_function_pointer_array()
{
	int x, y;
	int input = 1;
	int ret = 0;
	int(*p[5])(int x, int y) = { 0, Add, Sub, Mul, Div }; // 转移表 
	do {
		printf("*************************\n");
		printf("  1:add           2:sub  \n");
		printf("  3:mul           4:div  \n");
		printf("  0:exit                 \n");
		printf("*************************\n");
		printf("请选择：");
		scanf("%d", &input);
		if ((input <= 4 && input >= 1))
		{
			printf("输入操作数：");
			scanf("%d %d", &x, &y);
			ret = (p[input])(x, y);
			printf("ret = %d\n", ret);
		}
		else if (input == 0)
		{
			printf("退出计算器\n");
		}
		else
		{
			printf("输入有误\n");
		}
	} while (input);
}


int int_cmp(const void* p1, const void* p2)
{
	return (*(int*)p1 - *(int*)p2);
}

void _swap(void* p1, void* p2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}

void bubble(void* base, int count, int size, int(*cmp)(void*, void*))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
			{
				_swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
	}
}

void test_myqsort()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int i = 0;
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

#if 1
int main()
{
	//test_ascii();

	//test_string();

	//test_ESC();

	//test_expression_statement();

	//test_add();

	//test_compound_statement();

	//test_annotation();

	//test_data_type();

	//test_varible();

	//test_Arithmetic_operator();

	//test_assignment_operator();

	//test_monocular_operators();

	//test_scanf_printf();

	//test_Branching_looping();

	//test_relational_operator();

	//test_conditional_operator();

	//test_logical_operator();

	//test_if_else_switch();

	//test_while();

	//test_for();

	//test_do_while();

	//test_nested_loops();

	//test_goto();

	//test_array();

	//test_array_to_middle();

	//test_binary_search();

	//test_recursive();

	//test_pointer();

	//test_two_dimensional_array();

	//test_function_pointer();

	//test_function_pointer_array();

	test_myqsort();

	return 0;
}
#endif // !1

