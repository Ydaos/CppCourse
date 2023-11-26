#include <iostream>
#include <set>

/*
* set容器排序
* set容器默认排序从小到大
* 利用仿函数，可以改变排序规则
* 对于自定义数据类型，set必须指定排序规则才可以插入数据
*/

// 1、利用仿函数，改变常规数据排序规则
class MyCompare {
public:
	bool operator()(int v1, int v2)const {
		return v1 > v2;
	}
};

void MySort01() {
	std::set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(50);
	s1.insert(40);
	
	for (std::set<int>::const_iterator it = s1.begin(); it != s1.end(); it++) {
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;

	// 指定排序规则为降序
	std::set<int, MyCompare>s2;
	s2.insert(10);
	s2.insert(30);
	s2.insert(20);
	s2.insert(50);
	s2.insert(40);

	for (std::set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// 2、利用仿函数，改变自定义数据排序规则
class Person {
public:
	Person(std::string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	std::string m_Name;
	int m_Age;
};

class MyCompare2 {
public:
	bool operator()(const Person& p1, const Person& p2)const {
		// 按照年龄排序
		return p1.m_Age > p2.m_Age;
	}
};

void MySort02() {
	// 自定义类型 需要指定排序规则
	std::set<Person, MyCompare2> s;

	// 创建对象
	Person p1("Tom", 18);
	Person p2("Jerry", 16);
	Person p3("Hans", 22);
	Person p4("Mark", 20);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (std::set<Person, MyCompare2>::iterator it = s.begin(); it != s.end(); it++) {
		std::cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << std::endl;
	}
}

// 总结：
// 利用仿函数可以指定set容器排序规则
// 对于自定义数据类型，set必须指定排序规则才可以插入数据
int main() {
	MySort01();

	std::cout << "-------------------\n";
	MySort02();

	system("pause");
	return 0;
}