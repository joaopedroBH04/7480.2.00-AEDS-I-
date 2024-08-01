#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Jo�o Pedro Costa Amaral - Matr�cula: 853488

// Fun��o 1011: Gerar um valor inteiro aleat�rio dentro de um intervalo
int RandomIntGenerate(int inferior, int superior) {
    return rand() % (superior - inferior + 1) + inferior;
}

// Fun��o 1012: Procurar um valor inteiro em um arranjo
bool arraySearch(int valor, int arranjo[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (arranjo[i] == valor) {
            return true;
        }
    }
    return false;
}

// Fun��o 1013: Comparar dois arranjos de inteiros
bool arrayCompare(int arranjo1[], int arranjo2[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (arranjo1[i] != arranjo2[i]) {
            return false;
        }
    }
    return true;
}

// Fun��o 1014: Somar dois arranjos, com o segundo escalado por uma constante
void arrayAdd(int arranjo1[], int constante, int arranjo2[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arranjo1[i] += constante * arranjo2[i];
    }
}

// Fun��o 1015: Verificar se um arranjo est� em ordem decrescente
bool isArrayDecrescent(int arranjo[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (arranjo[i] < arranjo[i + 1]) {
            return false;
        }
    }
    return true;
}

// Fun��o 1016: Obter a transposta de uma matriz
void matrixTranspose(int matriz[][100], int linhas, int colunas, int transposta[][100]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
}

// Fun��o 1017: Verificar se uma matriz s� cont�m valores iguais a zero
bool matrixZero(int matriz[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

// Fun��o 1018: Verificar a igualdade de duas matrizes
bool matrixCompare(int matriz1[][100], int matriz2[][100], int linhas, int colunas) {
    if (linhas != linhas || colunas != colunas) {
        return false; // Tamanhos diferentes
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz1[i][j] != matriz2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Fun��o 1019: Somar duas matrizes, com a segunda escalada por uma constante
void matrixAdd(int matriz1[][100], int constante, int matriz2[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz1[i][j] += constante * matriz2[i][j];
        }
    }
}

// Fun��o 1020: Obter o produto de duas matrizes
void matrixProduct(int matriz1[][100], int matriz2[][100], int resultado[][100], int linhas1, int colunas1, int colunas2) {
    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < colunas1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

// Fun��o Extra 10E1: Ordenar um arranjo em ordem decrescente
void sortArrayDown(int arranjo[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (arranjo[i] < arranjo[j]) {
                int temp = arranjo[i];
                arranjo[i] = arranjo[j];
                arranjo[j] = temp;
            }
        }
    }
}

// Fun��o Extra 10E2: Verificar se o produto de duas matrizes � a matriz identidade
bool identityMatrix(int matriz[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if ((i == j && matriz[i][j] != 1) || (i != j && matriz[i][j] != 0)) {
                return false;
            }
        }
    }
    return true;
}

// Fun��o auxiliar para ler um array de um arquivo
void readArrayFromFile(const char *filename, int arranjo[], int *tamanho) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    fscanf(fp, "%d", tamanho);
    for (int i = 0; i < *tamanho; i++) {
        fscanf(fp, "%d", &arranjo[i]);
    }

    fclose(fp);
}

// Fun��o auxiliar para ler uma matriz de um arquivo
void readMatrixFromFile(const char *filename, int matriz[][100], int *linhas, int *colunas) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    fscanf(fp, "%d %d", linhas, colunas);
    for (int i = 0; i < *linhas; i++) {
        for (int j = 0; j < *colunas; j++) {
            fscanf(fp, "%d", &matriz[i][j]);
        }
    }

    fclose(fp);
}

// Fun��o 1011: Gerar N n�meros aleat�rios e grav�-los em um arquivo
void generateRandomNumbers(int inferior, int superior, int quantidade) {
    FILE *fp = fopen("DADOS.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo DADOS.TXT\n");
        exit(1);
    }

    fprintf(fp, "%d\n", quantidade);
    for (int i = 0; i < quantidade; i++) {
        int valor = RandomIntGenerate(inferior, superior);
        fprintf(fp, "%d\n", valor);
    }

    fclose(fp);
}

int main() {
    // Testando as fun��es e m�todos

    // Exemplo de uso da fun��o 1011: Gerar n�meros aleat�rios
    int inferior, superior, quantidade;
    printf("Informe o limite inferior do intervalo: ");
    scanf("%d", &inferior);
    printf("Informe o limite superior do intervalo: ");
    scanf("%d", &superior);
    printf("Informe a quantidade de n�meros a serem gerados: ");
    scanf("%d", &quantidade);
    generateRandomNumbers(inferior, superior, quantidade);

    // Exemplo de uso da fun��o 1012: Procurar valor em arranjo
    int arranjo[100], tamanhoArranjo, valorProcurado;
    readArrayFromFile("DADOS.TXT", arranjo, &tamanhoArranjo);
    printf("Informe o valor a ser procurado no arranjo: ");
    scanf("%d", &valorProcurado);
    bool encontrado = arraySearch(valorProcurado, arranjo, tamanhoArranjo);
    if (encontrado) {
        printf("O valor %d foi encontrado no arranjo.\n", valorProcurado);
    } else {
        printf("O valor %d n�o foi encontrado no arranjo.\n", valorProcurado);
    }


