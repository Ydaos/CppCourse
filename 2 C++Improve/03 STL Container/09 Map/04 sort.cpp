#include <iostream>
#include <map>

/*
* map的排序：
* map默认排序是按照key值从小到大排序，利用仿函数可以改变排序规则
* 对于自定义类型，map必须指定排序规则，同set容器
*/

// 1、利用仿函数改变默认排序规则
class MyCompare {// 降序
public:
	bool operator()(int v1, int v2)const {
		return v1 > v2;
	}
};

void MySort01() {
	std::map<int, int, MyCompare> m1;
	m1.insert(std::pair<int, int>(1, 10));
	m1.insert(std::pair<int, int>(3, 20));
	m1.insert(std::pair<int, int>(2, 30));
	m1.insert(std::pair<int, int>(4, 40));
	m1.insert(std::pair<int, int>(5, 50));

	for (std::map<int, int, MyCompare>::iterator it = m1.begin(); it != m1.end(); it++) {
		std::cout << "key = " << (*it).first << " value = " << (*it).second << std::endl;
	}
	std::cout << std::endl;
}

// 2、对自定义类型数据，指定排序规则
class Person {
public:
	Person(std::string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	std::string m_Name;
	int m_Age;
};

class MyCompare2 {// 按年龄降序
public:
	bool operator()(const Person& p1, const Person& p2)const {
		return p1.m_Age > p2.m_Age;
	}
};

void MySort02() {
	// 创建数据
	Person p1("Tom", 18);
	Person p2("Jersey", 16);
	Person p3("Hans", 20);
	Person p4("Mark", 22);

	// 插入
	std::map<Person, int, MyCompare2> m1;
	m1.insert(std::pair<Person, int>(p1, 170));
	m1.insert(std::pair<Person, int>(p3, 160));
	m1.insert(std::pair<Person, int>(p2, 180));
	m1.insert(std::pair<Person, int>(p4, 175));

	for (std::map<Person, int, MyCompare2>::iterator it = m1.begin(); it != m1.end(); it++) {
		std::cout << "姓名：" << (*it).first.m_Name << " 年龄：" << (*it).first.m_Age << " 身高：" << (*it).second << std::endl;
	}
	std::cout << std::endl;
}

int main04() {
	MySort01();

	std::cout << "-------------------\n";
	MySort02();

	system("pause");
	return 0;
}