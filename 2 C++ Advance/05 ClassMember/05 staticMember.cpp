#include <iostream>

/*
* ��̬��Ա��(��Ա�����ͳ�Ա����ǰ���Ϲؼ���static)
*
* ��̬��Ա������
* ���ж�����ͬһ������
* �ڱ���׶η����ڴ� ��ȫ������
* ���������������ʼ��
*
* ��̬��Ա������
* ���ж�����ͬһ������
* ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
*/

/*
* ��ĳ�Ա�洢��
* ��ĳ�Ա�����ͳ�Ա�����Ƿֿ��洢�ģ������洢�ڴ������������洢���ڴ���
* ��̬��Ա�����洢��ȫ��������
* �Ǿ�̬��Ա�����洢��ջ��or������ֻ�зǾ�̬��Ա������������Ķ���
* 
* ע�⣺
* �ն���ռ���ڴ�ռ䣺1
* C++���������ÿ������Ҳ����һ���ֽڵĿռ䣬Ϊ�����ֿն���ռ�ڴ��λ��
* ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
*/

class sPerson {
public:
	//��̬��Ա�����������������������ʼ��
	static int m_A;

	//��̬��Ա����Ҳ���з���Ȩ��
private:
	static int m_B;

public:
	int m_C;

	//��̬��Ա����
	static void func() {
		m_A = 300;
		//m_C = 100; ���ܷ��ʷǾ�̬��Ա����,�������޷���������һ�������m_C
		std::cout << "static func() �ĵ���\n";
	}
private:
	static void func2() {
		std::cout << "static func2() �ĵ���\n";
	}
};

int sPerson::m_A = 100; //�����ʼ��
int sPerson::m_B = 200;

//��̬��Ա�������ַ��ʷ�ʽ
void StaticVariate() {
	//1��ͨ��������з���
	sPerson p;
	std::cout << p.m_A << std::endl;

	//2��ͨ�������������
	std::cout << sPerson::m_A << std::endl;
	//std::cout << Person::m_B << std::endl; ˽�о�̬��Ա�������ɷ���

	//��̬��Ա����������ĳ���������ж��󶼹���һ������
	sPerson p2;
	p2.m_A = 200;
	std::cout << p.m_A << std::endl;
}

void test() {
	static int num = 0; //��̬�ֲ�����ֻ��ʼ��һ��
	num++;
	std::cout << num << " "; //��ӡ���Ϊ 1~10
}

//��̬��Ա�������ַ��ʷ�ʽ
void StaticFunc() {
	//1��ͨ���������
	sPerson p;
	p.func();
	//p.func2(); ������ʲ���˽�еľ�̬��Ա����

	//2��ͨ����������
	sPerson::func();
	std::cout << sPerson::m_A << std::endl;
}

void StaticMember() {
	std::cout << "This is a demo of static member variate.\n";
	StaticVariate();
	for (size_t i = 0; i < 10; i++) test();
	std::cout << std::endl;

	std::cout << "\nThis is a demo of static member function.\n";
	StaticFunc();

	std::cout << "\nThis is a demo of size of class member.\n";
	sPerson p;
	std::cout << "size of class:" << sizeof(sPerson) << std::endl;
	//���ۣ�ֻ�зǾ�̬��Ա������������Ķ�����
}

int main05() {
	StaticMember();

	system("pause");
	return 0;
}