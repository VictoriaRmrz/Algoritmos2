#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;

//Programa que lee numero en hexadecimal de unsigned char, lo convnierte a string
// y lo convierte  a decimal
#include <iostream>

int main() {
    unsigned char mychar[] = {0x55, 0x58, 0x16, 0x01, 0x19, 0x10, 0x09};
    int size = sizeof(mychar) / sizeof(mychar[0]);
    int decimal = 0;
    //int charToInt [] = {0,0,0,0,0,0,0};
    string intToString [] = {" ", " ", " ", " ", " ", " ", " "};

    for (int i = 0; i < size; i++) {
        decimal = static_cast<unsigned int>(mychar[i]);
        intToString[i] = to_string(decimal);
    }

    for(int i = 0; i < size; i++){
        cout << intToString[i] << endl;
    }
   
    return 0;
}
