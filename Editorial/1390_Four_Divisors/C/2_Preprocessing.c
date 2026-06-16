int sumFourDivisors(int* nums, int numsSize) {
    // C is the upper bound of the array nums, and C3 is the cube root of C.
    const int C = 100000, C3 = 46;

    int* isprime = (int*)malloc((C + 1) * sizeof(int));
    memset(isprime, 0, (C + 1) * sizeof(int));
    int* primes = (int*)malloc((C + 1) * sizeof(int));
    int primeCount = 0;

    // Sieve of Eratosthenes
    for (int i = 2; i <= C; ++i) {
        isprime[i] = 1;
    }
    for (int i = 2; i <= C; ++i) {
        if (isprime[i]) {
            primes[primeCount++] = i;
        }
        for (int j = i + i; j <= C; j += i) {
            isprime[j] = 0;
        }
    }

    // Sieve of Euler
    /*
    for (int i = 2; i <= C; ++i) {
        if (isprime[i]) {
            primes[primeCount++] = i;
        }
        for (int j = 0; j < primeCount; ++j) {
            if (i * primes[j] > C) {
                break;
            }
            isprime[i * primes[j]] = 0;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    */

    // Construct all four factors using the prime table
    int* factor4_keys = (int*)malloc(primeCount * primeCount * sizeof(int));
    int* factor4_values = (int*)malloc(primeCount * primeCount * sizeof(int));
    int factor4_count = 0;

    for (int i = 0; i < primeCount; ++i) {
        int prime = primes[i];
        if (prime <= C3) {
            factor4_keys[factor4_count] = prime * prime * prime;
            factor4_values[factor4_count] =
                1 + prime + prime * prime + prime * prime * prime;
            factor4_count++;
        }
    }
    for (int i = 0; i < primeCount; ++i) {
        for (int j = i + 1; j < primeCount; ++j) {
            if (primes[i] <= C / primes[j]) {
                factor4_keys[factor4_count] = primes[i] * primes[j];
                factor4_values[factor4_count] =
                    1 + primes[i] + primes[j] + primes[i] * primes[j];
                factor4_count++;
            } else {
                break;
            }
        }
    }

    int ans = 0;
    for (int idx = 0; idx < numsSize; ++idx) {
        int num = nums[idx];
        for (int i = 0; i < factor4_count; ++i) {
            if (factor4_keys[i] == num) {
                ans += factor4_values[i];
                break;
            }
        }
    }

    free(isprime);
    free(primes);
    free(factor4_keys);
    free(factor4_values);

    return ans;
}
