# 2818. Apply Operations to Maximize Score

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/apply-operations-to-maximize-score/)  
`Array` `Math` `Stack` `Greedy` `Sorting` `Monotonic Stack` `Number Theory`

**Problem Link:** [LeetCode 2818 - Apply Operations to Maximize Score](https://leetcode.com/problems/apply-operations-to-maximize-score/)

## Problem

You are given an array nums of n positive integers and an integer k.

Initially, you start with a score of 1. You have to maximize your score by applying the following operation at most k times:

- Choose any non-empty subarray nums[l, ..., r] that you haven't chosen previously.
- Choose an element x of nums[l, ..., r] with the highest prime score. If multiple such elements exist, choose the one with the smallest index.
- Multiply your score by x.

Here, nums[l, ..., r] denotes the subarray of nums starting at index l and ending at the index r, both ends being inclusive.

The prime score of an integer x is equal to the number of distinct prime factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5.

Return the maximum possible score after applying at most k operations.

Since the answer may be large, return it modulo 109 + 7.

### Example 1

```text
Input: nums = [8,3,9,3,8], k = 2
Output: 81
Explanation: To get a score of 81, we can apply the following operations:
- Choose subarray nums[2, ..., 2]. nums[2] is the only element in this subarray. Hence, we multiply the score by nums[2]. The score becomes 1 * 9 = 9.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 1, but nums[2] has the smaller index. Hence, we multiply the score by nums[2]. The score becomes 9 * 9 = 81.
It can be proven that 81 is the highest score one can obtain.
```

### Example 2

```text
Input: nums = [19,12,14,6,10,18], k = 3
Output: 4788
Explanation: To get a score of 4788, we can apply the following operations:
- Choose subarray nums[0, ..., 0]. nums[0] is the only element in this subarray. Hence, we multiply the score by nums[0]. The score becomes 1 * 19 = 19.
- Choose subarray nums[5, ..., 5]. nums[5] is the only element in this subarray. Hence, we multiply the score by nums[5]. The score becomes 19 * 18 = 342.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 2, but nums[2] has the smaller index. Hence, we multipy the score by nums[2]. The score becomes 342 * 14 = 4788.
It can be proven that 4788 is the highest score one can obtain.
```

## Constraints

- 1 <= nums.length == n <= 105
- 1 <= nums[i] <= 105
- 1 <= k <= min(n * (n + 1) / 2, 109)

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Next Greater Element IV](https://leetcode.com/problems/next-greater-element-iv/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2818. Apply Operations to Maximize Score

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Monotonic Stack & Priority Queue | C++, Java, Python3 |
| Sieve of Eratosthenes & Sorting | C++, Java, Python3 |

## Approach 1: Monotonic Stack & Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    const int MOD = 1e9 + 7;

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n);

        // Calculate the prime score for each number in nums
        for (int index = 0; index < n; index++) {
            int num = nums[index];

            // Check for prime factors from 2 to sqrt(n)
            for (int factor = 2; factor <= sqrt(num); factor++) {
                if (num % factor == 0) {
                    // Increment prime score for each prime factor
                    primeScores[index]++;

                    // Remove all occurrences of the prime factor from num
                    while (num % factor == 0) num /= factor;
                }
            }

            // If num is still greater than or equal to 2, it's a prime factor
            if (num >= 2) primeScores[index]++;
        }

        // Initialize next and previous dominant index arrays
        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);

        // Stack to store indices for monotonic decreasing prime score
        stack<int> decreasingPrimeScoreStack;

        // Calculate the next and previous dominant indices for each number
        for (int index = 0; index < n; index++) {
            // While the stack is not empty and the current prime score is
            // greater than the stack's top
            while (!decreasingPrimeScoreStack.empty() &&
                   primeScores[decreasingPrimeScoreStack.top()] <
                       primeScores[index]) {
                int topIndex = decreasingPrimeScoreStack.top();
                decreasingPrimeScoreStack.pop();

                // Set the next dominant element for the popped index
                nextDominant[topIndex] = index;
            }

            // If the stack is not empty, set the previous dominant element for
            // the current index
            if (!decreasingPrimeScoreStack.empty())
                prevDominant[index] = decreasingPrimeScoreStack.top();

            // Push the current index onto the stack
            decreasingPrimeScoreStack.push(index);
        }

        // Calculate the number of subarrays in which each element is dominant
        vector<long long> numOfSubarrays(n);
        for (int index = 0; index < n; index++) {
            numOfSubarrays[index] = (long long)(nextDominant[index] - index) *
                                    (index - prevDominant[index]);
        }

        // Priority queue to process elements in decreasing order of their value
        priority_queue<pair<int, int>> processingQueue;

        // Push each number and its index onto the priority queue
        for (int index = 0; index < n; index++)
            processingQueue.push({nums[index], index});

        long long score = 1;

        // Process elements while there are operations left
        while (k > 0) {
            // Get the element with the maximum value from the queue
            auto [num, index] = processingQueue.top();
            processingQueue.pop();

            // Calculate the number of operations to apply on the current
            // element
            long long operations = min((long long)k, numOfSubarrays[index]);

            // Update the score by raising the element to the power of
            // operations
            score = (score * power(num, operations)) % MOD;

            // Reduce the remaining operations count
            k -= operations;
        }

        return score;
    }

private:
    // Helper function to compute the power of a number modulo MOD
    long long power(long long base, long long exponent) {
        long long res = 1;

        // Calculate the exponentiation using binary exponentiation
        while (exponent > 0) {
            // If the exponent is odd, multiply the result by the base
            if (exponent % 2 == 1) {
                res = ((res * base) % MOD);
            }

            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    final int MOD = 1000000007;

    public int maximumScore(List<Integer> nums, int k) {
        int n = nums.size();
        List<Integer> primeScores = new ArrayList<>(Collections.nCopies(n, 0));

        // Calculate the prime score for each number in nums
        for (int index = 0; index < n; index++) {
            int num = nums.get(index);

            // Check for prime factors from 2 to sqrt(n)
            for (int factor = 2; factor <= Math.sqrt(num); factor++) {
                if (num % factor == 0) {
                    // Increment prime score for each prime factor
                    primeScores.set(index, primeScores.get(index) + 1);

                    // Remove all occurrences of the prime factor from num
                    while (num % factor == 0) num /= factor;
                }
            }

            // If num is still greater than or equal to 2, it's a prime factor
            if (num >= 2) primeScores.set(index, primeScores.get(index) + 1);
        }

        // Initialize next and previous dominant index arrays
        int[] nextDominant = new int[n];
        int[] prevDominant = new int[n];
        Arrays.fill(nextDominant, n);
        Arrays.fill(prevDominant, -1);

        // Stack to store indices for monotonic decreasing prime score
        Stack<Integer> decreasingPrimeScoreStack = new Stack<>();

        // Calculate the next and previous dominant indices for each number
        for (int index = 0; index < n; index++) {
            // While the stack is not empty and the current prime score is greater than the stack's top
            while (
                !decreasingPrimeScoreStack.isEmpty() &&
                primeScores.get(decreasingPrimeScoreStack.peek()) <
                primeScores.get(index)
            ) {
                int topIndex = decreasingPrimeScoreStack.pop();

                // Set the next dominant element for the popped index
                nextDominant[topIndex] = index;
            }

            // If the stack is not empty, set the previous dominant element for the current index
            if (!decreasingPrimeScoreStack.isEmpty()) prevDominant[index] =
                decreasingPrimeScoreStack.peek();

            // Push the current index onto the stack
            decreasingPrimeScoreStack.push(index);
        }

        // Calculate the number of subarrays in which each element is dominant
        long[] numOfSubarrays = new long[n];
        for (int index = 0; index < n; index++) {
            numOfSubarrays[index] =
                ((long) nextDominant[index] - index) *
                (index - prevDominant[index]);
        }

        // Priority queue to process elements in decreasing order of their value
        PriorityQueue<int[]> processingQueue = new PriorityQueue<>((a, b) -> {
            if (b[0] == a[0]) {
                return Integer.compare(a[1], b[1]); // break tie based on the index (ascending order)
            }
            return Integer.compare(b[0], a[0]); // descending order for the value
        });

        // Push each number and its index onto the priority queue
        for (int index = 0; index < n; index++) {
            processingQueue.offer(new int[] { nums.get(index), index });
        }

        long score = 1;

        // Process elements while there are operations left
        while (k > 0) {
            // Get the element with the maximum value from the queue
            int[] top = processingQueue.poll();
            int num = top[0];
            int index = top[1];

            // Calculate the number of operations to apply on the current element
            long operations = Math.min((long) k, numOfSubarrays[index]);

            // Update the score by raising the element to the power of operations
            score = (score * power(num, operations)) % MOD;

            // Reduce the remaining operations count
            k -= operations;
        }

        return (int) score;
    }

    // Helper function to compute the power of a number modulo MOD
    private long power(long base, long exponent) {
        long res = 1;

        // Calculate the exponentiation using binary exponentiation
        while (exponent > 0) {
            // If the exponent is odd, multiply the result by the base
            if (exponent % 2 == 1) {
                res = (res * base) % MOD;
            }

            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    MOD = 10**9 + 7

    def maximumScore(self, nums, k):
        n = len(nums)
        prime_scores = [0] * n

        # Calculate the prime score for each number in nums
        for index in range(n):
            num = nums[index]

            # Check for prime factors from 2 to sqrt(n)
            for factor in range(2, int(math.sqrt(num)) + 1):
                if num % factor == 0:
                    # Increment prime score for each prime factor
                    prime_scores[index] += 1

                    # Remove all occurrences of the prime factor from num
                    while num % factor == 0:
                        num //= factor

            # If num is still greater than or equal to 2, it's a prime factor
            if num >= 2:
                prime_scores[index] += 1

        # Initialize next and previous dominant index arrays
        next_dominant = [n] * n
        prev_dominant = [-1] * n

        # Stack to store indices for monotonic decreasing prime score
        decreasing_prime_score_stack = []

        # Calculate the next and previous dominant indices for each number
        for index in range(n):
            # While the stack is not empty and the current prime score is greater than the stack's top
            while (
                decreasing_prime_score_stack
                and prime_scores[decreasing_prime_score_stack[-1]]
                < prime_scores[index]
            ):
                top_index = decreasing_prime_score_stack.pop()

                # Set the next dominant element for the popped index
                next_dominant[top_index] = index

            # If the stack is not empty, set the previous dominant element for the current index
            if decreasing_prime_score_stack:
                prev_dominant[index] = decreasing_prime_score_stack[-1]

            # Push the current index onto the stack
            decreasing_prime_score_stack.append(index)

        # Calculate the number of subarrays in which each element is dominant
        num_of_subarrays = [0] * n
        for index in range(n):
            num_of_subarrays[index] = (next_dominant[index] - index) * (
                index - prev_dominant[index]
            )

        # Priority queue to process elements in decreasing order of their value
        processing_queue = []

        # Push each number and its index onto the priority queue
        for index in range(n):
            heapq.heappush(processing_queue, (-nums[index], index))

        score = 1

        # Helper function to compute the power of a number modulo MOD
        def _power(base, exponent):
            res = 1

            # Calculate the exponentiation using binary exponentiation
            while exponent > 0:
                # If the exponent is odd, multiply the result by the base
                if exponent % 2 == 1:
                    res = (res * base) % self.MOD

                # Square the base and halve the exponent
                base = (base * base) % self.MOD
                exponent //= 2

            return res

        # Process elements while there are operations left
        while k > 0:
            # Get the element with the maximum value from the queue
            num, index = heapq.heappop(processing_queue)
            num = -num  # Negate back to positive

            # Calculate the number of operations to apply on the current element
            operations = min(k, num_of_subarrays[index])

            # Update the score by raising the element to the power of operations
            score = (score * _power(num, operations)) % self.MOD

            # Reduce the remaining operations count
            k -= operations

        return score
```

</details>

<br>

## Approach 2: Sieve of Eratosthenes & Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    const int MOD = 1e9 + 7;

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n, 0);

        // Find the maximum element in nums to determine the range for prime
        // generation
        int maxElement = 0;
        for (int index = 0; index < n; index++) {
            maxElement = max(maxElement, nums[index]);
        }

        // Get all prime numbers up to maxElement using the Sieve of
        // Eratosthenes
        vector<int> primes = getPrimes(maxElement);

        // Calculate the prime score for each number in nums
        for (int index = 0; index < n; index++) {
            int num = nums[index];

            // Iterate over the generated primes to count unique prime factors
            for (int prime : primes) {
                if (prime * prime > num)
                    break;  // Stop early if prime^2 exceeds num
                if (num % prime != 0)
                    continue;  // Skip if the prime is not a factor

                primeScores[index]++;  // Increment prime score for the factor
                while (num % prime == 0)
                    num /= prime;  // Remove all occurrences of this factor
            }

            // If num is still greater than 1, it is a prime number itself
            if (num > 1) primeScores[index]++;
        }

        // Initialize next and previous dominant index arrays
        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);

        // Stack to store indices for a monotonic decreasing prime score
        stack<int> decreasingPrimeScoreStack;

        // Calculate the next and previous dominant indices for each number
        for (int index = 0; index < n; index++) {
            // While the stack is not empty and the current prime score is
            // greater than the stack's top, update nextDominant
            while (!decreasingPrimeScoreStack.empty() &&
                   primeScores[decreasingPrimeScoreStack.top()] <
                       primeScores[index]) {
                int topIndex = decreasingPrimeScoreStack.top();
                decreasingPrimeScoreStack.pop();

                // Set the next dominant element for the popped index
                nextDominant[topIndex] = index;
            }

            // If the stack is not empty, set the previous dominant element for
            // the current index
            if (!decreasingPrimeScoreStack.empty())
                prevDominant[index] = decreasingPrimeScoreStack.top();

            // Push the current index onto the stack
            decreasingPrimeScoreStack.push(index);
        }

        // Calculate the number of subarrays in which each element is dominant
        vector<long long> numOfSubarrays(n);
        for (int index = 0; index < n; index++) {
            numOfSubarrays[index] = (long long)(nextDominant[index] - index) *
                                    (index - prevDominant[index]);
        }

        // Sort elements in decreasing order based on their values
        vector<pair<int, int>> sortedArray(n);
        for (int index = 0; index < n; index++) {
            sortedArray[index] = {nums[index], index};
        }

        sort(sortedArray.begin(), sortedArray.end(), greater<>());

        long long score = 1;
        int processingIndex = 0;

        // Process elements while there are operations left
        while (k > 0) {
            // Get the element with the maximum value
            auto [num, index] = sortedArray[processingIndex++];

            // Calculate the number of operations to apply on the current
            // element
            long long operations = min((long long)k, numOfSubarrays[index]);

            // Update the score by raising the element to the power of
            // operations
            score = (score * power(num, operations)) % MOD;

            // Reduce the remaining operations count
            k -= operations;
        }

        return score;
    }

private:
    // Helper function to compute the power of a number modulo MOD
    long long power(long long base, long long exponent) {
        long long res = 1;

        // Calculate the exponentiation using binary exponentiation
        while (exponent > 0) {
            // If the exponent is odd, multiply the result by the base
            if (exponent % 2 == 1) {
                res = ((res * base) % MOD);
            }

            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }

    // Function to generate prime numbers up to a given limit using the Sieve of
    // Eratosthenes
    vector<int> getPrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        // Start marking from the first prime number (2)
        for (int number = 2; number <= limit; number++) {
            if (!isPrime[number]) continue;

            // Store the prime number
            primes.push_back(number);

            // Mark multiples of the prime number as non-prime
            for (long long multiple = (long long)number * number;
                 multiple <= limit; multiple += number) {
                isPrime[multiple] = false;
            }
        }

        return primes;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int MOD = 1_000_000_007;

    public int maximumScore(List<Integer> nums, int k) {
        int n = nums.size();
        int[] primeScores = new int[n];

        // Find the maximum element in nums to determine the range for prime generation
        int maxElement = Collections.max(nums);

        // Get all prime numbers up to maxElement using the Sieve of Eratosthenes
        List<Integer> primes = getPrimes(maxElement);

        // Calculate the prime score for each number in nums
        for (int index = 0; index < n; index++) {
            int num = nums.get(index);

            // Iterate over the generated primes to count unique prime factors
            for (int prime : primes) {
                if (prime * prime > num) break; // Stop early if prime^2 exceeds num
                if (num % prime != 0) continue; // Skip if the prime is not a factor

                primeScores[index]++; // Increment prime score for the factor
                while (num % prime == 0) num /= prime; // Remove all occurrences of this factor
            }

            // If num is still greater than 1, it is a prime number itself
            if (num > 1) primeScores[index]++;
        }

        // Initialize next and previous dominant index arrays
        int[] nextDominant = new int[n];
        int[] prevDominant = new int[n];
        Arrays.fill(nextDominant, n);
        Arrays.fill(prevDominant, -1);

        // Stack to store indices for a monotonic decreasing prime score
        Stack<Integer> decreasingPrimeScoreStack = new Stack<>();

        // Calculate the next and previous dominant indices for each number
        for (int index = 0; index < n; index++) {
            while (
                !decreasingPrimeScoreStack.isEmpty() &&
                primeScores[decreasingPrimeScoreStack.peek()] <
                primeScores[index]
            ) {
                int topIndex = decreasingPrimeScoreStack.pop();
                nextDominant[topIndex] = index;
            }

            if (!decreasingPrimeScoreStack.isEmpty()) {
                prevDominant[index] = decreasingPrimeScoreStack.peek();
            }

            decreasingPrimeScoreStack.push(index);
        }

        // Calculate the number of subarrays in which each element is dominant
        long[] numOfSubarrays = new long[n];
        for (int index = 0; index < n; index++) {
            numOfSubarrays[index] =
                (long) (nextDominant[index] - index) *
                (index - prevDominant[index]);
        }

        // Sort elements in decreasing order based on their values
        List<int[]> sortedArray = new ArrayList<>();
        for (int index = 0; index < n; index++) {
            sortedArray.add(new int[] { nums.get(index), index });
        }
        sortedArray.sort((a, b) -> Integer.compare(b[0], a[0])); // Sort in descending order

        long score = 1;
        int processingIndex = 0;

        // Process elements while there are operations left
        while (k > 0) {
            int[] element = sortedArray.get(processingIndex++);
            int num = element[0];
            int index = element[1];

            // Calculate the number of operations to apply on the current element
            long operations = Math.min(k, numOfSubarrays[index]);

            // Update the score by raising the element to the power of operations
            score = (score * power(num, operations)) % MOD;

            // Reduce the remaining operations count
            k -= operations;
        }

        return (int) score;
    }

    // Helper function to compute the power of a number modulo MOD
    private long power(long base, long exponent) {
        long res = 1;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }

    // Function to generate prime numbers up to a given limit using the Sieve of Eratosthenes
    private List<Integer> getPrimes(int limit) {
        boolean[] isPrime = new boolean[limit + 1];
        Arrays.fill(isPrime, true);
        List<Integer> primes = new ArrayList<>();

        for (int number = 2; number <= limit; number++) {
            if (!isPrime[number]) continue;

            primes.add(number);

            for (
                long multiple = (long) number * number;
                multiple <= limit;
                multiple += number
            ) {
                isPrime[(int) multiple] = false;
            }
        }

        return primes;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    MOD = int(1e9 + 7)

    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prime_scores = [0] * n

        # Find the maximum element in nums to determine the range for prime generation
        max_element = max(nums)

        # Get all prime numbers up to max_element using the Sieve of Eratosthenes
        primes = self.get_primes(max_element)

        # Calculate the prime score for each number in nums
        for index in range(n):
            num = nums[index]

            # Iterate over the generated primes to count unique prime factors
            for prime in primes:
                if prime * prime > num:
                    break  # Stop early if prime^2 exceeds num
                if num % prime != 0:
                    continue  # Skip if the prime is not a factor

                prime_scores[index] += 1  # Increment prime score for the factor
                while num % prime == 0:
                    num //= prime  # Remove all occurrences of this factor

            # If num is still greater than 1, it is a prime number itself
            if num > 1:
                prime_scores[index] += 1

        # Initialize next and previous dominant index arrays
        next_dominant = [n] * n
        prev_dominant = [-1] * n

        # Stack to store indices for a monotonic decreasing prime score
        decreasing_prime_score_stack = deque()

        # Calculate the next and previous dominant indices for each number
        for index in range(n):
            # While the stack is not empty and the current prime score is
            # greater than the stack's top, update next_dominant
            while (
                decreasing_prime_score_stack
                and prime_scores[decreasing_prime_score_stack[-1]]
                < prime_scores[index]
            ):
                top_index = decreasing_prime_score_stack.pop()

                # Set the next dominant element for the popped index
                next_dominant[top_index] = index

            # If the stack is not empty, set the previous dominant element for
            # the current index
            if decreasing_prime_score_stack:
                prev_dominant[index] = decreasing_prime_score_stack[-1]

            # Push the current index onto the stack
            decreasing_prime_score_stack.append(index)

        # Calculate the number of subarrays in which each element is dominant
        num_of_subarrays = [
            (next_dominant[i] - i) * (i - prev_dominant[i]) for i in range(n)
        ]

        # Sort elements in decreasing order based on their values
        sorted_array = sorted(enumerate(nums), key=lambda x: -x[1])

        score = 1

        # Helper function to compute the power of a number modulo MOD
        def _power(base, exponent):
            res = 1

            # Calculate the exponentiation using binary exponentiation
            while exponent > 0:
                # If the exponent is odd, multiply the result by the base
                if exponent % 2:
                    res = (res * base) % self.MOD

                # Square the base and halve the exponent
                base = (base * base) % self.MOD
                exponent //= 2

            return res

        processing_index = 0

        # Process elements while there are operations left
        while k > 0:
            # Get the element with the maximum value
            index, num = sorted_array[processing_index]
            processing_index += 1

            # Calculate the number of operations to apply on the current
            # element
            operations = min(k, num_of_subarrays[index])

            # Update the score by raising the element to the power of
            # operations
            score = (score * _power(num, operations)) % self.MOD

            # Reduce the remaining operations count
            k -= operations

        return score

    # Function to generate prime numbers up to a given limit using the Sieve of Eratosthenes
    def get_primes(self, limit: int) -> List[int]:
        is_prime = [True] * (limit + 1)
        primes = []

        # Start marking from the first prime number (2)
        for number in range(2, limit + 1):
            if not is_prime[number]:
                continue

            # Store the prime number
            primes.append(number)

            # Mark multiples of the prime number as non-prime
            for multiple in range(number * number, limit + 1, number):
                is_prime[multiple] = False

        return primes
```

</details>
