public class Solution {
    public int SumFourDivisors(int[] nums) {
        // C is the upper bound of the array nums, and C3 is the cube root of C.
        int C = 100000, C3 = 46;

        int[] isprime = new int[C + 1];
        for (int i = 2; i <= C; i++) isprime[i] = 1;
        List<int> primes = new List<int>();

        // Sieve of Eratosthenes
        for (int i = 2; i <= C; ++i) {
            if (isprime[i] == 1) {
                primes.Add(i);
            }
            for (int j = i + i; j <= C; j += i) {
                isprime[j] = 0;
            }
        }

        // Sieve of Euler
        /*
        for (int i = 2; i <= C; ++i) {
            if (isprime[i] == 1) {
                primes.Add(i);
            }
            foreach (int prime in primes) {
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
        Dictionary<int, int> factor4 = new Dictionary<int, int>();
        foreach (int prime in primes) {
            if (prime <= C3) {
                factor4[prime * prime * prime] =
                    1 + prime + prime * prime + prime * prime * prime;
            }
        }
        for (int i = 0; i < primes.Count; ++i) {
            for (int j = i + 1; j < primes.Count; ++j) {
                if (primes[i] <= C / primes[j]) {
                    factor4[primes[i] * primes[j]] =
                        1 + primes[i] + primes[j] + primes[i] * primes[j];
                } else {
                    break;
                }
            }
        }

        int ans = 0;
        foreach (int num in nums) {
            if (factor4.ContainsKey(num)) {
                ans += factor4[num];
            }
        }
        return ans;
    }
}
