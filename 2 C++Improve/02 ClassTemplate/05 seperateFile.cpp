#include <iostream>
/*
* ��ģ����ļ���д
* ���⣺��ģ���г�Ա��������ʱ���ǵ��ý׶Σ����·��ļ���дʱ���Ӳ���
* 
* ���������
* ��ʽ1��ֱ�Ӱ��� .cppԴ�ļ��������� ��Ϊһ�㲻����.cpp �ļ���
* ��ʽ2����������ʵ��д��ͬһ���ļ��У������ĺ�׺Ϊ .hpp��.hpp��Լ�������ƣ�����ǿ��
*/

#include "person.hpp"

int main05() {
	Person<std::string, int> p("Tom", 20);
	p.showPerson();

	system("pause");
	return 0;
}