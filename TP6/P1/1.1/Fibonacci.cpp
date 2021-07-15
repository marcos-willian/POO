#include <iostream>
#include <typeinfo>
using namespace std;

// emula operador de resto para tipo genérico
template<class T> float restOf(T n){
  float rest = float(n - int(n));
  return rest;
}

/**==============================================
 **              fibonacci
 *?  Retorna o enésimo termo da série de fibonacci no tipo dado pelo template
 *@param n generico //! Deve ser numerico e pertencente aos naturais
 *@return tipo pedido pela função (precisa ser um tipo numérico ou uma classe numérica)
 *=============================================**/
template <class T> T fibonacci(T n) {
  T x;
  if(n < 1){
    throw std::invalid_argument("Serie begins in 1.");
  }
  else if(restOf(n) > 0){
    throw std::domain_error("The param must be a natural number");
  }
  else if(typeid(T).name == typeid(char).name){
    throw std::bad_typeid("The type of param must be a number type, or a numerical class.")
  }

  if (n == 1) {
    return(1);
  }
  else if (n == 2) {
    return(1);
  }
  else{
    x = (int)(fibonacci<T>(n-1) + fibonacci<T>(n-2));
  }
  return(x);
};

template <class T> void print(T n){
  cout<<"Fibonacci for n  = "<<n<<"\n"<<fibonacci<T>(n)<<"  Type: "<<typeid(T).name()<<endl;
};

int main(){
  /// Testes da funcao

  try{
    // teste p/ executar excecao por argumento nao numerico
    print<char>(15);
  }
  catch(bad_typeid& err){
    cerr<<err.what()<<endl;
  }
  
  try{
    // teste p/ tipo inteiro
    print<int>(10);
    // teste p/ tipo decimal
    print<float>(3.0);
    // teste p/ decimal c/ dupla precisao
    print<double>(5.0);
    // teste p/ inteiro longo
    print<long int>(2);
    // teste p/ inteiro curto
    print<short int>(8);
    // teste p/ executar excecao de argumento invalido
    print<int>(0);
  }
  catch(invalid_argument& err){
    cerr<<err.what()<<endl;
  }

  try{
    // teste p/ executar excecao de argumento nao pertencente aos naturais
    print<float>(3.1);
  }
  catch(domain_error& err){
    cerr<<err.what()<<endl;
  }
}