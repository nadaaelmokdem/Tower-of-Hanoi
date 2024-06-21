#pragma once
#include<iostream>
#include<string>
#include"Functions.h"

using namespace std;

class Stack_String
{
private:
	int size;
	int top;
	string* stack;
	string name;

public:
	Stack_String(int size, const string& stackName);
	~Stack_String();
	void push(string value);
	string pop();
	int is_empty();
	int is_full();
	void display();
	string getName() {return name;}
};

