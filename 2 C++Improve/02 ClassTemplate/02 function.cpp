#include <iostream>

namespace my_src2 {

	/*
	* 类模板成员函数创建时机
	* 1、普通类中的成员函数一开始就可以创建
	* 2、类模板中的成员函数在调用时才能创建
	*/

	class Person1 {
	public:
		void showPerson1() {
			std::cout << "Person1 show" << std::endl;
		}
	};

	class Person2 {
	public:
		void showPerson2() {
			std::cout << "Person2 show" << std::endl;
		}
	};

	template<class T>
	class MyClass {
	public:
		T obj;

		// 类模板中的成员函数
		void func1() {
			obj.showPerson1();
		}

		void func2() {
			obj.showPerson2();
		}
		// 成员函数后创建，因为不知道T类型，故无法确定T的成员函数调用
	};

	void Func() {
		MyClass<Person1> mc;
		mc.func1();
		//mc.func2(); Error！创建后确定了T的类型为Person1，所以只能调用func1(),调用func()会报错
	}
	
}

int main02() {
	my_src2::Func();

	system("pause");
	return 0;
}