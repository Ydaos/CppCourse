#include<iostream>

//浅拷贝：简单赋值的拷贝操作
//深拷贝：在堆区重新申请空间，进行拷贝操作

class Person {
public:
	Person() {
		std::cout << "Person的默认构造函数调用\n";
	}
	Person(int age, int height) {
		std::cout << "Person的有参构造函数调用\n";
		m_age = age;
		m_height = new int(height);
	}

	//自己实现深拷贝的拷贝构造函数，解决浅拷贝带来的问题
	Person(const Person& p) {
		std::cout << "Person的拷贝构造函数调用\n";
		m_age = p.m_age;
		//m_height = p.m_height; 编译器默认操作，浅拷贝
		m_height = new int(*p.m_height);
	}

	~Person() {
		//析构代码，将堆区开辟数据做释放操作
		if (m_height != NULL) {
			delete m_height;
			m_height = NULL;
		}
		std::cout << "Person的析构函数调用\n";
	}

public:
	int m_age = 0; //年龄
	int* m_height = NULL; //身高
};


void DeepCopy() {
	Person p1(18, 170);
	std::cout << "p1的年龄为：" << p1.m_age << std::endl;
	std::cout << "p1的身高为：" << *p1.m_height << std::endl;

	Person p2(p1);
	std::cout << "p2的年龄为：" << p2.m_age << std::endl;
	std::cout << "p2的身高为：" << *p2.m_height << std::endl;
	//p2如果用编译器默认的拷贝构造函数，执行的是浅拷贝！
	//浅拷贝带来的问题就是堆区的内存重复释放！

	//栈区先进后出，p2会先被释放，先执行析构
}
//总结：如果类的对象有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的堆区内存重复释放问题。

int main02() {
	DeepCopy();

	system("pause");
	return 0;
}