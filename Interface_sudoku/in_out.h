#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int lerArquivos(int argc, char *argv[], FILE **arquivoSudoku, FILE **arquivoResultado);

void preencheTabuleiro(char **tabuleiro, FILE *arquivoSudoku);

void escreveResultado(char **tabuleiro, FILE *arquivoResultado);

void imprimeTabuleiro(char **tabuleiro);