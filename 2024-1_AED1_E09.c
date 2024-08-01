#include <stdio.h>
#include <stdbool.h>

// João Pedro Costa Amaral - Matrícula: 853488

// Função 0911: Ler dimensões e elementos de uma matriz real (apenas valores negativos)
void readNegativeDoubleMatrix(int rows, int cols, double matrix[rows][cols]) {
    printf("Digite os elementos da matriz %d x %d (valores negativos):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            do {
                printf("Elemento [%d][%d]: ", i, j);
                scanf("%lf", &matrix[i][j]);
            } while (matrix[i][j] >= 0);
        }
    }
}

// Função 0912: Gravar uma matriz real em arquivo
void fprintDoubleMatrix(const char *filename, int rows, int cols, double matrix[rows][cols]) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    fprintf(fp, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(fp, "%.2lf ", matrix[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Função 0913: Mostrar os valores na diagonal principal de uma matriz real
void printDiagonalDoubleMatrix(int size, double matrix[size][size]) {
    printf("Elementos da diagonal principal:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2lf ", matrix[i][i]);
    }
    printf("\n");
}

// Função 0914: Mostrar os valores na diagonal secundária de uma matriz real
void printSDiagonalDoubleMatrix(int size, double matrix[size][size]) {
    printf("Elementos da diagonal secundária:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2lf ", matrix[i][size - i - 1]);
    }
    printf("\n");
}

// Função 0915: Mostrar os valores abaixo e na diagonal principal de uma matriz real
void printLDTriangleDoubleMatrix(int size, double matrix[size][size]) {
    printf("Elementos abaixo e na diagonal principal:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Função 0916: Mostrar os valores acima e na diagonal principal de uma matriz real
void printLUTriangleDoubleMatrix(int size, double matrix[size][size]) {
    printf("Elementos acima e na diagonal principal:\n");
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Função 0917: Mostrar os valores abaixo e na diagonal secundária de uma matriz real
void printSLDTriangleDoubleMatrix(int size, double matrix[size][size]) {
    printf("Elementos abaixo e na diagonal secundária:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= size - i - 1; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Função 0918: Mostrar os valores acima e na diagonal secundária de uma matriz real
void printSLUTriangleDoubleMatrix(int size, double matrix[size][size]) {
    printf("Elementos acima e na diagonal secundária:\n");
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j >= i; j--) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Função 0919: Verificar se não são todos zeros os valores abaixo da diagonal principal de uma matriz real
bool allZerosLTriangleDoubleMatrix(int size, double matrix[size][size]) {
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != 0) {
                return false; // Encontrou um valor diferente de zero abaixo da diagonal principal
            }
        }
    }
    return true; // Todos os valores abaixo da diagonal principal são zeros
}

// Função 0920: Verificar se são todos zeros os valores acima da diagonal principal de uma matriz real
bool allZerosUTriangleDoubleMatrix(int size, double matrix[size][size]) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (matrix[i][j] != 0) {
                return false; // Encontrou um valor diferente de zero acima da diagonal principal
            }
        }
    }
    return true; // Todos os valores acima da diagonal principal são zeros
}

// Função Extra 09E1: Montar uma matriz com padrão específico e gravá-la em arquivo
void createAndSavePatternMatrix1() {
    int matrix1[4][8] = {
        {1, 2, 3, 4, 0, 0, 0, 0},
        {1, 2, 3, 5, 6, 7, 8, 0},
        {1, 2, 4, 5, 6, 9, 10, 11},
        {3, 4, 7, 8, 9, 13, 14, 15}
    };

    FILE *fp = fopen("MATRIX_PATTERN1.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo MATRIX_PATTERN1.TXT\n");
        return;
    }

    fprintf(fp, "4 8\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            fprintf(fp, "%d ", matrix1[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Função Extra 09E2: Montar uma matriz com padrão específico e gravá-la em arquivo
void createAndSavePatternMatrix2() {
    int matrix2[4][9] = {
        {16, 15, 14, 13, 0, 0, 0, 0, 0},
        {9, 8, 7, 12, 11, 10, 9, 0, 0},
        {4, 3, 6, 5, 4, 8, 7, 6, 5},
        {2, 1, 3, 2, 1, 4, 3, 2, 1}
    };

    FILE *fp = fopen("MATRIX_PATTERN2.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo MATRIX_PATTERN2.TXT\n");
        return;
    }

    fprintf(fp, "4 9\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 9; j++) {
            fprintf(fp, "%d ", matrix2[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main() {
    // Testando as funções e métodos

    // Exemplo de uso das funções principais
    double negativeMatrix[10][10];
    readNegativeDoubleMatrix(3, 3, negativeMatrix);
    printDiagonalDoubleMatrix(3, negativeMatrix);
    printSDiagonalDoubleMatrix(3, negativeMatrix);
    printLDTriangleDoubleMatrix(3, negativeMatrix);
    printLUTriangleDoubleMatrix(3, negativeMatrix);
    printSLDTriangleDoubleMatrix(3, negativeMatrix);
    printSLUTriangleDoubleMatrix(3, negativeMatrix);
    bool result1 = allZerosLTriangleDoubleMatrix(3, negativeMatrix);
    bool result2 = allZerosUTriangleDoubleMatrix(3, negativeMatrix);
    printf("A matriz abaixo da diagonal principal não é toda zero? %s\n", result1 ? "Sim" : "Não");
    printf("A matriz acima da diagonal principal é toda zero? %s\n", result2 ? "Sim" : "Não");

    // Exemplo de uso das funções extras
    createAndSavePatternMatrix1();
    createAndSavePatternMatrix2();

    return 0;
}
