#include <stdio.h>
#define MAX_NUM 100000
int sort_list[MAX_NUM];

void merge(int list[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while(i <= mid && j <= right) {
        if(list[i] <= list[j]) {
            sort_list[k] = list[i];
            i++;
        }
        else if(list[i] > list[j]) {
            sort_list[k] = list[j];
            j++;
        }
        k++;
    }

    if(i > mid) {
        for(int p = j; p <= right; p++) {
            sort_list[k] = list[p];
            k++;
        }
    }
    else {
        for(int p = i; p <= mid; p++) {
            sort_list[k] = list[p];
            k++;
        }
    }

    for(int q = left; q <= right; q++) {
        list[q] = sort_list[q];
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

void print_array(int list[], int n) {
     int i;
     for (i = 0; i < n; i++) {
        printf("%d ", list[i]);
     }
     printf("\n");
}

int main(void) {
    int a;
    int n;
    int list[MAX_NUM];

    printf("정렬할 배열의 크기를 입력하세요.\n");
    scanf("%d", &a);

    for(n = 0; n < a; n++) {
        printf("정렬할 배열의 %d번째 수를 입력하세요 : ", n+1);
        scanf("%d", &list[n]);
    }

    merge_sort(list, 0, a-1);

    print_array(list, a);
}