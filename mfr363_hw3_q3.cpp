#include <iostream>
#include <cmath>
using namespace std;
int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    double a, b, c, numberOfRealSlns, sln1, sln2;

    cout << "Please enter value of a: ";
    cin>>a;

    cout << "Please enter value of b: ";
    cin>>b;

    cout << "Please enter value of c: ";
    cin>>c;


    numberOfRealSlns = ((b*b) - (4*a*c));

    if(a == 0 && b==0 && c==0){
        cout << "Infinite number of solutions";
    } else if(a == 0 && b==0 && c != 0){
        cout << "No solution";
    } else if (a != 0 && b == 0 && c != 0) {
        cout << "No real solution";
    } else if (numberOfRealSlns > 0) {
            sln1 = (-b + sqrt(numberOfRealSlns)*2*a)/(2*a);
            sln2 = (-b - sqrt(numberOfRealSlns)*2*a)/(2*a);
            cout << "This equation has two real solutions x="<<sln1 <<" and x="<<sln2;
    } else if (numberOfRealSlns == 0) {
            sln1 = (-b + sqrt(numberOfRealSlns)*2*a)/(2*a);
            cout<<"This equation has a single real solution x="<<sln1;
    }

    return 0;
}