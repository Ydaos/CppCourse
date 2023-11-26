#include<iostream>

/*
* 多继承：C++可以一个类继承多个类
* 语法：class 子类 :继承方式 父类1, 继承方式 父类2 ...
* 多继承可能会引发父类中有同名成员出现，需要加作用域区分
* C++实际开发中不推荐多继承
*/

namespace my_src5 {
	class Base1 {
	public:
		Base1() {
			m_A = 100;
		}

		int m_A;
	};

	class Base2 {
	public:
		Base2() {
			m_A = 150;
			m_B = 200;
		}

		int m_A;
		int m_B;
	};

	class Son :public  Base1, public Base2 {
	public:
		Son() {
			m_C = 300;
			m_D = 400;
		}

		int m_C;
		int m_D;
	};

	void Super() {
		Son s;
		std::cout << "sizeof Son = " << sizeof(Son) << std::endl;
		
		//当父类出现重名成员，需要加作用域区分
		std::cout << "Base1 m_A = " << s.Base1::m_A << std::endl;
		std::cout << "Base2 m_A = " << s.Base2::m_A << std::endl;
	}
}

int main05() {
	my_src5::Super();

	system("pause");
	return 0;
}