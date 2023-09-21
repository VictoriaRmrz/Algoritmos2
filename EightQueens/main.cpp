// Victoria Ramírez Castro A01640824
//Andrea Valeria Pintor Valencia  A01067424
#include <iostream>
#include <vector>

using namespace std;

int N = 8; 
int solution = 0;
vector<int> queens(N); 

/*
This function create a board of N rows and columns. 
The board is create with "." to simulate a slot of the board.
Then it prints a "Q" in the position where a queen could be.
*/
void printBoard() {
    for (int i = 0; i < N; i++) {   
        for (int j = 0; j < N; j++) {
            if (queens[i] == j)
                cout << " Q ";
            else
                cout << " . ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
This function checks if a specific location on the board is available to put a queen in it.
It checks vertical, horizontal and diagonal positions.
It uses a formula explain in wikipedia:
Problema de las ocho reinas - Wikipedia, la enciclopedia libre. (2022). Wikipedia.org. https://es.wikipedia.org/wiki/Problema_de_las_ocho_reinas
*/
bool isAvailable(int row, int col) {
    for(int i = 0; i < row; i++){
        if(queens[i] == col || abs(queens[i] - col) == abs(i - row))
            return false;
    }

    return true;
}

/*
This function, as its name indicates, uses recursiveness to find all posibles solutions to N queens,
if the row review is equal to the number of N, it means it find a posible solution and print it.
Then, uses a for to review all colums, and checks each position to know if its avaliable, 
if its available, it places the queen in the position (row, col), then it moves to the next row.
*/
void findSolution(int row = 0) {
    if (row == N) {
        solution++;
        cout << "Solution: " << solution << endl;
        printBoard();
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isAvailable(row, col)) {
            queens[row] = col; 
            findSolution(row + 1);   
        }
    }
}

int main() {
    findSolution(); 
    return 0;
}
