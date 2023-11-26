#include <iostream>
#include <set>

/*
* set�����ϣ�������
* set�����������ݻ��Զ������Ҳ��������ظ�����
* set��������ֻ����insert��û��push��pop�Ĳ���
* 
* ���ʣ�set/multiset ���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��
* 
* set��multiset����
* 1��set�������������ظ�Ԫ��
* 2��multiset �������������ظ���Ԫ��
*/
void printSet(const std::set<int>& s) {
	for (std::set<int>::const_iterator it = s.begin(); it != s.end(); it++) {
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
}


/*
* set����͸�ֵ
* ����ԭ�ͣ�
* set<T> st;					 //Ĭ�Ϲ��캯��
* set(const set &st);		     //�������캯��
* set& operator=(const set &st); //����=�����
*/
void Definition() {
	std::set<int> s1;

	// ��������ֻ��insert��ʽ
	s1.insert(10);
	s1.insert(22);
	s1.insert(20);
	s1.insert(11);
	s1.insert(50);

	// ��������
	// �ص㣺����Ԫ�ز���ʱ���Զ�����
	// set��������������ظ���ֵ������
	printSet(s1);

	// ��������
	std::set<int> s2(s1);
	printSet(s2);

	// ��ֵ
	std::set<int> s3;
	s3 = s2;
	printSet(s3);
}

int main01() {
	Definition();

	system("pause");
	return 0;
}