#include "../Interface_sudoku/backtracking.h"

char** criaTabuleiro(){
    char** tabuleiro = (char**) malloc (9 * sizeof(char*));
    if(tabuleiro == NULL){
        printf("Erro na alocação do tabuleiro!\n");
        return NULL;
    }

    for(int i = 0; i < 9; i++){
        tabuleiro[i] = (char*) malloc (9 * sizeof(char));
        if(tabuleiro[i] == NULL){
            printf("Erro na alocação da linha do tabuleiro!\n");
            return NULL;
        }
    }

    return tabuleiro;
}

void destroiTabuleiro(char **tabuleiro){
    if(tabuleiro != NULL){
        for(int i = 0; i < 9; i++){
            free(tabuleiro[i]);
        }
        free(tabuleiro);
    }
}

int verificaValidadeTabuleiro(char **tabuleiro){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(tabuleiro[i][j] != 'v'){
                int num = tabuleiro[i][j] - '0';
                tabuleiro[i][j] = 'v';

                if(!verificaValido(tabuleiro, (int[2]){i, j}, num)){
                    return 1;
                }

                tabuleiro[i][j] = num + '0';
            }
        }
    }
    return 0;
}

int acharPosicaoVazia(char **tabuleiro, int coord[2]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(tabuleiro[i][j] == 'v'){
                coord[0] = i;
                coord[1] = j;
                return 1;
            }
        }    
    }
    return 0;
}

int verificaValido(char **tabuleiro, int coord[2], int num){
    for(int i = 0; i < 9; i++){
        if(tabuleiro[i][coord[1]] == num + '0'){
            return 0;
        }
    }

    for(int j = 0; j < 9; j++){
        if(tabuleiro[coord[0]][j] == num + '0'){
            return 0;
        }
    }

    int grid_inicio_x = coord[0] - coord[0] % 3;
    int grid_inicio_y = coord[1] - coord[1] % 3;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tabuleiro[grid_inicio_x + i][grid_inicio_y + j] == num + '0'){
                return 0;
            }
        }
    }
    return 1;
}

int resolver(char **tabuleiro){
    int coord[2];

    if(acharPosicaoVazia(tabuleiro, coord) == 0){
        return 1;
    }
    
    for(int i = 1; i <= 9; i++){
        if(verificaValido(tabuleiro, coord, i)){
            tabuleiro[coord[0]][coord[1]] = i + '0';
            if(resolver(tabuleiro)){
                return 1;
            }
            tabuleiro[coord[0]][coord[1]] = 'v';
        }
    }
    return 0;
}