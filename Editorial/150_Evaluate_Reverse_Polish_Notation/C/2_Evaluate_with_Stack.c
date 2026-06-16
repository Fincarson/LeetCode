// enum for operations
typedef enum { ADD, SUBTRACT, DIVIDE, MULTIPLY, UNKNOWN } Operation;

struct my_struct {
    const char* id;
    Operation op_id;
    UT_hash_handle hh;
};

int perform_operation(Operation op_id, int a, int b) {
    switch (op_id) {
        case ADD:
            return a + b;
        case SUBTRACT:
            return a - b;
        case DIVIDE:
            return a / b;
        case MULTIPLY:
            return a * b;
        default:
            return 0;
    }
}

int evalRPN(char** tokens, int tokensSize) {
    struct my_struct *operations = NULL, *s;

    // Define the operations
    s = (struct my_struct*)malloc(sizeof *s);
    s->id = "+";
    s->op_id = ADD;
    HASH_ADD_KEYPTR(hh, operations, s->id, strlen(s->id), s);
    s = (struct my_struct*)malloc(sizeof *s);
    s->id = "-";
    s->op_id = SUBTRACT;
    HASH_ADD_KEYPTR(hh, operations, s->id, strlen(s->id), s);
    s = (struct my_struct*)malloc(sizeof *s);
    s->id = "/";
    s->op_id = DIVIDE;
    HASH_ADD_KEYPTR(hh, operations, s->id, strlen(s->id), s);
    s = (struct my_struct*)malloc(sizeof *s);
    s->id = "*";
    s->op_id = MULTIPLY;
    HASH_ADD_KEYPTR(hh, operations, s->id, strlen(s->id), s);

    // Iterate over the tokens
    int* stack = (int*)malloc(tokensSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < tokensSize; ++i) {
        const char* key = tokens[i];
        HASH_FIND_STR(operations, key, s);
        if (s) {
            int op2 = stack[top--];
            int op1 = stack[top--];
            int result = perform_operation(s->op_id, op1, op2);
            stack[++top] = result;
        } else {
            stack[++top] = atoi(tokens[i]);
        }
    }

    int result = stack[0];

    free(stack);
    // Cleanup
    struct my_struct *tmp, *tmp2;
    HASH_ITER(hh, operations, s, tmp) {
        HASH_DEL(operations, s);
        free(s);
    }

    return result;
}
