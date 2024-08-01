#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Jo�o Pedro Costa Amaral - Matr�cula: 853488

// Fun��o para acrescentar caractere ao final de uma cadeia de caracteres
char* str_push_back(char *s, char c) {
    int len = strlen(s);
    s = realloc(s, len + 2);
    s[len] = c;
    s[len + 1] = '\0';
    return s;
}

// Fun��o para remover caractere do final de uma cadeia de caracteres
char* str_pop_back(char *s) {
    int len = strlen(s);
    if (len > 0) {
        s[len - 1] = '\0';
        s = realloc(s, len);
    }
    return s;
}

// Fun��o para acrescentar caractere ao in�cio de uma cadeia de caracteres
char* str_push_front(char c, char *s) {
    int len = strlen(s);
    s = realloc(s, len + 2);
    memmove(s + 1, s, len + 1);
    s[0] = c;
    return s;
}

// Fun��o para remover caractere do in�cio de uma cadeia de caracteres
char* str_pop_front(char *s) {
    int len = strlen(s);
    if (len > 0) {
        memmove(s, s + 1, len);
        s = realloc(s, len);
    }
    return s;
}

// Fun��o para inserir caractere no meio (aproximadamente) de uma cadeia de caracteres
char* str_push_mid(char *s, char c) {
    int len = strlen(s);
    if (len < 2) return s;
    int mid = len / 2;
    s = realloc(s, len + 2);
    memmove(s + mid + 1, s + mid, len - mid + 1);
    s[mid] = c;
    return s;
}

// Fun��o para remover caractere do meio (aproximadamente) de uma cadeia de caracteres
char* str_pop_mid(char *s) {
    int len = strlen(s);
    if (len < 2) return s;
    int mid = len / 2;
    memmove(s + mid, s + mid + 1, len - mid);
    s = realloc(s, len);
    return s;
}

// Fun��o para inserir caractere em certa posi��o v�lida de uma cadeia de caracteres
char* str_insert(char *s, char c, int index) {
    int len = strlen(s);
    if (index < 0 || index > len) return s;
    s = realloc(s, len + 2);
    memmove(s + index + 1, s + index, len - index + 1);
    s[index] = c;
    return s;
}

// Fun��o para remover caractere de certa posi��o v�lida de uma cadeia de caracteres
char* str_remove(char *s, int index) {
    int len = strlen(s);
    if (index < 0 || index >= len) return s;
    memmove(s + index, s + index + 1, len - index);
    s = realloc(s, len);
    return s;
}

// Fun��o para procurar pela primeira ocorr�ncia de certo s�mbolo em uma cadeia de caracteres
char* str_chr(char *s, char c) {
    while (*s) {
        if (*s == c) return s;
        s++;
    }
    return NULL;
}

// Fun��o para separar caracteres at� a ocorr�ncia de delimitador em uma cadeia de caracteres
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

// Fun��o para procurar por certo prefixo em cadeia de caracteres
char* str_prefix(char *prefix, char *s) {
    while (*prefix && *s && *prefix == *s) {
        prefix++;
        s++;
    }
    return *prefix == '\0' ? s : NULL;
}

// Fun��o para procurar por certo sufixo em cadeia de caracteres
char* str_suffix(char *s, char *sufix) {
    int len_s = strlen(s);
    int len_sufix = strlen(sufix);
    if (len_s < len_sufix) return NULL;
    s += (len_s - len_sufix);
    return strcmp(s, sufix) == 0 ? s : NULL;
}

int main() {
    // Testando as fun��es
    char *s = malloc(1);
    *s = '\0';

    printf("In�cio: \"%s\"\n", s);

    // Testando str_push_back
    s = str_push_back(s, 'A');
    printf("Ap�s str_push_back('A'): \"%s\"\n", s);

    // Testando str_pop_back
    s = str_pop_back(s);
    printf("Ap�s str_pop_back(): \"%s\"\n", s);

    // Testando str_push_front
    s = str_push_front('B', s);
    printf("Ap�s str_push_front('B'): \"%s\"\n", s);

    // Testando str_pop_front
    s = str_pop_front(s);
    printf("Ap�s str_pop_front(): \"%s\"\n", s);

    // Preenchendo a string para testes adicionais
    s = str_push_back(s, 'H');
    s = str_push_back(s, 'E');
    s = str_push_back(s, 'L');
    s = str_push_back(s, 'L');
    s = str_push_back(s, 'O');
    printf("String atual: \"%s\"\n", s);

    // Testando str_push_mid
    s = str_push_mid(s, 'X');
    printf("Ap�s str_push_mid('X'): \"%s\"\n", s);

    // Testando str_pop_mid
    s = str_pop_mid(s);
    printf("Ap�s str_pop_mid(): \"%s\"\n", s);

    // Testando str_insert
    s = str_insert(s, 'Y', 1);
    printf("Ap�s str_insert('Y', 1): \"%s\"\n", s);

    // Testando str_remove
    s = str_remove(s, 1);
    printf("Ap�s str_remove(1): \"%s\"\n", s);

    // Testando str_chr
    char *found = str_chr(s, 'L');
    printf("Primeira ocorr�ncia de 'L': \"%s\"\n", found ? found : "N�o encontrado");

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
    printf("Prefixo \"%s\" encontrado: \"%s\"\n", prefix, found ? found : "N�o encontrado");

    // Testando str_suffix
    char *sufix = "LO";
    found = str_suffix(s, sufix);
    printf("Sufixo \"%s\" encontrado: \"%s\"\n", sufix, found ? found : "N�o encontrado");

    // Liberando a mem�ria
    free(s);

    return 0;
}
