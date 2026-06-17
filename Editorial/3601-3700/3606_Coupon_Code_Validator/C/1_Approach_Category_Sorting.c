int compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

bool check(const char* code, bool isActive) {
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] != '_' && !isalnum(code[i])) {
            return false;
        }
    }
    return isActive;
}

char** validateCoupons(char** code, int codeSize, char** businessLine,
                       int businessLineSize, bool* isActive, int isActiveSize,
                       int* returnSize) {
    char** groups[4];
    int groupsSize[4] = {0};
    for (int i = 0; i < 4; i++) {
        groups[i] = (char**)malloc(sizeof(char*) * codeSize);
    }

    for (int i = 0; i < codeSize; i++) {
        if (strlen(code[i]) > 0 && check(code[i], isActive[i])) {
            if (strcmp(businessLine[i], "electronics") == 0) {
                groups[0][groupsSize[0]++] = code[i];
            } else if (strcmp(businessLine[i], "grocery") == 0) {
                groups[1][groupsSize[1]++] = code[i];
            } else if (strcmp(businessLine[i], "pharmacy") == 0) {
                groups[2][groupsSize[2]++] = code[i];
            } else if (strcmp(businessLine[i], "restaurant") == 0) {
                groups[3][groupsSize[3]++] = code[i];
            }
        }
    }

    int totalSize = 0;
    for (int i = 0; i < 4; i++) {
        qsort(groups[i], groupsSize[i], sizeof(char*), compare);
        totalSize += groupsSize[i];
    }

    char** result = malloc(sizeof(char*) * totalSize);
    int pos = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < groupsSize[i]; j++) {
            result[pos] = malloc(strlen(groups[i][j]) + 1);
            strcpy(result[pos], groups[i][j]);
            pos++;
        }
        free(groups[i]);
    }

    *returnSize = totalSize;
    return result;
}
