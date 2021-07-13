all: Teste_Ponto2D

Teste_Ponto2D: Programa_teste.o Ponto2D.o
	g++ Programa_teste.o Ponto2D.o -o Teste_Ponto2D

Programa_teste.o: Programa_teste.cpp Ponto2D.h
	g++ -c Programa_teste.cpp -g

Ponto2D.o: Ponto2D.cpp Ponto2D.h 
	g++ -c Ponto2D.cpp -g