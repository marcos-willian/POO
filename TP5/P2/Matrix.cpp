// matrix.cpp
#include "Matrix.h"
#include <iostream>
#include <fstream> 
#include <cstdlib> 
//Funções{}
void Matrix::initCopy(const Matrix& that){
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
        this->m = new double*[nRows];
        for(int i = 0; i < nRows; i++){
            this->m[i] = new double[nCols];
            for (int j = 0; j < nCols; j++){
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
    this->initCopy(that);
}

// destrutor
Matrix::~Matrix() {
    this->nRows = 0;
    this->nCols = 0;
    for(int i = 0; i < nRows; i++){
        delete[] this->m[i];
    }
}

/*
// retorna uma matriz transposta
Matrix Matrix::transpose() const {
    Matrix aux(this->nCols, this->nRows, 0);
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            aux.m[j][i] = this->m[i][j];
        }
    }
    return aux;
}*/

/*
// imprime o conteudo da matriz
void Matrix::print() const {
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            std::cout << m[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}*/

// Transforma a matriz em uma matriz identidade
Matrix& Matrix::unit(){
    if(nRows != nCols){
        std::cerr<<"Precisa ser uma matriz quadrada!"<<std::endl;
        return *this;
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

//Sobrecargas

Matrix& Matrix::operator=(const Matrix& that){
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

std::ostream& operator<<(std::ostream& os, const Matrix& M){
    for(int i = 0; i < M.nRows; i++){
        for(int j = 0; j < M.nCols; j++){
            os << M.m[i][j] << "\t";
        }
        os << std::endl;
    }
    os << "Numero de linhas: " << M.getRows() <<std::endl;
    os << "Numero de colunas: " << M.getCols() <<std::endl;
    return os;
}

//Deve ser inserido os dados no mesmo formato que o arquivo
/*std::ostream& operator>>(std::ostream& is, const Matrix& M){
    for(int i = 0; i < M.nRows; i++){
        delete[] M.m[i];
    }
    is>> M.nRows;
    is.ignore(1, ',');
    is>> M.nCols;
    M.m = new double*[nRows];
    for(int i = 0; i < nRows; i++){
        M.m[i] = new double[nCols];
        for (int j = 0; j < nCols; j++){
            is>> M.m[i][j];
            is.ignore(1, ',');
        }
        is.ignore(1, '\n');
    }
}*/

Matrix Matrix::operator+ (const Matrix& M) const{
    if((this->nRows == M.nRows) && (this->nCols == M.nCols)){
        Matrix temp;
        temp.nRows = this->nRows;
        temp.nCols = this->nCols;
        temp.m = new double*[temp.nRows];
        for(int i = 0; i < temp.nRows; i++){
            temp.m[i] = new double[nCols];
            for(int j = 0; j < temp.nCols; j++){
                temp.m[i][j] = this->m[i][j] + M.m[i][j];
            }
        }
        return temp;
    }else{
        std::cerr << "Dimensões diferentes";
        return *this;
    }
}

Matrix& Matrix::operator+= (const Matrix& M){
    if((this->nRows == M.nRows) && (this->nCols == M.nCols)){
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                this->m[i][j] = this->m[i][j] + M.m[i][j];
            }
        }
        return *this;
    }else{
        std::cerr << "Dimensões diferentes";
        return *this;
    }
}

Matrix Matrix::operator- (const Matrix& M) const{
    if((this->nRows == M.nRows) && (this->nCols == M.nCols)){
        Matrix temp;
        temp.nRows = this->nRows;
        temp.nCols = this->nCols;
        temp.m = new double*[temp.nRows];
        for(int i = 0; i < temp.nRows; i++){
            temp.m[i] = new double[nCols];
            for(int j = 0; j < temp.nCols; j++){
                temp.m[i][j] = this->m[i][j] - M.m[i][j];
            }
        }
        return temp;
    }else{
        std::cerr << "Dimensões diferentes";
        return *this;
    }
}

Matrix& Matrix::operator-= (const Matrix& M){
    if((this->nRows == M.nRows) && (this->nCols == M.nCols)){
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                this->m[i][j] = this->m[i][j] - M.m[i][j];
            }
        }
        return *this;
    }else{
        std::cerr << "Dimensões diferentes";
        return *this;
    }
}

Matrix& Matrix::operator~ (){
    Matrix aux(this->nCols, this->nRows, 0);
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            aux.m[j][i] = this->m[i][j];
        }
    }
    return *this = aux;
}

Matrix Matrix::operator* (const Matrix& M) const{
    if((this->nCols == M.nRows)){
        Matrix temp;
        temp.nRows = this->nRows;
        temp.nCols = M.nCols;
        temp.m = new double*[temp.nRows] {};
        for(int i = 0; i < temp.nRows; i++){
            temp.m[i] = new double[nCols] {};
            for(int j = 0; j < temp.nCols; j++){
                for(int l = 0; l < this->nCols; l++)
                        temp.m[i][j] += this->m[i][l] * M.m[l][j];
            }
        }
        return temp;
    }else{
        std::cerr << "Dimensões diferentes";
        return *this;
    }
}

Matrix& Matrix::operator*= (const Matrix& M){
    return *this = *this * M;
}

 Matrix Matrix::operator* (const double& num) const{
    Matrix temp;
    temp.nRows = this->nRows;
    temp.nCols = this->nCols;
    temp.m = new double*[temp.nRows];
    for(int i = 0; i < temp.nRows; i++){
        temp.m[i] = new double[nCols];
        for(int j = 0; j < temp.nCols; j++){
            temp.m[i][j] = this->m[i][j] * num;
        }
    }
    return temp;
 }

Matrix& Matrix::operator*= (const double& num){
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            this->m[i][j] = this->m[i][j] * num;
        }
    }
    return *this;
}

bool Matrix::operator== (const Matrix& M) const{
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
bool Matrix::operator!= (const Matrix& M) const{
    return !(*this == M);
}