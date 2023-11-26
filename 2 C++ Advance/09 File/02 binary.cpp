#include <iostream>
#include <fstream>
#include <string>

// �������ļ�
class Person {
public:
	//�����ƶ�д�ļ���������C++��string ����C���Ե�char
	char m_name[64]; //����
	int m_age; //����
};

// ������д�ļ�
// ����ԭ�ͣ�ostream& write(const *buf, int len);
void myWrite() {
	// 1������ͷ�ļ�
	// 2������������
	std::ofstream ofs("Person.txt", std::ios::out | std::ios::binary);

	// 3�����ļ�
	//ofs.open("Person.txt", ios::out | ios::binary);
	// λ����������ļ���output ���Ƕ�����binary����ʽд��

	// 4�����ļ���д���� 
	Person p = { "����",18 };
	ofs.write((const char*)&p, sizeof(Person));

	// 5���ر��ļ�
	ofs.close();
}
// �ܽ᣺�ļ�������������ͨ��write�������Զ�����д����

// �����ƶ��ļ�
// ����ԭ�ͣ�istream& read(const *buf, int len);
// �ַ�ָ��bufָ��һ���ڴ�ռ��׵�ַ��len��ʾ���ݳ���
void myRead() {
	// 2����������
	std::ifstream ifs;

	// 3�����ļ����ж��Ƿ�򿪳ɹ�
	ifs.open("Person.txt", std::ios::in | std::ios::binary);
	if (!ifs.is_open()) {
		std::cout << "file open false" << std::endl;
		return;
	}

	// 4��������
	Person p;
	ifs.read((char*)&p, sizeof(Person));

	std::cout << "������" << p.m_name << " ���䣺" << p.m_age << std::endl;

	// 5���ر��ļ�
	ifs.close();
}

int main() {
	myWrite();

	myRead();

	system("pause");
	return 0;
}