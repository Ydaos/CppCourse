#include <iostream>
#include <string>

/*
* string�滻������
* string& replace(int pos, int n, const string &str); //�滻��pos��ʼ��n���ַ�Ϊ�ַ�����str
* string& replace(int pos, int n, const char* str);   //�滻��pos��ʼ��n���ַ�Ϊ�ַ�����str
* 
* replace���滻ʱ��Ҫָ�����ĸ�λ���𣬶��ٸ��ַ����滻��ʲô�����ַ�
*/
void Replace() {
	// string& replace(int pos, int n, const char* str);
	std::string str = "abcdefgcd";
	str.replace(1, 3, "11");
	// ��str��1��λ���������ַ��滻Ϊ"11"�����ַ�
	std::cout << "str = " << str << std::endl;
}


/*
* string�ַ��������ɾ��
* ����ԭ�ͣ�
* string& insert(int pos, const char* s);   //��posλ�ò����ַ���
* string& insert(int pos, const string &s); //��posλ�ò����ַ���
* string& insert(int pos, int n, char c);   //��posλ�ò���n���ַ�c
* string& erase(int pos, int n = npos);     //��posλ�ÿ�ʼɾ��n���ַ�
*/
void InsertDel() {
	std::string str = "hello";

	// ����
	str.insert(1, "111"); //��1��λ�ò����ַ���"111"
	std::cout << "str = " << str << std::endl;

	str.insert(2, 2, '2'); //��2��λ�ò��������ַ� '2'
	std::cout << "str = " << str << std::endl;

	// ɾ��
	str.erase(1, 5); //��1��λ��ɾ��5���ַ�
	std::cout << "str = " << str << std::endl;
}
// ע�⣺�±�Ŀ�ʼ��0����1


int main03() {
	Replace();

	std::cout << "\n---------------------\n";
	InsertDel();

	system("pause");
	return 0;
}