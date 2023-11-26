#include<iostream>

namespace my_src4 {

	/*
	* 类模板与继承
	* 1、当子类继承的父类是一个类模板是，子类在声明的时候要指定出父类中的T的类型
	* 2、如果不指定，编译器无法给子类分配内存
	* 3、如果想灵活指定出父类T中的类型，子类也需变为类模板s
	*/

	template <class T>
	class Base {
	public:
		T obj;
	};

	//class Son :public Base {};
	// Error!!! 必须要指定父类的T类型，才能继承给子类，否则无法知道要分配的内存空间
	
	class Son :public Base<int> {};

	//如果想灵活指定出父类T中的类型，子类也需变为类模板
	template<class T1, class T2>
	class Son2 :public Base<T1> {
	public:
		void printSon2() {
			std::cout << "T1：" << typeid(T1).name() << std::endl;
			std::cout << "T2：" << typeid(T2).name() << std::endl;
		}

		T2 obj;
	};

	void Func() {
		Son s1;

		Son2<int, char> s;
		s.printSon2();
	}
}

// 总结：如果父类是类模板，子类需要指定出父类中的T的数据类型

int main04() {
	my_src4::Func();

	system("pause");
	return 0;
}