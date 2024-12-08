#include "../Interface_sudoku/in_out.h"

// Abre os arquivos de entrada e saída, o primiro para leitura e o segundo para escrita
int lerArquivos(int argc, char *argv[], FILE **arquivoSudoku, FILE **arquivoResultado, int *tamanho){
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

    if(!*arquivoSudoku || !*arquivoResultado){ // Verifica se o argumentos foram passados corretamente
        printf("Foram passados argumentos insuficientes!\n");
        exit(EXIT_FAILURE);
    }

    // Calcula o tamanho do tabuleiro lendo a primeira linha e contando os tokens
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), *arquivoSudoku)){ // Lê o arquivo de entrada
        char *token = strtok(buffer, " "); // Divide a linha em tokens
        while(token != NULL){ // Enquanto houver tokens o tamanho é acrescentado
            (*tamanho)++;
            token = strtok(NULL, " "); // Retorna nulo quando não há mais tokens
        }
        break; // Conta apenas a primeira linha
    }

    int raiz = sqrt(*tamanho);
    if(raiz * raiz != *tamanho){ // Verifica se o tamanho do sudoku é um quadrado perfeito
        printf("O sudoku não é um quadrado perfeito!\n");
        exit(EXIT_FAILURE);
    }

    printf("tamanho: %d\n", *tamanho);

    rewind(*arquivoSudoku); // Retorna o ponteiro para o início do arquivo
    return 0;
}

// Preenhe a matriz alocada com os valores iniciais do arquivo de entrada
void preencheTabuleiro(int **tabuleiro, FILE *arquivoSudoku, int tamanho){
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            char buffer[4]; // Buffer de tamanho 4 que guarda o valor em string, pois pode haver valores com dois dígitos
            fscanf(arquivoSudoku, "%s", buffer);
            if(buffer[0] == 'v'){ // Se o valor for vazio('v'), coloca 0 no tabuleiro
                tabuleiro[i][j] = 0;
            } else { // Se o valor não for vazio('v'), converte o valor para inteiro e coloca no tabuleiro
                tabuleiro[i][j] = atoi(buffer);
            }
        }
    }
}

int verificaFimTabuleiro(FILE *arquivoSudoku){
    int c;
    // Lê caracter por caracter até o final do arquivo ignorando espaços e quebra de linha
    while((c = fgetc(arquivoSudoku)) != EOF){
        if(c != '\n' && c != ' '){
            ungetc(c, arquivoSudoku); // Retorna o caracter para o buffer
            return 1; // Ainda há tabuleiros para resolver
        }
    }
    return 0; // Fim do arquivo
}

// Escreve o tabuleiro resolvido no arquivo de saída
void escreveResultado(int **tabuleiro, FILE *arquivoResultado, int tamanho){
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            fprintf(arquivoResultado, "%d ", tabuleiro[i][j]);
        }
        fprintf(arquivoResultado, "\n");
    }
    fprintf(arquivoResultado, "\n"); // Linha em branco para separar os tabuleiros resolvidos
}

void imprimeTabuleiro(int **tabuleiro, int tamanho){
    int grid = sqrt(tamanho);
    
    for(int i = 0; i < tamanho * grid; i++){
        printf("-");
    }
    printf("\n");

    for(int i = 0; i < tamanho; i++){
        printf("| ");

        for(int j = 0; j < tamanho; j++){
            printf("%d ", tabuleiro[i][j]);

            if((j + 1) % grid == 0 && j != tamanho - 1){
                printf("| ");
            }

        }
        printf("|\n");

        if((i + 1) % grid == 0 && i != tamanho - 1){
            for(int k = 0; k < tamanho * grid; k++){
                printf("-");
            }
            printf("\n");
        }
    }

    for(int i = 0; i < tamanho * grid; i++){
        printf("-");
    }
    printf("\n");
}