#ifndef PONTO2D_H
#define PONTO2D_H
#include <iostream>

class Ponto2D{
    
     public:
        Ponto2D(double xx = 0.0, double yy = 0.0):x(xx),y(yy){ };
        friend std::ostream& operator<< (std::ostream &op, const Ponto2D &p);
        Ponto2D& operator= (const Ponto2D &p);
        ~Ponto2D(){};
        double get_x(void) const { return x; }
        double get_y(void) const { return y; }
        void set (double nx, double ny) { x=nx; y=ny; }
    
    private:                
        double x;
        double y;
};


#endif // PONTO2D_H