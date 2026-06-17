# 1533. Find the Index of the Large Integer

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-index-of-the-large-integer/)  
`Array` `Binary Search` `Interactive`

**Problem Link:** [LeetCode 1533 - Find the Index of the Large Integer](https://leetcode.com/problems/find-the-index-of-the-large-integer/)

## Problem

We have an integer array arr, where all the integers in arr are equal except for one integer which is larger than the rest of the integers. You will not be given direct access to the array, instead, you will have an API ArrayReader which have the following functions:

- int compareSub(int l, int r, int x, int y): where 0 <= l, r, x, y < ArrayReader.length(), l <= r and x <= y. The function compares the sum of sub-array arr[l..r] with the sum of the sub-array arr[x..y] and returns:

		1 if arr[l]+arr[l+1]+...+arr[r] > arr[x]+arr[x+1]+...+arr[y].
		0 if arr[l]+arr[l+1]+...+arr[r] == arr[x]+arr[x+1]+...+arr[y].
		-1 if arr[l]+arr[l+1]+...+arr[r] < arr[x]+arr[x+1]+...+arr[y].
- int length(): Returns the size of the array.

You are allowed to call compareSub() 20 times at most. You can assume both functions work in O(1) time.

Return the index of the array arr which has the largest integer.

### Example 1

```text
Input: arr = [7,7,7,7,10,7,7,7]
Output: 4
Explanation: The following calls to the API
reader.compareSub(0, 0, 1, 1) // returns 0 this is a query comparing the sub-array (0, 0) with the sub array (1, 1), (i.e. compares arr[0] with arr[1]).
Thus we know that arr[0] and arr[1] doesn't contain the largest element.
reader.compareSub(2, 2, 3, 3) // returns 0, we can exclude arr[2] and arr[3].
reader.compareSub(4, 4, 5, 5) // returns 1, thus for sure arr[4] is the largest element in the array.
Notice that we made only 3 calls, so the answer is valid.
```

### Example 2

```text
Input: nums = [6,6,12]
Output: 2
```

## Constraints

- 2 <= arr.length <= 5 * 105
- 1 <= arr[i] <= 100
- All elements of arr are equal except for one element which is larger than all other elements.

Follow up:

- What if there are two numbers in arr that are bigger than all other numbers?
- What if there is one number that is bigger than other numbers and one number that is smaller than other numbers?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Search in a Sorted Array of Unknown Size](https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1533. Find the Index of the Large Integer

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C#, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C#</strong></summary>

```csharp
class Solution {
    public int GetIndex(ArrayReader reader) {
        int left = 0;
        int length = reader.Length(); 
        while (length > 1) {
            length /= 2;
            int cmp = reader.CompareSub(left, left + length - 1, left + length, left + length + length - 1);
            if (cmp == 0) {
                return left + length + length;
            }
            if (cmp < 0) {
                left += length;
            }
        }
        return left;
        
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int getIndex(ArrayReader reader) {
        int left = 0;
        int length = reader.length(); 
        while (length > 1) {
            length /= 2;
            // The left subarray starts from index left and the right part starts from left + length, both subarrays have length elements. 
            final int cmp = reader.compareSub(left, left + length - 1, left + length, left + length + length - 1);
            if (cmp == 0) {
                // The extra element is the larger integer.
                return left + length + length;
            }
            if (cmp < 0) {
                left += length;
            }
        }
        return left;
        
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def getIndex(self, reader):
        left = 0
        length = reader.length()
        while (length > 1):
            length //= 2;
            cmp = reader.compareSub(left, left + length - 1, left + length,
                                              left + length + length - 1)
            if cmp == 0:
                return left + length + length
            if cmp < 0:
                left += length
        return left
```

</details>
