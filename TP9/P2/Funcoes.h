#ifndef FUNCOES_H
#define FUNCOES_H
#include "Funcao.h"
#include <cmath>
#include <string>
#include <iostream>

class Quadratica: public Funcao{
    public:
        Quadratica( const double& a0 = 1, 
                    const double& a1 = 1,    
                    const double& a2 = 1, 
                    const double& a3 = 0) : Funcao(a0, a1, a2, a3) {};
        ~Quadratica() {};
        double func(const double& input);
        std::string funcDef();
        static void formato() {std::cout<<"Quadratica::\ta0*x^2 + a1*x + a2\n";}
};

class Sinc: public Funcao{
    public:
        Sinc( const double& a0 = 1, 
              const double& a1 = 0,    
              const double& a2 = 0, 
              const double& a3 = 0) : Funcao(a0, a1, a2, a3) {};
        ~Sinc() {};
        double func(const double& input);
        std::string funcDef();
        static void formato() {std::cout<<"Sinc::\ta0*(sen(x)/x)\n";}
};

class Linear: public Funcao{
    public:
        Linear( const double& a0 = 1, 
                const double& a1 = 1,    
                const double& a2 = 0, 
                const double& a3 = 0) : Funcao(a0, a1, a2, a3) {};
        ~Linear() {};
        double func(const double& input);
        std::string funcDef();
        static void formato() {std::cout<<"Linear::\ta0*x + a1\n";}
};

class Cubica: public Funcao{
    public:
        Cubica( const double& a0 = 1, 
                const double& a1 = 1,    
                const double& a2 = 1, 
                const double& a3 = 1) : Funcao(a0, a1, a2, a3) {};
        ~Cubica() {};
        double func(const double& input);
        std::string funcDef();
        static void formato() {std::cout<<"Cúbica::\ta0*x^3 + a1*x^2 + a2*x + a3\n";}
};

class Log: public Funcao{
    public:
        Log( const double& a0 = 1, 
             const double& a1 = 10,    
             const double& a2 = 0, 
             const double& a3 = 0) : Funcao(a0, a1, a2, a3) {};
        ~Log() {};
        double func(const double& input);
        std::string funcDef();
        static void formato() {std::cout<<"Log::\ta0*log(x) --base: a1\n";}
};


#endif