#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

/*
* STL_�����㷨 
* sort;           // ����
* random_shuffle; // ϴ��
* merge;          // �ϲ�
* reverse;        // ��ת
*/

namespace space_sort {

	class MyPrint {
	public:
		void operator()(int val) {
			std::cout << val << " ";
		}
	};

	/*
	* sort ��������Ԫ�ؽ�������
	* ����ԭ�ͣ�
	* sort(iterator beg, iterator end, _Pred);
	* 
	* sort�㷨�ǳ����ã�Ĭ����������ڽ��Ĺ�ϵ�º���greater<int>()ʵ�ֽ���
	*/
	void MySort() {
		std::vector<int> v;
		v.push_back(10);
		v.push_back(40);
		v.push_back(30);
		v.push_back(20);
		v.push_back(50);

		// Ĭ������
		sort(v.begin(), v.end());
		for_each(v.begin(), v.end(), MyPrint());
		std::cout << std::endl;

		// ���÷º�����Ϊ����
		sort(v.begin(), v.end(), std::greater<int>());
		for_each(v.begin(), v.end(), MyPrint());
		std::cout << std::endl;
	}


	/*
	* random_shuffle ָ����Χ�ڵ�Ԫ�������������
	* ����ԭ�ͣ�
	* random_shuffle(iterator beg, iterator end);
	* 
	* random_shuffle�㷨�ǳ�ʵ�ã�Ӧ���ڳ�ǩ������
	*/
	void MyRandom_Shuffle() {
		srand((unsigned int)time(NULL)); // ���������

		std::vector<int> v;
		for (int i = 0; i < 10; i++) {
			v.push_back(i);
		}

		// ����ϴ���㷨����˳��
		random_shuffle(v.begin(), v.end());
		for_each(v.begin(), v.end(), MyPrint());
		std::cout << std::endl;
	}


	/*
	* merge ��������Ԫ�غϲ������洢����һ��������
	* ����ԭ�ͣ�
	* merge(iterator beg_1, iterator end_1, iterator beg_2, iterator end_2, iterator dest); 
	* 
	* ע�⣺
	* ��ǰ��Ŀ����������ռ�
	* ������������������ģ������������ͬ��
	*/
	void MyMerge() {
		std::vector<int> v1;
		v1.push_back(20);
		v1.push_back(10);
		v1.push_back(30);
		v1.push_back(40);

		std::vector<int> v2;
		v2.push_back(10);
		v2.push_back(20);
		v2.push_back(15);
		v2.push_back(30);

		// ��ǰ��Ŀ����������ռ�
		std::vector<int> v3;
		v3.resize(v1.size() + v2.size());

		// ����ԭ�������������������������ͬ��������������
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		// �ϲ�ԭ����ѡ�������Ԫ�ص�Ŀ������
		merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
		for_each(v3.begin(), v3.end(), MyPrint());
		std::cout << std::endl;
	}


	/*
	* reverse ��תָ����Χ�ڵ�Ԫ��(10 20 -> 20 10)
	* ����ԭ�ͣ�
	* reverse(iterator beg, iterator end);
	*/
	void MyReverse() {
		std::vector<int> v1;
		v1.push_back(10);
		v1.push_back(30);
		v1.push_back(20);
		v1.push_back(40);

		std::cout << "��תǰ\n";
		for_each(v1.begin(), v1.end(), MyPrint());

		std::cout << "\n��ת��\n";
		reverse(v1.begin(), v1.end());
		for_each(v1.begin(), v1.end(), MyPrint());
		std::cout << std::endl;
	}

}


int main03() {
	space_sort::MySort();

	std::cout << "---------------------------\n";
	space_sort::MyRandom_Shuffle();

	std::cout << "---------------------------\n";
	space_sort::MyMerge();

	std::cout << "---------------------------\n";
	space_sort::MyReverse();

	system("pause");
	return 0;
}