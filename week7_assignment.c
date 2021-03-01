#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 4

int m[N][N]; //최소합 배열을 저장할 배열
int path[2*N - 1]; //최단 경로를 저장할 배열

int min(int a, int b) { //최소값 찾는 함수
    int minimum = 0;
    if (a > b) {
        minimum = b;
        return minimum;
    }
    if (a <= b) {
        minimum = a;
        return minimum;
    }
}

int mat(int L[][N]) { //최소합 배열 만들기
    int i, j;

    m[0][0] = L[0][0];

    for(i = 1; i < N; i++) {
        m[i][0] = L[i][0] + m[i-1][0];
    }
    for(j = 1; j < N; j++) {
        m[0][j] = L[0][j] + m[0][j -1];
    }
    for(i = 1; i < N; i++) {
        for(j = 1; j < N; j++) {
            m[i][j] = L[i][j] + min(m[i-1][j], m[i][j-1]);
        }
    }
    return m[N-1][N-1];
}

int printMat(int mat[][N], int col, int row) { //행렬 출력 함수
    int i, j;
    for(i = 0; i < col; i++) {
        for(j = 0; j < row; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int savePath(int m[][N], int L[][N]) { //최단 경로를 찾는 함수

    for(int i = 0; i < 2*N-1; i++) {

        for(int c = N-1; c >= 0; c--) { 
            for(int r = c; r >= 0; r--) { 

                if(abs(m[c-1][r] - m[c][r]) == L[c][r]) {
                    path[i] = L[c][r];
                    c--;
                    i++;
                }
                if(abs(m[c][r-1] - m[c][r]) == L[c][r]) {
                    path[i] = L[c][r];
                    i++;
                }
            }
        }
    }
}

int main(void) {

    int matrix[N][N] = {
        {6, 7, 12, 5},
        {5, 3, 11, 18},
        {7, 17, 3, 3},
        {8, 10, 14, 9}
    };

    int col = sizeof(matrix[0]) / sizeof(int);
    int row = sizeof(matrix) / sizeof(matrix[0]);

    printf("최단 경로 찾기\n");
    printMat(matrix, col, row); //원본 배열 출력
    printf("\n");

    mat(matrix); //최소합 배열 만들기

    printf("최소합 배열\n");
    printMat(m, col, row); //최소합 배열 출력
    printf("\n");

    printf("최단 경로 최소합 = %d\n\n", mat(matrix));

    savePath(m, matrix); //최단경로 찾기

    printf("최단 경로 출력 : ");
    for(int i = 2*N-2; i >= 0; i--) {
        printf("%d ", path[i]);
    } //최단경로 출력
    printf("\n");

}