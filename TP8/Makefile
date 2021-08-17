all: Teste

Teste: ProgramaTeste.o Agenda.o Conhecido.o Amigo.o Pessoa.o 
	g++ Pessoa.o Agenda.o Conhecido.o  Amigo.o ProgramaTeste.o -o Teste

ProgramaTeste.o: ProgramaTeste.cpp
	g++ -c ProgramaTeste.cpp -g

Agenda.o: Agenda.cpp Agenda.h 
	g++ -c Agenda.cpp -g

Conhecido.o: Conhecido.cpp Conhecido.h
	g++ -c Conhecido.cpp -g

Amigo.o: Amigo.cpp Amigo.h
	g++ -c Amigo.cpp -g

Pessoa.o: Pessoa.cpp Pessoa.h
	g++ -c Pessoa.cpp -g

cls: 
	rm *.o Teste