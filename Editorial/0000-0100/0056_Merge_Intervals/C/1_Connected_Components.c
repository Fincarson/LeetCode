#define MAX_INTERVALS 10000

typedef struct Node {
    int index;  // Index of the interval in the original list
    struct Node* next;
} Node;

typedef struct {
    Node* edges[MAX_INTERVALS];  // Adjacency list
    int visited[MAX_INTERVALS];  // Visited nodes
    int num_intervals;
} Graph;

void addEdge(Graph* g, int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = v;
    node->next = g->edges[u];
    g->edges[u] = node;
}

bool overlap(int* a, int* b) { return a[0] <= b[1] && b[0] <= a[1]; }

void buildGraph(Graph* g, int** intervals, int size) {
    g->num_intervals = size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j && overlap(intervals[i], intervals[j])) {
                addEdge(g, i, j);
            }
        }
    }
}

int* mergeNodes(Graph* g, int start, int** intervals, int* returnSize) {
    int* stack = malloc(g->num_intervals * sizeof(int));
    int top = 0;
    stack[top] = start;
    g->visited[start] = 1;

    int min_start = intervals[start][0];
    int max_end = intervals[start][1];

    while (top >= 0) {
        int node_index = stack[top--];
        Node* node = g->edges[node_index];
        while (node) {
            int idx = node->index;
            if (!g->visited[idx]) {
                g->visited[idx] = 1;
                min_start = (min_start < intervals[idx][0]) ? min_start
                                                            : intervals[idx][0];
                max_end =
                    (max_end > intervals[idx][1]) ? max_end : intervals[idx][1];
                stack[++top] = idx;
            }
            node = node->next;
        }
    }

    free(stack);
    *returnSize = 2;
    int* merged = malloc(2 * sizeof(int));
    merged[0] = min_start;
    merged[1] = max_end;
    return merged;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {
    Graph g = {0};
    buildGraph(&g, intervals, intervalsSize);

    int** merged = malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = malloc(intervalsSize * sizeof(int));

    int count = 0;
    for (int i = 0; i < intervalsSize; i++) {
        if (!g.visited[i]) {
            int size;
            merged[count] = mergeNodes(&g, i, intervals, &size);
            (*returnColumnSizes)[count] = size;
            count++;
        }
    }

    *returnSize = count;
    for (int i = 0; i < g.num_intervals; i++) {
        Node* node = g.edges[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }

    return merged;
}
