#include "../Interface_sudoku/backtracking.h"
#include "../Interface_sudoku/heuristica.h"
#include "../Interface_sudoku/in_out.h"
#include "../Interface_sudoku/tabuleiro.h"

int main(int argc, char *argv[]){
    FILE *arquivoSudoku = NULL;
    FILE *arquivoResultado = NULL;
    int tamanho = 0;

    lerArquivos(argc, argv, &arquivoSudoku, &arquivoResultado, &tamanho);

    while(verificaFimTabuleiro(arquivoSudoku)){
        int **tabuleiro = criaTabuleiro(tamanho);

        preencheTabuleiro(tabuleiro, arquivoSudoku, tamanho);

        if(verificaValidadeTabuleiro(tabuleiro, tamanho) == 0){
            if(resolver(tabuleiro, tamanho)){
                escreveResultado(tabuleiro, arquivoResultado, tamanho);
            } else {
                printf("\nUm dos tabuleiros é válido, porém não tem solução.\n");
            }
        } else {
            printf("\nUm dos tabuleiros não é válido, portanto impossível de resolver.\n");
        }

        destroiTabuleiro(tabuleiro, tamanho);
    }

    fclose(arquivoSudoku);
    fclose(arquivoResultado);

    return 0;
}