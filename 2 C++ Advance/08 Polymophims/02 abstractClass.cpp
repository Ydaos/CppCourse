#include<iostream>

namespace my_src2 {

	/*
	* 多态父类中的虚函数实现是毫无意义的，主要调用由子类重写实现的内容，因此父类虚函数通常改为纯虚函数
	* 
	* 纯虚函数语法：virtual 返回函数值类型 函数名(参数列表) = 0
	* 当类中有纯虚函数，这个类也称为抽象类
	* 
	* 抽象类特点：
	* 1、无法实例化对象
	* 2、子类必须重写抽象类中的纯虚函数，否则无法实例化对象
	*/

	// 纯虚函数和抽象类
	class Base {
	public:
		virtual void func() = 0;
	};

	class Son :public Base {
	};

	class Son2 :public Base {
	public:
		void func() {
			std::cout << "fun 函数调用\n";
		}
	};

	void Func() {
		//Base b;   Error!!! 无法实例化对象
		//Son s;    Error!!! 子类没重写虚函数，也属于抽象类，不能实例化

		Base* b = new Son2;
		b->func();
		delete b;

		// 不常用，堆区数据管理更可控
		Son2 s2;
		Base& b2 = s2;
		b2.func();
	}

	// 多态案例2：提供制作饮品的抽象基类，提供子类制作咖啡和茶叶
	// 饮品制作流程：煮水 - 冲泡 - 倒入杯中 - 加入辅料

	//抽象基类
	class AbstractDrinking {
	public:
		//煮水
		virtual void Boil() = 0;

		//冲泡
		virtual void Brew() = 0;

		//倒入杯中
		virtual void Pour() = 0;

		//加入辅料
		virtual void addAccessori() = 0;

		//制作饮品
		void makeDrink() {
			Boil();
			Brew();
			Pour();
			addAccessori();
		}
	};

	//制作咖啡
	class Coffee :public AbstractDrinking {
	public:
		//煮水
		void Boil() {
			std::cout << "煮农夫山泉" << std::endl;
		}

		//冲泡
		void Brew() {
			std::cout << "冲泡咖啡" << std::endl;
		}

		//倒入杯中
		void Pour() {
			std::cout << "倒入咖啡杯" << std::endl;
		}

		//加入辅料
		void addAccessori() {
			std::cout << "加入糖浆和牛奶" << std::endl;
		}
	};

	//制作茶叶
	class Tea :public AbstractDrinking {
	public:
		//煮水
		void Boil() {
			std::cout << "煮农夫山泉" << std::endl;
		}

		//冲泡
		void Brew() {
			std::cout << "冲泡茶叶" << std::endl;
		}

		//倒入杯中
		void Pour() {
			std::cout << "倒入茶杯" << std::endl;
		}

		//加入辅料
		void addAccessori() {
			std::cout << "加入枸杞！！！" << std::endl;
		}
	};

	//制作函数
	void doWork(AbstractDrinking* ad) {
		ad->makeDrink();
		delete ad;
	}

	void Practice() {
		//制作咖啡
		doWork(new Coffee);

		std::cout << "------------------------" << std::endl;
		//制作枸杞茶
		doWork(new Tea);
	}
}


int main02() {
	my_src2::Func();

	std::cout << "\nThis is a demo of abstract class application.\n";
	my_src2::Practice();

	system("pause");
	return 0;
}