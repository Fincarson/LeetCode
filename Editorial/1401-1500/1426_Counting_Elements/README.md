# 1426. Counting Elements

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/counting-elements/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 1426 - Counting Elements](https://leetcode.com/problems/counting-elements/)

## Problem

Given an integer array arr, count how many elements x there are, such that x + 1 is also in arr. If there are duplicates in arr, count them separately.

### Example 1

```text
Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
```

### Example 2

```text
Input: arr = [1,1,3,3,5,5,7,7]
Output: 0
Explanation: No numbers are counted, cause there is no 2, 4, 6, or 8 in arr.
```

## Constraints

- 1 <= arr.length <= 1000
- 0 <= arr[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1426. Counting Elements

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Search with Array | C++, Java, Python3 |
| Search with HashSet | C++, Java, Python3 |
| Search with Sorted Array | C++, Java, Python3 |

## Approach 1: Search with Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countElements(vector<int>& arr) {
        int count = 0;
        for (auto x : arr) {
            if (integerInArray(arr, x + 1)) {
                count++;
            }
        }
        return count;
    }

    bool integerInArray(vector<int>& arr, int target) {
        for (auto x : arr) {
            if (x == target) {
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

    public int countElements(int[] arr) {
        int count = 0;
        for (int x : arr) {
            if (integerInArray(arr, x + 1)) {
                count++;
            }
        }
        return count;
    }

    public boolean integerInArray(int[] arr, int target) {
        for (int x : arr) {
            if (x == target) {
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
    def countElements(self, arr: List[int]) -> int:
        count = 0
        for x in arr:
            if x + 1 in arr:
                count += 1
        return count


# Note that we could also do this as a one-liner generator comprehension.
# return sum(1 for x in arr if x + 1 in arr)
```

</details>

<br>

## Approach 2: Search with HashSet

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> hashSet(arr.begin(), arr.end());
        int count = 0;
        for (int x : arr) {
            if (hashSet.find(x + 1) != hashSet.end()) {
                count++;
            }
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countElements(int[] arr) {
        Set<Integer> hashSet = new HashSet<>();
        for (int x : arr) {
            hashSet.add(x);
        }
        int count = 0;
        for (int x : arr) {
            if (hashSet.contains(x + 1)) {
                count++;
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countElements(self, arr: List[int]) -> int:
        hash_set = set(arr)
        count = 0
        for x in arr:
            if x + 1 in hash_set:
                count += 1
        return count
```

</details>

<br>

## Approach 3: Search with Sorted Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countElements(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int count = 0;
        int runLength = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] != arr[i]) {
                if (arr[i - 1] + 1 == arr[i]) {
                    count += runLength;
                }
                runLength = 0;
            }
            runLength++;
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countElements(int[] arr) {
        Arrays.sort(arr);
        int count = 0;
        int runLength = 1;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i - 1] != arr[i]) {
                if (arr[i - 1] + 1 == arr[i]) {
                    count += runLength;
                }
                runLength = 0;
            }
            runLength++;
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countElements(self, arr: List[int]) -> int:
        arr.sort()
        count = 0
        run_length = 1
        for i in range(1, len(arr)):
            if arr[i - 1] != arr[i]:
                if arr[i - 1] + 1 == arr[i]:
                    count += run_length
                run_length = 0
            run_length += 1
        return count
```

</details>
