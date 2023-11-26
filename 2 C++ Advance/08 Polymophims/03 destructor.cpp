#include<iostream>

namespace my_src3 {

	/*
	* 父类的指针在析构的时候，不会调用子类的析构函数，如果子类有堆区数据，会造成内存泄漏
	* 利用虚析构，父类指针在析构时会调用子类的析构函数，从而解决子类对象释放不干净的问题
	* 纯虚析构更多是为了让基类变成抽象类，常用于基类含有纯虚函数的情况
	* 
	* 虚析构语法：virtual ~类名(){}
	* 纯虚析构语法：virtual ~类名() = 0;
	* 
	* 注意事项：
	* 纯虚析构需要声明，也需要实现
	* 有了纯虚析构之后，该类属于抽象类无法实例化
	*/

	class Animal {
	public:
		Animal() {
			std::cout << "Animal 的构造函数调用\n";
		}

		//利用虚析构：父类指针释放子类对象时不干净的问题
		/*virtual ~Animal() {
			std::cout << "Animal 的虚析构函数调用\n";
		}*/

		// 纯虚析构：需要声明，也需要实现
		// 有了纯虚析构之后，该类也属于抽象类，无法实例化
		virtual ~Animal() = 0;

		virtual void Speak() = 0;
	};

	Animal::~Animal() {
		std::cout << "Animal 的纯虚析构函数调用\n";
	}

	class Cat :public Animal {
	public:
		Cat(std::string name) {
			std::cout << "Cat 的构造函数调用\n";
			m_name = new std::string(name);
		}

		~Cat() {
			if (m_name != NULL) {
				std::cout << "Cat 的析构函数调用\n";
				delete m_name;
			}
		}

		void Speak() {
			std::cout << *m_name << "小猫在说话\n";
		}

		std::string* m_name;
	};

	void Func() {
		Animal* a = new Cat("Tom");
		a->Speak();
		delete a;
	}

	/*
	* 总结：
	* 虚析构和纯虚析构共性：可以解决父类指针释放子类对象；都需要具体的函数实现
	* 
	* 区别：如果是纯虚析构 该类属于抽象类，无法实例化对象
	* 如果子类无堆区数据，则没必要设置虚析构函数来释放子类数据
	*/
}

int main03() {
	my_src3::Func();

	system("pause");
	return 0;
}