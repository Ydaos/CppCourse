#include <iostream>
#include <algorithm>
#include <vector>

/*
* STL_常用集合算法：
* set_intersection; //求两个集合的交集
* set_union;        //求两个集合的并集
* set_difference;   //求两个集合的差集
*/

namespace space_collect {

	class MyPrint {
	public:
		void operator()(int val) {
			std::cout << val << " ";
		}
	};

	/*
	* set_intersection 求两个集合的交集
	* 函数原型：
	* iterator set_intersection(iterator beg_1, iterator end_1, iterator beg_2, iterator end_2, iterator dest);
	* 
	* 注意事项：
	* 1、求交集的两个集合必须是有序序列，且序列规则相同
	* 2、目标容器开辟空间需要取两个容器中小容器的size
	* 3、set_intersection返回值是交集中最后一个元素的迭代器地址
	*/
	void MySet_Intersection() {
		std::vector<int> v1;
		std::vector<int> v2;
		for (int i = 0; i < 10; i++) {
			v1.push_back(i);     //0~9
			v2.push_back(i + 5); //5~14
		}

		// 取小容器size 提前给目标容器开辟空间
		std::vector<int> v3;
		v3.resize(std::min(v1.size(), v2.size()));

		// 获取交集，返回值是交集中最后一个元素的迭代器迭代器地址
		std::vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

		// 用返回迭代器打印，不会打印多余默认值
		for_each(v3.begin(), itEnd, MyPrint());
		std::cout << std::endl;
	}


	/*
	* set_union 求两个集合的并集
	* 函数原型：
	* iterator set_union(iterator beg_1, iterator end_1, iterator beg_2, iterator end_2, iterator dest)
	* 
	* 注意事项：
	* 1、求并集的两个集合必须是有序序列，且序列规则相同
	* 2、目标容器开辟空间需要取两个容器的size之和
	* 3、set_union返回值是并集中最后一个元素的迭代器地址
	*/
	void MySet_Union() {
		std::vector<int> v1;
		std::vector<int> v2;
		for (int i = 0; i < 10; i++) {
			v1.push_back(i);     //0~9
			v2.push_back(i + 5); //5~14
		}

		// 取两个容器size之和 提前给目标容器开辟空间
		std::vector<int> v3;
		v3.resize(v1.size() + v2.size());

		// 获取并集，返回值是并集中最后一个元素的迭代器迭代器地址
		std::vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
		
		// 用返回迭代器打印，不会打印多余默认值
		for_each(v3.begin(), itEnd, MyPrint());
		std::cout << std::endl;
	}


	/*
	* set_difference 求两个集合的差集
	* 函数原型：
	* iterator set_difference(iterator beg_1, iterator end_1, iterator beg_2, iterator end_2, iterator dest)
	*
	* 注意事项：
	* 1、求差集的两个集合必须是有序序列，且序列规则相同
	* 2、目标容器开辟空间需要取两个容器中大容器的size
	* 3、set_difference返回值是差集中最后一个元素的迭代器地址
	*/
	void MySet_Difference() {
		std::vector<int> v1;
		std::vector<int> v2;
		for (int i = 0; i < 10; i++) {
			v1.push_back(i);     //0~9
			v2.push_back(i + 5); //5~14
		}

		// 取两个容器size中的最大值 提前给目标容器开辟空间
		// 最特殊清空两个容器没交集，取两个容器大的size为目标容器
		std::vector<int> v3;
		v3.resize(std::max(v1.size(), v2.size()));

		// 获取差集，返回值为差集中最后一个元素的迭代器迭代器地址
		std::cout << "v1相对于v2的差集：\n";
		std::vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
		
		// 用返回迭代器打印，不会打印多余默认值
		for_each(v3.begin(), itEnd, MyPrint());
		std::cout << std::endl;

		std::cout << "v2相对于v1的差集：\n";
		itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
		
		for_each(v3.begin(), itEnd, MyPrint());
		std::cout << std::endl;
	}
	
}

int main() {
	space_collect::MySet_Intersection();

	std::cout << "---------------------------\n";
	space_collect::MySet_Union();

	std::cout << "---------------------------\n";
	space_collect::MySet_Difference();

	system("pause");
	return 0;
}