#ifndef AMIGO_H
#define AMIGO_H 

#include "Pessoa.h"
#include <string.h>

class Amigo : public Pessoa {
    private:
        std::string dataAniversario;
    public:
        Amigo() : Pessoa(), dataAniversario("indefinido"){};
        void print() const;
        void set(const std::string& Bdate) {dataAniversario = Bdate;};
        void setByInput();
};

#endif