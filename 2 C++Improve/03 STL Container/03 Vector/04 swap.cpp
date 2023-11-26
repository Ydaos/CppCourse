#include <iostream>
#include <vector>

void printVector(std::vector<int>& v);// ����������01 definition.cpp

/*
* vector��������
* ����ԭ�ͣ�
* swap(v);  -- ��v�뱾���Ԫ�ػ���
* swap������ָ�뽻�����������������
*/

// 1������ʹ��
void Swap01() {
	std::cout << "����ǰ\n";
	std::vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);

	std::vector<int>v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	printVector(v2);

	std::cout << "������\n";
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

// 2��ʵ����;������swap�����ڴ�
void Swap02() {
	std::vector<int>v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	std::cout << "v��������" << v.capacity() << std::endl;
	std::cout << "v�Ĵ�С��" << v.size() << std::endl;

	v.resize(3); //����ָ����С
	std::cout << "v��������" << v.capacity() << std::endl;
	std::cout << "v�Ĵ�С��" << v.size() << std::endl;
	// ���size=3������������Ϊ13W+ ����ڴ�ռ��˷ѣ�����

	// ����swap���������ڴ�
	std::vector<int>(v).swap(v); //vector<int>(v) �������󣡵�ǰ��ִ�������������
	std::cout << "v��������" << v.capacity() << std::endl;
	std::cout << "v�Ĵ�С��" << v.size() << std::endl;

	// �ܽ�:swap������ָ�뽻���������ʹ�����������������Դﵽʵ�ʵ������ڴ�Ч��
}


int main04() {
	Swap01();
	std::cout << "--------------------------\n";
	Swap02();

	system("pause");
	return 0;
}