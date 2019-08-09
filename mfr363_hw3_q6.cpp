#include <iostream>
#include <math.h>
using namespace std;
int main() {
    string weekDay;
    double startTime;
    double callLength;
    double cost;

    cout<<"Please enter the day of the week (as one of the following: Mo, Tu, We, Th, Fr, Sa, Su): ";
    cin>>weekDay;

    cout<<"Please enter the time your call started (in 24-hour notation): ";
    cin>>startTime;

    cout<<"Please enter the length of your call: ";
    cin>>callLength;

    if((weekDay != "Su" && weekDay != "Sa") && (startTime >= 8 && startTime < 18)){
        cost =callLength*.40;
    }
    else if((weekDay != "Su" && weekDay != "Sa") && (startTime < 8 || startTime > 18)){
        cost =callLength*.25;
    }
    else if(weekDay == "Su" || weekDay == "Sa"){
        cost =callLength*.15;
    }

    cout<<"The cost of your call is: $"<<cost;

    return 0;
}



