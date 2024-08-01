
/*
-> REFAÇÃO DA PROVA <-


 João Pedro Costa Amaral - 853488

 Questão 1 = 2
 Questão 2 = bqbubebi
 Questão 3 =  Weiss Grun
 Questão 4 = OUTRA (CSTNHLDA)
 Questão 5 = "padre" "perda"


 */


// Questão 6

#include <stdio.h>
#include <string.h>

// Função para converter uma letra minúscula em maiúscula
char to_upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

// Função para verificar se o caractere é uma letra
int is_letter(char c) {
    c = to_upper(c);
    return (c >= 'A' && c <= 'Z');
}

// Função para calcular o valor isopsephico de uma palavra
int calcularValor(char *nome) {
    int valor = 0;

    for (int i = 0; i < strlen(nome); i++) {
        char c = to_upper(nome[i]);
        if (c >= 'A' && c <= 'I') {
            valor += (c - 'A' + 1);
        } else if (c >= 'J' && c <= 'R') {
            valor += (c - 'J' + 1);
        } else if (c >= 'S' && c <= 'Z') {
            valor += (c - 'S' + 1);
        }
    }

    return valor;
}

// Função para reduzir a soma a um número de 1 a 9, com exceções para 11 e 22
int reduzirValor(int valor) {
    while (valor > 9 && valor != 11 && valor != 22) {
        int soma = 0;
        while (valor > 0) {
            soma += valor % 10;
            valor /= 10;
        }
        valor = soma;
    }
    return valor;
}

int main() {
    char nome[100];

    printf("Digite um nome: ");
    fgets(nome, 100, stdin);

    // Remover o newline no final da string se existir
    nome[strcspn(nome, "\n")] = '\0';

    int valor = calcularValor(nome);
    int valorReduzido = reduzirValor(valor);

    printf("O valor correspondente ao nome '%s' é: %d\n", nome, valorReduzido);

    return 0;
}


// Questão 7

#include <stdio.h>

// Estrutura para armazenar a data de aniversário
struct Data {
    int dia;
    int mes;
    int ano;
};

// Função para calcular o número de dias até o próximo aniversário
int dias_ate_aniversario(struct Data aniversario, int dias_vividos) {
    int dias_por_ano = 365;
    int dias_por_mes = 30;

    // Calculando os anos, meses e dias que a pessoa viveu
    int anos_vividos = dias_vividos / dias_por_ano;
    dias_vividos %= dias_por_ano;
    int meses_vividos = dias_vividos / dias_por_mes;
    int dias_vividos_ano_atual = dias_vividos % dias_por_mes;

    // Calculando os dias até o próximo aniversário
    int dias_ate_aniversario = 0;

    // Calcular os dias restantes no mês atual
    if (dias_vividos_ano_atual < aniversario.dia) {
        dias_ate_aniversario += aniversario.dia - dias_vividos_ano_atual;
    } else {
        dias_ate_aniversario += (dias_por_mes - dias_vividos_ano_atual) + aniversario.dia;
        meses_vividos++;
    }

    // Calcular os meses restantes até o aniversário
    if (meses_vividos < aniversario.mes) {
        dias_ate_aniversario += (aniversario.mes - meses_vividos - 1) * dias_por_mes;
    } else {
        dias_ate_aniversario += ((12 - meses_vividos) + aniversario.mes - 1) * dias_por_mes;
        anos_vividos++;
    }

    return dias_ate_aniversario;
}

int main() {
    struct Data aniversarios[3];
    int dias_vividos[3];

    // Exemplos de dias vividos
    dias_vividos[0] = 9876;
    dias_vividos[1] = 8967;
    dias_vividos[2] = 6789;

    // Datas de aniversário
    aniversarios[0].dia = 15;
    aniversarios[0].mes = 5;
    aniversarios[0].ano = 1990; // Não utilizado neste contexto

    aniversarios[1].dia = 20;
    aniversarios[1].mes = 7;
    aniversarios[1].ano = 1985; // Não utilizado neste contexto

    aniversarios[2].dia = 10;
    aniversarios[2].mes = 12;
    aniversarios[2].ano = 1978; // Não utilizado neste contexto

    int dias_ate_aniversarios[3];

    // Calcular os dias até o próximo aniversário para cada professor
    for (int i = 0; i < 3; i++) {
        dias_ate_aniversarios[i] = dias_ate_aniversario(aniversarios[i], dias_vividos[i]);
    }

    // Determinar qual professor está mais próximo do aniversário
    int menor_dias = dias_ate_aniversarios[0];
    int indice_menor = 0;

    for (int i = 1; i < 3; i++) {
        if (dias_ate_aniversarios[i] < menor_dias) {
            menor_dias = dias_ate_aniversarios[i];
            indice_menor = i;
        }
    }

    printf("O professor mais próximo do aniversário é o professor %d.\n", indice_menor + 1);
    return 0;
}

//Questão 8

#include <stdio.h>

int main() {
    FILE *inputFile, *oddFile, *evenFile, *outputFile;
    int number;

    // Abrir o arquivo de entrada para leitura
    inputFile = fopen("DADOS.TXT", "r");
    if (inputFile == NULL) {
        printf("Erro ao abrir o arquivo DADOS.TXT\n");
        return 1;
    }

    // Criar arquivos temporários para números ímpares e pares
    oddFile = fopen("ODD.TXT", "w");
    evenFile = fopen("EVEN.TXT", "w");

    if (oddFile == NULL || evenFile == NULL) {
        printf("Erro ao criar arquivos temporários\n");
        fclose(inputFile);
        if (oddFile != NULL) fclose(oddFile);
        if (evenFile != NULL) fclose(evenFile);
        return 1;
    }

    // Ler números do arquivo de entrada e separá-los em ímpares e pares
    while (fscanf(inputFile, "%d", &number) != EOF) {
        if (number % 2 != 0) {
            fprintf(oddFile, "%d\n", number);
        } else {
            fprintf(evenFile, "%d\n", number);
        }
    }

    // Fechar o arquivo de entrada e os arquivos temporários
    fclose(inputFile);
    fclose(oddFile);
    fclose(evenFile);

    // Abrir o arquivo de saída para gravação
    outputFile = fopen("RESULTADO.TXT", "w");
    if (outputFile == NULL) {
        printf("Erro ao abrir o arquivo RESULTADO.TXT\n");
        return 1;
    }

    // Abrir os arquivos temporários para leitura
    oddFile = fopen("ODD.TXT", "r");
    evenFile = fopen("EVEN.TXT", "r");

    if (oddFile == NULL || evenFile == NULL) {
        printf("Erro ao reabrir arquivos temporários\n");
        fclose(outputFile);
        if (oddFile != NULL) fclose(oddFile);
        if (evenFile != NULL) fclose(evenFile);
        return 1;
    }

    // Gravar números ímpares no arquivo de saída
    while (fscanf(oddFile, "%d", &number) != EOF) {
        fprintf(outputFile, "%d\n", number);
    }

    // Gravar números pares no arquivo de saída
    while (fscanf(evenFile, "%d", &number) != EOF) {
        fprintf(outputFile, "%d\n", number);
    }

    // Fechar todos os arquivos
    fclose(oddFile);
    fclose(evenFile);
    fclose(outputFile);

    // Remover arquivos temporários
    remove("ODD.TXT");
    remove("EVEN.TXT");

    printf("Arquivo RESULTADO.TXT criado com sucesso!\n");

    return 0;
}
