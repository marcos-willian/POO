#include <iostream>
using namespace std;

/**--------------------------------------------
 **               Respostas
 *  1 = Sem problemas, porem irá sobreescrever a função read existente na classe base.
 *  2 = Alterando a herança para private todos os elementos da classe base serão privados na classe derivada porem ainda é possível sobreescrever a função read.
 *  3 = A função read será publica apenas para a classe derivada, para fora dela no caso seus objetos eles serão privados sendo impossível chamar read() a partir de um objeto.
 *  4 = Como a herança de Derived é protect a classe Base materá seus atributos publicos e protect publicos em todas as classes que derivarem de Derived. Assim
 *  em Derived2 é possível chamar read() e value()
 *---------------------------------------------**/


class Base{
    
    int i;
    
    protected:
        int read() const { return i; }
        void set(int ii) { i = ii; }
    
    public:
        Base(int ii = 0) : i(ii) {}
        int value(int m) const { return m*i; }
};


class Derived : protected Base {
        
        int j;
        public:
            Derived(int jj = 0) : j(jj) {}
            void change(int x) { set(x); }
};

class Derived2 : public Derived {
        
        int l;
        public:
            Derived2(int jj = 0) : l(jj) {}
            void membro(){ 
                cout<<read()<<endl;
                cout<<value(10)<<endl;
            }
};

int main() {
    Derived2 d(3);
    cout<<"Testando: Derived2 d(3);\nTestanto: d.membro()\n";
    d.membro();
}