#include <iostream>
#include "Box.h"

#define PRINT(X) cout << #X<<"::" <<X<<endl;
#define TRACE(s) cerr <<"Testando " <<#s<<": \n" << endl; s 
using namespace std;

int main()
{
    TRACE(Box b1);

    PRINT(b1);
    PRINT(b1.area());
    PRINT(b1.volume());

    TRACE(Box b2(2, 2, 2));
    PRINT(b2);
    PRINT(b2.area());
    PRINT(b2.volume());

    TRACE(Box b3(Ponto3D(2, 2, 2), 
                 Ponto3D(2, 4, 2),
                 Ponto3D(4, 4, 2),  
                 Ponto3D(4, 2, 2),
                 Ponto3D(2, 2, 6),
                 Ponto3D(4, 4, 6), 
                 Ponto3D(2, 4, 6), 
                 Ponto3D(4, 2, 6)));
    PRINT(b3);
    PRINT(b3.area());
    PRINT(b3.volume());             

    return 0;
}   