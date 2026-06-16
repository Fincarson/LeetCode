struct Node *cloneGraph(struct Node *node) {
    if (!node) {
        return NULL;
    }
    // Hash map to save the visited node and it's respective clone
    // as key and value respectively. This helps to avoid cycles.
    struct Node *visited[101] = {NULL};
    // Put the first node in the queue
    struct Node **queue = calloc(101, sizeof(struct Node *));
    queue[0] = node;
    int front = 0;
    int rear = 1;
    // create a new Node
    struct Node *cloneNode = calloc(1, sizeof(struct Node));
    cloneNode->val = node->val;
    cloneNode->numNeighbors = node->numNeighbors;
    // use this created node
    visited[node->val] = cloneNode;
    while (front != rear) {
        struct Node *oldNode = queue[front++];
        struct Node *newNode = visited[oldNode->val];
        // copy the neighbors
        newNode->neighbors =
            calloc(newNode->numNeighbors, sizeof(struct Node *));
        for (int i = 0; i < newNode->numNeighbors; i++) {
            struct Node *oldNeighbor = oldNode->neighbors[i];
            if (visited[oldNeighbor->val]) {
                newNode->neighbors[i] = visited[oldNeighbor->val];
            } else {
                queue[rear++] = oldNeighbor;
                struct Node *newNeighbor = calloc(1, sizeof(struct Node));
                newNeighbor->val = oldNeighbor->val;
                newNeighbor->numNeighbors = oldNeighbor->numNeighbors;
                newNode->neighbors[i] = visited[oldNeighbor->val] = newNeighbor;
            }
        }
    }
    free(queue);
    return visited[node->val];
}
