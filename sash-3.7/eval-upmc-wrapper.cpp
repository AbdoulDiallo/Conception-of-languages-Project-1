#include "eval-upmc.h"
#include "eval-upmc-wrapper.h"
#include <string.h>

using namespace std;

extern "C" {
	AST* newAST(){
		return new AST();
	}

	double eval_expr(char *expr){
		AST* a = new AST(1);
		if((expr != NULL) && (strcmp(expr, "") != 0)){
			std::string str(expr);		
			AST* b = a->Parse(str);
			return b->eval();
		}
		return -10000;
	}
}
