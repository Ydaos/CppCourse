#include <iostream>

/*
* 数据类型存在意义: 给变量分配合适的内存空间
* 
* sizeof：求出数据内存所占内存大小
* 语法：sizeof(数据类型 / 变量)
* 
* 转义字符：用于表示一些不能显示的ASCII字符 \n \t \\
* 换行符 \n 
* 反斜杠 \\
* 水平制表符 \t 作用可以整齐的输出数据 \t一共占八个空格
*/

void Integer() {
	//整型
	//1、短整型 short（-32768~32767）2字节16位
	short num1 = 32769;//溢出数据范围，打印结果-32767

	//2、整型 int 4字节32位
	int num2 = 32789;

	//3、长整型 long win 4字节32位；Linux（x32）4字节；（x64）8字节
	long num3 = 10;

	//4、长长整型 long long 8字节64位
	long long num4 = 10;

	std::cout << num1 << "\t" << num2 << "\t" << num3 << "\t" << num4 << std::endl;
}

int main01() {
	std::cout << "int占用内存空间为：" << sizeof(int) << std::endl;

	//转义字符：用于表示一些不能显示的ASCII字符
	std::cout << "aaaa\tHello World\n";
	std::cout << "aa\tHello World\n";

	Integer();

	system("pause");
	return 0;
}