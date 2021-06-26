
all: Matrix_p1

Matrix_p1: Programa_teste.o Matrix.o
	g++ Programa_teste.o Matrix.o -o Matrix_p1


Programa_teste.o: Programa_teste.cpp 
	g++ -c Programa_teste.cpp -g

Matrix.o: Matrix.cpp Matrix.h 
	g++ -c Matrix.cpp -g

Clean:
	rm *.o