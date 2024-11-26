#include "../Interface_sudoku/backtracking.h"
#include "../Interface_sudoku/in_out.h"

int main(int argc, char *argv[]){
    FILE *arquivoSudoku = NULL;
    FILE *arquivoResultado = NULL;

    lerArquivos(argc, argv, &arquivoSudoku, &arquivoResultado);

    char **tabuleiro = criaTabuleiro();

    preencheTabuleiro(tabuleiro, arquivoSudoku);

    if(verificaValidadeTabuleiro(tabuleiro) == 0){
        resolver(tabuleiro);

        escreveResultado(tabuleiro, arquivoResultado);
        
        imprimeTabuleiro(tabuleiro);
        
        destroiTabuleiro(tabuleiro);
        
    } else {
        printf("O tabuleiro não é válido, portanto impossível de resolver.\n");

        fclose(arquivoResultado);
        
        destroiTabuleiro(tabuleiro);
    }

    return 0;
}