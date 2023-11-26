#include <iostream>

namespace my_src1 {

/*
* ��̬��
* 1����̬��̬���������غ�������������ھ�̬��̬�����ú�����
* 2����̬��̬����������麯��ʵ������ʱ��̬
*
* ��������
* 1����̬��̬�ĺ�����ַ��� - ����׶�ȷ��������ַ
* 2����̬��̬�ĺ�����ַ��� - ���н׶�ȷ��������ַ
*/

	//������
	class Animal {
	public:
		//void speak() { //��ַ���
		//	cout << "������˵��" << endl;
		//}
		virtual void speak() { //�麯�����õ�ַ���
			std::cout << "������˵��\n";
		}
	};

	//è��
	class Cat :public Animal {
	public:
		//��д�����麯�� ��������ֵ���ͺͲ����б���ȫ��ͬ
		void speak() {
			std::cout << "Сè��˵��\n";
		}
	};

	//����
	class Dog :public Animal {
	public:
		void speak() {
			std::cout << "С����˵��\n";
		}
	};

	//ִ��˵���ĺ���
	//��ַ��� �ڱ���׶�ȷ��������ַ
	//ִ����Ҫè˵����������ַ��Ҫ��󶨣������н׶ΰ�
	void doSpeak(Animal& animal) { //Animal& animal = cat
		animal.speak();
	}

	void Func() {
		Cat cat;
		doSpeak(cat);

		Dog dog;
		doSpeak(dog);
	}

	/*
	* �ܽ᣺
	* ��̬��̬�����������м̳й�ϵ��������д�����麯��
	* 
	* ��̬��̬ʹ�������������ָ��������ã�ִ���������
	* 
	* ��̬��̬�ײ�ԭ��
	* �����麯����ַ��󶨣������Ա�����һ���麯��ָ��ָ���麯����
	* �����̳и����麯��ָ�룻
	* ������д�麯����ʹ�麯��ָ��ָ����д��ĺ���������ָ�����麯����
	*/
}

namespace prac_space {

	//�ֱ�������ͨд���Ͷ�̬���������ʵ��������������������ļ�������
	
	// 1����ͨд��
	class Calculator {
	public:
		int getResult(std::string oper) {
			if (oper == "+") {
				return m_num1 + m_num2;
			}
			else if (oper == "-") {
				return m_num1 - m_num2;
			}
			else if (oper == "*") {
				return m_num1 * m_num2;
			}
			//�������չ�µĹ��ܣ������������������޸�Դ��
			//����ʵ�Ŀ����У��ᳫ����ԭ�򣺶���չ���п��ţ����޸Ľ��йر�
		}

		int m_num1;
		int m_num2;
	};

	void case01() {
		//��������������
		Calculator cal;
		cal.m_num1 = 10;
		cal.m_num2 = 2;

		std::cout << cal.m_num1 << " + " << cal.m_num2 << " = " << cal.getResult("+") << std::endl;
		std::cout << cal.m_num1 << " - " << cal.m_num2 << " = " << cal.getResult("-") << std::endl;
		std::cout << cal.m_num1 << " * " << cal.m_num2 << " = " << cal.getResult("*") << std::endl;
	}

	// 2�����ö�̬ʵ�ּ�������
	// ����������������
	class AbstractCalculator {
	public:
		virtual int getResult() {
			return 0;
		}

		int m_num1 = 0;
		int m_num2 = 0;
	};

	//�ӷ���������
	class AddCalculator :public AbstractCalculator {
	public:
		int getResult() {
			return m_num1 + m_num2;
		}
	};

	//������������
	class SubCalculator :public AbstractCalculator {
	public:
		int getResult() {
			return m_num1 - m_num2;
		}
	};

	//�˷���������
	class MulCalculator :public AbstractCalculator {
	public:
		int getResult() {
			return m_num1 * m_num2;
		}
	};

	void case02() {
		// ��̬ʹ������
		// ����ָ�������ָ���������

		//�ӷ�����
		AbstractCalculator* ac = new AddCalculator;
		ac->m_num1 = 10;
		ac->m_num2 = 2;
		std::cout << ac->m_num1 << " + " << ac->m_num2 << " = " << ac->getResult() << std::endl;
		//������������ǵ�����
		delete ac;

		//��������
		ac = new SubCalculator;
		ac->m_num1 = 10;
		ac->m_num2 = 2;
		std::cout << ac->m_num1 << " - " << ac->m_num2 << " = " << ac->getResult() << std::endl;
		delete ac;

		//�˷����� (���÷�)
		MulCalculator mul;
		AbstractCalculator& abc = mul;
		abc.m_num1 = 10;
		abc.m_num2 = 2;
		std::cout << abc.m_num1 << " * " << abc.m_num2 << " = " << abc.getResult() << std::endl;
	}

	/*
	* ��̬�ô���
	* 1����֯�ṹ����
	* 2���ɶ���ǿ
	* 3�����������չ��ά��
	* eg�������¹���ֻ��Ҫ׷���¹����࣬����Ҫ�޸�Դ���룻ά������ֱ�Ӷ�λ����Ӧ�Ĺ����࣬�׶���ǿ
	*/
}

int main01() {
	my_src1::Func();

	std::cout << "\nThere are two case to compare the benefits of using polymorphims or not.\n";
	prac_space::case01();

	std::cout << std::endl;
	prac_space::case02();

	system("pause");
	return 0;
}