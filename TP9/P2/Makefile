all: Teste

Teste: Programa_teste.o Funcoes.o Funcao.o
	g++ Programa_teste.o Funcoes.o Funcao.o -o Teste 
	@echo Compilação bem sucedida!

Programa_teste.o: Programa_teste.cpp 
	g++ -c Programa_teste.cpp -g

Funcoes.o: Funcoes.cpp Funcoes.h
	g++ -c Funcoes.cpp -g

Funcao.o: Funcao.cpp Funcao.h
	g++ -c Funcao.cpp -g

clean: 
	@rm -f *.o Teste
	@echo Itens deletados!