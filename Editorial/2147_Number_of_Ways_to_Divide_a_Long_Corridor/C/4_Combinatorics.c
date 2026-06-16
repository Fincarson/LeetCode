int numberOfWays(char * corridor) {
    // Store 1000000007 in a variable for convenience
    const int MOD = 1e9 + 7;

    // Store indices of S in an array
    int indices[strlen(corridor)];
    int indicesLength = 0;
    for (int index = 0; index < strlen(corridor); index++) {
        if (corridor[index] == 'S') {
            indices[indicesLength++] = index;
        }
    }

    // When division is not possible
    if (indicesLength == 0 || indicesLength % 2 == 1) {
        return 0;
    }

    // Total number of ways
    long count = 1;

    // Take product of non-paired neighbors
    int previousPairLast = 1;
    int currentPairFirst = 2;
    while (currentPairFirst < indicesLength) {
        count *= (indices[currentPairFirst] - indices[previousPairLast]);
        count %= MOD;
        previousPairLast += 2;
        currentPairFirst += 2;
    }

    // Return the number of ways
    return (int) count;
}
