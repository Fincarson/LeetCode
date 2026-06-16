typedef struct {
    int* data;     // Stack for the actual data
    int* minData;  // Stack for the minimum values
    int* count;    // Stack for counting occurrences of minimum values
    int top;       // Top index for the data stack
    int minTop;    // Top index for the minimum stack
    int capacity;  // Capacity for all stacks
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 10;  // Initial capacity, can be grown as needed
    obj->data = (int*)malloc(obj->capacity * sizeof(int));
    obj->minData = (int*)malloc(obj->capacity * sizeof(int));
    obj->count = (int*)malloc(obj->capacity * sizeof(int));
    obj->top = -1;
    obj->minTop = -1;
    return obj;
}

void resizeStacks(MinStack* obj) {
    if (obj->top + 1 >= obj->capacity) {
        obj->capacity *= 2;
        obj->data = (int*)realloc(obj->data, obj->capacity * sizeof(int));
        obj->minData = (int*)realloc(obj->minData, obj->capacity * sizeof(int));
        obj->count = (int*)realloc(obj->count, obj->capacity * sizeof(int));
    }
}

void minStackPush(MinStack* obj, int val) {
    resizeStacks(obj);
    obj->data[++obj->top] = val;
    if (obj->minTop == -1 || val < obj->minData[obj->minTop]) {
        obj->minData[++obj->minTop] = val;
        obj->count[obj->minTop] = 1;
    } else if (val == obj->minData[obj->minTop]) {
        obj->count[obj->minTop]++;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->data[obj->top] == obj->minData[obj->minTop]) {
        obj->count[obj->minTop]--;
        if (obj->count[obj->minTop] == 0) {
            obj->minTop--;
        }
    }
    obj->top--;
}

int minStackTop(MinStack* obj) { return obj->data[obj->top]; }

int minStackGetMin(MinStack* obj) { return obj->minData[obj->minTop]; }

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->minData);
    free(obj->count);
    free(obj);
}
