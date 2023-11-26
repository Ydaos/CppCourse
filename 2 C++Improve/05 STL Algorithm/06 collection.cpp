#include <iostream>
#include <algorithm>
#include <vector>

/*
* STL_���ü����㷨��
* set_intersection; //���������ϵĽ���
* set_union;        //���������ϵĲ���
* set_difference;   //���������ϵĲ
*/

namespace space_collect {

	class MyPrint {
	public:
		void operator()(int val) {
			std::cout << val << " ";
		}
	};

	/*
	* set_intersection ���������ϵĽ���
	* ����ԭ�ͣ�
	* iterator set_intersection(iterator beg_1, iterator end_1, iterator beg_2, iterator end_2, iterator dest);
	* 
	* ע�����
	* 1���󽻼����������ϱ������������У������й�����ͬ
	* 2��Ŀ���������ٿռ���Ҫȡ����������С������size
	* 3��set_intersection����ֵ�ǽ��������һ��Ԫ�صĵ�������ַ
	*/
	void MySet_Intersection() {
		std::vector<int> v1;
		std::vector<int> v2;
		for (int i = 0; i < 10; i++) {
			v1.push_back(i);     //0~9
			v2.push_back(i + 5); //5~14
		}

		// ȡС����size ��ǰ��Ŀ���������ٿռ�
		std::vector<int> v3;
		v3.resize(std::min(v1.size(), v2.size()));

		// ��ȡ����������ֵ�ǽ��������һ��Ԫ�صĵ�������������ַ
		std::vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

		// �÷��ص�������ӡ�������ӡ����Ĭ��ֵ
		for_each(v3.begin(), itEnd, MyPrint());
		std::cout << std::endl;
	}


	/*
	* set_union ���������ϵĲ���
	* ����ԭ�ͣ�
	* iterator set_union(iterator beg_1, iterator end_1, iterator beg_2, iterator end_2, iterator dest)
	* 
	* ע�����
	* 1���󲢼����������ϱ������������У������й�����ͬ
	* 2��Ŀ���������ٿռ���Ҫȡ����������size֮��
	* 3��set_union����ֵ�ǲ��������һ��Ԫ�صĵ�������ַ
	*/
	void MySet_Union() {
		std::vector<int> v1;
		std::vector<int> v2;
		for (int i = 0; i < 10; i++) {
			v1.push_back(i);     //0~9
			v2.push_back(i + 5); //5~14
		}

		// ȡ��������size֮�� ��ǰ��Ŀ���������ٿռ�
		std::vector<int> v3;
		v3.resize(v1.size() + v2.size());

		// ��ȡ����������ֵ�ǲ��������һ��Ԫ�صĵ�������������ַ
		std::vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
		
		// �÷��ص�������ӡ�������ӡ����Ĭ��ֵ
		for_each(v3.begin(), itEnd, MyPrint());
		std::cout << std::endl;
	}


	/*
	* set_difference ���������ϵĲ
	* ����ԭ�ͣ�
	* iterator set_difference(iterator beg_1, iterator end_1, iterator beg_2, iterator end_2, iterator dest)
	*
	* ע�����
	* 1�������������ϱ������������У������й�����ͬ
	* 2��Ŀ���������ٿռ���Ҫȡ���������д�������size
	* 3��set_difference����ֵ�ǲ�����һ��Ԫ�صĵ�������ַ
	*/
	void MySet_Difference() {
		std::vector<int> v1;
		std::vector<int> v2;
		for (int i = 0; i < 10; i++) {
			v1.push_back(i);     //0~9
			v2.push_back(i + 5); //5~14
		}

		// ȡ��������size�е����ֵ ��ǰ��Ŀ���������ٿռ�
		// �����������������û������ȡ�����������sizeΪĿ������
		std::vector<int> v3;
		v3.resize(std::max(v1.size(), v2.size()));

		// ��ȡ�������ֵΪ������һ��Ԫ�صĵ�������������ַ
		std::cout << "v1�����v2�Ĳ��\n";
		std::vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
		
		// �÷��ص�������ӡ�������ӡ����Ĭ��ֵ
		for_each(v3.begin(), itEnd, MyPrint());
		std::cout << std::endl;

		std::cout << "v2�����v1�Ĳ��\n";
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