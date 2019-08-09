#include <iostream>
using namespace std;
int main() {
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

    double inputRealNumber;
    double output;
    int inputMethod;

    cout<<"Please enter a real number: "<<endl;
    cin>>inputRealNumber;

    cout<<"Choose your rounding method: "
          "\n1.Floor round "
          "\n2.Ceiling round "
          "\n3.Round to the nearest whole number"<<endl;
    cin>>inputMethod;

    switch(inputMethod){
        case FLOOR_ROUND:
            // round down to nearest integer
            output = int(inputRealNumber);
            break;
        case CEILING_ROUND:
            // round up to nearest integer
            output = inputRealNumber - (int)inputRealNumber;
            if(output > 0){
                output = (int)inputRealNumber + 1;
            }
            break;
        case ROUND:
            output = inputRealNumber - (int)inputRealNumber;
            if(output >= .5){
                output = (int)inputRealNumber + 1;
            } else if(output < .5){
                output = (int)inputRealNumber;
            }
            break;
        default:
            break;
    }

    cout<<output;

    return 0;
}



