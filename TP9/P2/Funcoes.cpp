#include "Funcoes.h"


/**============================================
 **               Quadratica
 *=============================================**/
double Quadratica::func(const double& input){ 
    return termos[0]*pow(input,2) + termos[1]*input + termos[2];
}

std::string Quadratica::funcDef(){
    return std::to_string(termos[0]).substr(0, std::to_string(termos[0]).find(".") +  3) + 
           "*x^2 + " + 
           std::to_string(termos[1]).substr(0, std::to_string(termos[1]).find(".") +  3) + 
           "*x + " + 
           std::to_string(termos[2]).substr(0, std::to_string(termos[2]).find(".") +  3);
}

/**============================================
 **               Sinc
 *=============================================**/
double Sinc::func(const double& input){ 
    return (termos[0]*sin(input))/input;
}

std::string Sinc::funcDef(){
    return std::to_string(termos[0]).substr(0, std::to_string(termos[0]).find(".") +  3) + 
           "*(sen(x)/x)";
}

/**============================================
 **               Linear
 *=============================================**/
double Linear::func(const double& input){ 
    return termos[0]*input + termos[1];
}

std::string Linear::funcDef(){
    return std::to_string(termos[0]).substr(0, std::to_string(termos[0]).find(".") +  3) + 
           "*x + " + 
           std::to_string(termos[1]).substr(0, std::to_string(termos[1]).find(".") +  3);
}

/**============================================
 **               Cubica
 *=============================================**/
double Cubica::func(const double& input){ 
    return termos[0]*(input*input*input) + termos[1]*pow(input,2) + termos[2]*input + termos[3];
}

std::string Cubica::funcDef(){
    return std::to_string(termos[0]).substr(0, std::to_string(termos[0]).find(".") +  3) + 
           "*x^3 + " +
           std::to_string(termos[1]).substr(0, std::to_string(termos[1]).find(".") +  3) + 
           "*x^2 + " +
           std::to_string(termos[2]).substr(0, std::to_string(termos[2]).find(".") +  3) + 
           "*x + " +
           std::to_string(termos[3]).substr(0, std::to_string(termos[3]).find(".") +  3);
}


/**============================================
 **               Log
 *=============================================**/
double Log::func(const double& input){ 
    if(input < 0){ 
        throw std::invalid_argument("O valor de entrada deve ser maior que 0!");
    }
    return termos[0]*log(input)/log(termos[1]);
}

std::string Log::funcDef(){
    return std::to_string(termos[0]).substr(0, std::to_string(termos[0]).find(".") +  3) + 
           "*log(x) --base:  " +
           std::to_string(termos[1]).substr(0, std::to_string(termos[1]).find(".") +  3);
}

