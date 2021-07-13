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
    Ponto2D(int c_x = 0, int c_y = 0) : x(c_x), y(c_y), id(getNextId()) {};

    ~Ponto2D() {idFree[this->id] = false;}

    //Construtor cópia
    Ponto2D(const Ponto2D& P) : x(P.x), y(P.y), id(getNextId()) {};

    void setPonto2D(const Ponto2D& P) {this->x = P.x; this->y = P.y;};

    std::vector<double> getPonto2D() {std::vector<double> ret({this->x, this->y}); return ret;};

    // Função membro para escrever (imprimir) as coordenadas do ponto na tela
    void print() const {std::cout<<"("<<this->x<<","<<this->y<<")";}

    // Função membro para calcular a distância do ponto a origem do sistema de coordenadas cartesiano
    double distToOrig() const;

    // Função membro para calcular a distância entre dois pontos 
    double distTo(const Ponto2D& P) const;
    
    // Função membro que modifica as coordenadas do objeto corrente p1 somando às 
    // suas coordenadas um novo ponto P passado por argumento.
    void sumOf(const Ponto2D& P); 

    // Função membro que retorna um ponto p3 que é o resultado da soma entre dois pontos p1 e p2, 
    // onde p1 é o objeto que chama a função. 
    Ponto2D sumOf(const Ponto2D& P) const;

};

bool Ponto2D::idFree[1001] = {false};


#endif //Ponto2d.h
