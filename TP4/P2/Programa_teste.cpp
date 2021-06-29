#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    ifstream in("exempleFile.txt");
    Matrix Y;
    Matrix X(3,1);
    Matrix Z(3,3,7.0);
    Matrix W(in);
    
    cout << "Y:: " << endl;
    Y.print();
    cout << "Numero de linhas de Y: " << Y.getRows() <<endl;
    cout << "Numero de colunas de Y: " << Y.getCols() <<endl;
    
    cout << "X:: " << endl;
    X.print();
    cout << "Numero de linhas de X: " << X.getRows() <<endl;
    cout << "Numero de colunas de X: " << X.getCols() <<endl;
    
    cout << "Z:: " << endl;
    Z.print();
    cout << "Numero de linhas de Z: " << Z.getRows() <<endl;
    cout << "Numero de colunas de Z: " << Z.getCols() <<endl;

    cout << "W:: " << endl;
    W.print();
    cout << "Numero de linhas de X: " << W.getRows() <<endl;
    cout << "Numero de colunas de X: " << W.getCols() <<endl;

    cout << "Testando inserção de elemento (1,1) em matriz: " << endl;
    cout << "Matriz Original: " << endl;
    X.print();
    X.putElement(1, 1, 10);
    cout << "Matriz modificada: " << endl;
    X.print();

    cout << "Testanto funcao get: " << endl;
    cout << "Matriz W: " << endl;
    W.print();
    cout << "elemento (2, 2): ";
    double element = W.get(2, 2);
    cout << element << endl;

    cout << "A é transposta de X: " << endl;
    Matrix A = X.transpose();
    A.print();
    cout << "Numero de linhas de A: " << A.getRows() <<endl;
    cout << "Numero de colunas de A: " << A.getCols() <<endl;

    cout << "Teste transformação em matriz identidade: " << endl;
    cout << "Matriz original: " << endl;
    Z.print();
    cout << "Matriz alterada: " << endl;
    Z.unit();
    Z.print();

    cout << "Teste transformação em matriz de 0's: " << endl;
    cout << "Matriz original: " << endl;
    A = W.transpose();
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