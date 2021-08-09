all: Teste

Teste: Programa_teste.o 
	@g++ Programa_teste.o -o Teste
	@echo Sucesso!

Programa_teste.o: Programa_teste.cpp Matrix.h
	@g++ -c Programa_teste.cpp -g

Clean:
	@rm  -f *.o Teste
	@echo Itens deletados!