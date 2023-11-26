// �Լ���ͨ��������
#pragma once
#include <iostream>

template<class T>
class MyArray {
public:
	// �вι��� ����������
	MyArray(int capacity) {
		std::cout << "MyArray �вε���\n";
		this->m_capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[m_capacity];
	}

	// ��������
	~MyArray() {
		if (this->pAddress != NULL) {
			std::cout << "MyArray ��������\n";
			delete[] pAddress;
			pAddress = NULL;
		}
	}

	// ��������
	MyArray(const MyArray& arr) {
		std::cout << "MyArray ��������\n";
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;

		// ���
		this->pAddress = new T[m_capacity];
		for (int i = 0; i < this->m_size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	// ���������'=',��ֹǳ��������
	MyArray& operator=(const MyArray& arr) {
		// ���ж�ԭ�������Ƿ������ݣ���������ͷ�
		if (this->pAddress != NULL) {
			delete[] pAddress;
			pAddress = NULL;
		}

		// ���
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[m_capacity];
		for (int i = 0; i < this->m_size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		std::cout << "MyArray = ����\n";
		return *this;
	}
	
	// β�巨
	void push_back(const T val) {
		// ���ж������Ƿ���ڴ�С
		if (this->m_size == this->m_capacity) {
			return;
		}
		this->pAddress[this->m_size] = val;
		this->m_size++;
	}

	// βɾ��
	void pop_back() {
		// ���û����ʲ������һ��Ԫ�أ���Ϊ�߼�ɾ����βɾ��
		if (this->m_size == 0) {
			return;
		}
		this->m_size--;
	}

	// ͨ���±����������Ԫ�أ�������[]�����Զ�������Ϳ���ʹ���±�Ѱַ��
	// eg: arr[0]; ͬʱҪ�����ֵ���� arr[0] = 100;
	T& operator[](int index) {
		return this->pAddress[index];
	}

	// ������������
	int getCapacity() {
		return this->m_capacity;
	}

	// ���������С
	int getSize() {
		return this->m_size;
	}

private:
	// ����
	T* pAddress; //ָ��ָ�����������ʵ����

	// ��������
	int m_capacity;

	// ����Ԫ������
	int m_size;
};