// matrix.cpp
#include "matrix.h"
#include <iostream>
using namespace std;

// construtor default - cria uma matriz vazia com nRows = nCols = 0  
Matrix::Matrix(){
    this->nRows = 0;
    this->nCols = 0;
    this->m = NULL;
}
    

// construtor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a elem (double)
Matrix::Matrix(int rows, int cols, double elem){
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


// destrutor
Matrix::~Matrix() {
    this->nRows = 0;
    this->nCols = 0;
    for(int i = 0; i < nRows; i++){
        delete[] this->m[i];
    }
}


// obtêm o numero de linhas
int Matrix::getRows() const {
    return this->nRows;
}

// obtém o numero de colunas
int Matrix::getCols() const {
    return this->nCols;
}

// Colocar um elemento na matriz
void Matrix::putElement(int row, int col, double elem){
    this->m[row][col] = elem;
}

// retorna uma matriz transposta
Matrix Matrix::transpose() {
    Matrix aux(this->nCols, this->nRows, 0);
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            aux.putElement(j,i, this->m[i][j]);
        }
    }
    return aux;
}

// imprime o conteudo da matriz
void Matrix::print() const {
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

