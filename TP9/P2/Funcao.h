#ifndef FUNCAO_H
#define FUNCAO_H
#include <string>
#include <cmath>
#include <iostream>

class Funcao{
    protected:
        const double termos[4];
    public:
        Funcao(const double& a0 = 0, 
               const double& a1 = 0,    
               const double& a2 = 0, 
               const double& a3 = 0) : termos{a0, a1, a2, a3} {};
        virtual ~Funcao() {};
        double getIntegral(const double& limInferior, const double& limSuperior, const double& precisao = 1000);
        virtual double func(const double& input) = 0;
        double operator()(const double& input){ return this->func(input); };
        void plot(const double& limInferior, const double& limSuperior, const int xlim = 50, const int ylim = 18);
        virtual std::string funcDef() = 0;
};

#endif