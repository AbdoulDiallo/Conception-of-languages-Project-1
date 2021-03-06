#include <iostream>
#include "include/AST.h"


using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    AST *a1 = new AST(5);
    AST *a2 = new AST(10.0);
    AST *b1 = new AST(6);
    AST *b2 = new AST(11.0);
    AST *c1 = new AST(7);
    AST *c2 = new AST(12.0);

    AST *a= new AST(PLUS,a1 , a2);
    AST *b= new AST(PLUS,b1 , b2);
    AST *c= new AST(PLUS,a , b);

    string expre = "5+5+7*1";
    AST * test = a1->Parse(expre);


    /*cout << a->GetvalueDouble()<< endl;
    cout << a->GetvalueInt()<< endl;*/

    double res =  test->eval();

    cout << res<< endl;

    return 0;

}
