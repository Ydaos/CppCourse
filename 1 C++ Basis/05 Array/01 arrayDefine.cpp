#include <iostream>

void array_define();
void multidimensional_array_define();
/*
* 数组特点：
* 放在一块连续的内存空间
* 数组中每个元素是相同的数据类型
* 通过下标访问数组中的元素，下标从0开始
*/
void ArrayDefine() {
	std::cout << "\nThis is a one-dimensional array demo.\n";
	array_define();

	std::cout << "\nThis is a two-dimensional array demo.\n";
	multidimensional_array_define();
}

// 一维数组定义
void array_define() {
	//数组定义
	//1、数据类型 数组名[数组长度];
	int arr1[3];
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 3;
	std::cout << arr1[0] << " " << arr1[1] << "," << arr1[2] << std::endl;

	//2、数据类型 数组名[数组长度] = {值1,值2,值3...};
	//如果初始化数据没有全部填写完，会用0来填补剩余数据
	int arr2[5] = { 1,2,3,4 };
	for (int i = 0; i < 5; i++) {
		std::cout << arr2[i] << ",";
	}
	std::cout << std::endl;

	//3、数据类型 数组名[ ] = {值1,值2,值3...};
	int arr3[] = { 1,2,3,4,5,6,7 };
	for (int i = 0; i < 7; i++) {
		std::cout << arr3[i] << ",";
	}
	std::cout << std::endl;

	char str[] = "hello world"; //C命名字符串方法
	std::string str1 = "hello world";//C++命名字符串方法
	//所以字符串本质就是字节数组！？
	std::cout << str << std::endl;
	std::cout << str1 << std::endl;

	std::string str2[] = { str,str1 }; //字符串数组
	std::cout << str2[0] << "-" << str2[1] << std::endl;
}

// 高维数组定义（以二维数组为例）
void multidimensional_array_define() {
	//1、数据类型 数组名[行数][列数];
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

	//2、数据类型 数组名[行数][列数] = {{数据1,数据2} , {数据3,数据4}};
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

	//3、数据类型 数组名[行数][列数] = { 数据1,数据2,数据3,数据4 };
	int arr3[2][3] = { 1,2,3,1,2 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << arr3[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//4、数据类型 数组名[][列数] = = {数据1,数据2 , 数据3,数据4};
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