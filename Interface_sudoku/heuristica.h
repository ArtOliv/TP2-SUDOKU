#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>

void calcularValoresPossiveis(int **tabuleiro, int coord[2], int tamanho, int *valores, int *count);

int encontrarCelula(int **tabuleiro, int coord[2], int tamanho, int *valores, int *count);

int resolver(int **tabuleiro, int tamanho);