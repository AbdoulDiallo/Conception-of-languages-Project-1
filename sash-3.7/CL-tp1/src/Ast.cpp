#include "Ast.h"

Ast::Ast()
{
     operation = Nothing;
        left = NULL;
        right = NULL;
        valueInt = 0;
        valueDouble = 0;
}

Ast::Ast(AST * le, AST *ri, t_Operation t)
{
     operation = t;
        left = le;
        right = ri;
        valueInt = 0;
        valueDouble = 0;
}
