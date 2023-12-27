#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* permutation;
    bool modsEven;
} ElementarProductCols;

void printMatrix(int rows, int cols, int **matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == 0) {
                printf("| ");
            }
            printf("%d ", matrix[i][j]);
            if (j + 1 == cols) {
                printf("|\n");
            }
        }
    }
}

void collectData(int rows, int cols, int **matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int fact(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* getSetOfNumbersUntil(int n) {
    int *set = (int*)malloc(n * sizeof(int));

    for (int i = 1; i <= n; i++) {
        set[i - 1] = i;
    }

    return set;
}

void getPermutedArray(int *array, int start, int end, int **permutedArrays, int *count) {
    if (start == end) {
        permutedArrays[*count] = (int*)malloc((end + 1) * sizeof(int));
        for (int i = 0; i <= end; i++) {
            permutedArrays[*count][i] = array[i];
        }
        (*count)++;
    } else {
        for (int i = start; i <= end; i++) {
            swap(&array[start], &array[i]);
            getPermutedArray(array, start + 1, end, permutedArrays, count);
            swap(&array[start], &array[i]);
        }
    }
}

int verifyMinimumChanges(int *initialPattern, int *possiblePermutation){
    int changes = 0;
    //verificar quais estão no lugar certo
}

int main() {
    int order;

    scanf("%d", &order);

    int *setToPermute = getSetOfNumbersUntil(order);
    int **permutedArrays = (int**)malloc(fact(order) * sizeof(int*));
    int count = 0;

    getPermutedArray(setToPermute, 0, order - 1, permutedArrays, &count);




    for (int i = 0; i < count; i++) {
        free(permutedArrays[i]);
    }

    free(permutedArrays);
    free(setToPermute);
    return 0;
}
