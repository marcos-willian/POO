#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    // ifstream in("myMatrix.txt");
    Matrix Y;
    Matrix X(3,1);
    Matrix Z(3,2,7.0);
    // Matrix W(in);
    // Matrix Y(3,2,1);
    // Matrix X(4,1,3);
    
    cout << "X:: " << endl;
    X.print();
    cout << "Numero de linhas de X: " << Y.getRows() <<endl;
    cout << "Numero de colunas de X: " << Y.getCols() <<endl;
   
    cout << "A é transposta de X: " << endl;
    Matrix A = X.transpose();
    A.print();
    cout << "Numero de linhas de A: " << A.getRows() <<endl;
    cout << "Numero de colunas de A: " << A.getCols() <<endl;
    
    cout << endl << "A: " << endl;
    A.print();
    
    cout << "Numero de linhas de Z: " << Z.getRows() <<endl;
    cout << "Numero de colunas de Z: " << Z.getCols() <<endl;

    cout << "Testando inserção de elemento em matriz: " << endl;
    cout << "Matriz Original: " << endl;
    X.print();
    X.putElement(1, 1, 10);
    cout << "Matriz modificada: " << endl;
    X.print();

    cout << "Testanto funcao get: " << endl;
    cout << "Matriz Z: " << endl;
    Z.print();
    cout << "elemento (2, 2): ";
    double element = Z.get(2, 2);
    cout << element << endl;

    // cout << "Teste transformação em matriz identidade: " << endl;

    cout << "Teste transformação em matriz de 0's: " << endl;
    cout << "Matriz original: " << endl;
    A = X.transpose();
    A.print();
    cout << "Matriz alterada: " << endl;
    A.zeros();
    A.print();

    cout << "Teste transformacao em matriz de 1's: " << endl;
    cout << "Matriz original: " << endl;
    X.print();
    cout << "Matriz alterada: " << endl;
    X.ones();
    X.print();

    return 0;
}