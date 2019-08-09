#include <iostream>
using namespace std;

int main() {
    int n;
    int nEvenNumber;
    int counter;

    // section a: a while loop that prints first n even #s
    cout<<"section a"<<endl;
    cout<<"Please enter a positive integer:";
    cin>> n;

    nEvenNumber = 0;
    counter = 1;

    while(counter <= n){
        nEvenNumber = nEvenNumber + 2;
        cout<<nEvenNumber<<endl;
        counter++;
    }

    // section b: a for loop that prints first n even #s
    cout<<"section b"<<endl;
    cout<<"Please enter a positive integer:";
    cin>> n;

    nEvenNumber = 0;

    for(counter = 1; counter <= n; counter++){
        nEvenNumber = nEvenNumber + 2;
        cout<<nEvenNumber<<endl;
    }

    return 0;
}
