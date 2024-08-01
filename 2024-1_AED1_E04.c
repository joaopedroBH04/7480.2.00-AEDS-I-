#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Jo�o Pedro Costa Amaral - Matr�cula: 853488

// Fun��o 0411: Contar valores dentro e fora de um intervalo fechado
void contar_valores_intervalo(float a, float b, int n, float valores[]) {
    int dentro = 0, fora = 0;
    for (int i = 0; i < n; i++) {
        if (valores[i] >= a && valores[i] <= b) {
            dentro++;
        } else {
            fora++;
        }
    }
    printf("Valores dentro do intervalo: %d\n", dentro);
    printf("Valores fora do intervalo: %d\n", fora);
}

// Fun��o auxiliar para verificar se um caractere � letra mai�scula maior que 'L'
int e_maiuscula_maior_que_L(char c) {
    return (isupper(c) && c > 'L');
}

// Fun��o 0412: Contar letras mai�sculas maiores que 'L'
void contar_maiusculas_maiores_que_L(char *sequencia) {
    int count = 0;
    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (e_maiuscula_maior_que_L(sequencia[i])) {
            count++;
        }
    }
    printf("Total de letras mai�sculas maiores que 'L': %d\n", count);
}

// Fun��o 0413: Contar e mostrar letras mai�sculas maiores que 'L' por uma fun��o
int contar_maiusculas_maiores_que_L_funcao(char *sequencia) {
    int count = 0;
    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (e_maiuscula_maior_que_L(sequencia[i])) {
            count++;
        }
    }
    return count;
}

// Fun��o 0414: Mostrar letras mai�sculas maiores que 'L' separadas por uma fun��o
void mostrar_maiusculas_maiores_que_L(char *sequencia) {
    printf("Letras mai�sculas maiores que 'L': ");
    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (e_maiuscula_maior_que_L(sequencia[i])) {
            printf("%c ", sequencia[i]);
        }
    }
    printf("\n");
}

// Fun��o auxiliar para verificar se uma letra � menor que 'L' ou 'l'
int e_letra_menor_que_Ll(char c) {
    return ((islower(c) && c < 'l') || (isupper(c) && c < 'L'));
}

// Fun��o 0415: Contar letras menores que 'L' e 'l' por uma fun��o
int contar_letras_menores_que_Ll(char *sequencia) {
    int count = 0;
    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (e_letra_menor_que_Ll(sequencia[i])) {
            count++;
        }
    }
    return count;
}

// Fun��o 0416: Mostrar letras menores que 'L' e 'l' separadas por uma fun��o
void mostrar_letras_menores_que_Ll(char *sequencia) {
    printf("Letras menores que 'L' e 'l': ");
    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (e_letra_menor_que_Ll(sequencia[i])) {
            printf("%c ", sequencia[i]);
        }
    }
    printf("\n");
}

// Fun��o 0417: Contar d�gitos pares em uma cadeia de caracteres
int contar_digitos_pares(char *sequencia) {
    int count = 0;
    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (isdigit(sequencia[i]) && (sequencia[i] - '0') % 2 == 0) {
            count++;
        }
    }
    return count;
}

// Fun��o 0418: Mostrar s�mbolos n�o alfanum�ricos em uma cadeia de caracteres
void mostrar_nao_alfanumericos(char *sequencia) {
    printf("S�mbolos n�o alfanum�ricos: ");
    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (!isalnum(sequencia[i])) {
            printf("%c ", sequencia[i]);
        }
    }
    printf("\n");
}

// Fun��o 0419: Mostrar s�mbolos alfanum�ricos em uma cadeia de caracteres
void mostrar_alfanumericos(char *sequencia) {
    printf("S�mbolos alfanum�ricos: ");
    for (int i = 0; sequencia[i] != '\0'; i++) {
        if (isalnum(sequencia[i])) {
            printf("%c ", sequencia[i]);
        }
    }
    printf("\n");
}

// Fun��o 0420: Contar s�mbolos alfanum�ricos em v�rias palavras
int contar_alfanumericos_palavras(int n, char palavras[][100]) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; palavras[i][j] != '\0'; j++) {
            if (isalnum(palavras[i][j])) {
                count++;
            }
        }
        printf("Total de s�mbolos alfanum�ricos na palavra %d: %d\n", i + 1, count);
        total += count;
    }
    return total;
}

// Fun��o 04E1: Contar s�mbolos alfanum�ricos, incluindo espa�os em branco, em v�rias palavras
int contar_alfanumericos_espacos_palavras(int n, char palavras[][100]) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; palavras[i][j] != '\0'; j++) {
            if (isalnum(palavras[i][j]) || palavras[i][j] == ' ') {
                count++;
            }
        }
        printf("Total de s�mbolos alfanum�ricos e espa�os na palavra %d: %d\n", i + 1, count);
        total += count;
    }
    return total;
}

// Fun��o 04E2: Calcular qual das duas sequ�ncias possui a menor quantidade de d�gitos
char* menor_quantidade_digitos(char *seq1, char *seq2) {
    int count1 = 0, count2 = 0;
    for (int i = 0; seq1[i] != '\0'; i++) {
        if (isdigit(seq1[i])) {
            count1++;
        }
    }
    for (int i = 0; seq2[i] != '\0'; i++) {
        if (isdigit(seq2[i])) {
            count2++;
        }
    }
    printf("Quantidade de d�gitos na sequ�ncia 1: %d\n", count1);
    printf("Quantidade de d�gitos na sequ�ncia 2: %d\n", count2);
    return (count1 < count2) ? seq1 : seq2;
}

int main() {
    // Vari�veis para armazenar entradas e resultados
    char palavra[100];
    char sequencia[100];
    char palavras[10][100];
    float a, b, valores[100];
    int n, valores_int[100];
    float valores_float[100];

    // 0411: Contar valores dentro e fora de um intervalo fechado
    printf("Digite os limites do intervalo [a:b]: ");
    scanf("%f %f", &a, &b);
    printf("Digite a quantidade de valores reais a serem testados: ");
    scanf("%d", &n);
    printf("Digite os valores reais: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &valores[i]);
    }
    printf("Fun��o 0411:\n");
    contar_valores_intervalo(a, b, n, valores);

    // 0412: Contar letras mai�sculas maiores que 'L'
    printf("Digite uma sequ�ncia de caracteres: ");
    scanf("%s", sequencia);
    printf("Fun��o 0412:\n");
    contar_maiusculas_maiores_que_L(sequencia);

    // 0413: Contar letras mai�sculas maiores que 'L' por uma fun��o
    printf("Fun��o 0413:\n");
    int count = contar_maiusculas_maiores_que_L_funcao(sequencia);
    printf("Total de letras mai�sculas maiores que 'L' (via fun��o): %d\n", count);

    // 0414: Mostrar letras mai�sculas maiores que 'L' separadas por uma fun��o
    printf("Fun��o 0414:\n");
    mostrar_maiusculas_maiores_que_L(sequencia);

    // 0415: Contar letras menores que 'L' e 'l' por uma fun��o
    printf("Fun��o 0415:\n");
    count = contar_letras_menores_que_Ll(sequencia);
    printf("Total de letras menores que 'L' e 'l': %d\n", count);

    // 0416: Mostrar letras menores que 'L' e 'l' separadas por uma fun��o
    printf("Fun��o 0416:\n");
    mostrar_letras_menores_que_Ll(sequencia);

    // 0417: Contar d�gitos pares em uma cadeia de caracteres
    printf("Fun��o 0417:\n");
    count = contar_digitos_pares(sequencia);
    printf("Total de d�gitos pares: %d\n", count);

    // 0418: Mostrar s�mbolos n�o alfanum�ricos em uma cadeia de caracteres
    printf("Fun��o 0418:\n");
    mostrar_nao_alfanumericos(sequencia);

    // 0419: Mostrar s�mbolos alfanum�ricos em uma cadeia de caracteres
    printf("Fun��o 0419:\n");
    mostrar_alfanumericos(sequencia);

    // 0420: Contar s�mbolos alfanum�ricos em v�rias palavras
    printf("Digite a quantidade de palavras: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Digite a palavra %d: ", i + 1);
        scanf("%s", palavras[i]);
    }
    printf("Fun��o 0420:\n");
    int total = contar_alfanumericos_palavras(n, palavras);
    printf("Total de s�mbolos alfanum�ricos em todas as palavras: %d\n", total);

    // 04E1: Contar s�mbolos alfanum�ricos, incluindo espa�os em branco, em v�rias palavras
    printf("Fun��o 04E1:\n");
    total = contar_alfanumericos_espacos_palavras(n, palavras);
    printf("Total de s�mbolos alfanum�ricos e espa�os em todas as palavras: %d\n", total);

    // 04E2: Calcular qual das duas sequ�ncias possui a menor quantidade de d�gitos
    char seq1[100], seq2[100];
    printf("Digite a primeira sequ�ncia: ");
    scanf("%s", seq1);
    printf("Digite a segunda sequ�ncia: ");
    scanf("%s", seq2);
    printf("Fun��o 04E2:\n");
    char *menor = menor_quantidade_digitos(seq1, seq2);
    printf("A sequ�ncia com menos d�gitos �: %s\n", menor);

    return 0;
}
