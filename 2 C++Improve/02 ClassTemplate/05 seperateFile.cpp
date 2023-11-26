#include <iostream>
/*
* 类模板分文件编写
* 问题：类模板中成员函数创建时机是调用阶段，导致分文件编写时链接不到
* 
* 解决方法：
* 方式1、直接包含 .cpp源文件（不常用 因为一般不包含.cpp 文件）
* 方式2、将声明和实现写到同一个文件中，并更改后缀为 .hpp，.hpp是约定的名称，并不强制
*/

#include "person.hpp"

int main05() {
	Person<std::string, int> p("Tom", 20);
	p.showPerson();

	system("pause");
	return 0;
}