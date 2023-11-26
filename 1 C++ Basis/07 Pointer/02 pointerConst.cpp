#include <iostream>

//1、const修饰指针 --常量指针
//2、const修饰常量 --指针常量
//3、const即修饰指针，又修饰常量

void PointerConst() {
	//1、const修饰指针 --常量指针
	int a = 10, b = 20;
	const int* p1 = &a;
	//特点：指针的指向可以改，但指针指向的值不可改
	//*p1 = 20; error!!!指针指向的值不可改
	p1 = &b; //正确 指针指向可以改

	//2、const修饰常量 --指针常量
	int* const p2 = &a;
	//特点：指针的指向不可改，但指针指向的值可以改
	*p2 = 20; //正确，指向的值可以改
	//p = &b; error!!!指针指向不可改

	//3、const即修饰指针，又修饰常量
	const int* const p3 = &a;
	//特点：指针指向和指针指向的值都不可以改
	//*p3 = 20; //error!!
	//p3 = &b; //error!!!
}

int main02() {
	PointerConst();

	system("pause");
	return 0;
}