#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

/*
* STL_排序算法 
* sort;           // 排序
* random_shuffle; // 洗牌
* merge;          // 合并
* reverse;        // 反转
*/

namespace space_sort {

	class MyPrint {
	public:
		void operator()(int val) {
			std::cout << val << " ";
		}
	};

	/*
	* sort 对容器内元素进行排序
	* 函数原型：
	* sort(iterator beg, iterator end, _Pred);
	* 
	* sort算法非常常用，默认升序；配合内建的关系仿函数greater<int>()实现降序
	*/
	void MySort() {
		std::vector<int> v;
		v.push_back(10);
		v.push_back(40);
		v.push_back(30);
		v.push_back(20);
		v.push_back(50);

		// 默认升序
		sort(v.begin(), v.end());
		for_each(v.begin(), v.end(), MyPrint());
		std::cout << std::endl;

		// 利用仿函数改为降序
		sort(v.begin(), v.end(), std::greater<int>());
		for_each(v.begin(), v.end(), MyPrint());
		std::cout << std::endl;
	}


	/*
	* random_shuffle 指定范围内的元素随机调整次序
	* 函数原型：
	* random_shuffle(iterator beg, iterator end);
	* 
	* random_shuffle算法非常实用，应用在抽签操作。
	*/
	void MyRandom_Shuffle() {
		srand((unsigned int)time(NULL)); // 随机数种子

		std::vector<int> v;
		for (int i = 0; i < 10; i++) {
			v.push_back(i);
		}

		// 利用洗牌算法打乱顺序
		random_shuffle(v.begin(), v.end());
		for_each(v.begin(), v.end(), MyPrint());
		std::cout << std::endl;
	}


	/*
	* merge 两个容器元素合并，并存储到另一个容器中
	* 函数原型：
	* merge(iterator beg_1, iterator end_1, iterator beg_2, iterator end_2, iterator dest); 
	* 
	* 注意：
	* 提前给目标容器分配空间
	* 两个容器必须是有序的，且排序规则相同！
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

		// 提前给目标容器分配空间
		std::vector<int> v3;
		v3.resize(v1.size() + v2.size());

		// 两个原容器必须是有序且排序规则相同，这里做升序处理
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		// 合并原容器选中区间的元素到目标容器
		merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
		for_each(v3.begin(), v3.end(), MyPrint());
		std::cout << std::endl;
	}


	/*
	* reverse 反转指定范围内的元素(10 20 -> 20 10)
	* 函数原型：
	* reverse(iterator beg, iterator end);
	*/
	void MyReverse() {
		std::vector<int> v1;
		v1.push_back(10);
		v1.push_back(30);
		v1.push_back(20);
		v1.push_back(40);

		std::cout << "反转前\n";
		for_each(v1.begin(), v1.end(), MyPrint());

		std::cout << "\n反转后\n";
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