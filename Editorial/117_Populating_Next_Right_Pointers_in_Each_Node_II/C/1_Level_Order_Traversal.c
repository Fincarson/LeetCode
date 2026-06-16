struct QueueNode {
    struct Node* node;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
    int size;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    struct QueueNode* temp =
        (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->node = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;

    struct QueueNode* temp = q->front;
    struct Node* node = temp->node;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    q->size--;
    return node;
}

int isEmpty(struct Queue* q) { return q->front == NULL; }

struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return root;
    }
    // Initialize a queue data structure which contains
    // just the root of the tree
    struct Queue* Q = createQueue();
    enqueue(Q, root);
    // Outer while loop which iterates over
    // each level
    while (!isEmpty(Q)) {
        // Note the size of the queue
        int size = Q->size;
        // Iterate over all the nodes on the current level
        for (int i = 0; i < size; i++) {
            // Pop a node from the front of the queue
            struct Node* node = dequeue(Q);
            // This check is important. We don't want to
            // establish any wrong connections. The queue will
            // contain nodes from 2 levels at most at any
            // point in time. This check ensures we only
            // don't establish next pointers beyond the end
            // of a level
            if (i < size - 1) {
                node->next = Q->front->node;
            }
            // Add the children, if any, to the back of
            // the queue
            if (node->left != NULL) {
                enqueue(Q, node->left);
            }
            if (node->right != NULL) {
                enqueue(Q, node->right);
            }
        }
    }
    free(Q);
    // Since the tree has now been modified, return the root node
    return root;
}
