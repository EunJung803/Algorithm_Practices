#include <stdio.h>
#define N 6
#define MIN(a,b) a < b ? a : b

int M[N+1][N+1];
int P[N+1][N+1];
int d[N+1];

int minmult(int n, int d[], int M[][N], int P[][N])
{
    int i, j, k, diagonal;
    int temp;
    int new_k;
    for(i = 0; i <= n; i++) { //diagonal = 0
        M[i][i] = 0;
    }

    for(diagonal = 1; diagonal <= n-1; diagonal++) {
        for(i = 1; i <= n-diagonal; i++) {

            j = i + diagonal;
            //M[i][j] = M[i][j] + M[i+1][j] + d[i-1] * d[i] * d[j];

            for(k = i; k <= j-1; k++) {
                M[i][j] = M[i][k] + M[k+1][j] + d[i-1] * d[k] * d[j];
                //int k2 = k++;
                //MIN((M[i][k]), (M[i][k2+1] + M[k2+1][j] + d[i-1] * d[k2] * d[j]));
                //M[i][k] + M[k+1][j] + d[i-1] * d[k] * d[j];
                //MIN((M[i][k] + M[k+1][j] + d[i-1] * d[k] * d[j]), (M[i][k2+1] + M[k2+1][j] + d[i-1] * d[k2] * d[j]));

                if(i == k) {
                    temp = M[i][j];
                    new_k = k;
                }
                else if(temp < M[i][j]) {
                    M[i][j] = temp;
                } 
                else {
                    new_k = k;
                }     
            }
            P[i][j] = new_k; //minimun value k
        }
    }
    return M[1][n];
}


void order(int i, int j, int P[][N]) {
    int k;

    if(i == j) {
        printf("A%d", i);
        //cout << "A" << i;
    }
    else {
        k = P[i][j];
        printf("(");
        //cout << "(";
        order(i, k, P);
        order(k + 1, j, P);
        printf(")");
        //cout << ")";
    }
}

int printMat(int mat[][N], int col, int row) { //행렬 출력 함수
    int i, j;
    for(i = 1; i < col; i++) {
        for(j = 1; j < row; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}

/*
int printMat_P(int mat[][N+1], int col, int row) { //행렬 출력 함수
    int i, j;
    for(i = 1; i < col; i++) {
        for(j = 1; j < row; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}*/

int main(void) {

    int n;

    printf("곱할 행렬의 수 n을 입력해주세요  :  ");
    scanf("%d", &n);

    printf("d0 부터 d%d까지 입력해주세요\n", n);
    for(int i = 0; i <= n; i++) {
        printf("d%d = ", i);
        scanf("%d", &d[i]);
    }

    printf("행과 열을 저장한 배열 d[n+1] = ");
    for(int i = 0; i <= n; i++) {
        printf("%d ", d[i]);
    }
    //int d[N+1] = {5, 2, 3, 4, 6, 7, 8};
    printf("\n\n");

    int min = minmult(n, d, M, P);
    printf("곱셉 횟수의 최소치= %d\n\n", min);

    printf("연쇄행렬곱셈의 최소곱셈수 행렬 M[i][j]\n");
    printMat(M, n+1, n+1);
    printf("\n");

    printf("최적의 순서를 담은 배열 P[i][j]\n");
    printMat(P, n+1, n+1);
    printf("\n");

    printf("최적의 순서를 따르는 최적의 분해\n");
    order(1, n, P);
    printf("\n");

}