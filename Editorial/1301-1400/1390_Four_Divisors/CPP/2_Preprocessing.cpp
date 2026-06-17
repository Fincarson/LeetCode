class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        // C is the upper bound of the array nums, and C3 is the cube root of C.
        int C = 100000, C3 = 46;

        vector<int> isprime(C + 1, 1);
        vector<int> primes;

        // Sieve of Eratosthenes
        for (int i = 2; i <= C; ++i) {
            if (isprime[i]) {
                primes.push_back(i);
            }
            for (int j = i + i; j <= C; j += i) {
                isprime[j] = 0;
            }
        }

        // Sieve of Euler
        /*
        for (int i = 2; i <= C; ++i) {
            if (isprime[i]) {
                primes.push_back(i);
            }
            for (int prime: primes) {
                if (i * prime > C) {
                    break;
                }
                isprime[i * prime] = 0;
                if (i % prime == 0) {
                    break;
                }
            }
        }
        */

        // Construct all four factors using the prime table
        unordered_map<int, int> factor4;
        for (int prime : primes) {
            if (prime <= C3) {
                factor4[prime * prime * prime] =
                    1 + prime + prime * prime + prime * prime * prime;
            }
        }
        for (int i = 0; i < primes.size(); ++i) {
            for (int j = i + 1; j < primes.size(); ++j) {
                if (primes[i] <= C / primes[j]) {
                    factor4[primes[i] * primes[j]] =
                        1 + primes[i] + primes[j] + primes[i] * primes[j];
                } else {
                    break;
                }
            }
        }

        int ans = 0;
        for (int num : nums) {
            if (factor4.count(num)) {
                ans += factor4[num];
            }
        }
        return ans;
    }
};
