#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    Matrix Y(3,2,1);
    Matrix X(4,1,3);
    
    cout << "Y:: " << endl;
    Y.print();
    cout << "Numero de linhas de Y:: " << Y.getRows()<<endl;
    cout << "Numero de colunas de Y:: " << Y.getCols()<<endl;
   
    cout << "Z é transposta de Y:: " << endl;
    Matrix Z = Y.transpose();
    Z.print();
    cout << "Numero de linhas de Z:: " << Z.getRows()<<endl;
    cout << "Numero de colunas de Z:: " << Z.getCols()<<endl;
    
    cout << endl << "X:: " << endl;
    X.print();
    
    cout << "Numero de linhas de X:: " << X.getRows()<<endl;
    cout << "Numero de colunas de X:: " << X.getCols()<<endl;

    cout << "Testando inserção de elemento em matriz: ";
    cout << "Matriz Original: " << endl;
    Y.print();
    Y.putElement(1, 1, 10);
    cout << "Matriz modificada: " << endl;
    Y.print();

    return 0;
}