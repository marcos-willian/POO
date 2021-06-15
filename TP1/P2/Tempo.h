

class Tempo
{
    private:
        int dia;
        int hora;
        int min;
        int seg;
    
    public:
        // construtores
        Tempo(int dia = 0, int hora = 0, int min = 0, int seg = 0);
        // destrutor
        ~Tempo();
        // outros metodos
        void ChecaConsistencia();
        Tempo SomaTempo(Tempo t1, Tempo t2);
        void PrintTempo();
        Tempo IncrementaSegundo();
        Tempo DecrementaSegundo();
        void getTempo(int *tempo);
};