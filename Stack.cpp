#include "Stack.h"

Stack::Stack(int size, const string& stackName) : size(size), top(-1), name(stackName)
{
	stack = new int[size];
}

Stack::~Stack()
{
	delete[] stack;
}

void Stack::push(int value)
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

int Stack::pop()
{
	if (is_empty())
	{
		cout << "Stack is empty" << endl;
		return -1;
	}
	else
	{
		int value = stack[top];
		top--;
		return value;
	}
}

int Stack::peek()
{
	if (is_empty())
	{
		cout << "Tower is empty" << endl;
		return -1;
	}
	else
	{
		return stack[top];
	}
}

bool Stack::is_empty()
{
	return top == -1;
}

bool Stack::is_full()
{
	return top == size - 1;
}

void Stack::display() // Display the state of the towers using '#' and '||'
{
    if (is_empty())
    {
        for (int i = 0; i < size; i++)
        {
            Functions::print_success("||");
            cout << endl;
        }
    }
    else
    {
        for (int i = top; i >=0; i--)
        {
            for (int j = stack[i]; j > 0; j--) 
            {
                Functions::print_success("#");
            }
            cout << endl;
        }
        cout << endl;
    }
}

int Stack::get_size() // Return the size of the tower
{
	return size;
}

int Stack::get_top()
{
	return top;
}

