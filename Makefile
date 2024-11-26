PC = gcc
CFLAGS = -Wall
EXECBT = backtracking
OBJ = main.o in_out.o backtracking.o
INTERFACEBT = Interface_sudoku/backtracking.h Interface_sudoku/in_out.h
CAMINHO = ./Entrada_saida/Entrada/

all: $(OBJ)
	$(PC) $(OBJ) $(CFLAGS) -o $(EXECBT)

main.o: Main/main.c $(INTERFACEBT)
	$(PC) $(CFLAGS) -c Main/main.c

in_out.o: Entrada_saida/in_out.c $(INTERFACEBT)
	$(PC) $(CFLAGS) -c Entrada_saida/in_out.c

backtracking.o: Forca_bruta/backtracking.c $(INTERFACEBT)
	$(PC) $(CFLAGS) -c Forca_bruta/backtracking.c

clean:
	rm *.o
	rm $(EXECBT)

run: $(EXECBT)
	./$(EXECBT) -i $(CAMINHO)sudoku.txt -o $(CAMINHO)resultado.txt