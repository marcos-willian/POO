all: Teste

Teste: Programa_teste.o Box.o
	@g++ Programa_teste.o Box.o -o Teste
	@echo Sucesso!

Programa_teste.o: Programa_teste.cpp 
	@g++ -c Programa_teste.cpp -g

Box.o: Box.cpp Box.h Ponto2D.h Ponto3D.h
	@g++ -c  Box.cpp -g
Clean:
	@rm  -f *.o Teste
	@echo Itens deletados!