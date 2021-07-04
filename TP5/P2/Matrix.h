// matrix.h (header file)
#ifndef MATRIX
#define MATRIX
#include <iostream>
#include <fstream> 

class Matrix {
    private:

        double** m; // m é um array 2D a ser implementado como um pointer de pointers
        int nRows;  // numero de linhas
        int nCols;  //  numero de colunas
        void initCopy(const Matrix& that);
    public:

        // Construtores
        //Construtor default
        Matrix() : nRows(0), nCols(0), m(NULL) {}; 
        // construtor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
        // com todos os elementos iguais a elem (double)                          
        Matrix(const int& rows, const int& cols, const double& elem = 0.0);
        // contrutor parametrico 2 - cria uma matriz com os dados fornecidos pelo arquivo texto myFile.
        //O arquivo deve estar no seguinte modelo (em csv)
        //nRow,nCol
        //m[0,0],m[0,1]
        //m[1,0],m[1,1]
        Matrix(std::ifstream& myFile);
        //Construtor cópia
        Matrix(const Matrix& that);
        // destrutor
        ~Matrix();

        // Retorna o numero de linhas
        int getRows() const;
        // Retorna o numero de colunas
        int getCols() const;
        //retorna um elemtro sendo 1,1 o primeiro elemento da matrix
        //Com sobrecarga de operador --- double get(const int& row, const int& col) const;
        
        // other methods
        //Coloca um elemento na matrix
        //Com sobrecarga de operador --- void putElement(const int& row, const int& col, const double& elem);
        //retorna uma matriz trasnporta sem alterar o objeto
        //Com sobrecarga de operador --- Matrix transpose() const;
        //printa todos os elementos da matrix
        //Com sobrecarga de operador --- void print() const;
        //trasforma a matrix em identidade
        Matrix& unit();
        //trasnforma uma matriz em zeros
        Matrix& zeros();
        //trasnforma uma matriz em 1
        Matrix& ones(); 

        //Sobrecarga de operadores
        double& operator() (const int& row, const int& col);
        Matrix& operator= (const Matrix& that);
        friend std::ostream& operator<<(std::ostream& os, const Matrix& M);
        //friend std::ostream& operator>>(std::ostream& is, const Matrix& M);
        Matrix operator+ (const Matrix& M) const;
        Matrix& operator+= (const Matrix& M);
        Matrix operator- (const Matrix& M) const;
        Matrix& operator-= (const Matrix& M);
        Matrix& operator~ ();
        Matrix operator* (const Matrix& M) const;
        Matrix& operator*= (const Matrix& M);
        Matrix operator* (const double& num) const;
        Matrix& operator*= (const double& num);
        bool operator== (const Matrix& M) const;
        bool operator!= (const Matrix& M) const;
        
};

inline int Matrix::getRows() const {return this->nRows;};

inline int Matrix::getCols() const {return this->nCols;};

/*
//retorna um elemto sendo 1,1 o primeiro elemento da matrix
inline double Matrix::get(const int& row, const int& col) const{
    if(((row - 1) < 0) || ((col - 1) < 0) || (row > this->nRows) || (col > this->nCols)){
        std::cout<<"Linha ou coluna inválida"<<std::endl;
        return 0;
    }
    return this->m[row - 1][col - 1];
};*/

/*
//Coloca um elemento na matrix
inline void Matrix::putElement(const int& row, const int& col, const double& elem){
    if(((row - 1) < 0) || ((col - 1) < 0) || (row > this->nRows) || (col > this->nCols)){
        std::cout<<"Linha ou coluna inválida"<<std::endl;
        return;
    }
    this->m[row - 1][col - 1] = elem;
}; */

inline double& Matrix::operator()(const int& row, const int& col){
    if(((row - 1) < 0) || ((col - 1) < 0) || (row > this->nRows) || (col > this->nCols)){
        std::cerr<<"Linha ou coluna inválida - segmentation fault"<<std::endl;
        exit(1);
    }
    return (this->m[row - 1][col - 1]);
}





#endif