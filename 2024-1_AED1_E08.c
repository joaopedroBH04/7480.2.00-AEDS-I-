#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Jo�o Pedro Costa Amaral - Matr�cula: 853488

// Fun��o 0811: Ler tamanho e elementos de um arranjo de inteiros (positivos e pares)
void ler_arranjo_positivo_par(int *arr, int tamanho) {
    printf("Digite os elementos do arranjo (valores positivos e pares):\n");
    for (int i = 0; i < tamanho; i++) {
        do {
            printf("Elemento %d: ", i + 1);
            scanf("%d", &arr[i]);
        } while (arr[i] <= 0 || arr[i] % 2 != 0); // Garante valores positivos e pares
    }
}

// Fun��o 0812: Ler arranjo de inteiros positivos de um arquivo
void ler_arranjo_arquivo_positivo(int *arr, int tamanho, const char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return;
    }

    // Ler tamanho do arranjo
    fscanf(fp, "%d", &tamanho);

    // Ler elementos do arranjo, ignorando negativos e �mpares
    for (int i = 0; i < tamanho; i++) {
        fscanf(fp, "%d", &arr[i]);
        if (arr[i] <= 0 || arr[i] % 2 != 0)
            arr[i] = 0; // Marca como zero para descarte posterior
    }

    fclose(fp);

    // Gravar arranjo v�lido em arquivo
    fp = fopen("RESULTADO02.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo RESULTADO02.TXT\n");
        return;
    }

    fprintf(fp, "%d\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] != 0)
            fprintf(fp, "%d\n", arr[i]);
    }

    fclose(fp);
}

// Fun��o 0813: Gerar valores inteiros aleat�rios dentro de um intervalo e grav�-los em arquivo
void gerar_valores_aleatorios(int inferior, int superior, int quantidade) {
    FILE *fp = fopen("DADOS.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo DADOS.TXT\n");
        return;
    }

    srand(time(NULL)); // Inicializa o gerador de n�meros aleat�rios com o tempo atual

    fprintf(fp, "%d\n", quantidade);
    for (int i = 0; i < quantidade; i++) {
        int valor = rand() % (superior - inferior + 1) + inferior;
        fprintf(fp, "%d\n", valor);
    }

    fclose(fp);
}

// Fun��o 0814: Procurar o menor valor �mpar em um arranjo de um arquivo
int achar_menor_impar_arquivo(const char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return -1;
    }

    int tamanho, menor = -1;
    fscanf(fp, "%d", &tamanho);

    for (int i = 0; i < tamanho; i++) {
        int valor;
        fscanf(fp, "%d", &valor);
        if (valor % 2 != 0 && (menor == -1 || valor < menor))
            menor = valor;
    }

    fclose(fp);
    return menor;
}

// Fun��o 0815: Procurar o maior valor �mpar em um arranjo de um arquivo
int achar_maior_impar_arquivo(const char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return -1;
    }

    int tamanho, maior = -1;
    fscanf(fp, "%d", &tamanho);

    for (int i = 0; i < tamanho; i++) {
        int valor;
        fscanf(fp, "%d", &valor);
        if (valor % 2 != 0 && valor > maior)
            maior = valor;
    }

    fclose(fp);
    return maior;
}

// Fun��o 0816: Determinar a m�dia dos valores de um arranjo e separ�-los em dois arquivos
void separar_por_media(const char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return;
    }

    int tamanho;
    fscanf(fp, "%d", &tamanho);

    int *arr = malloc(tamanho * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar mem�ria para o arranjo\n");
        fclose(fp);
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    // Calcular m�dia
    double media = 0;
    for (int i = 0; i < tamanho; i++) {
        media += arr[i];
    }
    media /= tamanho;

    // Separar em dois arquivos
    fp = fopen("MENOR_IGUAL_MEDIA.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo MENOR_IGUAL_MEDIA.TXT\n");
        free(arr);
        return;
    }

    FILE *fp2 = fopen("MAIOR_MEDIA.TXT", "w");
    if (fp2 == NULL) {
        printf("Erro ao abrir o arquivo MAIOR_MEDIA.TXT\n");
        free(arr);
        fclose(fp);
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        if (arr[i] <= media) {
            fprintf(fp, "%d\n", arr[i]);
        } else {
            fprintf(fp2, "%d\n", arr[i]);
        }
    }

    fclose(fp);
    fclose(fp2);
    free(arr);
}

// Fun��o 0817: Verificar se um arranjo est� ordenado em ordem decrescente
int verificar_ordem_decrescente(int *arr, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            return 0; // N�o est� ordenado decrescente
        }
    }
    return 1; // Est� ordenado decrescente
}

// Fun��o 0818: Procurar por um valor em um arranjo a partir de uma posi��o inicial
int procurar_valor(int procurado, int posicao_inicial, int tamanho, int *arr) {
    for (int i = posicao_inicial; i < tamanho; i++) {
        if (arr[i] == procurado) {
            return 1; // Valor encontrado
        }
    }
    return 0; // Valor n�o encontrado
}

// Fun��o 0819: Procurar por um valor em um arranjo e retornar a posi��o onde ele se encontra
int procurar_posicao_valor(int procurado, int posicao_inicial, int tamanho, int *arr) {
    for (int i = posicao_inicial; i < tamanho; i++) {
        if (arr[i] == procurado) {
            return i; // Posi��o onde o valor foi encontrado
        }
    }
    return -1; // Valor n�o encontrado
}

// Fun��o 0820: Contar quantas vezes um valor aparece em um arranjo a partir de uma posi��o inicial
int contar_ocorrencias_valor(int procurado, int posicao_inicial, int tamanho, int *arr) {
    int contador = 0;
    for (int i = posicao_inicial; i < tamanho; i++) {
        if (arr[i] == procurado) {
            contador++;
        }
    }
    return contador;
}

// Fun��o Extra 08E1: Calcular e gravar os divisores �mpares de um n�mero
void calcular_divisores_impares(int numero) {
    FILE *fp = fopen("DIVISORES.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo DIVISORES.TXT\n");
        return;
    }

    int *divisores = malloc(numero * sizeof(int));
    if (divisores == NULL) {
        printf("Erro ao alocar mem�ria para o arranjo de divisores\n");
        fclose(fp);
        return;
    }

    int j = 0;
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0 && i % 2 != 0) {
            divisores[j++] = i;
        }
    }

    fprintf(fp, "Quantidade de divisores �mpares de %d: %d\n", numero, j);
