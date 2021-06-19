#include <iostream>
#include "Tempo.h"
using namespace std;

int main(){
    cout<<"Programa teste classe Tempo\n";
    Tempo tempo1, tempo2(1), tempo3(2,1), tempo4(3,27,1), tempo5(4,3,61,59), tempo6(3, 23, 58, 60); //Testa inicialização
    cout<<"\n\nTeste imprimir tempo e inicialização com consistência\n";
    tempo1.print();     // dia = 0, hora = 0, min = 0, seg = 0
    tempo2.print();     // dia = 1, hora = 0, min = 0, seg = 0
    tempo3.print();     // dia = 2, hora = 1, min = 0, seg = 0
    tempo4.print();     // dia = 4, hora = 3, min = 1, seg = 0
    tempo5.print();     // dia = 4, hora = 4, min = 1, seg = 59
    tempo6.print();     // dia = 3, hora = 23, min = 59, seg = 0

    cout<<"\n\nTesta consistencia\n";
    int i[4] = {100, 24, 59, 60};
    cout<<"Valor de inicio: "<<i[0]<<" Dias, "<<i[1]<<" Horas, "<<i[2]<<" Minutos, "<<i[3]<<" Segundos.\n";
    cout<<"Valor gerado: ";     // dia = 101, hora = 1, min =0, seg = 0
    Tempo aux(i[0], i[1], i[2], i[3]);
    aux.print();


    cout<<"\n\nDecrementar\n";
    cout<<"Tempo inicial: ";
    tempo1.print();
    tempo1.DecrementaSegundo(); // dia = 0, hora = 0, min =0, seg = 0
    cout<<"Tempo final: ";
    tempo1.print();
    cout<<endl;
    cout<<"Tempo inicial: ";
    tempo2.print();
    tempo2.DecrementaSegundo(); // dia = 2, hora = 0, min =59, seg = 59
    cout<<"Tempo final: ";
    tempo2.print();
    cout<<endl;

    cout<<"\n\nIncrementar\n";
    cout<<"Tempo inicial: ";
    tempo5.print();
    tempo5.IncrementaSegundo();     // dia = 4, hora = 4, min = 2, seg = 0
    cout<<"Tempo final: ";
    tempo5.print();
    cout<<"Tempo inicial: ";
    tempo6.print();
    tempo6.IncrementaSegundo();     // dia = 3, hora = 23, min = 59, seg = 1
    cout<<"Tempo final: ";
    tempo6.print();
    cout<<endl;

    cout<<"\n\nSoma tempo\n";
    cout<<"Tempo 1: ";
    tempo3.print();
    cout<<"Tempo 2: ";
    tempo4.print();
    cout<<"Tempo final: ";
    aux = aux.SomaTempo(tempo3, tempo4);
    aux.print();
    cout<<endl;

    cout<<"Tempo 1: ";
    tempo2.print();
    cout<<"Tempo 2: ";
    tempo6.print();
    cout<<"Tempo final: ";
    aux = aux.SomaTempo(tempo2, tempo6);
    aux.print();
    cout<<endl;

    cout<<"\n\nLer tempo\n";
    int auxI[4];
    tempo2.getTempo(auxI);
    cout<<"Tempo lido: "<<auxI[0]<<" "<<auxI[1]<<" "<<auxI[2]<<" "<<auxI[3]<<endl;
}