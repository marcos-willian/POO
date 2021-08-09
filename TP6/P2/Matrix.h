/**==============================================
 * ?                    ABOUT
 * @author      : Marcos Willian & Denis Gaillac
 * @repo        : https://github.com/marcos-willian/POO.git
 * @description : Implementa través de uma classe uma matriz 
 *      com todas as operações necessárias.
 *=============================================**/
#ifndef MATRIX
#define MATRIX
#include <iostream>
#include <fstream> 

template <class T>
class Matrix;

template <class T> 
std::ostream& operator<<(std::ostream&, const Matrix<T>& M);

template <class T>
std::istream& operator>>(std::istream& is, Matrix<T>& M);

template <class T> class Matrix {
    private:
        T** m; //* INFO  m é um array 2D a ser implementado como um ponteiro de ponteiros
        int nRows;  //* INFO numero de linhas
        int nCols;  //* INFO  numero de colunas

        /**======================
         *@description: Aloca espaço e copia os dados de uma matriz dada 
         *@return type: void
         *========================**/
        void initCopy(const Matrix<T>& that);
    public:

        /**======================
         *@description: Contrutor default, zera todos os parametros e não aloca m  
         *@return type: Matrix
         *========================**/
        Matrix() : nRows(0), nCols(0), m(NULL) {}; 

        /**======================
         *@description: Construtor parametrico 1 - cria uma matriz 
                com nRows  = rows, nCols = cols e com todos os elementos iguais a elem (double)
         *@return type: Matrix
         *========================**/                      
        Matrix(const int& rows, const int& cols, const T& elem = 0.0);
         
        /**======================
         *@description: contrutor parametrico 2 - cria uma matriz 
                com os dados fornecidos pelo arquivo texto myFile.
                O arquivo deve estar no seguinte modelo (em csv):
                        nRows,nCols
                        m[0,0],m[0,1]
                        m[1,0],m[1,1]
         *@return type: Matrix
         //* Caso de erro lança um objeto runtime_erro 
         *========================**/ 
        Matrix(std::ifstream& myFile);
        
        /**======================
         *@description: Construtor cópia.
         *@return type: Matrix
         *========================**/ 
        Matrix(const Matrix<T>& that);
        
        /**======================
         *@description: Destrutor, desaloca o espaço.
         *@return type: void
         *========================**/ 
        ~Matrix();

        /**======================
         *@description: Getter. Retorna o numero de linhas.
         *@return type: int
         *========================**/ 
        int getRows() const;
        
        /**======================
         *@description: Getter. Retorna o nnumero de colunas
         *@return type: int
         *========================**/ 
        int getCols() const;

        /**======================
         *@description: Trasnforma a matriz em identidade
         *! Altera o objeto
         *@return type: Matrix&
         //* Em caso de erro lança um objeto invalid_argument 
         *========================**/ 
        Matrix<T>& unit();

        /**======================
         *@description: Transforma a matriz em 0s
         *! Altera o objeto
         *@return type: Matrix&
         *========================**/ 
        Matrix<T>& zeros();
        
        /**======================
         *@description: Transforma a matriz em 1s
         *! Altera o objeto
         *@return type: Matrix&
         *========================**/ 
        Matrix<T>& ones(); 

        /**======================
         *@description: Getter. Retorna um elemento da matriz indexando a partir de (1,1)
         *@return type: double&
         //* Caso erro lança um objeto invalid_argument 
         *========================**/ 
        T& operator() (const int& row, const int& col) const;

        /**======================
         *@description: Copia uma matriz dado para o objeto
         *! Altera o objeto
         *@return type: Matrix&
         *========================**/ 
        Matrix<T>& operator= (const Matrix<T>& that);

        /**======================
         *@description: Imprime a matriz, o numero de linhas e numero de colunas
         *@return type: Matrix&
         *========================**/ 
        friend std::ostream& operator<< <>(std::ostream& os, const Matrix<T>& M);

        /**======================
         *@description: Preenche uma matriz conforme a entrada. A entrada deve estar padronizada no padrão csv
                no qual a primeira linha indica o numero de linhas e o numero de colunas como o exemplo a seguir:
                        nRows,nCols
                        m[0,0],m[0,1]
                        m[1,0],m[1,1]
         *! Altera o objeto
         *@return type: istream&
         *========================**/ 
        friend std::istream& operator>> <>(std::istream& is, Matrix<T>& M);

         /**======================
         *@description: Realiza a soma de duas matrizes
         *@return type: Matrix
         //* Caso erro lança um objeto invalid_argument 
         *========================**/ 
        Matrix<T> operator+ (const Matrix<T>& M) const;

         /**======================
         *@description: Realiza a soma de duas matrizes e guarda no objeto a esquerda
         *! Altera o objeto
         *@return type: Matrix&
         //* Caso erro lança um objeto invalid_argument 
         *========================**/ 
        Matrix<T>& operator+= (const Matrix<T>& M);

        /**======================
         *@description: Realiza a subtração de duas matrizes
         *@return type: Matrix
         //* Caso erro lança um objeto invalid_argument 
         *========================**/ 
        Matrix<T> operator- (const Matrix<T>& M) const;

        /**======================
         *@description: Realiza a subtração de duas matrizes e guarda no objeto a esquerda
         *! Altera o objeto
         *@return type: Matrix&
         //* Caso erro lança um objeto invalid_argument 
         *========================**/ 
        Matrix<T>& operator-= (const Matrix<T>& M);

        /**======================
         *@description: Realiza a trasposição da matriz
         *! Altera o objeto
         *@return type: Matrix&
         *========================**/ 
        Matrix<T>& operator~ ();

        /**======================
         *@description: Realiza a multiplicação de duas matrizes
         *@return type: Matrix
         //* Caso erro lança um objeto invalid_argument 
         *========================**/ 
        Matrix<T> operator* (const Matrix<T>& M) const;

        /**======================
         *@description: Realiza a multiplicação de duas matrizes e guarda no objeto a esquerda
         *! Altera o objeto
         *@return type: Matrix&
         *========================**/ 
        Matrix<T>& operator*= (const Matrix<T>& M);

        /**======================
         *@description: Realiza a multiplicação de uma matriz por um escalar
         *@return type: Matrix
         *========================**/ 
        Matrix<T> operator* (const T& num) const;

        /**======================
         *@description: Realiza a multiplicação de uma matriz por um escalar e guarda no objeto a esquerda
         *! Altera o objeto
         *@return type: Matrix&
         *========================**/ 
        Matrix<T>& operator*= (const T& num);

        /**======================
         *@description: Compara duas matrizes
         *@return type: bool
         *========================**/ 
        bool operator== (const Matrix<T>& M) const;
        bool operator!= (const Matrix<T>& M) const;

        /**======================
         *    Funções substituidas por overload
         *========================**
            double get(const int& row, const int& col) const;
            void putElement(const int& row, const int& col, const double& elem);
            Matrix transpose() const;
            void print() const;
        /*==== END OF SECTION ====*/
        
        
};

/**============================================
 *            Funções Da Classe
 *=============================================**/
template <class T>
inline int Matrix<T>::getRows() const {return this->nRows;};

template <class T>
inline int Matrix<T>::getCols() const {return this->nCols;};

template <class T> 
inline T& Matrix<T>::operator()(const int& row, const int& col) const{
    if(((row - 1) < 0) || ((col - 1) < 0) || (row > this->nRows) || (col > this->nCols)){
        throw std::invalid_argument("Linha ou coluna inválida - segmentation fault");
    }
    return (this->m[row - 1][col - 1]);
}

template <class T>
void Matrix<T>::initCopy(const Matrix<T>& that){
    this->nRows = that.nRows;
    this->nCols = that.nCols;
    this->m = new T*[nRows];
    for(int i = 0; i < nRows; i++){
        this->m[i] = new T[nCols];
        for(int j = 0; j < nCols; j++){
            this->m[i][j] = that.m[i][j];
        }
    }
}

template <class T>
Matrix<T>::Matrix(const int& rows, const int& cols, const T& elem){
    this->nRows = rows;
    this->nCols = cols;
    this->m = new T*[nRows];
    for(int i = 0; i < nRows; i++){
        this->m[i] = new T[nCols];
        for(int j = 0; j < nCols; j++){
            this->m[i][j] = elem;
        }
    }
}

template <class T>
Matrix<T>::Matrix(std::ifstream &myFile){
    if(myFile.is_open()){
        myFile>> this->nRows;
        myFile.ignore(1, ',');
        myFile>> this->nCols;
        this->m = new T*[nRows];
        for(int i = 0; i < nRows; i++){
            this->m[i] = new T[nCols];
            for (int j = 0; j < nCols; j++){
                myFile>> this->m[i][j];
                myFile.ignore(1);
            }
        }
        myFile.close();
    }
    else{
        throw std::runtime_error("Ocorreu um erro ao abrir o arquivo");
    } 
}

template <class T>
inline Matrix<T>::Matrix(const Matrix<T>& that){
    this->initCopy(that);
}

template <class T>
Matrix<T>::~Matrix() {
    this->nRows = 0;
    this->nCols = 0;
    for(int i = 0; i < nRows; i++){
        delete[] this->m[i];
    }
}


template <class T>
Matrix<T>& Matrix<T>::unit(){
    if(nRows != nCols){
        throw std::invalid_argument("Precisa ser uma matriz quadrada!");
    }
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            if(i == j){
                this->m[i][j] = 1;
            }else{
                this->m[i][j] = 0;
            }
        }
    }
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::zeros(){
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            this->m[i][j] = 0;
        }
    }
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::ones(){
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            this->m[i][j] = 1;
        }
    }
    return *this;
}

template <class T>
inline Matrix<T>& Matrix<T>::operator=(const Matrix<T>& that){
    if(this == &that){
        return *this;
    }else if(this->m == NULL){
        this->initCopy(that);
        return *this;
    }else{
        for(int i = 0; i < this->nRows; i++){
            delete[] this->m[i];
        }
        this->initCopy(that);
        return *this;
    }
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& M){
    for(int i = 0; i < M.nRows; i++){
        for(int j = 0; j < M.nCols; j++){
            os << M.m[i][j] << "\t";
        }
        os << std::endl;
    }
   /* os << "Numero de linhas: " << M.getRows() <<std::endl;
    os << "Numero de colunas: " << M.getCols() <<std::endl;*/
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Matrix<T>& M){
    for(int i = 0; i < M.nRows; i++){
        delete[] M.m[i];
    }
    is>> M.nRows;
    is.ignore(1, ',');
    is>> M.nCols;
    is.ignore(1, '\n');
    M.m = new T*[M.nRows];
    for(int i = 0; i < M.nRows; i++){
        M.m[i] = new T[M.nCols];
        for (int j = 0; j < M.nCols; j++){
            is>> M.m[i][j];
            is.ignore(1);
        }
    }
    return is;
}

template <class T>
Matrix<T> Matrix<T>::operator+ (const Matrix<T>& M) const{
    if((this->nRows == M.nRows) && (this->nCols == M.nCols)){
        Matrix<T> temp;
        temp.nRows = this->nRows;
        temp.nCols = this->nCols;
        temp.m = new T*[temp.nRows];
        for(int i = 0; i < temp.nRows; i++){
            temp.m[i] = new T[nCols];
            for(int j = 0; j < temp.nCols; j++){
                temp.m[i][j] = this->m[i][j] + M.m[i][j];
            }
        }
        return temp;
    }else{
        throw std::invalid_argument("Dimensões diferentes");
    }
}

template <class T>
Matrix<T>& Matrix<T>::operator+= (const Matrix<T>& M){
    if((this->nRows == M.nRows) && (this->nCols == M.nCols)){
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                this->m[i][j] = this->m[i][j] + M.m[i][j];
            }
        }
        return *this;
    }else{
        throw std::invalid_argument("Dimensões diferentes");
    }
}

template <class T>
Matrix<T> Matrix<T>::operator- (const Matrix<T>& M) const{
    if((this->nRows == M.nRows) && (this->nCols == M.nCols)){
        Matrix<T> temp;
        temp.nRows = this->nRows;
        temp.nCols = this->nCols;
        temp.m = new T*[temp.nRows];
        for(int i = 0; i < temp.nRows; i++){
            temp.m[i] = new T[nCols];
            for(int j = 0; j < temp.nCols; j++){
                temp.m[i][j] = this->m[i][j] - M.m[i][j];
            }
        }
        return temp;
    }else{
        throw std::invalid_argument("Dimensões diferentes");
    }
}

template <class T>
Matrix<T>& Matrix<T>::operator-= (const Matrix<T>& M){
    if((this->nRows == M.nRows) && (this->nCols == M.nCols)){
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                this->m[i][j] = this->m[i][j] - M.m[i][j];
            }
        }
        return *this;
    }else{
        throw std::invalid_argument("Dimensões diferentes");
    }
}

template <class T>
Matrix<T>& Matrix<T>::operator~ (){
    Matrix<T> aux(this->nCols, this->nRows, 0);
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            aux.m[j][i] = this->m[i][j];
        }
    }
    return *this = aux;
}

template <class T>
Matrix<T> Matrix<T>::operator* (const Matrix<T>& M) const{
    if((this->nCols == M.nRows)){
        Matrix<T> temp;
        temp.nRows = this->nRows;
        temp.nCols = M.nCols;
        temp.m = new T*[temp.nRows] {};
        for(int i = 0; i < temp.nRows; i++){
            temp.m[i] = new T[nCols] {};
            for(int j = 0; j < temp.nCols; j++){
                for(int l = 0; l < this->nCols; l++)
                        temp.m[i][j] += this->m[i][l] * M.m[l][j];
            }
        }
        return temp;
    }else{
        throw std::invalid_argument("Dimensões diferentes");
        return *this;
    }
}

template <class T>
Matrix<T>& Matrix<T>::operator*= (const Matrix<T>& M){
    return *this = *this * M;
}

template <class T>
Matrix<T> Matrix<T>::operator* (const T& num) const{
    Matrix<T> temp;
    temp.nRows = this->nRows;
    temp.nCols = this->nCols;
    temp.m = new T*[temp.nRows];
    for(int i = 0; i < temp.nRows; i++){
        temp.m[i] = new T[nCols];
        for(int j = 0; j < temp.nCols; j++){
            temp.m[i][j] = this->m[i][j] * num;
        }
    }
    return temp;
 }

template <class T>
Matrix<T>& Matrix<T>::operator*= (const T& num){
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            this->m[i][j] = this->m[i][j] * num;
        }
    }
    return *this;
}

template <class T>
bool Matrix<T>::operator== (const Matrix<T>& M) const{
    if((this->nRows != M.nRows) || (this->nCols != M.nCols)){
        return false;
    }
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            if(this->m[i][j] != M.m[i][j])
                return false;
        }
    } 
    return true;
}

template <class T>
bool Matrix<T>::operator!= (const Matrix<T>& M) const{
    return !(*this == M);
}

/*===== Funções substituidas por overload ======*
void Matrix::print() const {
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            std::cout << m[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::transpose() const {
    Matrix aux(this->nCols, this->nRows, 0);
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            aux.m[j][i] = this->m[i][j];
        }
    }
    return aux;
}

inline double Matrix::get(const int& row, const int& col) const{
    if(((row - 1) < 0) || ((col - 1) < 0) || (row > this->nRows) || (col > this->nCols)){
        std::cout<<"Linha ou coluna inválida"<<std::endl;
        return 0;
    }
    return this->m[row - 1][col - 1];
}

inline void Matrix::putElement(const int& row, const int& col, const double& elem){
    if(((row - 1) < 0) || ((col - 1) < 0) || (row > this->nRows) || (col > this->nCols)){
        std::cout<<"Linha ou coluna inválida"<<std::endl;
        return;
    }
    this->m[row - 1][col - 1] = elem;
}

/*=============== END OF SECTION ==============*/


#endif