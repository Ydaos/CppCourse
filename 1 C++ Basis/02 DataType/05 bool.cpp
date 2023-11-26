#include <iostream>

/*
* 布尔数据类型代表真或假的值
* true 真（本质是1）
* false 假（本质是0）
* bool型数据只占用一个字节大小
*/

void Bool() {
	//1、创建布尔型数据
	bool flag = true; //真
	std::cout << flag << std::endl;
	flag = false;
	std::cout << flag << std::endl;
	//本质上1代表是真的值；0代表假的值

	//布尔类型所占内存空间
	std::cout << "布尔型所占内存空间 " << sizeof(bool) << std::endl;
}

int main05() {
	Bool();

	system("pause");
	return 0;
}