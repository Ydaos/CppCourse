#include<iostream>

//1��#defube�곣��
#define Day 7

void m_constant() {
	std::cout << "\n ------------- constant demo ---------------------\n";
	//Day = 14; //����Day�ǳ�����һ���޸ľͻᱨ��
	std::cout << "һ���ܹ��У�" << Day << " ��" << std::endl;

	//2��const���εı���
	const int month = 12;
	//month = 14; //���� const���εı���Ҳ��Ϊ����

	std::cout << "һ���ܹ���: " << month << " ���·�" << std::endl;
}

/*
  main������һ����������
  ÿ�����������һ��
  �н���һ��
*/
int main() {

	std::cout << "Hello World!" << std::endl;

	//�����������﷨���������� ������ = ������ʼֵ
	int a = 10;
	std::cout << "a = " << a << std::endl;

	m_constant();

	//����ϵͳ�����е��ã�ָ�����pause����ͣ���򣬵ȴ����������ִ�С�
	system("pause");
	return 0;
}

/*
* ���ؼ��֡���C++�������⺬���Ԥ�ȶ��屣����ʶ����
* �Ա�������ʱ����ʹ�ùؼ��֣�
* �����ؼ����У�
* �߼��ؼ��֣�if do while break continue ...
* �������͹ؼ��֣�int float double ...
* �����ؼ��֣�void  main ...
* �����ؼ��֣�namespace using class ...
*/

/*
* ��ʶ�����������������������������
* 1�������ǹؼ���
* 2������ĸ�����֡��»������
* 3����ͷ��һ���ַ�ֻ������ĸ���»���
* 4�����ִ�Сд
*/

/*
* �����Ķ��巽ʽ
* 1��#define�곣�� #define ������ ����ֵ
* 2��const���εı��� const �������� ������ = ����ֵ
*/
