#pragma once
#include <iostream>
using namespace std;

#define Max 1000

struct Contact {
	int idx = 0;
	string name;
	string gender;
	int age = 0;
	string phone;
	string address;
};

void addContact(Contact* p, int& num);
void showContact(Contact* p, int num);
void deleteContact(Contact* p, int& num);
void seekContact(Contact* p, int num);
void alterContact(Contact* p, int num);
void clearContact(Contact* p, int& num);