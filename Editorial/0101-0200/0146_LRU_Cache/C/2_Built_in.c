typedef struct Node {
    int key;
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    int capacity;
    int size;
    Node* head;
    Node* tail;
    struct Node_int* hashTable;
} LRUCache;

typedef struct Node_int {
    int id;
    Node* val;
    UT_hash_handle hh;
} Node_int;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;
    obj->head = NULL;
    obj->tail = NULL;
    obj->hashTable = NULL;
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node_int* tmp;
    HASH_FIND_INT(obj->hashTable, &key, tmp);

    if (tmp == NULL) {
        return -1;
    }

    Node* node = tmp->val;

    if (node != obj->head) {
        if (node == obj->tail) {
            obj->tail = node->prev;
        }

        node->prev->next = node->next;
        if (node->next) {
            node->next->prev = node->prev;
        }

        node->next = obj->head;
        node->prev = NULL;
        obj->head->prev = node;
        obj->head = node;
    }

    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node_int* tmp;
    HASH_FIND_INT(obj->hashTable, &key, tmp);

    if (tmp != NULL) {
        Node* node = tmp->val;
        node->value = value;

        if (node != obj->head) {
            if (node == obj->tail) {
                obj->tail = node->prev;
            }

            node->prev->next = node->next;
            if (node->next) {
                node->next->prev = node->prev;
            }

            node->next = obj->head;
            node->prev = NULL;
            obj->head->prev = node;
            obj->head = node;
        }
    } else {
        Node* node = (Node*)malloc(sizeof(Node));
        node->key = key;
        node->value = value;
        node->prev = NULL;
        node->next = obj->head;
        if (obj->head) {
            obj->head->prev = node;
        }
        obj->head = node;

        Node_int* s = (Node_int*)malloc(sizeof(Node_int));
        s->id = key;
        s->val = node;
        HASH_ADD_INT(obj->hashTable, id, s);

        if (obj->size == obj->capacity) {
            if (obj->tail) {
                Node_int* tmp;
                HASH_FIND_INT(obj->hashTable, &(obj->tail->key), tmp);
                HASH_DEL(obj->hashTable, tmp);
                if (tmp) free(tmp);

                Node* tail = obj->tail;
                obj->tail = tail->prev;
                if (obj->tail) {
                    obj->tail->next = NULL;
                }

                if (tail) free(tail);
            }
        } else if (obj->size < obj->capacity) {
            if (obj->size == 0) {
                obj->tail = node;
            }
            obj->size++;
        }
    }
}

void lRUCacheFree(LRUCache* obj) {
    Node* tmp = obj->head;
    while (tmp) {
        Node* next = tmp->next;
        free(tmp);
        tmp = next;
    }

    Node_int *current_entry, *tmp_entry;
    HASH_ITER(hh, obj->hashTable, current_entry, tmp_entry) {
        HASH_DEL(obj->hashTable, current_entry);
        free(current_entry);
    }

    free(obj);
}
