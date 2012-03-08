#pragma warning(disable : 4996)
#include <iostream>
#include <stdlib.h>
#include "compile.h"
#include "get_token.h"
#include "parser.h"
using namespace std;

int line_cnt = 1;
int column_cnt = 1;
int last_col;
TOK_INFO tok;

char *tokstr[] =
    {
    "TOK_PLUS",
    "TOK_MINUS",
    "TOK_MULT",
    "TOK_DIV",
    "TOK_PERCENT",
    "TOK_BANG",
    "TOK_QUES",
    "TOK_COLON",
    "TOK_ASSIGN",
    "TOK_COMMA",
    "TOK_LT",
    "TOK_GT",
    "TOK_OPAR",
    "TOK_CLPAR",
    "TOK_OCURLY",
    "TOK_CLCURLY",
    "TOK_OR",
    "TOK_AND",
    "TOK_EQUAL",
    "TOK_SEMI",
    "TOK_BREAK",
    "TOK_CONTIN",
    "TOK_ELSE",
    "TOK_FLOAT",
    "TOK_IF",
    "TOK_INT",
    "TOK_RETURN",
    "TOK_WHILE",
    "TOK_IDENT",
    "TOK_INTNUM",
    "TOK_FLOATNUM",
    "TOK_EOF",
    "TOK_COMMENT",
    "TOK_SPACE",
    "TOK_ERR"
    };

void main (int argc, char *argv[])
    {
    FILE *fp;
    SYM_ENTRY *p;
    int done;

    if (argc < 2)
        {
        fprintf (stderr, "need an input file as arg\n");
        exit (-1);
        }

    if ((fp = fopen (argv[1], "r")) == NULL)
        {
        fprintf (stderr, "can't open input file %s\n", argv[1]);
        exit (-1);
        }

    /* load keywords into symbol table */
    p = handle_ident ("break");
    p->toktype = TOK_BREAK;
    p = handle_ident ("continue");
    p->toktype = TOK_CONTIN;
    p = handle_ident ("else");
    p->toktype = TOK_ELSE;
    p = handle_ident ("float");
    p->toktype = TOK_FLOAT;
    p = handle_ident ("if");
    p->toktype = TOK_IF;
    p = handle_ident ("int");
    p->toktype = TOK_INT;
    p = handle_ident ("return");
    p->toktype = TOK_RETURN;
    p = handle_ident ("while");
    p->toktype = TOK_WHILE;

	//load first token
	get_token(fp);
	//start parser functions
	program(fp);
    }

int get_next_char (FILE *fp)
    {
		
    char c;
    c = getc (fp);
    if (c != EOF)
        if(c == '\n')
            {
            last_col = column_cnt;
            line_cnt++;
            column_cnt = 1;
            }
		else{
			column_cnt++;}
		return (c);
    }

void unget_next_char (int c, FILE *fp)
    {
    ungetc (c, fp);

    if (c == '\n')
        {
        line_cnt--;
        column_cnt = last_col;
        }
    else
        column_cnt--;
} 