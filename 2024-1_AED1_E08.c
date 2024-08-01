#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// João Pedro Costa Amaral - Matrícula: 853488

// Função 0811: Ler tamanho e elementos de um arranjo de inteiros (positivos e pares)
void ler_arranjo_positivo_par(int *arr, int tamanho) {
    printf("Digite os elementos do arranjo (valores positivos e pares):\n");
    for (int i = 0; i < tamanho; i++) {
        do {
            printf("Elemento %d: ", i + 1);
            scanf("%d", &arr[i]);
        } while (arr[i] <= 0 || arr[i] % 2 != 0); // Garante valores positivos e pares
    }
}

// Função 0812: Ler arranjo de inteiros positivos de um arquivo
void ler_arranjo_arquivo_positivo(int *arr, int tamanho, const char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return;
    }

    // Ler tamanho do arranjo
    fscanf(fp, "%d", &tamanho);

    // Ler elementos do arranjo, ignorando negativos e ímpares
    for (int i = 0; i < tamanho; i++) {
        fscanf(fp, "%d", &arr[i]);
        if (arr[i] <= 0 || arr[i] % 2 != 0)
            arr[i] = 0; // Marca como zero para descarte posterior
    }

    fclose(fp);

    // Gravar arranjo válido em arquivo
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

// Função 0813: Gerar valores inteiros aleatórios dentro de um intervalo e gravá-los em arquivo
void gerar_valores_aleatorios(int inferior, int superior, int quantidade) {
    FILE *fp = fopen("DADOS.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo DADOS.TXT\n");
        return;
    }

    srand(time(NULL)); // Inicializa o gerador de números aleatórios com o tempo atual

    fprintf(fp, "%d\n", quantidade);
    for (int i = 0; i < quantidade; i++) {
        int valor = rand() % (superior - inferior + 1) + inferior;
        fprintf(fp, "%d\n", valor);
    }

    fclose(fp);
}

// Função 0814: Procurar o menor valor ímpar em um arranjo de um arquivo
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

// Função 0815: Procurar o maior valor ímpar em um arranjo de um arquivo
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

// Função 0816: Determinar a média dos valores de um arranjo e separá-los em dois arquivos
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
        printf("Erro ao alocar memória para o arranjo\n");
        fclose(fp);
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    // Calcular média
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

// Função 0817: Verificar se um arranjo está ordenado em ordem decrescente
int verificar_ordem_decrescente(int *arr, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            return 0; // Não está ordenado decrescente
        }
    }
    return 1; // Está ordenado decrescente
}

// Função 0818: Procurar por um valor em um arranjo a partir de uma posição inicial
int procurar_valor(int procurado, int posicao_inicial, int tamanho, int *arr) {
    for (int i = posicao_inicial; i < tamanho; i++) {
        if (arr[i] == procurado) {
            return 1; // Valor encontrado
        }
    }
    return 0; // Valor não encontrado
}

// Função 0819: Procurar por um valor em um arranjo e retornar a posição onde ele se encontra
int procurar_posicao_valor(int procurado, int posicao_inicial, int tamanho, int *arr) {
    for (int i = posicao_inicial; i < tamanho; i++) {
        if (arr[i] == procurado) {
            return i; // Posição onde o valor foi encontrado
        }
    }
    return -1; // Valor não encontrado
}

// Função 0820: Contar quantas vezes um valor aparece em um arranjo a partir de uma posição inicial
int contar_ocorrencias_valor(int procurado, int posicao_inicial, int tamanho, int *arr) {
    int contador = 0;
    for (int i = posicao_inicial; i < tamanho; i++) {
        if (arr[i] == procurado) {
            contador++;
        }
    }
    return contador;
}

// Função Extra 08E1: Calcular e gravar os divisores ímpares de um número
void calcular_divisores_impares(int numero) {
    FILE *fp = fopen("DIVISORES.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo DIVISORES.TXT\n");
        return;
    }

    int *divisores = malloc(numero * sizeof(int));
    if (divisores == NULL) {
        printf("Erro ao alocar memória para o arranjo de divisores\n");
        fclose(fp);
        return;
    }

    int j = 0;
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0 && i % 2 != 0) {
            divisores[j++] = i;
        }
    }

    fprintf(fp, "Quantidade de divisores ímpares de %d: %d\n", numero, j);
