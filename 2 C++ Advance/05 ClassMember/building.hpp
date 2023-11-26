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
	//goodGayȫ�ֺ����� Building������ѣ����Է���Building��˽�г�Ա
	friend void goodGay(Building* building);

	//GoodGay���� Building��ĺ����ѣ����Է���Building�е�˽�к���
	friend class GoodGay;

	//GoodFriend��visit������ Building��ĺ�����
	friend void GoodFriend::visit();

public:
	Building();

	std::string m_sittingRoom; //����

private:
	std::string m_bedRoom;  //����
};

//--------------------------------------------------------------------------------
Building::Building() {
	m_sittingRoom = "����";
	m_bedRoom = "����";
}

GoodFriend::GoodFriend() {
	m_building = new Building;
}

void GoodFriend::visit() { //visit()���Է���Building˽�г�Ա
	std::cout << "visit()���ڷ��ʣ�" << m_building->m_sittingRoom << std::endl;
	std::cout << "visit()���ڷ��ʣ�" << m_building->m_bedRoom << std::endl;
}
void GoodFriend::visit2() { //visit2()�����Է���Building���г�Ա
	std::cout << "visit2()���ڷ��ʣ�" << m_building->m_sittingRoom << std::endl;
}
// ��Ա�����������Building���������棬�����Ҳ���Building��ĳ�Ա




