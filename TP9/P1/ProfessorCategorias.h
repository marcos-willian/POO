#ifndef PROFESSOR_CATEGORIA_H
#define PROFESSOR_CATEGORIA_H
#include <string>
#include "Professor.h"
#include <iostream>
#include <typeinfo>

class ProfHorista: public Professor {
        double numHorasTrabalhadas;
        double valorHora;
        std::ostream& opeOutStream(std::ostream& out) const{
            out<<"Tipo de professor: "<<typeid(*this).name()<<std::endl;
            out<<"Nome: "<<getName()<<"\tSalario: "<<getSalario()<<std::endl;
            return out;
        };
    public:
        ProfHorista(std::string n, double nht, double vh) : Professor(n), 
                                                            numHorasTrabalhadas(nht),
                                                            valorHora(vh) {}; 
        double getSalario() const;
        ~ProfHorista() {};
};

class ProfIntegral: public Professor {
        double salarioMensal;
        std::ostream& opeOutStream(std::ostream& out) const{
            out<<"Tipo de professor: "<<typeid(*this).name()<<std::endl;
            out<<"Nome: "<<getName()<<"\tSalario: "<<getSalario()<<std::endl;
            return out;
        }
    public:
       ProfIntegral(std::string n, double sm) : Professor(n),
                                                salarioMensal(sm) {};
       double getSalario() const;
       ~ProfIntegral(){};
};

#endif