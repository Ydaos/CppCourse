#include<iostream>

namespace my_src2 {

	/*
	* ��̬�����е��麯��ʵ���Ǻ�������ģ���Ҫ������������дʵ�ֵ����ݣ���˸����麯��ͨ����Ϊ���麯��
	* 
	* ���麯���﷨��virtual ���غ���ֵ���� ������(�����б�) = 0
	* �������д��麯���������Ҳ��Ϊ������
	* 
	* �������ص㣺
	* 1���޷�ʵ��������
	* 2�����������д�������еĴ��麯���������޷�ʵ��������
	*/

	// ���麯���ͳ�����
	class Base {
	public:
		virtual void func() = 0;
	};

	class Son :public Base {
	};

	class Son2 :public Base {
	public:
		void func() {
			std::cout << "fun ��������\n";
		}
	};

	void Func() {
		//Base b;   Error!!! �޷�ʵ��������
		//Son s;    Error!!! ����û��д�麯����Ҳ���ڳ����࣬����ʵ����

		Base* b = new Son2;
		b->func();
		delete b;

		// �����ã��������ݹ�����ɿ�
		Son2 s2;
		Base& b2 = s2;
		b2.func();
	}

	// ��̬����2���ṩ������Ʒ�ĳ�����࣬�ṩ�����������ȺͲ�Ҷ
	// ��Ʒ�������̣���ˮ - ���� - ���뱭�� - ���븨��

	//�������
	class AbstractDrinking {
	public:
		//��ˮ
		virtual void Boil() = 0;

		//����
		virtual void Brew() = 0;

		//���뱭��
		virtual void Pour() = 0;

		//���븨��
		virtual void addAccessori() = 0;

		//������Ʒ
		void makeDrink() {
			Boil();
			Brew();
			Pour();
			addAccessori();
		}
	};

	//��������
	class Coffee :public AbstractDrinking {
	public:
		//��ˮ
		void Boil() {
			std::cout << "��ũ��ɽȪ" << std::endl;
		}

		//����
		void Brew() {
			std::cout << "���ݿ���" << std::endl;
		}

		//���뱭��
		void Pour() {
			std::cout << "���뿧�ȱ�" << std::endl;
		}

		//���븨��
		void addAccessori() {
			std::cout << "�����ǽ���ţ��" << std::endl;
		}
	};

	//������Ҷ
	class Tea :public AbstractDrinking {
	public:
		//��ˮ
		void Boil() {
			std::cout << "��ũ��ɽȪ" << std::endl;
		}

		//����
		void Brew() {
			std::cout << "���ݲ�Ҷ" << std::endl;
		}

		//���뱭��
		void Pour() {
			std::cout << "����豭" << std::endl;
		}

		//���븨��
		void addAccessori() {
			std::cout << "������轣�����" << std::endl;
		}
	};

	//��������
	void doWork(AbstractDrinking* ad) {
		ad->makeDrink();
		delete ad;
	}

	void Practice() {
		//��������
		doWork(new Coffee);

		std::cout << "------------------------" << std::endl;
		//������轲�
		doWork(new Tea);
	}
}


int main02() {
	my_src2::Func();

	std::cout << "\nThis is a demo of abstract class application.\n";
	my_src2::Practice();

	system("pause");
	return 0;
}