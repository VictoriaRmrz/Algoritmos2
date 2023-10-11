// Victoria Ramírez Castro A01640824
//Andrea Valeria Pintor Valencia  A01067424
#include <iostream>
#include <list>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

/*
We create a class to represent the graph that we are going to create.
We stablish who it is going to store the nodes and declare all of its functions
*/
class Graph {
private:
    int numNode;
    list<int> *adjLists;
    bool **adjMatrix;

public:
    Graph(int v) {
        numNode = v;
        adjLists = new list<int>[v];
        adjMatrix = new bool*[v];
        for (int i = 0; i < numNode; i++) {
            adjMatrix[i] = new bool[numNode];
            for (int j = 0; j < numNode; j++) {
                adjMatrix[i][j] = false;
            }
        }
    }
    ~Graph() {
        delete[] adjLists;
    }
    void addEdge(int, int);
    void printGraph();
    int DFS(int, int, bool *);
    int BFS(int, int);
    bool isConex();
    bool IDS(int, int, int);
    bool* createEmptyList();
    void printMatrix();
};

/*
We use this function to create a array of N nodes, and put all of them in false,
to stablish that the nodes haven´t been visited
*/
bool* Graph::createEmptyList() {
    bool *visited = new bool[numNode];
    for (int i = 0; i < numNode; i++) {
        visited[i] = false;
    }
    return visited;
}

/*
This function is to create the conections between the nodes
*/
void Graph::addEdge(int nodeA, int nodeB) {
    adjLists[nodeA].push_back(nodeB);
    adjLists[nodeB].push_back(nodeA); 
    adjMatrix[nodeA][nodeB] = true;
    adjMatrix[nodeB][nodeA] = true; 
}

/*
To print the graph and see how each is conected
*/
void Graph::printGraph() {
    for (int i = 0; i < numNode; i++) {
        cout << "\nNode " << i+1 << ":";
        for (auto x : adjLists[i])
            cout << "->" << x+1;
        cout << endl;
    }
    cout << endl;
}

/*
To visualize the conections between the nodes, but in the matrix
*/
void Graph::printMatrix() {
    cout << "  ";
    for (int k = 0; k < numNode; k++) {
        cout << " " << k+1;
    }
    cout << endl << "   ___________________" << endl;
    for (int i = 0; i < numNode; i++) {
        cout << i+1 << "| ";
        for (int j = 0; j < numNode; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
We will use this function to go through the graph to search a node (by depth)
and mark it as visited. If we find any unvisited node, we'll call this function recursively
until all nodes are visited.
And use the variable "contador" to count if all of the nodes where visited
*/
int Graph::DFS(int Node, int contador, bool *visited) {
    visited[Node] = true; 
    contador ++;

    for (auto i : adjLists[Node]) {
        if (!visited[i]) {
            contador = DFS(i, contador, visited);
        }
    }

    return contador;
}

/*
We will use this function to go through the graph to search a node (by amplitude)
and mark it as visited. We create a queue to push back the visited nodes.
And use the variable "contador" to count if all of the nodes where visited
*/
int Graph::BFS(int startNode, int contador) {
    bool *visited = createEmptyList();
    visited[startNode] = true;
    list<int> queue;
    queue.push_back(startNode);
    contador ++;
    while (!queue.empty()) {
        int currentNode = queue.front();
        queue.pop_front();
        for (auto i : adjLists[currentNode]) {
            if (!visited[i]) {
                contador ++;
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
    return contador;
}

/*
IDS use the DFS method to search a node, but with a depth limit
*/
bool Graph::IDS(int source, int target, int max_depth) {
    bool *visited = createEmptyList();
    if (max_depth < 0)
        return false;

    visited[source] = true;

    if (source == target)
        return true;

    for (auto i : adjLists[source]) {
        if (!visited[i]) {
            if (IDS(i, target, max_depth - 1))
                return true;
        }
    }

    return false;
}

/*
Using both DFS and BFS, we will see if the given graph is conex or not.
If all of its nodes are connected by a path, the graph is conex.
*/
bool Graph::isConex() {
    bool *visited = createEmptyList();
    return (DFS(0,0, visited) == numNode || BFS(0,0) == numNode );
}

int main() {
    // Create a random graph with nodes between 5 to 1000 
    srand(time(NULL));
    int nodes = 5 + rand() % (1001-5);
    Graph G(nodes);
    srand((unsigned)time(NULL));
    float randomConnection = 0.0;
    int target = 5, maxDepth = 1, source = 0;

    /*Create randoms number between 0 to 1, if the number is more than 0.5
    we  create a connection between two nodes. The matrix generated will be
    symmetrical
    */
    for (int i = 0; i < nodes; i++) {
        for (int j = i; j < nodes; j++) {
            if (i != j) {
                randomConnection = (float)rand() / RAND_MAX;
                if (randomConnection > 0.5) {
                    G.addEdge(i, j);
                }
            }
        }
    }

    cout << "A graph with " << nodes << " was created." << endl;

    //G.printMatrix();
    //G.printGraph();

    // Since the source node, search the target node but with a certain limit depth
    if (G.IDS(source, target, maxDepth))
        cout << "\nYou can reach node " << target << " within the max depth of " << maxDepth << endl;
    else
        cout << "\nYou cannot reach node " << target << " within the max depth of " << maxDepth << endl;

    // Analize if the graph created is conex or not
    if (G.isConex())
        cout << "\nThe graph is convex." << endl;
    else
        cout << "\nThe graph is not convex." << endl;


    return 0;
}
