#include <stdio.h>
#include <stdbool.h>

int n, ans;
int check[15];
  
bool checkingPromissing(int a, int b) {
    for (int i = 1; i < a; i++) {
        if (check[i] == b) { // 세로상에 놓여있는지 확인
            return false;
        }
        if (abs(a - i) == abs(check[i] - b)) { // 대각선상에 놓여있는지 확인
            return false;
        }
    }
    return true;
}

void show_board() {
    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (check[i] == j) {
                printf("[✔] ");
            }
            else {
                printf("[x] ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
 
void search(int r, int c) {
 
    check[r] = c;
    if (r == n) {
        show_board();
        ans++;
    }
    else {
        for (int i = 1; i <= n; i++) {
            if(checkingPromissing(r + 1, i)) {
                search(r + 1, i);
            }
        }
    }
    check[r] = 0;
}
 
int main() {
    printf("n x n 크기의 체스판을 위해 n값을 입력해주세요 (1 <= n <= 30) : ");
    scanf("%d", &n);
    if(n < 0 || n > 30) {
        printf("n이 범위를 벗어났습니다.");
        return 0;
    }
    else {
        printf("\nQueen을 놓을 수 있는 곳 = ✔\n");
        for (int i = 1; i <= n; i++) {
            search(1, i);
        }
        printf(">> 경우의 수 = %d\n", ans);
    }
}
