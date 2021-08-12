#include <iostream>
#include "Ponto2D.h"
#include "Ponto3D.h"
#define PRINT(X) cout << #X<<"::" <<X<<endl;
#define TRACE(s) cerr <<"Testando " <<#s<<": \n" << endl; s 
using namespace std;

int main()
{
    Ponto2D p1(3,4), p2;
    TRACE(p2.set(2,1.5));
    cout << "Imprimindo ponto P1: "<< endl;
    PRINT(p1);
    cout << "Imprimindo ponto P2: "<< endl;
    PRINT(p2);

    TRACE(p2 = p1);
    cout << "Atribuindo o valor de P1 a P2: "<< endl;
    PRINT(p2);

    cout<<"Testes com pontos 3D" << endl;
    Ponto3D p3(2,4.5,5), p4;
    TRACE(p4.set(1,0.3,12));
    cout << "Imprimindo P3: "<< endl;
    PRINT(p3);
    cout << "Imprimindo P4: "<< endl;
    PRINT(p4);

    TRACE(p4 = p3);
    cout << "Atribuindo o valor de P3 a P4: "<< endl;
    PRINT(p4);
    cout << "Testando sobrecarga de operador '=' para ponto 3D \n" << endl;
    TRACE(p4 = p1);
    cout << "Atribuindo o valor de P1 a P4: "<< endl;
    PRINT(p4);
    cout << "Obtendo eixo x de P4: "<< endl;
    PRINT(p4.get_x());
    cout << "Obtendo eixo y de P4: "<< endl;
    PRINT(p4.get_y());

    return 0;
}   