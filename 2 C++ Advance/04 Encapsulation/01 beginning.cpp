#include<iostream>

/*
* C++面向对象编程三大特性：封装、继承、多态
*
* 封装意义：
* 将属性和行为作为一个整体，表现事物;
* 将属性和行为加以权限控制
* 
* 类中的属性和行为，我们统一称为：成员
* 属性亦称为 成员属性、成员变量
* 行为亦称为 成员函数、成员方法
* 
* 注意：
* class定义在第一个访问说明符之前的成员是private的
* struct定义在第一个访问说明符之前的成员是public的，这是两者封装唯一区别
*/

//设计一个学生类，属性有姓名和学号
//可以给姓名和学号赋值，可以显示学生的姓名和学号
class Student {

	//属性
	std::string m_name; //权限默认private
	std::string m_ID;

public:
	//行为
	void setName(std::string name) {
		m_name = name;
	}

	void setID(std::string ID) {
		m_ID = ID;
	}

	void showMessage() {
		std::cout << "学生的姓名：" << m_name << " " << "学生的学号：" << m_ID << std::endl;
	}
};

void Beginning() {
	//实例化 （通过一个类 创建一个对象的过程）
	Student s;
	//给对象的属性进行赋值
	s.setName("张三");
	s.setID("001");
	s.showMessage();
}

int main01() {
	Beginning();

	system("pause");
	return 0;
}