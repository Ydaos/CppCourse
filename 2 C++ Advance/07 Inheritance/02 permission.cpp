#include<iostream>

/*
* 继承方式：公共继承、保护继承、私有继承
* 
* 注意：
* 父类中所有对象（非静态成员属性）都会被子类继承下去
* 父类中私有成员属性是被编译器隐藏了，因此访问不到
*/

/*
* 通过开发者工具查看对象模型
* 
* 步骤：
* 1、利用开发人员命令提示工具查看对象模型
* 2、跳转定义类的.cpp文件所在的磁盘
* 3、cd指令打开.cpp文件所在目录
* 4、输入查看命令：cl /d1 reportSingleClassLayout类名 文件名
* 
* 案例：
* 打开开发者工具（Developer Command Prompt for VS2019）
* C: //跳转C磁盘
* cd C:\Users\King\Desktop\C++\2 C++ advance\07 inheritance\07 inheritance
* cl /d1 reportSingleClassLayoutSon1 "02 permission.cpp"
*/

namespace my_src2 {

	class Base {
	public:
		int m_A;
	protected:
		int m_B;
	private:
		int m_C;
	};

	// 1、公共继承
	class Son1 :public Base {
	public:
		void func() {
			m_A = 10;   //父类中公共权限成员，到子类中依然是公共权限
			m_B = 10;   //父类中保护权限成员，到子类中依然是保护权限
			//m_C = 10; //父类中私有成员，子类访问不到
		}
	};

	// 2、保护继承
	class Son2 :protected Base {
	public:
		void func() {
			m_A = 10;   //父类中公共权限成员，到子类中变为保护权限
			m_B = 10;   //父类中保护权限成员，到子类中依然是保护权限
			//m_C = 10; //父类中私有成员，子类访问不到
		}
	};

	// 3、私有继承
	class Son3 :private Base {
		void func() {
			m_A = 10;   //父类中公共权限成员，到子类中变为私有权限
			m_B = 10;   //父类中保护权限成员，到子类中变为私有权限
			//m_C = 10; //父类中私有成员，子类访问不到
		}
	};

	class GrandSon3 :public Son3 {
	public:
		void func() {
			//m_A = 200; //类内无法访问，说明m_A已经是私有权限成员
		}
	};

	void Permission() {
		// 1、公共继承
		Son1 s1;
		s1.m_A = 100;   //公共权限，类外可访问
		//s1.m_B = 200; //保护权限，类外不能访问

		// 2、保护继承
		Son2 s2;
		//s2.m_A = 100; //保护权限，类外不能访问
		//s2.m_B = 200; //保护权限，类外不能访问

		// 3、私有继承
		// 父类成员到子类变成私有权限，子类的子类无法访问父类的任何成员

		// 4、继承模型
		std::cout << "sizeof of Son1：" << sizeof(Son1) << std::endl;

		//结果为12，说明3个int变量（包括私有权限的 Base::m_C）全部被子类继承
	}
}

int main02() {
	my_src2::Permission();

	system("pause");
	return 0;
}