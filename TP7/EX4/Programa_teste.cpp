#include <iostream>
using namespace std;

/**--------------------------------------------
 **               Respostas
 *  1 = Sim. Como a classe 'Derived' é uma classe filha de 'Base', ela possui permissao de acesso aos atributos protegidos.
 * 
 *  2 = Alterando a herança para private todos os elementos da classe base serão privados na classe derivada porem ainda é possível
 *  acessar a função read.
 * 
 *  3 = A funcao read, por ser um atributo encapsulado como 'protected', será publica apenas para a classe derivada. Para fora dela
 *  (no caso seus objetos) os atributos serão privados, sendo impossível chamar read() a partir de um objeto, ou seja, fora do código
 *  da propria classe.
 * 
 *  4 = Como Derived herda a classe Base como 'protected', ela mantera seus atributos 'public' e 'protect' publicos em todas as classes
 *  que herdarem Derived. Assim, em Derived2 é possível chamar read() e value().
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
            void accessRead(){
                cout << "Testando acesso a funcao 'read' em Derived: "<< endl;
                cout<<read()<< endl;
            }
};

class Derived2 : public Derived {
        
        int l;
        public:
            Derived2(int jj = 0) : l(jj) {}
            void membro(){
                cout<<"Testando acesso ao metodo 'read' em Derived2: " << endl;
                cout<<read()<<endl;
                cout<<"Testando acesso ao metodo 'value' em Derived2, passando 10 como parametro: " << endl;
                cout<<value(10)<<endl;
            }
};

int main() {
    cout<<"Testando heranca de 'Derived' \n"<< endl;
    Derived derived(1);
    cout<<"Testando acesso a funcao read pela classe: \n";
    derived.accessRead();

    cout<<"Testando heranca de 'Derived2' \n"<< endl;
    Derived2 d(3);
    cout<<"Testando acesso a funcoes 'read' e 'value' pela classe: \n";
    d.membro();
}