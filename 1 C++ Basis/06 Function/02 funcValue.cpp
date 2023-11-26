#include <iostream>

/*
* 函数的分文件编写
* 1、创建 .h后缀名的头文件
* 2、创建 .cpp后缀名的源文件
* 3、在头文件中写函数声明
* 4、在源文件中写函数定义
* 
* 函数的声明：提前告诉编译器函数存在
* 声明可以多次，但定义只能有一次
*/

void swap(int num1, int num2);
void swap(int num1, int num2);

void swap2(int& num1, int& num2);
void PrintArr(int(&arr)[6]);
void PrintArr2(int arr[6]);


//函数调用时的值传递规则
void funcCall() {
	int a = 10;
	int b = 20;

	//函数值传递，形参发生改变不会影响实参
	swap(a, b);
	std::cout << "a = " << a << " b = " << b << std::endl;

	//函数地址传递，实参值会改变
	swap2(a, b);
	std::cout << "a = " << a << " b = " << b << std::endl;

	//函数参数为数组，本质为地址传递
	int arr[6] = { 1,2,3,4,5,6 };
	for (int i = 0; i < 6; i++) {
		std::cout << &arr[i] << std::endl;
	}
	PrintArr(arr);
	PrintArr2(arr);

	/*
	* 两个打印数组函数传参差异：
	* 1、(&arr)传进来整个数组地址，故调试可以看到数组成员的值；
	* 2、arr[6]或*arr 传进来数组首元素地址，故调试只能看到第一个值；
	* 3、数组内存空间连续，只要有首地址就能迭代得到整个数组的值。
	*/
}

void swap(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void swap2(int& num1, int& num2) //&引用符
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void PrintArr(int(&arr)[6])
{
	std::cout << "\ntest1\n";
	for (int i = 0; i < 6; i++) {
		std::cout << &arr[i] << "--" << arr + i << std::endl; //等价
	}
}

void PrintArr2(int arr[6])
{
	std::cout << "\ntest2\n";
	std::cout << (&arr)[0] << std::endl;
	std::cout << (&arr)[1] << std::endl;
	//比上个地址大24，因为数组arr占24字节，证明(&arr)打印整个数组地址
}

int main() {
	funcCall();

	system("pause");
	return 0;
}