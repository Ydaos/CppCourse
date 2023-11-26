#include <iostream>
#include <fstream>
#include <string>

namespace my_src1 {

	void myWrite() { //д�ļ�

		// ����������
		std::ofstream ofs;

		// ָ���򿪷�ʽ
		ofs.open("test.txt", std::ios::out);

		// ���ļ���д���� 
		ofs << "����������" << std::endl;
		ofs << "�Ա���" << std::endl;
		ofs << "���䣺18" << std::endl;

		// �ر��ļ�
		ofs.close();
	}

	void myRead() { //���ļ�
		// ��������
		std::ifstream ifs;

		// ���ļ����ж��Ƿ�򿪳ɹ�
		ifs.open("test.txt", std::ios::in);
		if (!ifs.is_open()) {
			std::cout << "file open false\n";
			return;
		}

		// �����ݣ����ַ�ʽ
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
			//�����Ƽ���һ�����ֽڶ�ȡ�ٶ�̫����
			char c;
			while ((c = ifs.get()) != EOF) { // EOF: end of file
				std::cout << c;
			}
			break;
		default:
			break;
		}

		// 5���ر��ļ�
		ifs.close();
	}
}

int main01() {
	my_src1::myWrite();

	my_src1::myRead();


	system("pause");
	return 0;
}