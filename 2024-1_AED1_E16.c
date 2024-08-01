#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// João Pedro Costa Amaral - 853488

typedef struct s_intArray {
    int length;
    int *data;
} intArray;

typedef intArray* ref_intArray;

// Função para imprimir o conteúdo de um arranjo de inteiros
void printArray(ref_intArray array) {
    for (int i = 0; i < array->length; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

// Função para liberar memória alocada para um arranjo de inteiros
void freeArray(ref_intArray array) {
    if (array != NULL) {
        if (array->data != NULL) {
            free(array->data);
        }
        free(array);
    }
}

/**
 * Funcao para acrescentar valor ao final
 * de um arranjo, por meio de apontador.
 * @return apontador para arranjo atualizado
 * @param array - apontador para arranjo
 * @param value - valor a ser inserido
 */
int* array_push_back(int *array, int value) {
    int len = 0;
    if (array != NULL) {
        while (array[len] != '\0') {
            len++;
        }
    }

    int *new_array = (int *)malloc((len + 2) * sizeof(int));
    for (int i = 0; i < len; i++) {
        new_array[i] = array[i];
    }
    new_array[len] = value;
    new_array[len + 1] = '\0';

    if (array != NULL) {
        free(array);
    }

    return new_array;
}

/**
 * Funcao para remover valor do final
 * de um arranjo, por meio de apontador.
 * @return apontador para arranjo atualizado
 * @param array - apontador para arranjo
 */
int* array_pop_back(int *array) {
    int len = 0;
    if (array != NULL) {
        while (array[len] != '\0') {
            len++;
        }
    }

    if (len == 0) return array;

    int *new_array = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len - 1; i++) {
        new_array[i] = array[i];
    }
    new_array[len - 1] = '\0';

    if (array != NULL) {
        free(array);
    }

    return new_array;
}

/**
 * Funcao para acrescentar valor ao início
 * de um arranjo, por meio de apontador.
 * @return apontador para arranjo atualizado
 * @param array - apontador para arranjo
 * @param value - valor a ser inserido
 */
int* array_push_front(int value, int *array) {
    int len = 0;
    if (array != NULL) {
        while (array[len] != '\0') {
            len++;
        }
    }

    int *new_array = (int *)malloc((len + 2) * sizeof(int));
    new_array[0] = value;
    for (int i = 0; i < len; i++) {
        new_array[i + 1] = array[i];
    }
    new_array[len + 1] = '\0';

    if (array != NULL) {
        free(array);
    }

    return new_array;
}

/**
 * Funcao para remover valor do início
 * de um arranjo, por meio de apontador.
 * @return apontador para arranjo atualizado
 * @param array - apontador para arranjo
 */
int* array_pop_front(int *array) {
    int len = 0;
    if (array != NULL) {
        while (array[len] != '\0') {
            len++;
        }
    }

    if (len == 0) return array;

    int *new_array = (int *)malloc(len * sizeof(int));
    for (int i = 1; i < len; i++) {
        new_array[i - 1] = array[i];
    }
    new_array[len - 1] = '\0';

    if (array != NULL) {
        free(array);
    }

    return new_array;
}

/**
 * Funcao para acrescentar valor no meio (aproximadamente)
 * de um arranjo, por meio de apontador.
 * @return apontador para arranjo atualizado
 * @param array - apontador para arranjo
 * @param value - valor a ser inserido
 */
int* array_push_mid(int *array, int value) {
    int len = 0;
    if (array != NULL) {
        while (array[len] != '\0') {
            len++;
        }
    }

    int mid = len / 2;
    int *new_array = (int *)malloc((len + 2) * sizeof(int));
    for (int i = 0; i < mid; i++) {
        new_array[i] = array[i];
    }
    new_array[mid] = value;
    for (int i = mid; i < len; i++) {
        new_array[i + 1] = array[i];
    }
    new_array[len + 1] = '\0';

    if (array != NULL) {
        free(array);
    }

    return new_array;
}

/**
 * Funcao para remover valor do meio (aproximadamente)
 * de um arranjo, por meio de apontador.
 * @return apontador para arranjo atualizado
 * @param array - apontador para arranjo
 */
int* array_pop_mid(int *array) {
    int len = 0;
    if (array != NULL) {
        while (array[len] != '\0') {
            len++;
        }
    }

    if (len == 0) return array;

    int mid = len / 2;
    int *new_array = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < mid; i++) {
        new_array[i] = array[i];
    }
    for (int i = mid + 1; i < len; i++) {
        new_array[i - 1] = array[i];
    }
    new_array[len - 1] = '\0';

    if (array != NULL) {
        free(array);
    }

    return new_array;
}

/**
 * Funcao para comparar arranjos de inteiros
 * por meio de apontadores.
 * @return zero , se forem iguais;
 * negativo, se o valor da diferenca for menor e estiver no primeiro arranjo
 * positivo , se o valor da diferenca for maior e estiver no primeiro arranjo
 * @param p - apontador para inicio do primeiro arranjo
 * @param q - apontador para inicio do segundo arranjo
 */
int intArray_cmp(ref_intArray p, ref_intArray q) {
    int min_len = p->length < q->length ? p->length : q->length;
    for (int i = 0; i < min_len; i++) {
        if (p->data[i] != q->data[i]) {
            return p->data[i] - q->data[i];
        }
    }
    return p->length - q->length;
}

/**
 * Funcao para juntar arranjos de inteiros
 * por meio de apontadores.
 * @return apontador para inicio do arranjo com a uniao
 * @param p - apontador para inicio do primeiro arranjo
 * @param q - apontador para inicio do segundo arranjo
 */
ref_intArray intArray_cat(ref_intArray p, ref_intArray q) {
    ref_intArray result = (ref_intArray)malloc(sizeof(intArray));
    result->length = p->length + q->length;
    result->data = (int *)malloc(result->length * sizeof(int));

    for (int i = 0; i < p->length; i++) {
        result->data[i] = p->data[i];
    }
    for (int i = 0; i < q->length; i++) {
        result->data[p->length + i] = q->data[i];
    }

    return result;
}

/**
 * Funcao para procurar pela primeira ocorrencia de valor em arranjo
 * por meio de apontador.
 * @return apontador para a primeira ocorrência; NULL, caso contrario
 * @param a - apontador para arranjo de inteiros
 * @param x - valor ser procurado
*/
ref_intArray intArray_seek(ref_intArray a, int x) {
    for (int i = 0; i < a->length; i++) {
        if (a->data[i] == x) {
            return a;
        }
    }
    return NULL;
}

/**
 * Funcao para separar sequencia de valores em arranjo
 * por meio de apontador.
 * @return apontador para inicio da sequencia de inteiros; NULL, caso contrario
 * @param a - apontador para arranjo de inteiros
 * @param start - posicao inicial
 * @param size - quantidade de dados
 */
ref_intArray intArray_sub(ref_intArray a, int start, int size) {
    if (start < 0 || start >= a->length || start + size > a->length) {
        return NULL;
    }

    ref_intArray sub_array = (ref_intArray)malloc(sizeof(intArray));
    sub_array->length = size;
    sub_array->data = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        sub_array->data[i] = a->data[start + i];
    }

    return sub_array;
}

/**
 * Funcao para intercalar arranjos de inteiros
 * por meio de apontadores.
 * @return apontador para inicio do arranjo com a uniao
 * @param p - apontador para inicio do primeiro arranjo
 * @param q - apontador para inicio do segundo arranjo
 */
ref_intArray intArray_merge(ref_intArray p, ref_intArray q) {
    int total_length = p->length + q->length;
    ref_intArray result = (ref_intArray)malloc(sizeof(intArray));
    result->length = total_length;
    result->data = (int *)malloc(total_length * sizeof(int));

    int i = 0, j = 0, k = 0;

    while (i < p->length && j < q->length) {
        if (k % 2 == 0) {
            result->data[k++] = p->data[i++];
        } else {
            result->data[k++] = q->data[j++];
        }
    }

    while (i < p->length) {
        result->data[k++] = p->data[i++];
    }

    while (j < q->length) {
        result->data[k++] = q->data[j++];
    }

    return result;
}

/**
 * Funcao para intercalar arranjos de inteiros em ordem crescente
 * por meio de apontadores.
 * @return apontador para inicio do arranjo com a uniao
 * @param p - apontador para inicio do primeiro arranjo
 * @param q - apontador para inicio do segundo arranjo
 */
ref_intArray intArray_mergeUp(ref_intArray p, ref_intArray q) {
    int total_length = p->length + q->length;
    ref_intArray result = (ref_intArray)malloc(sizeof(intArray));
    result->length = total_length;
    result->data = (int *)malloc(total_length * sizeof(int));

    int i = 0, j = 0, k = 0;

    while (i < p->length && j < q->length) {
        if (p->data[i] < q->data[j]) {
            result->data[k++] = p->data[i++];
        } else {
            result->data[k++] = q->data[j++];
        }
    }

    while (i < p->length) {
        result->data[k++] = p->data[i++];
    }

    while (j < q->length) {
        result->data[k++] = q->data[j++];
    }

    return result;
}

int main() {
    printf("João Pedro Costa Amaral - Matrícula: 853488\n");

    // Exemplo de uso das funções de manipulação de arranjos

    // Inicializa um arranjo
    int *arr = NULL;

    // Adiciona valores ao final do arranjo
    arr = array_push_back(arr, 10);
    arr = array_push_back(arr, 20);
    arr = array_push_back(arr, 30);
    printf("Arranjo após array_push_back: ");
    for (int i = 0; arr[i] != '\0'; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Remove valor do final do arranjo
    arr = array_pop_back(arr);
    printf("Arranjo após array_pop_back: ");
    for (int i = 0; arr[i] != '\0'; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Adiciona valores ao início do arranjo
    arr = array_push_front(5, arr);
    printf("Arranjo após array_push_front: ");
    for (int i = 0; arr[i] != '\0'; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Remove valor do início do arranjo
    arr = array_pop_front(arr);
    printf("Arranjo após array_pop_front: ");
    for (int i = 0; arr[i] != '\0'; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Adiciona valor ao meio do arranjo
    arr = array_push_mid(arr, 25);
    printf("Arranjo após array_push_mid: ");
    for (int i = 0; arr[i] != '\0'; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Remove valor do meio do arranjo
    arr = array_pop_mid(arr);
    printf("Arranjo após array_pop_mid: ");
    for (int i = 0; arr[i] != '\0'; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Exemplo de uso das funções de manipulação de arranjos com estruturas

    // Inicializa dois arranjos usando estruturas
    ref_intArray array1 = (ref_intArray)malloc(sizeof(intArray));
    array1->length = 5;
    array1->data = (int *)malloc(array1->length * sizeof(int));
    for (int i = 0; i < array1->length; i++) {
        array1->data[i] = i + 1;
    }

    ref_intArray array2 = (ref_intArray)malloc(sizeof(intArray));
    array2->length = 5;
    array2->data = (int *)malloc(array2->length * sizeof(int));
    for (int i = 0; i < array2->length; i++) {
        array2->data[i] = (i + 1) * 2;
    }

    // Compara os dois arranjos
    int cmp_result = intArray_cmp(array1, array2);
    printf("Resultado da comparação: %d\n", cmp_result);

    // Junta os dois arranjos
    ref_intArray concatenated_array = intArray_cat(array1, array2);
    printf("Arranjo concatenado: ");
    printArray(concatenated_array);

    // Procura um valor no arranjo
    int seek_value = 4;
    ref_intArray seek_result = intArray_seek(array1, seek_value);
    if (seek_result != NULL) {
        printf("Valor %d encontrado no arranjo.\n", seek_value);
    } else {
        printf("Valor %d não encontrado no arranjo.\n", seek_value);
    }

    // Obtém uma sub-sequência do arranjo
    ref_intArray sub_array = intArray_sub(array1, 1, 3);
    printf("Sub-arranjo: ");
    printArray(sub_array);

    // Intercala dois arranjos
    ref_intArray merged_array = intArray_merge(array1, array2);
    printf("Arranjo intercalado: ");
    printArray(merged_array);

    // Intercala dois arranjos em ordem crescente
    ref_intArray merged_up_array = intArray_mergeUp(array1, array2);
    printf("Arranjo intercalado em ordem crescente: ");
    printArray(merged_up_array);

    // Libera a memória alocada
    free(arr);
    freeArray(array1);
    freeArray(array2);
    freeArray(concatenated_array);
    freeArray(sub_array);
    freeArray(merged_array);
    freeArray(merged_up_array);

    return 0;
}
