#include <iostream>

//��װһ������������ð������ʵ�ֶ������������������

void BubbleSort(int* arr, int len);

void Fun_BubbleSort() {
	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
	BubbleSort(arr, 10);
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	//ָ�뱾���е������� p[0]��*p ָ���׵�ַ
	int a = 10;
	int* p = &a;
	std::cout << p[0] << std::endl;
	std::cout << p[1] << std::endl; //���ޣ�ָ����һ����ַ������ַ��û��ʼֵ��Ұָ�룩
}

//ð�������� ����1 �����׵�ַ ����2 ���鳤��
void BubbleSort(int* arr, int len) {
	int temp = 0;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < arr[i]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

int main() {
	Fun_BubbleSort();

	system("pause");
	return 0;
}
