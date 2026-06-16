char *simplifyPath(char *path) {
    // Initialize a stack
    char *stack[1000];
    unsigned stackIdx = 0;
    // Used for split string by '/'
    char *token = strtok(path, "/");
    while (token) {
        // If the current component is a "..", then
        // we pop an entry from the stack if it's non-empty
        if (strcmp(token, "..") == 0) {
            if (stackIdx > 0) {
                stackIdx--;
            }
        } else if (strcmp(token, ".") != 0 && strlen(token) > 0) {
            // Finally, a legitimate directory name, so we add it
            // to our stack
            stack[stackIdx] = token;
            stackIdx++;
        }
        token = strtok(NULL, "/");
    }
    // Construct simplified path
    char *res = (char *)malloc(sizeof(char) * 3000);
    memset(res, 0, sizeof(char) * 3000);
    for (unsigned i = 0; i < stackIdx; i++) {
        strcat(res, "/");
        strcat(res, stack[i]);
    }
    if (strcmp(res, "") == 0)
        return "/";
    else
        return res;
}
