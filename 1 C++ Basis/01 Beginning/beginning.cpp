#include<iostream>

//1、#defube宏常量
#define Day 7

void m_constant() {
	std::cout << "\n ------------- constant demo ---------------------\n";
	//Day = 14; //错误，Day是常量，一旦修改就会报错
	std::cout << "一周总共有：" << Day << " 天" << std::endl;

	//2、const修饰的变量
	const int month = 12;
	//month = 14; //错误， const修饰的变量也称为常量

	std::cout << "一年总共有: " << month << " 个月份" << std::endl;
}

/*
  main函数是一个程序的入口
  每个程序必须有一个
  有仅有一个
*/
int main() {

	std::cout << "Hello World!" << std::endl;

	//变量创建的语法：数据类型 变量名 = 变量初始值
	int a = 10;
	std::cout << "a = " << a << std::endl;

	m_constant();

	//发起系统命令行调用，指令命令：pause；暂停程序，等待任意键继续执行。
	system("pause");
	return 0;
}

/*
* ‘关键字’是C++具有特殊含义的预先定义保留标识符；
* 对变量命名时不能使用关键字；
* 常见关键字有：
* 逻辑关键字：if do while break continue ...
* 数据类型关键字：int float double ...
* 函数关键字：void  main ...
* 其他关键字：namespace using class ...
*/

/*
* 标识符（给常量或变量命名）命名规则
* 1、不能是关键字
* 2、由字母、数字、下划线组成
* 3、开头第一个字符只能是字母或下划线
* 4、区分大小写
*/

/*
* 常量的定义方式
* 1、#define宏常量 #define 常量名 常量值
* 2、const修饰的变量 const 数据类型 常量名 = 常量值
*/
