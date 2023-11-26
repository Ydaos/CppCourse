#include <iostream>

void break_demo();
void continue_demo();
void goto_demo();

/*
* 常见流程控制关键字有：break、continue、goto
*/
void Keyword() {
	std::cout << "\n----------- This is a break statement demo -------------\n";
	break_demo();

	std::cout << "\n----------- This is a continue statement demo -------------\n";
	continue_demo();

	std::cout << "\n----------- This is a goto statement demo -------------\n";
	goto_demo();
}

//break: 用于跳出选择结构或循环结构
void break_demo() {
	//break使用时机
	//1、用于switch
	std::cout << "请选择副本难度" << std::endl;
	std::cout << "1、普通" << std::endl;
	std::cout << "2、中等" << std::endl;
	std::cout << "3、困难" << std::endl;

	int select = 0;
	std::cin >> select;
	switch (select)
	{
	case 1:
		std::cout << "您选择的是普通难度" << std::endl;
		break;
	case 2:
		std::cout << "您选择的是中等难度" << std::endl;
		break;
	case 3:
		std::cout << "您选择的是困难难度" << std::endl;
		break;
	default:
		break;
	}

	//2、出现在循环语句中
	for (int i = 0; i < 10; i++) {
		if (i == 5) {
			break; //退出循环
		}
		std::cout << i << std::endl;
	}

	//3、出现在嵌套语句中
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 5) {
				break; //退出内层循环
			}
			std::cout << "* ";
		}
		std::cout << std::endl;
	}
}

void continue_demo() {
	//continue语句
	for (int i = 0; i < 20; i++) {
		if (i % 2 == 0) {
			continue; //可筛选条件，执行下一次循环
			//break;会退出循环
		}
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void goto_demo() {
	//goto语句
	std::cout << "1" << std::endl;
	std::cout << "2" << std::endl;
	goto FLAG;
	std::cout << "3" << std::endl;
	std::cout << "4" << std::endl;
FLAG:
	std::cout << "5" << std::endl;
	//尽量不使用，容易代码逻辑混乱
}

int main() {
	Keyword();

	system("pause");
	return 0;
}