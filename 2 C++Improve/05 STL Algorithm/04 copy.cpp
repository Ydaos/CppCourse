#include <iostream>
#include <algorithm>
#include <vector>

/*
* STL_排序算法
* copy;       //容器内指定范围元素拷贝到另一个容器中
* replace;    //将区间内旧元素替换成新元素
* replace_if; //将区间内满足条件的所有元素替换成新元素
* swap;       //互换两个容器的元素
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
			// 替换大于20的值
			return val > 20;
		}
	};

	/*
	* copy 容器内指定范围元素拷贝到另一个容器中
	* 函数原型：
	* copy(iterator beg, iterator end, iterator dest); 
	*
	* 接收容器必须先开辟空间来接收拷贝数据
	* 实际开发中copy函数不常用，循环赋值或拷贝构造函数更常用
	*/
	void MyCopy() {
		std::vector<int> v;
		v.push_back(10);
		v.push_back(40);
		v.push_back(30);
		v.push_back(20);
		v.push_back(50);

		// 接收容器必须先开辟空间来接收拷贝数据
		std::vector<int> v2;
		v2.resize(v.size());

		copy(v.begin(), v.end(), v2.begin());
		for_each(v2.begin(), v2.end(), MyPrint());
		std::cout << std::endl;
	}


	/*
	* replace 将区间内旧元素替换成新元素
	* 函数原型：
	* replace(iterator beg, iterator end, oldValue, newValue);
	* 
	* 注意：replace会把区间内所有旧的元素替换成新元素
	*/
	void MyReplace() {
		std::vector<int> v;
		v.push_back(10);
		v.push_back(40);
		v.push_back(30);
		v.push_back(20);
		v.push_back(10);

		std::cout << "替换前\n";
		for_each(v.begin(), v.end(), MyPrint());
		std::cout << std::endl;

		// 将等于10的值替换成100
		std::cout << "替换后\n";
		replace(v.begin(), v.end(), 10, 100);
		for_each(v.begin(), v.end(), MyPrint());
		std::cout << std::endl;
	}


	/*
	* replace_if 替换区间内所有满足条件的元素
	* 函数原型：
	* replace_if(iterator beg1, iterator end1, _Pred, newValue);
	* replace_if 可以利用仿函数灵活筛选满足的元素，再将其替换
	*/
	void MyReplace_IF() {
		std::vector<int> v1;
		v1.push_back(10);
		v1.push_back(30);
		v1.push_back(30);
		v1.push_back(20);
		v1.push_back(50);
		v1.push_back(40);

		std::cout << "替换前\n";
		for_each(v1.begin(), v1.end(), MyPrint());
		std::cout << std::endl;

		// 将大于20的值替换成200
		std::cout << "替换后\n";
		replace_if(v1.begin(), v1.end(), MyGreater(), 200);
		for_each(v1.begin(), v1.end(), MyPrint());
		std::cout << std::endl;
	}


	/*
	* swap 互换两个容器的元素
	* 函数原型：
	* swap(container c1, container c2);
	* 
	* 注意：swap 交换容器时，注意两个容器必须同种类型
	*/
	void MySwap() {
		std::vector<int> v1;
		std::vector<int> v2;

		for (int i = 0; i < 10; i++) {
			v1.push_back(i);
			v2.push_back(i * 100);
		}

		std::cout << "互换前\n";
		for_each(v1.begin(), v1.end(), MyPrint());
		std::cout << std::endl;
		for_each(v2.begin(), v2.end(), MyPrint());
		std::cout << std::endl;

		std::cout << "互换后\n";
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