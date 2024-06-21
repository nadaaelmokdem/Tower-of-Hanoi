#pragma once
#include <iostream>
#include <string>
#include "Functions.h"


using namespace std;

class Stack
{
private:
    int* stack;
    int top;
    int size;
    string name; // New member variable to store the name

public:
    Stack(int size, const string& stackName);
    ~Stack();
    void push(int value);
    int pop();
    int peek();
    bool is_empty();
    bool is_full();
    void display();
    int get_size();
    int get_top();
	string getName() { return name; } 
};

