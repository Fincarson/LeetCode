# 1570. Dot Product of Two Sparse Vectors

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/dot-product-of-two-sparse-vectors/)  
`Array` `Hash Table` `Two Pointers` `Design`

**Problem Link:** [LeetCode 1570 - Dot Product of Two Sparse Vectors](https://leetcode.com/problems/dot-product-of-two-sparse-vectors/)

## Problem

Given two sparse vectors, compute their dot product.

Implement class SparseVector:

- SparseVector(nums) Initializes the object with the vector nums
- dotProduct(vec) Compute the dot product between the instance of SparseVector and vec

A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?

### Example 1

```text
Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
Output: 8
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
```

### Example 2

```text
Input: nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
Output: 0
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0
```

### Example 3

```text
Input: nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
Output: 6
```

## Constraints

- n == nums1.length == nums2.length
- 1 <= n <= 10^5
- 0 <= nums1[i], nums2[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1570. Dot Product of Two Sparse Vectors

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Non-efficient Array Approach | Java, Python3 |
| Hash Table | Java, Python3 |
| Index-Value Pairs | Java, Python3 |

## Approach 1: Non-efficient Array Approach

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class SparseVector {

    private int[] array;

    SparseVector(int[] nums) {
        array = nums;
    }

    public int dotProduct(SparseVector vec) {
        int result = 0;

        for (int i = 0; i < array.length; i++) {
            result += array[i] * vec.array[i];
        }
        return result;
    }   
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class SparseVector:
    def __init__(self, nums):
        self.array = nums

    def dotProduct(self, vec):
        result = 0
        for num1, num2 in zip(self.array, vec.array):
            result += num1 * num2
        return result
```

</details>

<br>

## Approach 2: Hash Table

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class SparseVector {
    // Map the index to value for all non-zero values in the vector
    Map<Integer, Integer> mapping;      

    SparseVector(int[] nums) {
        mapping = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != 0) {
                mapping.put(i, nums[i]);        
            }
        }
    }

    public int dotProduct(SparseVector vec) {        
        int result = 0;

        // iterate through each non-zero element in this sparse vector
        // update the dot product if the corresponding index has a non-zero value in the other vector
        for (Integer i : this.mapping.keySet()) {
            if (vec.mapping.containsKey(i)) {
                result += this.mapping.get(i) * vec.mapping.get(i);
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class SparseVector:
    def __init__(self, nums: List[int]):
        self.nonzeros = {}
        for i, n in enumerate(nums):
            if n != 0:
                self.nonzeros[i] = n              

    def dotProduct(self, vec: 'SparseVector') -> int:
        result = 0
        # iterate through each non-zero element in this sparse vector
        # update the dot product if the corresponding index has a non-zero value in the other vector
        for i, n in self.nonzeros.items():
            if i in vec.nonzeros:
                result += n * vec.nonzeros[i]
        return result
```

</details>

<br>

## Approach 3: Index-Value Pairs

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class SparseVector {

    List<int[]> pairs;

    SparseVector(int[] nums) {
        pairs = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                pairs.add(new int[]{i, nums[i]});
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    public int dotProduct(SparseVector vec) {
        int result = 0, p = 0, q = 0;
        while (p < pairs.size() && q < vec.pairs.size()) {
            if (pairs.get(p)[0] == vec.pairs.get(q)[0]) {
                result += pairs.get(p)[1] * vec.pairs.get(q)[1];
                p++;
                q++;
            }
            else if (pairs.get(p)[0] > vec.pairs.get(q)[0]) {
                q++;
            }
            else {
                p++;
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class SparseVector:
    def __init__(self, nums: List[int]):
        self.pairs = []
        for index, value in enumerate(nums):
            if value != 0:
                self.pairs.append([index, value])

    def dotProduct(self, vec: 'SparseVector') -> int:
        result = 0
        p, q = 0, 0

        while p < len(self.pairs) and q < len(vec.pairs):
            if self.pairs[p][0] == vec.pairs[q][0]:
                result += self.pairs[p][1] * vec.pairs[q][1]
                p += 1
                q += 1
            elif self.pairs[p][0] < vec.pairs[q][0]:
                p += 1
            else:
                q += 1

        return result
```

</details>
