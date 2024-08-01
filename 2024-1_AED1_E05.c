#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// João Pedro Costa Amaral - Matrícula: 853488

// Função 0511: Mostrar múltiplos de 6 em ordem crescente
void mostrar_multiplos_6(int n) {
    printf("Múltiplos de 6: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i * 6);
    }
    printf("\n");
}

// Função 0512: Mostrar múltiplos de 3 e 5 em ordem crescente
void mostrar_multiplos_3_5(int n) {
    printf("Múltiplos de 3 e 5: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i * 15);
    }
    printf("\n");
}

// Função 0513: Mostrar potências de 4 em ordem decrescente
void mostrar_potencias_4(int n) {
    printf("Potências de 4: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%ld ", (long)pow(4, i));
    }
    printf("\n");
}

// Função 0514: Mostrar denominadores múltiplos de 7
void mostrar_inversos_multiplos_7(int n) {
    printf("Inversos de múltiplos de 7: ");
    for (int i = 1; i <= n; i++) {
        printf("1/%d ", i * 7);
    }
    printf("\n");
}

// Função 0515: Mostrar valores pares crescentes nos denominadores
void mostrar_pares_crescentes(int n, double x) {
    printf("Pares crescentes em denominadores: ");
    for (int i = 0; i < n; i++) {
        printf("1/%.2f ", pow(x, 2 * i));
    }
    printf("\n");
}

// Função 0516: Soma dos múltiplos de 3 não múltiplos de 5
int soma_multiplos_3_nao_5(int n) {
    int soma = 0, count = 0, valor = 3;
    while (count < n) {
        if (valor % 5 != 0) {
            soma += valor;
            count++;
        }
        valor += 3;
    }
    return soma;
}

// Função 0517: Soma dos inversos de múltiplos de 6 não múltiplos de 5
double soma_inversos_multiplos_6_nao_5(int n) {
    double soma = 0.0;
    int count = 0, valor = 6;
    while (count < n) {
        if (valor % 5 != 0) {
            soma += 1.0 / valor;
            count++;
        }
        valor += 6;
    }
    return soma;
}

// Função 0518: Soma dos primeiros números naturais começando em 6
int soma_naturais_comecando_6(int n) {
    int soma = 0, valor = 6;
    for (int i = 0; i < n; i++) {
        soma += valor;
        valor++;
    }
    return soma;
}

// Função 0519: Soma dos quadrados dos números naturais começando em 6
int soma_quadrados_comecando_6(int n) {
    int soma = 0, valor = 6;
    for (int i = 0; i < n; i++) {
        soma += valor * valor;
        valor++;
    }
    return soma;
}

// Função 0520: Soma dos inversos das adições dos números naturais terminando em 6
double soma_inversos_adicoes(int n) {
    double soma = 0.0;
    for (int i = 1; i <= n; i++) {
        soma += 1.0 / (n - i + 1 + 5);
    }
    return soma;
}

// Função Extra E1: Calcular fatorial de um número
long fatorial(int n) {
    long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Função Extra E2: Calcular o resultado da função f(n)
double calcular_f(int n) {
    double resultado = 1.0;
    for (int i = 0; i < n; i++) {
        resultado *= 1 + pow(2, i) / fatorial(5 + 2 * i);
    }
    return resultado;
}

int main() {
    int n, escolha;
    double x;

    do {
        printf("\nSelecione a opção desejada:\n");
        printf("1. Múltiplos de 6\n");
        printf("2. Múltiplos de 3 e 5\n");
        printf("3. Potências de 4\n");
        printf("4. Inversos de múltiplos de 7\n");
        printf("5. Pares crescentes em denominadores\n");
        printf("6. Soma de múltiplos de 3 não múltiplos de 5\n");
        printf("7. Soma de inversos de múltiplos de 6 não múltiplos de 5\n");
        printf("8. Soma de números naturais começando em 6\n");
        printf("9. Soma dos quadrados de números naturais começando em 6\n");
        printf("10. Soma dos inversos das adições de números naturais\n");
        printf("11. Calcular fatorial\n");
        printf("12. Calcular função f(n)\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite a quantidade de múltiplos de 6: ");
                scanf("%d", &n);
                mostrar_multiplos_6(n);
                break;
            case 2:
                printf("Digite a quantidade de múltiplos de 3 e 5: ");
                scanf("%d", &n);
                mostrar_multiplos_3_5(n);
                break;
            case 3:
                printf("Digite a quantidade de potências de 4: ");
                scanf("%d", &n);
                mostrar_potencias_4(n);
                break;
            case 4:
                printf("Digite a quantidade de inversos de múltiplos de 7: ");
                scanf("%d", &n);
                mostrar_inversos_multiplos_7(n);
                break;
            case 5:
                printf("Digite um valor para x: ");
                scanf("%lf", &x);
                printf("Digite a quantidade de pares crescentes: ");
                scanf("%d", &n);
                mostrar_pares_crescentes(n, x);
                break;
            case 6:
                printf("Digite a quantidade de múltiplos de 3 não múltiplos de 5: ");
                scanf("%d", &n);
                printf("Soma: %d\n", soma_multiplos_3_nao_5(n));
                break;
            case 7:
                printf("Digite a quantidade de inversos de múltiplos de 6 não múltiplos de 5: ");
                scanf("%d", &n);
                printf("Soma dos inversos: %.5f\n", soma_inversos_multiplos_6_nao_5(n));
                break;
            case 8:
                printf("Digite a quantidade de números naturais começando em 6: ");
                scanf("%d", &n);
                printf("Soma: %d\n", soma_naturais_comecando_6(n));
                break;
            case 9:
                printf("Digite a quantidade de quadrados dos números naturais começando em 6: ");
                scanf("%d", &n);
                printf("Soma dos quadrados: %d\n", soma_quadrados_comecando_6(n));
                break;
            case 10:
                printf("Digite a quantidade de inversos das adições de números naturais: ");
                scanf("%d", &n);
                printf("Soma dos inversos: %.5f\n", soma_inversos_adicoes(n));
                break;
            case 11:
                printf("Digite um número para calcular o fatorial: ");
                scanf("%d", &n);
                printf("Fatorial de %d: %ld\n", n, fatorial(n));
                break;
            case 12:
                printf("Digite a quantidade para calcular f(n): ");
                scanf("%d", &n);
                printf("Resultado de f(%d): %.5f\n", n, calcular_f(n));
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}
