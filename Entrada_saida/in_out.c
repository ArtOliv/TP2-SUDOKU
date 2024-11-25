#include "../Interface_sudoku/in_out.h"

//Função de leitura de arquivo aqui

void imprimeTabuleiro(char tabuleiro[9][9]){
    printf("+ - - - - - - - - - - - +\n");

    for(int i = 0; i < 9; i++){
        printf("| ");

        for(int j = 0; j < 9; j++){
            printf("%c ", tabuleiro[i][j]);

            if((j + 1) % 3 == 0 && j != 8){
                printf("| ");
            }

        }
        printf("|\n");

        if((i + 1) % 3 == 0 && i != 8){
            printf("| - - - + - - - + - - - |\n");
        }
    }

    printf("+ - - - - - - - - - - - +\n");
}