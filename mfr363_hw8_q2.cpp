#include <iostream>
#include <array>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main(){
	string inputWord = "";
	cout << "Please enter a word: ";
	cin >> inputWord;

	if(isPalindrome(inputWord)){
		cout << inputWord << " is a palindrome" << endl;
	} else{
		cout << inputWord << " is not a palindrome" << endl;
	}

	return 0;
}

bool isPalindrome(string str){
	string reverseStr;

	for(int ind = str.length() - 1; ind >= 0; ind--){
		reverseStr += str[ind];
	}

	if(reverseStr == str){
		return true;
	} else{
		return false;
	}
}