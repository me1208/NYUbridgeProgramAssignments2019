#include <iostream>
using namespace std;

int main() {
    int quarters, dimes, nickels, pennies, totalDollars, totalCents, resultingCents;

    cout << "Please enter number of coins:" <<endl;
    cout << "# of quarters:";
    cin>>quarters;

    cout << "# of dimes:";
    cin>>dimes;

    cout << "# of nickles:";
    cin>>nickels;

    cout << "# of pennies:";
    cin>>pennies;

    totalCents = quarters*25 + dimes*10 + nickels*5 + pennies*1;
    totalDollars = totalCents/100;
    resultingCents = totalCents%100;

    cout <<"The total is "<<totalDollars<<" dollars and "<<resultingCents<< " cents"<<endl;

    return 0;
}