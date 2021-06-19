#include <iostream>
#include "Tempo.h"
using namespace std;

int main(){
    cout<<"Programa teste classe Tempo\n";
    Tempo tempo1, tempo2(1), tempo3(2,1), tempo4(3,23,1), tempo5(4,3,2,59); //Testa inicialização
    cout<<"\n\nTeste imprimir tempo e inicialização\n";
    tempo1.PrintTempo();
    tempo2.PrintTempo();
    tempo3.PrintTempo();
    tempo4.PrintTempo();
    tempo5.PrintTempo();

    cout<<"\n\nTesta concistencia\n";
    int i[4] = {100, 24, 59, 60};
    cout<<"Valor de inicio: "<<i[0]<<" Dias, "<<i[1]<<" Horas, "<<i[2]<<" Minutos, "<<i[3]<<" Segundos.\n";
    cout<<"Valor gerado: ";
    Tempo aux(i[0], i[1], i[2], i[3]);
    aux.PrintTempo();


    cout<<"\n\nDecrementar\n";
    cout<<"Tempo inicial: ";
    tempo1.PrintTempo();
    cout<<endl;
    tempo1.DecrementaSegundo();
    cout<<"Tempo final: ";
    tempo1.PrintTempo();
    cout<<endl;

    cout<<"\n\nIncrementar\n";
    cout<<"Tempo inicial: ";
    tempo5.PrintTempo();
    cout<<endl;
    tempo5.IncrementaSegundo();
    cout<<"Tempo final: ";
    tempo5.PrintTempo();
    cout<<endl;

    cout<<"\n\nSoma tempo\n";
    cout<<"Tempo 1: ";
    tempo3.PrintTempo();
    cout<<endl;
    cout<<"Tempo 2: ";
    tempo4.PrintTempo();
    cout<<endl;
    cout<<"Tempo final: ";
    Tempo aux2 = aux.SomaTempo(tempo3, tempo4);
    aux2.PrintTempo();
    cout<<endl;

    cout<<"\n\nLer tempo\n";
    int auxI[4];
    tempo2.getTempo(auxI);
    cout<<"Tempo lido: "<<auxI[0]<<" "<<auxI[1]<<" "<<auxI[2]<<" "<<auxI[3]<<endl;
}