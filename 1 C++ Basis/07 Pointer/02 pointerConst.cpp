#include <iostream>

//1��const����ָ�� --����ָ��
//2��const���γ��� --ָ�볣��
//3��const������ָ�룬�����γ���

void PointerConst() {
	//1��const����ָ�� --����ָ��
	int a = 10, b = 20;
	const int* p1 = &a;
	//�ص㣺ָ���ָ����Ըģ���ָ��ָ���ֵ���ɸ�
	//*p1 = 20; error!!!ָ��ָ���ֵ���ɸ�
	p1 = &b; //��ȷ ָ��ָ����Ը�

	//2��const���γ��� --ָ�볣��
	int* const p2 = &a;
	//�ص㣺ָ���ָ�򲻿ɸģ���ָ��ָ���ֵ���Ը�
	*p2 = 20; //��ȷ��ָ���ֵ���Ը�
	//p = &b; error!!!ָ��ָ�򲻿ɸ�

	//3��const������ָ�룬�����γ���
	const int* const p3 = &a;
	//�ص㣺ָ��ָ���ָ��ָ���ֵ�������Ը�
	//*p3 = 20; //error!!
	//p3 = &b; //error!!!
}

int main02() {
	PointerConst();

	system("pause");
	return 0;
}