#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Jo�o Pedro Costa Amaral - Matr�cula: 853488

// Fun��o 0611: Mostrar m�ltiplos de 6 em ordem crescente
void mostrar_multiplos_6_crescente(int n, int valor) {
    if (n == 0) return;
    printf("%d ", valor);
    mostrar_multiplos_6_crescente(n - 1, valor + 6);
}

// Fun��o 0612: Mostrar m�ltiplos de 6 em ordem decrescente
void mostrar_multiplos_6_decrescente(int n, int valor) {
    if (n == 0) return;
    printf("%d ", valor);
    mostrar_multiplos_6_decrescente(n - 1, valor - 6);
}

// Fun��o 0613: Mostrar sequ�ncia de inversos dos m�ltiplos de 6 em ordem crescente
void mostrar_inversos_multiplos_6_crescente(int n, int valor) {
    if (n == 0) return;
    printf("1/%d ", valor);
    mostrar_inversos_multiplos_6_crescente(n - 1, valor + 6);
}

// Fun��o 0614: Mostrar sequ�ncia de inversos dos m�ltiplos de 6 em ordem decrescente
void mostrar_inversos_multiplos_6_decrescente(int n, int valor) {
    if (n == 0) return;
    printf("1/%d ", valor);
    mostrar_inversos_multiplos_6_decrescente(n - 1, valor - 6);
}

// Fun��o 0615: Calcular a soma dos valores gerados pela adi��o dos primeiros valores pares positivos ao valor 6
int soma_pares_positivos(int n, int valor) {
    if (n == 0) return valor;
    return valor + soma_pares_positivos(n - 1, valor + (n * n));
}

// Fun��o 0616: Calcular a soma dos inversos dos primeiros valores pares positivos m�ltiplos de 6
double soma_inversos_multiplos_6(int n, int valor) {
    if (n == 0) return 0.0;
    return 1.0 / valor + soma_inversos_multiplos_6(n - 1, valor + 6);
}

// Fun��o 0617: Mostrar cada s�mbolo de uma cadeia de caracteres, um por linha
void mostrar_simbolos(char *str) {
    if (*str == '\0') return;
    printf("%c\n", *str);
    mostrar_simbolos(str + 1);
}

// Fun��o 0618: Contar os d�gitos pares em uma cadeia de caracteres
int contar_digitos_pares(char *str) {
    if (*str == '\0') return 0;
    int count = (*str >= '0' && *str <= '9' && (*str - '0') % 2 == 0) ? 1 : 0;
    return count + contar_digitos_pares(str + 1);
}

// Fun��o 0619: Contar as mai�sculas menores que 'L' em uma cadeia de caracteres
int contar_maiusculas_menores_L(char *str) {
    if (*str == '\0') return 0;
    int count = (*str >= 'A' && *str < 'L') ? 1 : 0;
    return count + contar_maiusculas_menores_L(str + 1);
}

// Fun��o 0620: Calcular certo termo par da s�rie de Fibonacci
int fibonacci_par(int n) {
    static int fib_even_index = 0;
    int fibonacci(int n) {
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    int current_fib = fibonacci(fib_even_index);
    if (current_fib % 2 == 0 && n == 1) return current_fib;
    if (current_fib % 2 == 0) n--;
    fib_even_index++;
    return fibonacci_par(n);
}

// Fun��o Extra 06E1: Calcular a fun��o recursiva f(x, n)
double funcao_recursiva(double x, int n) {
    if (n == 0) return 1.0;
    return pow(x, 2 * n + 1) + funcao_recursiva(x, n - 1);
}

// Fun��o Extra 06E2: Calcular o valor de e usando a s�rie fornecida
double calcular_e(int n) {
    double fatorial(int x) {
        if (x == 0) return 1;
        return x * fatorial(x - 1);
    }

    if (n == 0) return 1.0;
    return (2 * n + 1) / fatorial(2 * n) + calcular_e(n - 1);
}

int main() {
    int escolha, n;
    double x;

    do {
        printf("\nSelecione a op��o desejada:\n");
        printf("1. M�ltiplos de 6 em ordem crescente\n");
        printf("2. M�ltiplos de 6 em ordem decrescente\n");
        printf("3. Inversos dos m�ltiplos de 6 em ordem crescente\n");
        printf("4. Inversos dos m�ltiplos de 6 em ordem decrescente\n");
        printf("5. Soma de valores pares positivos\n");
        printf("6. Soma dos inversos de m�ltiplos de 6\n");
        printf("7. Mostrar s�mbolos de uma cadeia de caracteres\n");
        printf("8. Contar d�gitos pares em uma cadeia de caracteres\n");
        printf("9. Contar mai�sculas menores que 'L' em uma cadeia de caracteres\n");
        printf("10. Calcular termo par da s�rie de Fibonacci\n");
        printf("11. Calcular fun��o recursiva f(x, n)\n");
        printf("12. Calcular valor de e usando s�rie fornecida\n");
        printf("0. Sair\n");
        printf("Op��o: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite a quantidade de m�ltiplos de 6: ");
                scanf("%d", &n);
                mostrar_multiplos_6_crescente(n, 6);
                printf("\n");
                break;
            case 2:
                printf("Digite a quantidade de m�ltiplos de 6: ");
                scanf("%d", &n);
                mostrar_multiplos_6_decrescente(n, n * 6);
                printf("\n");
                break;
            case 3:
                printf("Digite a quantidade de inversos de m�ltiplos de 6: ");
                scanf("%d", &n);
                mostrar_inversos_multiplos_6_crescente(n, 1);
                printf("\n");
                break;
            case 4:
                printf("Digite a quantidade de inversos de m�ltiplos de 6: ");
                scanf("%d", &n);
                mostrar_inversos_multiplos_6_decrescente(n, n * 6 - 6);
                printf("\n");
                break;
            case 5:
                printf("Digite a quantidade de valores pares positivos: ");
                scanf("%d", &n);
                printf("Soma: %d\n", soma_pares_positivos(n, 6));
                break;
            case 6:
                printf("Digite a quantidade de inversos de m�ltiplos de 6: ");
                scanf("%d", &n);
                printf("Soma dos inversos: %.5f\n", soma_inversos_multiplos_6(n, 6));
                break;
            case 7:
                {
                    char str[100];
                    printf("Digite a cadeia de caracteres: ");
                    scanf("%s", str);
                    mostrar_simbolos(str);
                }
                break;
            case 8:
                {
                    char str[100];
                    printf("Digite a cadeia de caracteres: ");
                    scanf("%s", str);
                    printf("D�gitos pares: %d\n", contar_digitos_pares(str));
                }
                break;
            case 9:
                {
                    char str[100];
                    printf("Digite a cadeia de caracteres: ");
                    scanf("%s", str);
                    printf("Mai�sculas menores que 'L': %d\n", contar_maiusculas_menores_L(str));
                }
                break;
            case 10:
                printf("Digite o n�mero de termos pares de Fibonacci: ");
                scanf("%d", &n);
                printf("Termo par de Fibonacci: %d\n", fibonacci_par(n));
                break;
            case 11:
                printf("Digite o valor de x: ");
                scanf("%lf", &x);
                printf("Digite a quantidade de termos n: ");
                scanf("%d", &n);
                printf("Resultado de f(x, n): %.5f\n", funcao_recursiva(x, n));
                break;
            case 12:
                printf("Digite a quantidade de termos n: ");
                scanf("%d", &n);
                printf("Valor de e usando a s�rie fornecida: %.5f\n", calcular_e(n));
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Op��o inv�lida!\n");
                break;
        }
    } while (escolha != 0);

    return 0;
}
