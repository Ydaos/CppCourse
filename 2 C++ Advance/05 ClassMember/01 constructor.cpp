#include<iostream>

/*
* C++面向对象编程三大特性：封装、继承、多态
* 
* 封装意义：
* 将属性和行为作为一个整体，表现事物;
* 将属性和行为加以权限控制
*/

/* 
* 成员对象的初始化和清理：构造+析构
* 
* 构造函数(进行初始化操作)
* 没有返回值且不用写void
* 函数名与类名相同
* 构造函数可以有参数，可以发生重载
* 构造对象的时候，构造函数会自动调用，而且只调用一次
*
* 析构函数(进行清理的操作)
* 没有返回值且不用写void
* 函数名与类名相同，在名称前加~
* 析构函数不可以有参数，因此不可以发生重载
* 对象销毁前，会自动调用析构函数，且只会调用一次
*
* 注意：构造和析构都是必须有的实现.如果我们自己不提供，编译器会自己执行一个空的构造和析构函数
*/

/*
* 构造函数的分类以及调用
*
* 分类
* 按参数分类：无参构造（默认构造）和有参构造
* 按类型分类：普通构造 拷贝构造
*
* 构造函数调用规则：
* 1、创建一个类，C++编译器会给每个类都添加至少3个函数：默认构造（空实现）、析构函数（空实现）、拷贝构造（值拷贝）
* 2、如果我们写了有参构造，编译器不再提供默认构造，依然提供拷贝构造
* 3、如果我们写了拷贝构造函数，编译器不再提供其他的构造函数
*/

class Person {
public:
	//普通构造函数
	Person() {//无参构造
		std::cout << "Person默认构造函数的调用\n";
	}
	Person(int age) {//有参构造
		m_age = age;
		std::cout << "Person有参构造函数的调用\n";
	}

	//拷贝构造函数
	Person(const Person& p) {
		//将传入的类身上所有的属性，拷贝到我身上
		std::cout << "Person拷贝构造函数的调用\n";
		m_age = p.m_age;
	}

	//析构函数
	~Person() {
		std::cout << "Person析构函数的调用\n";
	}

public:
	int m_age = 0;
};

void func01() {
	//1、括号法，常用
	std::cout << "-------------------------------1\n";
	Person p1;     //默认构造函数调用
	Person p2(10); //有参构造函数
	Person p3(p2); //拷贝构造函数

	std::cout << "p1的年龄：" << p1.m_age << std::endl;
	std::cout << "p2的年龄：" << p2.m_age << std::endl;
	std::cout << "p3的年龄：" << p3.m_age << std::endl;

	//注意事项：
	//调用默认构造函数时候，请不要加();
	//因为下面这行代码，编译器会认为是一个函数的声明，不会认为在创建对象
	//Person p4();

	//2、显式法
	std::cout << "-------------------------------2\n";
	Person p5 = Person(10);
	Person p6 = Person(p5);

	Person(10); //匿名对象 特点：当前执行完立即被释放

	//注意事项：
	//不要用拷贝构造函数初始化匿名对象 
	//Person(p5); //编译器会认为 Person(p5) === Person p5,认为这是对象声明

	//3、隐式转换法
	std::cout << "-------------------------------3\n";
	Person p7 = 10; //相当于写了 Person p7 = Person(10);有参构造
	Person p8 = p7; //拷贝构造

	//4、函数执行完，栈区释放内存，执行析构函数
	std::cout << "-------------------------------4\n";
}

/*
* 拷贝构造函数调用时机：
* 使用一个已经创建完毕的对象来初始化一个新对象
* 值传递的方式给函数参数传值
* 值的方式返回局部对象
*/

//1、使用一个已经创建完毕的对象来初始化一个新对象
void case01() {
	Person p1(20);
	Person p2(p1);

	std::cout << "p2的年龄：" << p2.m_age << std::endl;
}

//2、值传递的方式 给函数参数传值
void doWork(Person p) {

}

void case02() {
	Person p;
	doWork(p);
}

//3、值的方式返回局部对象
Person doWork2() {
	Person p;
	std::cout << &p << std::endl;
	return p;
}

void case03() {
	Person p = doWork2();
	std::cout << &p << std::endl;
}

void Constructor() {
	func01();

	std::cout << "\nThere are three type of copy constructor calling.\n";
	std::cout << "-------------------------------case 1\n";
	case01();
	std::cout << "-------------------------------case 2\n";
	case02();
	std::cout << "-------------------------------case 3\n";
	case03();
}

int main() {
	Constructor();

	system("pause");
	return 0;
}