#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

/*
* �ڽ��º�����
* ʹ���ڽ��º�����Ҫ����ͷ�ļ� #include<functional>
* ��Щ�º��������Ķ����÷���һ��º�����ȫ��ͬ
* 
* �ڽ��º��������������º�������ϵ�º������߼��º���
*/

/*
* �����º�����ʵ���������㣬����negate��һԪ���㣬�������Ƕ�Ԫ����
* 
* �º���ԭ�ͣ�
* template<class T> T plus<T>       // �ӷ��º���
* template<class T> T minus<T>      // �����º���
* template<class T> T multiplies<T> // �˷��º���
* template<class T> T divides<T>    // �����º���
* template<class T> T modules<T>    // ȡģ�º���
* template<class T> T negate<T>     // ȡ���º���
* 
* �ܽ᣺�е㼦�ߣ����þ���
*/
void Arithmetic() {
	// negate һԪ�º��� ȡ���º���
	std::negate<int> n;
	std::cout << n(10) << std::endl;

	// plus ��Ԫ�º��� �ӷ��º���
	std::plus<int> p;
	std::cout << p(10, 10) << std::endl;
}


/*
* ��ϵ�º���
* ����ԭ�ͣ�
* template<class T> bool equal_to<T>      //����
* template<class T> bool not_equal_to<T>  //������
* template<class T> bool greater<T>       //����
* template<class T> bool greater_equal<T> //���ڵ���
* template<class T> bool less<T>          //С��
* template<class T> bool less_equal<T>    //С�ڵ���
* 
* �ܽ᣺��ϵ�º��������greater<int>();��ΪĬ��sort��������less<T>()����
*/
void Relationship() {
	// greater
	std::vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	sort(v.begin(), v.end()); // ����
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	sort(v.begin(), v.end(), std::greater<int>()); // ����
	// greater<int>()  �ڽ��º���������Ҫ�Լ�д����ķº���
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


/*
* �߼��º���
* ����ԭ�ͣ�
* template<class T> bool logical_and<T> //�߼���
* template<class T> bool logical_or<T>  //�߼���
* template<class T> bool logical_not<T> //�߼���
* 
* �ܽ᣺�߼��º����õıȽ��٣��˽⼴�ɣ������߼��Ƿº��������ڰ�������ʱ������ȡ����
*/
void Logical() {
	std::vector<bool> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);

	for (std::vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// �����߼��� ������v�ᵽv2�� ��ȡ��
	std::vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), std::logical_not<bool>());
	// transform(); ���˺��� ����ǰ��Ҫ�����������ȿ��ٿռ䣡

	for (std::vector<bool>::iterator it = v2.begin(); it != v2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// �����߼���
	std::logical_and<bool> la;
	bool ret = la(1, 0);
	std::cout << "ret = " << ret << std::endl;
}


int main() {
	Arithmetic();

	std::cout << "-------------------\n";
	Relationship();

	std::cout << "-------------------\n";
	Logical();

	system("pause");
	return 0;
}