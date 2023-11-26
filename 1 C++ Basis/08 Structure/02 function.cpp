#include <iostream>

/*
* �ṹ����Ϊ���������д��ݣ�ֵ���ݡ���ַ����
*/
struct Student {
	std::string name;
	int age = 0;
	int score = 0;
};

void print_Stu1(Student s) {
	std::cout << "ѧ��������" << s.name << "\t"
		<< "ѧ�����䣺" << s.age << "\t"
		<< "ѧ��������" << s.score << std::endl;
}

void print_Stu2(Student* s) {
	s->age = 100;
	std::cout << "ѧ��������" << s->name << "\t"
		<< "ѧ�����䣺" << s->age << "\t"
		<< "ѧ��������" << s->score << std::endl;
}

//�������βθ�Ϊָ�룬���Լ����ڴ�ռ䣨ֻռ4�ֽڣ������Ҳ��Ḵ���µĸ�������
//���������������ܸı���������ֵ����const���Ա���
void print_Stu3(const Student* s) {
	//s->age = 100; error!!!�����޸�const����
	std::cout << "ѧ��������" << s->name << "\t"
		<< "ѧ�����䣺" << s->age << "\t"
		<< "ѧ��������" << s->score << std::endl;
}

void StructFunc() {
	
	//�ṹ������������
	//��ѧ����Ϊ�������뺯������ӡѧ����Ϣ
	Student stu = { "����",18,100 };
	
	//ֵ����
	print_Stu1(stu);

	//��ַ����
	print_Stu2(&stu);

	std::cout << "ѧ��������" << stu.name << "\t"
		<< "ѧ�����䣺" << stu.age << "\t"
		<< "ѧ��������" << stu.score << std::endl;

	//const�ĵ�ַ����
	print_Stu3(&stu);
}

int main02() {
	StructFunc();

	system("pause");
	return 0;
}