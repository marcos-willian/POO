#include "Funcoes.h"
#include "Funcao.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    
    cout << fixed << setprecision(2);
    vector<Funcao *>f = {   new Quadratica(1, 2, 4),
                            new Sinc(),
                            new Linear(1, 4),
                            new Cubica(2, 1, 3, 2),
                            new Log(1,10) };
    cout << "*** Calculo de integrais usando a regra do trapezio: ***"<<endl<<endl;
    cout << "*** Funcoes ***" << endl;          
    Quadratica::formato();
    cout<<("(1) " + f[0]->funcDef() + "\n")<<endl;
    Sinc::formato();
    cout<<("(2) " + f[1]->funcDef() + "\n")<<endl;
    Linear::formato();
    cout<<("(3) " + f[2]->funcDef() + "\n")<<endl;
    Cubica::formato();
    cout<<("(4) " + f[3]->funcDef() + "\n")<<endl;
    Log::formato();
    cout<<("(5) " + f[4]->funcDef() + "\n")<<endl;

    for (int i = 0; i < f.size(); i++){
        try{
            double resultado = f[i]->getIntegral(1, 4);
            cout << "Integral da Funcao (" << i+1 << ") de 1 até 4: " <<resultado<<endl;
            cout << "Mostrar gráfico? (y/n)";
            char res;
            double limSuperior, limInferior;
            cin>> res;
            if(res == 'y'){
                cout<< "Limite inferior: ";
                cin>>limInferior;
                cout << "Limite superior: ";
                cin>>limSuperior;
                f[i]->plot(limInferior, limSuperior, 100, 60);
            }
            cout<<endl;
        }catch(invalid_argument& err){
            cerr<<err.what()<<endl;
        }
    }

    f.clear();
    return 0;
    
    
}