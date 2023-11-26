#include <iostream>

/*
* 案例：设计一个英雄的结构体，包括成员姓名、年龄、性别；
* 创建结构体数组，数组中存放五个英雄
* 通过冒泡排序算法，将数组中的英雄按照年龄进行升序排序，并打印最终结果
*/

struct Hero {
	std::string name;
	int age = 0;
	std::string gender;
};

//打印所有信息函数
void printInfo(Hero hArr[], int len) {
	for (int i = 0; i < len; i++) {
		std::cout << "英雄姓名：" << hArr[i].name
			<< " 英雄年龄：" << hArr[i].age
			<< " 英雄性别：" << hArr[i].gender << std::endl;
	}
}

//冒泡排序函数对数组按年龄进行升序排序
void bubbleSort(Hero hArr[], int len) {
	for (int i = 0; i < len - 1; i++) {
		Hero temp;
		for (int j = i + 1; j < len; j++) {
			if (hArr[i].age > hArr[j].age) {
				temp = hArr[i];
				hArr[i] = hArr[j];
				hArr[j] = temp;
			}
		}
	}
}

void Practice() {
	//创建5名英雄的数组
	Hero h_arr[5] = { {"刘备",23,"男"},{"关羽",22,"男"}, {"张飞",20,"男"}, {"赵云",21,"男"}, {"貂蝉",19,"女"} };
	int len = sizeof(h_arr) / sizeof(h_arr[0]);

	//冒泡排序对数组进行排序，按年龄进行升序排列
	bubbleSort(h_arr, len);

	//通过函数输出所有信息
	printInfo(h_arr, len);
}

int main() {
	Practice();

	system("pause");
	return 0;
}