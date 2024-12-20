#include "../Interface_sudoku/heuristica.h"
#include "../Interface_sudoku/tabuleiro.h"

// Calcula valores possíveis a serem colocado em uma célula
void calcularValoresPossiveis(int **tabuleiro, int coord[2], int tamanho, int *valores, int *count){
    *count = 0;

    if(tabuleiro[coord[0]][coord[1]] != 0){ // Retorna se a célula já foi preenchidaa
        return;
    }

    for(int i = 1; i <= tamanho; i++){
        if(verificaValido(tabuleiro, coord, i, tamanho)){
            valores[(*count)++] = i;
        }
    }
}

// Encontra a célula com o menor número de valores possíveis
// Caso encontre uma célula com apenas um valor possível, já é feita a atribuição
int encontrarCelula(int **tabuleiro, int coord[2], int tamanho, int *valores, int *count){
    int min_count = tamanho + 1;
    int celulaVazia = 0;

    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(tabuleiro[i][j] == 0){ // Se célula vazia 
                celulaVazia = 1;
                int valoresTemp[tamanho];
                int countTemp;

                calcularValoresPossiveis(tabuleiro, (int[2]){i, j}, tamanho, valoresTemp, &countTemp);

                if(countTemp == 0){ // Se não há valores possíveis é inválido
                    *count = 0;
                    return 0;
                }

                if(countTemp < min_count){ // Atualiza a célula com menos valores possíveis
                    min_count = countTemp;
                    coord[0] = i;
                    coord[1] = j;
                    // Copia os valores temporários para os valores originais
                    *count = countTemp;                 
                    for(int k = 0; k < countTemp; k++){
                        valores[k] = valoresTemp[k];
                    }
                }

                if(countTemp == 1){ // Se a célula tem apenas um valor possível, o valor é atribuído imediatamente
                    return 1;
                } 
            }
        }
    }

    if(celulaVazia){
        return min_count;
    } else {
        return tamanho + 1;
    }
}

int resolver(int **tabuleiro, int tamanho){
    int coord[2]; // Array que guarda as coordenadas de uma célula a ser testada
    int valores[tamanho]; // Array que guarda os valores possíveis para uma célula
    int count;

    if(encontrarCelula(tabuleiro, coord, tamanho, valores, &count) == tamanho + 1){
        return 1;
    }

    if(count == 0){
        return 0; // Se não há valores possíveis para a célula, não há solução
    }

    for(int i = 0; i < count; i++){
        tabuleiro[coord[0]][coord[1]] = valores[i]; // Tenta valores na célula

        if(resolver(tabuleiro, tamanho)){ // Chama novamente a função para testar outras células
            return 1;
        }

        tabuleiro[coord[0]][coord[1]] = 0; // Se não funcionar, volta a célula para 0
    }
    return 0; // Se retornar 0, significa que o tabuleiro atingiu um dead-end e não pode ser resolvido
}