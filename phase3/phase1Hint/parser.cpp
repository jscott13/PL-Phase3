#include <iostream>
#include "compile.h"
#include "parser.h"
#include <queue>
using namespace std;

queue <int> errorQ;

void errorhandler(FILE * fp, char *errorString, int code){
	//error code corresponds to location in code 1-top 18-bottom
	/*errorQ.push(code);
	cout << "Error at line: " << tok.line << " column: " << tok.column << endl;
	cout << "Error Code: " << code << endl;*/
	printf (">>> %s  error code = %d\n",errorString, code);
   printf(">>> line = %d  column = %d  text encountered = %s  \n",tok.line, tok.column, tok.text);
   if(code < 100)  {
	   printf("*** Compilation abandoned ***\n");
	   exit(1);
   }
	while(!isInAnchorSet(production, tok.toktype) && tok.toktype != TOK_EOF) get_token (fp);
	 
//	printf (">>> for production %s skipping to token %s (%s)\n\n",
//		production, tok.text, tokenString(tok.toktype));


	//if(code == 1){
	//	get_token(fp);
	//	if(tok.toktype == TOK_FLOAT || tok.toktype == TOK_INT){return;}
	//	else errorhandler(fp, " not fixed",20);}
	//if(code == 2){
	//	while(tok.toktype >32 || tok.toktype < 14 || tok.toktype == 28){get_token(fp);}
	//	if(tok.toktype == TOK_OCURLY){return;}
	//	if(tok.toktype < 32){cout <<"Missing Open Curly at line: " << tok.line << "column: " << tok.column << endl;return;}
	//	else errorhandler(fp, " not fixed",21);
	//}
	//if(code == 3){
	//	while(tok.toktype >32 || tok.toktype < 12 || tok.toktype == 28){get_token(fp);}
	//	if(tok.toktype == TOK_OPAR){get_token(fp);return;}
	//	if(tok.toktype == TOK_FLOAT || tok.toktype == TOK_INT){cout << "Missing Open Parens at line: " << tok.line << "column: " << tok.column << endl;return;}
	//	else errorhandler(fp, " not fixed", 22);
	//}
	//if(code == 4){
	//	while(tok.toktype > 32 || tok.toktype < 14){get_token(fp);}
	//	if(tok.toktype == TOK_CLPAR){get_token(fp); return;}
	//	if(tok.toktype < 32){cout << "Missing Close Parens at line: "<< tok.line << " column: "<< tok.column << endl;return;}
	//	else errorhandler(fp, " not fixed",23);
	//}
	//if(code == 5){
	//	while(tok.toktype > 32 || tok.toktype == 28){get_token(fp);}
	//	if(tok.toktype == TOK_SEMI){get_token(fp);return;}
	//	if(tok.toktype < 32){cout << "Missing Semi Colon at line: "<< tok.line << " column: "<< tok.column << endl;return;}
	//	else errorhandler(fp, " not fixed",24);
	//}	
	//if(code == 6){
	//	/////while statement
	//}
	//if(code == 7){
	//	while(tok.toktype > 32 || tok.toktype == 28){get_token(fp);}
	//	if(tok.toktype == TOK_OPAR){return;}
	//	if(tok.toktype < 32){cout <<" Missing Open Parens at line: " << tok.line << " column: " << tok.column << endl;return;}
	//	else errorhandler(fp, " not fixed", 25);
	//}
	//if(code == 8){
	//	while(tok.toktype > 32 || tok.toktype == 28){get_token(fp);}
	//	if(tok.toktype == TOK_CLPAR){return;}
	//	if(tok.toktype < 32){cout <<" Missing Close Parens at line: " << tok.line << " column: " << tok.column << endl;return;}
	//	else errorhandler(fp, " not fixed", 26);

	//}
	//if(code == 9){
	//	////if statement
	//}
	//if(code == 10){
	//	while(tok.toktype > 32 || tok.toktype == 28){get_token(fp);}
	//	if(tok.toktype == TOK_OPAR){return;}
	//	if(tok.toktype < 32){cout <<" Missing Open Parens at line: " << tok.line << " column: " << tok.column << endl;return;}
	//	else errorhandler(fp, " not fixed", 27);
	//}
	//if(code == 11){
	//	while(tok.toktype > 32 || tok.toktype == 28){get_token(fp);}
	//	if(tok.toktype == TOK_OPAR){return;}
	//	if(tok.toktype < 32){cout <<" Missing Close Parens at line: " << tok.line << " column: " << tok.column << endl;return;}
	//	else errorhandler(fp, " not fixed", 28);
	//}
	//if(code == 12){
	//	while(tok.toktype > 32 || tok.toktype == 28){get_token(fp);}
	//	if(tok.toktype == TOK_SEMI){return;}
	//	if(tok.toktype < 32){cout <<" Missing Semi Colon at line: " << tok.line << " column: " << tok.column << endl;return;}
	//	else errorhandler(fp, " not fixed", 29);
	//}
	//if(code == 13){
	//	while(tok.toktype > 32 || tok.toktype == 28){get_token(fp);}
	//	if(tok.toktype == TOK_SEMI){return;}
	//	if(tok.toktype < 32){cout <<" Missing Semi Colon at line: " << tok.line << " column: " << tok.column << endl;return;}
	//	else errorhandler(fp, " not fixed", 30);
	//}
	//if(code == 14){
	//	while(tok.toktype > 32 || tok.toktype == 28){get_token(fp);}
	//	if(tok.toktype == TOK_SEMI){return;}
	//	if(tok.toktype < 32){cout <<" Missing Semi Colon at line: " << tok.line << " column: " << tok.column << endl;return;}
	//	else errorhandler(fp, " not fixed", 31);
	//}
	//if(code == 15){
	//	while(tok.toktype > 32 || tok.toktype == 28){get_token(fp);}
	//	//if(tok.toktype == TOK_SEMI){return;}
	//	if(tok.toktype < 32){cout <<"Statement Starter Expected at line: " << tok.line << " column: " << tok.column << endl;return;}
	//	else errorhandler(fp, " not fixed", 32);
	//}
	//if(code == 16){
	//	while(tok.toktype > 32 || tok.toktype == 28){get_token(fp);}
	//	if(tok.toktype == TOK_ASSIGN){return;}
	//	if(tok.toktype < 32){cout <<"Assign expected at line: " << tok.line << " column: " << tok.column << endl;return;}
	//	else errorhandler(fp, " not fixed", 33);
	//}
	//if(code == 17){
	//	while(tok.toktype > 32 || tok.toktype == 28){get_token(fp);}
	//	if(tok.toktype == TOK_COLON){return;}
	//	if(tok.toktype < 32){cout <<"Colon expected at line: " << tok.line << " column: " << tok.column << endl;return;}
	//	else errorhandler(fp, " not fixed", 34);
	//}
	//if(code == 18){
	//	while(tok.toktype > 32 || tok.toktype == 28){get_token(fp);}
	//	if(tok.toktype == TOK_CLPAR){return;}
	//	if(tok.toktype < 32){cout <<"Close Parens expected at line: " << tok.line << " column: " << tok.column << endl;return;}
	//	else errorhandler(fp, " not fixed", 35);
	//}

	//printf("Error>>> %s code - %d\n", errorString, code);
	//printf("line = %d column = %d text = %s \n", tok.line, tok.column, tok.text);
	//if(code != 100)exit(1);
}
void trace(char * theString){
	printf("%s", theString);
	for(int i = 25 - strlen(theString); i > 0; i--)printf(" ");
	printf("column = %d line = %d text = %s \n", tok.column, tok.line, tok.text);
}
//<type_specifier>    ::= int | float
void type_specifier(FILE *fp){
	 trace("type_specifier");
	if(tok.toktype == TOK_FLOAT)  {
		get_token(fp);
		return;}
	if(tok.toktype == TOK_INT){
		get_token(fp);
		return;}
	else{errorhandler(fp,"float or int expected" , 1);
	get_token(fp);
	return;}
	return;
}
//<identifier>
void identifier(FILE *fp){
	trace("identifier");
	get_token(fp);
}
//<param_decl>        ::= <type_specifier> <identifier>
void param_decl(FILE *fp){
	trace("param_decl");
	type_specifier(fp);
	identifier(fp);
}	 
 //<param_decl_list>   ::= <param_decl> { ',' <param_decl> }
void param_decl_list(FILE *fp){
	trace("param_decl_list");
	param_decl(fp);
	while(tok.toktype == TOK_COMMA || tok.toktype == TOK_FLOAT || tok.toktype == TOK_INT){
		if(tok.toktype == TOK_COMMA)get_token(fp);
		else param_decl(fp);
	}
}
// <compound_st_tail>::= '}' | { <var_decl> } <statement> { <statement> } '}'
void compound_st_tail(FILE *fp) {
                trace("compound_st_tail");
                if(tok.toktype == TOK_CLCURLY)  {
					get_token(fp);
					return;                 
                }
                // determine if we  a var_decl
                while(strcmp(tok.text,"int") == 0 || strcmp(tok.text,"float") == 0 ) var_decl(fp);
                // determine if we have more <statement>s or not
                while(tok.toktype != TOK_CLCURLY && tok.toktype != TOK_EOF) statement(fp);
 
                if(tok.toktype != TOK_EOF) get_token(fp);
}
//<compound_st>       ::= '{' <compound_st_tail>
void compound_st(FILE *fp){
	trace("compound_st");
	if(tok.toktype == TOK_OCURLY)get_token(fp);
	else{errorhandler(fp,"open bracket expected",2);}
	compound_st_tail(fp);
}	 
// <program>   ::= <type_specifier> <identifier> '(' <param_decl_list> ')' <compound_st>
void program (FILE *fp){
	trace("program");
	type_specifier(fp);
	identifier(fp);
	if(tok.toktype == TOK_OPAR)get_token(fp);
	else{errorhandler(fp,"open parenth expected", 3);}
	param_decl_list(fp);
	if(tok.toktype == TOK_CLPAR)get_token(fp);
	else{errorhandler(fp,"close parenth expected", 4);}
	compound_st(fp);
}
// <variable_ident_t>::= '=' <condition>  | lambda
void variable_ident_t(FILE *fp) {
                trace("variable_ident_t");
                if(tok.toktype == TOK_ASSIGN)  {
                    get_token (fp);
                    condition(fp);
					return;
				}
return;
}
//<variable_ident>    ::= <identifier> <variable_ident_t> 
void variable_ident(FILE *fp){
	trace("variable_ident");
	identifier(fp);
	variable_ident_t(fp);
}	
//<var_decl_list>     ::= <variable_ident> ( ',' <variable_ident> )
void var_decl_list(FILE *fp){
	trace("var_decl_list");
	variable_ident(fp);
	while(tok.toktype == TOK_COMMA){
		get_token(fp);
		variable_ident(fp);
	}
	
}
 //<var_decl>          ::= <type_specifier> <var_decl_list> ';'
void var_decl(FILE *fp){
	trace("var_decl");
	type_specifier(fp);
	var_decl_list(fp);
	if(tok.toktype != TOK_SEMI){errorhandler(fp,"semi expected", 5);}
	if(tok.toktype == TOK_SEMI){get_token(fp);}
}		
//<while_st>          ::= 'while' '(' <condition> ')' <statement>
void while_st(FILE *fp){
	trace("while_st");
	if(tok.toktype != TOK_WHILE){errorhandler(fp,"while expected", 6);}
	get_token(fp);
	if(tok.toktype != TOK_OPAR)errorhandler(fp,"open parenth expected", 7);
	if(tok.toktype == TOK_OPAR)	get_token(fp);
	condition(fp);	
	if(tok.toktype != TOK_CLPAR)errorhandler(fp,"close parenth expected", 8);
	if(tok.toktype == TOK_CLPAR)get_token(fp);
	statement(fp);
}
 //<conditional_st>    ::= 'if' '(' <condition> ')' <statement> <if_tail>
void conditional_st(FILE *fp){
	trace("conditional_st");
	if(tok.toktype != TOK_IF)errorhandler(fp,"if_expected", 9);
	get_token(fp);
	if(tok.toktype != TOK_OPAR)errorhandler(fp,"open parenth expected", 10);
	if(tok.toktype == TOK_OPAR)get_token(fp);
	condition(fp);
	if(tok.toktype != TOK_CLPAR)errorhandler(fp,"close parenth expected", 11);
	if(tok.toktype == TOK_CLPAR)get_token(fp);
	statement(fp);
	if_tail(fp);
}	
//<statement>         ::= <compound_st> | <conditional_st> | <while_st> | 'break' ';' | 
 //                        'continue' ';' |  'return' <condition> ';' | 
 //                        <expression> ';' | ';'
void statement(FILE *fp){
	trace("statement");
	if(tok.toktype == TOK_BREAK || tok.toktype == TOK_CONTIN){
		get_token(fp);
		if(tok.toktype != TOK_SEMI)errorhandler(fp,"semicolon expected",12);
		if(tok.toktype == TOK_SEMI)get_token(fp);
		return;
	}
	if(tok.toktype == TOK_RETURN){
		get_token(fp);
		condition(fp);
		if(tok.toktype != TOK_SEMI)errorhandler(fp,"semicolon expected",13);
		if(tok.toktype == TOK_SEMI)get_token(fp);
		return;
	}
	if(tok.toktype == TOK_SEMI){get_token(fp);return;}
	if(tok.toktype == TOK_IF){conditional_st(fp);return;}
	if(tok.toktype == TOK_OCURLY){compound_st(fp);return;}
	if(tok.toktype == TOK_WHILE){while_st(fp);return;}
	if(tok.toktype == TOK_IDENT){
		expression_st(fp);
		if(tok.toktype != TOK_SEMI){errorhandler(fp,"semicolon expected", 14);}
		if(tok.toktype == TOK_SEMI)get_token(fp);
		return;
	}
	else errorhandler(fp,"Statement Starter Expected",15);
}	
//<if_tail>           ::= 'else' <statement> | lambda
void if_tail(FILE *fp){
	trace("it_tail");
	if(tok.toktype == TOK_ELSE){
		get_token(fp);
		statement(fp);
		return;
	}
}	
//<expression>        ::= <ident> '=' <condition>  
void expression_st(FILE *fp){
	trace("expression_st");
	identifier(fp);
	if(tok.toktype != TOK_ASSIGN)errorhandler(fp,"assign expected", 16);
	if(tok.toktype == TOK_ASSIGN)get_token(fp);
	condition(fp);
}	
//<condition>         ::= <disjunction> <condition_tail>
void condition(FILE *fp){
	trace("condition");
	disjunction(fp);
	condition_tail(fp);
}	
//<condition_tail>    ::= '?' <condition> ':' <condition> | lambda
void condition_tail(FILE *fp){
	trace("conditional_tail");
	if(tok.toktype == TOK_QUES){
	get_token(fp);
	condition(fp);
	if(tok.toktype != TOK_COLON){errorhandler(fp,"colon expected",17);}
	if(tok.toktype == TOK_COLON)get_token(fp);
	condition(fp);
	return;
	}
}	
//<disjunction>       ::= <conjunction> <disjunction_prime>
void disjunction(FILE *fp){
	trace("disjunction");
conjunction(fp);
disjunction_prime(fp);
}	
//<disjunction_prime> ::= '||' <conjunction> <disjunction_prime> | lambda
void disjunction_prime(FILE *fp){
	trace("disjunction_prime");
if(tok.toktype == TOK_OR){
	get_token(fp);
	conjunction(fp);
	disjunction_prime(fp);
	return;	
}
}	
//<conjunction>       ::= <comparison> <conjunction_prime>
void conjunction(FILE *fp){
	trace("conjunction");
comparison(fp);
conjunction_prime(fp);
}	
//<conjunction_prime> ::= '&&' <comparison> <conjunction_prime> | lambda
void conjunction_prime(FILE *fp){
	trace("conjunction_prime");
if(tok.toktype == TOK_AND){
	get_token(fp);
	comparison(fp);
	conjunction_prime(fp);
	return;
}
}	
//<comparison>        ::= <relation> <comparison_tail>
void comparison(FILE *fp){
	trace("comparison");
	relation(fp);
	comparison_tail(fp);
}	
//<comparison_tail>   ::= '==' <relation> | lambda
void comparison_tail(FILE *fp){
	trace("comparison_tail");
	if(tok.toktype == TOK_EQUAL){
		get_token(fp);
		relation(fp);
		return;
	}
}	
//<relation>          ::= <sum> <relation_tail>
void relation(FILE *fp){
	trace("relation");
	sum(fp);
	relation_tail(fp);
}	
//<relation_tail>     ::= ( '<' | '>' ) <sum> | lambda
void relation_tail(FILE *fp){
	trace("relation_tail");
	if(tok.toktype == TOK_LT || tok.toktype == TOK_GT){
		get_token(fp);
		sum(fp);
		return;
	}
}	
//<sum>               ::= <term> <sum_prime>
void sum(FILE *fp){
	trace("sum");
	term(fp);
	sum_prime(fp);
}	
//<sum_prime>         ::= ( '+' | '-' ) <term> <sum_prime> | lambda
void sum_prime(FILE *fp){
	trace("sum_prime");
	if(tok.toktype == TOK_PLUS || tok.toktype == TOK_MINUS){
		get_token(fp);
		term(fp);
		sum_prime(fp);
		return;
	}
}	
//<term>              ::= <factor> <term_prime>
void term(FILE *fp){
	trace("term");
	factor(fp);
	term_prime(fp);
	//return;
}	
//<term_prime>        ::= ( '*' | '/' | '%' ) <factor> <term_prime> | lambda
void term_prime(FILE *fp){
	trace("term_prime");
	if(tok.toktype == TOK_MULT || tok.toktype == TOK_DIV || tok.toktype == TOK_PERCENT){
		get_token(fp);
		factor(fp);
		term_prime(fp);	
		return;
	}
}	
//<factor>            ::= <primary> | ( '!' | '-' ) <factor>
void factor(FILE *fp){
	trace("factor");
	if(tok.toktype == TOK_BANG || tok.toktype == TOK_MINUS){
		get_token(fp);
		factor(fp);
		return;
	}
	primary(fp);
}	
//<primary>           ::= <integer_num> | <float_num> | <identifier> | '(' <condition> ')'
void primary(FILE *fp){
	trace("primary");
	if(tok.toktype == TOK_OPAR){
		get_token(fp);
		condition(fp);
	if(tok.toktype != TOK_CLPAR)errorhandler(fp,"close parenth expected",18);
	if(tok.toktype == TOK_CLPAR)get_token(fp);
		return;
	}
	if(tok.toktype == TOK_INTNUM){
		integer_num(fp);
		return;
	}
	if(tok.toktype == TOK_FLOATNUM){
		float_num(fp);
		return;
	}
	if(tok.toktype == TOK_IDENT){
		identifier(fp);
		return;
	}
}	
//<integer_num>
void integer_num(FILE *fp){
	trace("integer_num");
	get_token(fp);
}	
//<float_num>
void float_num(FILE *fp){
	trace("float_num");
	get_token(fp);
}	

int isInAnchorSet(char * nonTerminal, int tokenType) {

	const int numberOfEntries = 31;
	const int maxTokensInAnchorSet = 20;
	const int maxNonTerminalStringSize = 23;

	int anchorSet[numberOfEntries][maxTokensInAnchorSet+1] = {
		 /* <program> */				{ 1,TOK_EOF},          
		 /* <type_specifier> */			{ 2,TOK_IDENT,    TOK_EOF},   
		 /* <param_decl_list> */		{ 2,TOK_CLPAR,    TOK_EOF},   
		 /* <param_decl> */				{ 3,TOK_CLPAR,    TOK_COMMA,   TOK_EOF},       
		 /* <compound_st> */			{16,TOK_BREAK,    TOK_CONTIN,  TOK_RETURN,   TOK_SEMI,
											TOK_OCURLY,   TOK_IF,      TOK_WHILE,    TOK_BANG, 
											TOK_MINUS,    TOK_INTNUM,  TOK_FLOATNUM, TOK_IDENT,
											TOK_OPAR,     TOK_CLCURLY, TOK_ELSE,     TOK_EOF }, 
		 /* <compound_st_tail> */		{ 2,TOK_CLCURLY,  TOK_EOF },      
		 /* <var_decl> */				{16,TOK_INT,      TOK_FLOAT,   TOK_BREAK,    TOK_CONTIN,
											TOK_RETURN,   TOK_SEMI,	   TOK_OCURLY,   TOK_IF,  
											TOK_WHILE,    TOK_BANG,    TOK_MINUS,    TOK_INTNUM,
											TOK_FLOATNUM, TOK_IDENT,   TOK_OPAR,     TOK_EOF  },          
		 /* <var_decl_list> */			{ 2, TOK_SEMI,   TOK_EOF},     
		 /* <variable_ident> */			{ 3, TOK_COMMA,  TOK_SEMI,    TOK_EOF},    
		 /* <variable_ident_tail> */	{ 2, TOK_COMMA,  TOK_SEMI},    
		 /* <statement> */				{16,TOK_BREAK,    TOK_CONTIN,  TOK_RETURN,   TOK_SEMI,
											TOK_OCURLY,   TOK_IF,      TOK_WHILE,    TOK_BANG, 
											TOK_MINUS,    TOK_INTNUM,  TOK_FLOATNUM, TOK_IDENT,
											TOK_OPAR,     TOK_CLCURLY, TOK_ELSE,     TOK_EOF },           
		 /* <conditional_st> */			{16,TOK_BREAK,    TOK_CONTIN,  TOK_RETURN,   TOK_SEMI,
											TOK_OCURLY,   TOK_IF,      TOK_WHILE,    TOK_BANG, 
											TOK_MINUS,    TOK_INTNUM,  TOK_FLOATNUM, TOK_IDENT,
											TOK_OPAR,     TOK_CLCURLY, TOK_ELSE,     TOK_EOF }, 
		 /* <if_tail> */				{16,TOK_BREAK,    TOK_CONTIN,  TOK_RETURN,   TOK_SEMI,
											TOK_OCURLY,   TOK_IF,      TOK_WHILE,    TOK_BANG, 
											TOK_MINUS,    TOK_INTNUM,  TOK_FLOATNUM, TOK_IDENT,
											TOK_OPAR,     TOK_CLCURLY, TOK_ELSE,     TOK_EOF },    
		 /* <while_st> */				{16,TOK_BREAK,    TOK_CONTIN,  TOK_RETURN,   TOK_SEMI,
											TOK_OCURLY,   TOK_IF,      TOK_WHILE,    TOK_BANG, 
											TOK_MINUS,    TOK_INTNUM,  TOK_FLOATNUM, TOK_IDENT,
											TOK_OPAR,     TOK_CLCURLY, TOK_ELSE,     TOK_EOF },          
		 /* <expression> */				{ 5,TOK_COMMA,    TOK_SEMI,    TOK_CLPAR,    TOK_COLON,
											TOK_EOF    }, 
		 /* <condition> */				{ 6,TOK_COMMA,    TOK_SEMI,    TOK_CLPAR,    TOK_ASSIGN,
											TOK_COLON,    TOK_EOF    },     
		 /* <condition_tail> */			{ 6,TOK_COMMA,    TOK_SEMI,    TOK_CLPAR,    TOK_ASSIGN,
											TOK_COLON,    TOK_EOF    },             
		 /* <disjunction> */			{ 7,TOK_QUES,     TOK_COMMA,   TOK_SEMI,     TOK_CLPAR, 
											TOK_ASSIGN,   TOK_COLON,   TOK_EOF    },  
		 /* <disjunction_prime> */		{ 7,TOK_QUES,     TOK_COMMA,   TOK_SEMI,     TOK_CLPAR, 
											TOK_ASSIGN,   TOK_COLON,   TOK_EOF    },        
		 /* <conjunction> */			{ 8,TOK_OR,       TOK_QUES,    TOK_COMMA,    TOK_SEMI, 
											TOK_CLPAR,    TOK_ASSIGN,  TOK_COLON,    TOK_EOF    },  
		 /* <conjunction_prime> */		{ 8,TOK_OR,       TOK_QUES,    TOK_COMMA,    TOK_SEMI, 
											TOK_CLPAR,    TOK_ASSIGN,  TOK_COLON,    TOK_EOF    },         
		 /* <comparison> */				{ 9,TOK_AND,      TOK_OR,      TOK_QUES,     TOK_COMMA,
											TOK_SEMI,     TOK_CLPAR,    TOK_ASSIGN,  TOK_COLON,
											TOK_EOF    },   
		 /* <comparison_tail> */		{ 9,TOK_AND,      TOK_OR,      TOK_QUES,     TOK_COMMA,
											TOK_SEMI,     TOK_CLPAR,   TOK_ASSIGN,   TOK_COLON,
											TOK_EOF    },             
		 /* <relation> */				{10,TOK_EQUAL,    TOK_AND,     TOK_OR,       TOK_QUES, 
											TOK_COMMA,    TOK_SEMI,    TOK_CLPAR,    TOK_ASSIGN,
											TOK_COLON,    TOK_EOF    },   
		 /* <relation_tail> */			{10,TOK_EQUAL,    TOK_AND,     TOK_OR,       TOK_QUES, 
											TOK_COMMA,    TOK_SEMI,    TOK_CLPAR,    TOK_ASSIGN,
											TOK_COLON,    TOK_EOF    },          
		 /* <sum> */					{12,TOK_LT,       TOK_GT,      TOK_EQUAL,    TOK_AND,
											TOK_OR,       TOK_QUES,    TOK_COMMA,    TOK_SEMI,  
											TOK_CLPAR,    TOK_ASSIGN,  TOK_COLON,    TOK_EOF    },     
		 /* <sum_prime> */				{12,TOK_LT,       TOK_GT,      TOK_EQUAL,    TOK_AND,
											TOK_OR,       TOK_QUES,    TOK_COMMA,    TOK_SEMI,  
											TOK_CLPAR,    TOK_ASSIGN,  TOK_COLON,    TOK_EOF    },                             
		 /* <term> */					{14,TOK_PLUS,     TOK_MINUS,   TOK_LT,       TOK_GT,
											TOK_EQUAL,    TOK_AND,     TOK_OR,       TOK_QUES,
											TOK_COMMA,    TOK_SEMI,    TOK_CLPAR,    TOK_ASSIGN,
											TOK_COLON,    TOK_EOF    },    
		 /* <term_prime> */				{14,TOK_PLUS,     TOK_MINUS,   TOK_LT,       TOK_GT,
											TOK_EQUAL,    TOK_AND,     TOK_OR,       TOK_QUES,
											TOK_COMMA,    TOK_SEMI,    TOK_CLPAR,    TOK_ASSIGN,
											TOK_COLON,    TOK_EOF    },             
		 /* <factor> */					{17,TOK_MULT,     TOK_DIV,     TOK_PERCENT,  TOK_PLUS,
											TOK_MINUS,    TOK_LT,      TOK_GT,       TOK_EQUAL,
											TOK_AND,     TOK_OR,       TOK_QUES,     TOK_COMMA,
											TOK_SEMI,    TOK_CLPAR,    TOK_ASSIGN,   TOK_COLON,
											TOK_EOF    },            
		 /* <primary> */				{17,TOK_MULT,     TOK_DIV,     TOK_PERCENT,  TOK_PLUS,
											TOK_MINUS,    TOK_LT,      TOK_GT,       TOK_EQUAL,
											TOK_AND,     TOK_OR,       TOK_QUES,     TOK_COMMA,
											TOK_SEMI,    TOK_CLPAR,    TOK_ASSIGN,   TOK_COLON,
											TOK_EOF    },
	};

	char nonTerminals[numberOfEntries][maxNonTerminalStringSize] = {
		"<program>",          
		"<type_specifier>",   
		"<param_decl_list>",  
		"<param_decl>",       
		"<compound_st>",
		"<compount_st_tail>",      
		"<var_decl>",         
		"<var_decl_list>",    
		"<variable_ident>",   
		"<variable_ident_tail>",   
		"<statement>",          
		"<conditional_st>",
		"<if_tail>",   
		"<while_st>",         
		"<expression>",
		"<condition>",    
		"<condition_tail>",          
		"<disjunction>", 
		"<disjunction_prime>",      
		"<conjunction>", 
		"<conjunction_prime>",      
		"<comparison>", 
		"<comparison_tail>",           
		"<relation>",  
		"<relation_tail>",        
		"<sum>",   
		"<sum_prime>",                        
		"<term>",  
		"<term_prime>",           
		"<factor>",           
		"<primary>"          
	};

	int i, j;

	// find the non-terminal in the list

	for(i = 0; i < numberOfEntries; i++) {
		if(strcmp(nonTerminal, nonTerminals[i]) == 0) {
			// go thru the list and see if the token matches
			for(j = 1; j <= anchorSet[i][0]; j++)
				if(tokenType == anchorSet[i][j]) return 1;
		}
	}
	return 0;

	errorhandler("we be in big trouble in isInAnchorSet",9999);

	return 0;

}