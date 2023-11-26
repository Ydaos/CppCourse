#include <iostream>

void array_name();
void multi_dimensional_array_name();

/*
* һά��������;��
* ����ͳ�������������ڴ��еĳ���  sizeof(arr)
* ���Ի�ȡ�������ڴ��е��׵�ַ
*/
void ArrayName() {
	std::cout << "\nThis is a one-dimensional array demo.\n";
	array_name();

	std::cout << "\nThis is a two-dimensional array demo.\n";
	multi_dimensional_array_name();
}

void array_name() {
	//1��ͳ�������������ڴ��еĳ���
	int arr[5] = { 1,2,3,4,5 };
	std::cout << sizeof(arr) << std::endl; //�����������ݳ���
	std::cout << sizeof(arr[0]) << std::endl; //���鵥��Ԫ�����ݳ���
	std::cout << sizeof(arr) / sizeof(arr[0]) << std::endl; //����Ԫ�ظ���

	//2�����Ի�ȡ�������ڴ��е��׵�ַ
	std::cout << arr << std::endl; //�������ڴ��е��׵�ַ
	std::cout << &arr[0] << std::endl; //�����һ��Ԫ�صĵ�ַ
	std::cout << &arr[1] << std::endl; //����ڶ���Ԫ�صĵ�ַ���ȵ�һ��Ԫ�ص�ַ��4����Ϊ���ݳ���Ϊ4

	//arr = 100; error!!!�������Ǹ������������Ը�ֵ
}

void multi_dimensional_array_name() {
	//��ά����������;��

	//1�����Բ鿴ռ���ڴ�ռ��С
	int arr[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	std::cout << "��ά����ռ���ڴ�ռ��ǣ�" << sizeof(arr) << std::endl;
	std::cout << "��ά�����һ��Ԫ��ռ���ڴ�ռ��ǣ�" << sizeof(arr[0]) << std::endl;
	std::cout << "��ά�����һ��Ԫ��ռ���ڴ�ռ��ǣ�" << sizeof(arr[0][0]) << std::endl;

	std::cout << "��ά����������" << sizeof(arr) / sizeof(arr[0]) << std::endl;
	std::cout << "��ά����������" << sizeof(arr[0]) / sizeof(arr[0][0]) << std::endl;

	//2�����Բ鿴��ά������׵�ַ
	std::cout << "��ά�����׵�ַ��" << (int)arr << std::endl;
	std::cout << "��ά�����һ�е�ַ��" << (int)arr[0] << std::endl;
	std::cout << "��ά����ڶ��е�ַ��" << (int)arr[1] << std::endl;
}

int main02() {
	ArrayName();

	system("pause");
	return 0;
}