#include "Tower_of_Hanoi.h"

// Constructor
Tower_of_Hanoi::Tower_of_Hanoi(int num) : start(num, "start"), end(num, "end"), other(num, "other"), Undo(no_of_moves(num),"Undo") {   // Constructor
    NumberOfDisks = num;
    NumberOfMoves = 0;
    StackFill(start, end, other);
    DisplayAll();
    cout << endl;
    Start_Solve(NumberOfDisks, start, end, other, NumberOfMoves);
}
// Function to move a disk from one tower to another
void Tower_of_Hanoi::Start_Solve(int NumberOfDisks, Stack& start, Stack& end, Stack& other, int& NumberOfMoves) {   // Recursive function to solve the problem
    if (NumberOfDisks == 1) {
        move(start, end);
        NumberOfMoves++;
		string move = "Move disk from tower " + start.getName() + " to tower " + end.getName();
        string undo_move = "Move disk from tower " + end.getName() + " to tower " + start.getName();
		Undo.push(undo_move);
        Functions::print(move);
        cout << endl;
        DisplayAll();
        cout << endl;
        return;
    }
    Start_Solve(NumberOfDisks - 1, start, other, end, NumberOfMoves);
    move(start, end);
    NumberOfMoves++;
    string move = "Move disk from tower " + start.getName() + " to tower " + end.getName();
    string undo_move = "Move disk from tower " + end.getName() + " to tower " + start.getName();
    Undo.push(undo_move);
    Functions::print(move);
    cout << endl;
    DisplayAll();
    cout << endl;
    Start_Solve(NumberOfDisks - 1, other, end, start, NumberOfMoves);
}

// Function to display the state of the towers
void Tower_of_Hanoi::DisplayAll() {     // Display the state of the towers
    Functions::print_success("\nfirst row state now is :\n");
    start.display();
    Functions::print_success("\nSecound row state now is :\n");
    other.display();
    Functions::print_success("\nThird row state now is :\n");
    end.display();
    Functions::print_success("\nNumber of moves now equal: " + to_string(NumberOfMoves));
	cout << endl;
}

// Function to fill the first tower with disks
void Tower_of_Hanoi::StackFill(Stack& start, Stack& end, Stack& other) {   // Fill the first tower with disks
    for (int i = NumberOfDisks; i > 0; i--) {
        start.push(i);
    }
}

// Function to calculate the number of moves needed to solve the problem
int Tower_of_Hanoi::no_of_moves(int disks) {   // Calculate the number of moves needed to solve the problem
	return pow(2, disks) - 1;
}

// Function to Undo the moves
void Tower_of_Hanoi::UndoMoves() {   // Function to Undo the moves
	while (!Undo.is_empty()) {
		string undo_print = Undo.pop()+"\n";
		Functions::print(undo_print);
	}
}
