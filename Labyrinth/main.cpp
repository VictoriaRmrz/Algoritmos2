// Victoria Ramírez Castro A01640824
//Andrea Valeria Pintor Valencia  A01067424

#include <iostream>
using namespace std;

const int N = 10; // Declaration of the lenght of the maze
bool findSolution(int maze[N][N], int solution[N][N], int i, int j);

/*
This function print the maze matrix and the solution matrix,
and to be easier to appreciate the maze and the path taken, 
the parts where you are allow to "step" are mark with an "X", 
and the walls are symbolize with an "#"
*/
void printMaze(int solution[N][N]){
    for (int i = 0; i < N; i++) {   
        for (int j = 0; j < N; j++) {
            if(solution[i][j] == 1)
                cout << " X ";
            else
                cout << " | ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
In this function, the matrix solution is create in 0´s
and the function findSolution is called, if it returns false,
it means that there is no solution, if it returns true,
it means that there is a solution and it prints the path taken.
*/
bool solutionMaze(int maze[N][N]){
    int solution[N][N] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};

    if (!findSolution(maze, solution, 0, 0)) {
        cout<<"Can´t find a solution";
        return false;
    }
    cout << "Path taken: " << endl;
    printMaze(solution);
    return true;
}

/*
Here, we check if the number of steps you want to take is within the range 
of the size of the matrix, and if the position you want to move is "path" or "wall" 
*/
bool validMove(int maze[N][N], int i, int j){
    if (i >= 0 && i < N && j >= 0 && j < N && maze[i][j] == 1){
        return true;
    }
    return false;
}

/*
Here, we use backtracking to solve the maze
*/
bool findSolution(int maze[N][N], int solution[N][N], int i, int j){
    /*
    first, we create the base case, where you already are in a valid position of the maze
    and put a "1" in that position of our solution matrix
    */
    if(i == N-1 && j == N-1 && maze[i][j] == 1){
        solution[i][j] = 1;
        return true;
    } 
    /*then, we check if the move you want to take is valid, and if it is, 
    we use recursivity to call again the function to check the next position,
    if is a valid move, mark "1" in the solution matrix.
    */
    if(validMove(maze, i, j)){
        if(findSolution(maze, solution, i + 1, j)){
            solution[i][j] = 1;
            return true;
        }
        if(findSolution(maze, solution, i, j + 1)){
            solution[i][j] = 1;
            return true;
        }
        return false;
    }
    return false;
}

/*
This function create the maze with 1´s and 0´s, and print it,
then it calls the function solutionMaze, where a path to solve the
labyrinth is generated.
*/
void maze(){
  int maze[N][N] =   { { 1, 0, 1, 0, 0, 1, 1, 0, 0, 0 },
                       { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
                       { 0, 1, 1, 1, 1, 0, 0, 1, 0, 0 },
                       { 1, 1, 1, 1, 0, 0, 0, 1, 0, 0 },
                       { 1, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
                       { 0, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
                       { 1, 0, 0, 1, 0, 1, 1, 1, 1, 0 },
                       { 0, 0, 1, 1, 1, 0, 0, 0, 1, 1 },
                       { 0, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
                       { 1, 1, 1, 1, 0, 0, 0, 1, 0, 1 }, };

    cout << " Labyrinth: " << endl;
    printMaze(maze);

    solutionMaze(maze);
}

int main(){
    maze();
    return 0;
}