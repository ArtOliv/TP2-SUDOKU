#include "../Interface_sudoku/backtracking.h"

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

// Verifia se o número é válido para ser colocado na coordenada do tabuleiro
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

// Resolve o tabuleiro com baktracking
int resolver(int **tabuleiro, int tamanho){
    int coord[2]; // Variável que guarda as coordenadas de uma célula a ser testada

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