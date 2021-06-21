#include <iostream>
#include "Ponto2D.h"
using namespace std;

int main(){
    cout << "Programa Teste classe Ponto2D\n";
    Ponto2D origem, P1(1), P2(1, 2), P3(2, 3);
    cout << "Imprimindo pontos gerados: ";
    origem.print();
    P1.print();
    P2.print();
    P3.print();
    
    cout << "Calculo de distância entre pontos e a origem. \n";
    double d = origem.distToOrig();
    cout << "Coordenadas x = 0 e y = 0: " << d;
    d = P1.distToOrig();
    cout << "\n Coordenadas x = 1 e y = 0: " << d;

    cout << "\n Calculo da distancia entre dois pontos quaisquer. \n";
    d = P1.distTo(P2);
    cout << "Distancia entre os pontos (1, 0) e (1, 2): " << d;
    d = origem.distTo(P3);
    cout << "Distancia entre os pontos (0, 0) e (2, 3): " << d;

    cout << "\n Modificacao das coordenadas de um ponto somando-o a outro ponto. \n";
    P1.sumOf(P2);
    cout << "Soma das coordenadas (1, 0) com (2, 1): ";
    P1.print();

    cout << "\n Criacao de novo ponto baseado na soma das coordenadas de outros dois pontos (sem modificar qualquer um).";
    Ponto2D PNew = P2.sumOf(&P3);
    cout << "\n Soma de (2, 1) e (3, 2): ";
    PNew.print();
}