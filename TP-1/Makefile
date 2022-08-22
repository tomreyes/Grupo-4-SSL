# How to run: mingw32-make.exe run
all: calculadoraPolaca.exe

run: calculadoraPolaca.exe
	./calculadoraPolaca.exe

calculadoraPolaca.exe: calculadoraPolaca.o get_token.o stack.o buffer.o
	gcc calculadoraPolaca.o get_token.o stack.o buffer.o -o calculadoraPolaca.exe

calculadoraPolaca.o: calculadoraPolaca.c
	gcc -c calculadoraPolaca.c -std=c18 -o calculadoraPolaca.o

get_token.o: get_token.c
	gcc -c get_token.c -std=c18 -o get_token.o

stack.o: stack.c
	gcc -c stack.c -std=c18 -o stack.o

buffer.o: buffer.c
	gcc -c buffer.c -std=c18 -o buffer.o
clean: 
	del buffer.o
	del stack.o
	del get_token.o
	del calculadoraPolaca.o
	del calculadoraPolaca.exe