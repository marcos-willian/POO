#include "Ponto2D.h"
#include <math.h>
#include <iostream>
int Ponto2D::getNextId(){
    int id = random()%1000;
    int idInitial = id;
    while(idFree[id]){
        id = (id + 1)%1000;
        if(id == idInitial){
            std::cerr<<"Não possui Id disponível";
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

Ponto2D Ponto2D::sumOf(const Ponto2D& P) const{
    Ponto2D P3( (this->x + P.x), (this->y + P.y) );
    return P3;
}