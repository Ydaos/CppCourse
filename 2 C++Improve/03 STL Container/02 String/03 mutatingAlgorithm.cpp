#include <iostream>
#include <string>

/*
* string替换函数：
* string& replace(int pos, int n, const string &str); //替换从pos开始的n个字符为字符串的str
* string& replace(int pos, int n, const char* str);   //替换从pos开始的n个字符为字符串的str
* 
* replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符
*/
void Replace() {
	// string& replace(int pos, int n, const char* str);
	std::string str = "abcdefgcd";
	str.replace(1, 3, "11");
	// 将str从1号位置起三个字符替换为"11"两个字符
	std::cout << "str = " << str << std::endl;
}


/*
* string字符串插入和删除
* 函数原型：
* string& insert(int pos, const char* s);   //从pos位置插入字符串
* string& insert(int pos, const string &s); //从pos位置插入字符串
* string& insert(int pos, int n, char c);   //从pos位置插入n个字符c
* string& erase(int pos, int n = npos);     //从pos位置开始删除n个字符
*/
void InsertDel() {
	std::string str = "hello";

	// 插入
	str.insert(1, "111"); //从1号位置插入字符串"111"
	std::cout << "str = " << str << std::endl;

	str.insert(2, 2, '2'); //从2号位置插入两个字符 '2'
	std::cout << "str = " << str << std::endl;

	// 删除
	str.erase(1, 5); //从1号位置删除5个字符
	std::cout << "str = " << str << std::endl;
}
// 注意：下标的开始是0不是1


int main03() {
	Replace();

	std::cout << "\n---------------------\n";
	InsertDel();

	system("pause");
	return 0;
}