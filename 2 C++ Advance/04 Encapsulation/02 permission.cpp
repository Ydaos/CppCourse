#include<iostream>

/*
* ����Ȩ��
* public    ����Ȩ��:��Ա������Կ��Է���
* protected ����Ȩ��:��Ա���ڿ��Է��ʣ����ⲻ���Է��ʣ�������Է��ʸ���ı�������
* private   ˽��Ȩ��:��Ա���ڿ��Է��ʣ����ⲻ���Է��ʣ����಻���Է��ʸ����˽������
* 
* ��C++�У�struct��classΨһ��������Ĭ�Ϸ���Ȩ�޲�ͬ
* 
* ��Ա��������Ϊ˽���ŵ㣺
* �����г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
* ����дȨ�ޣ����ǿ��Լ�����ݵ���Ч��
*/

class Person {
	int m_test;
public://����Ȩ��
	std::string m_name;

protected: //����Ȩ��
	std::string m_car;

private: //˽��Ȩ��
	int m_Password;

public:
	void func() {
		m_name = "����";
		m_car = "������";
		m_Password = 123456;
	}
};

struct Persion2 {
	int m_test;
};

//�������
class Persion3 {
private:
	std::string m_name;
	int m_age = 0;
	std::string m_lover;

public:
	//��������
	void setName(std::string name) {
		m_name = name;
	}
	//��ȡ����
	std::string getName() {
		return m_name;
	}

	//��������
	void setAge(int age) {
		if (age < 1 || age>100) {
			std::cout << "����̫���ˣ�" << std::endl;
			return;
		}
		m_age = age;
	}
	//��ȡ����
	int getAge() {
		return m_age;
	}

	//��������
	void setLover(std::string name) {
		m_lover = name;
	}
};

void Permission() {
	//ʵ�����������
	Person p1;
	p1.m_name = "lisa";
	//p1.m_car = "����"; //error�� ����Ȩ��������ʲ���
	//p1.m_Password = 123; //error�� ˽��Ȩ��������ʲ���
	//p1.m_test = 0; //���ʲ�����Ĭ��Ϊ˽�У����ⲻ�ɷ���

	Persion2 p2;
	p2.m_test = 10; //���Է��ʣ�struct��ԱȨ��Ĭ��Ϊpublic


	/*This is the first demo of permission.*/
	//1�����ƶ�дȨ��
	Persion3 p3;
	p3.setName("����"); //�������ɶ���д
	std::cout << "����Ϊ��" << p3.getName() << std::endl;

	p3.setLover("lisa"); //���� ֻд�����ɶ�

	//2�����������Ч��
	p3.setAge(1000); //����̫�� ��������ʧ��
	std::cout << "����Ϊ��" << p3.getAge() << std::endl; //���� �ɶ���д����Χ1~100

	p3.setAge(10);
	std::cout << "����Ϊ��" << p3.getAge() << std::endl;
}

int main02() {
	Permission();

	system("pause");
	return 0;
}