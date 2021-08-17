#include "Universidade.h"
#include "ProfessorCategorias.h"
#include <iostream>
using namespace std;



int main(){
    Universidade UFMG;
    //Adiciona professores
    ProfHorista m("Marcos", 176, 19.59);
    ProfIntegral d("Denis", 15500.41);
    ProfHorista g("Gabriel", 120, 100);
    UFMG.addProfessor(m);
    UFMG.addProfessor(d);
    UFMG.addProfessor(g);
    
    UFMG.imprimeProfs();

    cout<<"O total pago é: "<<UFMG.totalPago()<<endl;
}