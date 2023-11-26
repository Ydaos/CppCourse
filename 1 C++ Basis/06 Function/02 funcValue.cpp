#include <iostream>

/*
* �����ķ��ļ���д
* 1������ .h��׺����ͷ�ļ�
* 2������ .cpp��׺����Դ�ļ�
* 3����ͷ�ļ���д��������
* 4����Դ�ļ���д��������
* 
* ��������������ǰ���߱�������������
* �������Զ�Σ�������ֻ����һ��
*/

void swap(int num1, int num2);
void swap(int num1, int num2);

void swap2(int& num1, int& num2);
void PrintArr(int(&arr)[6]);
void PrintArr2(int arr[6]);


//��������ʱ��ֵ���ݹ���
void funcCall() {
	int a = 10;
	int b = 20;

	//����ֵ���ݣ��βη����ı䲻��Ӱ��ʵ��
	swap(a, b);
	std::cout << "a = " << a << " b = " << b << std::endl;

	//������ַ���ݣ�ʵ��ֵ��ı�
	swap2(a, b);
	std::cout << "a = " << a << " b = " << b << std::endl;

	//��������Ϊ���飬����Ϊ��ַ����
	int arr[6] = { 1,2,3,4,5,6 };
	for (int i = 0; i < 6; i++) {
		std::cout << &arr[i] << std::endl;
	}
	PrintArr(arr);
	PrintArr2(arr);

	/*
	* ������ӡ���麯�����β��죺
	* 1��(&arr)���������������ַ���ʵ��Կ��Կ��������Ա��ֵ��
	* 2��arr[6]��*arr ������������Ԫ�ص�ַ���ʵ���ֻ�ܿ�����һ��ֵ��
	* 3�������ڴ�ռ�������ֻҪ���׵�ַ���ܵ����õ����������ֵ��
	*/
}

void swap(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void swap2(int& num1, int& num2) //&���÷�
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void PrintArr(int(&arr)[6])
{
	std::cout << "\ntest1\n";
	for (int i = 0; i < 6; i++) {
		std::cout << &arr[i] << "--" << arr + i << std::endl; //�ȼ�
	}
}

void PrintArr2(int arr[6])
{
	std::cout << "\ntest2\n";
	std::cout << (&arr)[0] << std::endl;
	std::cout << (&arr)[1] << std::endl;
	//���ϸ���ַ��24����Ϊ����arrռ24�ֽڣ�֤��(&arr)��ӡ���������ַ
}

int main() {
	funcCall();

	system("pause");
	return 0;
}