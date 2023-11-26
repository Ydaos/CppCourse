#include<iostream>

/*
* 函数调用运算符重载
* 由于重载后使用的方法非常像函数的调用，因此称为仿函数
* 仿函数没有固定写法，非常灵活
*/

class MyPrint {
public:
	//重载函数调用运算符
	void operator()(std::string str) {
		std::cout << str << std::endl;
	}
};

void Print(std::string str) { //打印函数
	std::cout << str << std::endl;
}

class MyAdd {
public:
	int operator()(int num1, int num2) {
		return num1 + num2;
	}
};

void CallOperator() {
	// First demo
	MyPrint myPrint;
	myPrint("Hello World"); // 由于使用起来非常类似函数，因此称为仿函数
	Print("Hello World");	// 普通函数

	// Second demo
	MyAdd myAdd;
	int ret = myAdd(10, 20);
	std::cout << "ret = " << ret << std::endl;

	//匿名函数对象调用
	std::cout << MyAdd()(100, 100) << std::endl; //匿名对象，当行执行完就会被释放
}

int main06() {
	CallOperator();

	system("pause");
	return 0;
}