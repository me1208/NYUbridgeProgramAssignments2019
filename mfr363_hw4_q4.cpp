#include <iostream>
#include <cmath>
using namespace std;


int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    double sequenceLength;
    double sequenceInput;
    double inputProduct = 1;
    double geoMean;

    cout<<"section a"<<endl;
    cout<<"Please enter the length of the sequence:";
    cin>> sequenceLength;
    cout<<"Please enter your sequence:" <<endl;
    for(int counter = 1; counter <= sequenceLength; counter++){
        cin>> sequenceInput;
        inputProduct = inputProduct*sequenceInput;
    }

    // calculate the geometric mean
    geoMean = pow(inputProduct, 1 / sequenceLength);

    cout.precision(4);
    cout<<"The geometric mean is: "<<geoMean<<endl;

    cout<<"section b"<<endl;
    cout<<"Please enter a non-empty sequence of positive integers, "
          "each one in a separate line. End your sequence by typing -1:" <<endl;
    while(-1 != sequenceInput){
        cin>> sequenceInput;
        if(sequenceInput != -1){
            sequenceLength = sequenceLength + 1;
            inputProduct = inputProduct*sequenceInput;
        }
    }

    // calculate the geometric mean
    geoMean = pow(inputProduct, 1 / sequenceLength);

    cout<<"The geometric mean is: "<<geoMean<<endl;

    return 0;
}
