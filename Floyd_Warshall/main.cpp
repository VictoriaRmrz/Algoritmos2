// Victoria Ramírez Castro A01640824
//Andrea Valeria Pintor Valencia  A01067424
#include <iostream>
#include <list>
#include <vector>
#include <climits> 

using namespace std;

class Graph {
private:
    int numNode;
    list<int> *adjLists;
    int **adjMatrix;

public:
    Graph(int v) {
        numNode = v;
        adjLists = new list<int>[v];
        adjMatrix = new int*[v];
        for (int i = 0; i < numNode; i++) {
            adjMatrix[i] = new int[numNode];
            for (int j = 0; j < numNode; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    ~Graph() {
        delete[] adjLists;
    }

    void addEdge(int, int, int);
    void printGraph();
    bool* createEmptyList();
    void printMatrix();
    void floydWarshall();
    void printfloydMatrix(int**); 

};

bool* Graph::createEmptyList() {
    bool *visited = new bool[numNode];
    for (int i = 0; i < numNode; i++) {
        visited[i] = false;
    }
    return visited;
}

void Graph::addEdge(int nodeA, int nodeB, int weight) {
    adjLists[nodeA].push_back(nodeB);
    adjMatrix[nodeA][nodeB] = weight;
}

void Graph::printGraph() {
    for (int i = 0; i < numNode; i++) {
        cout << "\nNode " << i << ":";
        for (auto x : adjLists[i])
            cout << "->" << x;
        cout << endl;
    }
    cout << endl;
}

void Graph::printMatrix() {
    cout << "  ";
    for (int k = 0; k < numNode; k++) {
        cout << " " << k;
    }
    cout << endl << "   ___________________" << endl;
    for (int i = 0; i < numNode; i++) {
        cout << i << "| ";
        for (int j = 0; j < numNode; j++) {
            if (adjMatrix[i][j] == 0 && i != j) {
                adjMatrix[i][j] = INT_MAX;
            }
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::printfloydMatrix(int** Matrix) { 
    cout << "  ";
    for (int k = 0; k < numNode; k++) {
        cout << " " << k;
    }
    cout << endl << "   ___________________" << endl;
    for (int i = 0; i < numNode; i++) {
        cout << i << "| ";
        for (int j = 0; j < numNode; j++) {
            if (Matrix[i][j] == 0 && i != j) {
                Matrix[i][j] = INT_MAX;
            }
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
Create a new identic matrix, to use in the Floyd Warshall algorithm
*/
int** createNewMatrix(int &numNode, int** &adjMatrix){
    int** NewMatrix = new int*[numNode];
    for (int i = 0; i < numNode; i++) {
        NewMatrix[i] = new int[numNode];
        for (int j = 0; j < numNode; j++) {
            NewMatrix[i][j] = adjMatrix[i][j];
        }
    }
    return NewMatrix;
}


void Graph::floydWarshall() {
    int** NewMatrix = createNewMatrix(numNode, adjMatrix);

    /*
    Start iterating in New matrix and change the values if the value in the position (i,j) is bigger than 
    the sum of the value in the position (i,k) and (k,j)
    */
    for (int k = 0; k < numNode; k++) {
        for (int i = 0; i < numNode; i++) {
            for (int j = 0; j < numNode; j++) {
                if (NewMatrix[i][j] > (NewMatrix[i][k] + NewMatrix[k][j]) && (NewMatrix[k][j] != INT_MAX && NewMatrix[i][k] != INT_MAX))
                    NewMatrix[i][j] = NewMatrix[i][k] + NewMatrix[k][j];
            }
        }
    }
    printfloydMatrix(NewMatrix);
}

int main() {
    int nodes = 6;
    Graph G(nodes);
    G.addEdge(0,1,8);
    G.addEdge(0,3,7);
    G.addEdge(1,2,10);
    G.addEdge(1,4,12);
    G.addEdge(3,2,14);
    G.addEdge(3,4,11);
    G.addEdge(2,5,9);
    G.addEdge(2,4,6);
    G.addEdge(4,5,5);

    G.printMatrix();

    G.floydWarshall();
    return 0;
}
