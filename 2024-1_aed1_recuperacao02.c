#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fun��o para determinar se os valores no arranjo est�o em ordem decrescente
bool isDecrescente(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Fun��o para ordenar arranjo em ordem decrescente usando Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Troca os elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fun��o para inverter a ordem dos elementos no arranjo
void inverterArranjo(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        // Troca elementos do come�o com o final
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

// Fun��o para encontrar a mediana do arranjo
double arranjo_mediana(int arr[], int n) {
    // Ordena o arranjo para calcular a mediana
    bubbleSort(arr, n);

    // Se o tamanho do arranjo for �mpar, retorna o elemento central
    if (n % 2 != 0) {
        return arr[n / 2];
    }
    // Se o tamanho do arranjo for par, retorna a m�dia dos dois elementos centrais
    else {
        int mid1 = arr[n / 2 - 1];
        int mid2 = arr[n / 2];
        return (double)(mid1 + mid2) / 2.0;
    }
}

// Fun��o para encontrar e mostrar a moda do arranjo
void arranjo_moda(int arr[], int n) {
    int freq[n];
    for (int i = 0; i < n; i++) {
        freq[i] = -1;
    }

    // Conta as ocorr�ncias de cada elemento
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = 0; // Marca o elemento como visitado
            }
        }
        if (freq[i] != 0) {
            freq[i] = count;
        }
    }

    // Encontra o elemento com maior frequ�ncia
    int moda = arr[0];
    int maxFreq = freq[0];
    for (int i = 1; i < n; i++) {
        if (freq[i] > maxFreq) {
            moda = arr[i];
            maxFreq = freq[i];
        }
    }

    printf("Moda: %d\n", moda);
}

// Fun��o para encontrar e gravar os elementos comuns em dois arranjos em um arquivo
void arranjo_filtrar(int arr1[], int arr2[], int n1, int n2) {
    int arr3[n1 > n2 ? n1 : n2]; // Arranjo para armazenar elementos comuns
    int idx = 0;

    // Percorre arr1 e verifica se cada elemento est� presente em arr2
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                // Verifica se o elemento j� foi adicionado ao arr3
                bool alreadyExists = false;
                for (int k = 0; k < idx; k++) {
                    if (arr1[i] == arr3[k]) {
                        alreadyExists = true;
                        break;
                    }
                }
                if (!alreadyExists) {
                    arr3[idx++] = arr1[i];
                }
                break;
            }
        }
    }

    // Grava arr3 em um arquivo FILTRADOS.TXT
    FILE *fp = fopen("FILTRADOS.TXT", "w");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo FILTRADOS.TXT");
        exit(EXIT_FAILURE);
    }

    // Escreve a quantidade de dados �nicos na primeira linha
    fprintf(fp, "%d\n", idx);

    // Escreve os elementos �nicos no arquivo
    for (int i = 0; i < idx; i++) {
        fprintf(fp, "%d ", arr3[i]);
    }

    fclose(fp);
}

// Fun��o para converter um arranjo de bin�rios em decimal
int arranjo_paraDecimal(int arr[], int n) {
    int decimal = 0;
    int potencia = 1; // Inicia com 2^0

    for (int i = n - 1; i >= 0; i--) {
        decimal += arr[i] * potencia;
        potencia *= 2;
    }

    return decimal;
}

// Fun��o para montar e gravar uma matriz tridiagonal crescente em um arquivo
void matriz_tridiagonal_crescente(int N) {
    int matriz[N][N];

    // Inicializa a matriz com zeros
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = 0;
        }
    }

    // Preenche a matriz tridiagonal crescente
    int num = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                matriz[i][j] = num++;
            } else if (i == j - 1) {
                matriz[i][j] = num++;
            } else if (i == j + 1) {
                matriz[i][j] = num++;
            }
        }
    }

    // Mostra a matriz
    printf("Matriz Tridiagonal Crescente:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Grava a matriz no arquivo MATRIZ2.TXT
    FILE *fp = fopen("MATRIZ2.TXT", "w");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo MATRIZ2.TXT");
        exit(EXIT_FAILURE);
    }

    // Escreve a quantidade de linhas e colunas da matriz
    fprintf(fp, "%d\n", N);

    // Escreve os elementos da matriz no arquivo
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(fp, "%d ", matriz[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Fun��o para montar e gravar uma matriz tridiagonal secund�ria decrescente em um arquivo
void matriz_tridiagonal_secundaria_decrescente(int N) {
    int matriz[N][N];

    // Inicializa a matriz com zeros
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = 0;
        }
    }

    // Preenche a matriz tridiagonal secund�ria decrescente
    int num = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + j == N - 1) {
                matriz[i][j] = num++;
            } else if (i + j == N - 2) {
                matriz[i][j] = num++;
            } else if (i + j == N) {
                matriz[i][j] = num++;
            }
        }
    }

    // Mostra a matriz
    printf("Matriz Tridiagonal Secund�ria Decrescente:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Grava a matriz no arquivo MATRIZ2.TXT
 FILE *fp = fopen("MATRIZ2.TXT", "w");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo MATRIZ2.TXT");
        exit(EXIT_FAILURE);
    }

    // Escreve a quantidade de linhas e colunas da matriz
    fprintf(fp, "%d\n", N);

    // Escreve os elementos da matriz no arquivo
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(fp, "%d ", matriz[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Fun��o para verificar se uma matriz � uma matriz de pot�ncias por linha
bool matriz_potencias_linha(int matriz[][4], int N) {
    for (int i = 0; i < N; i++) {
        int potencia = 1;
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] != potencia) {
                return false;
            }
            potencia *= (i + 1); // Calcula a pr�xima pot�ncia
        }
    }
    return true;
}

// Fun��o para verificar se uma matriz � uma matriz de pot�ncias por coluna
bool matriz_potencias_coluna(int matriz[][4], int N) {
    for (int j = 0; j < N; j++) {
        int potencia = 1;
        for (int i = 0; i < N; i++) {
            if (matriz[i][j] != potencia) {
                return false;
            }
            potencia *= (j + 1); // Calcula a pr�xima pot�ncia
        }
    }
    return true;
}

// Fun��o para calcular o pre�o m�dio de um produto e indicar os supermercados com pre�os inferiores
void supermercados_precos(int N) {
    char nome_supermercado[50];
    int codigo_supermercado;
    double preco_produto, soma_precos = 0.0;
    int contador_precos_inferiores = 0;
    double preco_medio;

    for (int i = 0; i < N; i++) {
        printf("Digite o nome do supermercado: ");
        scanf("%s", nome_supermercado);

        printf("Digite o c�digo do supermercado: ");
        scanf("%d", &codigo_supermercado);

        printf("Digite o pre�o do produto no supermercado: ");
        scanf("%lf", &preco_produto);

        soma_precos += preco_produto;

        if (preco_produto < preco_medio) {
            contador_precos_inferiores++;
        }
    }

    preco_medio = soma_precos / N;

    printf("\nPre�o m�dio do produto: %.2lf\n", preco_medio);

    if (contador_precos_inferiores >= 2) {
        printf("Pelo menos dois supermercados t�m pre�os inferiores � m�dia.\n");
    } else {
        printf("Menos de dois supermercados t�m pre�os inferiores � m�dia.\n");
    }
}

int main() {
    // Exemplo de uso das fun��es
    int arr1[] = {4, 3, 2, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    // 01.) Determinar se os valores no arranjo est�o em ordem decrescente
    if (!isDecrescente(arr1, n1)) {
        printf("O arranjo n�o est� em ordem decrescente. Ordenando...\n");
        bubbleSort(arr1, n1);
        printf("Arranjo ordenado: ");
        for (int i = 0; i < n1; i++) {
            printf("%d ", arr1[i]);
        }
        printf("\n");

        // Grava no arquivo DECRESCENTE.TXT
        FILE *fp = fopen("DECRESCENTE.TXT", "w");
        if (fp == NULL) {
            perror("Erro ao abrir arquivo DECRESCENTE.TXT");
            exit(EXIT_FAILURE);
        }

        // Escreve a quantidade de elementos na primeira linha
        fprintf(fp, "%d\n", n1);

        // Escreve os elementos ordenados no arquivo
        for (int i = 0; i < n1; i++) {
            fprintf(fp, "%d ", arr1[i]);
        }

        fclose(fp);
    } else {
        printf("O arranjo j� est� em ordem decrescente.\n");
    }

    // 02.) Inverter a ordem dos elementos do arranjo
    int arr2[n1];
    for (int i = 0; i < n1; i++) {
        arr2[i] = arr1[i];
    }
    inverterArranjo(arr2, n1);
    printf("Arranjo invertido: ");
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Grava no arquivo INVERTIDOS.TXT
    FILE *fp_invertidos = fopen("INVERTIDOS.TXT", "w");
    if (fp_invertidos == NULL) {
        perror("Erro ao abrir arquivo INVERTIDOS.TXT");
        exit(EXIT_FAILURE);
    }

    // Escreve a quantidade de elementos na primeira linha
    fprintf(fp_invertidos, "%d\n", n1);

    // Escreve os elementos invertidos no arquivo
    for (int i = 0; i < n1; i++) {
        fprintf(fp_invertidos, "%d ", arr2[i]);
    }

    fclose(fp_invertidos);

    // 03.) Calcular a mediana e mostrar a moda
    int arr3[] = {1, 2, 2, 3, 3, 4};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    double mediana = arranjo_mediana(arr3, n3);
    printf("Mediana do arranjo: %.1lf\n", mediana);

    arranjo_moda(arr3, n3);

    // 04.) Filtrar e mostrar os elementos comuns em dois arranjos
    int arr4[] = {1, 2, 3, 4, 5};
    int arr5[] = {3, 4, 5, 6, 7};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int n5 = sizeof(arr5) / sizeof(arr5[0]);

    arranjo_filtrar(arr4, arr5, n4, n5);

    // 05.) Converter arranjos bin�rios para decimal
    FILE *fp_binarios = fopen("BINARIOS1.TXT", "r");
    if (fp_binarios == NULL) {
        perror("Erro ao abrir arquivo BINARIOS1.TXT");
        exit(EXIT_FAILURE);
    }

    int arr_binarios[100];
    int idx = 0;
    char c;

    // L� os bin�rios do arquivo e converte para um arranjo de inteiros
    while (fscanf(fp_binarios, " %c", &c) == 1) {
        if (c == '0' || c == '1') {
            arr_binarios[idx++] = c - '0'; // Converte caractere para inteiro
        }
    }

    fclose(fp_binarios);

    int decimal = arranjo_paraDecimal(arr_binarios, idx);
    printf("Decimal equivalente: %d\n", decimal);

    // 06.) Criar uma matriz tridiagonal crescente e gravar no arquivo MATRIZ2.TXT
    int N = 4; // Tamanho da matriz quadrada
    matriz_tridiagonal_crescente(N);

    // 07.) Criar uma matriz tridiagonal secund�ria decrescente e gravar no arquivo MATRIZ2.TXT
    matriz_tridiagonal_secundaria_decrescente(N);

    // 08.) Verificar se uma matriz apresenta pot�ncias por linha
    int matriz1[4][4] = {{1, 1, 1, 1},
                         {1, 2, 4, 8},
                         {1, 3, 9, 27},
                         {1, 4, 16, 64}};
    bool potencias_linha = matriz_potencias_linha(matriz1, N);
    if (potencias_linha) {
        printf("A matriz apresenta pot�ncias por linha.\n");
    } else {
        printf("A matriz n�o apresenta pot�ncias por linha.\n");
    }

    // 09.) Verificar se uma matriz apresenta pot�ncias por coluna
    bool potencias_coluna = matriz_potencias_coluna(matriz1, N);
    if (potencias_coluna) {
        printf("A matriz apresenta pot�ncias por coluna.\n");
    } else {
        printf("A matriz n�o apresenta pot�ncias por coluna.\n");
    }

    // 10.) Calcular pre�o m�dio de um produto e indicar supermercados com pre�os inferiores
    int num_supermercados;
    printf("Digite a quantidade de supermercados: ");
    scanf("%d", &num_supermercados);

    supermercados_precos(num_supermercados);

    return 0;
}
