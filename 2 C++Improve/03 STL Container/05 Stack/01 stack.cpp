#include <iostream>
#include <stack>

/*
* stack���ջ����stack���Ƚ���������ݽṹ����ֻ��һ������
* ջ�������б�����Ϊ����Ϊֻ��ջ��Ԫ�ز��ܱ�����
* ջ�����ж��Ƿ�Ϊ�� -- empty
* ջ���Է���Ԫ�ظ��� -- size
* ջ�н������ݳ�Ϊ��ջ -- push
* ջ�е������ݳ�Ϊ��ջ -- pop
*
* stack���ýӿ�
* ���캯����
* stack<T> stk;            //Ĭ�Ϲ��캯��
* stack(const stack &std); //�������캯��
*
* ��ֵ������
* stack& operator=(const stack &stk); //����=�����

* ���ݴ�ȡ��
* push(elem); //��ջ�����Ԫ��
* pop();      //��ջ���Ƴ���һ��Ԫ��
* top();      //����ջ��Ԫ��

* ��С������
* empty();    //�ж϶�ջ�Ƿ�Ϊ��
* size();     //���ض�ջ��С
*/
void MyStack() {
	// �ص㣺�Ƚ����
	std::stack<int> s;

	// ��ջ
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	// ֻҪջ��Ϊ�գ��鿴ջ��������ջ
	std::cout << "ջ��Ԫ�ظ�����" << s.size() << std::endl;
	while (!s.empty()) {
		std::cout << "ջ��Ԫ�أ�" << s.top() << std::endl;
		s.pop();
	}
	std::cout << "ջ��Ԫ�ظ�����" << s.size() << std::endl;
}


int main() {
	MyStack();

	system("pause");
	return 0;
}