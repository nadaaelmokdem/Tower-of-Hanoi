#include <iostream>
#include <windows.h> // Add this header for clear screen
#include <conio.h> // Add this header for _getch() function
#include "Functions.h"
#include "Tower_of_Hanoi.h"

using namespace std;

int main() {
	Functions::wellcome_screen(); 
	Functions::print("press any key to continue..."); 
	_getch(); // Wait for a key press
	system("cls"); // Clear the screen

	Functions::print("Please enter the printing speed (in milliseconds): ");
	int speed = Functions::check_int(); 
	Functions::set_printing_speed(speed);
	system("cls");


	while (true) {   // Loop to play the game again
        Functions::print("Enter the number of disks: ");
        int num = Functions::check_int();
		Tower_of_Hanoi game(num); // Create an object of the Tower_of_Hanoi class
		cout << endl;
        Functions::print("press any key to continue..."); 
        _getch();
        system("cls");

		Functions::print("Press Z to undo the towers or Press other key to clear the screen\n\n");
		char choice = _getch();
		if (choice == 'Z' || choice == 'z') {   // Undo the moves
			game.UndoMoves();
			Functions::print("\n\nPress any key to continue...\n\n");
		}
		_getch(); 
		system("cls");

        Functions::print("Press N to exit or press other to stay\n\n");
        char choice2 = _getch();

		if (choice2 == 'N' || choice2 == 'n') {
			Functions::print("\n");
			Functions::print("\nTake a moment to observe a stack being constructed before you leave.;)\n");
			Functions::draw_stack();
			Functions::print("\npress any key to continue...");
			_getch();
			system("cls");

			Functions::print_success("\n\nMade by  \n\n");
			Functions::Functions::print_success("Anas Ahmed	        192200122\n");
			Functions::Functions::print_success("Hesham Mahmoud		192200154\n");
			Functions::Functions::print_success("Nada Elmokdem		192200252\n");
			Functions::Functions::print_success("Elsayed Rezkallah	192200207\n");
			Functions::Functions::print_success("Hend Elhout		192300146\n");
			break;
        }
    }
	return 0;
}
