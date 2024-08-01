#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// João Pedro Costa Amaral - Matrícula: 853488

// Função para acrescentar caractere ao final de uma cadeia de caracteres
char* str_push_back(char *s, char c) {
    int len = strlen(s);
    s = realloc(s, len + 2);
    s[len] = c;
    s[len + 1] = '\0';
    return s;
}

// Função para remover caractere do final de uma cadeia de caracteres
char* str_pop_back(char *s) {
    int len = strlen(s);
    if (len > 0) {
        s[len - 1] = '\0';
        s = realloc(s, len);
    }
    return s;
}

// Função para acrescentar caractere ao início de uma cadeia de caracteres
char* str_push_front(char c, char *s) {
    int len = strlen(s);
    s = realloc(s, len + 2);
    memmove(s + 1, s, len + 1);
    s[0] = c;
    return s;
}

// Função para remover caractere do início de uma cadeia de caracteres
char* str_pop_front(char *s) {
    int len = strlen(s);
    if (len > 0) {
        memmove(s, s + 1, len);
        s = realloc(s, len);
    }
    return s;
}

// Função para inserir caractere no meio (aproximadamente) de uma cadeia de caracteres
char* str_push_mid(char *s, char c) {
    int len = strlen(s);
    if (len < 2) return s;
    int mid = len / 2;
    s = realloc(s, len + 2);
    memmove(s + mid + 1, s + mid, len - mid + 1);
    s[mid] = c;
    return s;
}

// Função para remover caractere do meio (aproximadamente) de uma cadeia de caracteres
char* str_pop_mid(char *s) {
    int len = strlen(s);
    if (len < 2) return s;
    int mid = len / 2;
    memmove(s + mid, s + mid + 1, len - mid);
    s = realloc(s, len);
    return s;
}

// Função para inserir caractere em certa posição válida de uma cadeia de caracteres
char* str_insert(char *s, char c, int index) {
    int len = strlen(s);
    if (index < 0 || index > len) return s;
    s = realloc(s, len + 2);
    memmove(s + index + 1, s + index, len - index + 1);
    s[index] = c;
    return s;
}

// Função para remover caractere de certa posição válida de uma cadeia de caracteres
char* str_remove(char *s, int index) {
    int len = strlen(s);
    if (index < 0 || index >= len) return s;
    memmove(s + index, s + index + 1, len - index);
    s = realloc(s, len);
    return s;
}

// Função para procurar pela primeira ocorrência de certo símbolo em uma cadeia de caracteres
char* str_chr(char *s, char c) {
    while (*s) {
        if (*s == c) return s;
        s++;
    }
    return NULL;
}

// Função para separar caracteres até a ocorrência de delimitador em uma cadeia de caracteres
char* str_tok(char *s, char delimiter) {
    static char *last = NULL;
    if (s) last = s;
    if (!last || !*last) return NULL;
    char *start = last;
    while (*last && *last != delimiter) last++;
    if (*last) *last++ = '\0';
    else last = NULL;
    return start;
}

// Função para procurar por certo prefixo em cadeia de caracteres
char* str_prefix(char *prefix, char *s) {
    while (*prefix && *s && *prefix == *s) {
        prefix++;
        s++;
    }
    return *prefix == '\0' ? s : NULL;
}

// Função para procurar por certo sufixo em cadeia de caracteres
char* str_suffix(char *s, char *sufix) {
    int len_s = strlen(s);
    int len_sufix = strlen(sufix);
    if (len_s < len_sufix) return NULL;
    s += (len_s - len_sufix);
    return strcmp(s, sufix) == 0 ? s : NULL;
}

int main() {
    // Testando as funções
    char *s = malloc(1);
    *s = '\0';

    printf("Início: \"%s\"\n", s);

    // Testando str_push_back
    s = str_push_back(s, 'A');
    printf("Após str_push_back('A'): \"%s\"\n", s);

    // Testando str_pop_back
    s = str_pop_back(s);
    printf("Após str_pop_back(): \"%s\"\n", s);

    // Testando str_push_front
    s = str_push_front('B', s);
    printf("Após str_push_front('B'): \"%s\"\n", s);

    // Testando str_pop_front
    s = str_pop_front(s);
    printf("Após str_pop_front(): \"%s\"\n", s);

    // Preenchendo a string para testes adicionais
    s = str_push_back(s, 'H');
    s = str_push_back(s, 'E');
    s = str_push_back(s, 'L');
    s = str_push_back(s, 'L');
    s = str_push_back(s, 'O');
    printf("String atual: \"%s\"\n", s);

    // Testando str_push_mid
    s = str_push_mid(s, 'X');
    printf("Após str_push_mid('X'): \"%s\"\n", s);

    // Testando str_pop_mid
    s = str_pop_mid(s);
    printf("Após str_pop_mid(): \"%s\"\n", s);

    // Testando str_insert
    s = str_insert(s, 'Y', 1);
    printf("Após str_insert('Y', 1): \"%s\"\n", s);

    // Testando str_remove
    s = str_remove(s, 1);
    printf("Após str_remove(1): \"%s\"\n", s);

    // Testando str_chr
    char *found = str_chr(s, 'L');
    printf("Primeira ocorrência de 'L': \"%s\"\n", found ? found : "Não encontrado");

    // Testando str_tok
    char *token;
    token = str_tok(s, 'L');
    while (token) {
        printf("Token: \"%s\"\n", token);
        token = str_tok(NULL, 'L');
    }

    // Testando str_prefix
    char *prefix = "HE";
    found = str_prefix(prefix, s);
    printf("Prefixo \"%s\" encontrado: \"%s\"\n", prefix, found ? found : "Não encontrado");

    // Testando str_suffix
    char *sufix = "LO";
    found = str_suffix(s, sufix);
    printf("Sufixo \"%s\" encontrado: \"%s\"\n", sufix, found ? found : "Não encontrado");

    // Liberando a memória
    free(s);

    return 0;
}
