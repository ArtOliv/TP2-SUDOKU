/* Módulo para manipulação dos arquivos(leitura e escrita) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <getopt.h>

int lerArquivos(int argc, char *argv[], FILE **arquivoSudoku, FILE **arquivoResultado, int *tamanho);

void preencheTabuleiro(int **tabuleiro, FILE *arquivoSudoku, int tamanho);

int verificaFimTabuleiro(FILE *arquivoSudoku);

void escreveResultado(int **tabuleiro, FILE *arquivoResultado, int tamanho);