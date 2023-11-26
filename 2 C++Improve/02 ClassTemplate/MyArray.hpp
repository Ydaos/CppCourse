// 自己的通用数组类
#pragma once
#include <iostream>

template<class T>
class MyArray {
public:
	// 有参构造 参数：容量
	MyArray(int capacity) {
		std::cout << "MyArray 有参调用\n";
		this->m_capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[m_capacity];
	}

	// 析构函数
	~MyArray() {
		if (this->pAddress != NULL) {
			std::cout << "MyArray 析构调用\n";
			delete[] pAddress;
			pAddress = NULL;
		}
	}

	// 拷贝构造
	MyArray(const MyArray& arr) {
		std::cout << "MyArray 拷贝调用\n";
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;

		// 深拷贝
		this->pAddress = new T[m_capacity];
		for (int i = 0; i < this->m_size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	// 运算符重载'=',防止浅拷贝问题
	MyArray& operator=(const MyArray& arr) {
		// 先判断原来堆区是否有数据，如果有先释放
		if (this->pAddress != NULL) {
			delete[] pAddress;
			pAddress = NULL;
		}

		// 深拷贝
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[m_capacity];
		for (int i = 0; i < this->m_size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		std::cout << "MyArray = 调用\n";
		return *this;
	}
	
	// 尾插法
	void push_back(const T val) {
		// 先判断容量是否等于大小
		if (this->m_size == this->m_capacity) {
			return;
		}
		this->pAddress[this->m_size] = val;
		this->m_size++;
	}

	// 尾删法
	void pop_back() {
		// 让用户访问不到最后一个元素，即为逻辑删除的尾删；
		if (this->m_size == 0) {
			return;
		}
		this->m_size--;
	}

	// 通过下标访问数组中元素（即重载[]，让自定义的类型可以使用下标寻址）
	// eg: arr[0]; 同时要兼顾左值返回 arr[0] = 100;
	T& operator[](int index) {
		return this->pAddress[index];
	}

	// 返回数组容量
	int getCapacity() {
		return this->m_capacity;
	}

	// 返回数组大小
	int getSize() {
		return this->m_size;
	}

private:
	// 数组
	T* pAddress; //指针指向堆区开辟真实数组

	// 数组容量
	int m_capacity;

	// 数组元素数量
	int m_size;
};