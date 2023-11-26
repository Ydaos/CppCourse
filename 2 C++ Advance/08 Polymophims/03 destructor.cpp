#include<iostream>

namespace my_src3 {

	/*
	* �����ָ����������ʱ�򣬲�����������������������������ж������ݣ�������ڴ�й©
	* ����������������ָ��������ʱ���������������������Ӷ������������ͷŲ��ɾ�������
	* ��������������Ϊ���û����ɳ����࣬�����ڻ��ຬ�д��麯�������
	* 
	* �������﷨��virtual ~����(){}
	* ���������﷨��virtual ~����() = 0;
	* 
	* ע�����
	* ����������Ҫ������Ҳ��Ҫʵ��
	* ���˴�������֮�󣬸������ڳ������޷�ʵ����
	*/

	class Animal {
	public:
		Animal() {
			std::cout << "Animal �Ĺ��캯������\n";
		}

		//����������������ָ���ͷ��������ʱ���ɾ�������
		/*virtual ~Animal() {
			std::cout << "Animal ����������������\n";
		}*/

		// ������������Ҫ������Ҳ��Ҫʵ��
		// ���˴�������֮�󣬸���Ҳ���ڳ����࣬�޷�ʵ����
		virtual ~Animal() = 0;

		virtual void Speak() = 0;
	};

	Animal::~Animal() {
		std::cout << "Animal �Ĵ���������������\n";
	}

	class Cat :public Animal {
	public:
		Cat(std::string name) {
			std::cout << "Cat �Ĺ��캯������\n";
			m_name = new std::string(name);
		}

		~Cat() {
			if (m_name != NULL) {
				std::cout << "Cat ��������������\n";
				delete m_name;
			}
		}

		void Speak() {
			std::cout << *m_name << "Сè��˵��\n";
		}

		std::string* m_name;
	};

	void Func() {
		Animal* a = new Cat("Tom");
		a->Speak();
		delete a;
	}

	/*
	* �ܽ᣺
	* �������ʹ����������ԣ����Խ������ָ���ͷ�������󣻶���Ҫ����ĺ���ʵ��
	* 
	* ��������Ǵ������� �������ڳ����࣬�޷�ʵ��������
	* ��������޶������ݣ���û��Ҫ�����������������ͷ���������
	*/
}

int main03() {
	my_src3::Func();

	system("pause");
	return 0;
}