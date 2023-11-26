#include <iostream>

/*
* 程序运行后
* 栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
* 注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
* 
* 堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收
* 在C++中主要利用new在堆区开辟内存
*/

int* func(int b) { //形参数据也会存放在栈区
	b = 20;
	int a = 10; //局部变量 存放在栈区，栈区的数据在函数执行完后自动释放
	return &a; //返回局部变量的地址
}

int* func2() {
	//利用new关键字 可以将数据开辟到堆区
	//指针本质也是局部变量，放在栈上，指针保存的数据是放在堆区
	int* p = new int(10);
	return p;
}

void func3() {
	//在堆区利用new开辟数组
	int* arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << std::endl;
	}

	//释放堆区数组
	//释放数组的时候，要加[]才可以
	delete[] arr;
}

void Memory02() {
	//栈区
	//接收func函数的返回值
	int* p = func(1);
	std::cout << "*p的值：" << *p << std::endl; //第一次可以打印正确数字，是因为编译器做了保留
	std::cout << "*p的值：" << *p << std::endl; //第二次数据不再保留
	//总结：不要返回局部变量的地址

	//在堆区开辟数据
	int* p2 = func2();
	std::cout << *p2 << std::endl;
	std::cout << *p2 << std::endl;
	//堆区的数据由程序员管理开辟，程序员管理释放
	
	delete p2; //如果向释放堆区数据，利用关键字 delete
	//cout << *p << endl; //内存已释放，再次访问就是非法操作

	//在堆区利用new开辟数组
	func3();
}

int main() {
	Memory02();

	system("pause");
	return 0;
}