#include "Universidade.h"

void Universidade::imprimeProfs() const{
    for (std::vector<std::reference_wrapper<const Professor>>::const_iterator prof = professores.begin(); prof != professores.end(); ++prof){
        std::cout<<prof->get()<<std::endl;
    }
}
