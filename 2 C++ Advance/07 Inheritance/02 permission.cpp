#include<iostream>

/*
* �̳з�ʽ�������̳С������̳С�˽�м̳�
* 
* ע�⣺
* ���������ж��󣨷Ǿ�̬��Ա���ԣ����ᱻ����̳���ȥ
* ������˽�г�Ա�����Ǳ������������ˣ���˷��ʲ���
*/

/*
* ͨ�������߹��߲鿴����ģ��
* 
* ���裺
* 1�����ÿ�����Ա������ʾ���߲鿴����ģ��
* 2����ת�������.cpp�ļ����ڵĴ���
* 3��cdָ���.cpp�ļ�����Ŀ¼
* 4������鿴���cl /d1 reportSingleClassLayout���� �ļ���
* 
* ������
* �򿪿����߹��ߣ�Developer Command Prompt for VS2019��
* C: //��תC����
* cd C:\Users\King\Desktop\C++\2 C++ advance\07 inheritance\07 inheritance
* cl /d1 reportSingleClassLayoutSon1 "02 permission.cpp"
*/

namespace my_src2 {

	class Base {
	public:
		int m_A;
	protected:
		int m_B;
	private:
		int m_C;
	};

	// 1�������̳�
	class Son1 :public Base {
	public:
		void func() {
			m_A = 10;   //�����й���Ȩ�޳�Ա������������Ȼ�ǹ���Ȩ��
			m_B = 10;   //�����б���Ȩ�޳�Ա������������Ȼ�Ǳ���Ȩ��
			//m_C = 10; //������˽�г�Ա��������ʲ���
		}
	};

	// 2�������̳�
	class Son2 :protected Base {
	public:
		void func() {
			m_A = 10;   //�����й���Ȩ�޳�Ա���������б�Ϊ����Ȩ��
			m_B = 10;   //�����б���Ȩ�޳�Ա������������Ȼ�Ǳ���Ȩ��
			//m_C = 10; //������˽�г�Ա��������ʲ���
		}
	};

	// 3��˽�м̳�
	class Son3 :private Base {
		void func() {
			m_A = 10;   //�����й���Ȩ�޳�Ա���������б�Ϊ˽��Ȩ��
			m_B = 10;   //�����б���Ȩ�޳�Ա���������б�Ϊ˽��Ȩ��
			//m_C = 10; //������˽�г�Ա��������ʲ���
		}
	};

	class GrandSon3 :public Son3 {
	public:
		void func() {
			//m_A = 200; //�����޷����ʣ�˵��m_A�Ѿ���˽��Ȩ�޳�Ա
		}
	};

	void Permission() {
		// 1�������̳�
		Son1 s1;
		s1.m_A = 100;   //����Ȩ�ޣ�����ɷ���
		//s1.m_B = 200; //����Ȩ�ޣ����ⲻ�ܷ���

		// 2�������̳�
		Son2 s2;
		//s2.m_A = 100; //����Ȩ�ޣ����ⲻ�ܷ���
		//s2.m_B = 200; //����Ȩ�ޣ����ⲻ�ܷ���

		// 3��˽�м̳�
		// �����Ա��������˽��Ȩ�ޣ�����������޷����ʸ�����κγ�Ա

		// 4���̳�ģ��
		std::cout << "sizeof of Son1��" << sizeof(Son1) << std::endl;

		//���Ϊ12��˵��3��int����������˽��Ȩ�޵� Base::m_C��ȫ��������̳�
	}
}

int main02() {
	my_src2::Permission();

	system("pause");
	return 0;
}