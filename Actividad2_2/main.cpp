// Victoria Ramírez Castro A01640824
//Andrea Valeria Pintor Valencia  A01067424

#include <iostream>

using namespace std;
int contador = 0;

void hanoi(int n, char Origen, char Destino, char Aux){ // complejidad O(2^n)
    contador ++;
    if(n == 1){
        cout << "Mueve disco 1 de " << Origen << " a " << Destino << endl;
    }
    else{
        hanoi( n - 1, Origen, Aux, Destino);
        cout << "Mueve disco " << n << " de " << Origen << " a " << Destino << endl;
        hanoi(n - 1, Aux, Destino, Origen);
    }
}

int main(){
   
    hanoi(2, 'A', 'C', 'B');
    cout << "Se itero " << contador << endl;

    return 0;
}