#include <stdio.h>
#include <assert.h>
#define MAX 20

typedef struct matrix{
    int col;
    int row;
    int mat[MAX][MAX];
} Matrix;

Matrix CreateMatrix(int row, int col){
    assert(row <= MAX && col <= MAX);
    Matrix m = {
        .col = col,
        .row = row
    };
    return m;
}

Matrix MultiplyMatrix(Matrix A, Matrix B){
    assert(A.col == B.row);
    Matrix C = CreateMatrix(A.row, B.col);
    for(int i = 0; i < A.row; i++){
        for(int j = 0; j < B.col; j++){
            int sum = 0;
            for(int k = 0; k < A.col; k++){
                sum += A.mat[i][k] * B.mat[k][j];
            }
            C.mat[i][j] = sum;
        }
    }
    return C;
}

Matrix TransposeMatrix(Matrix A){
    Matrix T = CreateMatrix(A.col, A.row);
    for(int i = 0; i < A.row; i++){
        for(int j = 0; j < A.col; j++){
            T.mat[j][i] = A.mat[i][j];
        }
    }
    return T;
}

Matrix CreateInputFilledMatrix(int row, int col){
    Matrix A = CreateMatrix(row, col);
    printf("Enter Matrix Elements : ");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &(A.mat[i][j]));
        }
    }
    return A;
}

void DisplayMatrix(Matrix M){
    for(int i = 0; i < M.row; i++){
        for(int j = 0; j < M.col; j++){
            printf("%3d ", M.mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    Matrix A, B, T, C;
    int row, col;

    printf("Enter Row and Column size of Matrix A : ");
    scanf("%d%d", &row, &col);
    A = CreateInputFilledMatrix(row, col);

    printf("Enter Row and Column size of Matrix B : ");
    scanf("%d%d", &row, &col);
    B = CreateInputFilledMatrix(row, col);

    printf("Matrix A : \n");
    DisplayMatrix(A);

    printf("Matrix B : \n");
    DisplayMatrix(B);

    C = MultiplyMatrix(A, B);
    T = TransposeMatrix(A);

    printf("Matrix A * B : \n");
    DisplayMatrix(C);

    printf("Matrix A' : \n");
    DisplayMatrix(T);
}