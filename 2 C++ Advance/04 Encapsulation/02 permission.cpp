#include<iostream>

/*
* 访问权限
* public    公共权限:成员类内外皆可以访问
* protected 保护权限:成员类内可以访问，类外不可以访问；子类可以访问父类的保护内容
* private   私有权限:成员类内可以访问，类外不可以访问：子类不可以访问父类的私有内容
* 
* 在C++中，struct和class唯一区别在于默认访问权限不同
* 
* 成员属性设置为私有优点：
* 将所有成员属性设置为私有，可以自己控制读写权限
* 对于写权限，我们可以检测数据的有效性
*/

class Person {
	int m_test;
public://公共权限
	std::string m_name;

protected: //保护权限
	std::string m_car;

private: //私有权限
	int m_Password;

public:
	void func() {
		m_name = "张三";
		m_car = "拖拉机";
		m_Password = 123456;
	}
};

struct Persion2 {
	int m_test;
};

//设计人类
class Persion3 {
private:
	std::string m_name;
	int m_age = 0;
	std::string m_lover;

public:
	//设置姓名
	void setName(std::string name) {
		m_name = name;
	}
	//获取姓名
	std::string getName() {
		return m_name;
	}

	//设置年龄
	void setAge(int age) {
		if (age < 1 || age>100) {
			std::cout << "年龄太大了！" << std::endl;
			return;
		}
		m_age = age;
	}
	//获取年龄
	int getAge() {
		return m_age;
	}

	//设置情人
	void setLover(std::string name) {
		m_lover = name;
	}
};

void Permission() {
	//实例化具体对象
	Person p1;
	p1.m_name = "lisa";
	//p1.m_car = "奔驰"; //error！ 保护权限类外访问不到
	//p1.m_Password = 123; //error！ 私有权限类外访问不到
	//p1.m_test = 0; //访问不到，默认为私有，类外不可访问

	Persion2 p2;
	p2.m_test = 10; //可以访问，struct成员权限默认为public


	/*This is the first demo of permission.*/
	//1、控制读写权限
	Persion3 p3;
	p3.setName("张三"); //姓名，可读可写
	std::cout << "姓名为：" << p3.getName() << std::endl;

	p3.setLover("lisa"); //情人 只写，不可读

	//2、检测数据有效性
	p3.setAge(1000); //年龄太大 年龄设置失败
	std::cout << "年龄为：" << p3.getAge() << std::endl; //年龄 可读可写，范围1~100

	p3.setAge(10);
	std::cout << "年龄为：" << p3.getAge() << std::endl;
}

int main02() {
	Permission();

	system("pause");
	return 0;
}