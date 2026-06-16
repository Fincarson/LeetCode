typedef struct {
    int* data;     // Array to store the stack values
    int* mins;     // Array to store the minimum values
    int top;       // Index of the top element in the stack
    int capacity;  // Maximum number of items the stack can hold
} MinStack;

MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->capacity = 10;  // Initial capacity, can grow as needed
    stack->data = (int*)malloc(stack->capacity * sizeof(int));
    stack->mins = (int*)malloc(stack->capacity * sizeof(int));
    stack->top = -1;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    /* If the stack is full, increase the capacity */
    if (obj->top == obj->capacity - 1) {
        obj->capacity *= 2;
        obj->data = (int*)realloc(obj->data, obj->capacity * sizeof(int));
        obj->mins = (int*)realloc(obj->mins, obj->capacity * sizeof(int));
    }
    /* If the stack is empty, then the min value
     * must just be the first value we add. */
    obj->top++;
    obj->data[obj->top] = val;
    if (obj->top == 0) {
        obj->mins[obj->top] = val;
    } else {
        int currentMin = obj->mins[obj->top - 1];
        obj->mins[obj->top] = (val < currentMin) ? val : currentMin;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top != -1) {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    if (obj->top != -1) {
        return obj->data[obj->top];
    }
    return -1;  // Should handle this error case appropriately in real
                // applications
}

int minStackGetMin(MinStack* obj) {
    if (obj->top != -1) {
        return obj->mins[obj->top];
    }
    return -1;  // Should handle this error case appropriately in real
                // applications
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->mins);
    free(obj);
}
