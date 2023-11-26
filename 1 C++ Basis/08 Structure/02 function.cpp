#include <iostream>

/*
* 结构体作为参数向函数中传递：值传递、地址传递
*/
struct Student {
	std::string name;
	int age = 0;
	int score = 0;
};

void print_Stu1(Student s) {
	std::cout << "学生姓名：" << s.name << "\t"
		<< "学生年龄：" << s.age << "\t"
		<< "学生分数：" << s.score << std::endl;
}

void print_Stu2(Student* s) {
	s->age = 100;
	std::cout << "学生姓名：" << s->name << "\t"
		<< "学生年龄：" << s->age << "\t"
		<< "学生分数：" << s->score << std::endl;
}

//将函数形参改为指针，可以减少内存空间（只占4字节），而且不会复制新的副本出来
//但是有隐患，可能改变主函数的值，用const可以避免
void print_Stu3(const Student* s) {
	//s->age = 100; error!!!不能修改const变量
	std::cout << "学生姓名：" << s->name << "\t"
		<< "学生年龄：" << s->age << "\t"
		<< "学生分数：" << s->score << std::endl;
}

void StructFunc() {
	
	//结构体做函数参数
	//将学生作为参数传入函数，打印学生信息
	Student stu = { "张三",18,100 };
	
	//值传递
	print_Stu1(stu);

	//地址传递
	print_Stu2(&stu);

	std::cout << "学生姓名：" << stu.name << "\t"
		<< "学生年龄：" << stu.age << "\t"
		<< "学生分数：" << stu.score << std::endl;

	//const的地址传递
	print_Stu3(&stu);
}

int main02() {
	StructFunc();

	system("pause");
	return 0;
}