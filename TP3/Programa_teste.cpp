#include <iostream>
#include "Ponto2D.h"
using namespace std;

void estouraLimite(int i)
{
    if (i < 1001)
    {
        Ponto2D ponto(i);
        ponto.printId();
        cout << "   ";
        estouraLimite(i+1);
    }
}

int main(){
    cout << "Programa Teste classe Ponto2D";
    Ponto2D origem, P1(1), P2(1, 2), P3(2, 3);
    cout << "\n\n Imprimindo pontos gerados: ";
    origem.print();
    P1.print();
    P2.print();
    P3.print();
    
    cout << "\n\n Calculo de distância entre pontos e a origem.";
    double d = origem.distToOrig();
    cout << "\n\n Coordenadas (0, 0): " << d;
    d = P1.distToOrig();
    cout << "\n Coordenadas (1, 0): " << d;
    d = P3.distToOrig();
    cout << "\n Coordenadas (2, 3): " << d;

    cout << "\n\n Calculo da distancia entre dois pontos quaisquer.";
    d = P1.distTo(P2);
    cout << "\n\n Distancia entre os pontos (1, 0) e (1, 2): " << d;
    d = origem.distTo(P3);
    cout << "\n Distancia entre os pontos (0, 0) e (2, 3): " << d;
    d = P2.distTo(P3);
    cout << "\n Distancia entre os pontos (1, 2) e (2, 3): " << d;

    cout << "\n\n Modificacao das coordenadas de um ponto somando-o a outro ponto.";
    P1.sumOf(P2);
    cout << "\n\n Soma das coordenadas (1, 0) com (2, 1): ";
    P1.print();
    origem.sumOf(P2);
    cout << "\n Soma das coordenadas (0, 0) com (2, 1): ";
    origem.print();

    cout << "\n\n Criacao de novo ponto baseado na soma das coordenadas de outros dois pontos (sem modificar qualquer um).";
    Ponto2D PNew = P2.sumOf(&P3);
    cout << "\n Soma de (2, 1) e (3, 2): ";
    PNew.print();
    cout << "\n\n";
    // Desaloca todos os ids
    origem.~Ponto2D();
    P1.~Ponto2D();
    P2.~Ponto2D();
    P3.~Ponto2D();
    PNew.~Ponto2D();
    cout << "\n\n Testa criação de identificadores únicos";
    cout << "\n O teste consiste em estourar o limite definido de pontos, de modo que ao tentar criar um ponto alem do limite,";
    cout << "\n ha o estouro da pilha retornando uma mensagem de erro: \n\n";

    estouraLimite(0);
}