#include<iostream>

//初始化列表
//语法：构造函数():属性1(值1),属性2(值2),属性3(值3)...{}

class Person {
public:
	//传统初始化操作
	/*Person(int a,int b,int c) {
		m_A = a;
		m_B = b;
		m_C = c;
	}*/

	//初始化列表初始化属性
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {

	}

	~Person() {
		std::cout << "Person的析构函数调用\n";
	}

public:
	int m_A;
	int m_B;
	int m_C;
};

void InitList() {
	Person p1(10, 20, 30);
	std::cout << p1.m_A << std::endl;
	std::cout << p1.m_B << std::endl;
	std::cout << p1.m_C << std::endl;
}

int main03() {
	InitList();

	system("pause");
	return 0;
}