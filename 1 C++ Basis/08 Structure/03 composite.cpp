#include <iostream>

struct Student {
	std::string name;
	int age = 0;
	int score = 0;
};

//�ṹ��ĳ�Ա��������һ���ṹ��
struct Teacher {
	std::string name;
	Student stu_arr[5];
};


/*
* ������һ��������ʦ��ÿ����ʦ�����ѧ��������
* �����ʦ��ѧ���Ľṹ�壬��ʦ�ṹ������������һ��������ѧ����������Ϊ��Ա
* ѧ���ĳ�Ա�������ͷ���������������������ʦ
* ͨ����������ʦ����������ѧ����ֵ������ӡ��������
*/

//����ʦ��ѧ����ֵ�ĺ���
void allocateSpace(Teacher tArr[], int len) {
	std::string nameSeed = "ABCDE";
	for (int i = 0; i < len; i++) {
		tArr[i].name = "Teacher_";
		tArr[i].name += nameSeed[i];

		//ͨ��ѭ����ÿ����ʦ����ѧ����ֵ
		for (int j = 0; j < 5; j++) {
			tArr[i].stu_arr[j].name = "Student_";
			tArr[i].stu_arr[j].name += nameSeed[j];

			int score = rand() % 61 + 40;  //����40~100�����
			tArr[i].stu_arr[j].score = score;
		}
	}
}

//��ӡ������Ϣ����
void printInfo(Teacher tArr[], int len) {
	for (int i = 0; i < len; i++) {
		std::cout << "��ʦ������" << tArr[i].name << std::endl;
		for (int j = 0; j < 5; j++) {
			std::cout << "\tѧ��������" << tArr[i].stu_arr[j].name
				<< " ѧ������" << tArr[i].stu_arr[j].score << std::endl;
		}
	}
}

void CompositeStruct() {
	//���������
	srand((unsigned int)time(0));

	//����3����ʦ������
	Teacher t_arr[3];
	int len = sizeof(t_arr) / sizeof(t_arr[0]);

	//ͨ��������3����ʦ����Ϣ��ֵ
	allocateSpace(t_arr, len);

	//ͨ���������������Ϣ
	printInfo(t_arr, len);
}

int main03() {
	CompositeStruct();

	system("pause");
	return 0;
}