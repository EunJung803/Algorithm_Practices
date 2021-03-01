#include <stdio.h>

#include <string.h>

#include <math.h>

 

const int MAX_NODE = 16;

const double INF = MAX_NODE * 1500.0; 

 

#define min(a,b) ((a)<(b)?(a):(b))

 

double cost[MAX_NODE][MAX_NODE];

// 중간 해를 저장할 공간. dp[from][경로(도시들의 집합)]

double dp[MAX_NODE][1<<16];

 

int bitarr[MAX_NODE];

 

double tsp(int from, int path, int len)

{

if (len == 1) {

int to = (int)log2(path);

return cost[from][to];

}

// 저장한 값을 이용

if (dp[from][path]) {

return dp[from][path];

}

 

double ans = INF;

 

for(int i = 1; i < MAX_NODE; i++)

{

if (bitarr[i] & path) 

{

int node = bitarr[i];

// 새로운 경로는 목적지 node를 제외한 나머지 도시들

int npath = (path & ~node);

// 다음 목적지 지정. node는 2^n 값만 존재

   int to = (int)log2(node);

// f(N,{N-1,N-2...1}) = cost[N][N-1] + f(N-1, {N-2,N-3...1})

double fcost = tsp(to, npath, len-1);

double newcost = cost[from][to] + fcost;

 

ans = min(ans, newcost);

}

}

// 최소비용을 저장

dp[from][path] = ans;

 

return ans;

}

 

int main()

{

int t, N;

// bit에서의 도시 위치를 배열에 저장

// bit[1] = 0000 0001 ==> 1번 도시를 표시

// bit[2] = 0000 0010 ==> 2번 도시를 표시

// bit[3] = 0000 0100 ==> 3번 도시를 표시

//...

for(int i = 1; i < MAX_NODE; i++) {

bitarr[i] = 1<<i;

}

 

scanf("%d", &t);

 

while(t--)

{

// 도시간 비용 입력

scanf("%d", &N);

 

for(int i = 1; i <= N; i++) 

{

for(int j = 1; j <= N; j++) {

scanf("%lf", &cost[i][j]);

}

}

 

double ans = INF, result = 0.0; 

 

memset(dp, 0, sizeof(dp));

 

int path = 0;

// 경로 저장. path에는 모든 도시가 저장됨

for(int i = 1; i <= N; i++) 

{

path |= 1<<i;

}

// 출발지점을 차례대로 바꿔서 해를 구한다.

for(int i=1; i<=N; i++) {

int npath = (path & ~bitarr[i]);

result = tsp(i, npath, N-1);

ans = min(ans, result);

}

 

printf("%.10lf\n", ans);

}

 

return 0;

}