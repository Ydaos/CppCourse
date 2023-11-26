#include <iostream>

struct Student {
	std::string name;
	int age = 0;
	int score = 0;
};

//结构体的成员可以是另一个结构体
struct Teacher {
	std::string name;
	Student stu_arr[5];
};


/*
* 案例：一共三个老师，每个老师带五个学生做毕设
* 设计老师和学生的结构体，老师结构体中有姓名和一个存放五个学生的数组作为成员
* 学生的成员有姓名和分数，创建数组存放三个老师
* 通过函数给老师及其所带的学生赋值，并打印最终数据
*/

//给老师和学生赋值的函数
void allocateSpace(Teacher tArr[], int len) {
	std::string nameSeed = "ABCDE";
	for (int i = 0; i < len; i++) {
		tArr[i].name = "Teacher_";
		tArr[i].name += nameSeed[i];

		//通过循环给每名老师带的学生赋值
		for (int j = 0; j < 5; j++) {
			tArr[i].stu_arr[j].name = "Student_";
			tArr[i].stu_arr[j].name += nameSeed[j];

			int score = rand() % 61 + 40;  //生成40~100随机数
			tArr[i].stu_arr[j].score = score;
		}
	}
}

//打印所有信息函数
void printInfo(Teacher tArr[], int len) {
	for (int i = 0; i < len; i++) {
		std::cout << "教师姓名：" << tArr[i].name << std::endl;
		for (int j = 0; j < 5; j++) {
			std::cout << "\t学生姓名：" << tArr[i].stu_arr[j].name
				<< " 学生分数" << tArr[i].stu_arr[j].score << std::endl;
		}
	}
}

void CompositeStruct() {
	//随机数种子
	srand((unsigned int)time(0));

	//创建3名老师的数组
	Teacher t_arr[3];
	int len = sizeof(t_arr) / sizeof(t_arr[0]);

	//通过函数给3名老师的信息赋值
	allocateSpace(t_arr, len);

	//通过函数输出所有信息
	printInfo(t_arr, len);
}

int main03() {
	CompositeStruct();

	system("pause");
	return 0;
}