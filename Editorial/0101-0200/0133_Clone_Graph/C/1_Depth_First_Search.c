/*
// Definition for a Node.
struct Node {
    int val;
    struct Node** neighbors;
    int numNeighbors;
};
*/
#define MAX_SIZE 101
struct Node* newNode(int val) {
    struct Node* node = malloc(sizeof(struct Node));
    node->val = val;
    node->neighbors = malloc(MAX_SIZE * sizeof(struct Node*));
    node->numNeighbors = 0;
    return node;
}
struct HashTable {
    struct Node* key;
    struct Node* val;
    UT_hash_handle hh;
};
struct HashTable* visited = NULL;
void add(struct Node* keyNode, struct Node* valNode) {
    struct HashTable* s;
    HASH_FIND_PTR(visited, &keyNode, s);
    if (s == NULL) {
        s = (struct HashTable*)malloc(sizeof *s);
        s->key = keyNode;
        s->val = valNode;
        HASH_ADD_PTR(visited, key, s);
    }
}
struct Node* find(struct Node* keyNode) {
    struct HashTable* s;
    HASH_FIND_PTR(visited, &keyNode, s);
    return s ? s->val : NULL;
}
struct Node* cloneGraph(struct Node* node) {
    if (node == NULL) {
        return node;
    }
    struct Node* cloneNode = find(node);
    if (cloneNode) {
        return cloneNode;
    }
    cloneNode = newNode(node->val);
    add(node, cloneNode);
    for (int i = 0; i < node->numNeighbors; i++) {
        cloneNode->neighbors[cloneNode->numNeighbors++] =
            cloneGraph(node->neighbors[i]);
    }
    return cloneNode;
}
