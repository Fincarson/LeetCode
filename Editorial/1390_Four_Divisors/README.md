# 1390. Four Divisors

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/four-divisors/)  
`Array` `Math`

**Problem Link:** [LeetCode 1390 - Four Divisors](https://leetcode.com/problems/four-divisors/)

## Problem

Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

### Example 1

```text
Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
```

### Example 2

```text
Input: nums = [21,21]
Output: 64
```

### Example 3

```text
Input: nums = [1,2,3,4,5]
Output: 0
```

## Constraints

- 1 <= nums.length <= 104
- 1 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1390. Four Divisors

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Preprocessing | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int sumFourDivisors(int* nums, int numsSize) {
    int ans = 0;
    for (int idx = 0; idx < numsSize; idx++) {
        int num = nums[idx];
        // factor_cnt: number of factors
        // factor_sum: sum of factors
        int factor_cnt = 0, factor_sum = 0;
        for (int i = 1; i * i <= num; ++i) {
            if (num % i == 0) {
                ++factor_cnt;
                factor_sum += i;
                if (i * i != num) {  // check if i and num/i are equal; if not,
                                     // consider num/i as a new factor.
                    ++factor_cnt;
                    factor_sum += num / i;
                }
            }
        }
        if (factor_cnt == 4) {
            ans += factor_sum;
        }
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            // factor_cnt: number of factors
            // factor_sum: sum of factors
            int factor_cnt = 0, factor_sum = 0;
            for (int i = 1; i * i <= num; ++i) {
                if (num % i == 0) {
                    ++factor_cnt;
                    factor_sum += i;
                    if (i * i != num) {  // check if i and num/i are equal; if
                                         // not, consider num/i as a new factor.
                        ++factor_cnt;
                        factor_sum += num / i;
                    }
                }
            }
            if (factor_cnt == 4) {
                ans += factor_sum;
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int SumFourDivisors(int[] nums) {
        int ans = 0;
        foreach (int num in nums) {
            // factor_cnt: number of factors
            // factor_sum: sum of factors
            int factor_cnt = 0, factor_sum = 0;
            for (int i = 1; i * i <= num; ++i) {
                if (num % i == 0) {
                    ++factor_cnt;
                    factor_sum += i;
                    if (i * i != num) {  // check if i and num/i are equal; if
                                         // not, consider num/i as a new factor.
                        ++factor_cnt;
                        factor_sum += num / i;
                    }
                }
            }
            if (factor_cnt == 4) {
                ans += factor_sum;
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func sumFourDivisors(nums []int) int {
    ans := 0
    for _, num := range nums {
        // factor_cnt: number of factors
        // factor_sum: sum of factors
        factor_cnt, factor_sum := 0, 0
        for i := 1; i*i <= num; i++ {
            if num%i == 0 {
                factor_cnt++
                factor_sum += i
                if i*i != num {   // check if i and num/i are equal; if not, consider num/i as a new factor.
                    factor_cnt++
                    factor_sum += num / i
                }
            }
        }
        if factor_cnt == 4 {
            ans += factor_sum
        }
    }
    return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int sumFourDivisors(int[] nums) {
        int ans = 0;
        for (int num : nums) {
            // factorCnt: number of factors
            // factorSum: sum of factors
            int factorCnt = 0;
            int factorSum = 0;
            for (int i = 1; i * i <= num; ++i) {
                if (num % i == 0) {
                    ++factorCnt;
                    factorSum += i;
                    // check if i and num/i are equal; 
                    // if not, consider num/i as a new factor.
                    if (i * i != num) { 
                        ++factorCnt;
                        factorSum += num / i;
                    }
                }
            }
            if (factorCnt == 4) {
                ans += factorSum;
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sumFourDivisors = function (nums) {
    let ans = 0;
    for (const num of nums) {
        // factor_cnt: number of factors
        // factor_sum: sum of factors
        let factor_cnt = 0,
            factor_sum = 0;
        for (let i = 1; i * i <= num; ++i) {
            if (num % i === 0) {
                ++factor_cnt;
                factor_sum += i;
                if (i * i !== num) {
                    // check if i and num/i are equal; if not, consider num/i as a new factor.
                    ++factor_cnt;
                    factor_sum += num / i;
                }
            }
        }
        if (factor_cnt === 4) {
            ans += factor_sum;
        }
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        ans = 0
        for num in nums:
            # factor_cnt: number of factors
            # factor_sum: sum of factors
            factor_cnt = factor_sum = 0
            i = 1
            while i * i <= num:
                if num % i == 0:
                    factor_cnt += 1
                    factor_sum += i
                    if (
                        i * i != num
                    ):  # check if i and num/i are equal; if not, consider num/i as a new factor.
                        factor_cnt += 1
                        factor_sum += num // i
                i += 1
            if factor_cnt == 4:
                ans += factor_sum
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function sumFourDivisors(nums: number[]): number {
    let ans = 0;
    for (const num of nums) {
        // factor_cnt: number of factors
        // factor_sum: sum of factors
        let factor_cnt = 0,
            factor_sum = 0;
        for (let i = 1; i * i <= num; ++i) {
            if (num % i === 0) {
                ++factor_cnt;
                factor_sum += i;
                if (i * i !== num) {
                    // check if i and num/i are equal; if not, consider num/i as a new factor.
                    ++factor_cnt;
                    factor_sum += num / i;
                }
            }
        }
        if (factor_cnt === 4) {
            ans += factor_sum;
        }
    }
    return ans;
}
```

</details>

<br>

## Approach 2: Preprocessing

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
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
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
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
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
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
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func sumFourDivisors(nums []int) int {
    // C is the upper bound of the array nums, and C3 is the cube root of C.
    C, C3 := 100000, 46
    
    isprime := make([]int, C+1)
    for i := 2; i <= C; i++ {
        isprime[i] = 1
    }
    primes := []int{}

    // Sieve of Eratosthenes
    for i := 2; i <= C; i++ {
        if isprime[i] == 1 {
            primes = append(primes, i)
        }
        for j := i + i; j <= C; j += i {
            isprime[j] = 0
        }
    }

    // Sieve of Euler
    /*
    for i := 2; i <= C; i++ {
        if isprime[i] == 1 {
            primes = append(primes, i)
        }
        for _, prime := range primes {
            if i * prime > C {
                break
            }
            isprime[i * prime] = 0
            if i % prime == 0 {
                break
            }
        }
    }
    */
    
    // Construct all four factors using the prime table
    factor4 := make(map[int]int)
    for _, prime := range primes {
        if prime <= C3 {
            factor4[prime * prime * prime] = 1 + prime + prime * prime + prime * prime * prime
        }
    }
    for i := 0; i < len(primes); i++ {
        for j := i + 1; j < len(primes); j++ {
            if primes[i] <= C / primes[j] {
                factor4[primes[i] * primes[j]] = 1 + primes[i] + primes[j] + primes[i] * primes[j]
            } else {
                break
            }
        }
    }

    ans := 0
    for _, num := range nums {
        if val, exists := factor4[num]; exists {
            ans += val
        }
    }
    return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int sumFourDivisors(int[] nums) {
        // C is the upper bound of the array nums, and C3 is the cube root of C.
        int C = 100000;
        int C3 = 46;

        boolean[] isPrime = new boolean[C + 1];
        Arrays.fill(isPrime, true);
        List<Integer> primes = new ArrayList<Integer>();

        // Sieve of Eratosthenes
        for (int i = 2; i <= C; ++i) {
            if (isPrime[i]) {
                primes.add(i);
            }
            for (int j = i + i; j <= C; j += i) {
                isPrime[j] = false;
            }
        }

        // Sieve of Euler
        /*
        for (int i = 2; i <= C; ++i) {
            if (isPrime[i]) {
                primes.add(i);
            }
            for (int prime : primes) {
                if (i * prime > C) {
                    break;
                }
                isPrime[i * prime] = false;
                if (i % prime == 0) {
                    break;
                }
            }
        }
        */

        // Construct all four factors using the prime table
        Map<Integer, Integer> factor4 = new HashMap<Integer, Integer>();
        for (int prime : primes) {
            if (prime <= C3) {
                factor4.put(
                    prime * prime * prime,
                    1 + prime + prime * prime + prime * prime * prime
                );
            }
        }
        for (int i = 0; i < primes.size(); ++i) {
            for (int j = i + 1; j < primes.size(); ++j) {
                if (primes.get(i) <= C / primes.get(j)) {
                    factor4.put(
                        primes.get(i) * primes.get(j),
                        1 +
                        primes.get(i) +
                        primes.get(j) +
                        primes.get(i) * primes.get(j)
                    );
                } else {
                    break;
                }
            }
        }

        int ans = 0;
        for (int num : nums) {
            if (factor4.containsKey(num)) {
                ans += factor4.get(num);
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sumFourDivisors = function (nums) {
    // C is the upper bound of the array nums, and C3 is the cube root of C.
    const C = 100000,
        C3 = 46;

    let isprime = new Array(C + 1).fill(0);
    let primes = [];

    // Sieve of Eratosthenes
    for (let i = 2; i <= C; i++) {
        isprime[i] = 1;
    }
    for (let i = 2; i <= C; i++) {
        if (isprime[i]) {
            primes.push(i);
        }
        for (let j = i + i; j <= C; j += i) {
            isprime[j] = 0;
        }
    }

    // Sieve of Euler
    /*
    for (let i = 2; i <= C; i++) {
        if (isprime[i]) {
            primes.push(i);
        }
        for (let prime of primes) {
            if (i * prime > C) {
                break;
            }
            isprime[i * prime] = 0;
            if (i % prime === 0) {
                break;
            }
        }
    }
    */

    // Construct all four factors using the prime table
    let factor4 = new Map();
    for (let prime of primes) {
        if (prime <= C3) {
            factor4.set(
                prime * prime * prime,
                1 + prime + prime * prime + prime * prime * prime,
            );
        }
    }
    for (let i = 0; i < primes.length; i++) {
        for (let j = i + 1; j < primes.length; j++) {
            if (primes[i] <= C / primes[j]) {
                factor4.set(
                    primes[i] * primes[j],
                    1 + primes[i] + primes[j] + primes[i] * primes[j],
                );
            } else {
                break;
            }
        }
    }

    let ans = 0;
    for (let num of nums) {
        if (factor4.has(num)) {
            ans += factor4.get(num);
        }
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        # C is the upper bound of the array nums, and C3 is the cube root of C.
        C, C3 = 100000, 46

        isprime = [True] * (C + 1)
        primes = list()

        # Sieve of Eratosthenes
        for i in range(2, C + 1):
            if isprime[i]:
                primes.append(i)
            for j in range(i + i, C + 1, i):
                isprime[j] = False

        # Sieve of Euler
        """
        for i in range(2, C + 1):
            if isprime[i]:
                primes.append(i)
            for prime in primes:
                if i * prime > C:
                    break
                isprime[i * prime] = False
                if i % prime == 0:
                    break
        """

        # Construct all four factors using the prime table
        factor4 = dict()
        for prime in primes:
            if prime <= C3:
                factor4[prime**3] = 1 + prime + prime**2 + prime**3
        for i in range(len(primes)):
            for j in range(i + 1, len(primes)):
                if primes[i] * primes[j] <= C:
                    factor4[primes[i] * primes[j]] = (
                        1 + primes[i] + primes[j] + primes[i] * primes[j]
                    )
                else:
                    break

        ans = 0
        for num in nums:
            if num in factor4:
                ans += factor4[num]
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function sumFourDivisors(nums: number[]): number {
    // C is the upper bound of the array nums, and C3 is the cube root of C.
    const C: number = 100000,
        C3: number = 46;

    let isprime: number[] = new Array(C + 1).fill(0);
    let primes: number[] = [];

    // Sieve of Eratosthenes
    for (let i = 2; i <= C; i++) {
        isprime[i] = 1;
    }
    for (let i = 2; i <= C; i++) {
        if (isprime[i]) {
            primes.push(i);
        }
        for (let j = i + i; j <= C; j += i) {
            isprime[j] = 0;
        }
    }

    // Sieve of Euler
    /*
    for (let i = 2; i <= C; i++) {
        if (isprime[i]) {
            primes.push(i);
        }
        for (let prime of primes) {
            if (i * prime > C) {
                break;
            }
            isprime[i * prime] = 0;
            if (i % prime === 0) {
                break;
            }
        }
    }
    */

    // Construct all four factors using the prime table
    let factor4: Map<number, number> = new Map();
    for (let prime of primes) {
        if (prime <= C3) {
            factor4.set(
                prime * prime * prime,
                1 + prime + prime * prime + prime * prime * prime,
            );
        }
    }
    for (let i = 0; i < primes.length; i++) {
        for (let j = i + 1; j < primes.length; j++) {
            if (primes[i] <= C / primes[j]) {
                factor4.set(
                    primes[i] * primes[j],
                    1 + primes[i] + primes[j] + primes[i] * primes[j],
                );
            } else {
                break;
            }
        }
    }

    let ans: number = 0;
    for (let num of nums) {
        if (factor4.has(num)) {
            ans += factor4.get(num)!;
        }
    }
    return ans;
}
```

</details>
