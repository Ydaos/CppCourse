#include <iostream>

/*
* 继承中同名成员处理
* 1、子类对象可以直接访问子类中的同名
* 2、子类对象加作用域可以访问父类同名成员
* 3、当子类和父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类的同名成员函数
* 4、同名静态成员处理方式和非静态处理方式一样，只不过有两种访问方式（通过对象和通过类名）
*/

namespace my_src4 {

	class Base {
	public:
		Base() {
			m_A = 100;
		}

		void func() {
			std::cout << "Base - func() 调用\n";
		}

		void func(int a) {
			std::cout << "Base - func(int a) 调用\n";
		}

		//静态成员函数
		static void func1() {
			std::cout << "Base - static func() 调用\n";
		}

		static void func1(int a) {
			std::cout << "Base - static func(int a) 调用\n";
		}

		int m_A;
		static int m_B; //类内声明类外定义
	};
	int Base::m_B = 100;

	class Son :public Base {
	public:
		Son() {
			m_A = 200;
		}

		void func() {
			std::cout << "Son - func() 调用\n";
		}

		//静态成员函数
		static void func1() {
			std::cout << "Son - static func() 调用\n";
		}

		static void func1(int a) {
			std::cout << "Son - static func(int a) 调用\n";
		}

		int m_A;
		static int m_B;
	};
	int Son::m_B = 200;

	//同名（静态）成员属性处理方式
	void ClassVar() {
		Son s;
		std::cout << "Son 下的m_A = " << s.m_A << std::endl;        //直接调用调用的是子类的同名成员
		std::cout << "Base 下的m_A = " << s.Base::m_A << std::endl; //如果通过子类对象访问父类的同名成员，需要加作用域

		//1、通过类名访问静态同名成员
		std::cout << "Son 下的static m_B = " << s.m_B << std::endl;
		std::cout << "Base 下的static m_B = " << s.Base::m_B << std::endl;

		//2、通过作用域访问同名静态成员
		std::cout << "通过作用域访问 Son 下的static m_B = " << Son::m_B << std::endl;

		//第一个::代表通过类名方式访问，第二个::代表父类作用域
		std::cout << "通过作用域访问 Base 下的static m_B = " << Son::Base::m_B << std::endl;
	}

	//同名（静态）成员函数处理方式
	void ClassFunc() {
		Son s;
		s.func();       //直接调用调用的是子类的同名成员
		s.Base::func(); //如果通过子类对象访问父类的同名成员，需要加作用域

		//如果子类中出现了和父类同名的成员函数，子类的同名成员函数会隐蔽掉父类所有同名成员函数
		//如果想访问父类中被隐藏的同名成员函数，需要加作用域
		s.Base::func(10);

		//1、通过类名访问静态同名函数
		std::cout << "通过类名调用\n";
		s.func1();
		s.Base::func1();

		//2、通过作用域访问同名静态成员函数
		std::cout << "通过作用域调用\n";
		Son::func1();
		Son::Base::func1();
	}
}

int main04() {
	std::cout << "\n-------------- Demo of class variable --------------\n";
	my_src4::ClassVar();

	std::cout << "\n-------------- Demo of class function --------------\n";
	my_src4::ClassFunc();

	system("pause");
	return 0;
}