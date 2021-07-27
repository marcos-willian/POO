#include "Box.h"
#include "Ponto2D.h"
#include "Ponto3D.h"
double distP1P2(const Ponto3D& p1, const Ponto3D& p2){
    return (std::sqrt( std::pow((p1.get_x() - p2.get_x()), 2) + std::pow((p1.get_y() - p2.get_y()), 2) + std::pow((p1.get_z() - p2.get_z()), 2)));
}

Box::Box(double alt, double lar, double prof){
    vertices[0] = Ponto3D(0, 0, 0);
    vertices[1] = Ponto3D(0, prof, 0);
    vertices[2] = Ponto3D(lar, prof, 0);
    vertices[3] = Ponto3D(lar, 0, 0);
    vertices[4] = Ponto3D(0, 0, alt);
    vertices[5] = Ponto3D(0, prof, alt);
    vertices[6] = Ponto3D(lar, prof, alt);
    vertices[7] = Ponto3D(lar, 0, alt);
    altura = alt;
    largura = lar;
    profundidade = prof;
}

Box::Box(Ponto3D p0, Ponto3D p1, Ponto3D p2, Ponto3D p3, Ponto3D p4, Ponto3D p5, Ponto3D p6, Ponto3D p7) {
    vertices[0] = p0; 
    vertices[1] = p1; 
    vertices[2] = p2; 
    vertices[3] = p3; 
    vertices[4] = p4; 
    vertices[5] = p5; 
    vertices[6] = p6; 
    vertices[7] = p7;
    altura = distP1P2(vertices[4], vertices[0]);
    largura = distP1P2(vertices[3], vertices[0]);
    profundidade = distP1P2(vertices[1], vertices[0]);
}

Box::Box(const Box& B){
    for (int i = 0; i < 8; i++){
        vertices[i] = B.vertices[i];
    }
    altura = B.altura;
    largura = B.largura;
    profundidade = B.profundidade;    
}

Box& Box::operator= (const Box& B){
    for (int i = 0; i < 8; i++){
        vertices[i] = B.vertices[i];
    }
    altura = B.altura;
    largura = B.largura;
    profundidade = B.profundidade; 
    return *this;
}

std::ostream& operator<< (std::ostream &op, const Ponto2D &p){
            op << "(" << p.x;
            op << ", " << p.y;
            return op;
}

Ponto2D& Ponto2D::operator= (const Ponto2D &p){
    x = p.x;
    y = p.y;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Box& B){
    os << "\nAltura: "<< B.altura;
    os << "\nLargura: "<< B.largura;
    os << "\nProfundidade: "<< B.profundidade;
    os << "\nVertices: \n";
    for (int i = 0; i < 8; i++)
    {
        os << i << ":\t" << B.vertices[i] << "\n";
    }
    os<<std::endl;
    return os;
}

std::ostream& operator<< (std::ostream &op, const Ponto3D &p){
    op << (Ponto2D) p;
    op << ", " << p.z << ")";
    return op;

}

Ponto3D& Ponto3D::operator= (const Ponto2D &p) {
    Ponto2D::operator=(p);
    return *this;
}

Ponto3D& Ponto3D::operator= (const Ponto3D &p) {
    Ponto2D::operator=(p);
    z = p.z;
    return *this;
}

