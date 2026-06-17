# 1356. Sort Integers by The Number of 1 Bits

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/)  
`Array` `Bit Manipulation` `Sorting` `Counting`

**Problem Link:** [LeetCode 1356 - Sort Integers by The Number of 1 Bits](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/)

## Problem

You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.

### Example 1

```text
Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
```

### Example 2

```text
Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
```

## Constraints

- 1 <= arr.length <= 500
- 0 <= arr[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Subsequence of Length K With the Largest Sum](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find if Array Can Be Sorted](https://leetcode.com/problems/find-if-array-can-be-sorted/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1356. Sort Integers by The Number of 1 Bits

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort By Custom Comparator: Built-in | C++, Java, Python3 |
| Bit Manipulation | C++, Java, Python3 |
| Brian Kerninghan's Algorithm | C++, Java, Python3 |

## Approach 1: Sort By Custom Comparator: Built-in

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    static bool compare(int a, int b) {
        if (__builtin_popcount(a) == __builtin_popcount(b)) {
            return a < b;
        }
        
        return __builtin_popcount(a) < __builtin_popcount(b);
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] sortByBits(int[] arr) {
        Integer[] nums = Arrays.stream(arr).boxed().toArray(Integer[]::new);
        Comparator<Integer> comparator = new CustomComparator();
        Arrays.sort(nums, comparator);
        return Arrays.stream(nums).mapToInt(Integer::intValue).toArray();
    }
}

class CustomComparator implements Comparator<Integer> {
    @Override
    public int compare(Integer a, Integer b) {
        if (Integer.bitCount(a) == Integer.bitCount(b)) {
            return a - b;
        }
        
        return Integer.bitCount(a) - Integer.bitCount(b);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        arr.sort(key = lambda num: (num.bit_count(), num))
        return arr
```

</details>

<br>

## Approach 2: Bit Manipulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    static int findWeight(int num) {
        int mask = 1;
        int weight = 0;
        
        while (num > 0) {
            if ((num & mask) > 0) {
                weight++;
                num ^= mask;
            }
            
            mask <<= 1;
        }
        
        return weight;
    }
    
    static bool compare(int a, int b) {
        if (findWeight(a) == findWeight(b)) {
            return a < b;
        }
        
        return findWeight(a) < findWeight(b);
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] sortByBits(int[] arr) {
        Integer[] nums = Arrays.stream(arr).boxed().toArray(Integer[]::new);
        Comparator<Integer> comparator = new CustomComparator();
        Arrays.sort(nums, comparator);
        return Arrays.stream(nums).mapToInt(Integer::intValue).toArray();
    }
}

class CustomComparator implements Comparator<Integer> {
    private int findWeight(int num) {
        int mask = 1;
        int weight = 0;
        
        while (num > 0) {
            if ((num & mask) > 0) {
                weight++;
                num ^= mask;
            }
            
            mask <<= 1;
        }
        
        return weight;
    }
    
    @Override
    public int compare(Integer a, Integer b) {
        if (findWeight(a) == findWeight(b)) {
            return a - b;
        }
        
        return findWeight(a) - findWeight(b);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        def find_weight(num):
            mask = 1
            weight = 0
            
            while num:
                if num & mask:
                    weight += 1
                    num ^= mask
                
                mask <<= 1
            
            return weight
        
        arr.sort(key = lambda num: (find_weight(num), num))
        return arr
```

</details>

<br>

## Approach 3: Brian Kerninghan's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    static int findWeight(int num) {
        int weight = 0;
        
        while (num > 0) {
            weight++;
            num &= (num - 1);
        }
        
        return weight;
    }
    
    static bool compare(int a, int b) {
        if (findWeight(a) == findWeight(b)) {
            return a < b;
        }
        
        return findWeight(a) < findWeight(b);
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] sortByBits(int[] arr) {
        Integer[] nums = Arrays.stream(arr).boxed().toArray(Integer[]::new);
        Comparator<Integer> comparator = new CustomComparator();
        Arrays.sort(nums, comparator);
        return Arrays.stream(nums).mapToInt(Integer::intValue).toArray();
    }
}

class CustomComparator implements Comparator<Integer> {
    private int findWeight(int num) {
        int weight = 0;
        
        while (num > 0) {
            weight++;
            num &= (num - 1);
        }
        
        return weight;
    }
    
    @Override
    public int compare(Integer a, Integer b) {
        if (findWeight(a) == findWeight(b)) {
            return a - b;
        }
        
        return findWeight(a) - findWeight(b);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        def find_weight(num):
            weight = 0
            
            while num:
                weight += 1
                num &= (num - 1)
            
            return weight
        
        arr.sort(key = lambda num: (find_weight(num), num))
        return arr
```

</details>
