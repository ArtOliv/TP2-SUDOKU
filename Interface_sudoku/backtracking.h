#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

char** criaTabuleiro();

void destroiTabuleiro(char **tabuleiro);

int verificaValidadeTabuleiro(char **tabuleiro);

int acharPosicaoVazia(char **tabuleiro, int coord[2]);

int verificaValido(char **tabuleiro, int coord[2], int num);

int resolver(char **tabuleiro);