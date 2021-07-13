#include <iostream>
#include <typeinfo>
using namespace std;



/**==============================================
 **              fibonacci
 *?  Retorna o enésimo termo da série de fibonacci no tipo dado pelo template
 *@param n int //! Deve ser maior que zero  
 *@return tipo pedido pela função
 *=============================================**/
template <class T> T fibonacci(int n) {
  int x;
  if(n < 1){
      throw std::invalid_argument("Serie begins in 1.");
  }
  if (n == 1) {
    return(1);
  }
  
  if (n == 2) {
    return(1);
  }
  
  x = fibonacci<T>(n-1) + fibonacci<T>(n-2);
  return(x);
};

template <class T> void print(int n){
  cout<<"Fibonacci for n  = "<<n<<"\n"<<fibonacci<T>(n)<<"  Type: "<<typeid(T).name()<<endl;
};

int main(){
  /// Testes function
  try{
    print<int>(10);

    print<char>(15);

    print<float>(3);

    print<double>(5);

    print<long int>(2);

    print<short int>(8);
  }catch(invalid_argument& err){
    cerr<<err.what()<<endl;
  }
  
}