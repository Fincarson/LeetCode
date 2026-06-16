int candy(int* ratings, int ratingsSize) {
    int* candies = (int*)malloc(ratingsSize * sizeof(int));
    for (int i = 0; i < ratingsSize; i++) {
        candies[i] = 1;  // Initialize all elements to 1 as in Arrays.fill
    }

    bool hasChanged = true;
    while (hasChanged) {
        hasChanged = false;
        for (int i = 0; i < ratingsSize; i++) {
            if (i != ratingsSize - 1 && ratings[i] > ratings[i + 1] &&
                candies[i] <= candies[i + 1]) {
                candies[i] = candies[i + 1] + 1;
                hasChanged = true;
            }
            if (i > 0 && ratings[i] > ratings[i - 1] &&
                candies[i] <= candies[i - 1]) {
                candies[i] = candies[i - 1] + 1;
                hasChanged = true;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < ratingsSize; i++) {
        sum += candies[i];
    }

    free(candies);  // Free the allocated memory
    return sum;
}
