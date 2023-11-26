#include <iostream>
#include <list>

void printList(const std::list<int>& l); //�����������ļ�"01 definition.cpp"


/*
* List������С����
* ����ԭ�ͣ�
* size();			     //����������С
* empty();               //�ж������Ƿ�Ϊ��
* resize(int num);       //����ָ��������СΪnum�����䳤����Ĭ��ֵ�����λ�ã��������ɾ�������������ȵ�Ԫ�أ�
* resize(int num, elem); //����ָ��������СΪnum�����䳤����elemֵ�����λ�ã��������ɾ�������������ȵ�Ԫ�أ�
*/
void ListSize() {
	std::list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	L.push_back(50);
	printList(L);

	// �ж������Ƿ�Ϊ��
	if (L.empty()) {
		std::cout << "����Ϊ��" << std::endl;
	}
	else {
		std::cout << "������Ϊ��" << std::endl;

		// size
		std::cout << "������СΪ��" << L.size() << std::endl;
	}

	// ����ָ����С
	L.resize(3);
	printList(L);
	std::cout << "����ָ����������СΪ��" << L.size() << std::endl;

	L.resize(5, 10);
	printList(L);
	std::cout << "����ָ����������СΪ��" << L.size() << std::endl;
}


/*
* List��������
* ����ԭ�ͣ�
* swap(lst); //��lst�뱾��Ԫ�ؽ���
*/
void ListSwap() {
	std::cout << "����ǰ" << std::endl;
	std::list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	L.push_back(50);
	printList(L);

	std::list<int>L2;
	L2.assign(10, 66);
	printList(L2);

	std::cout << "������" << std::endl;
	L.swap(L2);
	printList(L);
	printList(L2);
}

int main02() {
	ListSize();

	std::cout << "--------------------------\n";
	ListSwap();

	system("pause");
	return 0;
}