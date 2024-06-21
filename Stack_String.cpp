#include "Stack_String.h"

Stack_String::Stack_String(int size, const string& stackName) {
	this->size = size;
	top = -1;
	stack = new string[size];
	name = stackName;
}

Stack_String::~Stack_String() {
	delete[] stack;
}

void Stack_String::push(string value)
{
	if (is_full())
	{
		cout << "Stack is full" << endl;
	}
	else
	{
		top++;
		stack[top] = value;
	}
}

int Stack_String::is_empty()
{
	if (top == -1)
		return 1;
	return 0;
}

int Stack_String::is_full()
{
	if (top == size - 1)
		return 1;
	return 0;
}

string Stack_String::pop()
{
	if (is_empty())
	{
		cout << "Stack is empty" << endl;
		return "";
	}
	else
		return stack[top--];
}

void Stack_String::display() 
{
	if (is_empty())
	{
		Functions::print("Stack is empty\n");
	}
	else
	{
		for (int i = 0; i <= top; i++)
		{
			Functions::print(stack[i] + "\n");
		}
		cout << endl;
	}
}

