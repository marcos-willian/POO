#include "Amigo.h"
#include <iostream>


void Amigo::print() const {
    Pessoa::print();
    std::cout <<dataAniversario<<std::endl;
}

void Amigo::setByInput(){
    std::string nome;
    int idade;
    std::cout <<"\n-------------Amigo----------------\n";
    std::cout <<"Insira o nome: ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    std::cout <<"Insira a idade: ";
    std::cin >> idade;
    if( idade <= 0){
        throw std::invalid_argument("Idade deve ser maior que 0!!\n");
    }
    Pessoa::set(nome, idade);
    std::cout <<"insira a data de aniversário (DD/MM/AAAA): ";
    std::cin.ignore();
    std::getline(std::cin, dataAniversario);
    if(dataAniversario.empty()) {
        throw std::invalid_argument("Erro ao digitar!!\n");
    }
    if(dataAniversario.length() != 10){
        throw std::invalid_argument("Data invalida!!\n");
    }
    int dia = atoi(dataAniversario.substr(0,1).c_str());
    if(  0 > dia || dia > 31){
        throw std::invalid_argument("Dia invalido!!\n");
    }
    int mes = atoi(dataAniversario.substr(3,4).c_str());
    if( 0 >= mes || mes > 12){
        throw std::invalid_argument("Mes invalido!!\n");
    }
    int ano = atoi(dataAniversario.substr(6,9).c_str());
    if( 0 > ano){
        throw std::invalid_argument("Ano invalido!!\n");
    }
}