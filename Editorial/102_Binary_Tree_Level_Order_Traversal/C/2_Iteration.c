int** levelOrder(struct TreeNode* root, int* returnSize,
                 int** returnColumnSizes) {
    *returnSize = 0;
    if (!root) return NULL;
    typedef struct Node {
        void* data;
        struct Node* next;
    } Node;
    typedef struct Queue {
        Node* head;
        Node* tail;
    } Queue;
    Queue* createQueue() {
        Queue* queue = malloc(sizeof(Queue));
        queue->head = queue->tail = NULL;
        return queue;
    }
    void push(Queue * queue, void* data) {
        Node* node = malloc(sizeof(Node));
        node->data = data;
        node->next = NULL;
        if (queue->head == NULL) {
            queue->head = queue->tail = node;
        } else {
            queue->tail = queue->tail->next = node;
        }
    }
    void* pop(Queue * queue) {
        if (!queue->head) return NULL;
        Node* head = queue->head;
        void* data = head->data;
        queue->head = queue->head->next;
        if (queue->head == NULL) queue->tail = NULL;
        free(head);
        return data;
    }
    size_t size(Queue * queue) {
        size_t count = 0;
        for (Node* node = queue->head; node; node = node->next) count++;
        return count;
    }
    int isEmpty(Queue * queue) { return queue->head == NULL; }
    Queue* queue = createQueue();
    push(queue, root);
    int** levels = malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
    while (!isEmpty(queue)) {
        int level_size = size(queue);
        levels[*returnSize] = malloc(sizeof(int) * level_size);
        (*returnColumnSizes)[*returnSize] = level_size;
        for (int i = 0; i < level_size; i++) {
            struct TreeNode* node = pop(queue);
            levels[*returnSize][i] = node->val;
            if (node->left) push(queue, node->left);
            if (node->right) push(queue, node->right);
        }
        (*returnSize)++;
    }
    return levels;
}
