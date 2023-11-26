#include <iostream>

/*
* 运算符重载：对已有的运算符重新进行定义，赋予其另一种功能以适应不同数据类型
* 
* 算术运算符重载：+ - * /
* 两种方式：
* 1、成员函数重载（以加号为例）
* 2、全局函数重载（以乘号为例）
* 
* 注意事项：
* 对于内置的数据类型的表达式的运算符是不可能改变的
* 不要滥用运算符重载
*/

//1、成员函数重载+号
class Person {
public:
	Person(int a, int b) {
		m_A = a;
		m_B = b;
	}

	Person operator+(Person& p) {
		Person temp(m_A + p.m_A, m_B + p.m_B);
		return temp;
	}

	int m_A = 0;
	int m_B = 0;
};

//2、全局函数重载*号
Person operator*(Person& p1, Person& p2) {
	Person temp(p1.m_A * p2.m_A, p1.m_B * p2.m_B);
	return temp;
}

Person operator*(Person& p1, int num) {
	Person temp(p1.m_A * num, p1.m_B * num);
	return temp;
}

void Arithmetic() {
	//1、成员函数重载+号
	Person p1(10, 20);
	Person p2(10, 20);

	//成员函数重载本质调用：Person p3 = p1.operator+(p2);
	Person p3 = p1 + p2;
	std::cout << "p3:" << p3.m_A << " " << p3.m_B << std::endl;
	
	//2、全局函数重载*号
	//全局函数重载本质调用：Person p4 = operator*(p1, p2);
	Person p4 = p1 * p2;
	std::cout << "p4:" << p4.m_A << " " << p4.m_B << std::endl;

	//运算符重载也可以发生函数重载
	Person p5 = p1 * 10;
	std::cout << "p5:" << p5.m_A << " " << p5.m_B << std::endl;
}

int main() {
	Arithmetic();

	system("pause");
	return 0;
}