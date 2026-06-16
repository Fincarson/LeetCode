// Struct to hold key-value pairs
typedef struct {
    char* key;          // key (sorted string)
    char** values;      // list of original strings
    int size;           // number of elements
    int capacity;       // allocated capacity
    UT_hash_handle hh;  // makes this structure hashable
} AnagramGroup;

// Function to compare strings for qsort
int charcmp(const void* a, const void* b) {
    char ca = *(const char*)a;
    char cb = *(const char*)b;
    return (ca > cb) - (ca < cb);
}

// Function to add anagrams to the hash table
void add_anagram(AnagramGroup** groups, const char* key, const char* value) {
    AnagramGroup* s;

    HASH_FIND_STR(*groups, key, s);  // try to find group in hash table
    if (s == NULL) {
        s = malloc(sizeof(AnagramGroup));
        s->key = strdup(key);
        s->capacity = 10;
        s->size = 0;
        s->values = malloc(sizeof(char*) * s->capacity);
        HASH_ADD_KEYPTR(hh, *groups, s->key, strlen(s->key), s);
    }

    if (s->size >= s->capacity) {  // resize array if necessary
        s->capacity *= 2;
        s->values = realloc(s->values, sizeof(char*) * s->capacity);
    }
    s->values[s->size++] = strdup(value);  // add new value
}

// Main function to group anagrams
char*** groupAnagrams(char** strs, int strsSize, int* returnSize,
                      int** returnColumnSizes) {
    AnagramGroup *groups = NULL, *s, *tmp;
    char*** result;

    for (int i = 0; i < strsSize; i++) {
        char* key = strdup(strs[i]);
        qsort(key, strlen(key), sizeof(char), charcmp);  // sort the key
        add_anagram(&groups, key, strs[i]);              // add to hash table
        free(key);  // freeing the sorted key after use
    }

    *returnSize = HASH_COUNT(groups);
    result = malloc(sizeof(char**) * (*returnSize));
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));

    int i = 0;
    HASH_ITER(hh, groups, s, tmp) {
        result[i] = malloc(sizeof(char*) *
                           s->size);  // allocate memory for pointers to strings
        for (int j = 0; j < s->size; j++) {
            result[i][j] =
                s->values[j];  // copy the pointers to the result array
        }
        (*returnColumnSizes)[i] = s->size;
        i++;
    }

    // Freeing groups after copying the data
    HASH_ITER(hh, groups, s, tmp) {
        HASH_DEL(groups, s);  // delete the hash table entry
        free(s->key);         // free the key
        free(s->values);      // free the list of strings
        free(s);              // free the structure
    }

    return result;
}
