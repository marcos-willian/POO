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
    PRINT(p1);
    PRINT(p2);

    TRACE(p2 = p1);
    PRINT(p2);


    Ponto3D p3(2,4.5,5), p4;
    TRACE(p4.set(1,0.3,12));
    PRINT(p3);
    PRINT(p4);

    TRACE(p4 = p3);
    PRINT(p4);

    TRACE(p4 = p1);
    PRINT(p4);
    PRINT(p4.get_x());
    PRINT(p4.get_y());


    return 0;
}   