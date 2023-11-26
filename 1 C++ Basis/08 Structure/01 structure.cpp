#include <iostream>

/*
* 结构体属于用户自定义的数据类型，允许用户存储不同的数据类型
* 语法：struct 结构体名{ 结构体成员列表 };
*
* 结构体的成员可以是另一个结构体
*/
struct Student {
	// 姓名
	std::string name;
	// 年龄
	int age = 0;
	//分数
	int score = 0;
}s3;//顺便创建一个结构体变量（不建议！！！）

//1、创建结构体变量
void StructDefine() {
	
	//1.1 通过 . 访问结构体变量中的成员来赋值
	struct Student s1;
	s1.name = "张三";
	s1.age = 18;
	s1.score = 100;
	std::cout << "姓名：" << s1.name << " 年龄：" << s1.age << " 分数：" << s1.score << std::endl;

	//1.2 struct Student s2 = { ... }
	Student s2 = { "李四",19,99 };//struct 在创建变量时候关键字可以省略
	std::cout << "姓名：" << s2.name << " 年龄：" << s2.age << " 分数：" << s2.score << std::endl;

	//2.3 在定义结构体时顺便创建结构体变量
	s3.name = "王五";
	s3.age = 20;
	s3.score = 80;
	std::cout << "姓名：" << s3.name << " 年龄：" << s3.age << " 分数：" << s3.score << std::endl;
	
	//推荐第1 2种
	//如果把结构体写进头文件统一管理，该头文件被多个源文件引用时，第三种写法会导致结构体变量重复定义！！！
}

//2、创建结构体数组
void StructArray() {
	//创建结构体数组
	Student arr[3] = { { "张三",18,100 },{ "李四",19,90 },{ "王五",20,80 } };

	//给结构体数组中的元素赋值
	arr[2].name = "赵六";
	arr[2].age = 21;
	arr[2].score = 60;

	//遍历结构体数组
	for (int i = 0; i < 3; i++) {
		std::cout << "姓名：" << arr[i].name
			<< " 年龄：" << arr[i].age
			<< " 成绩：" << arr[i].score << std::endl;
	}
}

//3、通过结构体指针访问结构体内的成员
void StructPointer() {
	//创建学生的结构体变量
	Student s = { "张三",18,100 };

	//通过指针指向结构体变量
	Student* p = &s;

	//通过指针访问结构体变量中的数据
	std::cout << "姓名: " << p->name << " 年龄: " << p->age << " 分数: " << p->score << std::endl;
}

int main01() {
	std::cout << "\n--------------------------StructDefine\n";
	StructDefine();

	std::cout << "\n--------------------------StructArray\n";
	StructArray();

	std::cout << "\n--------------------------StructPointer\n";
	StructPointer();

	system("pause");
	return 0;
}