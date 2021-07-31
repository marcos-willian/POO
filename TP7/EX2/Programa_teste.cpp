#include <iostream>
#include "Box.h"

#define PRINT(X) cout << #X<<"::" <<X<<endl;
#define TRACE(s) cerr <<"Testando " <<#s<<": \n" << endl; s 
using namespace std;

int main()
{   
    cout << "Teste de criação de caixa vazia" << endl;
    TRACE(Box b1);
    cout << "Caixa criada: "<< endl;
    PRINT(b1);
    cout << "Area da caixa: "<< endl;
    PRINT(b1.area());
    cout << "Volume da caixa: "<< endl;
    PRINT(b1.volume());

    cout << "Teste de criação de caixa quadrada de lado 2" << endl;
    TRACE(Box b2(2, 2, 2));
    cout << "Caixa criada: " << endl;
    PRINT(b2);
    cout << "Area da caixa: "<< endl;
    PRINT(b2.area());
    cout << "Volume da caixa: "<< endl;
    PRINT(b2.volume());

    cout << "Testando criacao de caixa passando seus vertices "<< endl;
    TRACE(Box b3(Ponto3D(2, 2, 2), 
                 Ponto3D(2, 4, 2),
                 Ponto3D(4, 4, 2),  
                 Ponto3D(4, 2, 2),
                 Ponto3D(2, 2, 6),
                 Ponto3D(4, 4, 6), 
                 Ponto3D(2, 4, 6), 
                 Ponto3D(4, 2, 6)));
    cout<< "Caixa criada: "<< endl;
    PRINT(b3);
    cout << "Area da caixa: "<< endl;
    PRINT(b3.area());
    cout << "Volume da caixa: "<< endl;
    PRINT(b3.volume());             

    return 0;
}   