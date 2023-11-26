#include<iostream>

namespace my_src4 {

	/*
	* ��ģ����̳�
	* 1��������̳еĸ�����һ����ģ���ǣ�������������ʱ��Ҫָ���������е�T������
	* 2�������ָ�����������޷�����������ڴ�
	* 3����������ָ��������T�е����ͣ�����Ҳ���Ϊ��ģ��s
	*/

	template <class T>
	class Base {
	public:
		T obj;
	};

	//class Son :public Base {};
	// Error!!! ����Ҫָ�������T���ͣ����ܼ̳и����࣬�����޷�֪��Ҫ������ڴ�ռ�
	
	class Son :public Base<int> {};

	//��������ָ��������T�е����ͣ�����Ҳ���Ϊ��ģ��
	template<class T1, class T2>
	class Son2 :public Base<T1> {
	public:
		void printSon2() {
			std::cout << "T1��" << typeid(T1).name() << std::endl;
			std::cout << "T2��" << typeid(T2).name() << std::endl;
		}

		T2 obj;
	};

	void Func() {
		Son s1;

		Son2<int, char> s;
		s.printSon2();
	}
}

// �ܽ᣺�����������ģ�壬������Ҫָ���������е�T����������

int main04() {
	my_src4::Func();

	system("pause");
	return 0;
}