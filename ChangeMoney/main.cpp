//Victoria Ramírez Castro A01640824
//Andrea Valeria Pintor Valencia  A01067424
#include <iostream>
#include <vector>

using namespace std;


int changeMoney(vector<int>& coins, int amountToChange){
    int m = coins.size();
    int temp = 0;
    int j = 0;
    vector<int> F(amountToChange + 1, INT_MAX);

    F[0] = 0;
    for(int i = 1; i <= amountToChange; i++){ 
        temp = INT_MAX;
        j = 1;
        while(j <= m && i >= coins[j - 1]){  //iterates through each coin that is smaller than or equal to the current amount.
            //finds the minimun number between  the available coins in a certain position, and the value of the 
            // temp variable, then, update the temp variable with said number
            temp = min(F[i-coins[j - 1]] + 1, temp); 
            j++;
        }
        //update the value
        F[i] = temp;
    }
    return F[amountToChange];
}

int main(){
    int amountToChange = 11;
    vector<int> coins = {1, 2, 5};

    int result = changeMoney(coins, amountToChange);
    cout << result << endl;

    return 0;
}