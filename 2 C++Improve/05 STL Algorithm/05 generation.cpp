#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

// STL_���������㷨 С���㷨��ʹ��ǰҪ����ͷ�ļ�<numeric>
namespace space_generate {

	class MyPrint {
	public:
		void operator()(int val) {
			std::cout << val << " ";
		}
	};

	/*
	* accumulate ��������Ԫ���ۼ��ܺ�
	* ����ԭ�ͣ�
	* int accumulate(iterator beg, iterator end, value);
	* valueΪ��ʼֵ��һ����Ϊ0
	*/
	void MyAccumulate() {
		std::vector<int> v;
		v.push_back(10);
		v.push_back(40);
		v.push_back(30);
		v.push_back(20);
		v.push_back(50);

		// ����3 ��ʼ�ۼ�ֵ
		int total = accumulate(v.begin(), v.end(), 0);
		std::cout << total << std::endl;
	}


	/*
	* fill ���������ָ����Ԫ��
	* ����ԭ�ͣ�
	* fill(iterator beg, iterator end, value);
	*/
	void MyFill() {
		std::vector<int> v;
		v.resize(10);
		fill(v.begin(), v.end(), 10);

		for_each(v.begin(), v.end(), MyPrint());
		std::cout << std::endl;
	}
}


int main05() {
	space_generate::MyAccumulate();

	std::cout << "---------------------------\n";
	space_generate::MyFill();

	system("pause");
	return 0;
}