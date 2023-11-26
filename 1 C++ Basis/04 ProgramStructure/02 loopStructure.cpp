#include <iostream>

void while_demo();
void do_while_demo();
void for_demo();

/*
* 常见循环结构有以下几种：
* while
* do-while
* for
* 
* do-while和while区别在于 do-while会先执行一次循环语句
*/
void LoopStructure() {
	std::cout << "\n----------- This is a loop-while demo -------------\n";
	while_demo();

	std::cout << "\n----------- This is a loop-do_while demo -------------\n";
	do_while_demo();

	std::cout << "\n----------- This is a loop-for demo -------------\n";
	for_demo();
}

void while_demo() {
	//在屏幕中打印0~9这10个数字

	int num = 0;
	//在while()中加入循环条件
	//注意事项：写循环一定要避免死循环的出现
	while (num < 10) {
		std::cout << num << " ";
		num++;
	}
	std::cout << std::endl;
}

void do_while_demo() {
	//水仙花数：3位数，每个位上数字的三次幂之和等于他本身
	int num = 100;
	int a = 0; //个位
	int b = 0; //十位
	int c = 0; //百位

	do {
		a = num % 10; //获取个位数字
		b = (num / 10) % 10; //获取十位数字
		c = num / 100; //获取百位数字

		if ((a * a * a + b * b * b + c * c * c) == num) {
			std::cout << num << " ";
		}
		num++;
	} while (num < 1000);
	std::cout << std::endl;
}

void for_demo() {
	//for循环
	//打印数字0~9
	for (int i = 0; i < 10; i++) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//利用嵌套循环打印9*9乘法表
	//外层循环执行一次，内层循环执行一周
	for (int i = 1; i < 10; i++) { //外层循环
		for (int j = 1; j <= i; j++) { //内层循环
			std::cout << j << "*" << i << "=" << j * i << " ";
		}
		std::cout << std::endl;
	}
}

int main02() {
	LoopStructure();

	system("pause");
	return 0;
}