#include <iostream>

/*
* 函数定义步骤
* 1、返回值类型 void int double bool ...
* 2、函数名 add
* 3、参数列表
* 4、函数体语句
* 5、return表达式
*/

/* 
* 函数定义语法：
* 返回值类型 函数名称(参数列表)
* {
*	函数体语句
* }
*/

/*
* 定义加法函数
* 函数定义时，num1和num2并没有真实数据
* a和b只是一个形式的参数，简称形参
*/
int add(int num1, int num2)
{
	int sum = num1 + num2;
	return sum;
}

/*
* main函数中调用add函数 语法：函数名称 (参数)
* a和b称为实际参数，简称实参
* 当调用函数时，实参的值会传递给形参
*/
int main01() {
	int a = 10;
	int b = 20;
	int sum = add(a, b);
	std::cout << "a + b = " << sum << std::endl;

	system("pause");
	return 0;
}



