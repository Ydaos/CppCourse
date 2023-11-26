#include <iostream>
#include <deque>

void printDeque(const std::deque<int>& d);// ����������"01 definition.cpp"

/*
* deque ��С����
* ����ԭ�ͣ�
* deque.empty();              //�ж������Ƿ�Ϊ��
* deque.size();				  //����������Ԫ�صĸ���
* deque.resize(int num);	  //����ָ��������СΪnum.�������䳤����Ĭ��ֵ�����λ�ã������ɾ���������Ԫ��
* deque.resize(int num, ele,) //����ָ��������СΪnum���������䳤����elemֵ�����λ�ã������ɾ���������Ԫ��
*/
void mySize() {
	std::deque<int> d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);

	if (d1.empty()) {
		std::cout << "d1Ϊ��" << std::endl;
	}
	else {
		std::cout << "d1��Ϊ��" << std::endl;
		std::cout << "d1��С��" << d1.size() << std::endl;
		// dequeû����������
	}

	// ����ָ����С
	d1.resize(15, 2); //�ӳ�������2�����
	printDeque(d1);

	d1.resize(5);     //��̻�ɾ�������Ԫ��
	printDeque(d1);
}

int main02() {
	mySize();

	system("pause");
	return 0;
}