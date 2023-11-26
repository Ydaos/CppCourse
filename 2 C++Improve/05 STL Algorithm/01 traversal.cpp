#include <iostream>
#include <algorithm>
#include <vector>

/*
* STL常用算法：
* 1、算法主要由头文件<algorithm> <numeric> <functional>组成
* 2、<algorithm>是所有STL头文件最大的一个，范围涉及到比较、交换、遍历操作、复制、修改等等
* 3、<numeric>体积很小、只包括几个在序列上面进行简单数学运算的模板函数
* 4、<functional>定义了一些模板类，用以声明函数对象
* 
* STL_遍历算法：
* for_each;  // 遍历容器
* transform; // 搬运容器
*/

namespace space_tra {

	// 普通函数
	void myPrint(int val) {
		std::cout << val << " ";
	}

	// 仿函数
	class MyPrint {
	public:
		void operator()(int val) {
			std::cout << val << " ";
		}
	};

	class MyTransform {
	public:
		int operator()(int val) {
			val += 100; //可以添加逻辑运算给搬运数据
			return val;
		}
	};


	/*
	* for_each 遍历函数
	* 函数原型：
	* for_each(iterator beg, iterator end, _func);
	* for_each在实际开发中是最常用的遍历算法，必须熟练掌握
	*/
	void ForEach() {
		std::vector<int> v;
		for (int i = 0; i < 10; i++) {
			v.push_back(i);
		}

		// 普通函数
		for_each(v.begin(), v.end(), myPrint);
		std::cout << std::endl;

		// 仿函数
		for_each(v.begin(), v.end(), MyPrint());
		std::cout << std::endl;
	}


	/*
	* transform 搬运函数
	* 函数原型：
	* transform(iterator beg_1, iterator end_1, iterator beg_2, _func);
	* 
	* _func 为函数或者仿函数，可以对搬运的值进行操作
	* transform 搬运目标容器必须提前开辟空间，否则无法正常搬运
	*/
	void Transform() {
		std::vector<int> v;
		for (int i = 0; i < 10; i++) {
			v.push_back(i);
		}

		std::vector<int> v2;
		v2.resize(v.size()); //目标容器必须提前开辟空间来接收搬运数据
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