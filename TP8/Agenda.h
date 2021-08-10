#ifndef AGENDA_H
#define AGENDA_H 

#include "Pessoa.h"
#include "Amigo.h"
#include "Conhecido.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <functional>

class Agenda {
    private:
        std::vector<std::reference_wrapper<Pessoa>> pessoas;
        int qtdAmigos;
        int qtdConhecidos;
    public:
        Agenda(const int& qtdPessoas);
        void addInfomacoes();
        void imprimeAniversarios();
        void imprimeEmail();
        int getQtdAmigos() { return qtdAmigos; };
        int getQtdConhecidos() {return qtdConhecidos; };
};
#endif