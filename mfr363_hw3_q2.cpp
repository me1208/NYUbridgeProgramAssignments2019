#include <iostream>
using namespace std;
int main() {
    string name;
    int gradYear;
    int currentYear;
    string gradStatus;

    cout << "Please enter your name: ";
    cin>>name;

    cout << "Please enter your graduation year: ";
    cin>>gradYear;

    cout << "Please enter current year: ";
    cin>>currentYear;

    // • Buy	one	get	one	half	off	promotion:	the	lower	price	item	is	half	price.
    if((currentYear+4) < gradYear){
    gradStatus = "not in college yet";
    }
    else if((currentYear + 4) == gradYear){
        gradStatus = "Freshman";
    } else if((currentYear + 3) == gradYear){
        gradStatus = "Sophomore";
    } else if((currentYear + 2) == gradYear){
        gradStatus = "Junior";
    } else if((currentYear + 1) == gradYear){
        gradStatus = "Senior";
    }else if(currentYear >= gradYear){
        gradStatus = "Graduated";
    }

    cout<<name<<", you are a "<<gradStatus<<endl;

    return 0;
}



