#include "Pessoa.h"
#include <string>
#include <iostream>

void Pessoa::print() const{ 
    std::cout <<"Nome: "<<nome;
    std::cout <<"\tIdade: "<<idade<<std::endl;
}

void Pessoa::set(const std::string& name, const int& age){
    idade = age;
    nome = name;
}
