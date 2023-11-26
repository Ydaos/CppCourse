#include <iostream>

namespace my_src1 {

	/*
	* 类模板
	* 语法：template<class T1, class T2, ...>
	* 
	* 类模板与函数模板区别：
	* 1、类模板没有自动类型推导的方式
	* 2、类模板在模板参数列表中可以有默认参数
	* 3、类模板成员函数可以类外实现
	*/

	template<class NameType, class AgeType>
	class Person {
	public:
		Person(NameType name, AgeType age) {
			m_name = name;
			m_age = age;
		}

		void showPerson() {
			std::cout << "name: " << m_name << " age: " << m_age << std::endl;
		}

		NameType m_name;
		AgeType m_age;
	};

	// 2、类模板在模板参数列表中可以有默认参数
	template<class NameType, class AgeType = int>
	class Person2 {
	public:
		Person2(NameType name, AgeType age) {
			m_name = name;
			m_age = age;
		}

		void showPerson() {
			std::cout << "name: " << m_name << " age: " << m_age << std::endl;
		}

		NameType m_name;
		AgeType m_age;
	};

	// 3、类模板成员函数的类外实现
	template<class T1, class T2>
	class Person3 {
	public:
		Person3(T1 name, T2 age);

		void showPerson();

		T1 m_name;
		T2 m_age;
	};

	// 类模板构造函数类外实现
	template<class T1, class T2>
	Person3<T1, T2>::Person3(T1 name, T2 age) {
		m_name = name;
		m_age = age;
	}

	// 类模板成员函数类外实现
	template<class T1, class T2>
	void Person3<T1, T2>::showPerson() {
		std::cout << "name: " << m_name << " age: " << m_age << std::endl;
	}

	void Func() {
		// Person p1("Tom", 20); Error!!! 无法使用自动类型推导
		Person<std::string, int> p1("Tom", 20);// True! 只能使用显示指定类型
		p1.showPerson();

		// Person2 的类模板参数列表指定了int型，所以声明时只需要显示指定string类型即可
		Person2<std::string> p2("Jerry", 20);
		p2.showPerson();

		Person3<std::string, int>p3("Lisa", 22);
		p3.showPerson();
	}
}

int main01() {
	my_src1::Func();

	system("pause");
	return 0;
}