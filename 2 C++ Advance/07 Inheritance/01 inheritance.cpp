#include<iostream>

/*
* C++��������������ԣ���װ���̳кͶ�̬
* 
* �̳У������ظ�����
* �﷨��class ���ࣨ�����ࣩ : �̳з�ʽ ���ࣨ���ࣩ
* eg: class A : public B {}
* 
* �������Ա�������󲿷֣��ӻ���̳й����ĳ�Ա���Լ������ӵĳ�Ա
* �ӻ���̳й����ı����乲�ԣ��������ĳ�Ա�����������
*/

namespace my_src1 {

	//�̳� ʵ��ҳ��
	//����������
	class BasePage {
	public:
		void header() {
			std::cout << "��ҳ�������Ρ���¼��ע��...������ͷ����\n";
		}
		void footer() {
			std::cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���\n";
		}
		void left() {
			std::cout << "Java��Python��C++��...�����������б�\n";
		}
	};

	//Javaҳ��
	class Java :public BasePage {
	public:
		void contene() {
			std::cout << "Javaѧ����Ƶ\n";
		}
	};

	//Pythonҳ��
	class Python :public BasePage {
	public:
		void contene() {
			std::cout << "Pythonѧ����Ƶ\n";;
		}
	};

	//C++ҳ��
	class CPP :public BasePage {
	public:
		void contene() {
			std::cout << "C++ѧ����Ƶ\n";
		}
	};

	void Beginning() {
		std::cout << "\nJava������Ƶҳ�����£�\n";
		Java ja;
		ja.header();
		ja.footer();
		ja.left();
		ja.contene();

		std::cout << "\nPython������Ƶҳ�����£�\n";
		Python py;
		py.header();
		py.footer();
		py.left();
		py.contene();

		std::cout << "\nJava������Ƶҳ�����£�\n";
		CPP cpp;
		cpp.header();
		cpp.footer();
		cpp.left();
		cpp.contene();
	}
}


int main01() {
	my_src1::Beginning();

	system("pause");
	return 0;
}