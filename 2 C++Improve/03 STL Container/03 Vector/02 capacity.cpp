#include <iostream>
#include <vector>

void printVector(std::vector<int>& v);// ����������01 definition.cpp

/*
* vector�����ʹ�С
* ����ԭ�ͣ�
* empty();			     //�ж������Ƿ�Ϊ��
* capacity();            //����������
* size();                //����������Ԫ�صĸ���
* resize(int num);       //����ָ�������ĳ���Ϊnum���������䳤����Ĭ��ֵ����䣻�����������β�������������ȵ�Ԫ�ػᱻɾ��
* resize(int num, elem); //����ָ�������ĳ���Ϊnum���������䳤����elemֵ����䣻�����������β�������������ȵ�Ԫ�ػᱻɾ��
* 
* vectorԤ���ռ䣺����vector�ڶ�̬��չ����ʱ����չ����
* ����ԭ�ͣ�
* reserve(int len);      //����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ���
*/
void Capacity() {
	std::vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty()) {
		std::cout << "v1Ϊ��" << std::endl;
	}
	else {
		std::cout << "v1��Ϊ��" << std::endl;
		std::cout << "v1 ������" << v1.capacity() << std::endl;
		std::cout << "v1 ��С��" << v1.size() << std::endl;
	}

	// ����ָ����С
	v1.resize(15);
	printVector(v1); //�������ָ���ı�ԭ������Ĭ����0����µ�λ��

	v1.resize(20, 6);
	printVector(v1); //�����ذ汾����ʹ��ָ��ֵ����µ�λ��

	v1.resize(5);
	printVector(v1); //�������ָ����ԭ���̣���ɾ���������β��


	// ����reserveԤ���ռ�
	std::vector<int> v;
	v.reserve(100000);

	int num = 0; // ͳ�ƿ��ٴ���
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	std::cout << "\n���ٴ���:" << num << std::endl;
	// �ܽ�:����������Ƚϴ󣬿���һ��ʼ����reserveԤ���ռ�
}

int main() {
	Capacity();

	system("pause");
	return 0;
}