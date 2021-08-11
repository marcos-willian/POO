#ifndef CONHECIDO_H
#define CONHECIDO_H 

#include "Pessoa.h"
#include <string.h>

class Conhecido : public Pessoa {
    private:
        std::string email;
    public:
        Conhecido() : Pessoa(), email("indefinido"){};
        void print() const;
        void set(const std::string& EMAIL) { email = EMAIL; };
        void setByInput();
        void printData();
};
#endif