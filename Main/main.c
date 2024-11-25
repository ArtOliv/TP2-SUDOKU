#include "../Interface_sudoku/backtracking.h"
#include "../Interface_sudoku/in_out.h"

int main(int argc, char *argv[]){
    char tabuleiro[9][9] = {{'v', 'v', '1', '8', 'v', 'v', '3', 'v', 'v'},
                            {'v', '4', '9', '7', '1', '6', 'v', '8', 'v'},
                            {'v', '2', 'v', 'v', '9', 'v', 'v', 'v', 'v'},
                            {'v', 'v', '4', 'v', 'v', 'v', 'v', '2', 'v'},
                            {'v', '5', '6', 'v', 'v', '1', '8', 'v', 'v'},
                            {'v', '1', 'v', 'v', 'v', 'v', '5', 'v', '9'},
                            {'v', 'v', 'v', 'v', 'v', 'v', '4', '3', 'v'},
                            {'v', 'v', 'v', '1', '6', 'v', 'v', 'v', '8'},
                            {'7', 'v', 'v', 'v', 'v', '2', 'v', 'v', '1'}};

    resolver(tabuleiro);
    
    imprimeTabuleiro(tabuleiro);

    return 0;
}