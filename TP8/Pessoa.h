#ifndef PESSOA
#define PESSOA

#include <string>

class Pessoa{
    private:
        int idade;
        std::string nome;
    public:
        Pessoa(std::string nome, int idade);
        Pessoa();
};

#endif