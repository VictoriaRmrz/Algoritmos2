// Victoria Ramírez Castro A01640824
//Andrea Valeria Pintor Valencia  A01067424
#include <iostream>

using namespace std;

int contador = 0;

void hanoi(int n, char inicio, char aux, char final) { // Complejidad O(3^n)
    contador++;
    if (n == 1) {
        cout << "Mueve diso 1 de " << inicio << " a " << aux << endl;
        cout << "Mueve disco 1 de " << aux << " a " << final << endl;
        contador++;
        return;
    }
    hanoi(n - 1, inicio, aux, final);
    cout << "Mueve disco " << n << " de " << inicio << " a " << aux << endl;
    hanoi(n - 1, final, aux, inicio);
    cout << "Mueve disco " << n << " de " << aux << " a " << final << endl;
    hanoi(n - 1, inicio, aux, final);
    contador++;
}

int main() {
    hanoi(3, 'A', 'B', 'C');
    cout << "Numero de movimientos: " << contador << endl;

    return 0;
}
