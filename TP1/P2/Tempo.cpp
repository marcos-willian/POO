#include "Tempo.h"
#include <iostream>
using namespace std;

// construtor parametrizado
Tempo::Tempo(int dia, int hora, int min, int seg){
    this->dia = dia;
    this->hora = hora;
    this->min = min;
    this->seg = seg;
    this->ChecaConsistencia();
}
// destrutor 
Tempo::~Tempo()
{
}
// checa a consistencia dos atributos
void Tempo::ChecaConsistencia()
{
    int aux;
    if(this->seg > 59)
    {
        aux = int(this->seg/60);
        this->min += aux;
        this->seg = this->seg%60;
    }
    else if(this->seg < 0)
    {
        this->seg = 60+this->seg;
        this->min--;
    }
    if(this->min > 59)
    {
        aux = int(this->min/60);
        this->hora += aux;
        this->min = this->min%60;
    }
    else if(this->min < 0)
    {
        this->min = 60+this->min;
        this->hora--;
    }
    if(this->hora > 23)
    {
        aux = int(this->hora/24);
        this->dia += aux;
        this->hora = this->hora%24;
    }
    else if(this->hora < 0)
    {
        this->hora = 24+this->hora;
        this->dia--;
    }
    if(dia < 0)
    {
        this->dia = 0;
        this->hora = 0;
        this->min = 0;
        this->seg = 0;
    }
}
// metodo de soma de dois objetos da classe Tempo
Tempo Tempo:: SomaTempo(Tempo t1, Tempo t2)
{
    this->dia = t1.dia + t2.dia;
    this->hora = t1.hora + t2.hora;
    this->min = t1.min + t2.min;
    this->seg = t1.seg + t2.seg;
    this->ChecaConsistencia();
    return *this;
}
// metodo de impressao de tempo
void Tempo::print() const
{
    std::cout<<this->dia<<" Dias, ";
    std::cout<<this->hora<<" Horas, ";
    std::cout<<this->min<<" Minutos, ";
    std::cout<<this->seg<<" Segundos. ";
    std::cout<<std::endl;
}
// metodo de incremento de segundo
Tempo Tempo::IncrementaSegundo()
{
    this->seg++;
    this->ChecaConsistencia();
    return *this;
}
// metodo de decremento de segundo
Tempo Tempo::DecrementaSegundo()
{
    this->seg--;
    this->ChecaConsistencia();
    return *this;
}
void Tempo::getTempo(){
    cout<< " Dia: ";
    cin>> this->dia;
    cout<< "Hora: ";
    cin>> this->hora;
    cout<< "Minuto: ";
    cin>> this->min;
    cout<< "Segundo: ";
    cin>> this->seg;
    this->ChecaConsistencia();
}