#include <iostream>
#include "BusinessTraveler.h"
#include "Pager.h"
#include "Traveler.h"
using namespace std;
#define PRINT(X) cout << #X<<"::\n" <<X<<endl;
#define TRACE(s) cerr <<"\nTestando: " <<#s<< endl; s 

void atributionTraveler(Traveler &t, BusinessTraveler b){
   t = b;
}

int main(){ 
    cout << "Testando construtor default de Business Traveler"<< endl;
    TRACE(BusinessTraveler b1;)
    PRINT(b1);

    cout << "Testando construtor de Business Traveler por passagem de parametro"<< endl;
    TRACE(BusinessTraveler b2("b2");)
    PRINT(b2);

    cout << "Testando construtor de Business Traveler por copia"<< endl;
    TRACE(BusinessTraveler b3(b2);)
    PRINT(b3);
    
    cout<< "Testando sobrecarga de operador '=' para classe Business Traveler"<< endl;
    TRACE(b1 = b2);
    PRINT(b1);

    cout<< "Testando funcao de atribuicao de Business Traveler"<< endl;
    TRACE(atributionTraveler(b3,b2);)
    PRINT(b3);
}
