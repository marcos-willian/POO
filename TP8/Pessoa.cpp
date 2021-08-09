#include "Pessoa.h"
#include <string>

Pessoa::Pessoa(){
    this->nome = "indefinido";
    this->idade = 0;
}

Pessoa::Pessoa(std::string nome, int idade){
    this->nome = nome;
    this->idade = idade;
}