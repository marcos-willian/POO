#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H
#include "Professor.h"
#include <vector>
#include <iostream>
#include <functional>

class Universidade {
    private:
        std::vector<std::reference_wrapper<const Professor>> professores;
        double totalpago;
    public:
        Universidade() : totalpago(0) {};
        ~Universidade(){professores.clear();};
        void addProfessor(const Professor& prof) {professores.push_back(prof); totalpago += prof.getSalario();}
        double totalPago() const {return totalpago;};
        void imprimeProfs() const;
};

#endif