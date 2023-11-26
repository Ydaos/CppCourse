#include <iostream>

/*
* �ṹ�������û��Զ�����������ͣ������û��洢��ͬ����������
* �﷨��struct �ṹ����{ �ṹ���Ա�б� };
*
* �ṹ��ĳ�Ա��������һ���ṹ��
*/
struct Student {
	// ����
	std::string name;
	// ����
	int age = 0;
	//����
	int score = 0;
}s3;//˳�㴴��һ���ṹ������������飡������

//1�������ṹ�����
void StructDefine() {
	
	//1.1 ͨ�� . ���ʽṹ������еĳ�Ա����ֵ
	struct Student s1;
	s1.name = "����";
	s1.age = 18;
	s1.score = 100;
	std::cout << "������" << s1.name << " ���䣺" << s1.age << " ������" << s1.score << std::endl;

	//1.2 struct Student s2 = { ... }
	Student s2 = { "����",19,99 };//struct �ڴ�������ʱ��ؼ��ֿ���ʡ��
	std::cout << "������" << s2.name << " ���䣺" << s2.age << " ������" << s2.score << std::endl;

	//2.3 �ڶ���ṹ��ʱ˳�㴴���ṹ�����
	s3.name = "����";
	s3.age = 20;
	s3.score = 80;
	std::cout << "������" << s3.name << " ���䣺" << s3.age << " ������" << s3.score << std::endl;
	
	//�Ƽ���1 2��
	//����ѽṹ��д��ͷ�ļ�ͳһ������ͷ�ļ������Դ�ļ�����ʱ��������д���ᵼ�½ṹ������ظ����壡����
}

//2�������ṹ������
void StructArray() {
	//�����ṹ������
	Student arr[3] = { { "����",18,100 },{ "����",19,90 },{ "����",20,80 } };

	//���ṹ�������е�Ԫ�ظ�ֵ
	arr[2].name = "����";
	arr[2].age = 21;
	arr[2].score = 60;

	//�����ṹ������
	for (int i = 0; i < 3; i++) {
		std::cout << "������" << arr[i].name
			<< " ���䣺" << arr[i].age
			<< " �ɼ���" << arr[i].score << std::endl;
	}
}

//3��ͨ���ṹ��ָ����ʽṹ���ڵĳ�Ա
void StructPointer() {
	//����ѧ���Ľṹ�����
	Student s = { "����",18,100 };

	//ͨ��ָ��ָ��ṹ�����
	Student* p = &s;

	//ͨ��ָ����ʽṹ������е�����
	std::cout << "����: " << p->name << " ����: " << p->age << " ����: " << p->score << std::endl;
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