class Solution:
    def isPrime(self, num):
        if num < 2:
            return False
        if num == 2 or num == 3:
            return True
        if num % 2 == 0:
            return False
        divisor = 3
        while divisor * divisor <= num:
            if num % divisor == 0:
                return False
            divisor += 2
        return True

    def closestPrimes(self, left, right):
        # Step 1: Handle special (2, 3) case
        if left <= 2 and right >= 3:
            return [2, 3]

        prev_prime = -1
        closestA = -1
        closestB = -1
        min_difference = float("inf")

        # Step 2: Iterate and find primes
        for candidate in range(left, right + 1):
            if self.isPrime(candidate):
                if prev_prime != -1:
                    difference = candidate - prev_prime
                    if difference < min_difference:
                        min_difference = difference
                        closestA = prev_prime
                        closestB = candidate
                    # Twin prime optimization
                    if difference == 2:
                        return [prev_prime, candidate]
                prev_prime = candidate

        # Step 3: Return result
        return [closestA, closestB]
