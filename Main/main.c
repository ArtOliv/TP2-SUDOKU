#include "../Interface_sudoku/backtracking.h"
#include "../Interface_sudoku/in_out.h"

int main(int argc, char *argv[]){
    FILE *arquivoSudoku = NULL;
    FILE *arquivoResultado = NULL;
    int tamanho = 0;

    lerArquivos(argc, argv, &arquivoSudoku, &arquivoResultado, &tamanho);

    while(verificaFimTabuleiro(arquivoSudoku)){
        int **tabuleiro = criaTabuleiro(tamanho);

        preencheTabuleiro(tabuleiro, arquivoSudoku, tamanho);
        for(int i = 0; i < tamanho; i++){
            for(int j = 0; j < tamanho; j++){
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }

        if(verificaValidadeTabuleiro(tabuleiro, tamanho) == 0){
            if(resolver(tabuleiro, tamanho)){
                escreveResultado(tabuleiro, arquivoResultado, tamanho);
            
                imprimeTabuleiro(tabuleiro, tamanho);
            } else {
                printf("O tabuleiro é válido, porém não tem solução.\n");
            }
        } else {
            printf("O tabuleiro não é válido, portanto impossível de resolver.\n");
        }

        destroiTabuleiro(tabuleiro, tamanho);
    }

    fclose(arquivoSudoku);
    fclose(arquivoResultado);

    return 0;
}