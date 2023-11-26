#include <iostream>

void if_else_demo();
void ternary_operator_demo();
void switch_demo();

/*
* 程序流程结构有三种：顺序结构、选择结构、循环结构
* 
* 常见选择结构有以下几种：
* if else-if else
* 三目运算符
* switch-case
*/
void SelectionStructure() {
	//选择结构 - 单行if语句
	std::cout << "\n----------- This is a if-else demo -------------\n";
	if_else_demo();
	
	//三目运算符
	std::cout << "\n----------- This is a ternary operator demo -------------\n";
	ternary_operator_demo();

	//switch-case
	std::cout << "\n----------- This is a switch-case demo -------------\n";
	switch_demo();

	//if和switch区别
	//switch缺点：在判断时候只能是整型或字符型，不可以是一个区间
	//switch优点：结构清晰，执行效率高
}

void if_else_demo() {
	//1、用户输入分数
	int score = 0;
	std::cout << "请输出一个分数" << std::endl;
	std::cin >> score;

	//2、打印用户分数
	std::cout << "您输入的分数为：" << score << std::endl;

	//3、判断分数是否大于600，是就输出
	//注意事项：在if判断语句后面，不要加分号
	if (score >= 600) {
		std::cout << "恭喜你考入一本大学" << std::endl;
		if (score > 700) {
			std::cout << "您能考入清华大学" << std::endl;
		}
		else if (score > 650) {
			std::cout << "您能考入北京大学" << std::endl;
		}
		else {
			std::cout << "您能考入人民大学" << std::endl;
		}
	}
	else if (score >= 500) {
		std::cout << "恭喜你考上二本大学" << std::endl;
	}
	else if (score >= 400) {
		std::cout << "恭喜你考上三本大学" << std::endl;
	}
	else {
		std::cout << "很遗憾你未考上本科大学，请再接再厉" << std::endl;
	}
}

void ternary_operator_demo() {
	//三目运算符

	//创建三个变量 a b c
	//将a b最大值赋值给c
	int a = 10;
	int b = 20;
	int c = 0;

	c = (a > b ? a : b);
	std::cout << "c = " << c << std::endl;

	//在C++中三目运算符返回的是变量，可以继续赋值
	(a > b ? a : b) = 100;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
}

void switch_demo() {
	//给电影打分：10~9 经典；8~7 非常好;6~5 一般；5以下 烂片

	//1、给电影打分
	int score = 0;
	std::cout << "请从0~10中选一个数字给电影打分" << std::endl;
	std::cin >> score;
	std::cout << "你打的分是" << score << std::endl;

	//2、根据用户评分来提示电影最后的结果
	switch (score) {
	case 10:
		std::cout << "您认为是经典电影" << std::endl;
		break; //退出当前分支，否则会往下执行！！！
	case 9:
		std::cout << "您认为是经典电影" << std::endl;
		break;
	case 8:
		std::cout << "您认为电影非常好" << std::endl;
		break;
	case 7:
		std::cout << "您认为电影非常好" << std::endl;
		break;
	case 6:
		std::cout << "您认为电影一般" << std::endl;
		break;
	case 5:
		std::cout << "您认为电影一般" << std::endl;
		break;
	default:
		std::cout << "您认为电影是烂片" << std::endl;
		break;
	}
}

int main01() {
	SelectionStructure();

	system("pause");
	return 0;
}