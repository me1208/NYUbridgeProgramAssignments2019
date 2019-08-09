#include <iostream>
using namespace std;

int main() {
    long int input;
    long int counter;
    long int I, V, X, L, C, D, M;
    string nRomanNumeral;
    
    
    cout<<"Enter decimal number:"<<endl;
    cin>>input;
    
    // assign input to n to preserve original input
    long int inputRemainder = input;
    
    while(inputRemainder != 0) {
        // check for roman numeral M (1000)
        if (inputRemainder >= 1000) {
            M = inputRemainder / 1000;
            inputRemainder = inputRemainder - (M * 1000);
            
            for (counter = 1; counter <= M; counter++) {
                nRomanNumeral = nRomanNumeral + "M";
            }
        }
        // check remaining input value for roman numeral D (500)
        else if (inputRemainder < 1000 && inputRemainder >= 500) {
            D = inputRemainder / 500;
            inputRemainder = inputRemainder - (D * 500);
            
            for (counter = 1; counter <= D; counter++) {
                nRomanNumeral = nRomanNumeral + "D";
            }
        }
        // check remaining input value for roman numeral C (100)
        else if (inputRemainder < 500 && inputRemainder >= 100){
            C = inputRemainder / 100;
            inputRemainder = inputRemainder - (C * 100);
            
            for(counter = 1; counter <= C; counter++){
                nRomanNumeral = nRomanNumeral + "C";
            }
        }
        // check remaining input value for roman numeral L (50)
        else if (inputRemainder < 100 && inputRemainder >= 50){
            L = inputRemainder / 50;
            inputRemainder = inputRemainder - (L * 50);
            
            for(counter = 1; counter <= L; counter++){
                nRomanNumeral = nRomanNumeral + "L";
            }
        }
        // check remaining input value for roman numeral X (10)
        else if (inputRemainder < 50 && inputRemainder >= 10){
            X = inputRemainder / 10;
            inputRemainder = inputRemainder - (X * 10);
            
            for(counter = 1; counter <= X; counter++){
                nRomanNumeral = nRomanNumeral + "X";
            }
        }
        // check remaining input value for roman numeral V (5)
        else if (inputRemainder < 10 && inputRemainder >= 5){
            V = inputRemainder / 5;
            inputRemainder = inputRemainder - (V * 5);
            
            for(counter = 1; counter <= V; counter++){
                nRomanNumeral = nRomanNumeral + "V";
            }
        }
        // check remaining input value for roman numeral I (1)
        else if (inputRemainder < 5 && inputRemainder >= 1){
            I = inputRemainder / 1;
            inputRemainder = inputRemainder - (I * 1);
            
            for(counter = 1; counter <= I; counter++){
                nRomanNumeral = nRomanNumeral + "I";
            }
        }
    }
    
    cout<<input<<" is "<<nRomanNumeral;
    
    return 0;
}
