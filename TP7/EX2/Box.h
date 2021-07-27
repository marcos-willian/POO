#ifndef BOX_H
#define BOX_H
#include "Ponto3D.h"
#include <iostream>
#include <cmath>

class Box {
    private:
        double altura;
        double profundidade;
        double largura;
        Ponto3D vertices[8] = {0};
    public:
        Box(double alt = 0, double lar = 0, double prof = 0);
        Box(Ponto3D p0, Ponto3D p1, Ponto3D p2, Ponto3D p3, Ponto3D p4, Ponto3D p5, Ponto3D p6, Ponto3D p7);
        Box(const Box& B);
        Box& operator= (const Box& B);
        friend std::ostream& operator<< (std::ostream& op, const Box& B);
        double area() const { return (2*altura*largura + 2*largura*profundidade + 2*altura*profundidade); };
        double volume() const { return (altura*profundidade*largura); };
        const Ponto3D * getVertices() const { return vertices; };
        double getAltura() const { return altura; };
        double getProfundidade() const { return profundidade; };
        double getLargura() const { return largura; };
};



#endif // BOX_H