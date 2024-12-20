/* Módulo para alocação e verificação do tabuleiro */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>

int** criaTabuleiro(int tamanho);

void destroiTabuleiro(int **tabuleiro, int tamanho);

int verificaValidadeTabuleiro(int **tabuleiro, int tamanho);

int verificaValido(int **tabuleiro, int coord[2], int num, int tamanho);