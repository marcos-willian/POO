#include "Tempo.h"
#include <iostream>
using namespace std;

// construtor default
Tempo::Tempo()
{
    this->dia = 0;
    this->hora = 0;
    this->min = 0;
    this->seg = 0;
}
// construtor parametrizado
Tempo::Tempo(int dia = 0, int hora = 0, int min = 0, int seg = 0){
    this->dia = dia;
    this->hora = hora;
    this->min = min;
    this->seg = seg;
    this->ChecaConsistencia();
}
// destrutor 
Tempo::~Tempo()
{
    delete this;
}
// checa a consistencia dos atributos
Tempo Tempo:: ChecaConsistencia()
{
    int aux;
    if(this->seg > 59)
    {
        aux = int(this->seg/60);
        this->min += aux;
        this->seg -= aux;
    }
    else if(this->seg < 0)
    {
        this->seg = 60-this->seg;
        this->min--;
    }
    if(this->min > 59)
    {
        aux = int(this->min/60);
        this->hora += aux;
        this->min -= aux;
    }
    else if(this->seg < 0)
    {
        this->min = 60-this->min;
        this->hora--;
    }
    if(this->hora > 23)
    {
        aux = int(this->hora/60);
        this->dia += aux;
        this->hora -= aux;
    }
    else if(this->hora < 0)
    {
        this->hora = 60-this->hora;
        this->dia = this->dia-- < 0 ? 0 : this->dia--;
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
}
// metodo de impressao de tempo
void Tempo::PrintTempo()
{
    std::cout<<"Dias: "<< this->dia;
    std::cout<<"Horas: "<< this->hora;
    std::cout<<"Minutos: "<< this->min;
    std::cout<<"Segundos: "<< this->seg;
}
// metodo de incremento de segundo
Tempo Tempo::IncrementaSegundo()
{
    this->seg++;
    this->ChecaConsistencia();
}
// metodo de decremento de segundo
Tempo Tempo::DecrementaSegundo()
{
    this->seg--;
    this->ChecaConsistencia();
}