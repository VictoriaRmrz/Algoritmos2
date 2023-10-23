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
    void dijkstra(int, int);
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
void Graph::addEdge(int nodeA, int nodeB, int weight) {
    adjLists[nodeA].push_back(nodeB);
    adjMatrix[nodeA][nodeB] = weight;
}

/*
To print the graph and see how each is conected
*/
void Graph::printGraph() {
    for (int i = 0; i < numNode; i++) {
        cout << "\nNode " << i << ":";
        for (auto x : adjLists[i])
            cout << "->" << x;
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
        cout << " " << k;
    }
    cout << endl << "   ___________________" << endl;
    for (int i = 0; i < numNode; i++) {
        cout << i << "| ";
        for (int j = 0; j < numNode; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
This function uses the  dijkstra algorithm to find the shortest path in a graph
using the weights of its connections to calculate the cost to go from one node to another.
*/
void Graph::dijkstra(int start, int target) {
    vector<int> distances(numNode, INT_MAX); // vector with a size of the number of nodes in the graph, initialize with a big number
    vector<int> path(numNode, -1); // vector with a size of the number of nodes in the graph, initialize with -1
    distances[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> weightedGraph; // priority queue using meanheap, it saves the information like a pair
    weightedGraph.push(make_pair(0, start)); //(distance, node)
   
    while(!weightedGraph.empty()){
        int node = weightedGraph.top().second; // obtain the node
        weightedGraph.pop(); // delete the smallest element fo the queue
        for(auto neighbor: adjLists[node]){ // checks the neighbors of the node
            if(distances[neighbor] > distances[node] + adjMatrix[node][neighbor]){
                distances[neighbor] = distances[node] + adjMatrix[node][neighbor]; // actualize the new distance to that node
                path[neighbor] = node; // to save the path taken
                weightedGraph.push(make_pair(distances[neighbor], neighbor)); // add the element to the queu
            }
        }
    }

    for(int i = 0; i < numNode; i++){
        if(distances[i] == INT_MAX){
            cout << "You cannot move from " << start << " to " << i << endl;
            continue;
        }else
            cout << "Distance from " << start << " to " << i << " is " << distances[i] << endl;
    }

    if(distances[target] == INT_MAX){
        cout << "\nThere is no path from " << start << " to " << target << endl;
        return;
    }else{
        cout << "\n\nPath from " << start << " to " << target << ": ";
        int node = target;
        while(node != start){ //using backtracking to print the shortest path to a target node
            cout << node << " <- ";
            node = path[node];
        }
        cout << start << endl;
    }
    
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

    G.dijkstra(1,  0);
    return 0;
}
