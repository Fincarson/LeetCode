#define MIN_QUEUE_SIZE 64

typedef struct Element {
    int data[2];
} Element;

typedef bool (*compare)(const void*, const void*);

typedef struct PriorityQueue {
    Element* arr;
    int capacity;
    int queueSize;
    compare lessFunc;
} PriorityQueue;

Element* createElement(int x, int y) {
    Element* obj = (Element*)malloc(sizeof(Element));
    obj->data[0] = x;
    obj->data[1] = y;
    return obj;
}

static bool less(const void* a, const void* b) {
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;
    return e1->data[0] > e2->data[0];
}

static bool greater(const void* a, const void* b) {
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;
    return e1->data[0] < e2->data[0];
}

static void memswap(void* m1, void* m2, size_t size) {
    unsigned char* a = (unsigned char*)m1;
    unsigned char* b = (unsigned char*)m2;
    while (size--) {
        *b ^= *a ^= *b ^= *a;
        a++;
        b++;
    }
}

static void swap(Element* arr, int i, int j) {
    memswap(&arr[i], &arr[j], sizeof(Element));
}

static void down(Element* arr, int size, int i, compare cmpFunc) {
    for (int k = 2 * i + 1; k < size; k = 2 * k + 1) {
        if (k + 1 < size && cmpFunc(&arr[k], &arr[k + 1])) {
            k++;
        }
        if (cmpFunc(&arr[k], &arr[(k - 1) / 2])) {
            break;
        }
        swap(arr, k, (k - 1) / 2);
    }
}

PriorityQueue* createPriorityQueue(compare cmpFunc) {
    PriorityQueue* obj = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    obj->capacity = MIN_QUEUE_SIZE;
    obj->arr = (Element*)malloc(sizeof(Element) * obj->capacity);
    obj->queueSize = 0;
    obj->lessFunc = cmpFunc;
    return obj;
}

void heapfiy(PriorityQueue* obj) {
    for (int i = obj->queueSize / 2 - 1; i >= 0; i--) {
        down(obj->arr, obj->queueSize, i, obj->lessFunc);
    }
}

void enQueue(PriorityQueue* obj, Element* e) {
    // we need to alloc more space, just twice space size
    if (obj->queueSize == obj->capacity) {
        obj->capacity *= 2;
        obj->arr = realloc(obj->arr, sizeof(Element) * obj->capacity);
    }
    memcpy(&obj->arr[obj->queueSize], e, sizeof(Element));
    for (int i = obj->queueSize;
         i > 0 && obj->lessFunc(&obj->arr[(i - 1) / 2], &obj->arr[i]);
         i = (i - 1) / 2) {
        swap(obj->arr, i, (i - 1) / 2);
    }
    obj->queueSize++;
}

Element* deQueue(PriorityQueue* obj) {
    swap(obj->arr, 0, obj->queueSize - 1);
    down(obj->arr, obj->queueSize - 1, 0, obj->lessFunc);
    Element* e = &obj->arr[obj->queueSize - 1];
    obj->queueSize--;
    return e;
}

bool isEmpty(const PriorityQueue* obj) { return obj->queueSize == 0; }

Element* front(const PriorityQueue* obj) {
    if (obj->queueSize == 0) {
        return NULL;
    } else {
        return &obj->arr[0];
    }
}

void clear(PriorityQueue* obj) { obj->queueSize = 0; }

int size(const PriorityQueue* obj) { return obj->queueSize; }

void freeQueue(PriorityQueue* obj) {
    free(obj->arr);
    free(obj);
}

typedef struct AdjNode {
    int vertex;
    int weight;
    struct AdjNode* next;
} AdjNode;

typedef struct {
    AdjNode** lists;
    int n;
} Graph;

AdjNode* createAdjNode(int vertex, int weight) {
    AdjNode* newNode = (AdjNode*)malloc(sizeof(AdjNode));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->n = n;
    graph->lists = (AdjNode**)malloc(n * sizeof(AdjNode*));
    for (int i = 0; i < n; i++) {
        graph->lists[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    AdjNode* newNode = createAdjNode(dest, weight);
    newNode->next = graph->lists[src];
    graph->lists[src] = newNode;

    AdjNode* reverseNode = createAdjNode(src, 2 * weight);
    reverseNode->next = graph->lists[dest];
    graph->lists[dest] = reverseNode;
}

void freeGraph(Graph* graph) {
    if (!graph) return;

    for (int i = 0; i < graph->n; i++) {
        AdjNode* current = graph->lists[i];
        while (current) {
            AdjNode* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(graph->lists);
    free(graph);
}

int minCost(int n, int** edges, int edgesSize, int* edgesColSize) {
    Graph* graph = createGraph(n);
    for (int i = 0; i < edgesSize; i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        int weight = edges[i][2];
        addEdge(graph, src, dest, weight);
    }

    int* dist = (int*)malloc(n * sizeof(int));
    bool* visited = (bool*)calloc(n, sizeof(bool));
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    PriorityQueue* pq = createPriorityQueue(less);

    Element startElem;
    startElem.data[0] = 0;
    startElem.data[1] = 0;
    enQueue(pq, &startElem);

    while (!isEmpty(pq)) {
        Element* current = front(pq);
        int currentDist = current->data[0];
        int x = current->data[1];
        deQueue(pq);

        if (x == n - 1) {
            int result = currentDist;
            free(dist);
            free(visited);
            freeQueue(pq);
            freeGraph(graph);
            return result;
        }
        if (visited[x]) {
            continue;
        }

        visited[x] = true;
        for (AdjNode* neighbor = graph->lists[x]; neighbor != NULL;
             neighbor = neighbor->next) {
            int y = neighbor->vertex;
            int w = neighbor->weight;
            if (currentDist + w < dist[y]) {
                dist[y] = currentDist + w;

                Element newElem;
                newElem.data[0] = dist[y];
                newElem.data[1] = y;
                enQueue(pq, &newElem);
            }
        }
    }

    free(dist);
    free(visited);
    freeQueue(pq);
    freeGraph(graph);

    return -1;
}
