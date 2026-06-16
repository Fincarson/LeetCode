struct hash_table {
    char key[2];
    int (*value)(int, int);
    UT_hash_handle hh;
};

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

struct hash_table *create_hash_table() {
    struct hash_table *s, *hash_table = NULL;
    int (*functions[4])(int, int) = {add, sub, mult, divide};
    char *keys[4] = {"+", "-", "*", "/"};

    for (int i = 0; i < 4; i++) {
        s = malloc(sizeof(struct hash_table));
        strncpy(s->key, keys[i], 2);
        s->value = functions[i];
        HASH_ADD_STR(hash_table, key, s);
    }

    return hash_table;
}

int evalRPN(char **tokens, int tokens_size) {
    struct hash_table *hash_table = create_hash_table();
    struct hash_table *s;
    int currentPosition = 0;
    int *stack = calloc(tokens_size, sizeof(int));
    int top = -1;

    while (currentPosition < tokens_size) {
        HASH_FIND_STR(hash_table, tokens[currentPosition], s);
        if (s == NULL) {
            stack[++top] = atoi(tokens[currentPosition++]);
        } else {
            int a = stack[top--];
            int b = stack[top--];
            stack[++top] = s->value(b, a);
            currentPosition++;
        }
    }

    int result = stack[top];
    free(stack);
    HASH_CLEAR(hh, hash_table);
    return result;
}
