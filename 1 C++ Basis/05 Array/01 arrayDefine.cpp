#include <iostream>

void array_define();
void multidimensional_array_define();
/*
* �����ص㣺
* ����һ���������ڴ�ռ�
* ������ÿ��Ԫ������ͬ����������
* ͨ���±���������е�Ԫ�أ��±��0��ʼ
*/
void ArrayDefine() {
	std::cout << "\nThis is a one-dimensional array demo.\n";
	array_define();

	std::cout << "\nThis is a two-dimensional array demo.\n";
	multidimensional_array_define();
}

// һά���鶨��
void array_define() {
	//���鶨��
	//1���������� ������[���鳤��];
	int arr1[3];
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 3;
	std::cout << arr1[0] << " " << arr1[1] << "," << arr1[2] << std::endl;

	//2���������� ������[���鳤��] = {ֵ1,ֵ2,ֵ3...};
	//�����ʼ������û��ȫ����д�꣬����0���ʣ������
	int arr2[5] = { 1,2,3,4 };
	for (int i = 0; i < 5; i++) {
		std::cout << arr2[i] << ",";
	}
	std::cout << std::endl;

	//3���������� ������[ ] = {ֵ1,ֵ2,ֵ3...};
	int arr3[] = { 1,2,3,4,5,6,7 };
	for (int i = 0; i < 7; i++) {
		std::cout << arr3[i] << ",";
	}
	std::cout << std::endl;

	char str[] = "hello world"; //C�����ַ�������
	std::string str1 = "hello world";//C++�����ַ�������
	//�����ַ������ʾ����ֽ����飡��
	std::cout << str << std::endl;
	std::cout << str1 << std::endl;

	std::string str2[] = { str,str1 }; //�ַ�������
	std::cout << str2[0] << "-" << str2[1] << std::endl;
}

// ��ά���鶨�壨�Զ�ά����Ϊ����
void multidimensional_array_define() {
	//1���������� ������[����][����];
	int arr1[2][3];
	arr1[0][0] = 1;
	arr1[0][1] = 2;
	arr1[0][2] = 3;
	arr1[1][0] = 4;
	arr1[1][1] = 5;
	arr1[1][2] = 6;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << arr1[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//2���������� ������[����][����] = {{����1,����2} , {����3,����4}};
	int arr2[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << arr2[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//3���������� ������[����][����] = { ����1,����2,����3,����4 };
	int arr3[2][3] = { 1,2,3,1,2 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << arr3[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//4���������� ������[][����] = = {����1,����2 , ����3,����4};
	int arr4[][3] = { 1,2,3,1,2 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << arr3[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main01() {
	ArrayDefine();

	system("pause");
	return 0;
}