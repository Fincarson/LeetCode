void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int numberOfWays(char * corridor) { 
    // Initial values of three variables
    int zero = 0;
    int one = 0;
    int two = 1;

    // Compute using derived equations
    for (int index = 0; index < strlen(corridor); index++) {
        if (corridor[index] == 'S') {
            zero = one;
            swap(&one, &two);
        } else {
            two = (two + zero) % 1000000007;
        }
    }

    // Return the result
    return zero;
}
