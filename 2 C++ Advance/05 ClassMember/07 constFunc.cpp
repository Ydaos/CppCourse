#include<iostream>

/*
* 常函数：
* 成员函数后加const 我们称这个函数为常函数
* 常函数不可以修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依然可以修改
*
* 常对象：
* 声明对象前加const 称该对象为常对象
* 常对象只能调用常函数
*/

class Person {
public:
	//this指针本质是指针常量 指针的指向是不可以修改的
	void showPerson() {
		this->m_A = 100;
		this->m_B = 100;
		//this = NULL; //error！！！this指针不可以修改指针的指向
	}

	//在成员函数后面加const，修饰的是this指针。让指针指向的值也不可以修改
	void showPerson2()const {
		//this->m_A = 100; //error！！！
		this->m_B = 200;
	}

	int m_A;
	mutable int m_B; //特殊变量，即使在常函数中依然可以修改
};

void ConstFunc() {
	Person p1;
	p1.showPerson();
	p1.showPerson2();

	// 常对象（不常用）
	const Person p2; //在对象前加const，变为常对象
	//p2.m_A = 100;  //error!!!常对象不可以修改
	p2.m_B = 200;    //特殊变量，常对象中亦可以修改

	//p2.showPerson();
	p2.showPerson2(); //常对象只能调用常函数
}

int main07() {
	ConstFunc();

	system("pause");
	return 0;
}