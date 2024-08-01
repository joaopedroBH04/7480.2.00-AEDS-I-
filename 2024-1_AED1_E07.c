#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// Jo�o Pedro Costa Amaral - Matr�cula: 853488

// Fun��o 0711: Gravar m�ltiplos de 4, pares, em ordem crescente
void gravar_multiplos_4_pares_crescente(int n) {
    FILE *fp;
    fp = fopen("RESULTADO01.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo RESULTADO01.TXT\n");
        return;
    }

    int valor = 4;
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", valor);
        valor += 4;
    }

    fclose(fp);
}

// Fun��o 0712: Gravar m�ltiplos de 5, �mpares, em ordem decrescente encerrando em 25
void gravar_multiplos_5_impares_decrescente(int n) {
    FILE *fp;
    fp = fopen("RESULTADO02.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo RESULTADO02.TXT\n");
        return;
    }

    int valor = 65; // Come�a em 65 para n = 5
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", valor);
        valor -= 10;
    }

    fclose(fp);
}

// Fun��o 0713: Gravar valores da sequ�ncia: 1, 5, 25, 125, 625, ...
void gravar_sequencia_potencias(int n) {
    FILE *fp;
    fp = fopen("RESULTADO03.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo RESULTADO03.TXT\n");
        return;
    }

    int valor = 1;
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", valor);
        valor *= 5;
    }

    fclose(fp);
}

// Fun��o 0714: Gravar inversos dos valores da sequ�ncia: 1/625, 1/125, 1/25, 1/5, 1
void gravar_inversos_sequencia_potencias(int n) {
    FILE *fp;
    fp = fopen("RESULTADO04.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo RESULTADO04.TXT\n");
        return;
    }

    double valor = 625.0;
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%.5f\n", 1.0 / valor);
        valor /= 5.0;
    }

    fclose(fp);
}

// Fun��o 0715: Gravar valores da sequ�ncia: 1, 1/x^3, 1/x^5, 1/x^7, ...
void gravar_sequencia_potencias_x(int n, double x) {
    FILE *fp;
    fp = fopen("RESULTADO05.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo RESULTADO05.TXT\n");
        return;
    }

    double valor = 1.0;
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%.5f\n", valor);
        valor *= 1.0 / pow(x, 2 * i + 1);
    }

    fclose(fp);
}

// Fun��o 0716: Somar os primeiros n valores gravados no arquivo do exerc�cio 0715
double somar_valores_arquivo(int n) {
    FILE *fp;
    fp = fopen("RESULTADO05.TXT", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo RESULTADO05.TXT\n");
        return 0.0;
    }

    double soma = 0.0, valor;
    for (int i = 0; i < n; i++) {
        if (fscanf(fp, "%lf", &valor) != 1) {
            printf("Erro ao ler o arquivo RESULTADO05.TXT\n");
            fclose(fp);
            return soma;
        }
        soma += valor;
    }

    fclose(fp);
    return soma;
}

// Fun��o Exemplo 0717: Somar os inversos das pot�ncias dos primeiros n valores gravados no arquivo do exerc�cio 0714
double somar_inversos_arquivo(int n) {
    FILE *fp;
    fp = fopen("RESULTADO04.TXT", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo RESULTADO04.TXT\n");
        return 0.0;
    }

    double soma = 0.0, valor;
    for (int i = 0; i < n; i++) {
        if (fscanf(fp, "%lf", &valor) != 1) {
            printf("Erro ao ler o arquivo RESULTADO04.TXT\n");
            fclose(fp);
            return soma;
        }
        soma += valor;
    }

    fclose(fp);
    return soma;
}

// Fun��o 0718: Gravar os primeiros termos pares da s�rie de Fibonacci
void gravar_termos_pares_fibonacci(int n) {
    FILE *fp;
    fp = fopen("RESULTADO08.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo RESULTADO08.TXT\n");
        return;
    }

    int a = 1, b = 2, c;
    fprintf(fp, "%d\n", b); // O primeiro termo par � 2

    for (int i = 1; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
        if (b % 2 == 0)
            fprintf(fp, "%d\n", b);
    }

    fclose(fp);
}

// Fun��o 0719: Contar mai�sculas em uma cadeia de caracteres de um arquivo texto
void contar_maiusculas_arquivo(const char *nome_arquivo) {
    FILE *fp;
    fp = fopen(nome_arquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return;
    }

    FILE *out_fp;
    out_fp = fopen("RESULTADO09.TXT", "w");
    if (out_fp == NULL) {
        printf("Erro ao abrir o arquivo RESULTADO09.TXT\n");
        fclose(fp);
        return;
    }

    char c;
    int count = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (isupper(c))
            count++;
    }

    fprintf(out_fp, "Mai�sculas no arquivo %s: %d\n", nome_arquivo, count);

    fclose(fp);
    fclose(out_fp);
}

// Fun��o 0720: Contar d�gitos maiores ou iguais a 5 em uma cadeia de caracteres
void contar_digitos_maiores_igual_5_arquivo(const char *nome_arquivo) {
    FILE *fp;
    fp = fopen(nome_arquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return;
    }

    FILE *out_fp;
    out_fp = fopen("RESULTADO10.TXT", "w");
    if (out_fp == NULL) {
        printf("Erro ao abrir o arquivo RESULTADO10.TXT\n");
        fclose(fp);
        return;
    }

    char c;
    int count = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (isdigit(c) && c >= '5')
            count++;
    }

    fprintf(out_fp, "D�gitos >= 5 no arquivo %s: %d\n", nome_arquivo, count);

    fclose(fp);
    fclose(out_fp);
}

// Fun��o Extra 07E1: Gravar divisores �mpares de um n�mero em ordem decrescente
void gravar_divisores_impares(int numero) {
    FILE *fp;
    fp = fopen("RESULTADO_E1.TXT", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo RESULTADO_E1.TXT\n");
        return;
    }

    for (int i = numero; i >= 1; i--) {
        if (numero % i == 0 && i % 2 != 0) {
            fprintf(fp, "%d\n", i);
        }
    }

    fclose(fp);
}

// Fun��o Extra 07E2: Contar palavras que come�am com 'c' ou 'C' em um arquivo de texto
void contar_palavras_c_arquivo(const char *nome_arquivo) {
    FILE *fp;
    fp = fopen(nome_arquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return;
    }

    FILE *out_fp;
    out_fp = fopen("RESULTADO_E2.TXT", "w");
    if (out_fp == NULL) {
        printf("Erro ao abrir o arquivo RESULTADO_E2.TXT\n");
        fclose(fp);

