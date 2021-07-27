#ifndef Ponto3D_H
#define Ponto3D_H
#include <iostream>
#include "Ponto2D.h"
class Ponto3D: public Ponto2D{
    
    public:
        Ponto3D(double xx = 0, double yy = 0, double zz=0) : Ponto2D(xx, yy), z(zz) {};
        friend std::ostream& operator<< (std::ostream &op, const Ponto3D &p);
        Ponto3D& operator= (const Ponto2D &p);
        Ponto3D& operator= (const Ponto3D &p);
        void set(double nx = 0, double ny = 0, double nz=0){
            Ponto2D::set(nx, ny);
            z = nz;
        }
        double get_z() { return z;}
    
    private:
        double z;
};

std::ostream& operator<< (std::ostream &op, const Ponto3D &p){
    op << (Ponto2D) p;
    op << "z = " << p.z << std::endl;
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

#endif //PONTO3D_H