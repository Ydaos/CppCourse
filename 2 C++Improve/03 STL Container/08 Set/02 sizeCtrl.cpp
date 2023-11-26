#include <iostream>
#include <set>

void printSet(const std::set<int>& s); //����������"01 definition.cpp"

/*
* set������С�ͽ���
* ����ԭ�ͣ�
* size();	  //��������Ԫ����Ŀ
* empty();    //�ж������Ƿ�Ϊ��
* swap(s);    //������������
* 
* ע�����set�������������ظ�Ԫ�أ����Բ���resize()������С����ΪĬ��ֵ��������ظ�����
*/
void MySize() {
	std::set<int> s1;
	s1.insert(10);
	s1.insert(22);
	s1.insert(20);
	s1.insert(11);
	s1.insert(50);

	if (s1.empty()) {
		std::cout << "����Ϊ��\n";
	}
	else {
		std::cout << "������Ϊ��\n";
		std::cout << "����Ԫ�ظ�����" << s1.size() << std::endl;
	}
}

void MySwap() {
	std::set<int> s1;
	s1.insert(10);
	s1.insert(22);
	s1.insert(20);
	s1.insert(11);
	s1.insert(50);

	std::set<int> s2;
	s2.insert(100);
	s2.insert(220);
	s2.insert(200);

	std::cout << "����ǰ��\n";
	printSet(s1);
	printSet(s2);

	std::cout << "������\n";
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
}

int main02() {
	MySize();

	std::cout << "------------------\n";
	MySwap();

	system("pause");
	return 0;
}