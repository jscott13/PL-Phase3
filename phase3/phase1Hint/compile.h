#ifndef COMPILE_H
#define COMPILE_H

#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

#define FALSE 0
#define TRUE (!FALSE)
////////////////////////////////////////////////
//////////////////////////////////////////////
/////////COMMENT CHANGED GIT HUB TEST
/* tokens types used by the scanner */
enum token {
    TOK_PLUS,
    TOK_MINUS,
    TOK_MULT,
    TOK_DIV,
    TOK_PERCENT,
    TOK_BANG,
    TOK_QUES,
    TOK_COLON,
    TOK_ASSIGN,
    TOK_COMMA,
    TOK_LT,
    TOK_GT,
    TOK_OPAR,
    TOK_CLPAR,
    TOK_OCURLY,
    TOK_CLCURLY,
    TOK_OR,
    TOK_AND,
    TOK_EQUAL,
    TOK_SEMI,
    TOK_BREAK,
    TOK_CONTIN,
    TOK_ELSE,
    TOK_FLOAT,
    TOK_IF,
    TOK_INT,
    TOK_RETURN,
    TOK_WHILE,
    TOK_IDENT,
    TOK_INTNUM,
    TOK_FLOATNUM,
    TOK_EOF,
    TOK_COMMENT,
    TOK_SPACE,
    TOK_ERR
    };

typedef struct
    {
    enum token toktype; /* the token's type */
    char text[256];     /* the string */
    int line, column;   /* the location */
    union
        {
        int intval;     /* for TOK_INTNUM */
        int symval;     /* for TOK_IDENT */
        float floatval; /* for TOK_FLOATNUM */
        } yylval;
    } TOK_INFO;

extern TOK_INFO tok;

typedef struct sym_entry
    {
    char *name;
    int val;
    enum token toktype;
    struct sym_entry *link;
    } SYM_ENTRY;

extern SYM_ENTRY *sym_table;
extern int sym_cnt;

extern int line_cnt;
extern int column_cnt;

/* function prptotypes */

SYM_ENTRY *handle_ident (char *name);
int get_next_char (FILE *fp);
void unget_next_char (int c, FILE *fp);
void get_token (FILE *fp);

#endif