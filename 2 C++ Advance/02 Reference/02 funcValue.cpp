#include<iostream>

//作用：函数传参时，可以利用引用的技术让形参修饰实参
//优点：可以简化指针修改实参

//交换函数
//1、值传递
void mySwap1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	std::cout << "swap1 a = " << a << " b = " << b << std::endl;
}

//2、地址传递
void mySwap2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	std::cout << "swap2 a = " << *a << " b = " << *b << std::endl;
}

//3、引用传递
void mySwap3(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
	std::cout << "swap3 a = " << a << " b = " << b << std::endl;
}

//作用：常量引用主要用来修饰形参，防止误操作
//在函数形参中，可以加const修饰形参，防止形参改变实参

//打印函数
void showValue(const int& val) {
	//val = 1000; 加const防止误修改
	std::cout << "val = " << val << std::endl;
}

void FuncValue() {
	int a = 10;
	int b = 20;
	mySwap1(a, b); //值传递，形参不修饰实参
	std::cout << "a = " << a << "\tb = " << b << std::endl;

	mySwap2(&a, &b); //地址传递，形参会修饰实参
	std::cout << "a = " << a << "\tb = " << b << std::endl;

	mySwap3(a, b); //引用传递，形参会修饰实参
	std::cout << "a = " << a << "\tb = " << b << std::endl;
	//总结：通过引用参数产生的效果同按地址传递是一样的、引用的语法更清楚简单
	
	//int& b = 10; error! 引用必须引一块合法的内存空间
	//加上const之后，编译器将代码修改为 int temp = 10; const int& ref = temp;
	const int& ref = 10;
	//ref = 20; //加入const之后变为只读，不可以修改
	showValue(ref);
}

int main02() {
	FuncValue();

	system("pause");
	return 0;
}