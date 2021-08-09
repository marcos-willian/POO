#ifndef PONTO2D_H
#define PONTO2D_H
#include <iostream>
class Ponto2D{
    
     public:
        Ponto2D(double xx = 0.0, double yy = 0.0):x(xx),y(yy){ };
        friend std::ostream& operator<< (std::ostream &op, const Ponto2D &p);
        Ponto2D& operator= (const Ponto2D &p);
        ~Ponto2D(){};
        double get_x(void) { return x; }
        double get_y(void) { return y; }
        void set (double nx, double ny) { x=nx; y=ny; }
    
    private:                
        double x;
        double y;
};

std::ostream& operator<< (std::ostream &op, const Ponto2D &p){
            op << std::endl;
            op << "x = " << p.x << std::endl;
            op << "y = " << p.y << std::endl;
            return op;
}

Ponto2D& Ponto2D::operator= (const Ponto2D &p){
    x = p.x;
    y = p.y;
    return *this;
}
#endif // PONTO2D_H