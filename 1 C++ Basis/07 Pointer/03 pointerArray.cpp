#include <iostream>

//���ã�ʹ��ָ�����������Ԫ��
void PointerArray() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	std::cout << "��һ��Ԫ��Ϊ��" << arr[0] << std::endl;

	int* p = arr;//arr����������׵�ַ
	std::cout << "����ָ����ʵ�һ��Ԫ��Ϊ��" << *p << std::endl;
	p++; //��ָ�����ƫ��4���ֽ�
	std::cout << "����ָ����ʵڶ���Ԫ��Ϊ��" << *p << std::endl;

	int* p2 = arr;
	for (int i = 0; i < 10; i++) {
		std::cout << "����ָ����ʵ�" << i + 1 << "��Ԫ��Ϊ��" << *p2 << std::endl;
		p2++;
	}
}

int main03() {
	PointerArray();

	system("pause");
	return 0;
}