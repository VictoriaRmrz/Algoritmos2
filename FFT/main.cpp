#include <iostream>
#include <complex>
#include <cmath>
#include <vector>

using namespace std;

typedef complex<double> Complex;

void fft(vector<Complex>& x) {
    int n = x.size();
    if (n <= 1) return;  
    
    vector<Complex> even(n / 2);
    vector<Complex> odd(n / 2);
    
    for (int i = 0; i < n / 2; i++) {
        even[i] = x[i * 2];
        odd[i] = x[i * 2 + 1];
    }
    
    fft(even);
    fft(odd);
    
    double angle = 2 * 3.1416 / n;
    Complex w(1);
    Complex wn(cos(angle), sin(angle));

    for (int i = 0; i < n / 2; i++) {
        Complex temp = w * odd[i];
        x[i] = even[i] + temp;
        x[i + n / 2] = even[i] - temp;
        w *= wn; // recorre el circulo unitario
    }
}

int main() {
    vector<Complex> x = {3,2}; 
    int n = x.size();
    
    fft(x);
    
    cout << "FFT output: ";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    
    return 0;
}
