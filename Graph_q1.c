#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph
struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to create a new graph with given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    int i, j;

    // Initialize adjacency matrix to all zeros
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Assuming undirected graph
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Depth-First Search traversal
void DFS(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    int i;
    for (i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Breadth-First Search traversal
void BFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        int i;
        for (i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    struct Graph* graph = createGraph(5); // Create a graph with 5 vertices
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    printf("Depth First Traversal: ");
    int visitedDFS[MAX_VERTICES] = {0};
    DFS(graph, 0, visitedDFS);
    printf("\n");

    printf("Breadth First Traversal: ");
    BFS(graph, 0);
    printf("\n");

    return 0;
}
