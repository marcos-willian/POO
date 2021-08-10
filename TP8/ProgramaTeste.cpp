#include <iostream>
#include "Agenda.h"
using namespace std;


int main(){
    int n;
    cout<<"Insira a quantidade de pessoas da agenda: ";
    cin>>n;
    srand((unsigned int) time (NULL));
    Agenda agenda(n);
    cout<<"Nesta agenda a quantidade de Amigos é: "<< agenda.getQtdAmigos();
    cout<<"\nA quantidade de Conhecidos é: "<< agenda.getQtdConhecidos()<<endl;

    agenda.addInfomacoes();

    agenda.imprimeAniversarios();

    agenda.imprimeEmail();
    

}