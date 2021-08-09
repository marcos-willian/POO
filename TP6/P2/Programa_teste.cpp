#include <iostream>
#include "Matrix.h"
#include <cstdlib> // system()
using namespace std;
#define PRINT(X) cout << #X<<":: \n" <<X<<endl;
#define TRACE(s) cerr <<"Testando " <<#s<<": \n" << endl; s
// Programa cliente para testar a classe Matrix
/**----------------------------------------------
 * todo                  To do
 *   Criar semelhante aos do profesor testes observando funções que podem dar problemas
 * utilizar try catch.
 *   Vrificar se fiz merdinhas
 *   
 *
 *---------------------------------------------**/
void inline continuar(){
    cout << "\nPressione enter para continuar...";
    getchar();
    if (system( "clear" )) system( "cls" );
}

int main(){
    
    cout << "\n ---------------Testando construtores -------------- \n" << endl;

    TRACE(Matrix<double> m1);
    cout << "-> Matriz de dimensao " << m1.getRows() << " x " << m1.getCols() << endl;
    PRINT(m1);

    TRACE(Matrix<float> m2(5, 5, 7.5));
    cout << "-> Matriz de dimensao " << m2.getRows() << " x " << m2.getCols() << endl;
    PRINT(m2);

    continuar();
    
    TRACE(Matrix<float> m3(m2));
    cout << "-> Matriz de dimensao " << m3.getRows() << " x " << m3.getCols() << endl;
    PRINT(m3);
    
    TRACE(Matrix<int> m4(3, 3, 6.9));
    cout << "-> Matriz de dimensao " << m4.getRows() << " x " << m4.getCols() << endl;
    PRINT(m4);    
    
    ifstream in("exempleFile.txt");
    TRACE(Matrix<short int> Y);
    PRINT(Y);

    TRACE(Matrix<long int> X(3,3));
    PRINT(X);

    TRACE(Matrix <float> A(3,3));
    PRINT(A);
        
    TRACE(Matrix<float> C(3,3));
    PRINT(C);
        
    TRACE(Matrix<double> Z(3,2,7.0));
    PRINT(Z);
        
    TRACE(Matrix<long int> W(in));
    PRINT(W);

    continuar();
    
    cout << "\n ---------------Testando Inicializacoes -------------- \n" << endl;
    
    TRACE(Matrix<float> m6(3, 4, 2.3));
    cout << "-> Matriz de dimensao " << m6.getRows() << " x " << m6.getCols() << endl;
    PRINT(m6);
    cout << "m6.zeros() :: Matriz Zeros" << endl;
    m6.zeros();
    PRINT(m6);
    
    TRACE(Matrix<float> m7(3, 4, 2.3));
    cout << "-> Matriz de dimensao " << m6.getRows() << " x " << m6.getCols() << endl;
    PRINT(m7);
    cout << "m7.unit() :: Matriz Unit" << endl;
    try{
        m7.unit();
    }catch(invalid_argument& err){
        cerr<<"ERRO\t"<<err.what()<<endl<<endl;
    }
    PRINT(m7);

    continuar();
    
    cout << "\n --------------- Testando Sobrecarga de Operadores-------------------------- \n" << endl;

    cout << "-> Sobrecarga do Operador ( )" << endl;
    TRACE(m6(1, 1) = 7; m6(1, 3) = -3; m6(2, 1) = 3.6; m6(2, 2) = -2; m6(3, 1) = 4;)
    PRINT(m6);    
    continuar();

    TRACE(A(2,1) = 10);
    PRINT(A);
    
    cout << "-> Sobrecarga do operador +" << endl;
    TRACE(A + A);
    PRINT(A + A);
    continuar();

    try{
        cout << "-> Sobrecarga do operador -=" << endl;
        C -= A;
        PRINT(C);

        cout << "-> Sobrecarga do operador -" << endl;
        X = X - W;                                  // Subtração
        PRINT(X);
        continuar();
    }
    catch(invalid_argument &err){
        cerr<<"ERRO\t"<<err.what()<<endl;
    }

    cout << "-> Sobrecarga do operador ~" << endl;
    TRACE(A = ~C);                                  // A é igual a transposta de C
    PRINT(A);
    continuar();

    cout << "-> Sobrecarga do operador *" << endl;
    TRACE(X = W * 2);                                   // multiplicação por uma constante
    PRINT(X);
    continuar();

    cout << "-> Sobrecarga do operador *=" << endl;
    TRACE(C *= A);                                            // multiplicação de matrizes
    PRINT(C);
    continuar();

    cout << "-> Sobrecarga do operador ==" << endl;
    TRACE(A == C);                                 // verifica a igualdade entre A e C
    if( A==C ) 
        cout << "Verdadeiro\n";
    else
        cout<< "Falso\n";
    continuar();

    cout << "-> Sobrecarga do operador !=" << endl;
    TRACE(X != W);                                  // verifica a desigualdade entre A e C
    if( X != W ) 
        cout << "Verdadeiro\n";
    else
        cout<< "Falso\n";
    continuar();
    
    cout << "\n --------------- Testando Funções de Matrizes-------------------------- \n" << endl;
    cout << "-> Impressão de matrizes" << endl;
    TRACE(cout << Z << endl);                        // impressão de matrizes
    continuar();

    cout << "-> Leitura de dados pela entrada padrão" << endl;
    TRACE(cin >> W);                                 // leitura de dados para dentro da matriz Y 
    PRINT(W);
    continuar();

    cout << "-> Geração de matriz de zeros" << endl;
    TRACE(A.zeros());
    PRINT(A);
    continuar();

    cout << "-> Geração de matriz de 1's" << endl;
    TRACE(X.ones());
    PRINT(X);

    return 0;
}