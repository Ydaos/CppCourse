#include<iostream>

/*
* C++����������������ԣ���װ���̳С���̬
*
* ��װ���壺
* �����Ժ���Ϊ��Ϊһ�����壬��������;
* �����Ժ���Ϊ����Ȩ�޿���
* 
* ���е����Ժ���Ϊ������ͳһ��Ϊ����Ա
* �������Ϊ ��Ա���ԡ���Ա����
* ��Ϊ���Ϊ ��Ա��������Ա����
* 
* ע�⣺
* class�����ڵ�һ������˵����֮ǰ�ĳ�Ա��private��
* struct�����ڵ�һ������˵����֮ǰ�ĳ�Ա��public�ģ��������߷�װΨһ����
*/

//���һ��ѧ���࣬������������ѧ��
//���Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��
class Student {

	//����
	std::string m_name; //Ȩ��Ĭ��private
	std::string m_ID;

public:
	//��Ϊ
	void setName(std::string name) {
		m_name = name;
	}

	void setID(std::string ID) {
		m_ID = ID;
	}

	void showMessage() {
		std::cout << "ѧ����������" << m_name << " " << "ѧ����ѧ�ţ�" << m_ID << std::endl;
	}
};

void Beginning() {
	//ʵ���� ��ͨ��һ���� ����һ������Ĺ��̣�
	Student s;
	//����������Խ��и�ֵ
	s.setName("����");
	s.setID("001");
	s.showMessage();
}

int main01() {
	Beginning();

	system("pause");
	return 0;
}