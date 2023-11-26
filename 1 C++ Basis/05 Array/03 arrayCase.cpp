#include <iostream>

void case1();
void case2();

void ArrayCase() {
	std::cout << "\nThis is a one-dimensional array demo.\n";
	case1();

	std::cout << "\nThis is a two-dimensional array demo.\n";
	case2();
}

void case1() {
	//1、五只小猪称体重(数组中找到最大值)
	int arr[6] = { 300,350,500,400,250,100 };
	int max = arr[0];
	for (int i = 1; i < 5; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	std::cout << max << std::endl;

	//2、数组元素逆置
	int start = 0; //数组首部下标
	int end = sizeof(arr) / sizeof(arr[0]) - 1; //数组尾部下标
	int tmp = 0; //容器

	for (int i = 0; i <= (end - start) / 2; i++) {
		tmp = arr[i];
		arr[i] = arr[end - i];
		arr[end - i] = tmp;
	}
	for (int i = 0; i < 6; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void case2() {
	std::string name[3] = { "张三","李四","王五" };
	int scores[3][3] = {
		{100,100,100},
		{90,50,100},
		{60,70,80}
	};
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += scores[i][j];
		}
		std::cout << name[i] << "的总成绩为：" << sum << std::endl;
	}
}

int main03() {
	ArrayCase();

	system("pause");
	return 0;
}