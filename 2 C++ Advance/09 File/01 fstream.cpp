#include <iostream>
#include <fstream>
#include <string>

namespace my_src1 {

	void myWrite() { //写文件

		// 创建流对象
		std::ofstream ofs;

		// 指定打开方式
		ofs.open("test.txt", std::ios::out);

		// 往文件中写内容 
		ofs << "姓名：张三" << std::endl;
		ofs << "性别：男" << std::endl;
		ofs << "年龄：18" << std::endl;

		// 关闭文件
		ofs.close();
	}

	void myRead() { //读文件
		// 创建对象
		std::ifstream ifs;

		// 打开文件并判断是否打开成功
		ifs.open("test.txt", std::ios::in);
		if (!ifs.is_open()) {
			std::cout << "file open false\n";
			return;
		}

		// 读数据：四种方式
		int key = 3;
		char buf[1024] = { 0 };
		std::string s_buf;
		switch (key)
		{
		case 1:
			while (ifs >> buf) {
				std::cout << buf << std::endl;
			}
			break;
		case 2:
			while (ifs.getline(buf, sizeof(buf))) {
				std::cout << buf << std::endl;
			}
			break;
		case 3:
			while (getline(ifs, s_buf)) {
				std::cout << s_buf << std::endl;
			}
			break;
		case 4:
			//（不推荐，一个个字节读取速度太慢）
			char c;
			while ((c = ifs.get()) != EOF) { // EOF: end of file
				std::cout << c;
			}
			break;
		default:
			break;
		}

		// 5、关闭文件
		ifs.close();
	}
}

int main01() {
	my_src1::myWrite();

	my_src1::myRead();


	system("pause");
	return 0;
}