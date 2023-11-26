#pragma once
#include <iostream>

class Building;

class GoodFriend {
public:
	GoodFriend();

	void visit(); 
	void visit2();

	Building* m_building;
};

class Building {
	//goodGay全局函数是 Building类好朋友，可以访问Building中私有成员
	friend void goodGay(Building* building);

	//GoodGay类是 Building类的好朋友，可以访问Building中的私有函数
	friend class GoodGay;

	//GoodFriend的visit函数是 Building类的好朋友
	friend void GoodFriend::visit();

public:
	Building();

	std::string m_sittingRoom; //客厅

private:
	std::string m_bedRoom;  //卧室
};

//--------------------------------------------------------------------------------
Building::Building() {
	m_sittingRoom = "客厅";
	m_bedRoom = "卧室";
}

GoodFriend::GoodFriend() {
	m_building = new Building;
}

void GoodFriend::visit() { //visit()可以访问Building私有成员
	std::cout << "visit()正在访问：" << m_building->m_sittingRoom << std::endl;
	std::cout << "visit()正在访问：" << m_building->m_bedRoom << std::endl;
}
void GoodFriend::visit2() { //visit2()仅可以访问Building公有成员
	std::cout << "visit2()正在访问：" << m_building->m_sittingRoom << std::endl;
}
// 成员函数定义放在Building类声明后面，反正找不到Building类的成员




