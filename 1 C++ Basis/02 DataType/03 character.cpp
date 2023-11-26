#include <iostream>

/*
* 语法：char ch = 'a'; 
* 字符型变量只占用一个字节内存
* 字符型变量不是把字符本身存到内存中，而是将对应的ASCII编码放入存储单元
*/

void Character() {
	//1、字符型变量创建方式
	char ch = 'A';
	std::cout << "ch = " << ch << std::endl;

	//2、字符型变量所占空间大小
	std::cout << "字符型变量所占内存 " << sizeof(ch) << std::endl;

	//3、字符型变量常见错误
	//char ch2 = "b"; error! 创建字符型变量要用单引号
	//char ch3 = 'abcde'; error! 创建字符型变量单引号里面只能有一个字符

	//4、字符型变量对应的ASCII编码
	std::cout << "ASCII码：" << (int)ch << std::endl;
	//A - 65
	//a - 97
}

int main03() {
	Character();

	system("pause");
	return 0;
}