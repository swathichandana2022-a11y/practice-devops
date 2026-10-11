#include <stdio.h>
#define MAX 10
#define INF 9999
int main() {
    int n, i, j, u, v, min,src;
    int cost[MAX][MAX], dist[MAX], visited[MAX];
    printf("Enter number of nodes: "); //linkstaterouting
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("Enter source node: ");
    scanf("%d", &src);
    for(i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }
    visited[src] = 1;
    for(i = 1; i < n; i++) {
        min = INF;
        for(j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        visited[u] = 1;
        for(v = 0; v < n; v++) {
            if(!visited[v] && dist[v] > dist[u] + cost[u][v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }
    printf("\nShortest paths from node %d:\n", src);
    for(i = 0; i < n; i++) {
        printf("To %d -> Distance = %d\n", i, dist[i]);
    }
    return 0;
}
