/* Módulo para alocação e verificação do tabuleiro */

#include "../Interface_sudoku/tabuleiro.h"

int** criaTabuleiro(int tamanho){
    int** tabuleiro = (int**) malloc (tamanho * sizeof(int*));
    if(tabuleiro == NULL){
        printf("Erro na alocação do tabuleiro!\n");
        return NULL;
    }

    for(int i = 0; i < tamanho; i++){
        tabuleiro[i] = (int*) malloc (tamanho * sizeof(int));
        if(tabuleiro[i] == NULL){
            printf("Erro na alocação da linha do tabuleiro!\n");
            return NULL;
        }
    }

    return tabuleiro;
}

void destroiTabuleiro(int **tabuleiro, int tamanho){
    if(tabuleiro != NULL){
        for(int i = 0; i < tamanho; i++){
            free(tabuleiro[i]);
        }
        free(tabuleiro);
    }
}

// Verifica se há numeros iguais na mesma linha, coluna ou subgrid
int verificaValidadeTabuleiro(int **tabuleiro, int tamanho){
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(tabuleiro[i][j] != 0){
                int num = tabuleiro[i][j];
                tabuleiro[i][j] = 0; // Coloca 0 temporariamente para verificar se há outros numeros iguais

                if(!verificaValido(tabuleiro, (int[2]){i, j}, num, tamanho)){
                    return 1;
                }

                tabuleiro[i][j] = num; // Após verificar a validade atribui novamente o número original
            }
        }
    }
    return 0;
}

int verificaValido(int **tabuleiro, int coord[2], int num, int tamanho){
    for(int i = 0; i < tamanho; i++){ // Verifica a coluna
        if(tabuleiro[i][coord[1]] == num){
            return 0;
        }
    }

    for(int j = 0; j < tamanho; j++){ // Verifica a linha
        if(tabuleiro[coord[0]][j] == num){
            return 0;
        }
    }

    // Cálculo da posição inicial do subgrid da célula que está sendo verifiada
    int grid = sqrt(tamanho);
    int grid_inicio_x = coord[0] - coord[0] % grid;
    int grid_inicio_y = coord[1] - coord[1] % grid;
    
    for(int i = 0; i < grid; i++){ // Verifica o subgrid
        for(int j = 0; j < grid; j++){
            if(tabuleiro[grid_inicio_x + i][grid_inicio_y + j] == num){
                return 0;
            }
        }
    }
    return 1;
}