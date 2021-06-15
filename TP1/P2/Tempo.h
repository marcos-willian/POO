#include <iostream>

class Tempo
{
    private:
        int dia;
        int hora;
        int min;
        int seg;
    
    public:
        // construtores
        Tempo();
        Tempo(int dia, int hora, int min, int seg);
        // destrutor
        ~Tempo();
        // outros metodos
        Tempo ChecaConsistencia();
        Tempo SomaTempo(Tempo t1, Tempo t2);
        void PrintTempo();
        Tempo IncrementaSegundo();
        Tempo DecrementaSegundo();
};