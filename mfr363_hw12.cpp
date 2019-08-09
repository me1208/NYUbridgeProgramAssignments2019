#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>
using namespace std;

class Money {
public:
	Money();
	Money(long dollars, int cents);
	Money(long dollars);
	double get_value() const;
	friend istream& operator >>(istream& ins, Money& amount);
	friend ostream& operator <<(ostream& outs, Money& amount);

private:
	long all_cents;
};

Money::Money() :all_cents(0) {}
Money::Money(long dollars) : all_cents(dollars*.01){}
Money::Money(long dollars, int cents) {
	all_cents = dollars * .01 + cents;
}

istream& operator >>(istream& ins, Money& amount){
	long dollars;
	int cents;
	double input1;

	ins >> input1;
	dollars = (int)input1;
	cents = input1 - dollars;
	amount.all_cents = (dollars * 100) + cents;

	return ins;
};
ostream& operator <<(ostream& outs, Money& amount){
	long dollars;
	int cents;
	outs << dollars << "." << cents;
	return outs;
}

double Money::get_value() const {
	return (all_cents * .01);
}

class Check {
	int number;
	Money amount;
	bool isCashed;
public:
	Check();
	Check(int num, Money amnt, bool isCash);

	friend istream& operator >>(istream& ins, Check& check);
	friend ostream& operator <<(ostream& outs, Check& check);

	void setNumber(int num);
	void setAmount(Money amnt);
	void setIsCashed(bool isCash);

	int getNumber();
	Money getAmount();
	bool getIsCashed();

};

int Check::getNumber() {
	return this->number;
}
Money Check::getAmount() {
	return this->amount;
}
bool Check::getIsCashed(){
	return  this->isCashed;
}
void Check::setNumber(int num){
	this->number = num;
}
void Check::setAmount(Money amnt){
	this->amount = amnt;
}
void Check::setIsCashed(bool isCash){
	this->isCashed = isCash;
}

Check::Check() :number(0), amount(), isCashed(false) {}
Check::Check(int num, Money amnt, bool isCash){
	this->number = num;
	this->amount = amnt;
	this->isCashed = isCash;
}

ostream& operator <<(ostream& outs, Check& check){
	outs << "Check #" << check.number << "\t\t\t\t\t\t" << (check.getAmount()).get_value();
	if(check.isCashed){
		outs << " (cashed)" << endl;
	} else{
		outs << " (not cashed)" << endl;
	}
	return outs;
}

istream& operator >>(istream& ins, Check& check){
	int num;
	double amnt;
	bool isCash;
	check.number = num;
	check.amount = amnt;
	check.isCashed = isCash;

	return ins;
}

int main() {
	double oldAcctBal = 0;
	int numberOfCashedChecks = 0;
	double cashedChecksTotalVal = 0;
	double deposits = 0;

	cout << "What is your old account balance:\n";
	cin >> oldAcctBal;

	vector<Check> checkBook;
	string isDepositing = "y";

	cout << "Would you like to make a deposit (y or n)? \n";
	cin >> isDepositing;

	while(isDepositing == "y"){
		int depAmount = 0;
		cout << "How much money would you like to deposit:\n";
		cin >> depAmount;
		deposits += depAmount;
		cout << "Would you like to make another deposit (y or n)? \n";
		cin >> isDepositing;
	};

	string isChecking = "y";
	int checkNum = 1;

	while (isChecking == "y") {
		int checkNumber, isCashed;
		Money amnt;

		cout << "Check #" << checkNum++ << endl;
		cout << "Enter check number: ";
		cin >> checkNumber;
		cout << "Enter check amount: ";
		operator>>(cin, amnt);
		cout << "Is the check cashed? (1 for yes or 0 for no)";
		cin >> isCashed;

		Check newCheck(checkNumber, amnt, isCashed);
		checkBook.push_back(newCheck);

		cout << "Would you like to add another check (y or n)? \n";
		cin >> isChecking;
	}

	for (int i = 0; i < checkBook.size(); ++i) {

		if(checkBook[i].getIsCashed()){
			// total of checks cashed
			cashedChecksTotalVal += (checkBook[i].getAmount()).get_value();
			numberOfCashedChecks += 1;

		} else{
			// total of deposits
			deposits += (checkBook[i].getAmount()).get_value();
		}
	}

	// The new account balance should be the old balance plus all deposits, minus all checks that have been cashed.
	double newAcctBal = oldAcctBal + deposits - cashedChecksTotalVal;

	cout << "Old Balance:\t\t\t\t\t\t$" << oldAcctBal << endl;
	cout << "New Balance:\t\t\t\t\t\t$" << newAcctBal << endl;
	cout << "Total Amount Cashed:\t\t\t\t$" << cashedChecksTotalVal << endl;
	cout << "Total Amount Deposited:\t\t\t\t$" << deposits << endl;
	cout << "Balance Difference:\t\t\t\t\t$" <<  newAcctBal - oldAcctBal << endl;

	cout << "\nCashed Checks:" << endl;
	for (int i = 0; i < checkBook.size(); ++i) {
		if(checkBook[i].getIsCashed()){
			operator<<(cout, checkBook[i]);
		}
	}

	cout << "\nUncashed Checks:" << endl;
	for (int i = 0; i < checkBook.size(); ++i) {
		if(!checkBook[i].getIsCashed()){
			operator<<(cout, checkBook[i]);
		}
	}
	return 0;
}