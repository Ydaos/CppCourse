#include <iostream>

//作用：从键盘获取数据
//语法： cin >> 变量;
void InputData() {
	//1、整型
	int a = 0;
	std::cout << "请给整型变量a赋值：\n";
	std::cin >> a;
	std::cout << "a = " << a << std::endl;

	//2、浮点型
	float f = 3.14f;
	std::cout << "请给浮点型变量f赋值：\n";
	std::cin >> f;
	std::cout << "f = " << f << std::endl;

	//3、字符型
	char ch = 'a';
	std::cout << "请给字符型变量ch赋值：\n";
	std::cin >> ch;
	std::cout << "ch = " << ch << std::endl;

	//4、字符串型
	std::string str = "hello";
	std::cout << "请给字符串型变量str赋值：\n";
	std::cin >> str;
	std::cout << "str = " << str << std::endl;

	//5、布尔类型
	bool flag = false;
	std::cout << "请给布尔类型变量flag赋值：\n";
	std::cin >> flag; //布尔类型只要是非0的值都为真
	std::cout << "flag = " << flag << std::endl;
}

int main() {
	InputData();

	system("pause");
	return 0;
}