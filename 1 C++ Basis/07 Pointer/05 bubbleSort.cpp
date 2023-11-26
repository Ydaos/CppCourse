#include <iostream>

//封装一个函数，利用冒泡排序，实现对整型数组的升序排序

void BubbleSort(int* arr, int len);

void Fun_BubbleSort() {
	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
	BubbleSort(arr, 10);
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	//指针本身含有迭代功能 p[0]即*p 指向首地址
	int a = 10;
	int* p = &a;
	std::cout << p[0] << std::endl;
	std::cout << p[1] << std::endl; //超限，指向下一个地址，但地址内没初始值（野指针）
}

//冒泡排序函数 参数1 数组首地址 参数2 数组长度
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
