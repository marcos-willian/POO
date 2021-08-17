#include "ProfessorCategorias.h"

double ProfHorista::getSalario() const{
    return valorHora*numHorasTrabalhadas;
}

double ProfIntegral::getSalario() const{
    return salarioMensal;
}

