#include <iostream>
#include <vector>

using namespace std;

void findSolution(int size, int permutation[], int location,  vector <pair<int,bool>> usedList[]){
    if (location == size){
        for (int i = 0; i < size; i++){
            cout << permutation[i] << " ";
        }
        cout << endl;
    }
    else{
        for (int i = 0; i < size; i++){
            if(usedList[i].second == false){
                
            }
            
        }
    }
}

