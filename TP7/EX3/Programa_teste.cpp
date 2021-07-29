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
    TRACE(BusinessTraveler b1;)
    PRINT(b1);

    TRACE(BusinessTraveler b2("b2");)
    PRINT(b2);

    TRACE(BusinessTraveler b3(b2);)
    PRINT(b3);
    
    TRACE(b1 = b2);
    PRINT(b1);

    TRACE(atributionTraveler(b3,b2);)
    PRINT(b3);
}
