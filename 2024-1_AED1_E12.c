#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// João Pedro Costa Amaral - Matrícula: 853488

// Função 1211: Gerar uma matriz aleatória e gravá-la em um arquivo
void generateRandomMatrix(int M, int N, int inferior, int superior) {
    FILE *fp = fopen("DADOS.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo DADOS.TXT\n");
        exit(1);
    }

    fprintf(fp, "%d %d\n", M, N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int valor = rand() % (superior - inferior + 1) + inferior;
            fprintf(fp, "%d ", valor);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Função 1212: Escalar uma matriz multiplicando todos os seus valores por uma constante
void scalarMatrix(const char *filename, int constante) {
    FILE *fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    int M, N;
    fscanf(fp, "%d %d", &M, &N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int valor;
            fscanf(fp, "%d", &valor);
            fseek(fp, -sizeof(int), SEEK_CUR);
            fprintf(fp, "%d ", valor * constante);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Função 1213: Verificar se uma matriz é a identidade
bool isIdentityMatrix(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    int M, N;
    fscanf(fp, "%d %d", &M, &N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int valor;
            fscanf(fp, "%d", &valor);
            if ((i == j && valor != 1) || (i != j && valor != 0)) {
                fclose(fp);
                return false;
            }
        }
    }

    fclose(fp);
    return true;
}

// Função 1214: Testar a igualdade de duas matrizes
bool isEqualMatrix(const char *filename1, const char *filename2) {
    FILE *fp1 = fopen(filename1, "r");
    if (fp1 == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename1);
        exit(1);
    }

    FILE *fp2 = fopen(filename2, "r");
    if (fp2 == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename2);
        fclose(fp1);
        exit(1);
    }

    int M1, N1, M2, N2;
    fscanf(fp1, "%d %d", &M1, &N1);
    fscanf(fp2, "%d %d", &M2, &N2);

    if (M1 != M2 || N1 != N2) {
        fclose(fp1);
        fclose(fp2);
        return false;
    }

    for (int i = 0; i < M1; i++) {
        for (int j = 0; j < N1; j++) {
            int valor1, valor2;
            fscanf(fp1, "%d", &valor1);
            fscanf(fp2, "%d", &valor2);
            if (valor1 != valor2) {
                fclose(fp1);
                fclose(fp2);
                return false;
            }
        }
    }

    fclose(fp1);
    fclose(fp2);
    return true;
}

// Função 1215: Somar duas matrizes e mostrar o resultado
void addMatrices(const char *filename1, const char *filename2) {
    FILE *fp1 = fopen(filename1, "r");
    if (fp1 == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename1);
        exit(1);
    }

    FILE *fp2 = fopen(filename2, "r");
    if (fp2 == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename2);
        fclose(fp1);
        exit(1);
    }

    int M1, N1, M2, N2;
    fscanf(fp1, "%d %d", &M1, &N1);
    fscanf(fp2, "%d %d", &M2, &N2);

    if (M1 != M2 || N1 != N2) {
        printf("As matrizes não têm o mesmo tamanho para a soma.\n");
        fclose(fp1);
        fclose(fp2);
        exit(1);
    }

    int matriz1[M1][N1], matriz2[M2][N2], soma[M1][N1];

    for (int i = 0; i < M1; i++) {
        for (int j = 0; j < N1; j++) {
            fscanf(fp1, "%d", &matriz1[i][j]);
            fscanf(fp2, "%d", &matriz2[i][j]);
            soma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    printf("A soma das matrizes é:\n");
    for (int i = 0; i < M1; i++) {
        for (int j = 0; j < N1; j++) {
            printf("%d ", soma[i][j]);
        }
        printf("\n");
    }

    fclose(fp1);
    fclose(fp2);
}

// Função 1216: Operar duas linhas da matriz, guardando na primeira as somas de cada elemento da primeira linha com a respectiva da segunda linha multiplicados por uma constante
void addRows(const char *filename, int linha1, int linha2, int constante) {
    FILE *fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    int M, N;
    fscanf(fp, "%d %d", &M, &N);

    int matriz[M][N];

    // Ler a matriz do arquivo
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d", &matriz[i][j]);
        }
    }

    // Operar as linhas
    for (int j = 0; j < N; j++) {
        matriz[linha1][j] += matriz[linha2][j] * constante;
    }

    // Escrever a matriz de volta no arquivo
    rewind(fp);
    fprintf(fp, "%d %d\n", M, N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(fp, "%d ", matriz[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Função 1217: Operar duas linhas da matriz, guardando na primeira as diferenças de cada elemento da primeira linha com a respectiva da segunda linha multiplicado por uma constante
void subtractRows(const char *filename, int linha1, int linha2, int constante) {
    FILE *fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    int M, N;
    fscanf(fp, "%d %d", &M, &N);

    int matriz[M][N];

    // Ler a matriz do arquivo
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d", &matriz[i][j]);
        }
    }

    // Operar as linhas
    for (int j = 0; j < N; j++) {
        matriz[linha1][j] -= matriz[linha2][j] * constante;
    }

    // Escrever a matriz de volta no arquivo
    rewind(fp);
    fprintf(fp, "%d %d\n", M, N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(fp, "%d ", matriz[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Função 1218: Dizer em qual linha da matriz se encontra certo valor, se houver
int searchRows(const char *filename, int procurado) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    int M, N;
    fscanf(fp, "%d %d", &M, &N);

    int matriz[M][N];

    // Ler a matriz do arquivo
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d", &matriz[i][j]);
        }
    }

    fclose(fp);

    // Procurar o valor na matriz
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] == procurado) {
                return i;
            }
        }
    }

    // Se não encontrou, retorna -1
    return -1;
}

// Função 1219: Dizer em qual coluna da matriz se encontra certo valor, se houver
int searchColumns(const char *filename, int procurado) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    int M, N;
    fscanf(fp, "%d %d", &M, &N);

    int matriz[M][N];

    // Ler a matriz do arquivo
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d", &matriz[i][j]);
        }
    }

    fclose(fp);

    // Procurar o valor na matriz
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            if (matriz[i][j] == procurado) {
                return j;
            }
        }
    }

    // Se não encontrou, retorna -1
    return -1;
}

// Função 1220: Transpor os dados em uma matriz
void transposeMatrix(const char *filename) {
    FILE *fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    int M, N;
    fscanf(fp, "%d %d", &M, &N);

    int matriz[M][N];

    // Ler a matriz do arquivo
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d", &matriz[i][j]);
        }
    }

    // Transpor a matriz
    int transposta[N][M];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    // Escrever a matriz transposta de volta no arquivo
    rewind(fp);
    fprintf(fp, "%d %d\n", N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fprintf(fp, "%d ", transposta[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Função 12E1: Verificar se uma matriz apresenta a característica 1, 5, 9, 13...
bool hasCharacteristicPattern(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    int M, N;
    fscanf(fp, "%d %d", &M, &N);

    int matriz[M][N];

    // Ler a matriz do arquivo
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d", &matriz[i][j]);
        }
    }

    fclose(fp);

    // Verificar se a matriz possui o padrão 1, 5, 9, 13...
    int valorEsperado = 1;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] != valorEsperado) {
                return false;
            }
            valorEsperado += 4;
        }
    }

    return true;
}

// Função 12E2: Montar uma matriz com a característica 16, 12, 8, 4...
void generateCharacteristicMatrix(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    int M = 4, N = 4;
    fprintf(fp, "%d %d\n", M, N);

    int valor = 16;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(fp, "%d ", valor);
            valor -= 4;
        }
        fprintf(fp, "\n");
        valor = 9 - i;
    }

    fclose(fp);
}

int main() {
    // Inicializar o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Testando as funções
    int M = 3, N = 4;
    int inferior = 1, superior = 100;

    // 1211: Gerar matriz aleatória e gravar em arquivo
    generateRandomMatrix(M, N, inferior, superior);

    // 1212: Escalar uma matriz
    scalarMatrix("DADOS.TXT", 3);

    // 1213: Verificar se uma matriz é a identidade
    if (isIdentityMatrix("DADOS.TXT")) {
        printf("A matriz é a identidade.\n");
    } else {
        printf("A matriz não é a identidade.\n");
    }

    // 1214: Testar a igualdade de duas matrizes
    if (isEqualMatrix("DADOS1.TXT", "DADOS2.TXT")) {
        printf("As matrizes são iguais.\n");
    } else {
        printf("As matrizes são diferentes.\n");
    }

    // 1215: Somar duas matrizes
    addMatrices("DADOS1.TXT", "DADOS2.TXT");

    // 1216: Operar duas linhas da matriz (adicionar)
    addRows("DADOS.TXT", 0, 1, -1);

    // 1217: Operar duas linhas da matriz (subtrair)
    subtractRows("DADOS.TXT", 0, 1, 2);

    // 1218: Procurar valor em uma linha da matriz
    int linhaEncontrada = searchRows("DADOS.TXT", 10);
    if (linhaEncontrada != -1) {
        printf("O valor foi encontrado na linha %d.\n", linhaEncontrada);
    } else {
        printf("O valor não foi encontrado na matriz.\n");
    }

    // 1219: Procurar valor em uma coluna da matriz
    int colunaEncontrada = searchColumns("DADOS.TXT", 5);
    if (colunaEncontrada != -1) {
        printf("O valor foi encontrado na coluna %d.\n", colunaEncontrada);
    } else {
        printf("O valor não foi encontrado na matriz.\n");
    }

    // 1220: Transpor a matriz
    transposeMatrix("DADOS.TXT");

    // 12E1: Verificar padrão característico na matriz
    if (hasCharacteristicPattern("DADOS.TXT")) {
        printf("A matriz apresenta o padrão característico.\n");
    } else {
        printf("A matriz não apresenta o padrão característico.\n");
    }

    // 12E2: Gerar matriz com característica específica
    generateCharacteristicMatrix("CARACTERISTICA.TXT");

    return 0;
}

