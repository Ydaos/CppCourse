#include <iostream>
#include "MyArray.hpp"

namespace my_src7 {

	/*
	* ʵ��һ��ͨ�õ�������
	* 1�����Զ��������������Լ��Զ����������ͽ��д洢
	* 2�����������ݴ洢������
	* 3�����캯���п��Դ�����������
	* 4���ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
	* 5���ṩβ�巨��βɾ���������е�����������Ӻ�ɾ��
	* 6������ͨ���±�ķ�ʽ���������е�Ԫ��
	* 7�����Ի�ȡ�����е�ǰԪ�ظ��������������
	*/

	// 1�����������๹��
	void test1() {
		MyArray <int> arr1(5);
		MyArray <int> arr2(arr1);
		MyArray <int> arr3(100);
		arr3 = arr1;
	}

	// 2���������������ɾ�����±�Ѱַ
	void printArr(MyArray <int>& arr) {
		for (int i = 0; i < arr.getSize(); i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

	void test2() {
		MyArray <int> arr(5);
		for (int i = 0; i < 5; i++) {
			arr.push_back(i);// ����β�巨�������в�������
		}
		std::cout << "arr��β���ӡ���Ϊ��\n";
		printArr(arr);
		std::cout << "arr������" << arr.getCapacity() << std::endl;
		std::cout << "arr��С��" << arr.getSize() << std::endl;

		// ����βɾ��ɾ����������
		std::cout << "----------------------\n";
		std::cout << "arr��βɾ��ӡ���Ϊ��\n";
		arr.pop_back();
		printArr(arr);
		std::cout << "arr������" << arr.getCapacity() << std::endl;
		std::cout << "arr��С��" << arr.getSize() << std::endl;
	}

	// 3�������Զ�����������
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
			std::cout << "������" << arr[i].m_Name << " ���䣺" << arr[i].m_Age << std::endl;
		}
	}

	void test3() {
		MyArray<Person> arr(10);

		Person p1("Tom", 20);
		Person p2("Jerry", 20);
		Person p3("Hans", 20);
		Person p4("Mark", 20);
		Person p5("Tony", 20);

		// ������β����������
		arr.push_back(p1);
		arr.push_back(p2);
		arr.push_back(p3);
		arr.push_back(p4);
		arr.push_back(p5);
		printPersonArr(arr);
		std::cout << "arr������" << arr.getCapacity() << std::endl;
		std::cout << "arr��С��" << arr.getSize() << std::endl;
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