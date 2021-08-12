#include "Agenda.h"


Agenda::Agenda(const int& qtdPessoas) {
    qtdAmigos = 0;
    qtdConhecidos = 0;
    srand((unsigned int) time (NULL));
    for(int i = 0; i < qtdPessoas; i++){
        int choose = rand() < RAND_MAX/2;
        if(choose == 1){
            qtdAmigos++;
            Amigo *amigo = new Amigo();
            pessoas.push_back(*amigo);
        }else if(choose == 0){
            qtdConhecidos++;
            Conhecido *conhecido = new Conhecido();
            pessoas.push_back(*conhecido);            
        }
    }
}

void Agenda::addInfomacoes(){ 
    std::cout << "Escreva as informações das pessoas:\n";
    for(std::vector<std::reference_wrapper<Pessoa>>::const_iterator pessoa = this->pessoas.begin(); pessoa != this->pessoas.end(); ++pessoa){
        try{
            pessoa->get().setByInput();
        }catch(std::invalid_argument& err){
            std::cout<<err.what()<<"Falha!! ---- Esreva novamente\n";
            --pessoa;
        }
    }
}

void Agenda::imprimeAniversarios(){
    int i = 0;
    std::cout<<"\nAniversário dos amigos:\n";
    for(std::vector<std::reference_wrapper<Pessoa>>::const_iterator pessoa = this->pessoas.begin(); pessoa != this->pessoas.end(); ++pessoa){
        if(typeid(pessoa->get()) == typeid(Amigo)){
            pessoa->get().print();
        }
        i++;
    }
}

void Agenda::imprimeEmail(){
    int i = 0;
    std::cout<<"\nEmail dos cohecidos:\n";
    for(std::vector<std::reference_wrapper<Pessoa>>::const_iterator pessoa = this->pessoas.begin(); pessoa != this->pessoas.end(); ++pessoa){
        if(typeid(pessoa->get()) == typeid(Conhecido)){
            pessoa->get().print();
        }
    }
}