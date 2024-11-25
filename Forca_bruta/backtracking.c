#include "../Interface_sudoku/backtracking.h"

int acharPosicaoVazia(char tabuleiro[9][9], int coord[2]){
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

int verificaValido(char tabuleiro[9][9], int coord[2], int num){
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

int resolver(char tabuleiro[9][9]){
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