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

    public:

        // Construtores
        //Construtor defalte
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
    
        // basic getters
        //Retorna o numero de linhas
        int getRows() const {return this->nRows;};
        //Retorna o numero de colunas
        int getCols() const {return this->nCols;};
        //retorna um elemtro sendo 1,1 o primeiro elemento da matrix
        double get(const int& row, const int& col) const{
                                                            if(((row - 1) < 0) || ((col - 1) < 0) || (row > this->nRows) || (col > this->nCols)){
                                                                std::cout<<"Linha ou coluna iválida"<<std::endl;
                                                                return 0;
                                                            }
                                                            return this->m[row - 1][col - 1];
                                                        };
        
        // other methods
        //Coloca um elemento na matrix
        void putElement(const int& row, const int& col, const double& elem){
                                                                                if(((row - 1) < 0) || ((col - 1) < 0) || (row > this->nRows) || (col > this->nCols)){
                                                                                    std::cout<<"Linha ou coluna iválida"<<std::endl;
                                                                                    return;
                                                                                }
                                                                                this->m[row - 1][col - 1] = elem;
                                                                            }; 
        //retorna uma matriz trasnporta sem alterar o objeto
        Matrix transpose() const;
        //printa todos os elementos da matrix
        void print() const;
        //trasforma a matrix em identidade
        Matrix& unit();
        //trasnforma uma matriz em zeros
        Matrix& zeros();
        //trasnforma uma matriz em 1
        Matrix& ones();        
};

#endif