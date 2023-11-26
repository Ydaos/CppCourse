#include <iostream>
#include <fstream>
#include <string>

// 二进制文件
class Person {
public:
	//二进制读写文件不建议用C++的string 优先C语言的char
	char m_name[64]; //姓名
	int m_age; //年龄
};

// 二进制写文件
// 函数原型：ostream& write(const *buf, int len);
void myWrite() {
	// 1、包含头文件
	// 2、创建流对象
	std::ofstream ofs("Person.txt", std::ios::out | std::ios::binary);

	// 3、打开文件
	//ofs.open("Person.txt", ios::out | ios::binary);
	// 位或操作声明文件是output 且是二进制binary的形式写入

	// 4、往文件中写内容 
	Person p = { "张三",18 };
	ofs.write((const char*)&p, sizeof(Person));

	// 5、关闭文件
	ofs.close();
}
// 总结：文件输出流对象可以通过write函数，以二进制写数据

// 二进制读文件
// 函数原型：istream& read(const *buf, int len);
// 字符指针buf指向一段内存空间首地址，len表示数据长度
void myRead() {
	// 2、创建对象
	std::ifstream ifs;

	// 3、打开文件并判断是否打开成功
	ifs.open("Person.txt", std::ios::in | std::ios::binary);
	if (!ifs.is_open()) {
		std::cout << "file open false" << std::endl;
		return;
	}

	// 4、读数据
	Person p;
	ifs.read((char*)&p, sizeof(Person));

	std::cout << "姓名：" << p.m_name << " 年龄：" << p.m_age << std::endl;

	// 5、关闭文件
	ifs.close();
}

int main() {
	myWrite();

	myRead();

	system("pause");
	return 0;
}