/*
Program name: Laboratory 14: Tokenizer
Written by: Amilton de Camargo, Nasser
Date: April 29, 2014
*/

#include <iostream>
#include <string>
#include "String.h"
#include "Tokens.h"
using namespace std;

char* StringToChar(string str);

// Main function
int main() {

	// Variables
	string str;
	char delimiter;

	cout << "Please type some sentence: ";
	getline(cin, str);
	cout << "Please type the delimiter character: ";
	cin >> delimiter;

	cout << endl << "Tokenizing..." << endl << endl;
	Tokens* tokens = createTokens(createString(StringToChar(str)), delimiter);

	cout << tokens->sz << " token(s) found:" << endl << endl;
	displayTokens(tokens);

	// End of the program
	return 0;
}
// Function that convert a string to a char*
// Receives:
//      @ (string) str : string to be converted
// Returns:
//      # (char*) _char : character pointer
char* StringToChar(string str)
{
	char* _char = new char[str.size() + 1];
	copy(str.begin(), str.end(), _char);
	_char[str.size()] = '\0';

	return _char;
}

