# 1550. Three Consecutive Odds

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/three-consecutive-odds/)  
`Array`

**Problem Link:** [LeetCode 1550 - Three Consecutive Odds](https://leetcode.com/problems/three-consecutive-odds/)

## Problem

### Example 1

```text
Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.
```

### Example 2

```text
Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.
```

## Constraints

- 1 <= arr.length <= 1000
- 1 <= arr[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1550. Three Consecutive Odds

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Counting | C++, Java, Python3 |
| Product of Three Numbers | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        // Loop through the array up to the third-to-last element
        for (int i = 0; i < n - 2; i++) {
            // Check if the current element and the next two elements are all
            // odd
            if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) {
                return true;
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean threeConsecutiveOdds(int[] arr) {
        // Loop through the array up to the third-to-last element
        for (int i = 0; i < arr.length - 2; i++) {
            // Check if the current element and the next two elements are all odd
            if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) {
                return true;
            }
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        # Loop through the array up to the third-to-last element
        for i in range(len(arr) - 2):
            # Check if the current element and the next two elements are all odd
            if arr[i] % 2 == 1 and arr[i + 1] % 2 == 1 and arr[i + 2] % 2 == 1:
                return True
        return False
```

</details>

<br>

## Approach 2: Counting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int consecutiveOdds = 0;

        // Loop through each element in the array
        for (int i = 0; i < arr.size(); i++) {
            // Increment the counter if the number is odd,
            // else reset the counter
            if (arr[i] % 2 == 1) {
                consecutiveOdds++;
            } else {
                consecutiveOdds = 0;
            }

            // Check if there are three consecutive odd numbers
            if (consecutiveOdds == 3) {
                return true;
            }
        }

        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean threeConsecutiveOdds(int[] arr) {
        int consecutiveOdds = 0;

        // Loop through each element in the array
        for (int i = 0; i < arr.length; i++) {
            // Increment the counter if the number is odd,
            // else reset the counter
            if (arr[i] % 2 == 1) {
                consecutiveOdds++;
            } else {
                consecutiveOdds = 0;
            }

            // Check if there are three consecutive odd numbers
            if (consecutiveOdds == 3) {
                return true;
            }
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        consecutive_odds = 0

        # Increment the counter if the number is odd,
        # else reset the counter
        for num in arr:
            # Check if the current number is odd
            if num % 2 == 1:
                consecutive_odds += 1
            else:
                consecutive_odds = 0

            # Check if there are three consecutive odd numbers
            if consecutive_odds == 3:
                return True

        return False
```

</details>

<br>

## Approach 3: Product of Three Numbers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        // Loop through the array up to the third-to-last element
        for (int i = 0; i < n - 2; i++) {
            int product = arr[i] * arr[i + 1] * arr[i + 2];
            // Check if the product is odd
            if (product % 2 == 1) return true;
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean threeConsecutiveOdds(int[] arr) {
        // Loop through the array up to the third-to-last element
        for (int i = 0; i < arr.length - 2; i++) {
            int product = arr[i] * arr[i + 1] * arr[i + 2];
            // Check if the product is odd
            if (product % 2 == 1) return true;
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def threeConsecutiveOdds(self, arr: list[int]) -> bool:
        # Loop through the array up to the third-to-last element
        for i in range(len(arr) - 2):
            product = arr[i] * arr[i + 1] * arr[i + 2]
            # Check if the product is odd
            if product % 2 == 1:
                return True
        return False
```

</details>
