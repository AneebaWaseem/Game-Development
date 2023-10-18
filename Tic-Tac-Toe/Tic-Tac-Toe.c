#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if a move is valid
int isValid(char arr[][3], int i, int j) {
    if (i >= 0 && i < 3 && j >= 0 && j < 3 && arr[i][j] == '-')
        return 1;
    return 0;
}

// Function to take user input and place the mark
void takeInputAndPlace(char arr[][3], char mark) {
    int i, j;
    printf("Enter input Row and column separated by space: ");
    scanf("%d %d", &i, &j);
    
    // Check if the input is valid
    while (isValid(arr, i, j) == 0) {
        printf("Invalid input! Please enter Row and column separated by space: ");
        scanf("%d %d", &i, &j);
    }
    
    arr[i][j] = mark;

    // Display the updated game board
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won
int checkWin(char arr[][3]) {
    // Check all possible win conditions
    if (arr[0][0] != '-' && arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2])
        return 1;

    // Add similar checks for other win conditions...

    return 0;
}

int main() {
    int i, j;
    char arr[3][3], mark;
    srand(time(0));

    // Initialize the game board with empty spaces
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            arr[i][j] = '-';
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    // Loop for the game's 9 turns
    for (i = 0; i < 9; i++) {
        if (i % 2 == 0)
            mark = 'A';
        else
            mark = 'B';

        // Take user input and place the mark on the board
        takeInputAndPlace(arr, mark);

        // Check if a player has won
        if (checkWin(arr) == 1) {
            printf("Congratulations! Player %c won", mark);
            return 0;
        }
    }

    // If no player has won after 9 turns, it's a draw
    printf("Game Draw");
    return 0;
}
