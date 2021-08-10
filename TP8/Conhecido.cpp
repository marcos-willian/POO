#include "Conhecido.h"
#include <iostream>
#include <string>

void Conhecido::print() const{
    Pessoa::print();
    std::cout <<"Email: "<<email<<std::endl;
}
void Conhecido::setByInput(){
    std::string nome;
    int idade;
    std::cout <<"\n-------------Conhecido----------------\n";
    std::cout <<"Insira o nome: ";
    std::cin >> nome;
    std::cout <<"Insira a idade: ";
    std::cin >> idade;
    if( idade <= 0){
        throw std::invalid_argument("Idade deve ser maior que 0!!\n");
    }
    Pessoa::set(nome, idade);
    std::cout <<"Insira o email: ";
    std::cin >> email;
    if(email.empty()){
        throw std::invalid_argument("Email vazio!!\n");
    }
    if(email.find('@') == email.npos){
        throw std::invalid_argument("Fomato do email errado!!\n");
    }
}

void Conhecido::printEmail(){
    print();
}