#include <stdio.h>
#define MAX_SIZE 5

void quick_sort(int list[], int left, int right)
{
    if(left < right) {
        int q = partition(list, left, right);
        print_list(list, MAX_SIZE);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);
    }
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int list[], int left, int right)
{
    int pivot;
    int low = left, high = right + 1;

    pivot = list[left];
    do {
        do
        {
            low++;
        } while(low <= right && list[low] < pivot);
        do
        {
            high--;
        } while (high >= left && list[high] > pivot);
        if (low < high)
            swap(&list[low], &list[high]);
    } while(low < high);

    swap(&list[left], &list[high]);

    return high;
}

void print_list(int list[], int n) {
     int i;
     for (i = 0; i < n; i++) {
        printf("%d ", list[i]);
     }
     printf("\n");
}

int calculate(int list[])
{
    int answer = 0;
    int a = 1;

    for(int i = 0; i < MAX_SIZE; i++) {
        answer = answer + (list[i])*a;
        a = -a;
    }
    printf("%d\n", answer);
    
}

int main()
{
    int list[MAX_SIZE];
    int size;
    int n;

    printf("정렬할 배열의 크기를 입력하세요.\n");  //5
    scanf("%d", &size);

    for(n = 0; n < size; n++) {
        printf("정렬할 배열의 %d번째 수를 입력하세요 : ", n+1);  //3 5 1 8 4
        scanf("%d", &list[n]);
    }

    printf("\n퀵정렬 전 데이터 \n");
    print_list(list, MAX_SIZE);
    printf("\n");

    printf("퀵정렬 과정 \n");
    quick_sort(list, 0, MAX_SIZE-1);
    printf("\n");

    printf("퀵정렬 후 데이터 \n");  // 1 3 4 5 8
    print_list(list, MAX_SIZE);
    printf("\n");

    printf("연산 결과 = ");
    calculate(list);

}