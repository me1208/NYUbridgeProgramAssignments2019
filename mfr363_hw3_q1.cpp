#include <iostream>
using namespace std;
int main() {
    char hasClubCard;
    long double price1, price2, taxRate, basePrice, discountPrice, totalPrice;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);

    cout << "Enter price of first item: ";
    cin>>price1;

    cout << "Enter price of second item: ";
    cin>>price2;

    cout << "Does customer have a club card? (Y/N): ";
    cin>>hasClubCard;

    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin>>taxRate;

    basePrice = price1 + price2;

    // • Buy	one	get	one	half	off	promotion:	the	lower	price	item	is	half	price.
    if(price1 > price2){
        discountPrice = price1 + (price2*.5);
    } else if (price1 < price2){
        discountPrice = price2 + (price1*.5);
    }
    // • If	the	customer	is	club	card	member,	additional	10%	off.
    if(hasClubCard == 'y' || hasClubCard == 'Y'){
        discountPrice = discountPrice - (discountPrice*.1);
    }

    // • Tax	is	added.
    totalPrice = (discountPrice*(taxRate/100)) + discountPrice;
    cout.precision(1);
    cout<<"Base price: " <<basePrice<<endl;
    cout<<"Price after discounts: " <<discountPrice<<endl;
    cout.precision(5);
    cout<<"Total price: " <<totalPrice<<endl;

    return 0;
}



