#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TELEFONES 10 // N�mero m�ximo de telefones que um contato pode ter

// Defini��o da classe Contato
typedef struct {
    char nome[100];
    char telefone[100];
    char telefone2[100];
    int quantidadeTelefones;
} Contato;

// M�todo 1311: Ler do teclado e atribuir um valor ao nome
void readName(Contato *contato, const char *prompt) {
    printf("%s", prompt);
    scanf(" %[^\n]s", contato->nome); // L� at� quebra de linha e exclui o espa�o
}

// M�todo 1312: Ler do teclado e atribuir um valor ao telefone
void readPhone(Contato *contato, const char *prompt) {
    printf("%s", prompt);
    scanf(" %[^\n]s", contato->telefone); // L� at� quebra de linha e exclui o espa�o

    // Testa se o telefone n�o est� vazio
    if (strlen(contato->telefone) == 0) {
        printf("Erro: O telefone n�o pode estar vazio.\n");
        exit(1);
    }

    // Verifica se o telefone � v�lido
    if (!validatePhone(contato->telefone)) {
        printf("Erro: Formato de telefone inv�lido.\n");
        exit(1);
    }

    contato->quantidadeTelefones = 1;
}

// M�todo privado 1313: Testar se o valor de um telefone � v�lido
bool validatePhone(const char *telefone) {
    // O telefone deve conter apenas algarismos e o caractere '-'
    for (int i = 0; i < strlen(telefone); i++) {
        if (!isdigit(telefone[i]) && telefone[i] != '-') {
            return false;
        }
    }
    return true;
}

// M�todo 1314: Ler dados de arquivo, dado o nome do mesmo, e armazenar em um objeto dessa classe
void readFromFile(Contato *contato, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    // Ler nome
    fscanf(fp, "%s", contato->nome);

    // Ler telefone
    fscanf(fp, "%s", contato->telefone);

    // Ler segundo telefone (se existir)
    if (fscanf(fp, "%s", contato->telefone2) == 1) {
        contato->quantidadeTelefones = 2;
    } else {
        contato->telefone2[0] = '\0';
        contato->quantidadeTelefones = 1;
    }

    fclose(fp);
}

// M�todo 1315: Gravar dados de uma pessoa em arquivo, dado o nome do mesmo
void writeToFile(Contato *contato, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    // Escrever nome
    fprintf(fp, "%s\n", contato->nome);

    // Escrever telefone
    fprintf(fp, "%s\n", contato->telefone);

    // Escrever segundo telefone (se existir)
    if (contato->quantidadeTelefones == 2) {
        fprintf(fp, "%s\n", contato->telefone2);
    }

    fclose(fp);
}

// M�todo 1316: Incluir um segundo telefone e modificar os construtores para lidar com isso
void addSecondPhone(Contato *contato, const char *nome, const char *telefone1, const char *telefone2) {
    strcpy(contato->nome, nome);
    strcpy(contato->telefone, telefone1);
    strcpy(contato->telefone2, telefone2);
    contato->quantidadeTelefones = 2;
}

// M�todo 1317: Indicar quantos telefones est�o associados a cada objeto
int phones(Contato *contato) {
    return contato->quantidadeTelefones;
}

// M�todo 1318: Atribuir valor ao segundo telefone
void setPhone2a(Contato *contato, const char *telefone2) {
    if (contato->quantidadeTelefones == 1) {
        char resposta;
        printf("O contato s� tem um telefone. Deseja adicionar mais um? (s/n): ");
        scanf(" %c", &resposta);
        if (resposta == 's' || resposta == 'S') {
            strcpy(contato->telefone2, telefone2);
            contato->quantidadeTelefones = 2;
        } else {
            printf("Opera��o cancelada.\n");
        }
    } else {
        strcpy(contato->telefone2, telefone2);
    }
}

// M�todo 1319: Alterar o valor apenas do segundo telefone
void setPhone2b(Contato *contato, const char *telefone2) {
    if (contato->quantidadeTelefones != 2) {
        printf("Erro: O contato n�o tem dois telefones.\n");
        exit(1);
    }

    strcpy(contato->telefone2, telefone2);
}

// M�todo 1320: Remover apenas o valor do segundo telefone
void setPhone2c(Contato *contato, const char *telefone2) {
    if (contato->quantidadeTelefones == 1) {
        printf("Erro: O contato s� tem um telefone.\n");
        exit(1);
    }

    contato->telefone2[0] = '\0';
    contato->quantidadeTelefones = 1;
}

int main() {
    Contato contato1;

    // Exemplo de uso dos m�todos
    readName(&contato1, "Digite o nome: ");
    readPhone(&contato1, "Digite o telefone: ");

    printf("\nDados do Contato:\n");
    printf("Nome: %s\n", contato1.nome);
    printf("Telefone 1: %s\n", contato1.telefone);

    // Testando leitura e escrita em arquivo
    writeToFile(&contato1, "contato1.txt");

    Contato contato2;
    readFromFile(&contato2, "contato1.txt");

    printf("\nDados lidos do arquivo:\n");
    printf("Nome: %s\n", contato2.nome);
    printf("Telefone 1: %s\n", contato2.telefone);

    return 0;
}
