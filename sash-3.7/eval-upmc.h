#ifndef AST_H
#define AST_H
#include <string>

enum Operateur {PLUS, MINUS, MULT, DIV, INTEGER, DOUBLE, STRING, NOTHING};

class AST
{
    public:
        AST();
        AST(Operateur op, AST * left, AST * right);
        AST(int valueInt );
        AST(double valueDouble );
        AST(char *valueString );
        AST *Parse(std::string& theExpress );
        AST *Getleft() { return _left; }
        void Setleft(AST *val) { _left = val; }
        AST *Getright() { return _right; }
        void Setright(AST *val) { _right = val; }
        int GetvalueInt() { return _valueInt; }
        void SetvalueInt(int val) { _valueInt = val; }
        double GetvalueDouble() { return _valueDouble; }
        void SetvalueDouble(double val) { _valueDouble = val; }
        char *GetvalueString() { return _valueString; }
        void SetvalueString(char *val) { _valueString = val; }
		Operateur GetOperateur() { return _op; }
        void SetOperateur(Operateur op) { _op = op; }


        double eval();
        char *evalString();


    protected:
    private:
        Operateur _op;
        AST *_left;
        AST *_right;
        int _valueInt;
        double _valueDouble;
        char *_valueString;

};

#endif // AST_H
