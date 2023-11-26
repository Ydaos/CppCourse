#include<iostream>

/*
* C++面向对象三大特性：封装、继承和多态
* 
* 继承：减少重复代码
* 语法：class 子类（派生类） : 继承方式 父类（基类）
* eg: class A : public B {}
* 
* 派生类成员包含两大部分：从基类继承过来的成员、自己新增加的成员
* 从基类继承过来的表现其共性，而新增的成员体现了其个性
*/

namespace my_src1 {

	//继承 实现页面
	//公共特征类
	class BasePage {
	public:
		void header() {
			std::cout << "首页、公开课、登录、注册...（公共头部）\n";
		}
		void footer() {
			std::cout << "帮助中心、交流合作、站内地图...（公共底部）\n";
		}
		void left() {
			std::cout << "Java、Python、C++、...（公共分类列表）\n";
		}
	};

	//Java页面
	class Java :public BasePage {
	public:
		void contene() {
			std::cout << "Java学科视频\n";
		}
	};

	//Python页面
	class Python :public BasePage {
	public:
		void contene() {
			std::cout << "Python学科视频\n";;
		}
	};

	//C++页面
	class CPP :public BasePage {
	public:
		void contene() {
			std::cout << "C++学科视频\n";
		}
	};

	void Beginning() {
		std::cout << "\nJava下载视频页面如下：\n";
		Java ja;
		ja.header();
		ja.footer();
		ja.left();
		ja.contene();

		std::cout << "\nPython下载视频页面如下：\n";
		Python py;
		py.header();
		py.footer();
		py.left();
		py.contene();

		std::cout << "\nJava下载视频页面如下：\n";
		CPP cpp;
		cpp.header();
		cpp.footer();
		cpp.left();
		cpp.contene();
	}
}


int main01() {
	my_src1::Beginning();

	system("pause");
	return 0;
}