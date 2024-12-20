#include "../Interface_sudoku/backtracking.h"
#include "../Interface_sudoku/tabuleiro.h"

// Procura uma posição vazia no tabuleiro e atribui as coordenadas da posição à variável coord
int acharPosicaoVazia(int **tabuleiro, int coord[2], int tamanho){
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(tabuleiro[i][j] == 0){
                coord[0] = i;
                coord[1] = j;
                return 1;
            }
        }    
    }
    return 0;
}

// Resolve o tabuleiro com baktracking
int resolver(int **tabuleiro, int tamanho){
    int coord[2]; // Array que guarda as coordenadas de uma célula a ser testada

    if(acharPosicaoVazia(tabuleiro, coord, tamanho) == 0){ // Se não há mais células vazias, o tabuleiro está resolvido
        return 1;
    }
    
    for(int i = 1; i <= tamanho; i++){
        if(verificaValido(tabuleiro, coord, i, tamanho)){
            tabuleiro[coord[0]][coord[1]] = i; // Se o número for válido, coloca o número na célula

            if(resolver(tabuleiro, tamanho)){ // Chama novamente a função para testar outras células
                return 1;
            }

            tabuleiro[coord[0]][coord[1]] = 0; // Se não funcionar, volta a célula para 0
        }
    }
    return 0; // Se retornar 0, significa que o tabuleiro atingiu um dead-end e não pode ser resolvido
}