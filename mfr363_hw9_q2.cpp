#include <iostream>
#include <array>
#include <string>
#include <vector>
using namespace std;

vector<int> convertSent(string inputText);
void compareStrings(string input1, string input2);

int main(){
	string input1,  input2;

	cout << "Please enter a line of text #1: " << endl;
	getline(cin, input1);

	cout << "Please enter a line of text #2: " << endl;
	getline(cin, input2);

	compareStrings(input1, input2);

	return 0;
}


void compareStrings(string input1, string input2){
	vector<int> charOccurances1 = {};
	vector<int> charOccurances2 = {};

	charOccurances1 = convertSent(input1);
	charOccurances2 = convertSent(input2);
	int i = 0;
	bool isEqual = true;
	while (isEqual && i < charOccurances1.size()) {
		if(charOccurances1[i] == charOccurances2[i]){
			i += 1;
		} else{
			isEqual = false;
			cout << input1 << "and " << input2 << " are not anagrams" << endl;
		}
	}

	if(isEqual){
		cout << "'" << input1 << "'" << " and '" << input2 << "'" << " are anagrams" << endl;
	}
}


vector<int> convertSent(string inputText){
	int numberOfWords = 1;
	vector<int> charOccurances;
	charOccurances.resize(26);

	for (int charInSent = 0; charInSent < inputText.length(); ++charInSent) {
		// a starts at 97
		if(inputText[charInSent] >= 'a' && inputText[charInSent] <= 'z' ) {
			// we want our array index at 0 -  a minus a is 0 and char minus a is the index from 1 - 26 where 1 is a
			charOccurances[inputText[charInSent] - 'a'] += 1;

			// A starts at 65
		}else if(inputText[charInSent] >= 'A' && inputText[charInSent] <= 'Z' ){
			charOccurances[inputText[charInSent] - 'A'] += 1;
		} else if(inputText[charInSent] == ' '){
			numberOfWords += 1;
		}
	}

	return charOccurances;
}
