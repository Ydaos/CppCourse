#include<iostream>

/*
* 菱形继承概念：
* 1、两个派生类继承同一个基类
* 2、又有某个类同时继承两个派生类
* 3、这种继承称为菱形继承，又称为钻石继承
* 4、通过虚继承可以解决菱形继承二义性问题
*/

namespace my_src6 {

	//动物类
	class Animal {
	public:
		int m_age;
	};

	//利用虚继承可以解决菱形继承的问题
	// 继承之前加上关键字 virtual 变为虚继承
	// Animal 类称为虚基类

	//羊类
	class Sheep :virtual public Animal {

	};

	//驼类
	class Tuo :virtual public Animal {

	};

	//草泥马（羊驼）
	class SheepTuo :public Sheep, public Tuo {

	};

	void Diamond() {
		SheepTuo st;
		st.Sheep::m_age = 10;
		st.Tuo::m_age = 20;

		//菱形继承，两个父类拥有相同属性，需要加作用域区分
		std::cout << "st.Sheep::m_age = " << st.Sheep::m_age << std::endl;
		std::cout << "st.Tuo::m_age = " << st.Tuo::m_age << std::endl;

		//但该数据只需有一份即可，菱形继承导致数据有两份，资源浪费！
		//虚继承之后数据共享只有一份，所以可以直接访问
		std::cout << "st.m_age = " << st.m_age << std::endl;
	}
}

/*
* 总结：
* 1、菱形继承带来主要问题是子类基类两份相同数据，导致资源浪费已经二义性
* 2、利用虚继承可以解决菱形继承问题
* 
* 虚继承解决菱形继承原理：
* SheepTuo类分别从两个基类虚继承继承的是两个虚基类指针，而不再是两份具体数据；
* 虚基类指针指向对应的虚基类链表，链表存放的数据是内存偏移；
* 通过虚基类链表数据，两个虚基类指针会指向虚基类Animal中的同一份数据m_age，因此不会带来资源浪费，多继承的二义性也不存在。
* 故：直接访问数据 s.m_age 不加作用域也不会报错了！！！
*/

int main() {
	my_src6::Diamond();

	system("pause");
	return 0;
}