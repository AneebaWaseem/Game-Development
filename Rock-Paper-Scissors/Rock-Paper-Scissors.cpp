#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

// Function to map random integers to 'rock', 'paper', or 'scissors'
string choiceOfComputer(int n) {
    string st;
    if (n == 1)
        st = "rock";
    else if (n == 2)
        st = "paper";
    else
        st = "scissors";
    return st;
}

// Function to determine the game outcome
// 0: Draw, 1: Player wins, 2: Computer wins
int win(string st1, string st2) {
    if (st1 == st2)
        return 0;
    if (st1 == "rock" && st2 == "scissors")
        return 1;
    if (st1 == "scissors" && st2 == "paper")
        return 1;
    if (st1 == "paper" && st2 == "rock")
        return 1;
    return 2;
}

int main() {
    srand(time(0));
    string user, computer;
    int again = 1;

    while (again) {
        again = 0;
        int n = rand() % 3 + 1;

        cout << "Enter your choice: ";
        cin >> user;

        cout << "Computer's choice is: ";
        computer = choiceOfComputer(n);
        cout << computer << endl;

        int result = win(user, computer);

        if (result == 1)
            cout << "You won!" << endl;
        else if (result == 2)
            cout << "Computer won!" << endl;
        else {
            if (result == 0)
                cout << "Your choice is the same as the computer's. Play again.";
            else
                cout << "No one won!" << endl;
        }

        if (result == 0)
            again = 1;
        else {    
            cout << "Do you want to play again? (1 for yes and 0 for no): ";
            cin >> again;
        }
    }

    return 0;
}
