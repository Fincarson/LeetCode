# 1497. Check If Array Pairs Are Divisible by k

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/)  
`Array` `Hash Table` `Counting`

**Problem Link:** [LeetCode 1497 - Check If Array Pairs Are Divisible by k](https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/)

## Problem

Given an array of integers arr of even length n and an integer k.

We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

Return true If you can find a way to do that or false otherwise.

### Example 1

```text
Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
```

### Example 2

```text
Input: arr = [1,2,3,4,5,6], k = 7
Output: true
Explanation: Pairs are (1,6),(2,5) and(3,4).
```

### Example 3

```text
Input: arr = [1,2,3,4,5,6], k = 10
Output: false
Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
```

## Constraints

- arr.length == n
- 1 <= n <= 105
- n is even.
- -109 <= arr[i] <= 109
- 1 <= k <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Array Pairs Divisible by K](https://leetcode.com/problems/count-array-pairs-divisible-by-k/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Deletions to Make Array Divisible](https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Count Pairs That Form a Complete Day II](https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Pairs That Form a Complete Day I](https://leetcode.com/problems/count-pairs-that-form-a-complete-day-i/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1497. Check If Array Pairs Are Divisible by k

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hashing / Counting | C++, Java, Python3 |
| Sorting and Two-Pointers | C++, Java, Python3 |

## Approach 1: Hashing / Counting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderCount;

        // Store the count of remainders in a map.
        for (auto i : arr) remainderCount[(i % k + k) % k]++;

        for (auto i : arr) {
            int rem = (i % k + k) % k;

            // If the remainder for an element is 0, then the count
            // of numbers that give this remainder must be even.
            if (rem == 0) {
                if (remainderCount[rem] % 2 == 1) return false;
            }

            // If the remainder rem and k-rem do not have the
            // same count then pairs cannot be made.
            else if (remainderCount[rem] != remainderCount[k - rem])
                return false;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canArrange(int[] arr, int k) {
        Map<Integer, Integer> remainderCount = new HashMap<>();

        // Store the count of remainders in a map.
        for (int i : arr) {
            int rem = ((i % k) + k) % k;
            remainderCount.put(rem, remainderCount.getOrDefault(rem, 0) + 1);
        }

        for (int i : arr) {
            int rem = ((i % k) + k) % k;

            // If the remainder for an element is 0, then the count
            // of numbers that give this remainder must be even.
            if (rem == 0) {
                if (remainderCount.get(rem) % 2 == 1) return false;
            }
            // If the remainder rem and k-rem do not have the
            // same count then pairs cannot be made.
            else if (
                !Objects.equals(
                    remainderCount.get(rem),
                    remainderCount.get(k - rem)
                )
            ) return false;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canArrange(self, arr, k):
        remainder_count = {}

        # Store the count of remainders in a map.
        for i in arr:
            remainder_count[(i % k + k) % k] = (
                remainder_count.get((i % k + k) % k, 0) + 1
            )

        for i in arr:
            rem = (i % k + k) % k

            # If the remainder for an element is 0, then the count of numbers that give this remainder must be even.
            if rem == 0:
                if remainder_count[rem] % 2 == 1:
                    return False

            # If the remainder rem and k-rem do not have the same count then pairs cannot be made.
            elif remainder_count[rem] != remainder_count.get(k - rem, 0):
                return False
        return True
```

</details>

<br>

## Approach 2: Sorting and Two-Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Custom comparator to sort based on mod values.
    struct Comparator {
        int k;
        Comparator(int k) { this->k = k; }
        bool operator()(int i, int j) {
            return (k + i % k) % k < (k + j % k) % k;
        }
    };

    bool canArrange(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end(), Comparator(k));

        // Assign the pairs with modulo 0 first.
        int start = 0, end = arr.size() - 1;
        while (start < end) {
            if (arr[start] % k != 0) break;
            if (arr[start + 1] % k != 0) return false;
            start = start + 2;
        }

        // Now, pick one element from the beginning and one element from the
        // end.
        while (start < end) {
            if ((arr[start] + arr[end]) % k != 0) return false;
            start++;
            end--;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Custom comparator to sort based on mod values.
    private class Comparator implements java.util.Comparator<Integer> {

        private int k;

        public Comparator(int k) {
            this.k = k;
        }

        public int compare(Integer i, Integer j) {
            return ((k + (i % k)) % k) - ((k + (j % k)) % k);
        }
    }

    public boolean canArrange(int[] arr, int k) {
        Integer[] array = new Integer[arr.length];
        for (int i = 0; i < arr.length; ++i) {
            array[i] = arr[i];
        }

        Arrays.sort(array, new Comparator(k));

        // Assign the pairs with modulo 0 first.
        int start = 0, end = array.length - 1;
        while (start < end) {
            if (array[start] % k != 0) break;
            if (array[start + 1] % k != 0) return false;
            start = start + 2;
        }

        // Now, pick one element from the beginning and one element from the end.
        while (start < end) {
            if ((array[start] + array[end]) % k != 0) return false;
            start++;
            end--;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        # Custom comparator to sort based on mod values.
        arr = sorted(arr, key=lambda x: (k + x % k) % k)

        # Assign the pairs with modulo 0 first.
        start = 0
        end = len(arr) - 1
        while start < end:
            if arr[start] % k != 0:
                break
            if arr[start + 1] % k != 0:
                return False
            start = start + 2

        # Now, pick one element from the beginning and one element from the
        # end.
        while start < end:
            if (arr[start] + arr[end]) % k != 0:
                return False
            start += 1
            end -= 1

        return True
```

</details>
