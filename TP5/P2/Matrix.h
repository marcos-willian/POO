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

class Matrix {
    private:

        double** m; //* INFO  m é um array 2D a ser implementado como um ponteiro de ponteiros
        int nRows;  //* INFO numero de linhas
        int nCols;  //* INFO  numero de colunas

        /**======================
         *@description: Aloca espaço e copia os dados de uma matrix dada 
         *@return type: void
         *========================**/
        void initCopy(const Matrix& that);
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
        Matrix(const int& rows, const int& cols, const double& elem = 0.0);
         
        /**======================
         *@description: contrutor parametrico 2 - cria uma matriz 
                com os dados fornecidos pelo arquivo texto myFile.
                O arquivo deve estar no seguinte modelo (em csv):
                        nRows,nCols
                        m[0,0],m[0,1]
                        m[1,0],m[1,1]
         *@return type: Matrix
         *========================**/ 
        Matrix(std::ifstream& myFile);
        
        /**======================
         *@description: Construtor cópia.
         *@return type: Matrix
         *========================**/ 
        Matrix(const Matrix& that);
        
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

        //retorna um elemtro sendo 1,1 o primeiro elemento da matrix
        //Com sobrecarga de operador --- 
        
        // other methods
        //Coloca um elemento na matrix
        //Com sobrecarga de operador --- 
        //retorna uma matriz trasnporta sem alterar o objeto
        //Com sobrecarga de operador --- 
        //printa todos os elementos da matrix
        //Com sobrecarga de operador ---

        /**======================
         *@description: Trasnforma a matrix em identidade
         *! Altera o objeto
         *@return type: Matrix&
         *========================**/ 
        Matrix& unit();

        /**======================
         *@description: Trasnforma a matrix em 0s
         *! Altera o objeto
         *@return type: Matrix&
         *========================**/ 
        Matrix& zeros();
        
        /**======================
         *@description: Trasnforma a matrix em 1s
         *! Altera o objeto
         *@return type: Matrix&
         *========================**/ 
        Matrix& ones(); 

        /**======================
         *@description: Getter. Retorna um elemento da matrix indexando apartir de (1,1)
         *@return type: double&
         *========================**/ 
        double& operator() (const int& row, const int& col) const;

        /**======================
         *@description: Copia uma matirx dado para o objeto
         *! Altera o objeto
         *@return type: Matrix&
         *========================**/ 
        Matrix& operator= (const Matrix& that);

        /**======================
         *@description: Imprime a matrix, o numero de linhas e numero de colunas
         *@return type: Matrix&
         *========================**/ 
        friend std::ostream& operator<<(std::ostream& os, const Matrix& M);

        /**======================
         *@description: Preenche uma matrix conforme a entrada. A entrada deve estar padronizada no padrão csv
                no qual a primeira linha é o numero de linhas e o numero de colunas como o exemplo a seguir:
                        nRows,nCols
                        m[0,0],m[0,1]
                        m[1,0],m[1,1]
         *! Altera o objeto
         *@return type: istream&
         *========================**/ 
        friend std::istream& operator>>(std::istream& is, Matrix& M);

         /**======================
         *@description: Realiza a soma de duas matrizes
         *@return type: Matrix
         *========================**/ 
        Matrix operator+ (const Matrix& M) const;

         /**======================
         *@description: Realiza a soma de duas matrizes e guarda no objeto a esquerda
         *! Altera o objeto
         *@return type: Matrix&
         *========================**/ 
        Matrix& operator+= (const Matrix& M);

        /**======================
         *@description: Realiza a subtração de duas matrizes
         *@return type: Matrix
         *========================**/ 
        Matrix operator- (const Matrix& M) const;

        /**======================
         *@description: Realiza a subtração de duas matrizes e guarda no objeto a esquerda
         *! Altera o objeto
         *@return type: Matrix&
         *========================**/ 
        Matrix& operator-= (const Matrix& M);

        /**======================
         *@description: Realiza a trasposição da matriz
         *! Altera o objeto
         *@return type: Matrix&
         *========================**/ 
        Matrix& operator~ ();

        /**======================
         *@description: Realiza a multiplicação de duas matrizes
         *@return type: Matrix
         *========================**/ 
        Matrix operator* (const Matrix& M) const;

        /**======================
         *@description: Realiza a multiplicação de duas matrizes e guarda no objeto a esquerda
         *! Altera o objeto
         *@return type: Matrix&
         *========================**/ 
        Matrix& operator*= (const Matrix& M);

        /**======================
         *@description: Realiza a multiplicação de uma matris por um escalar
         *@return type: Matrix
         *========================**/ 
        Matrix operator* (const double& num) const;

        /**======================
         *@description: Realiza a multiplicação de uma matris por um escalar e guarda no objeto a esquerda
         *! Altera o objeto
         *@return type: Matrix&
         *========================**/ 
        Matrix& operator*= (const double& num);

        /**======================
         *@description: Compara duas matrizes
         *@return type: bool
         *========================**/ 
        bool operator== (const Matrix& M) const;
        bool operator!= (const Matrix& M) const;

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
 *               Funções inline
 *=============================================**/

inline int Matrix::getRows() const {return this->nRows;};

inline int Matrix::getCols() const {return this->nCols;};

inline double& Matrix::operator()(const int& row, const int& col) const{
    if(((row - 1) < 0) || ((col - 1) < 0) || (row > this->nRows) || (col > this->nCols)){
        std::cerr<<"Linha ou coluna inválida - segmentation fault"<<std::endl;
        exit(1);
    }
    return (this->m[row - 1][col - 1]);
}

#endif