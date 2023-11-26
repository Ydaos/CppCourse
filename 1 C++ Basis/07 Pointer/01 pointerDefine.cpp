#include <iostream>

//指针作用：可以通过指针间接访问内存
//指针就是一个地址！！！
void PointerDefine() {
	//1、定义一个指针
	int a = 10;
	//指针定义的语法：数据类型 *指针变量名;
	int* p;
	//让指针记录变量a的地址
	p = &a;
	std::cout << "a的地址为：" << &a << std::endl;
	std::cout << "指针P为：" << p << std::endl;

	//2、使用指针
	//可以通过解引用的方式来找到指针指向的内存
	//指针前加*代表解引用，找到指针指向的内存中的数据
	*p = 1000;
	std::cout << "a = " << a << std::endl;
	std::cout << "p = " << *p << std::endl;

	//在32位操作系统下：指针占4个字节空间，64位占八个字节
	std::cout << "size of pointer: " << sizeof(p) << std::endl;

	//1、空指针用于给指针变量初始化
	int* p2 = NULL;

	//2、空指针不可访问
	//0~255之间的内存编号是系统占用的，因此不可访问
	//*p = 100; error!

	//野指针：指针变量指向非法的内存空间
	int* pf = (int*)0x1100;
	//cout << *pf << endl; error!!!!

	//总结：空指针和野指针都不是我们自己申请的空间，因此不要访问
}

int main01() {
	PointerDefine();

	system("pause");
	return 0;
}