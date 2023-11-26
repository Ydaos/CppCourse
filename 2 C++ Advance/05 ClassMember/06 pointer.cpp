#include<iostream>

/*
* this指针
* this指针是隐含每一个非静态成员函数内的一种指针
* this指针不需要定义，直接使用即可
* 用途：解决名称冲突；返回对象本身
* 
* 空指针调用成员函数
*/

class Person {
public:
	//1、解决名称冲突 
	Person(int age) {
		//this指针指向的是被调用的成员函数所属对象
		this->age = age;
	}

	//2、返回对象本身用*this
	Person& PersonAddPerson(Person& p) {
		age += p.age;
		return *this;
	}

	void showClassName() {
		std::cout << "this is Person class\n";
	}

	void showClassAge() {
		//报错是因为传入的指针是NULL
		if (this == NULL) { //提高程序健壮性
			return;
		}
		std::cout << "age = " << this->age << std::endl;
	}

	int age = 0;
};

void ClassPointer() {
	Person p1(10);
	Person p2(20);

	//链式编程思想
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
	std::cout << "p2的年龄：" << p2.age << std::endl;

	//空指针调用成员函数
	Person* p = NULL;
	p->showClassAge();
	p->showClassName();
}

int main06() {
	ClassPointer();

	system("pause");
	return 0;
}