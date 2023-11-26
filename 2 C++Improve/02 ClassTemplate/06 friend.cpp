#include <iostream>

namespace my_src6 {

	/*
	* 类模板配合友元函数的类内和类外实现
	* 1、全局函数类内实现 - 直接在类内声明友元即可
	* 2、全局函数类外实现 - 需要提前让编译器知道全局函数的存在
	* 
	* 建议全局函数类内实现，用法简单而且编译器可以直接识别
	*/

	// 2、全局函数类外实现
	// 先让编译器知道Person存在，方便声明类外实现的全局函数模板
	template<class T1, class T2>
	class Person;

	// 全局函数类外实现在类定义前，方便编译器知道这个函数存在
	template<class T1, class T2>
	void printPerson2(Person<T1, T2> p) {
		std::cout << "类外实现" << std::endl;
		std::cout << "姓名：" << p.m_name << " 年龄：" << p.m_age << std::endl;
	}

	// 通过全局函数 打印person信息
	template<class T1, class T2>
	class Person {
		// 全局函数类内实现
		friend void printPerson(Person<T1, T2> p) {
			std::cout << "类内实现" << std::endl;
			std::cout << "姓名：" << p.m_name << " 年龄：" << p.m_age << std::endl;
		}

		// 全局函数类外实现
		// 如果全局函数是类外实现，需要让编译器知道这个函数的存在
		// 加空模板参数列表 告诉编译器是函数模板的声明
		friend void printPerson2<>(Person<T1, T2> p);

	public:
		Person(T1 name, T2 age) {
			m_name = name;
			m_age = age;
		}

	private:
		T1 m_name;
		T2 m_age;
	};

	void Func() {
		Person<std::string, int> p("Tom", 20);
		printPerson(p);

		printPerson2(p);
	}
}

int main06() {
	my_src6::Func();

	system("pause");
	return 0;
}