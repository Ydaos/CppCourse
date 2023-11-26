#include <iostream>
#include <list>

void printList(const std::list<int>& l); //�����������ļ�"01 definition.cpp"

/*
* List���������ɾ��
* ����ԭ�ͣ�
* push_back(elem);          //������β������һ��elemֵԪ��
* pop_back();               //ɾ���������һ��Ԫ��
* push_front(elem);         //������ͷ������һ��elemֵԪ��
* pop_front();              //ɾ��ͷ��һ��Ԫ��
*
* insert(pos, elem);        //�ڵ�����posλ�ò���һ��elemֵԪ��
* insert(pos, int n, elem); //�ڵ�����posλ�ò���n��elemֵԪ��
* insert(pos, beg, end);    //�ڵ�����posλ�ò���[beg, end]��������Ԫ��
*
* clear();                  //�����������Ԫ��
* erase(beg, end);          //ɾ��[beg, end]��������Ԫ��
* erase(pos);               //ɾ���ڵ�����posλ���ϵ�Ԫ��
* remove(elem);             //ɾ������������elemֵƥ���Ԫ��
* 
* List��Ҫ���ԣ������ɾ���������������ԭ��list��������ʧЧ������vector�ǲ����ڵ�
*/
void Insert() {
	std::list<int> L;

	// 1��List���˲�������
	// β������
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);

	// ͷ������
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);
	printList(L);

	// 2��List���λ�ò�������
	// insert(pos, elem);
	std::list<int>::iterator it = L.begin();
	L.insert(++it, 1000);
	printList(L);

	// insert(pos, int n, elem)
	L.insert(it, 3, 2000);
	printList(L);

	// insert(pos, beg, end)
	std::list<int>L2;
	L2.insert(L2.begin(), it, L.end());
	printList(L2); // 100 10 20 

	// ע�����
	// List��Ҫ���ԣ������ɾ���������������ԭ��list��������ʧЧ������vector�ǲ����ڵ�
	// ���it��ʼ����ָ���һֱ��100���������±�Ϊ1��Ԫ�أ�
}

void Delete() {
	std::list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	L.push_back(50);
	printList(L);

	// β��ɾ��
	L.pop_back();
	printList(L);

	// ͷ��ɾ��
	L.pop_front();
	printList(L);

	// erase(pos);
	L.erase(++L.begin());
	printList(L);

	// erase(beg, end) || clear()
	L.clear();  //�ȼ��� L.erase(L.begin(), L.end());
	printList(L);

	// remove(elem)
	std::list<int>L2;
	L2.push_back(10);
	L2.push_back(20);
	L2.push_back(10);
	L2.push_back(40);
	L2.push_back(10);
	printList(L2);

	L2.remove(10);
	printList(L2);
}


/*
* List����Ԫ�ش�ȡ
* ����ԭ�ͣ�
* front();  //���ص�һ��Ԫ��
* back();   //�������һ��Ԫ��
* �����������˫���������������ģ���Ϊ���ݽṹ�����ڴ�ռ䲻�������޷��������
* Ҳ����˵��֧��[]��������ؼ�at()����
*/
void Access() {
	std::list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);

	// L[0];    Error!!!��������[]����
	// L.at(0); Error!!!û�����Ա����
	// ԭ��list����������ÿ�����ݲ��������ռ�洢����֧���������

	std::cout << "list��һ��Ԫ��Ϊ��" << L.front() << std::endl;
	std::cout << "list���һ��Ԫ��Ϊ��" << L.back() << std::endl;

	// ��֤list��֧���������
	std::list<int>::iterator it = L.begin();
	it++;
	// it += 1; Error!!!����������ʣ�ֻ���ۼ����ҵ���һ�����
}


/*
* List������ת������
* ����ԭ�ͣ�
* reverse();  //��ת����
* sort();     //��������
*
* ע�����
* ����֧��������ʵ�����������������ʹ�ñ�׼�����㷨��sort(L.begin(), L.end());
* ��֧��������ʵ��������������ڲ����ṩһЩ��Ա�����㷨
*/
bool myCompare(int v1, int v2) {
	// ���� ���õ�һ���� > �ڶ�����
	return v1 > v2;
}

void MySort() {
	std::list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(25);
	std::cout << "��תǰ\n";
	printList(L);

	// reserve��ת����
	L.reverse();
	std::cout << "��ת��\n";
	printList(L);

	// ��Ա����sort����
	L.sort(); //Ĭ���������
	std::cout << "�����\n";
	printList(L);

	L.sort(myCompare); //�������
	std::cout << "�����\n";
	printList(L);
}

int main03() {
	Insert();

	std::cout << "------------------\n";
	Delete();

	std::cout << "------------------\n";
	Access();

	std::cout << "------------------\n";
	MySort();

	system("pause");
	return 0;
}