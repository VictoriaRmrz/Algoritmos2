// Victoria Ramírez Castro A01640824
//Andrea Valeria Pintor Valencia  A01067424

#include <iostream>
using namespace std;

const int N = 4;
bool findSolution(int maze[N][N], int solution[N][N], int i, int j);

void printMaze(int solution[N][N]){
    for (int i = 0; i < N; i++) {   
        for (int j = 0; j < N; j++) {
            cout << " " << solution[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool solutionMaze(int maze[N][N]){
    int solution[N][N] = { { 0, 0, 0, 0 },
                           { 0, 0, 0, 0 },
                           { 0, 0, 0, 0 },
                           { 0, 0, 0, 0 } };

    if (!findSolution(maze, solution, 0, 0)) {
        cout<<"Can´t find a solution";
        return false;
    }
    cout << "Path taken: " << endl;
    printMaze(solution);
    return true;
}

bool validMove(int maze[N][N], int i, int j){
    if (i >= 0 && i < N && j >= 0 && j < N && maze[i][j] == 1){
        return true;
    }
    return false;
}

bool findSolution(int maze[N][N], int solution[N][N], int i, int j){
    if(i == N-1 && j == N-1 && maze[i][j] == 1){
        solution[i][j] = 1;
        return true;
    } 
    if(validMove(maze, i, j)){
        solution[i][j] = 1;
        if(findSolution(maze, solution, i + 1, j) == true)
            return true;
        if(findSolution(maze, solution, i, j + 1) == true)
            return true;
        
        //solution[i][j] = 0;
        return false;
    }
    return false;
}


void maze(){
  int maze[N][N] =   { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };

    cout << " Labyrinth: " << endl;
    printMaze(maze);

    solutionMaze(maze);
}

int main(){
    maze();
    return 0;
}