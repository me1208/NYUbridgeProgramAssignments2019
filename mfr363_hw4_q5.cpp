#include <iostream>
using namespace std;

int main() {
    int numberOfLines = 0;
    int input;
    string asterisks;
    int numberOfastrisks = 0;

    cout<<"Enter a positive integer:" <<endl;
    cin>> input;

    numberOfLines = input * 2;
    numberOfastrisks = numberOfLines - 1;

    for(int counter = 1; counter <= numberOfLines; counter++){
        asterisks = "";
        // find how many asterisks to put in a row
        for(int i = 1; i <= numberOfastrisks; i++){
          asterisks = asterisks + "*";
        }
        // find how many rows to print
        if(counter != 1 && counter != numberOfLines){
            for(int i = 1; i <= (numberOfLines - numberOfastrisks - 1); i++){
                // add buffer whitespace to asterisks to get proper pattern
                if(i % 2 == 0){
                    asterisks = asterisks + " ";
                } else{
                    asterisks = " " + asterisks;
                }
            }
        }

        cout<<asterisks<<endl;

        if (counter < input){
            numberOfastrisks = numberOfastrisks - 2;
        } else if(counter > input){
            numberOfastrisks = numberOfastrisks + 2;
        }
    }

    return 0;
}
