#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct jewelry {
    int w;  //보석의 무게
    int p;  //보석의 profit
} Jw;

int jw_num, limitWeight;

int fractional(int jw_num, int limitWeight) {   // 쪼갤 수 있다 = greedy

    printf("(분할 O) 보석의 무게와 보석의 가치를 차례대로 입력해주세요\n");
    Jw jw[jw_num];
    for(int i = 0; i < jw_num; i++) {
        scanf("%d %d", &jw[i].w, &jw[i].p);
    }

    int profit[jw_num];
    int temp;
    for(int i = 0; i < jw_num; i++) {
        profit[i] = jw[i].w / jw[i].p;
    }
    for (int i = 0; i < jw_num; i++) {
        for (int j = 0; j < jw_num-1; j++) {
            if (profit[j] > profit[j + 1]) {
                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;
                }
        }
    }

    int result = 0;

    for(int i = 0; i < jw_num; i++) {
        if(limitWeight > 0) {
            if(limitWeight >= jw[i].w) {
                limitWeight -= jw[i].w;
                result += jw[i].p;
            }
            else {  //물건 무게 초과된 경우
                result += jw[i].p / jw[i].w * limitWeight;    //잘라서 넣기
                limitWeight = 0;
            }
        }
        else {
            break;
        }
    }
    printf("(분할 가능한 경우) 최대로 얻을 수 있는 이익 = %d\n", result);
}

int zero_one(int jw_num, int limitWeight, int maxPi[][limitWeight]) {   // 쪼갤 수 없다 = dynamic

    printf("(분할 X) 보석의 무게와 보석의 가치를 차례대로 입력해주세요\n");
    Jw jw[jw_num];
    for(int i = 0; i < jw_num; i++) {
        scanf("%d %d", &jw[i].w, &jw[i].p);
    }

   for(int i = 1; i <= jw_num; i++) {
        for(int j = 0; j <= limitWeight; j++) {
            if(jw[i-1].w > j) {
                maxPi[i][j] = maxPi[i-1][j];            
            }
            else {
                maxPi[i][j] = MAX(maxPi[i-1][j], maxPi[i][j-jw[i-1].w] + jw[i-1].p);
            }
        }
    }
    printf("(분할 불가능 경우) 최대로 얻을 수 있는 이익 = %d\n\n", maxPi[jw_num][limitWeight]);
}

int main(void) {
    Jw jw[jw_num];

    printf("훔칠 보석의 개수를 입력해주세요 : ");
    scanf("%d", &jw_num);

    printf("배낭의 용량을 입력해주세요 : ");
    scanf("%d", &limitWeight);
    printf("\n");
    
    int maxPi[jw_num+1][limitWeight+1];
    for(int i = 0; i < jw_num; i++) {
        maxPi[i][0] = 0;
    }
    for(int i = 0; i < limitWeight; i++) {
        maxPi[0][i] = 0;
    }

    zero_one(jw_num, limitWeight, maxPi);

    fractional(jw_num, limitWeight);

}