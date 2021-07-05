// matrix.cpp
#include "Matrix.h"
#include <iostream>
#include <fstream> 
#include <cstdlib> 

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
                myFile.ignore(1);
            }
        }
        myFile.close();
    }
    else std::cout << "ocorreu um erro ao abrir o arquivo"; 
}

Matrix::Matrix(const Matrix& that){
    this->initCopy(that);
}

Matrix::~Matrix() {
    this->nRows = 0;
    this->nCols = 0;
    for(int i = 0; i < nRows; i++){
        delete[] this->m[i];
    }
}

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

Matrix& Matrix::zeros(){
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            this->m[i][j] = 0;
        }
    }
    return *this;
}

Matrix& Matrix::ones(){
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            this->m[i][j] = 1;
        }
    }
    return *this;
}

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

std::istream& operator>>(std::istream& is, Matrix& M){
    for(int i = 0; i < M.nRows; i++){
        delete[] M.m[i];
    }
    is>> M.nRows;
    is.ignore(1, ',');
    is>> M.nCols;
    is.ignore(1, '\n');
    M.m = new double*[M.nRows];
    for(int i = 0; i < M.nRows; i++){
        M.m[i] = new double[M.nCols];
        for (int j = 0; j < M.nCols; j++){
            is>> M.m[i][j];
            is.ignore(1);
        }
    }
    return is;
}

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

