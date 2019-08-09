#include <iostream>
#include <list>
#include <fstream>
#include <vector>

using namespace std;

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

template <class T>
class Stack{
	list<T> data;
public:
	void push(T newItem){data.push_front(newItem);}
	void pop(){ return data.pop_front();}
	T top()const { return *data.begin();}
	bool isEmpty() const { return data.size() == 0; };
	int size() const {  return data.size(); }
	void clear(){ data.clear();}

};

bool compileChecker(ifstream pascalCode){
	string commandToExecute;
	char nextChar;
	Stack<char> stack;

	while(commandToExecute != "egin"){
		pascalCode.ignore(99999, 'b');
		pascalCode >> commandToExecute;
	}
	while(pascalCode >> nextChar && commandToExecute == "egin"){

		if(nextChar == 'e'){
			string checkCommand;
			pascalCode >> checkCommand;
			if(checkCommand == "nd"){
				commandToExecute = "end";
			}
		} else{
			if(nextChar == '"'){
				pascalCode.ignore(99999, '"');
			} else if(nextChar == '{' || nextChar ==  '(' || nextChar == '['){
				stack.push(nextChar);
			}else if(nextChar == '}' || nextChar ==  ')' || nextChar ==  ']')
			{
				switch(nextChar) {
					case '}':
						if(stack.top() == '{'){
							stack.pop();
						}
						break;
					case ')':
						if(stack.top() == '('){
							stack.pop();
						}
						break;
					case ']':
						if(stack.top() == '['){
							stack.pop();
						}
						break;
				}
			}
		}
	}

	if(stack.size() == 0 && commandToExecute == "end"){
		return true;
	} else{
		return false;
	}
}


template <class T>
class Queue {
	vector<T> data;
public:
	void enqueueArry(T newItem) {
		data.push_back(newItem);
		end += 1;
	}
	void dequeueArry() {
		if(start < end){
			data[start] = NULL;
			start += 1;
		} else{
			clear();
		}
	}
	T top() const { return *data.begin(); }
	bool isEmpty() const { return end == start; }
	int size() const { return end - start; }
	void clear() { data.clear(); }
	void printData() const {
		if(isEmpty()){
			cout << "The array is empty." << endl;
		} else{
			for (int i = start; i < end; ++i) {
				cout << data[i] << " ";
			}
			cout << endl;
		}
	}

private:
	int start;
	int end;
};



int main() {

	// test file //
	ofstream pascalFile;
	pascalFile.open("p.txt");
	pascalFile << "begin {} ((([[end]]))) " << endl;

	cout << "********* HW #16 Part 1 *********" << endl;
	bool compiled = compileChecker(openInputFile(" your Pascal programming language function"));

	string result = "";
	if(compiled){
		result = "PASSED";
	} else{
		result = "FAILED";
	}
	cout << "Symbol balance checker " + result << endl;

	cout << "\n********* HW #16 Part 2 Test Cases *********" << endl;
	// test queue as int arry
	Queue<int> inputArry;

	cout << "\nTest case #1: queue array is enqueued with random ints 10 times to produce the following array: " << endl;
	while (inputArry.size() != 10) {
		int randomNum = rand() % 100;
		inputArry.enqueueArry(randomNum);
	}
	inputArry.printData();
	cout << "\nTest case #2: queue array is dequeued 4 times to produce the following array: " << endl;
	while (inputArry.size() != 6) {
		inputArry.dequeueArry();
	}
	inputArry.printData();
	cout << "\nTest case #3: remaining queue array is dequeued to produce the following result: " << endl;
	while (!inputArry.isEmpty()) {
		inputArry.dequeueArry();
	}
	inputArry.printData();

	return 0;
}