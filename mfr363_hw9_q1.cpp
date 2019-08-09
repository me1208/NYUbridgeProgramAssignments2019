#include <iostream>
#include <array>
#include <string>
using namespace std;

void convertSentence(string inputText);
void printOccurences(int numOfWords, int charOccurances[]);

int main(){
	string inputText;

	cout << "Please enter a line of text: " << endl;
	getline(cin, inputText);

	convertSentence(inputText);

	return 0;
}

void convertSentence(string inputText){
	int numberOfWords = 1;
	int charOccurances[26] = {0};
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

	printOccurences(numberOfWords, charOccurances);

}

void printOccurences(int numOfWords, int charOccurances[]){
	char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g' , 'h', 'i', 'j', 'k', 'l',
	                     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	cout << numOfWords << "\twords" << endl;
	for (int i = 0; i < sizeof(alphabet); ++i) {
		if(charOccurances[i] != 0){
			cout << charOccurances[i] << "\t"<< alphabet[i] << endl;
		}
	}
}