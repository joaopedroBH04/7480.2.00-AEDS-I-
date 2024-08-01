#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Jo�o Pedro Costa Amaral - Matr�cula: 853488

// Fun��o 0311: Mostrar letras mai�sculas de uma palavra
void mostrar_maiusculas(char *palavra) {
    printf("Letras mai�sculas: ");
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (isupper(palavra[i])) {
            printf("%c ", palavra[i]);
        }
    }
    printf("\n");
}

// Fun��o 0312: Contar e mostrar letras mai�sculas de uma palavra
void contar_mostrar_maiusculas(char *palavra) {
    int count = 0;
    printf("Letras mai�sculas: ");
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (isupper(palavra[i])) {
            printf("%c ", palavra[i]);
            count++;
        }
    }
    printf("\nTotal de letras mai�sculas: %d\n", count);
}

// Fun��o 0313: Contar e mostrar letras mai�sculas de uma palavra (do fim para o in�cio)
void contar_mostrar_maiusculas_reverso(char *palavra) {
    int count = 0;
    int len = strlen(palavra);
    printf("Letras mai�sculas (reverso): ");
    for (int i = len - 1; i >= 0; i--) {
        if (isupper(palavra[i])) {
            printf("%c ", palavra[i]);
            count++;
        }
    }
    printf("\nTotal de letras mai�sculas: %d\n", count);
}

// Fun��o 0314: Contar e mostrar letras (mai�sculas ou min�sculas) de uma cadeia de caracteres
void contar_mostrar_letras(char *cadeia) {
    int count = 0;
    printf("Letras encontradas: ");
    for (int i = 0; cadeia[i] != '\0'; i++) {
        if (isalpha(cadeia[i])) {
            printf("%c ", cadeia[i]);
            count++;
        }
    }
    printf("\nTotal de letras: %d\n", count);
}

// Fun��o 0315: Contar e mostrar d�gitos de uma cadeia de caracteres (do fim para o in�cio)
void contar_mostrar_digitos_reverso(char *cadeia) {
    int count = 0;
    int len = strlen(cadeia);
    printf("D�gitos (reverso): ");
    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(cadeia[i])) {
            printf("%c ", cadeia[i]);
            count++;
        }
    }
    printf("\nTotal de d�gitos: %d\n", count);
}

// Fun��o 0316: Contar e mostrar tudo que n�o for d�gito e tamb�m n�o for letra
void contar_mostrar_nao_alnum(char *cadeia) {
    int count = 0;
    printf("S�mbolos n�o alfanum�ricos: ");
    for (int i = 0; cadeia[i] != '\0'; i++) {
        if (!isalnum(cadeia[i])) {
            printf("%c ", cadeia[i]);
            count++;
        }
    }
    printf("\nTotal de s�mbolos n�o alfanum�ricos: %d\n", count);
}

// Fun��o 0317: Contar e mostrar valores m�ltiplos de 6 em um intervalo
void contar_mostrar_multiplos_6(int a, int b, int n, int valores[]) {
    int count = 0;
    printf("M�ltiplos de 6 no intervalo [%d:%d]: ", a, b);
    for (int i = 0; i < n; i++) {
        if (valores[i] % 6 == 0 && valores[i] >= a && valores[i] <= b) {
            printf("%d ", valores[i]);
            count++;
        }
    }
    printf("\nTotal de m�ltiplos de 6 no intervalo: %d\n", count);
}

// Fun��o 0318: Contar e mostrar valores m�ltiplos de 4 e n�o m�ltiplos de 5 em um intervalo
void contar_mostrar_multiplos_4_nao_5(int a, int b, int n, int valores[]) {
    int count = 0;
    printf("M�ltiplos de 4 e n�o de 5 no intervalo [%d:%d]: ", a, b);
    for (int i = 0; i < n; i++) {
        if (valores[i] % 4 == 0 && valores[i] % 5 != 0 && valores[i] >= a && valores[i] <= b) {
            printf("%d ", valores[i]);
            count++;
        }
    }
    printf("\nTotal de m�ltiplos de 4 e n�o de 5 no intervalo: %d\n", count);
}

// Fun��o 0319: Contar e mostrar valores reais com partes inteiras pares em um intervalo aberto
void contar_mostrar_partes_inteiras_pares(float a, float b, int n, float valores[]) {
    int count = 0;
    printf("Valores com partes inteiras pares no intervalo (%.2f:%.2f): ", a, b);
    for (int i = 0; i < n; i++) {
        int parte_inteira = (int)valores[i];
        if (valores[i] > a && valores[i] < b && parte_inteira % 2 == 0) {
            printf("%.2f ", valores[i]);
            count++;
        }
    }
    printf("\nTotal de valores com partes inteiras pares no intervalo: %d\n", count);
}

// Fun��o 0320: Contar e mostrar valores reais com partes fracion�rias fora de um intervalo
void contar_mostrar_partes_fracionarias_fora_intervalo(float a, float b, int n, float valores[]) {
    int count = 0;
    printf("Valores com partes fracion�rias fora do intervalo (%.2f:%.2f): ", a, b);
    for (int i = 0; i < n; i++) {
        float parte_fracionaria = valores[i] - (int)valores[i];
        if (parte_fracionaria <= a || parte_fracionaria >= b) {
            printf("%.2f ", valores[i]);
            count++;
        }
    }
    printf("\nTotal de valores com partes fracion�rias fora do intervalo: %d\n", count);
}

// Fun��o 03E1: Separar e mostrar todos os s�mbolos n�o alfanum�ricos de uma linha
void mostrar_simbolos_nao_alfanumericos(char *linha) {
    printf("S�mbolos n�o alfanum�ricos: ");
    for (int i = 0; linha[i] != '\0'; i++) {
        if (!isalnum(linha[i])) {
            printf("%c ", linha[i]);
        }
    }
    printf("\n");
}

// Fun��o 03E2: Verificar se uma sequ�ncia cont�m apenas letras
int contem_apenas_letras(char *sequencia) {
    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (!isalpha(sequencia[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char palavra[100];
    char cadeia[100];
    char linha[100];
    int a, b, n;
    int valores[100];
    float fa, fb;
    float fvalores[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    printf("Fun��o 0311:\n");
    mostrar_maiusculas(palavra);

    printf("Fun��o 0312:\n");
    contar_mostrar_maiusculas(palavra);

    printf("Fun��o 0313:\n");
    contar_mostrar_maiusculas_reverso(palavra);

    printf("Digite uma cadeia de caracteres: ");
    scanf("%s", cadeia);

    printf("Fun��o 0314:\n");
    contar_mostrar_letras(cadeia);

    printf("Fun��o 0315:\n");
    contar_mostrar_digitos_reverso(cadeia);

    printf("Fun��o 0316:\n");
    contar_mostrar_nao_alnum(cadeia);

    printf("Digite os limites do intervalo [a:b] e a quantidade de valores a serem testados:\n");
    scanf("%d %d %d", &a, &b, &n);
    printf("Digite os valores inteiros a serem testados:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &valores[i]);
    }

    printf("Fun��o 0317:\n");
    contar_mostrar_multiplos_6(a, b, n, valores);

    printf("Fun��o 0318:\n");
    contar_mostrar_multiplos_4_nao_5(a, b, n, valores);

    printf("Digite os limites do intervalo (a:b) e a quantidade de valores reais a serem testados:\n");
    scanf("%f %f %d", &fa, &fb, &n);
    printf("Digite os valores reais a serem testados:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &fvalores[i]);
    }

    printf("Fun��o 0319:\n");
    contar_mostrar_partes_inteiras_pares(fa, fb, n, fvalores);

    printf("Digite os limites do intervalo aberto para partes fracion�rias (a:b):\n");
    scanf("%f %f", &fa, &fb);

    printf("Fun��o 0320:\n");
    contar_mostrar_partes_fracionarias_fora_intervalo(fa, fb, n, fvalores);

    getchar(); // Limpar o buffer do teclado
    printf("Digite uma linha de texto:\n");
    gets(linha); // Use gets() para ler uma linha completa

    printf("Fun��o 03E1:\n");
    mostrar_simbolos_nao_alfanumericos(linha);

    printf("Digite uma sequ�ncia de caracteres:\n");
    scanf("%s", cadeia);

    printf("Fun��o 03E2:\n");
    if (contem_apenas_letras(cadeia)) {
        printf("A sequ�ncia cont�m apenas letras.\n");
    } else {
        printf("A sequ�ncia cont�m outros caracteres al�m de letras.\n");
    }

    return 0;
}
