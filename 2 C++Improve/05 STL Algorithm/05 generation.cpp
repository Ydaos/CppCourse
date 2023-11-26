#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

// STL_算术生成算法 小型算法，使用前要包含头文件<numeric>
namespace space_generate {

	class MyPrint {
	public:
		void operator()(int val) {
			std::cout << val << " ";
		}
	};

	/*
	* accumulate 计算容器元素累计总和
	* 函数原型：
	* int accumulate(iterator beg, iterator end, value);
	* value为起始值，一般设为0
	*/
	void MyAccumulate() {
		std::vector<int> v;
		v.push_back(10);
		v.push_back(40);
		v.push_back(30);
		v.push_back(20);
		v.push_back(50);

		// 参数3 起始累加值
		int total = accumulate(v.begin(), v.end(), 0);
		std::cout << total << std::endl;
	}


	/*
	* fill 向容器填充指定的元素
	* 函数原型：
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