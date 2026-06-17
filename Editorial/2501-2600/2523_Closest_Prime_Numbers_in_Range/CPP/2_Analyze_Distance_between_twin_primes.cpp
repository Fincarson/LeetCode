class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // Step 1: Handle special (2, 3) case
        if (left <= 2 && right >= 3)
            return {2, 3};

        int prevPrime = -1, closestA = -1, closestB = -1;
        int minDifference = 1e6;

        // Step 2: Iterate and find primes
        for (int candidate = left; candidate <= right; candidate++) {
            if (isPrime(candidate)) {
                if (prevPrime != -1) {
                    int difference = candidate - prevPrime;
                    if (difference < minDifference) {
                        minDifference = difference;
                        closestA = prevPrime;
                        closestB = candidate;
                    }
                    // Twin prime optimization
                    if (difference == 2)
                        return {prevPrime, candidate};
                }
                prevPrime = candidate;
            }
        }

        // Step 3: Return result
        return {closestA, closestB};
    }

private:
    bool isPrime(int number) {
        if (number < 2) return false;
        if (number == 2 || number == 3) return true;
        if (number % 2 == 0) return false;
        for (int divisor = 3; divisor * divisor <= number; divisor += 2) {
            if (number % divisor == 0) return false;
        }
        return true;
    }
};
