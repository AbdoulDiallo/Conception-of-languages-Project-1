#ifndef __EVAL_UPMC_WRAPPER_H
#define __EVAL_UPMC_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif
	typedef struct AST AST;

	AST* newAST();
	
	double eval_expr(char *expr);

	char *eval_string_expr(char *expr);

#ifdef __cplusplus
}
#endif
#endif
