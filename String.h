#if !defined MYSTRING
#define MYSTRING

struct String {
	char *str;
};

String* createString(const char* char_array);
void destroyString(String* str);
void displayString(String* str);
int find(String* str, char delimiter, int start);
String* substr(String* str, int start, int end);
int compare(String* str1, String* str2);

#endif
