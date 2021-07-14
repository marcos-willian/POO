#include <iostream>
#include "Matrix.h"
#include <cstdlib> // system()
using namespace std;
#define PRINT(X) cout << #X<<":: \n" <<X<<endl;
#define TRACE(s) cerr <<"Testando " <<#s<<": \n" << endl; s
// Programa cliente para testar a classe Matrix

void clearscreen() {
    if (system( "clear" )) system( "cls" );
}

void inline continuar(){
    cout << "\nPressione qualquer tecla para continuar...";
    getchar();
    clearscreen();
}

int main(){
    
    cout << "\n ---------------Testando construtores -------------- \n" << endl;
    TRACE(Matrix<double> m1);
    cout << "-> Matriz de dimensao " << m1.rows() << " x " << m1.cols() << endl;
    PRINT(m1);

    TRACE(Matrix<float> m2(5, 5, 7.5));
    cout << "-> Matriz de dimensao " << m2.rows() << " x " << m2.cols() << endl;
    PRINT(m2);

    continuar();
    
    TRACE(Matrix<float> m3(m2));
    cout << "-> Matriz de dimensao " << m3.rows() << " x " << m3.cols() << endl;
    PRINT(m3);
    
    TRACE(Matrix<double> m4(2, 3, 6));
    cout << "-> Matriz de dimensao " << m4.rows() << " x " << m4.cols() << endl;
    PRINT(m4);    
    
    continuar();
    
    cout << "\n ---------------Testando Inicializacoes -------------- \n" << endl;
    
    TRACE(Matrix<float> m6(3, 4, 2.3));
    cout << "-> Matriz de dimensao " << m6.rows() << " x " << m6.cols() << endl;
    PRINT(m6);
    m6.zeros();
    cout << "m6.zeros() :: Matriz Zeros" << endl;
    PRINT(m6);
   
    continuar();
    
    cout << "\n --------------- Testando Sobrecarga de Operadores-------------------------- \n" << endl;

    cout << "-> Sobrecarga do Operador ( )" << endl;
    TRACE(m6(1, 1) = 7; m6(1, 3) = -3; m6(2, 1) = 3.6; m6(2, 2) = -2; m6(3, 1) = 4;)
    PRINT(m6);    
    continuar();
}
/*
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
}*/