#include <iostream>
#include <set>

void printSet(const std::set<int>& s); //����������"01 definition.cpp

/*
* set���������ɾ��
* insert(elem);    //����������elemֵ��Ԫ��
* clear();         //�������
* erase(pos);      //ɾ��pos������ָ���Ԫ��
* erase(beg, end); //ɾ��[beg, end]��������Ԫ��
* erase(elem);     //ɾ��elemֵ��Ԫ�أ�����list�����remove
*/
void Insert() {
	// ����
	std::set<int> s1;
	s1.insert(10);
	s1.insert(22);
	s1.insert(20);
	s1.insert(11);
	s1.insert(50);
	printSet(s1);
}

void Delete() {
	std::set<int> s1;
	s1.insert(10);
	s1.insert(22);
	s1.insert(20);
	s1.insert(11);
	s1.insert(50);
	printSet(s1);

	// erase(pos); 
	s1.erase(++s1.begin());
	printSet(s1);

	// erase(elem)
	s1.erase(22);
	printSet(s1);

	// clear()
	s1.clear();
	printSet(s1);
}


/*
* set�������Һ�ͳ��
* ����ԭ�ͣ�
* find(key);    //����keyԪ���Ƿ���ڣ����ظü���Ԫ�صĵ��������������򷵻�set.end()
* count(key);   //ͳ��key��Ԫ�ظ���
*/
void FindAndCount() {

	std::set<int> s1;
	s1.insert(10);
	s1.insert(22);
	s1.insert(20);
	s1.insert(11);
	s1.insert(50);
	printSet(s1);

	// find(key)
	std::set<int>::iterator pos = s1.find(10); //���ص��ǵ�����
	if (pos != s1.end()) {
		std::cout << "�ҵ�Ԫ�أ�" << *pos << std::endl;
	}
	else {
		std::cout << "δ�ҵ�Ԫ��" << std::endl;
	}

	// count(key)
	int num = s1.count(22);
	// ����set���ԣ���������ظ��������Է��ؽ����0��1
	std::cout << "num = " << num << std::endl;
}

int main03() {
	Insert();

	std::cout << "---------------\n";
	Delete();

	std::cout << "---------------\n";
	FindAndCount();

	system("pause");
	return 0;
}