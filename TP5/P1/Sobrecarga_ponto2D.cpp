#include <iostream> 
using namespace std;
class Ponto2D{
    
    int x,y;
    
    public:
        Ponto2D(int xx = 0, int yy = 0) : x(xx), y(yy) { };
        const Ponto2D& operator-- (){
            x--;
            y--;
            return *this;
        }
        const Ponto2D operator+ (const Ponto2D& P) const{
            return Ponto2D(x + P.x, y + P.y);
        }
        friend ostream& operator<<(ostream& os, const Ponto2D& P);
        ~Ponto2D(){}; 
};
ostream& operator<<(ostream& os, const Ponto2D& P){
    
    os<<P.x<<", "<<P.y<<endl;
    return os;
}

int main() {
    
    Ponto2D a(1,4), b(3,2), c;
    cout<<"a: "<<a<<"b: "<<b<<"c: "<<c;
    c = a + b;               // soma as coordenadas dos pontos a e b
    cout<<"c: "<<c;
    --c;                    // decrementa em uma unidade as coordenadas de c
    cout<<"c: "<<c;
}