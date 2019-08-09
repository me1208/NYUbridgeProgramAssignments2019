#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <class T>
class LList;

template <class T>
class LListItr;

template <class T>
class LListNode{
	T data; // item to be stored
	LListNode<T> *next; // template to next node

public:
	//LListNode(T newData =T(), LListNode<T> newNext = nullptr): data(newData), next(newNext){}; // constructor
	LListNode(const T& newdata = T(), LListNode<T>* newnext = nullptr) :data(newdata), next(newnext){}
	friend class LList<T>;
	friend class LListItr<T>;
};

// Creating the linked List
template <class T>
class LList{
	LListNode<T>* head;
	LListNode<T>* recursionCopy(LListNode<T>* rhs);

public:
	LList() :head(nullptr){};
	LList(const LList& rhs) :head(nullptr){*this= rhs;};
	LList &operator=(const LList<T>& rhs);
	~LList(){ clear();}
	void insertAtHead(const T& toInsert){ head = new LListNode<T>(toInsert, head); }
	bool isEmpty() const{ return head == nullptr; }
	void clear(){ while (!isEmpty()) removeFromHead(); }
	T removeFromHead(){ return head->data; }
	void insertAtEnd(T newData);
	LListItr<T> begin(){ return head; }
	LListItr<T> end(){ return nullptr; }
	void insertAtPoint(LListNode<T> * ptr, T newData);
	int size() const;
	friend class LListNode<T>;

};
template <class T>
int LList<T>::size() const {
	int count = 0;
	LListNode<T>* temp = head;
	while (temp != nullptr){
		count ++;
		temp = temp->next;
	}
	return count;
}

template <class T>
void LList<T>::insertAtEnd(T newData){
	if (isEmpty()){
		insertAtEnd(newData);
		return;
	}
	LListNode<T>* temp = new LListNode<T>(newData);
	LListNode<T>* end = head;
	while (end->next != nullptr){
		end = end->next;
	}
	end->next = temp;
}

template <class T>
LListNode<T>* LList<T>::recursionCopy(LListNode<T> * rhs) {
			if(rhs == nullptr){
				return nullptr;
			}
			return new LListNode<T>(rhs-> data, recursionCopy(rhs->next));
}






template <class T>

class LListItr{
	LListNode<T>* currentNode;
public:
	LListItr(LListNode<T>* newcurrentNode = nullptr) :currentNode(newcurrentNode){}
	T& operator*(){ return currentNode->data; }
	T operator*()const { return currentNode->data; }
	LListItr<T>& operator++(); //preincrement
	LListItr<T> operator++(int); //postincrement
	bool operator==(const LListItr<T>& rhs)const { return currentNode == rhs.currentNode; }
	bool operator!=(const LListItr<T>& rhs)const { return !(*this == rhs); }

	friend class LList < T > ;
};

template <class T>
LListItr<T>& LListItr<T>::operator++(){
	if (currentNode != nullptr){
		currentNode = currentNode->next;
	}
	return *this;
}

template <class T>
LListItr<T> LListItr<T>::operator++(int){
	LListItr<T> temp = *this;
	if (currentNode != nullptr){
		currentNode = currentNode->next;
	}
	return temp;
}

class Employee {
public:
	// constructor
	Employee();
	Employee(int inputId, string inputName, double inputHourlyRate);

	// destructor
	~Employee();

	// get data variables
	int get_Id();
	string get_Name();
	double get_hourlyRate();
	int get_totalHours();
	double get_totalPay();

	// set data variables
	void set_Id(int newId);
	void set_Name(string newName);
	void set_hourlyRate(double newHourlyRate);
	void set_totalHours(int newTotalHours);
	void set_totalPay(double newTotalPay);

	// functions
	void addToTotalPay(double &payCheck);
	void updateHoursAndPay(int hours);

private:
	int id;
	string name;
	double hourlyRate;
	int totalHours;
	double totalPay;

};
Employee::Employee(){
	this->id = 0;
	this->name = "";
}

Employee::Employee(int inputId, string inputName, double inputHourlyRate){
	this->id = inputId;
	this->name = inputName;
	this->hourlyRate = inputHourlyRate;
	this->totalPay = 0;
	this-> totalHours = 0;

}

Employee::~Employee(){
	delete ;
}

// get data variables
int Employee::get_Id(){ return this->id;}
string Employee::get_Name(){ return this->name;}
double Employee::get_hourlyRate(){ return this->hourlyRate;}
int Employee::get_totalHours(){ return this->totalHours;}
double Employee::get_totalPay(){ return this->totalPay;}

// set data variables
void Employee::set_Id(int newId){this->id = newId;}
void Employee::set_Name(string newName){this->name = newName;}
void Employee::set_hourlyRate(double newHourlyRate){this->hourlyRate = newHourlyRate;}
void Employee::set_totalHours(int newTotalHours){this->totalHours = newTotalHours;}
void Employee::set_totalPay(double newTotalPay){this->totalPay = newTotalPay;}

// other employee functions
void Employee::addToTotalPay(double &payCheck){
	this->totalPay += payCheck;
};

void Employee::updateHoursAndPay(int hours){
	this->totalHours += hours;
	double payCheck = hours*hourlyRate;
	addToTotalPay(payCheck);
};

ifstream openInputFile(string fileType){
	ifstream inFile;
	string fileName;

	cout << "Please enter the file name for " << fileType << ":"<< endl;
	cin >> fileName;
	inFile.open(fileName);
	while(!inFile){
		cout << "INVALID FILE NAME! \n Please enter the file name:" << endl;
		cin >> fileName;
		inFile.clear(); // reset failure flags
		inFile.open(fileName);
	}
	return inFile;
}


void selectionSort(vector<Employee>& v){
	for (int i = 0; i < v.size(); i++){
		int indexOfLowest = i;
		for (int j = i + 1; j < v.size(); j++)
			if (v[j].get_totalPay() > v[indexOfLowest].get_totalPay())
				indexOfLowest = j;
		Employee temp = v[i];
		v[i] = v[indexOfLowest];
		v[indexOfLowest] = temp;
	}
}

int main() {

	/*	//// Practice Files - for testing purposes \\\\  */
	ofstream outFile;
	outFile.open("e.txt");
	outFile<<
			 "17 5.25 Daniel Katz\n"
		     "18 116.75 John F. Jones\n"
	         "20 20.80 Melissa Frendo-Rosso\n"
		     "21 280.80 j Dietz" << endl;

	ofstream payRollOut;
	payRollOut.open("p.txt");
	payRollOut <<
		 "17    40\n"
		 "18    20\n"
		 "18    20\n"
         "20    90\n"
		 "21    100" << endl;

	// read in data as such 17 5.25 Daniel Katz
	int tempId;
	double tempRate;
	string tempName;
	LList<Employee> employeeList;
	ifstream employeeInputFile = openInputFile("general employee information (id, hourly rate, name)");
	while(employeeInputFile >> tempId >> tempRate){
		getline(employeeInputFile, tempName);
		Employee tempEmployee(tempId, tempName, tempRate);
		employeeList.insertAtHead(tempEmployee);
	}

	// read in data as such 17 5.25 Daniel Katz
	int payRollId, hoursWorked;
	ifstream inPayRoll = openInputFile("employee payroll information (id, hours worked)");
	while(inPayRoll >> payRollId >> hoursWorked) {
		for (LListItr<Employee> i = employeeList.begin(); i != employeeList.end(); i++) {
			if ((*i).get_Id() == payRollId) {
				(*i).updateHoursAndPay(hoursWorked);
			}
		}
	}

	// converting to vector for sorting purposes
	vector<Employee> employeesVect;
	for (LListItr<Employee> i = employeeList.begin(); i != employeeList.end(); i++) {
			employeesVect.push_back(*i);
	}
	selectionSort(employeesVect);

	cout << "*********Payroll Information********" << endl;
	for (int j = 0; j < employeesVect.size(); ++j) {
		cout << employeesVect[j].get_Name() << ", $" << employeesVect[j].get_totalPay() << endl;
	}
	cout << "*********End payroll****************" << endl;

	return 0;
}
