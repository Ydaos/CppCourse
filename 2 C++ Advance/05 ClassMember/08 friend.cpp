#include <iostream>
#include "building.hpp"

/*
* ��Ԫ
* ��һ������������ ������һ������˽�г�Ա
* 
* ��Ԫ����ʵ�֣�
* 1��ȫ�ֺ�������Ԫ
* 2��������Ԫ
* 3����ĳ�Ա��������Ԫ
*/

//1��ȫ�ֺ�������Ԫ
void goodGay(Building* building) {
	std::cout << "�û��ѵ�ȫ�ֺ��� ���ڷ��ʣ�" << building->m_sittingRoom << std::endl;
	std::cout << "�û��ѵ�ȫ�ֺ��� ���ڷ��ʣ�" << building->m_bedRoom << std::endl;
}

//2��������Ԫ
class GoodGay {
public:
	GoodGay() {
		m_building = new Building;
	}

	void visit() { //�ιۺ���������Building�е�����
		std::cout << "�û��������ڷ��ʣ�" << m_building->m_sittingRoom << std::endl;
		std::cout << "�û��������ڷ��ʣ�" << m_building->m_bedRoom << std::endl;
	}

	Building* m_building;
};

void ClassFriend() {
	//1��ȫ�ֺ�������Ԫ
	std::cout << std::endl;
	Building b;
	goodGay(&b);

	//2��������Ԫ
	std::cout << std::endl;
	GoodGay gg;
	gg.visit();

	//3����ĳ�Ա��������Ԫ
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