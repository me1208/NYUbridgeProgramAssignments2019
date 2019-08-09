#include <iostream>
using namespace std;
int main() {
    int input1, input2;
    int add, subtract, multiply, div, mod;
    double divide;

    cout << "Please enter two positive integers, separated by a space:"<<endl;
    cin>>input1 >> input2;

    add = input1 + input2;
    subtract = input1 - input2;
    multiply = input1 * input2;
    divide = (double)input1 / (double)input2;
    div = input1 / input2;
    mod = input1 % input2;


    cout<<input1<< " + " <<input2<< " = " <<add<<endl;
    cout<<input1<< " - " <<input2<< " = " <<subtract<<endl;
    cout<<input1<< " * " <<input2<< " = " <<multiply<<endl;
    cout<<input1<< " / " <<input2<< " = " <<divide<<endl;
    cout<<input1<< " div " <<input2<< " = " <<div<<endl;
    cout<<input1<< " mod " <<input2<< " = " <<mod<<endl;


    return 0;
}


