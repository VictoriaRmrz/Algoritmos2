//Victoria Ramírez Castro A01640824
//Andrea Valeria Pintor Valencia  A01067424
#include <iostream>
#include <vector>

using namespace std;

//This function checks the best combination of items
//based on its weight and benefit, to achieve the best benefit
//without going over the maximum weight
int Knapsack(vector<pair<int, int>> items, int W) {
    int n = items.size();
    vector<vector<int>> B(n + 1, vector<int>(W + 1, 0));

    //Go through the matrix starting in the position (1,1)
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (items[i - 1].second <= w) { //Checks if the weight of an item is less than the maximun weight
               //Checks the maximun benefit between the benefit of an item or 
               //the previous accumulated benefit 
                B[i][w] = max(items[i - 1].first + B[i - 1][w - items[i - 1].second], B[i - 1][w]);
            } else {
                B[i][w] = B[i - 1][w];
            }
        }
    }

    return B[n][W];
}

int main() {
    vector<pair<int, int>> items;
    items.push_back(make_pair(1,4));  // (benefit, weight) 
    items.push_back(make_pair(2,5));
    items.push_back(make_pair(3,1));

    int W = 4;  //Maximum weight
    cout << "Maximum benefit: " << Knapsack(items, W) << endl;

    return 0;
}
