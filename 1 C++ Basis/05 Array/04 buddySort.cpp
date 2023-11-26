#include <iostream>

void BubbleSort() {
	int arr[10] = { 4,2,8,0,5,7,1,3,9,6 };
	int tmp = 0;
	//1¡¢ÉıĞòÅÅĞò
	for (int i = 0; i < 9; i++) {
		tmp = arr[i];
		for (int j = i + 1; j < 10; j++) {
			if (arr[j] < tmp) {
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
	for (int k = 0; k < 10; k++) {
		std::cout << arr[k] << " ";
	}
	std::cout << std::endl;

	//2¡¢½µĞòÅÅĞò
	for (int i = 0; i < 9; i++) {
		tmp = arr[i];
		for (int j = i + 1; j < 10; j++) {
			if (arr[j] > tmp) {
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
	for (int k = 0; k < 10; k++) {
		std::cout << arr[k] << " ";
	}
	std::cout << std::endl;
}

int main() {
	BubbleSort();

	system("pause");
	return 0;
}