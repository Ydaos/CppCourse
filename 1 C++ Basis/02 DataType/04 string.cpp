#include <iostream>
#include <string> //2019VS不需要即可声明string类型 但应该有这个好习惯

void String() {

	//C风格字符串： char 变量名[] = "字符串值"
	//注意事项：char字符串名[]
	//注意事项2：等号后面加双引号包含起来字符串值
	char str1[] = "Hello World";
	std::cout << "str1 = " << str1 << std::endl;

	//C++风格字符串：string 变量名 = "字符串值"
	//包含头文件 #include <string>
	std::string str2 = "Hello World";
	std::cout << "str2 = " << str2 << std::endl;
}

int main04() {
	String();

	system("pause");
	return 0;
}