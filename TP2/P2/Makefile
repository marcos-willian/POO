
all: Teste_tempo

Teste_tempo: Programa_teste.o Tempo.o
	g++ Programa_teste.o Tempo.o -o Teste_tempo

Programa_teste.o: Programa_teste.cpp Tempo.h
	g++ -c Programa_teste.cpp -g

Tempo.o: Tempo.cpp Tempo.h 
	g++ -c Tempo.cpp -g