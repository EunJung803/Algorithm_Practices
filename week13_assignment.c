#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphType {
    int n; //정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

//그래프 초기화
void init(GraphType* g) {
    int r, c;
    g->n = 0;
    for(r = 0; r<MAX_VERTICES; r++)
        for(c = 0; c<MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}

//정점 삽입 연산
void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

//간선 삽입 연산
void insert_edge(GraphType* g, int start, int end) {
    if(start >= g->n || end >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void dfs_mat(GraphType* g, int v) {
    int w;
    visited[v] = TRUE;              //정점 v의 방문 표시
    printf("정점 %d -> ", v);       //방문한 정점 출력
    for(w = 0; w < g->n; w++)       //인접 정점 탐색
        if(g->adj_mat[v][w] && !visited[w])
            dfs_mat(g, w);          //정점 w에서 DFS 새로 시작
}

int main(void) {
    GraphType*g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for(int i = 0; i < 8; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 7);
    insert_edge(g, 0, 6);
    insert_edge(g, 0, 1);
    insert_edge(g, 7, 1);
    insert_edge(g, 7, 6);
    insert_edge(g, 1, 6);
    insert_edge(g, 6, 5);
    insert_edge(g, 5, 4);
    insert_edge(g, 2, 5);
    insert_edge(g, 5, 4);
    insert_edge(g, 4, 3);
    insert_edge(g, 3, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 0);

    int n;
    printf("시작할 정점을 입력해주세요 : ");
    scanf("%d", &n);
    dfs_mat(g, n);
    printf("정점 %d", n);
    printf("\n");
    free(g);
    return 0;
}