PC = gcc
CFLAGS = -Wall -lm
EXECBT = backtracking
EXECHEU = heuristica
OBJ = main.o in_out.o tabuleiro.o
INTERFACE = Interface_sudoku/backtracking.h Interface_sudoku/heuristica.h Interface_sudoku/in_out.h Interface_sudoku/tabuleiro.h
CAMINHO = ./Entrada_saida/Entrada/

all: $(EXECBT) $(EXECHEU)

$(EXECBT): $(OBJ) backtracking.o
	$(PC) $(OBJ) backtracking.o $(CFLAGS) -o $(EXECBT)

$(EXECHEU): $(OBJ) heuristica.o
	$(PC) $(OBJ) heuristica.o $(CFLAGS) -o $(EXECHEU)

main.o: Main/main.c $(INTERFACE)
	$(PC) $(CFLAGS) -c Main/main.c

in_out.o: Entrada_saida/in_out.c $(INTERFACE)
	$(PC) $(CFLAGS) -c Entrada_saida/in_out.c

tabuleiro.o: Entrada_saida/tabuleiro.c $(INTERFACE)
	$(PC) $(CFLAGS) -c Entrada_saida/tabuleiro.c

backtracking.o: Forca_bruta/backtracking.c $(INTERFACE)
	$(PC) $(CFLAGS) -c Forca_bruta/backtracking.c

heuristica.o: Heuristica/heuristica.c $(INTERFACE)
	$(PC) $(CFLAGS) -c Heuristica/heuristica.c

clean:
	rm -f *.o
	rm -f $(EXECBT) $(EXECHEU)

run1: $(EXECBT)
	./$(EXECBT) -i $(CAMINHO)sudoku.txt -o $(CAMINHO)resultado.txt

run2: $(EXECHEU)
	./$(EXECHEU) -i $(CAMINHO)sudoku.txt -o $(CAMINHO)resultado.txt