all: testProgram
	
testProgram: testProgram.o 
	g++ testProgram.o -o testProgram
	

testProgram.o: testProgram.cpp List.h
	g++ -c testProgram.cpp -g

cls: 
	rm *.o testProgram