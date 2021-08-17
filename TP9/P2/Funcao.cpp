#include "Funcao.h"

void Funcao::plot(const double& limInferior, const double& limSuperior, const int xlim /*= 50*/, const int ylim /*= 20*/){
    if(limInferior > limSuperior){
            throw std::invalid_argument("O limite superior deve ser maior ou igual ao limite inferior!\n");
        }
        std::cout<<("Função: " + funcDef())<<std::endl;
        std::string inferior = std::to_string(limInferior).substr(0, std::to_string(limInferior).find(".") +  3);
        std::string superior = std::to_string(limSuperior).substr(0, std::to_string(limSuperior).find(".") +  3);
        double min = INFINITY, max = 0;
        double variacao = (limSuperior - limInferior)/(xlim - 3);
        double y[xlim - 3];
        char plot[ylim][xlim];
        for (int i = 0; i < ylim; i++){   
            for(int j = 0; j < xlim; j++){
                plot[i][j] = ' ';
                if(j == 0){
                    if(i == 0){
                        plot[i][j] = 'y';
                    }
                }
                if(j == 1){
                    if(i != 0 and i < (ylim - 1)){
                        plot[i][j] = '|';
                    }
                }
                if(i == (ylim - 2)){
                    if(j != (xlim - 2) and j > 1){
                        plot[i][j] = '_';
                    }
                }
                if(j == (xlim - 1)){
                    if(i == (ylim - 1)){
                        plot[i][j] = 'x';
                    }else{
                        plot[i][j] = '\n';
                    }
                }
            }
        }
        for(int i = 1; i < (inferior.size() + 1); i++ )
            plot[ylim - 1][i] = inferior.at(i - 1);
        for(int i = xlim - superior.size() - 2; (i - xlim + superior.size() + 2) < superior.size(); i++ )
            plot[ylim - 1][i] = superior.at(i - xlim + superior.size() + 2);

        for(int i = 0; i < (xlim - 3); i++){
            y[i] = func(limInferior + variacao*i) * 10000;
            if(y[i] > max){
                max = y[i];
            }
            if(y[i] < min){
                min = y[i];
            }
        }
        for(int j = 0; j < (xlim - 3); j++){
            int i = (((ylim - 5))*y[j] + ((min - max)*2 - (ylim - 5)*max))/(min - max);
            plot[i][j + 2] = '.';
        }
        for (int i = 0; i < ylim; i++)
        {
        for(int j = 0; j < xlim; j++){
            std::cout<<plot[i][j];
        }
        }
        std::cout<<std::endl;
}

double Funcao::getIntegral(const double& limInferior, const double& limSuperior, const double& precisao /*= 1000*/){
    if(limInferior > limSuperior){
        throw std::invalid_argument("O limite superior deve ser maior ou igual ao limite inferior!\n");
    }
    double soma = 0;       
    double variacao = (limSuperior - limInferior)/precisao; 
    for(int i = 0; i < precisao; i++){
        double base1 = func(limInferior + variacao*i);
        double base2 = func(limInferior + variacao*(i+1));
        soma += ((base1 + base2)*variacao)/2;
    }
    return soma;                                                                                                                                                                                      
}