#include <iostream>
using namespace std;

int main() {
    int quarters, dimes, nickels, pennies, dollars, cents;
    int centsRemaining;

    cout << "Please enter your amount in the format of dollars and cents separated by a space:" <<endl;
    cin>>dollars >> cents;

    quarters = dollars*4 + cents/25;
    centsRemaining=cents%25;

    dimes = centsRemaining/10;
    centsRemaining=centsRemaining%10;

    nickels = centsRemaining/5;
    centsRemaining = centsRemaining%5;

    pennies = centsRemaining/1;

    cout <<dollars<<" dollars and "<<cents<< " cents are: \n" <<quarters<< " quarters, " <<dimes<< " dimes, " <<nickels<< " nickles and " <<pennies<< " pennies"<<endl;

    return 0;
}
