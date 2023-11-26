#include <iostream>
#include "building.hpp"

/*
* 友元
* 让一个函数或者类 访问另一个类中私有成员
* 
* 友元三种实现：
* 1、全局函数做友元
* 2、类做友元
* 3、类的成员函数做友元
*/

//1、全局函数做友元
void goodGay(Building* building) {
	std::cout << "好基友的全局函数 正在访问：" << building->m_sittingRoom << std::endl;
	std::cout << "好基友的全局函数 正在访问：" << building->m_bedRoom << std::endl;
}

//2、类做友元
class GoodGay {
public:
	GoodGay() {
		m_building = new Building;
	}

	void visit() { //参观函数，访问Building中的属性
		std::cout << "好基友类正在访问：" << m_building->m_sittingRoom << std::endl;
		std::cout << "好基友类正在访问：" << m_building->m_bedRoom << std::endl;
	}

	Building* m_building;
};

void ClassFriend() {
	//1、全局函数做友元
	std::cout << std::endl;
	Building b;
	goodGay(&b);

	//2、类做友元
	std::cout << std::endl;
	GoodGay gg;
	gg.visit();

	//3、类的成员函数做友元
	std::cout << std::endl;
	GoodFriend gf;
	gf.visit();
	gf.visit2();
}

int main08() {
	ClassFriend();

	system("pause");
	return 0;
}