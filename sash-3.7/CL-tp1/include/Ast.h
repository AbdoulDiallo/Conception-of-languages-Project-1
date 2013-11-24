#ifndef AST_H
#define AST_H

enum t_Operation {Nothing, Plus, Minus, Mult, Div, Integer, Real};

class Ast
{
    public:
        Ast();
        double eval();
        Ast getLeft();
        Ast getRight();
        int getValueInt();
        double getValueDouble();
    protected:
    private:
        t_Operation operation;
        Ast left;
        Ast right;
        int valueInt;
        double valueDouble;


};

#endif // AST_H
