#include <iostream>

/*
* 静态成员：(成员变量和成员函数前加上关键字static)
*
* 静态成员变量：
* 所有对象共享同一份数据
* 在编译阶段分配内存 （全局区）
* 类内声明，类外初始化
*
* 静态成员函数：
* 所有对象共享同一个函数
* 静态成员函数只能访问静态成员变量
*/

/*
* 类的成员存储：
* 类的成员变量和成员函数是分开存储的：函数存储在代码区，变量存储在内存区
* 静态成员变量存储在全局数据区
* 非静态成员变量存储在栈区or堆区，只有非静态成员变量才属于类的对象
* 
* 注意：
* 空对象占有内存空间：1
* C++编译器会给每个对象也分配一个字节的空间，为了区分空对象占内存的位置
* 每个空对象也应该有一个独一无二的内存地址
*/

class sPerson {
public:
	//静态成员变量必须类内声明，类外初始化
	static int m_A;

	//静态成员变量也是有访问权限
private:
	static int m_B;

public:
	int m_C;

	//静态成员函数
	static void func() {
		m_A = 300;
		//m_C = 100; 不能访问非静态成员变量,编译器无法区分是那一个对象的m_C
		std::cout << "static func() 的调用\n";
	}
private:
	static void func2() {
		std::cout << "static func2() 的调用\n";
	}
};

int sPerson::m_A = 100; //类外初始化
int sPerson::m_B = 200;

//静态成员变量两种访问方式
void StaticVariate() {
	//1、通过对象进行访问
	sPerson p;
	std::cout << p.m_A << std::endl;

	//2、通过类名进项访问
	std::cout << sPerson::m_A << std::endl;
	//std::cout << Person::m_B << std::endl; 私有静态成员变量不可访问

	//静态成员变量不属于某个对象，所有对象都共享一个数据
	sPerson p2;
	p2.m_A = 200;
	std::cout << p.m_A << std::endl;
}

void test() {
	static int num = 0; //静态局部变量只初始化一次
	num++;
	std::cout << num << " "; //打印结果为 1~10
}

//静态成员函数两种访问方式
void StaticFunc() {
	//1、通过对象访问
	sPerson p;
	p.func();
	//p.func2(); 类外访问不到私有的静态成员函数

	//2、通过类名访问
	sPerson::func();
	std::cout << sPerson::m_A << std::endl;
}

void StaticMember() {
	std::cout << "This is a demo of static member variate.\n";
	StaticVariate();
	for (size_t i = 0; i < 10; i++) test();
	std::cout << std::endl;

	std::cout << "\nThis is a demo of static member function.\n";
	StaticFunc();

	std::cout << "\nThis is a demo of size of class member.\n";
	sPerson p;
	std::cout << "size of class:" << sizeof(sPerson) << std::endl;
	//结论：只有非静态成员变量才属于类的对象上
}

int main05() {
	StaticMember();

	system("pause");
	return 0;
}