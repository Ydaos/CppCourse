#include <iostream>
#include <string>
 
/*
* string ������������һ���࣬���ڲ���װchar*�������ַ���
* �ص㣺
* ��װ�ܶ��Ա��������find��copy��insert��
* string����char*������ڴ棬���õ��ĸ���Խ�硢ȡֵԽ��ȣ������ڲ�����
* 
* string�Ĺ��캯����
* - string();                  //����һ���յ��ַ���
* - string(const char* s);     //ʹ���ַ�����s��ʼ��
* - string(const string& str); //ʹ��һ��string�����ʼ����һ��string����
* - string(int n, char c);     //ʹ��n���ַ�c��ʼ��
*/
void Constructor() {
	std::string s1;

	const char* s = "hello world!";
	std::string s2(s);
	std::cout << "s2 = " << s2 << std::endl;

	std::string s3(s2);
	std::cout << "s3 = " << s3 << std::endl;

	std::string s4(4, 'a');
	std::cout << "s4 = " << s4 << std::endl;

	//�ܽ᣺string�Ķ��ֹ��췽��û�пɱ��ԣ����Ӧ�ü���
	//ʵ���ϸ�ֵ���������ã�string str = "hello world";
}


/*
* string��ֵ����
* string& operator=(const char* s);     //char*�����ַ���s ��ֵ����ǰ���ַ���
* string& operator=(const string &s);   //�ַ���s ��ֵ����ǰ�ַ���
* string& operator=(char c);            //�ַ�c ��ֵ����ǰ�ַ���
* string& assign(const char* s);        //char*�����ַ���s ��ֵ����ǰ���ַ���
* string& assign(const char* s, int n); //char*�����ַ���s��ǰn���ַ���ֵ����ǰ���ַ���
* string& assign(const string &s);      //�ַ���s ��ֵ����ǰ�ַ���
* string& assign(int n, char c);        //��n���ַ�c ��ֵ����ǰ�ַ���
*/
void Assignment() {
	// string& operator=(const char* s);
	const char* c = "hello world!";
	std::string str1 = c;
	std::cout << "str1 = " << str1 << std::endl;

	// string& operator=(const string &s); 
	std::string str2;
	str2 = str1;
	std::cout << "str2 = " << str2 << std::endl;

	// string& operator=(char c);
	std::string str3;
	str3 = 'a';
	std::cout << "str3 = " << str3 << std::endl;

	// string& assign(const char* s); 
	std::string str4;
	str4.assign("hello C++");
	std::cout << "str4 = " << str4 << std::endl;

	// string& assign(const char* s, int n);
	std::string str5;
	str5.assign("hello C++", 5);
	std::cout << "str5 = " << str5 << std::endl;

	// string& assign(const string &s);
	std::string str6;
	str6.assign(str5);
	std::cout << "str6 = " << str6 << std::endl;

	// string& assign(int n, char c);
	std::string str7;
	str7.assign(5, 'a');
	std::cout << "str7 = " << str7 << std::endl;
}


/*
* �ַ���ĩβƴ���ַ���
* string �ַ���ƴ�Ӻ���ԭ��
* string& operator+=(const char* s);               //����+=������
* string& operator+=(const string &s);             //����+=������
* string& operator+=(const char c);                //����+=������
* string& append(const char* s);                   //���ַ���s ���ӵ���ǰ�ַ�����β
* string& append(const char* s, int n);            //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
* string& append(const string &s);                 //ͬstring& operator+=(const string &s);
* string& append(const string &s, int pos, int n); //���ַ���s��pos���ĵ�n���ַ����ӵ��ַ�����β
* 
* �ܽ᣺�ַ���ƴ�����ذ汾�ܶ࣬��һ������+=�������append()ʵ�־ֲ��ַ���ƴ�Ӽ���
*/
void Joint() {
	// string& operator+=(const char* s);
	std::string str1 = "abc";
	str1 += "efg";
	std::cout << "str1 = " << str1 << std::endl;

	// string& operator+=(const string &s);
	std::string str2 = "str2 += ";
	str2 += str1;
	std::cout << "str2 = " << str2 << std::endl;

	// string& operator+=(const char c);
	str2 += '!';
	std::cout << "str2 = " << str2 << std::endl;

	// string& append(const char* s);
	std::string str4 = "C++";
	str4.append(" hello");
	std::cout << "str4 = " << str4 << std::endl;

	// string& append(const char* s, int n); 
	std::string str5 = "abc ";
	str5.append("hello C++", 5);
	std::cout << "str5 = " << str5 << std::endl;

	// string& append(const string &s); 
	std::string str6 = "str6 += ";
	str6.append(str5);
	std::cout << "str6 = " << str6 << std::endl;

	// string& append(const string &s, int pos, int n);
	std::string str7 = "abcdefg";
	std::string str8 = "str8 ";
	str8.append(str7, 3, 2);
	std::cout << "str8 = " << str8 << std::endl;
}


int main() {
	Constructor();

	std::cout << "\n---------------------\n";
	Assignment();

	std::cout << "\n---------------------\n";
	Joint();

	system("pause");
	return 0;
}