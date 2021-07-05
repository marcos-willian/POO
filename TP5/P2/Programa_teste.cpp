#include <iostream>
#include "Matrix.h"
using namespace std;
#define PRINT(X) cout << #X<<":: \n" <<X<<endl;
#define TRACE(s) cerr <<"Testando " <<#s<<": \n" << endl; s
int main()
{
    ifstream in("exempleFile.txt");
    Matrix Y;
    Matrix X(3,1), A(3,3), C(3,3);
    Matrix Z(3,2,7.0);
    Matrix W(in);

    PRINT(Y);
    PRINT(X);
    PRINT(A);
    PRINT(C);
    PRINT(Z);
    PRINT(W);
    
    TRACE(A(2,1) = 10);
    PRINT(A);

    TRACE(A + A);
    PRINT(A + A);

    TRACE(C = A + W);                             // Soma
    PRINT(C);

    TRACE(C -= A); 
    PRINT(C);                                  // Subtração 
     
    TRACE(A = C - A);                                  // Subtração
    PRINT(A);

    TRACE(A += A);                                  // Subtração
    PRINT(A);

    TRACE(A = ~C);                                  // A é igual a transposta de C
    PRINT(A);

    
    TRACE(X = Z * 2);                                   // multiplicação por uma constante
    PRINT(X);

    TRACE(X *= 2);                                   // multiplicação por uma constante
    PRINT(X);

    TRACE(C = A*C);                                         // multiplicação de matrizes
    PRINT(C);

    TRACE(C.unit());
    PRINT(C);

    TRACE(C *= X);                                            // multiplicação de matrizes
    PRINT(C);

    TRACE(A == C);                                 // verifica a igualdade entre A e C
    if( A==C ) 
        cout << "Verdadeiro\n";
    else
        cout<< "Falso\n";

    TRACE(X != Y);                                  // verifica a desigualdade entre A e C
    if( X != Y ) 
        cout << "Verdadeiro\n";
    else
        cout<< "Falso\n";

    TRACE(cout << Z << endl);                        // impressão de matrizes
    TRACE(cin >> W);                                        // leitura de dados para dentro da matriz Y 
    PRINT(W);
    
    TRACE(A.zeros());
    PRINT(A);

    TRACE(X.ones());
    PRINT(X);

    return 0;
}