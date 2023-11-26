#include <iostream>
#include <algorithm>
#include <vector>

/*
* STL�����㷨��
* 1���㷨��Ҫ��ͷ�ļ�<algorithm> <numeric> <functional>���
* 2��<algorithm>������STLͷ�ļ�����һ������Χ�漰���Ƚϡ��������������������ơ��޸ĵȵ�
* 3��<numeric>�����С��ֻ��������������������м���ѧ�����ģ�庯��
* 4��<functional>������һЩģ���࣬����������������
* 
* STL_�����㷨��
* for_each;  // ��������
* transform; // ��������
*/

namespace space_tra {

	// ��ͨ����
	void myPrint(int val) {
		std::cout << val << " ";
	}

	// �º���
	class MyPrint {
	public:
		void operator()(int val) {
			std::cout << val << " ";
		}
	};

	class MyTransform {
	public:
		int operator()(int val) {
			val += 100; //��������߼��������������
			return val;
		}
	};


	/*
	* for_each ��������
	* ����ԭ�ͣ�
	* for_each(iterator beg, iterator end, _func);
	* for_each��ʵ�ʿ���������õı����㷨��������������
	*/
	void ForEach() {
		std::vector<int> v;
		for (int i = 0; i < 10; i++) {
			v.push_back(i);
		}

		// ��ͨ����
		for_each(v.begin(), v.end(), myPrint);
		std::cout << std::endl;

		// �º���
		for_each(v.begin(), v.end(), MyPrint());
		std::cout << std::endl;
	}


	/*
	* transform ���˺���
	* ����ԭ�ͣ�
	* transform(iterator beg_1, iterator end_1, iterator beg_2, _func);
	* 
	* _func Ϊ�������߷º��������Զ԰��˵�ֵ���в���
	* transform ����Ŀ������������ǰ���ٿռ䣬�����޷���������
	*/
	void Transform() {
		std::vector<int> v;
		for (int i = 0; i < 10; i++) {
			v.push_back(i);
		}

		std::vector<int> v2;
		v2.resize(v.size()); //Ŀ������������ǰ���ٿռ������հ�������
		transform(v.begin(), v.end(), v2.begin(), MyTransform());

		for_each(v2.begin(), v2.end(), MyPrint());
		std::cout << std::endl;
	}

}

int main01() {
	space_tra::ForEach();

	std::cout << "--------------------\n";
	space_tra::Transform();

	system("pause");
	return 0;
}