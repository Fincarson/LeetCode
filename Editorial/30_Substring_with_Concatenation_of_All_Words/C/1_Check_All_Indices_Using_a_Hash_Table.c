typedef struct {
    char* key;          // key (string)
    int value;          // value (count)
    UT_hash_handle hh;  // makes this structure hashable
} HashTable;

// Function to add or update a word count in the hash table
void add_word_count(HashTable** table, char* word) {
    HashTable* s;
    HASH_FIND_STR(*table, word, s);
    if (s == NULL) {
        s = (HashTable*)malloc(sizeof(HashTable));
        s->key = strdup(word);
        s->value = 1;
        HASH_ADD_KEYPTR(hh, *table, s->key, strlen(s->key), s);
    } else {
        s->value++;
    }
}

// Function to deep copy a hash table
HashTable* hash_table_deep_copy(HashTable* original) {
    HashTable *new_table = NULL, *element, *tmp;
    HASH_ITER(hh, original, element, tmp) {
        HashTable* s = malloc(sizeof(HashTable));
        s->key = strdup(element->key);
        s->value = element->value;
        HASH_ADD_KEYPTR(hh, new_table, s->key, strlen(s->key), s);
    }
    return new_table;
}

// Function to decrement the count in the hash table
int decrement_hash_count(HashTable* table, char* word) {
    HashTable* element;
    HASH_FIND_STR(table, word, element);
    if (element && element->value > 0) {
        element->value--;
        return 1;  // Successfully decremented
    }
    return 0;  // Not found or zero count
}

// Function to free the hash table
void free_hash_table(HashTable* table) {
    HashTable *current, *tmp;
    HASH_ITER(hh, table, current, tmp) {
        HASH_DEL(table, current);
        free(current->key);
        free(current);
    }
}

// Check if substring starting at index i can form a valid concatenation
int check(int i, char* s, int wordLength, int substringSize,
          HashTable* wordCount, int k) {
    HashTable* remaining = hash_table_deep_copy(wordCount);
    int wordsUsed = 0;
    char* sub = (char*)malloc(wordLength + 1);

    for (int j = i; j < i + substringSize; j += wordLength) {
        strncpy(sub, s + j, wordLength);
        sub[wordLength] = '\0';
        if (decrement_hash_count(remaining, sub)) {
            wordsUsed++;
        } else {
            free(sub);
            free_hash_table(remaining);
            return 0;
        }
    }

    free(sub);
    free_hash_table(remaining);
    return wordsUsed == k;
}

// Main function to find substrings
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int n = strlen(s);
    int wordLength = strlen(words[0]);
    int substringSize = wordLength * wordsSize;
    int* results = malloc(sizeof(int) * (n - substringSize + 1));
    *returnSize = 0;

    HashTable* wordCount = NULL;
    for (int i = 0; i < wordsSize; i++) {
        add_word_count(&wordCount, words[i]);
    }

    for (int i = 0; i <= n - substringSize; i++) {
        if (check(i, s, wordLength, substringSize, wordCount, wordsSize)) {
            results[(*returnSize)++] = i;
        }
    }

    free_hash_table(wordCount);
    return results;
}
