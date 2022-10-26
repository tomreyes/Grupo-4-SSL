# Variables
CC = gcc
CFlags = -Wall -Wextra -std=c18
CALCULADORA_C = calculadoraPolaca.c
CALCULADORA_O = calculadoraPolaca.o
CALCULADORA = calculadoraPolaca.exe
SCANNER_L = scanner.l
STACK_O = stack.o
STACK_C = stack.c
STACK_H = stack.h
RESULTS = results.txt
SCANNER_H = scanner.h
SCANNER_O = scanner.o
SCANNER_AUTO_C = lex.scanner.c
SCANNER_MANUAL_C = scanner.c
EXPRESSIONS = expressions.txt
EXPECTED = expected.txt

ifdef OS
   RM = del
else
   ifeq ($(shell uname), Linux)
      RM = rm -f
   endif
endif

# How to run: mingw32-make.exe run

auto:
	 $(eval SCANNER_C = $(SCANNER_AUTO_C))

manual:
	 $(eval SCANNER_C = $(SCANNER_MANUAL_C))

test_manual: manual $(CALCULADORA)
	$(CALCULADORA) < $(EXPRESSIONS) > $(RESULTS)
	comp $(EXPECTED) $(RESULTS)
	$(RM) $(RESULTS)

test_auto: auto $(CALCULADORA)
	$(CALCULADORA) < $(EXPRESSIONS) > $(RESULTS)
	comp $(EXPECTED) $(RESULTS)
	$(RM) $(RESULTS)

run_auto: auto $(CALCULADORA)
	./$(CALCULADORA)

run_manual: manual $(CALCULADORA)
	./$(CALCULADORA)

$(CALCULADORA): $(CALCULADORA_O) $(SCANNER_O) $(STACK_O)
	$(CC) $(CALCULADORA_O) $(SCANNER_O) $(STACK_O) -o $(CALCULADORA)

$(CALCULADORA_O): $(CALCULADORA_C) $(SCANNER_H) $(STACK_H)
	$(CC) $(CFlags) -c $(CALCULADORA_C)  

$(SCANNER_O): $(SCANNER_C) $(SCANNER_H)
	$(CC) $(CFlags) -c $(SCANNER_C) -o $(SCANNER_O)

$(STACK_O): $(STACK_C) $(STACK_H)
	$(CC) $(CFlags) -c $(STACK_C) 

$(SCANNER_AUTO_C): $(SCANNER_L)
	flex $(SCANNER_L)

clean:
	$(RM) $(STACK_O)
	$(RM) $(SCANNER_O)
	$(RM) $(SCANNER_AUTO_C)
	$(RM) $(CALCULADORA_O)
	$(RM) $(CALCULADORA)
	$(RM) $(RESULTS)