#include <iostream>

namespace my_src2 {

	/*
	* ��ģ���Ա��������ʱ��
	* 1����ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
	* 2����ģ���еĳ�Ա�����ڵ���ʱ���ܴ���
	*/

	class Person1 {
	public:
		void showPerson1() {
			std::cout << "Person1 show" << std::endl;
		}
	};

	class Person2 {
	public:
		void showPerson2() {
			std::cout << "Person2 show" << std::endl;
		}
	};

	template<class T>
	class MyClass {
	public:
		T obj;

		// ��ģ���еĳ�Ա����
		void func1() {
			obj.showPerson1();
		}

		void func2() {
			obj.showPerson2();
		}
		// ��Ա�����󴴽�����Ϊ��֪��T���ͣ����޷�ȷ��T�ĳ�Ա��������
	};

	void Func() {
		MyClass<Person1> mc;
		mc.func1();
		//mc.func2(); Error��������ȷ����T������ΪPerson1������ֻ�ܵ���func1(),����func()�ᱨ��
	}
	
}

int main02() {
	my_src2::Func();

	system("pause");
	return 0;
}