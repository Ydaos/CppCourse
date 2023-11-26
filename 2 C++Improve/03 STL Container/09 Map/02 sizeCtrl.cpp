#include <iostream>
#include <map>

void printMap(std::map<int, int>& m); //����������"01 definition.cpp"

/*
* map�Ĵ�С�ͽ���
* ����ԭ�ͣ�
* size();	 // ��������Ԫ�ظ���
* empty();	 // �ж������Ƿ�Ϊ��
* swap(st); // ������������
*/
void MySize() {
	std::map<int, int> m1;
	m1.insert(std::pair<int, int>(1, 10));
	m1.insert(std::pair<int, int>(3, 20));
	m1.insert(std::pair<int, int>(2, 30));
	m1.insert(std::pair<int, int>(4, 40));
	m1.insert(std::pair<int, int>(5, 50));
	printMap(m1);

	if (m1.empty()) {
		std::cout << "����Ϊ��\n";
	}
	else {
		std::cout << "������Ϊ��\n";
		std::cout << "����Ԫ�ظ�����" << m1.size() << std::endl;
	}
}

// ��������
void MySwap() {
	std::map<int, int> m1;
	m1.insert(std::pair<int, int>(1, 10));
	m1.insert(std::pair<int, int>(3, 20));
	m1.insert(std::pair<int, int>(2, 30));
	m1.insert(std::pair<int, int>(4, 40));
	m1.insert(std::pair<int, int>(5, 50));

	std::map<int, int>m2;
	m2.insert(std::pair<int, int>(1, 100));
	m2.insert(std::pair<int, int>(3, 200));
	m2.insert(std::pair<int, int>(2, 300));
	m2.insert(std::pair<int, int>(4, 400));
	m2.insert(std::pair<int, int>(5, 500));
	std::cout << "����ǰ��\n";
	printMap(m1);
	printMap(m2);

	m1.swap(m2);
	std::cout << "������\n";
	printMap(m1);
	printMap(m2);
}

int main02() {
	MySize();

	std::cout << "-------------------\n";
	MySwap();

	system("pause");
	return 0;
}