#include "../Interface_sudoku/in_out.h"

int lerArquivos(int argc, char *argv[], FILE **arquivoSudoku, FILE **arquivoResultado){
    int opt;
    while((opt = getopt(argc, argv, "i:o:")) != -1){
        switch(opt){
            case 'i':
                *arquivoSudoku = fopen(optarg, "r");
                if(*arquivoSudoku == NULL){
                    printf("Erro ao ler o arquivo de entrada.\n");
                    return 1;
                }
                break;
            case 'o':
                *arquivoResultado = fopen(optarg, "w");
                if(*arquivoResultado == NULL){
                    printf("Erro ao ler o arquivo para escrita.\n");
                    if(*arquivoSudoku){
                        fclose(*arquivoSudoku);
                    }
                    return 1;
                }
                break;
            default:
                printf("Arquivos inválidos!");
                exit(EXIT_FAILURE);
        }
    }

    if(!*arquivoSudoku || !*arquivoResultado){
        printf("Foram passados argumentos insuficientes!\n");
        return 1;
    }
    return 0;
}

void preencheTabuleiro(char **tabuleiro, FILE *arquivoSudoku){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            fscanf(arquivoSudoku, " %c", &tabuleiro[i][j]);
        }
    }
    fclose(arquivoSudoku);
}

void escreveResultado(char **tabuleiro, FILE *arquivoResultado){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            fprintf(arquivoResultado, "%c ", tabuleiro[i][j]);
        }
        fprintf(arquivoResultado, "\n");
    }
    fclose(arquivoResultado);
}

void imprimeTabuleiro(char **tabuleiro){
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