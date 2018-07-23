#include <iostream>
#include "String.h"
using namespace std;

// Function that count an array length and return it
// Receives:
//      @ (const char*) char_array : array of characters
// Returns:
//      # (int) i : array length
int contStr(const char* char_array)
{
	int i = 0;

	while (char_array[i] != '\0')
		i++;

	return i;
}

// Function that print out a string
// Receives:
//      @ (String*) str : string to be printed out
// Returns:
//      # (void)
void displayString(String* str)
{
	int i = 0;

	while (str -> str[i] != '\0')
		cout << str -> str[i++];
}

// Function that remove a string from the memory
// Receives:
//      @ (String*) str : string to be removed
// Returns:
//      # (void)
void destroyString(String* str)
{
	delete [] str->str;
	delete str;
	str = NULL;
}

// Function that find a character in a string and return its position
// Receives:
//      @ (String*) str : string to be searched
//      @ (char) delimiter : character to be found
//      @ (int) start : starting point or first position to start seeking
// Returns:
//      # (int) r : position of the character in the string
int find(String* str, char delimiter, int start)
{
	int i = start;

	if (start < 0 || start > contStr(str->str))
		return -1;

	while (str->str[i] != '\0' && str->str[i] != delimiter)
		i++;

	return str->str[i] == '\0'? -1 : i;
}

// Function that truncate a string and get only values between specific boundaries
// Receives:
//      @ (String*) str : string to be used
//      @ (int) start : first position in the string
//      @ (int) length : total length of characters after the first position
// Returns:
//      # (String*) newSubStr : string generated based on the arguments
String* substr(String* str, int start, int length)
{
	if ( length > contStr(str->str) )
		return 0;

	String *newSubStr = new String;
	int i, j;

	newSubStr -> str = new char[length+1];

	for ( i=start, j=0; i<length; i++, j++ )
		newSubStr -> str[j] = str-> str[i];

	newSubStr -> str[j] = '\0';

	return newSubStr;
}

// Function that compare the ASCII values of two strings and
// return 0 if str1 = str2, 1 if str1 > str2, -1 if str1 < str2
// Receives:
//      @ (String*) str1 : pointer of the first string
//      @ (String*) str2 : pointer of the second string
// Returns:
//      # (int) : numeric result (-1/0/1)
int compare(String* str1, String* str2)
{
	int i = 0, j = 0;

	while (str1->str[i] != '\0' && str2->str[i] != '\0')
    {
		if (str1->str[i] > str2->str[i])
			return 1;
		else if (str1->str[i] < str2->str[i])
			return -1;

		i++;
	}

	if (str1->str[i] == '\0' && str2->str[i] == '\0')
		return 0;
	else if (str1->str[i] == '\0')
		return -1;
	else
		return 1;
}

// Function that create a new String in the memory
// Receives:
//      @ (const char*) char_array : array of characters
// Returns:
//      # (String*) newString : pointer of the new created String
String* createString(const char* char_array)
{
	String *newString = NULL;
	int size = contStr(char_array);
	int i;

	if (size > 0)
    {
		newString = new String;

		if (newString != NULL)
		{
			newString -> str = new char[size + 1];

			for (i = 0; i < size; i++)
				newString -> str[i] = char_array[i];

			newString -> str[i] = '\0';
		}
	}

	return newString;
}
