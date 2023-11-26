#include<iostream>

namespace my_src4 {

	//��װ���԰���

	// 1�����������
	// ����CPU��
	class AbstractCPU {
	public:
		virtual void calculate() = 0;
	};

	// ����GPU��
	class AbstractGPU {
	public:
		virtual void display() = 0;
	};

	// ����Memory��
	class AbstractMemory {
	public:
		virtual void storage() = 0;
	};

	// 2�������������
	// Intel��CPU
	class IntelCPU :public AbstractCPU {
	public:
		void calculate() {
			std::cout << "ʹ��Intel������CPU\n";
		}
	};

	//AMD��CPU
	class AMDCPU :public AbstractCPU {
	public:
		void calculate() {
			std::cout << "ʹ��AMD������CPU\n";
		}
	};

	//Nvidia��GPU
	class NvidiaGPU :public AbstractGPU {
	public:
		void display() {
			std::cout << "ʹ��Ӣΰ���������Կ�\n";
		}
	};

	//AMD��GPU
	class AMDGPU :public AbstractGPU {
	public:
		void display() {
			std::cout << "ʹ��AMD�������Կ�\n";
		}
	};

	// Kinston���ڴ���
	class Kinston :public AbstractMemory {
	public:
		void storage() {
			std::cout << "ʹ�ý�ʿ�ٵ��ڴ���\n";
		}
	};

	// ֥����ڴ���
	class Skill :public AbstractMemory {
	public:
		void storage() {
			std::cout << "ʹ�ûʼ�ꪵ��ڴ���\n";
		}
	};

	//������
	class Computer {
	public:
		Computer(AbstractCPU* ac, AbstractGPU* ag, AbstractMemory* am) {
			m_CPU = ac;
			m_GPU = ag;
			m_Memory = am;
		}

		//�������
		~Computer() {
			if (m_CPU != NULL) {
				delete m_CPU;
				m_CPU = NULL;
			}
			if (m_GPU != NULL) {
				delete m_GPU;
				m_GPU = NULL;
			}
			if (m_Memory != NULL) {
				delete m_Memory;
				m_Memory = NULL;
			}
			std::cout << "delete computer\n";
		}

		// ��װ���Ժ���
		void doWork() {
			m_CPU->calculate();
			m_GPU->display();
			m_Memory->storage();
		}

		AbstractCPU* m_CPU;
		AbstractGPU* m_GPU;
		AbstractMemory* m_Memory;
	};

	void Func() {
		Computer c1(new AMDCPU, new AMDGPU, new Kinston);
		c1.doWork();
		std::cout << "------------------------\n";

		Computer c2(new AMDCPU, new NvidiaGPU, new Skill);
		c2.doWork();
		std::cout << "------------------------\n";

		Computer c3(new IntelCPU, new NvidiaGPU, new Skill);
		c3.doWork();
		std::cout << "------------------------\n";
	}
}

int main() {
	my_src4::Func();

	system("pause");
	return 0;
}