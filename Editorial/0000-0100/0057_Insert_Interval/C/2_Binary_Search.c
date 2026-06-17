// struct for list node
typedef struct list_node {
    int interval[2];
    struct list_node* next;
} list_node;

int** insert(int** intervals, int intervalsSize, int* intervalsColSize,
             int* newInterval, int newIntervalSize, int* returnSize,
             int** returnColumnSizes) {
    // If the intervals vector is empty, return a vector containing the
    // newInterval
    if (intervalsSize == 0) {
        *returnSize = 1, *returnColumnSizes = malloc(sizeof(int));
        **returnColumnSizes = 2;
        int** ans = malloc(sizeof(int*));
        *ans = malloc(2 * sizeof(int));
        memcpy(*ans, newInterval, 2 * sizeof(int));
        return ans;
    }

    int n = intervalsSize;
    int target = newInterval[0];
    int left = 0, right = n - 1;

    // Binary search to find the position to insert newInterval
    while (left <= right) {
        int mid = (left + right) / 2;
        if (intervals[mid][0] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Insert newInterval at the found position
    list_node* head = NULL;
    list_node** next_ptr = &head;
    for (int i = 0; i < left; ++i) {
        *next_ptr = malloc(sizeof(list_node));
        (*next_ptr)->next = NULL;
        memcpy((*next_ptr)->interval, intervals[i], 2 * sizeof(int));
        next_ptr = &((*next_ptr)->next);
    }
    *next_ptr = malloc(sizeof(list_node));
    (*next_ptr)->next = NULL;
    memcpy((*next_ptr)->interval, newInterval, 2 * sizeof(int));
    next_ptr = &((*next_ptr)->next);
    for (int i = left; i < n; ++i) {
        *next_ptr = malloc(sizeof(list_node));
        (*next_ptr)->next = NULL;
        memcpy((*next_ptr)->interval, intervals[i], 2 * sizeof(int));
        next_ptr = &((*next_ptr)->next);
    }

    // Merge overlapping intervals
    int** res_data = malloc(1001 * sizeof(int*));
    int* res_sizes = malloc(1001 * sizeof(int));
    int res_size = 0;
    for (list_node* node = head; node != NULL; node = node->next) {
        int* interval = node->interval;
        // If res is empty or there is no overlap, add the interval to the
        // result
        if (res_size == 0 || res_data[res_size - 1][1] < interval[0]) {
            res_data[res_size] = malloc(2 * sizeof(int));
            memcpy(res_data[res_size], interval, 2 * sizeof(int));
            res_sizes[res_size] = 2;
            ++res_size;
            // If there is an overlap, merge the intervals by updating the end
            // of the last interval in res
        } else {
            res_data[res_size - 1][1] =
                (res_data[res_size - 1][1] < interval[1])
                    ? interval[1]
                    : res_data[res_size - 1][1];
        }
    }
    *returnSize = res_size, *returnColumnSizes = res_sizes;

    return res_data;
}
