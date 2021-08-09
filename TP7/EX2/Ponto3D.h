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
        };

        double get_z() const{ return z;}
    
    private:
        double z;
};


#endif //PONTO3D_H