#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

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

void test_unimal_operator()
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

test_scanf_printf()
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

}

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

	//test_unimal_operator();

	test_scanf_printf();

	return 0;
}