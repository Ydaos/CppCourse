#include <iostream>
#include <vector>
#include <algorithm> // 标准算法头文件！

/*
* STL (Standard Template Library,标准模板库)
* 为提高复用性，建立一套数据结构和算法的标准，即STL
* 广义分为：容器、算法和迭代器
* 
*  STL分为六大组件：容器、算法、迭代器、伪函数、适配器和空间配置器。
* 1、容器：各种数据结构，如vector、list、map等
* 2、算法：各种常用算法，如sort、find、copy、for_each等
* 3、迭代器：扮演了容器和算法之间的胶合剂
* 4、仿函数：类似函数，可作为算法的某种策略
* 5、适配器：一种用来修饰容器、仿函数或迭代器接口的东西
* 6、空间配置器：负责空间的配置和管理
* 
* STL容器：将最广泛的一些数据结构实现出来
* 常用数据结构：数组、链表、树、栈、队列、集合、映射表等
* 容器分为：序列式容器和关联式容器
* 序列式容器：强调值的排列顺序，序列式容器每个元素均有固定位置
* 关联式容器：二叉树结构，各个元素之间没有严格的物理上的顺序关系
* 
* 算法(Algorithms):有限步骤解决逻辑或数学上的问题
* 算法分为质变算法和非质变算法
* 质变算法：运算过程中会改变区间内的元素内容。例如拷贝、替换、删除等等
* 非质变算法：运算过程中不会改变区间内元素内容。例如查找、计数、遍历、寻找极值等等
* 
* 迭代器：提供一种方法，使之能够依序访问容器所含的各个元素，而又无需暴露该容器的内部表达方式
* 每个容器都有自己专属的迭代器，迭代器使用类似指针。
* 
* 迭代器种类：
* 1、输入迭代器：对数据只读访问
* 2、输出迭代器：对数据只写访问
* 3、前向迭代器：读写操作，并能向前推进迭代器
* 4、双向迭代器：读写操作，并能向前和向后操作
* 5、随机访问迭代器：读写操作，并能跳跃的方式访问任意数据，功能最强
* 常用容器中迭代器种类为双向迭代器和随机访问迭代器。
*/

// vector容器存放内置数据类型，并遍历容器

void myPrint(int val) {
	std::cout << val << std::endl;
}

void test() {
	// 创建一个vector容器
	std::vector<int> v;

	// 向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	// 通过迭代器访问容器中的数据
	std::vector<int>::iterator itBegin = v.begin(); // 起始迭代器，指向容器中第一个元素
	std::vector<int>::iterator itEnd = v.end(); // 结束迭代器，指向容器中最后一个元素的下一个位置

	// 第一种遍历方式
	std::cout << "---------------------first way\n";
	while (itBegin != itEnd) {
		std::cout << *itBegin << std::endl;
		itBegin++;
	}

	// 第二种遍历方式
	std::cout << "---------------------second way\n";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << std::endl;
	}

	// 第三种遍历方式 利用STL提供遍历算法
	std::cout << "---------------------third way\n";
	for_each(v.begin(), v.end(), myPrint);
}

// vector容器存放自定义数据类型，并遍历容器
class Person {
public:
	Person(std::string name, int age) {
		m_Name = name;
		m_Age = age;
	}

	std::string m_Name;
	int m_Age;
};

void myPersonPrint(Person p) {
	std::cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << std::endl;
}

void test2() {
	// 创建一个vector容器
	std::vector<Person> v;

	Person p1("Tom", 20);
	Person p2("Jerry", 20);
	Person p3("Mark", 20);
	Person p4("Tony", 20);
	Person p5("Hans", 20);

	// 向容器中插入数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	// 通过迭代器访问容器中的数据
	std::vector<Person>::iterator itBegin = v.begin(); // 起始迭代器，指向容器中第一个元素
	std::vector<Person>::iterator itEnd = v.end(); // 结束迭代器，指向容器中最后一个元素的下一个位置

	// 第一种遍历方式
	std::cout << "---------------------first way\n";
	while (itBegin != itEnd) {
		std::cout << "姓名：" << (*itBegin).m_Name << " 年龄：" << (*itBegin).m_Age << std::endl;
		itBegin++;
	}

	// 第二种遍历方式
	std::cout << "---------------------second way" << std::endl;
	for (std::vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << std::endl;
	}

	// 第三种遍历方式 利用STL提供遍历算法
	std::cout << "---------------------third way\n";
	for_each(v.begin(), v.end(), myPersonPrint);
}

// 存放自定义类型指针
void test3() {
	// 创建一个vector容器
	std::vector<Person*> v;

	Person p1("Tom", 20);
	Person p2("Jerry", 20);
	Person p3("Mark", 20);
	Person p4("Tony", 20);
	Person p5("Hans", 20);

	// 向容器中插入数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	// 遍历容器
	for (std::vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << "姓名：" << (*it)->m_Name << " 年龄：" << (*it)->m_Age << std::endl;
	}
}

int main01() {
	std::cout << "---------------------vector<int>\n";
	test();

	std::cout << "---------------------vector<Person>\n";
	test2();

	std::cout << "---------------------vector<Pointer*>\n";
	test3();

	system("pause");
	return 0;
}