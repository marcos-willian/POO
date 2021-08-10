#ifndef PESSOA
#define PESSOA

#include <string>
#include <vector>

class Pessoa{
    private:
        int idade;
        std::string nome;
    public:
        Pessoa(const std::string& name = "indefinido", const int& age = 0) : idade(age), nome(name) {};
        virtual void print() const;
        int getIdade() { return idade; }
        std::string getNome() { return nome; }
        void set(const std::string& nome, const int& idade);
        virtual void setByInput() = 0;
        virtual void printEmail() {};
        virtual void printAniversario() {};
};




#endif