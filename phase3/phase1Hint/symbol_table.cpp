#pragma warning(disable : 4996)

#include <string.h>
#include "compile.h"
#include <iostream>
using namespace std;

SYM_ENTRY *sym_table = NULL;
int sym_cnt = 0;

SYM_ENTRY *handle_ident (char *name)
    {
    SYM_ENTRY *x;

    for (x=sym_table; x!=NULL; x=x->link)
        if (strcmp (name, x->name) == 0)
            return (x);

    x = (SYM_ENTRY*) malloc (sizeof (SYM_ENTRY));
    x->name = (char*) malloc (1 + strlen (name));
    strcpy (x->name, name);
    x->val = sym_cnt++;
	x->toktype = TOK_IDENT;
    x->link = sym_table;
    sym_table = x;
    return (x);
    }