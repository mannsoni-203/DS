#include <stdio.h>
#define MAX 20

int graph[MAX][MAX], visited[MAX], n;

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i])
            DFS(i);
    }
}

void BFS(int start) {
    int q[MAX], front = 0, rear = 0;
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    q[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        v = q[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                q[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 0;
    }

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting vertex.\n");
        return 0;
    }

    printf("DFS: ");
    for (i = 0; i < n; i++) visited[i] = 0;
    DFS(start);

    printf("\nBFS: ");
    BFS(start);

    printf("\n");
    return 0;
}
