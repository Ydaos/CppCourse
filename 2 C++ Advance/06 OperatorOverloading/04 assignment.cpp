#include<iostream>

/*
* C++编译器至少给一个类添加四个函数：
* 1、默认构造函数(无参，函数体为空)
* 2、默认析构函数(无参，函数体为空)
* 3、默认拷贝构造函数，对属性进行值拷贝
* 4、赋值运算符operator= ，对属性进行值拷贝
* 
* 如果类中属性指向堆区，做赋值操作也会出现深浅拷贝问题
*/

//赋值运算符重载
class Person {
public:
	Person(int age) {
		m_age = new int(age);
	}

	~Person() {
		if (m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}
	}

	//重载 赋值运算符
	Person& operator=(Person& p) {
		//编译器是提供浅拷贝
		//m_age = p.m_age;

		//应该先判断是否有属性在堆区，如果有先释放干净，再进行深拷贝操作
		if (m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}
		//深拷贝
		m_age = new int(*p.m_age);

		//返回对象本身 链式变量思想！！！
		return *this;
	}

	int* m_age;
};

void Assignment() {
	Person p1(18);
	Person p2(20);
	Person p3(30);

	p3 = p2 = p1;   //链式变量思想！！！
	std::cout << "p1的年龄：" << *p1.m_age << std::endl;
	std::cout << "p2的年龄：" << *p2.m_age << std::endl;
	std::cout << "p3的年龄：" << *p3.m_age << std::endl;
}

int main04() {
	Assignment();

	system("pause");
	return 0;
}