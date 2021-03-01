/*최소한의 적은 수의 동전으로 거스름돈 거슬러주기
1cent-penny / 5cent-nickle / 10cent-dime / 25cent-quarter / 50cent-half dollar / 100cent-silver dollar
cent단위로 입력받아서 -> 거슬러 받을 동전의 최소 갯수를 출력*/

#include <stdio.h>

int count;


void changeMoney(int cent) {
    int money[6] = {100, 50, 25, 10, 5, 1};

    for(int i = 0; i < 6; i++) {
        while(cent >= money[i]) {
            cent -= money[i];
            count++;
        }
    }

}

int main(void) {
    int cent;

    printf("거슬러 받아야 하는 돈의 액수를 입력하세요 (cent) : ");
    scanf("%d", &cent);

    changeMoney(cent);
    printf("거슬러지는 동전의 개수는 %d 개 입니다.\n", count);

}