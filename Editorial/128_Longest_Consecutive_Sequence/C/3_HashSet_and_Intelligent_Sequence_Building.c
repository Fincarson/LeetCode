// Define the structure for the hash table to represent the set
typedef struct {
    int key;            // the key here is the number itself
    UT_hash_handle hh;  // makes this structure hashable
} IntHash;

// Function to add a number to the hash set
void add_to_set(IntHash **s, int num) {
    IntHash *element;
    HASH_FIND_INT(*s, &num, element);
    if (element == NULL) {
        element = (IntHash *)malloc(sizeof(IntHash));
        element->key = num;
        HASH_ADD_INT(*s, key, element);
    }
}

// Function to check if a number exists in the set
int set_contains(IntHash *s, int num) {
    IntHash *element;
    HASH_FIND_INT(s, &num, element);
    return element != NULL;
}

// Function to find the longest consecutive sequence
int longestConsecutive(int *nums, int numsSize) {
    IntHash *num_set = NULL;

    // Insert all numbers into the set
    for (int i = 0; i < numsSize; i++) {
        add_to_set(&num_set, nums[i]);
    }

    int longestStreak = 0;

    // Iterate over all numbers in the set
    for (IntHash *it = num_set; it != NULL; it = it->hh.next) {
        int num = it->key;
        // Start a new sequence if there's no preceding element
        if (!set_contains(num_set, num - 1)) {
            int currentNum = num;
            int currentStreak = 1;
            // Continue the sequence while consecutive elements are found
            while (set_contains(num_set, currentNum + 1)) {
                currentNum++;
                currentStreak++;
            }
            // Update the longest streak found
            if (currentStreak > longestStreak) {
                longestStreak = currentStreak;
            }
        }
    }

    // Clean up the hash table
    IntHash *current_item, *tmp;
    HASH_ITER(hh, num_set, current_item, tmp) {
        HASH_DEL(num_set,
                 current_item);  // delete it (num_set advances to next)
        free(current_item);      // free it
    }
    return longestStreak;
}
