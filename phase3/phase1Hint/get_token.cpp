#pragma warning(disable : 4996)
#include "get_token.h"
#include "compile.h"
#include "special.h"
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;

void get_token(FILE * fp) {
    SYM_ENTRY *p;
	char c;
	tok.toktype = TOK_ERR;
//execute until valid token is found
while((tok.toktype == TOK_ERR) || (tok.toktype == TOK_COMMENT)){
	char tokenString[256] = "";

	// skip over whitespace
	c = get_next_char(fp); 
	while(c == ' ' || c == '\n' || c == '\t')c = get_next_char(fp);
	
	// check for end of file
	if(c == EOF) {
			tok.toktype = TOK_EOF;			//set toktype
			tok.line = line_cnt;			//set linecount
			tok.column = column_cnt;		//set column count
			addCharToStr(tokenString, EOF);	
			strcpy(tok.text, tokenString);	//add string to tok.text
		}
	else{ //not end of file
///FLOAT OR INT		
		if(isdigit(c) || c == '.'){		//IF FLOAT OR INT
			tok.line = line_cnt;		//save line #
			tok.column = column_cnt;	//save column #
			addCharToStr(tokenString, c);
			c = get_next_char(fp);

			while(myisIntFloat(c)) {		//execute until non-int/float character is found
				addCharToStr(tokenString, c);
				c = get_next_char(fp);
			}
			unget_next_char(c, fp);	
			strcpy(tok.text,tokenString);
			
	////DETERMINE IF VALUE IS INT OR FLOAT USING TEST() FUNCTION///// if test returns: 9(float) 10(int) 11(error)
			addCharToStr(tokenString, ' ');	//**must add space to end of string for 'test' function to work properly**
			int a = test(tokenString);
			if(a == 9){
				p = handle_ident (tokenString);		//insert into symbol table
				tok.yylval.floatval = p->val;		// the symbol table entry index
				p->toktype = TOK_FLOATNUM;			//set FLOAT toktypes
				tok.toktype = TOK_FLOATNUM;	
				break;
			}
			
			if(a == 10){
				p = handle_ident (tokenString);
				tok.yylval.intval = p->val;
				p->toktype = TOK_INTNUM;			//set INT toktypes
				tok.toktype = TOK_INTNUM;
				break;
			}
			else break;	//test(tokenString) returned error(11); toktype stays as TOK_ERROR
		}
///IDENTIFIER
		if(myisalpha(c)) {
			tok.line = line_cnt;
			tok.column = column_cnt;
			addCharToStr(tokenString, c);
			c = get_next_char(fp);

			while(myisalpha(c) || isdigit(c)) { //execute until non-identifier character is found
				addCharToStr(tokenString, c);
				c = get_next_char(fp);
			}
			unget_next_char(c,fp);
			p = handle_ident (tokenString);		//insert into symbol table
			tok.yylval.symval = p->val;	
			
			//identifier is NOT a keyword
			if(tok.yylval.symval > 7 )tok.toktype = TOK_IDENT;
			//identifier is a keyword
			else{
				switch(tok.yylval.symval) {
				case 0: tok.toktype = TOK_BREAK; break;
				case 1: tok.toktype = TOK_CONTIN; break;
				case 2: tok.toktype = TOK_ELSE; break;
				case 3: tok.toktype = TOK_FLOAT; break;
				case 4: tok.toktype = TOK_IF; break;
				case 5: tok.toktype = TOK_INT; break;
				case 6: tok.toktype = TOK_RETURN; break;
				case 7: tok.toktype = TOK_WHILE; break;
				}
			}

			strcpy(tok.text,tokenString);
			//unget_next_char(c, fp);
		break;
		}
///OPERATOR
		if(mySpecial(c)){
			tok.line = line_cnt;
			tok.column = column_cnt;
			addCharToStr(tokenString, c);
			strcpy(tok.text,tokenString);

			p = handle_ident (tokenString);		//add to symbol table
			tok.yylval.symval = p->val;	
			
			if(*tokenString == '&'){
				c = get_next_char(fp);
				if(c == '&'){
					addCharToStr(tokenString,c);
					strcpy(tok.text,tokenString);
					tok.toktype = TOK_AND;
					p->toktype = TOK_AND;
					break;}		//&& AND OPERATOR
				else{
				unget_next_char(c,fp);tok.toktype = TOK_ERR;p->toktype = TOK_ERR;break;}
			}
			if(*tokenString == '|'){
				c = get_next_char(fp);
				if(c == '|'){addCharToStr(tokenString,c);strcpy(tok.text,tokenString);tok.toktype = TOK_OR;p->toktype = TOK_OR;break;}		//&& AND OPERATOR
				else{unget_next_char(c,fp);tok.toktype = TOK_ERR;p->toktype = TOK_ERR;break;}
			}
			if(*tokenString == '/') {
					c = get_next_char(fp);
					if(c == '*'){	//beginning of comment
						addCharToStr(tokenString,c);
						char temp[4] = " ";
						c = get_next_char(fp);
						if(c == '/')c = get_next_char(fp);
						else unget_next_char(c,fp);
						
						while(0 != strcmp(temp,"*/")){
							temp[0] = temp[1];			//analyze previous and current character to recognize end of comment
							temp[1] = c;
							c = get_next_char(fp);
							if(c == EOF)tok.toktype = TOK_ERR;p->toktype = TOK_ERR;
						}
						//unget_next_char(c,fp);
						p = handle_ident (tokenString);
						tok.yylval.symval = p->val;	
						strcpy(tok.text,tokenString);
						tok.toktype = TOK_COMMENT;p->toktype = TOK_COMMENT;
						//break;
					}
					//divide
				else{tok.toktype = TOK_DIV;p->toktype = TOK_DIV;break;}
			}
			if(*tokenString == '=') {
				c = get_next_char(fp);
				if(c == '='){addCharToStr(tokenString,c);strcpy(tok.text,tokenString);tok.toktype = TOK_EQUAL;p->toktype = TOK_EQUAL;break;}	//EQUAL OPERATOR
				else{unget_next_char(c,fp);tok.toktype = TOK_ASSIGN;p->toktype = TOK_ASSIGN;break;}		//ASSIGN OPERATOR
			}
			if(*tokenString == '+') {tok.toktype = TOK_PLUS; p->toktype = TOK_PLUS;break;}
			if(*tokenString == '-') {tok.toktype = TOK_MINUS;p->toktype = TOK_MINUS;break;}
			if(*tokenString == '*') {tok.toktype = TOK_MULT;p->toktype = TOK_MULT;break;}
			if(*tokenString == '%') {tok.toktype = TOK_PERCENT;p->toktype = TOK_PERCENT;break;}
			if(*tokenString == '!') {tok.toktype = TOK_BANG;p->toktype = TOK_BANG;break;}
			if(*tokenString == '?') {tok.toktype = TOK_QUES;p->toktype = TOK_QUES;break;}
			if(*tokenString == ':') {tok.toktype = TOK_COLON;p->toktype = TOK_COLON;break;}
			if(*tokenString == ',') {tok.toktype = TOK_COMMA;p->toktype = TOK_COMMA;break;}
			if(*tokenString == '<') {tok.toktype = TOK_LT;p->toktype = TOK_LT;break;}
			if(*tokenString == '>') {tok.toktype = TOK_GT;p->toktype = TOK_GT;break;}
			if(*tokenString == '(') {tok.toktype = TOK_OPAR;p->toktype = TOK_OPAR;break;}
			if(*tokenString == ')') {tok.toktype = TOK_CLPAR;p->toktype = TOK_CLPAR;break;}
			if(*tokenString == '{') {tok.toktype = TOK_OCURLY;p->toktype = TOK_OCURLY;break;}
			if(*tokenString == '}') {tok.toktype = TOK_CLCURLY;p->toktype = TOK_CLCURLY;break;}
			if(*tokenString == ';') {tok.toktype = TOK_SEMI;p->toktype = TOK_SEMI;break;}
			//else{tok.toktype = TOK_ERR;p->toktype = TOK_ERR;break;}
			//break;
		}
		else {		// error case
			tok.toktype = TOK_ERR;
			tok.line = line_cnt;
			tok.column = column_cnt;
			addCharToStr(tokenString, c);
			}	
		}
}	
}