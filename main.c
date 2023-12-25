#include <stdio.h>
#include <stdlib.h>

int** genIdentity(int order){
    int** matrixId = (int**)malloc(order * sizeof(int));

    for(int i = 0; i < order; i++){
        matrixId[i] = (int*)malloc(order * sizeof(int));
        for(int j = 0; j < order; j++){
            if(i == j){
                matrixId[i][j] = 1;
            } else {
                matrixId[i][j] = 0;
            }
        }
    }
    return matrixId;
}

int** joinMatrixes(int order, int** matrixA, int** matrixB){
    int** augmentedMatrix = (int**)malloc(order * sizeof(int));

    for(int i = 0; i < order; i++){
        augmentedMatrix[i] = (int*)malloc(2 * order * sizeof(int));
        for(int j = 0; j < order; j++){
            augmentedMatrix[i][j] = matrixA[i][j];
        }
        for(int k = 0; k < order; k++){
            augmentedMatrix[i][order + k] = matrixB[i][k];
        }
    }
    return augmentedMatrix;
}

void freeMatrix(int order, int** matrix){
    for(int i = 0; i < order; i++){
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int rows, int cols, int **matrix){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(j == 0){
                printf("| ");
            }
            printf("%d ", matrix[i][j]);
            if(j + 1 == cols){
                printf("|\n");
            }
        }
    }
}

void collectData(int rows, int cols, int** matrix){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }   
}

int main(){
    int order;

    printf("Type matrix's order: ");
    scanf("%d", &order);

    int** matrix = (int**)malloc(order * sizeof(int));

    for(int i = 0; i < order; i++){
        matrix[i] = (int*)malloc(order * sizeof(int));
    }

    collectData(order, order, matrix);
    printMatrix(order, order, matrix);

    int** id = genIdentity(order);
    int** joinedMatrix = joinMatrixes(order, matrix, id);

    printMatrix(order, order, id);
    printMatrix(order, order * 2, joinedMatrix);

    freeMatrix(order, matrix);
    freeMatrix(order, id);
    freeMatrix(order, joinedMatrix);

    return 0;
}