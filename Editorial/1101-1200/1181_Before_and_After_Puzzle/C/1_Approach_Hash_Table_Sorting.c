#define MAX_PHRASE_LEN 256

typedef struct {
    char key[MAX_PHRASE_LEN];
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, const char *key) {
    HashItem *pEntry = NULL;
    HASH_FIND_STR(*obj, key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, const char *key) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    strcpy(pEntry->key, key);
    HASH_ADD_STR(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

typedef struct {
    char first[MAX_PHRASE_LEN];
    char last[MAX_PHRASE_LEN];
} FirstLast;

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

char **beforeAndAfterPuzzles(char **phrases, int phrasesSize, int *returnSize) {
    FirstLast sp[phrasesSize];
    for (int i = 0; i < phrasesSize; i++) {
        char phrase[MAX_PHRASE_LEN];
        strcpy(phrase, phrases[i]);
        char *first = strtok(phrase, " ");
        char *last = first;
        char *token = NULL;
        while ((token = strtok(NULL, " ")) != NULL) {
            last = token;
        }
        strcpy(sp[i].first, first);
        strcpy(sp[i].last, last);
    }

    int combinedSize = 0;
    HashItem *set = NULL;
    for (int i = 0; i < phrasesSize; i++) {
        for (int j = 0; j < phrasesSize; j++) {
            if (i == j) continue;
            if (strcmp(sp[i].first, sp[j].last) == 0) {
                char combined[MAX_PHRASE_LEN];
                strcpy(combined, phrases[j]);
                strcat(combined, phrases[i] + strlen(sp[i].first));
                hashAddItem(&set, combined);
            }
        }
    }

    *returnSize = HASH_COUNT(set);
    char **result = (char **)malloc(sizeof(char *) * HASH_COUNT(set));
    int pos = 0;
    for (HashItem *pEntry = set; pEntry; pEntry = pEntry->hh.next) {
        result[pos++] = strdup(pEntry->key);
    }
    qsort(result, *returnSize, sizeof(char *), compare);
    hashFree(&set);
    return result;
}
