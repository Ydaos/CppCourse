#include <iostream>
#include "MyArray.hpp"

namespace my_src7 {

	/*
	* 实现一个通用的数组类
	* 1、可以对内置数据类型以及自定义数据类型进行存储
	* 2、将数组数据存储到堆区
	* 3、构造函数中可以传入数组容量
	* 4、提供对应的拷贝构造函数以及operator=防止浅拷贝问题
	* 5、提供尾插法和尾删法对数组中的数组进行增加和删除
	* 6、可以通过下标的方式访问数组中的元素
	* 7、可以获取数组中当前元素个数和数组的容量
	*/

	// 1、测试数组类构造
	void test1() {
		MyArray <int> arr1(5);
		MyArray <int> arr2(arr1);
		MyArray <int> arr3(100);
		arr3 = arr1;
	}

	// 2、测试数组类插入删除及下标寻址
	void printArr(MyArray <int>& arr) {
		for (int i = 0; i < arr.getSize(); i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

	void test2() {
		MyArray <int> arr(5);
		for (int i = 0; i < 5; i++) {
			arr.push_back(i);// 利用尾插法向数组中插入数据
		}
		std::cout << "arr的尾插打印输出为：\n";
		printArr(arr);
		std::cout << "arr容量：" << arr.getCapacity() << std::endl;
		std::cout << "arr大小：" << arr.getSize() << std::endl;

		// 利用尾删法删除数组数据
		std::cout << "----------------------\n";
		std::cout << "arr的尾删打印输出为：\n";
		arr.pop_back();
		printArr(arr);
		std::cout << "arr容量：" << arr.getCapacity() << std::endl;
		std::cout << "arr大小：" << arr.getSize() << std::endl;
	}

	// 3、测试自定义数据类型
	class Person {
	public:
		Person() {
			m_Age = 0;
		}

		Person(std::string name, int age) {
			m_Name = name;
			m_Age = age;
		}

		std::string m_Name;
		int m_Age;
	};

	void printPersonArr(MyArray <Person>& arr) {
		for (int i = 0; i < arr.getSize(); i++) {
			std::cout << "姓名：" << arr[i].m_Name << " 年龄：" << arr[i].m_Age << std::endl;
		}
	}

	void test3() {
		MyArray<Person> arr(10);

		Person p1("Tom", 20);
		Person p2("Jerry", 20);
		Person p3("Hans", 20);
		Person p4("Mark", 20);
		Person p5("Tony", 20);

		// 将数据尾插入数组中
		arr.push_back(p1);
		arr.push_back(p2);
		arr.push_back(p3);
		arr.push_back(p4);
		arr.push_back(p5);
		printPersonArr(arr);
		std::cout << "arr容量：" << arr.getCapacity() << std::endl;
		std::cout << "arr大小：" << arr.getSize() << std::endl;
	}
}


int main() {
	std::cout << "\n---------------------- test constructor\n";
	my_src7::test1();

	std::cout << "\n---------------------- test insert and delete\n";
	my_src7::test2();

	std::cout << "\n---------------------- test custom data type\n";
	my_src7::test3();

	system("pause");
	return 0;
}