#ifndef PONTO2D
#define PONTO2D
#include <iostream>
#include <vector>

class Ponto2D{
private:
    double x, y;
    const int id;
    static bool idFree[1001];
    int getNextId();

public:

    Ponto2D(int c_x = 0, int c_y = 0);
    ~Ponto2D() {idFree[this->id] = false;};
    // Função membro para escrever (imprimir) as coordenadas do ponto na tela
    void print() const {std::cout<<"("<<this->x<<","<<this->y<<")";}
    // Função criada para apresentar o valor dos ids gerados de cada ponto
    void printId() const{std::cout<<"Id do ponto ("<<this->x<<","<<this->y<<"): "<< this->id;}
    // Função membro para calcular a distância do ponto a origem do sistema de coordenadas cartesiano
    double distToOrig() const;
    // Função membro para calcular a distância entre dois pontos 
    double distTo(const Ponto2D& P) const;
    // Ponto2D getPonto2D();
    std::vector<double> getPonto2D();
    void setPonto2D(const Ponto2D& P);
    // Função membro que modifica as coordenadas do objeto corrente p1 somando às 
    // suas coordenadas um novo ponto P passado por argumento.
    void sumOf(const Ponto2D& P); 
    // Função membro que retorna um ponto p3 que é o resultado da soma entre dois pontos p1 e p2, 
    // onde p1 é o objeto que chama a função. 
    Ponto2D sumOf(const Ponto2D* P) const;
};

#endif
