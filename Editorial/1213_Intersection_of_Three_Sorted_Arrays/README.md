# 1213. Intersection of Three Sorted Arrays

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/intersection-of-three-sorted-arrays/)  
`Array` `Hash Table` `Binary Search` `Counting`

**Problem Link:** [LeetCode 1213 - Intersection of Three Sorted Arrays](https://leetcode.com/problems/intersection-of-three-sorted-arrays/)

## Problem

Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays.

### Example 1

```text
Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.
```

### Example 2

```text
Input: arr1 = [197,418,523,876,1356], arr2 = [501,880,1593,1710,1870], arr3 = [521,682,1337,1395,1764]
Output: []
```

## Constraints

- 1 <= arr1.length, arr2.length, arr3.length <= 1000
- 1 <= arr1[i], arr2[i], arr3[i] <= 2000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Intersection of Multiple Arrays](https://leetcode.com/problems/intersection-of-multiple-arrays/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1213. Intersection of Three Sorted Arrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force with Hashmap | C++, Java, Python3 |
| Three Pointers | C++, Java, Python3 |

## Approach 1: Brute Force with Hashmap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2,
                                   vector<int>& arr3) {
        vector<int> ans;
        map<int, int> counter;

        // Iterate through arr1, arr2, and arr3 to count the frequencies
        for (int e : arr1) {
            counter[e]++;
        }
        for (int e : arr2) {
            counter[e]++;
        }
        for (int e : arr3) {
            counter[e]++;
        }

        // Collect elements that appear in all three arrays
        for (const auto& item : counter) {
            if (item.second == 3) {
                ans.push_back(item.first);
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> arraysIntersection(
        int[] arr1,
        int[] arr2,
        int[] arr3
    ) {
        List<Integer> ans = new ArrayList<>();

        // note that HashMap won't work here as it does not guarantee
        // the key orders
        Map<Integer, Integer> counter = new TreeMap<>();

        // iterate through arr1, arr2, and arr3 to count the frequencies
        for (Integer e : arr1) {
            counter.put(e, counter.getOrDefault(e, 0) + 1);
        }
        for (Integer e : arr2) {
            counter.put(e, counter.getOrDefault(e, 0) + 1);
        }
        for (Integer e : arr3) {
            counter.put(e, counter.getOrDefault(e, 0) + 1);
        }

        for (Integer item : counter.keySet()) {
            if (counter.get(item) == 3) {
                ans.add(item);
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def arraysIntersection(
        self, arr1: List[int], arr2: List[int], arr3: List[int]
    ) -> List[int]:
        ans = []

        # you can use a dict to count the frequencies
        # or you can use collections.Counter
        # more info is available here:
        # https://docs.python.org/3/library/collections.html

        counter = collections.Counter(
            arr1 + arr2 + arr3
        )  # concatenate them together

        for item in counter:
            if counter[item] == 3:
                ans.append(item)
        return ans
```

</details>

<br>

## Approach 2: Three Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2,
                                   vector<int>& arr3) {
        vector<int> ans;

        // Initialize three pointers for the three arrays
        int p1 = 0, p2 = 0, p3 = 0;

        while (p1 < arr1.size() && p2 < arr2.size() && p3 < arr3.size()) {
            // Check if all three pointers point to the same element
            if (arr1[p1] == arr2[p2] && arr2[p2] == arr3[p3]) {
                ans.push_back(arr1[p1]);
                p1++;
                p2++;
                p3++;
            } else {
                // Move the pointer with the smallest value to find the
                // intersection
                if (arr1[p1] < arr2[p2]) {
                    p1++;
                } else if (arr2[p2] < arr3[p3]) {
                    p2++;
                } else {
                    p3++;
                }
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> arraysIntersection(
        int[] arr1,
        int[] arr2,
        int[] arr3
    ) {
        List<Integer> ans = new ArrayList<>();
        // prepare three pointers to iterate through three arrays
        // p1, p2, and p3 point to the beginning of arr1, arr2, and arr3
        int p1 = 0, p2 = 0, p3 = 0;

        while (p1 < arr1.length && p2 < arr2.length && p3 < arr3.length) {
            if (arr1[p1] == arr2[p2] && arr2[p2] == arr3[p3]) {
                ans.add(arr1[p1]);
                p1++;
                p2++;
                p3++;
            } else {
                if (arr1[p1] < arr2[p2]) {
                    p1++;
                } else if (arr2[p2] < arr3[p3]) {
                    p2++;
                } else {
                    p3++;
                }
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def arraysIntersection(
        self, arr1: List[int], arr2: List[int], arr3: List[int]
    ) -> List[int]:
        ans = []
        # prepare three pointers to iterate through three arrays
        # p1, p2, and p3 point to the beginning of arr1, arr2, and arr3 accordingly
        p1 = p2 = p3 = 0
        while p1 < len(arr1) and p2 < len(arr2) and p3 < len(arr3):
            if arr1[p1] == arr2[p2] == arr3[p3]:
                ans.append(arr1[p1])
                p1 += 1
                p2 += 1
                p3 += 1
            else:
                if arr1[p1] < arr2[p2]:
                    p1 += 1
                elif arr2[p2] < arr3[p3]:
                    p2 += 1
                else:
                    p3 += 1
        return ans
```

</details>
