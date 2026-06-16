char* reverseWords(char* s) {
    char *token, *last, *reversed;
    char space[2] = " ";
    char* new_s = malloc(10000 * sizeof(char));

    if (!new_s) return NULL;

    new_s[0] = '\0';

    // split by spaces and reverse
    token = strtok(s, space);
    while (token != NULL) {
        if (strlen(new_s) > 0) {
            last = strdup(new_s);
            strcpy(new_s, token);
            strcat(new_s, " ");
            strcat(new_s, last);
            free(last);
        } else {
            strcpy(new_s, token);
            strcat(new_s, " ");
        }
        token = strtok(NULL, space);
    }

    // remove trailing space
    new_s[strlen(new_s) - 1] = '\0';

    // return the reversed words
    reversed = strdup(new_s);

    free(new_s);

    return reversed;
}
