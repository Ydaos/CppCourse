#include <iostream>

void AssignmentOperator() {

	//¸³ÖµÔËËã·û
	// = 
	int a = 10;
	a = 100;
	std::cout << "a = " << a << std::endl;

	// +=
	a = 10;
	a += 2; // a = a + 2;
	std::cout << "a = " << a << std::endl;

	// -=
	a = 10;
	a -= 2; // a = a - 2;
	std::cout << "a = " << a << std::endl;

	// *=
	a = 10;
	a *= 2; // a = a * 2;
	std::cout << "a = " << a << std::endl;

	// /=
	a = 10;
	a /= 2; // a = a / 2;
	std::cout << "a = " << a << std::endl;

	// %=
	a = 10;
	a %= 3; // a = a % 3;
	std::cout << "a = " << a << std::endl;
}

int main02() {
	AssignmentOperator();

	system("pause");
	return 0;
}