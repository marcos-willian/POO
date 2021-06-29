#include "Ponto2D.h"
#include <math.h>
#include <iostream>
#include <vector>

inline Ponto2D::Ponto2D(int c_x , int c_y) : x(c_x), y(c_y), id(getNextId()) {};
inline std::vector<double> Ponto2D::getPonto2D() {std::vector<double> ret({this->x, this->y}); return ret;};
// Função membro para escrever (imprimir) as coordenadas do ponto na tela
inline void Ponto2D::setPonto2D(const Ponto2D& P) {this->x = P.x; this->y = P.y;};

int Ponto2D::getNextId(){
    int id = random()%1000;
    int idInitial = id;
    while(idFree[id]){
        id = (id + 1)%1000;
        if(id == idInitial){
            std::cerr<<"\n\nNão possui Id disponível\n\n";
            exit(1);
        }
    }
    idFree[id] = true; 
    
    return id;
}

double Ponto2D::distToOrig() const{
    return sqrt(pow(this->x,2) + pow(this->y,2));
}

double Ponto2D::distTo(const Ponto2D& P) const{
    return sqrt(pow((this->x - P.x), 2) + pow((this->y - P.y), 2));
}

void Ponto2D::sumOf(const Ponto2D& P) {
    this->x += P.x;
    this->y += P.y;
}

Ponto2D Ponto2D::sumOf(const Ponto2D* P) const{
    Ponto2D P3( (this->x + P->x), (this->y + P->y) );
    return P3;
}

bool Ponto2D::idFree[1001] = {false};