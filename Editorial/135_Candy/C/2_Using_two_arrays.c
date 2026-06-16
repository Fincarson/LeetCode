int candy(int* ratings, int ratingsSize) {
    int sum = 0;
    int* left2right = (int*)malloc(ratingsSize * sizeof(int));
    int* right2left = (int*)malloc(ratingsSize * sizeof(int));

    // Initialize arrays with 1s
    for (int i = 0; i < ratingsSize; i++) {
        left2right[i] = 1;
        right2left[i] = 1;
    }

    // Calculate candies from left to right
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1]) {
            left2right[i] = left2right[i - 1] + 1;
        }
    }

    // Calculate candies from right to left
    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            right2left[i] = right2left[i + 1] + 1;
        }
    }

    // Calculate the total candies to distribute
    for (int i = 0; i < ratingsSize; i++) {
        sum += (left2right[i] > right2left[i]) ? left2right[i] : right2left[i];
    }

    // Free the allocated memory
    free(left2right);
    free(right2left);

    return sum;
}
