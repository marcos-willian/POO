all: Teste

Teste: ProfessorCategorias.o Programa_teste.o Universidade.o
	g++ Programa_teste.o ProfessorCategorias.o Universidade.o -o Teste

Programa_teste.o: Programa_teste.cpp
	g++ -c Programa_teste.cpp -g

ProfessorCategorias.o: ProfessorCategorias.cpp ProfessorCategorias.h Professor.h
	g++ -c ProfessorCategorias.cpp -g

Universidade.o: Universidade.cpp Universidade.h
	g++ -c Universidade.cpp -g

clean:
	rm *.o Teste