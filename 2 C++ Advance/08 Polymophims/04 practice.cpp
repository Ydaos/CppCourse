#include<iostream>

namespace my_src4 {

	//组装电脑案例

	// 1、抽象零件类
	// 抽象CPU类
	class AbstractCPU {
	public:
		virtual void calculate() = 0;
	};

	// 抽象GPU类
	class AbstractGPU {
	public:
		virtual void display() = 0;
	};

	// 抽象Memory类
	class AbstractMemory {
	public:
		virtual void storage() = 0;
	};

	// 2、具体零件厂商
	// Intel的CPU
	class IntelCPU :public AbstractCPU {
	public:
		void calculate() {
			std::cout << "使用Intel生产的CPU\n";
		}
	};

	//AMD的CPU
	class AMDCPU :public AbstractCPU {
	public:
		void calculate() {
			std::cout << "使用AMD生产的CPU\n";
		}
	};

	//Nvidia的GPU
	class NvidiaGPU :public AbstractGPU {
	public:
		void display() {
			std::cout << "使用英伟达生产的显卡\n";
		}
	};

	//AMD的GPU
	class AMDGPU :public AbstractGPU {
	public:
		void display() {
			std::cout << "使用AMD生产的显卡\n";
		}
	};

	// Kinston的内存条
	class Kinston :public AbstractMemory {
	public:
		void storage() {
			std::cout << "使用金士顿的内存条\n";
		}
	};

	// 芝奇的内存条
	class Skill :public AbstractMemory {
	public:
		void storage() {
			std::cout << "使用皇家戟的内存条\n";
		}
	};

	//电脑类
	class Computer {
	public:
		Computer(AbstractCPU* ac, AbstractGPU* ag, AbstractMemory* am) {
			m_CPU = ac;
			m_GPU = ag;
			m_Memory = am;
		}

		//析构零件
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

		// 组装电脑函数
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