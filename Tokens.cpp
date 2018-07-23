#include "Tokens.h"

#if !defined NULL
   #define NULL 0
#endif

#include <iostream>
using namespace std;

// Functions prototypes
void addToken(Tokens* tokens, String* str);  //requires a resizing check
void resize(Tokens* tokens);
Tokens* initTokens(int start_size);
int charLength(const char* char_array); // Used only inside this file

// Function that initialize a Token element
// Receives:
//      @ (int) start_size : maximum number of tokens
// Returns:
//      # (Tokens*) tokens : pointer of the created element
Tokens* initTokens(int start_size)
{
   Tokens* tokens = new Tokens;
   tokens->max_tokens = start_size;
   tokens->sz = 0;

   String** strings = new String*[start_size];
   for ( int i = 0; i < start_size; i++ )
      strings[i] = NULL;

   tokens->tokens = strings;
   return tokens;
}

// Function that create tokens based on a character delimiter
// Receives:
//      @ (String*) str : String element
//      @ (char) delimiter : character that tell where to stop
// Returns:
//      # (Tokens*) tokens : pointer of the element created
Tokens* createTokens(String* str, char delimiter)
{
    int i=0,
        start_size=1,
        beginning=0;

    Tokens* tokens = initTokens(start_size);

    while ( str->str[i] != '\0' )
    {
        if ( str->str[i] == delimiter )
        {
            addToken(tokens, substr(str, beginning, i));
            beginning = i + 1;
        }
        else
            if ( str->str[i+1] == '\0' )
            {
                addToken(tokens, substr(str, beginning, i+1));
                break;
            }

		i++;
    }

    return tokens;
}

// Function that resize a token element
// Receives:
//      @ (Tokens*) tokens : pointer of the token element
// Returns:
//      # (void)
void resize(Tokens* tokens)
{
	if ( tokens == NULL )
        return;

	tokens->max_tokens++;
    String** strings = new String*[tokens->max_tokens];

    for ( int i = 0; i<(tokens->max_tokens-1); i++ )
        strings[i] = tokens->tokens[i];

    delete [] tokens->tokens;

    tokens->tokens = strings;
}

// Function that add a token to a token element
// Receives:
//      @ (Tokens*) tokens : pointer of the token element
//      @ (String*) str : pointer of the token on String format
// Returns:
//      # (void)
void addToken(Tokens* tokens, String* str)
{
	if ( tokens == NULL )
		return;

	if ( tokens->sz == tokens->max_tokens )
		resize(tokens);

	tokens->tokens[tokens->sz] = str;
	tokens->sz++;
}

// Function that get a specific token
// Receives:
//      @ (Tokens*) tokens : pointer of the element
//      @ (int) index : index of the token to be returned
// Returns:
//      # (String*) r : token found
String* getToken(Tokens* tokens, int index)
{
	String* r;

	if ( tokens == NULL || index > tokens->sz )
		r = NULL;
	else
		r = tokens->tokens[index];

	return r;
}

// Function that remove a tokens element from the memory
// Receives:
//      @ (Tokens*) tokens : pointer of the element
// Returns:
//      # (void)
void destroyTokens(Tokens* tokens)
{
   if ( tokens == NULL )
		return;

    int num_tokens = tokens->sz;
    String** strings = tokens->tokens;

    for ( int i = 0; i<num_tokens; i++ )
    {
        String* str = strings[i];
        destroyString(str);
    }

    delete[] strings;
    delete tokens;
}

// Function that print out all the tokens
// Receives:
//      @ (Tokens*) tokens : pointer of the element
// Returns:
//      # (void)
void displayTokens(Tokens* tokens)
{
   int num_tokens = tokens->sz;
   String** strings = tokens->tokens;

   for ( int i=0; i<num_tokens; i++ )
   {
      String* str = strings[i];
      displayString(str);
      cout << endl;
   }
}

// Function that count an array length and return it
// Receives:
//      @ (const char*) char_array : array of characters
// Returns:
//      # (int) i : array length
int charLength(const char* char_array) {
	int i = 0;
	// While end is not found, count
	while (char_array[i] != '\0')
		i++;
	// Return the length
	return i;
}
