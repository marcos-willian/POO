// matrix.cpp
#include "Matrix.h"
#include <iostream>
#include <fstream> 
#include <cstdlib> 


    

// construtor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a elem (double)
Matrix::Matrix(const int& rows, const int& cols, const double& elem){
    this->nRows = rows;
    this->nCols = cols;
    this->m = new double*[nRows];
    for(int i = 0; i < nRows; i++){
        this->m[i] = new double[nCols];
        for(int j = 0; j < nCols; j++){
            this->m[i][j] = elem;
        }
    }
}

// contrutor parametrico 2 - cria uma matriz com os dados fornecidos pelo arquivo texto myFile.
// O arquivo deve estar no seguinte modelo (em csv)
//nRow,nCol
//m[0,0],m[0,1]
//m[1,0],m[1,1]
Matrix::Matrix(std::ifstream &myFile){
    if(myFile.is_open()){
        myFile>> this->nRows;
        myFile.ignore(1, ',');
        myFile>> this->nCols;

        for(int i = 0; i < nRows; i++){
            for (int j = 0; j < nCols; j++)
            {
                myFile>> this->m[i][j];
                myFile.ignore(1, ',');
            }
            myFile.ignore(1, '\n');
        }
        myFile.close();
    }
    else std::cout << "ocorreu um erro ao abrir o arquivo";
    
}

Matrix::Matrix(const Matrix& that){
    this->nRows = that.nRows;
    this->nCols = that.nCols;
    this->m = new double*[nRows];
    for(int i = 0; i < nRows; i++){
        this->m[i] = new double[nCols];
        for(int j = 0; j < nCols; j++){
            this->m[i][j] = that.m[i][j];
        }
    }
}

// destrutor
Matrix::~Matrix() {
    this->nRows = 0;
    this->nCols = 0;
    for(int i = 0; i < nRows; i++){
        delete[] this->m[i];
    }
}

int Matrix::getRows() const {return this->nRows;};

int Matrix::getCols() const {return this->nCols;};
// retorna uma matriz transposta
Matrix Matrix::transpose() const {
    Matrix aux(this->nCols, this->nRows, 0);
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            aux.m[j][i] = this->m[i][j];
        }
    }
    return aux;
}

// imprime o conteudo da matriz
void Matrix::print() const {
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Transforma a matriz em uma matriz identidade
Matrix& Matrix::unit(){
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

// Transforma a matriz em uma matriz nula
Matrix& Matrix::zeros(){
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            this->m[i][j] = 0;
        }
    }
    return *this;
}

// Altera o valor de todos os elementos da matriz para 1
Matrix& Matrix::ones(){
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            this->m[i][j] = 1;
        }
    }
    return *this;
}
//retorna um elemto sendo 1,1 o primeiro elemento da matrix
double Matrix::get(const int& row, const int& col) const{
    if(((row - 1) < 0) || ((col - 1) < 0) || (row > this->nRows) || (col > this->nCols)){
        std::cout<<"Linha ou coluna inválida"<<std::endl;
        return 0;
    }
    return this->m[row - 1][col - 1];
};

//Coloca um elemento na matrix
void Matrix::putElement(const int& row, const int& col, const double& elem){
    if(((row - 1) < 0) || ((col - 1) < 0) || (row > this->nRows) || (col > this->nCols)){
        std::cout<<"Linha ou coluna inválida"<<std::endl;
        return;
    }
    this->m[row - 1][col - 1] = elem;
}; 