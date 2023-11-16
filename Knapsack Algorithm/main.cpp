//Victoria Ramírez Castro A01640824
//Andrea Valeria Pintor Valencia  A01067424
#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> B){
    for (int i = 0; i < B.size(); i++) {
        for (int j = 0; j < B[i].size(); j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
}

//This function checks the best combination of items
//based on its weight and benefit, to achieve the best benefit
//without going over the maximum weight
vector<vector<int>> Knapsack(vector<pair<int, int>> items, int W) {
    int n = items.size();
    vector<vector<int>> B(W + 1, vector<int>(n + 1, 0)); 

    //Go through the matrix starting in the position (1,1)
    for(int i = 1; i <= n+1; i++){
        for(int w = 1; w <= W; w++){
            if(items[i-1].second <= w){  //Checks if the weight of an item is less than the maximun weight
               //Checks the maximun benefit between the benefit of an item or 
               //the previous accumulated benefit 
                B[w][i] = max(items[i-1].first + B[w - items[i-1].second][i-1], B[w][i-1]);
            }
            else{
                //If the weight of the item is greater than the maximum weight
                //then we just copy the benefit of the item in the previous row and column
                B[w][i] = B[w][i-1];
            }
        }
    }
    return B;
}

int main() {
    vector<pair<int, int>> items;
    int W = 4;  //Maximum weight
    items.push_back(make_pair(1,4));  // (benefit, weight) 
    items.push_back(make_pair(2,5));
    items.push_back(make_pair(3,1));

    vector<vector<int>> B = Knapsack(items, W);
    printMatrix(B);
    cout << "Maximum benefit: " << B[W][items.size()] << endl;

    return 0;
}
