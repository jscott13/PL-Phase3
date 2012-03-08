#pragma warning(disable : 4996)

#include "special.h"
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;

int myisalpha(char c) {
	if(isalpha(c) || c == '_') return 1;
	return 0;
}
int myisIntFloat(char c){
	if(isdigit(c) || c == '.')return 1;
	if(c == 'e' || c == 'E')return 1;
	if(c == '+' || c == '-')return 1;
	return 0;
}
int mySpecial(char c){
	if(c == '+'||c == '-'||c == '*'||c == '/'||c == '%'||c == '!'||c == '?'||c == ':'||c == '='||c == ','||c == '<'||c == '>'||c == '('||c == ')'||c == '{'||c == '}'||c == '|'||c == '&' || c == ';'){
		return 1;
	}
	else return 0;
}
void addCharToStr(char * myString, char c) {
	int len = (int) strlen(myString);
	myString[len] = c; 
	myString[len + 2] = '\0';
}
int test(char * input) {
		int StateTable[9][5] = {
		{2,1,11,11,11},
		{8,11,11,11,11},
		{2,3,5,10,10},
		{4,9,5,9,9},
		{4,9,5,9,9},
		{7,11,11,6,11},
		{7,11,11,11,11},
		{7,9,9,9,9},
		{8,9,9,9,9}};
// final states:  9 - float    10 - integer   11 - error
int currentState = 0;
int column;
char c;
char d = ' ';
char e = ' ';
for(int charToEvaluate = 0; charToEvaluate < (int) strlen(input); charToEvaluate++) {
	if(charToEvaluate > 0){d = input[charToEvaluate - 1];}
	if(charToEvaluate > 1){e = input[charToEvaluate - 2];}
	c = input[charToEvaluate];
	if(isdigit(d) && mySpecial(c)){return 11;}
	if(isdigit(e) && (c == '.') && (d == '.')){return 11;}
	int column = 4;
	if(isdigit(c)) column = 0;
	if(c == '.') column = 1;
	if(c == 'E' || c == 'e') column = 2;
	if(c == '-' || c == '+') column = 3;
	currentState = StateTable[currentState][column];
	if(currentState > 8) return currentState;
}
return 11; // error state
}


