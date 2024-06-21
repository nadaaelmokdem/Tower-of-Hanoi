#include "Functions.h"

int Functions::printing_speed = 20; // Default printing speed

void Functions::set_printing_speed(int speed) {
	printing_speed = speed;
}

void Functions::wellcome_screen() {
	cout << "\033[32m   /\\		   /\\		   /\\   \n\033[0m"; // Green
	cout << "\033[33m  /  \\		  /  \\		  /  \\  \n\033[0m"; // Yellow
	cout << "\033[94m /____\\		 /____\\		 /____\\  \n\033[0m"; // Bright Blue
	cout << "\033[31m |~~~~|		 |~~~~|		 |~~~~| \n\033[0m"; // Red
	cout << "\033[31m |~~~~|		 |~~~~|		 |~~~~| \n\033[0m";
	cout << "\033[31m |~~~~|		 |~~~~|		 |~~~~| \n\033[0m"; // Red
	cout << "\033[96m ~~~~~~		 ~~~~~~		 ~~~~~~ \n\033[0m"; // Cyan
	print("Welcome to the Tower of Hanoi\n\n\n");
}

void Functions::print(string text) { // Change the color of the text to blue
	for (char c : text) {
		cout << "\033[1m\033[34;3m" << c;
		cout.flush();
		/*
		* cout.flush() is used to flush or clear the output buffer.
		* which means that it prints all the char one by one without waiting for the buffer to fill up.
		*/
		this_thread::sleep_for(chrono::milliseconds(printing_speed)); // Delay between each character
	}
	cout << "\033[0m";
}

void Functions::print_error(string text) { // Change the color of the text to red
	for (char c : text) {
		cout << "\033[1m\033[31;3m" << c;
		cout.flush();
		this_thread::sleep_for(chrono::milliseconds(printing_speed)); // Delay between each character
	}
	cout << "\033[0m";
}

void Functions::print_success(string text) { // Change the color of the text to yellow
	for (char c : text) {
		cout << "\033[1m\033[33;3m" << c;
		cout.flush();
		this_thread::sleep_for(chrono::milliseconds(printing_speed)); // Delay between each character
	}
	cout << "\033[0m";
}

void Functions::print_fast_yellow(string text) { 
	for (char c : text) {
		cout << "\033[1m\033[34;3m" << c;
		cout.flush();
		this_thread::sleep_for(chrono::milliseconds(5)); // Delay between each character
	}
	cout << "\033[0m";

}

void Functions::print_fast_blue(string text) {
	for (char c : text) {
		cout << "\033[1m\033[33;3m" << c;
		cout.flush();
		this_thread::sleep_for(chrono::milliseconds(5)); // Delay between each character
	}
	cout << "\033[0m";
}

// Function to draw a stack
void Functions::draw_stack() {
	print_fast_yellow("                              .+++/     \n");
	print_fast_yellow("                   `.::`       /+++.    \n");
	print_fast_yellow("                  -////.      :+++-     \n");
	print_fast_yellow("                    .////-`    .+++/`   \n");
	print_fast_yellow("                    `:///:`   `/++/.    \n");
	print_fast_yellow("            ..`        -////.   -+++:   \n");
	print_fast_yellow("           :+++:-`      .////:` ./++/`  \n");
	print_fast_yellow("          `-/+++++/-.    `:////.`:++/.  \n");
	print_fast_yellow("             `.:/++++/:.`  -////..:--`  \n");
	print_fast_yellow("                 .-/+++++/-..::.`       \n");
	print_fast_blue("       `:::-..``    `.:/++++-   		 \n");
	print_fast_blue("       -++++++///:--.```.-/-    		 \n");
	print_fast_blue("        `.--:///++++++//::.     		 \n");
	print_fast_blue("`--.          ``..-::///+/``--- 		 \n");
	print_fast_blue("-oo+  -::::----....````... `ooo 		 \n");
	print_fast_blue("-oo+  /+++++++++++++++++/. `ooo 		 \n");
	print_fast_blue("-oo+  ...----::::////+++/` `ooo 		 \n");
	print_fast_blue("-oo+  ```````````````````  `ooo 		 \n");
	print_fast_blue("-oo+  +oooooooooooooooooo- `ooo 		 \n");
	print_fast_blue("-oo+  /++++++++++++++++++. `ooo 		 \n");
	print_fast_blue("-oo+  -::::----....````... `ooo 		 \n");
	print_fast_blue("-oo+  /+++++++++++++++++/. `ooo 		 \n");
	print_fast_blue("-oo+  ...----::::////+++/` `ooo 		 \n");
	print_fast_yellow("-oo+  ```````````````````  `ooo 		 \n");
	print_fast_yellow("-oo+  +oooooooooooooooooo- `ooo 		 \n");
	print_fast_yellow("-oo+  /++++++++++++++++++. `ooo 		 \n");
	print_fast_yellow("-oo+  -::::----....````... `ooo 		 \n");
	print_fast_yellow("-oo+                       `ooo 		 \n");
	print_fast_yellow("-oo+:::::::::::::::::::::::/ooo 		 \n");
	print_fast_yellow("-oooooooooooooooooooooooooooooo 		 \n");
}

// Function to check if the input is an integer
int Functions::check_int() {
	int num;
	while (true) { // Loop indefinitely until valid input
		cin >> num;
		if (cin.fail()) { // Check if input failed
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear error state, discard invalid input
			print_error("Invalid input. Please enter an integer: ");
		} else if (num <= 0) {  // Check if the number is less than or equal to 0
			print_error("Invalid input. Please enter a number greater than 0: ");
		} else {  // Valid input 
			break; // Exit the loop
		}
	}
	return num;
}


//int Functions::check_int(int min, int max) {
//    int input;
//    while (true) {
//        cout << "Enter a number between " << min << " and " << max << ": ";
//        cin >> input;
//
//        if (cin.fail()) {
//            cin.clear();
//            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//            print_error("Invalid input. Please enter a valid number.");
//        }
//        else if (input < min || input > max) {
//            print_error("Input out of range. Please try again.");
//        }
//        else {
//            break; // Valid input
//        }
//    }
//    return input;
//}
