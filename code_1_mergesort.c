#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 35
int sorted[MAX_NUM];
int book[MAX_NUM];

void merge(int list[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while(i <= mid && j <= right) {
        if(list[i] <= list[j]) {
            sorted[k] = list[i];
            i++;
        }
        else if(list[i] > list[j]) {
            sorted[k] = list[j];
            j++;
        }
        k++;
    }
    if(i > mid) {
        for(int p = j; p <= right; p++) {
            sorted[k] = list[p];
            k++;
        }
    }
    else {
        for(int p = i; p <= mid; p++) {
            sorted[k] = list[p];
            k++;
        }
    }
    for(int q = left; q <= right; q++) {
        list[q] = sorted[q];
    }
}

void merge_sort(int list[], int left, int right)
{
    int mid;
    if(left < right) {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}

void books(int list[], int day[], int n) {
    int i, part, sub_part;

    printf("어느 구역의 도서 대출 현황을 확인하고 싶습니까?\n");
    printf("( 1 역사 / 2 수리,과학 / 3 문학 / 4 언어 / 5 종교 ) : ");
    scanf("%d", &part);

    if(part <= 0 || part >= 6) {
        printf("범위 외의 영역을 고르셨습니다.\n");
        exit(0);
    }

    printf("\n9월 한달간의 기록입니다.\n");
    for (i = 0; i < n; i++) {   
        printf("9월 %d일 - 대출된 도서 : %d권\n", day[i], book[i]);
    }
    printf("\n");
}

int main(void) {
    int day[MAX_NUM];
    int ask, ask2, n = 30;

    for (int i = 0; i < 30; i++) {
        day[i] = i+1;
    }

    printf("날짜별 대출 현황을 확인하시겠습니까? (예 = 1 / 아니오 = 2) : ");
    scanf("%d", &ask);

    if(ask == 1) {  //확인한다
        srand(time(NULL));        
        for(int i = 0 ; i < n ; i++) {
            book[i] = rand()%100 + 1;
            for(int j = 0; j < i; j++) {
                if(book[i] == book[j]) {
                    i--;
                }
            }
        }
        books(book, day, n);

        merge_sort(book, 0, 29);
        printf("해당 구역에 대한 최소•최다 대출도서 정렬이 완료되었습니다.\n");
        printf("최소 대출 권수 : %d권\n", book[0]);
        printf("최대 대출 권수 : %d권\n", book[29]);

        printf("\n1을 입력하시면 모든 정렬 현황을 보여드립니다. ");
        scanf("%d", &ask2);
        if(ask2 == 1) {
            for (int a = 0; a < 30; a++) {
                printf("%d권 ", book[a]);
            }
            printf("\n");
        }
        else{
            return 0;
        }
    }

    else if(ask == 2) {
        printf("감사합니다.\n");
        return 0;
    }

    else {
        printf("종료\n");
        return 0;
    }
    
}