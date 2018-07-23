#if !defined TOKENS_STRUCT
#define TOKENS_STRUCT

#include "String.h"

struct Tokens
{
   String** tokens;
   int max_tokens;
   int sz;
};

Tokens* createTokens(String* str, char delimiter);
String* getToken(Tokens* tokens, int index);  //returns a specifically requested token
void destroyTokens(Tokens* tokens);  //Tokens is responsible for deleting each token
void displayTokens(Tokens* tokens);

#endif
