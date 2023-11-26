#include <iostream>

namespace my_src1 {

/*
* 多态：
* 1、静态多态：函数重载和运算符重载属于静态多态，复用函数名
* 2、动态多态：派生类和虚函数实现运行时多态
*
* 两者区别：
* 1、静态多态的函数地址早绑定 - 编译阶段确定函数地址
* 2、动态多态的函数地址晚绑定 - 运行阶段确定函数地址
*/

	//动物类
	class Animal {
	public:
		//void speak() { //地址早绑定
		//	cout << "动物在说话" << endl;
		//}
		virtual void speak() { //虚函数，让地址晚绑定
			std::cout << "动物在说话\n";
		}
	};

	//猫类
	class Cat :public Animal {
	public:
		//重写父类虚函数 函数返回值类型和参数列表完全相同
		void speak() {
			std::cout << "小猫在说话\n";
		}
	};

	//狗类
	class Dog :public Animal {
	public:
		void speak() {
			std::cout << "小狗在说话\n";
		}
	};

	//执行说话的函数
	//地址早绑定 在编译阶段确定函数地址
	//执行想要猫说话，函数地址需要晚绑定，在运行阶段绑定
	void doSpeak(Animal& animal) { //Animal& animal = cat
		animal.speak();
	}

	void Func() {
		Cat cat;
		doSpeak(cat);

		Dog dog;
		doSpeak(dog);
	}

	/*
	* 总结：
	* 动态多态满足条件：有继承关系、子类重写父类虚函数
	* 
	* 动态多态使用条件：父类的指针或者引用，执行子类对象
	* 
	* 动态多态底层原理：
	* 父类虚函数地址晚绑定，父类成员会分配一个虚函数指针指向虚函数；
	* 子类会继承父类虚函数指针；
	* 子类重写虚函数会使虚函数指针指向重写后的函数而不再指向父类虚函数。
	*/
}

namespace prac_space {

	//分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类
	
	// 1、普通写法
	class Calculator {
	public:
		int getResult(std::string oper) {
			if (oper == "+") {
				return m_num1 + m_num2;
			}
			else if (oper == "-") {
				return m_num1 - m_num2;
			}
			else if (oper == "*") {
				return m_num1 * m_num2;
			}
			//如果想扩展新的功能（如加入除法），必须修改源码
			//在真实的开发中，提倡开闭原则：对扩展进行开放，对修改进行关闭
		}

		int m_num1;
		int m_num2;
	};

	void case01() {
		//创建计算器对象
		Calculator cal;
		cal.m_num1 = 10;
		cal.m_num2 = 2;

		std::cout << cal.m_num1 << " + " << cal.m_num2 << " = " << cal.getResult("+") << std::endl;
		std::cout << cal.m_num1 << " - " << cal.m_num2 << " = " << cal.getResult("-") << std::endl;
		std::cout << cal.m_num1 << " * " << cal.m_num2 << " = " << cal.getResult("*") << std::endl;
	}

	// 2、利用多态实现计算器类
	// 创建计算器抽象类
	class AbstractCalculator {
	public:
		virtual int getResult() {
			return 0;
		}

		int m_num1 = 0;
		int m_num2 = 0;
	};

	//加法计算器类
	class AddCalculator :public AbstractCalculator {
	public:
		int getResult() {
			return m_num1 + m_num2;
		}
	};

	//减法计算器类
	class SubCalculator :public AbstractCalculator {
	public:
		int getResult() {
			return m_num1 - m_num2;
		}
	};

	//乘法计算器类
	class MulCalculator :public AbstractCalculator {
	public:
		int getResult() {
			return m_num1 * m_num2;
		}
	};

	void case02() {
		// 多态使用条件
		// 父类指针或引用指向子类对象

		//加法运算
		AbstractCalculator* ac = new AddCalculator;
		ac->m_num1 = 10;
		ac->m_num2 = 2;
		std::cout << ac->m_num1 << " + " << ac->m_num2 << " = " << ac->getResult() << std::endl;
		//堆区数据用完记得销毁
		delete ac;

		//减法运算
		ac = new SubCalculator;
		ac->m_num1 = 10;
		ac->m_num2 = 2;
		std::cout << ac->m_num1 << " - " << ac->m_num2 << " = " << ac->getResult() << std::endl;
		delete ac;

		//乘法运算 (引用法)
		MulCalculator mul;
		AbstractCalculator& abc = mul;
		abc.m_num1 = 10;
		abc.m_num2 = 2;
		std::cout << abc.m_num1 << " * " << abc.m_num2 << " = " << abc.getResult() << std::endl;
	}

	/*
	* 多态好处：
	* 1、组织结构清晰
	* 2、可读性强
	* 3、方便后期扩展和维护
	* eg：增加新功能只需要追加新功能类，不需要修改源代码；维护可以直接定位到对应的功能类，易读性强
	*/
}

int main01() {
	my_src1::Func();

	std::cout << "\nThere are two case to compare the benefits of using polymorphims or not.\n";
	prac_space::case01();

	std::cout << std::endl;
	prac_space::case02();

	system("pause");
	return 0;
}