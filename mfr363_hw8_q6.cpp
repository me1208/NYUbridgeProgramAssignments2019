#include <iostream>
#include <array>
#include <string>
using namespace std;

string convertSentence(string inputText);
bool isOnlyDigits(string subString);
string digitToX(string digitString);

int main(){
	string inputText;

	cout << "Please enter a line of text: " << endl;
	getline(cin, inputText);

	cout << convertSentence(inputText);

	return 0;
}

bool isOnlyDigits(string subString){
	if(subString.find_first_not_of("1234567890 ") != string::npos){
		return false;
	} else {
		return true;
	}

}

string convertSentence(string inputText){
	int pos1 = 0, pos2 = 0;
	string outputText;

	string editedInput = inputText;
	while (outputText.length() < inputText.length()) {

		pos2  = editedInput.find(' ');
		string inputSubStrng = editedInput.substr(pos1, pos2);
		editedInput = editedInput.substr(pos2 + 1);

		bool onlydigits = isOnlyDigits(inputSubStrng);
		if(onlydigits){
			outputText += digitToX(inputSubStrng) + " ";
		} else{
			outputText += inputSubStrng + " ";
		}
	}

	return outputText;
}

string digitToX(string digitString){
	string xString = "";

	for (int ind = 0; ind < digitString.length(); ++ind) {
		xString += "x";
	}
	return xString;
}