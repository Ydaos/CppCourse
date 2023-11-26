#include <iostream>
#include <algorithm>
#include <vector>

/*
* STL_�����㷨
* copy;       //������ָ����ΧԪ�ؿ�������һ��������
* replace;    //�������ھ�Ԫ���滻����Ԫ��
* replace_if; //����������������������Ԫ���滻����Ԫ��
* swap;       //��������������Ԫ��
*/

namespace space_copy {

	class MyPrint {
	public:
		void operator()(int val) {
			std::cout << val << " ";
		}
	};

	class MyGreater {
	public:
		bool operator()(int val) {
			// �滻����20��ֵ
			return val > 20;
		}
	};

	/*
	* copy ������ָ����ΧԪ�ؿ�������һ��������
	* ����ԭ�ͣ�
	* copy(iterator beg, iterator end, iterator dest); 
	*
	* �������������ȿ��ٿռ������տ�������
	* ʵ�ʿ�����copy���������ã�ѭ����ֵ�򿽱����캯��������
	*/
	void MyCopy() {
		std::vector<int> v;
		v.push_back(10);
		v.push_back(40);
		v.push_back(30);
		v.push_back(20);
		v.push_back(50);

		// �������������ȿ��ٿռ������տ�������
		std::vector<int> v2;
		v2.resize(v.size());

		copy(v.begin(), v.end(), v2.begin());
		for_each(v2.begin(), v2.end(), MyPrint());
		std::cout << std::endl;
	}


	/*
	* replace �������ھ�Ԫ���滻����Ԫ��
	* ����ԭ�ͣ�
	* replace(iterator beg, iterator end, oldValue, newValue);
	* 
	* ע�⣺replace������������оɵ�Ԫ���滻����Ԫ��
	*/
	void MyReplace() {
		std::vector<int> v;
		v.push_back(10);
		v.push_back(40);
		v.push_back(30);
		v.push_back(20);
		v.push_back(10);

		std::cout << "�滻ǰ\n";
		for_each(v.begin(), v.end(), MyPrint());
		std::cout << std::endl;

		// ������10��ֵ�滻��100
		std::cout << "�滻��\n";
		replace(v.begin(), v.end(), 10, 100);
		for_each(v.begin(), v.end(), MyPrint());
		std::cout << std::endl;
	}


	/*
	* replace_if �滻��������������������Ԫ��
	* ����ԭ�ͣ�
	* replace_if(iterator beg1, iterator end1, _Pred, newValue);
	* replace_if �������÷º������ɸѡ�����Ԫ�أ��ٽ����滻
	*/
	void MyReplace_IF() {
		std::vector<int> v1;
		v1.push_back(10);
		v1.push_back(30);
		v1.push_back(30);
		v1.push_back(20);
		v1.push_back(50);
		v1.push_back(40);

		std::cout << "�滻ǰ\n";
		for_each(v1.begin(), v1.end(), MyPrint());
		std::cout << std::endl;

		// ������20��ֵ�滻��200
		std::cout << "�滻��\n";
		replace_if(v1.begin(), v1.end(), MyGreater(), 200);
		for_each(v1.begin(), v1.end(), MyPrint());
		std::cout << std::endl;
	}


	/*
	* swap ��������������Ԫ��
	* ����ԭ�ͣ�
	* swap(container c1, container c2);
	* 
	* ע�⣺swap ��������ʱ��ע��������������ͬ������
	*/
	void MySwap() {
		std::vector<int> v1;
		std::vector<int> v2;

		for (int i = 0; i < 10; i++) {
			v1.push_back(i);
			v2.push_back(i * 100);
		}

		std::cout << "����ǰ\n";
		for_each(v1.begin(), v1.end(), MyPrint());
		std::cout << std::endl;
		for_each(v2.begin(), v2.end(), MyPrint());
		std::cout << std::endl;

		std::cout << "������\n";
		swap(v1, v2);
		for_each(v1.begin(), v1.end(), MyPrint());
		std::cout << std::endl;
		for_each(v2.begin(), v2.end(), MyPrint());
		std::cout << std::endl;
	}

}


int main04() {
	space_copy::MyCopy();

	std::cout << "---------------------------\n";
	space_copy::MyReplace();

	std::cout << "---------------------------\n";
	space_copy::MyReplace_IF();

	std::cout << "---------------------------\n";
	space_copy::MySwap();

	system("pause");
	return 0;
}