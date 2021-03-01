/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cnt = 0;
int arr[8][8] = {0, };

void showtable(void) {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(arr[i][j] == 1) {
                printf(" [X] ");
            }
            else {
                printf(" [ ] ");
            }
        }
        printf("\n");
    }
}

//특정 좌표에 퀸이 놓였을 경우, 퀸을 놓을 수 없는 위치를 표시하는 함수
void isAble(int x, int y) {
    int data_arr[8][8] = {0, };

    for(int i = 0; i < 8; i ++) {
        data_arr[i][y] = 1;
    }
    for(int j = 0; j < 8; j++) {
        data_arr[x][j] = 1;
    }

    if(x >= y) {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(i - j == x - y) {
                    data_arr[i][j] = 1;
                }
            }
        }
    }
    else {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(j - i == y - x) {
                    data_arr[i][j] = 1;
                }
            }
        }
    }
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(i + j == x + y) {
                data_arr[i][j] = 1;
            }
        }
    }
    printf("\n");
    
    for(int i = 0; i < 8; i++) {
        printf(" ");
            for(int j = 0; j < 8; j++) {
                //printf("%d ", data_arr[i][j]);
                if(data_arr[i][j] = 1) {
                    if(i == x && j == y) {
                        printf(" [*] ");
                    }
                    else {
                        printf(" [X] ");
                    }
                }
                else {
                    printf(" [ ] ");
                }
            }
        printf("\n");
    }
}

int able(int x, int y) {
    int i, j;
    int ret_num = 1;

    //행 체크 (행당 하나씩 들어가게 짜서 필요없지만 직관성을 위해 넣음)
    for(i = 0; i < 8; i++) {
        if(arr[i][y] == 1) {
            ret_num = 0;
        }
    }

    //열 체크
    for(j = 0; j < 8; j++) {
        if(arr[x][j] == 1) {
            ret_num = 0;
        }
    }

    //대각선 체크
    if(x >= y) {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(i - j == x - y) {
                    ret_num = 0;
                }
            }
        }
    }
    else {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(j - i == y - x) {
                    if(arr[i][j] == 1) {
                        ret_num = 0;
                    }
                }
            }
        }
    }
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(i + j == x + y) {
                if(arr[i][j] == 1) {
                    ret_num = 0;
                }
            }
        }
    }

    if(ret_num == 0) {
        printf("[%d, %d]에는 놓을 수 없습니다\n\n", x, y);
        showtable();
    }
    else {
        arr[x][y] == 1;
        printf("[%d, %d]에는 놓을 수 없습니다\n\n", x, y);
        showtable();
    }
    arr[x][y] == 0;
    return ret_num;
}

int check(int depth) {
    if(depth == 8) {
        cnt++; //가능한 판의 개수 한개 추가
        printf("\n----성립(%02d)----\n", cnt);
        showtable();
        printf("\n");
        getchar(); //입력대기
        return 1;
    }

    for(int i = 0; i < 8; i++) {
        if(able(i, depth) == 1) {
            arr[i][depth] = 1;
            check(depth + 1);
        }
        arr[i][depth] = 0;
    }
    return 0;
}

int main(void) {
    srand((unsigned int)time(NULL));
    
    while(1) {
        isAble(rand()%8, rand()%8);
        getchar();
    }

    check(0);

    printf("가능한 배열의 수 : %d\n", cnt);
}
*/

#include <stdio.h>
#include <algorithm>
 
int n, res;
int map[15];
 
bool isPromising(int r,int c) {
    for (int i = 1; i < r; i++) {
        // 세로상에 놓여있는지
        if (map[i] == c) return false;
        // 대각선상에 놓여있는지
        if (abs(r - i) == abs(map[i] - c)) return false;
    }
    return true;
}
 
//디버깅용
void printBoard() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i] == j) printf("o ");
            else printf("x ");
        }
        printf("\n");
    }
    printf("\n");
}
 
void dfs(int r, int c) {
 
    map[r] = c;
    if (r == n) {
        //printBoard();
        res++;
    }
    else {
        for (int i = 1; i <= n; i++) {
            if(isPromising(r + 1, i)) {
                dfs(r + 1, i);
            }
        }
    }
    map[r] = 0;
}
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        dfs(1, i);
    }
    printf("%d\n", res);
}
