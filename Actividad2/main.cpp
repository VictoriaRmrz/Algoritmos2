// Victoria Ramírez Castro A01640824
//Andrea Valeria Pintor Valencia  A01067424

#include <iostream>

using namespace std;
int contador = 0;

void hanoi(int n, int A, int C, int B){ // complejidad O(2^n)
    contador ++;
    if(n == 1){
        cout << "Mueve " << A << " a " << C << endl;
    }
    else{
        hanoi( n - 1, A, B, C);
        cout << "Mueve " << A << " a " << C << endl;
        hanoi(n - 1, B, C, A);
    }
}

int main(){
   
    hanoi(2, 1, 3, 2);
    cout << "Se itero " << contador << endl;

    return 0;
}