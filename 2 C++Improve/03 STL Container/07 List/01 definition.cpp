#include <iostream>
#include <list>

/*
* List��������ݽ�����ʽ�洢
* ����(list)��һ������洢��Ԫ�Ϸ������Ĵ洢�ṹ������Ԫ�ص��߼�˳����ͨ�������е�ָ������ʵ�ֵ�
* ������һϵ�н�����
* ��㣺һ���洢����Ԫ�ص���������һ���Ǵ洢��һ������ַ��ָ����
* 
* STL�е�������һ��˫��ѭ������
* ˫����������ָ�����в����洢����һ�����ĵ�ַ�����洢����һ�����ĵ�ַ
* ��������Ĵ洢��ʽ�����������ڴ�ռ䣬�������list�еĵ�����ֻ֧��ǰ�ƺͺ��ƣ���˫�������
* 
* �ŵ㣺���Զ�����λ�ý��п��ٲ����ɾ��Ԫ�أ����ö�̬�洢���䣬��������ڴ��˷Ѻ����
* ȱ�㣺���������ٶ�����û������죻ռ�õĿռ�Ҳ��������ָ����
* 
* List��Ҫ���ԣ������ɾ���������������ԭ��list��������ʧЧ������vector�ǲ����ڵ�
* List��Vector�������������������������Ҫ���Ӧ��
*/
void printList(const std::list<int>& l) {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
}


/*
* List���캯��
* ����ԭ�ͣ�
* list<T> lst;           //Ĭ�Ϲ��캯��
* list(beg, end);        //��[beg, end]����Ԫ�ؿ���������
* list(n, elem);         //��n��elemԪ�ؿ���������
* list(const list &lst); //�������캯��
*/
void Constructor() {
	// Ĭ�Ϲ���
	std::list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	L.push_back(50);
	printList(L);

	// ��������
	std::list<int>L2(L);
	printList(L2);

	// list(beg, end); 
	std::list<int>L3(L.begin(), L.end());
	printList(L3);

	// list(n, elem);
	std::list<int>L4(5, 6);
	printList(L4);
}


/*
* List������ֵ
* ����ԭ�ͣ�
* list& operator=(const list &lst); //����=�����
* assign(beg, end);			     //��[beg, end]������Ԫ�ظ�ֵ������
* assign(n, elem);                  //��n��elemԪ�ظ�ֵ������
*/
void Assignment() {
	std::list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	L.push_back(50);
	printList(L);

	// list& operator=(const list &lst);
	std::list<int>L2;
	L2 = L;
	printList(L2);

	// assign(beg, end);
	std::list<int>L3;
	L3.assign(L.begin(), L.end());
	printList(L3);

	// assign(n, elem); 
	std::list<int>L4;
	L4.assign(5, 6);
	printList(L4);
}


int main01() {
	Constructor();

	std::cout << "--------------------------\n";
	Assignment();

	system("pause");
	return 0;
}