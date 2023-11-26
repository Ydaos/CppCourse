#include <iostream>
#include <set>

void printSet(const std::set<int>& s); //����������"01 definition.cpp

/*
* pair���飺�ɶԳ��ֵ����ݣ����ö�����Է�����������
* ���ִ�����ʽ��
* pair<type, type> p(val1, val2);             
* pair<type, type> p = make_pair(val1, val2); 
*/
void PairDefine() {
	// ��һ�ַ�ʽ
	std::pair<std::string, int>p("Tom", 20);
	std::cout << "������" << p.first << " ���䣺" << p.second << std::endl;

	// �ڶ��ַ�ʽ
	std::pair<std::string, int>p2 = std::make_pair("Jerry", 16);
	std::cout << "������" << p2.first << " ���䣺" << p2.second << std::endl;
}


/*
* set��multiset����
* 1��set�����Բ��ظ����ݣ�multiset����
* 2��set�������ݵ�ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ������ؽ��Ϊ pair<set<T>::iterator, bool>
* 3��multiset���������ݣ����ؽ��Ϊ������set<T>::iterator����˿��Բ����ظ�����
*/
void Diff() {
	std::set<int> s1;
	std::pair<std::set<int>::iterator, bool>ret = s1.insert(10);
	if (ret.second) {
		std::cout << "��һ�β���ɹ�\n";
	}
	else {
		std::cout << "��һ�β���ʧ��\n";
	}

	ret = s1.insert(10);
	if (ret.second) {
		std::cout << "�ڶ��β���ɹ�\n";
	}
	else {
		std::cout << "�ڶ��β���ʧ��\n";
	}

	std::multiset<int> ms;
	ms.insert(10);
	ms.insert(10); //insert���ص��ǵ��������������ݲ�����м��
	for (std::multiset<int>::const_iterator it = ms.begin(); it != ms.end(); it++) {
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
}


int main04() {
	PairDefine();

	std::cout << "------------------\n";
	Diff();

	system("pause");
	return 0;
}