#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
void printArry(string arr[], int arrSize);

int main() {

	string sentence = "You can do it!";
	int outWordsArrSize = 1;
	string * newSentenceArryPtr;

	newSentenceArryPtr = createWordsArray(sentence, outWordsArrSize);
	cout << "Your original sentence is '" << sentence << "'. New array size is " << outWordsArrSize << " and words inside the array include: ";
	printArry(newSentenceArryPtr, outWordsArrSize);


	return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize){
	int lastChar = 0, firstChar = 0;

	for (int j = 0; j < sentence.length(); ++j) {
		if(sentence[j] == ' '){
			outWordsArrSize++;
		}
	}

	string * sentArry = new string[outWordsArrSize];
	for (int i = 0; i < outWordsArrSize; ++i) {

		if(sentence.find(" ") != std::string::npos){
			lastChar = sentence.find(" ");
			firstChar = lastChar + 1;
		} else {
			lastChar = sentence.length();
			firstChar = 0;
		}

		sentArry[i] = sentence.substr(0, lastChar);
		sentence = sentence.substr(firstChar, sentence.length());

	}
	return sentArry;
}

void printArry(string arr[], int arrSize){
	cout << "( ";
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << ")";
}
