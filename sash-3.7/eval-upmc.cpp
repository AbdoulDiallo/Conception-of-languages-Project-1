#include "eval-upmc.h"
#include <iostream>
#include <stack>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>
#include <string.h>

using namespace std;

AST::AST(){
    _op = NOTHING;
    _left = NULL;
    _right = NULL;
    _valueInt = NULL;
    _valueDouble = NULL;
    _valueString = NULL;
}

AST::AST(Operateur op, AST * left, AST * right){
    _op = op;
    _left = left;
    _right = right;
    _valueInt = NULL;
    _valueDouble = NULL;
    _valueString = NULL;
}

AST::AST(int valueInt ){
    _op = INTEGER;
    _left = NULL;
    _right = NULL;
    _valueInt = valueInt;
    _valueDouble = 0;
    _valueString = NULL;
}

AST::AST(double valueDouble ){
    _op = DOUBLE;
    _left = NULL;
    _right = NULL;
    _valueInt = NULL;
    _valueDouble = valueDouble;
    _valueString = NULL;
}

AST::AST(char *valueString ){
    _op = STRING;
    _left = NULL;
    _right = NULL;
    _valueInt = 0;
    _valueDouble = 0;
    _valueString = valueString;
}


Operateur finfOperateur(char op){
    switch(op){
        case '*':
            return MULT;
        break;
        case '/':
            return DIV;
        break;
        case '-':
            return MINUS;
        break;
        case '+':
            return PLUS;
        break;
        default:
            return NOTHING;
    }

}


AST *AST::Parse(std::string& theExpress){
//Restrictions:

// * theExpress must be a postfix expression
// * the numbers must be single digit and positive
// * no spaces between items

    stack<AST*> theStackNum;            //An int stack
    stack<char> theStackOp;



   int first, second;

   //For each item in the postfix expression from the left:

   for (int n = theExpress.size() - 1; n >= 0 ; n--)
   {
      switch (theExpress [n])
      {
      //if the item is an operator (+,-,*, or /) then

      //      pop two numbers off the stack

      //      make a calculation:  the second number
      //            popped-operator-first number

      //      push the result on the stack

      case '*':
        if(!theStackOp.empty()){
            if(theStackOp.top() == '+' || theStackOp.top() == '-'){
                char op = theStackOp.top();
               theStackOp.pop();
                AST *left = theStackNum.top();
                theStackNum.pop();
                AST *right = theStackNum.top();
                theStackNum.pop();

                AST *a= new AST(finfOperateur(op),left , right);
                theStackNum.push(a);

            }
            else{
                theStackOp.push ('*');
            }
        }
        else{
            theStackOp.push ('*');
        }

     break;

      case '/':
        if(!theStackOp.empty()){
            if(theStackOp.top() == '+' || theStackOp.top() == '-'){
                char op = theStackOp.top();
                theStackOp.pop();
                AST *left = theStackNum.top();
                theStackNum.pop();
                AST *right = theStackNum.top();
                theStackNum.pop();

                AST *a= new AST(finfOperateur(op),left , right);
                theStackNum.push(a);

            }
            else{
                theStackOp.push ('/');
            }
        }
        else{
            theStackOp.push ('/');
        }
     break;

      case '+':
        theStackOp.push ('+');
     break;

        case '-':
        theStackOp.push ('-');
     break;

      //   if the item is a number push it on the stack

      default:

      //str is a one character Cstring to hold the one digit number.
      //atoi is a library function that changes the Cstring to an int.
      //This won't work if str is an STL string.

      	 char *str  = (char *) malloc (sizeof(char));

      	 *str = theExpress [n];
      	 *(str+1) = '\0';

		if(std::isdigit(theExpress [n])){
         	theStackNum.push (new AST(atoi(str)));
        } else {
        	theStackNum.push (new AST(str));
        }
      }

   }

    while(!theStackOp.empty()){

        char op = theStackOp.top();
        theStackOp.pop();
        AST *left = theStackNum.top();
        theStackNum.pop();
        AST *right = theStackNum.top();
        theStackNum.pop();
		AST *a;
        if(op == '/'){
            a= new AST(finfOperateur(op),right , left);
        }else{
            a= new AST(finfOperateur(op),left , right);
        }

        theStackNum.push(a);
    }

   return theStackNum.top();
}



double AST::eval(){

    if(_op == PLUS){
        return _left->eval() + _right->eval();
    }
    else if(_op == MINUS){
        return _left->eval() - _right->eval();
    }
    else if(_op == MULT){
        return _left->eval() * _right->eval();
    }
    else if(_op == DIV){
        return _left->eval() / _right->eval();
    }
    else if(_op == INTEGER){
        return this->_valueInt;
    }
    else if(_op == DOUBLE){
        return this->_valueDouble;
    }
    else return -1;
}

char * AST::evalString(){

    if(_op == PLUS){
        char *res = (char *) malloc (sizeof(char));
        strcpy(res, _left->evalString());
    	strcat(res, _right->evalString());
        return res;
    }
    else if(_op == MINUS){
    	return NULL;
        //return _left->eval() - _right->eval();
    }
    else if(_op == MULT){
    	return NULL;
        //return _left->eval() * _right->eval();
    }
    else if(_op == DIV){
    	return NULL;
        //return _left->eval() / _right->eval();
    }
    else if(_op == STRING){
        return this->_valueString;
    }
    else return NULL;
}

