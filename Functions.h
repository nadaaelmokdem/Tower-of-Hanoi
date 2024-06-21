#pragma once
#include<iostream>
#include<string>
#include<thread>
#include<chrono>
//#include <algorithm>

using namespace std;

class Functions {
private:
    static int printing_speed;
public:
    
	static void set_printing_speed(int speed);
	static void wellcome_screen();
    static void print(string text);
	static void print_fast_yellow(string text);
    static void print_fast_blue(string text);
    static void print_error(string text);
    static void print_success(string text);
	static void draw_stack();
    static int check_int();
};

