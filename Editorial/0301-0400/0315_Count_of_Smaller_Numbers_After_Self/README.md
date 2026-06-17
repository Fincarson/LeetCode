# 315. Count of Smaller Numbers After Self

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)  
`Array` `Binary Search` `Divide and Conquer` `Binary Indexed Tree` `Segment Tree` `Merge Sort` `Ordered Set`

**Problem Link:** [LeetCode 315 - Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)

## Problem

Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

### Example 1

```text
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
```

### Example 2

```text
Input: nums = [-1]
Output: [0]
```

### Example 3

```text
Input: nums = [-1,-1]
Output: [0,0]
```

## Constraints

- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Reverse Pairs](https://leetcode.com/problems/reverse-pairs/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [How Many Numbers Are Smaller Than the Current Number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count Good Triplets in an Array](https://leetcode.com/problems/count-good-triplets-in-an-array/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Count the Number of K-Big Indices](https://leetcode.com/problems/count-the-number-of-k-big-indices/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 315. Count of Smaller Numbers After Self

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Segment Tree | C++, Java, Python3 |
| Binary Indexed Tree (Fenwick Tree) | C++, Java, Python3 |
| Merge Sort | C++, Java, Python3 |

## Approach 1: Segment Tree

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int offset = 1e4;        // offset negative to non-negative
        int size = 2 * 1e4 + 1;  // total possible values in nums
        vector<int> tree(size * 2);
        vector<int> result;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int smaller_count = query(0, nums[i] + offset, tree, size);
            result.push_back(smaller_count);
            update(nums[i] + offset, 1, tree, size);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // implement segment tree
    void update(int index, int value, vector<int>& tree, int size) {
        index += size;  // shift the index to the leaf
        // update from leaf to root
        tree[index] += value;
        while (index > 1) {
            index /= 2;
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
        }
    }

    int query(int left, int right, vector<int>& tree, int size) {
        // return sum of [left, right)
        int result = 0;
        left += size;  // shift the index to the leaf
        right += size;
        while (left < right) {
            // if left is a right node
            // bring the value and move to parent's right node
            if (left % 2 == 1) {
                result += tree[left];
                left++;
            }
            // else directly move to parent
            left /= 2;
            // if right is a right node
            // bring the value of the left node and move to parent
            if (right % 2 == 1) {
                right--;
                result += tree[right];
            }
            // else directly move to parent
            right /= 2;
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> countSmaller(int[] nums) {
        int offset = 10000; // offset negative to non-negative
        int size = 2 * 10000 + 1; // total possible values in nums
        int[] tree = new int[size * 2];
        List<Integer> result = new ArrayList<Integer>();

        for (int i = nums.length - 1; i >= 0; i--) {
            int smaller_count = query(0, nums[i] + offset, tree, size);
            result.add(smaller_count);
            update(nums[i] + offset, 1, tree, size);
        }
        Collections.reverse(result);
        return result;
    }

    // implement segment tree
    private void update(int index, int value, int[] tree, int size) {
        index += size; // shift the index to the leaf
        // update from leaf to root
        tree[index] += value;
        while (index > 1) {
            index /= 2;
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
        }
    }

    private int query(int left, int right, int[] tree, int size) {
        // return sum of [left, right)
        int result = 0;
        left += size; // shift the index to the leaf
        right += size;
        while (left < right) {
            // if left is a right node
            // bring the value and move to parent's right node
            if (left % 2 == 1) {
                result += tree[left];
                left++;
            }
            // else directly move to parent
            left /= 2;
            // if right is a right node
            // bring the value of the left node and move to parent
            if (right % 2 == 1) {
                right--;
                result += tree[right];
            }
            // else directly move to parent
            right /= 2;
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        # implement segment tree
        def update(index, value, tree, size):
            index += size  # shift the index to the leaf
            # update from leaf to root
            tree[index] += value
            while index > 1:
                index //= 2
                tree[index] = tree[index * 2] + tree[index * 2 + 1]

        def query(left, right, tree, size):
            # return sum of [left, right)
            result = 0
            left += size  # shift the index to the leaf
            right += size
            while left < right:
                # if left is a right node
                # bring the value and move to parent's right node
                if left % 2 == 1:
                    result += tree[left]
                    left += 1
                # else directly move to parent
                left //= 2
                # if right is a right node
                # bring the value of the left node and move to parent
                if right % 2 == 1:
                    right -= 1
                    result += tree[right]
                # else directly move to parent
                right //= 2
            return result

        offset = 10**4  # offset negative to non-negative
        size = 2 * 10**4 + 1  # total possible values in nums
        tree = [0] * (2 * size)
        result = []
        for num in reversed(nums):
            smaller_count = query(0, num + offset, tree, size)
            result.append(smaller_count)
            update(num + offset, 1, tree, size)
        return reversed(result)
```

</details>

<br>

## Approach 2: Binary Indexed Tree (Fenwick Tree)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int offset = 1e4;        // offset negative to non-negative
        int size = 2 * 1e4 + 2;  // total possible values in nums plus one dummy
        vector<int> tree(size);
        vector<int> result;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int smaller_count = query(nums[i] + offset, tree);
            result.push_back(smaller_count);
            update(nums[i] + offset, 1, tree, size);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // implement Binary Index Tree
    void update(int index, int value, vector<int>& tree, int size) {
        index++;  // index in BIT is 1 more than the original index
        while (index < size) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int query(int index, vector<int>& tree) {
        // return sum of [0, index)
        int result = 0;
        while (index >= 1) {
            result += tree[index];
            index -= index & -index;
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> countSmaller(int[] nums) {
        int offset = 10000; // offset negative to non-negative
        int size = 2 * 10000 + 2; // total possible values in nums plus one dummy
        int[] tree = new int[size];
        List<Integer> result = new ArrayList<Integer>();

        for (int i = nums.length - 1; i >= 0; i--) {
            int smaller_count = query(nums[i] + offset, tree);
            result.add(smaller_count);
            update(nums[i] + offset, 1, tree, size);
        }
        Collections.reverse(result);
        return result;
    }

    // implement Binary Index Tree
    private void update(int index, int value, int[] tree, int size) {
        index++; // index in BIT is 1 more than the original index
        while (index < size) {
            tree[index] += value;
            index += index & -index;
        }
    }

    private int query(int index, int[] tree) {
        // return sum of [0, index)
        int result = 0;
        while (index >= 1) {
            result += tree[index];
            index -= index & -index;
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        # implement Binary Index Tree
        def update(index, value, tree, size):
            index += 1  # index in BIT is 1 more than the original index
            while index < size:
                tree[index] += value
                index += index & -index

        def query(index, tree):
            # return sum of [0, index)
            result = 0
            while index >= 1:
                result += tree[index]
                index -= index & -index
            return result

        offset = 10**4  # offset negative to non-negative
        size = 2 * 10**4 + 2  # total possible values in nums plus one dummy
        tree = [0] * size
        result = []
        for num in reversed(nums):
            smaller_count = query(num + offset, tree)
            result.append(smaller_count)
            update(num + offset, 1, tree, size)
        return reversed(result)
```

</details>

<br>

## Approach 3: Merge Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> indices(n);  // record the index. we are going to sort this array
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        // sort indices with their corresponding values in nums, i.e., nums[indices[i]]
        mergeSort(indices, 0, n, result, nums);
        return result;
    }

    void mergeSort(vector<int>& indices, int left, int right, vector<int>& result,
                   vector<int>& nums) {
        if (right - left <= 1) {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(indices, left, mid, result, nums);
        mergeSort(indices, mid, right, result, nums);
        merge(indices, left, right, mid, result, nums);
    }

    void merge(vector<int>& indices, int left, int right, int mid, vector<int>& result,
               vector<int>& nums) {
        // merge [left, mid) and [mid, right)
        int i = left;  // current index for the left array
        int j = mid;   // current index for the right array
        // use temp to temporarily store sorted array
        vector<int> temp;
        while (i < mid && j < right) {
            if (nums[indices[i]] <= nums[indices[j]]) {
                // j - mid numbers jump to the left side of indices[i]
                result[indices[i]] += j - mid;
                temp.push_back(indices[i]);
                i++;
            } else {
                temp.push_back(indices[j]);
                j++;
            }
        }
        // when one of the subarrays is empty
        while (i < mid) {
            // j - mid numbers jump to the left side of indices[i]
            result[indices[i]] += j - mid;
            temp.push_back(indices[i]);
            i++;
        }
        while (j < right) {
            temp.push_back(indices[j]);
            j++;
        }
        // restore from temp
        move(temp.begin(), temp.end(), indices.begin() + left);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        int[] indices = new int[n]; // record the index. we are going to sort this array
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        // sort indices with their corresponding values in nums, i.e., nums[indices[i]]
        mergeSort(indices, 0, n, result, nums);
        // change int[] to List to return
        List<Integer> resultToReturn = new ArrayList<Integer>(n);
        for (int i : result) {
            resultToReturn.add(i);
        }
        return resultToReturn;
    }

    private void mergeSort(int[] indices, int left, int right, int[] result, int[] nums) {
        if (right - left <= 1) {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(indices, left, mid, result, nums);
        mergeSort(indices, mid, right, result, nums);
        merge(indices, left, right, mid, result, nums);
    }

    private void merge(int[] indices, int left, int right, int mid, int[] result, int[] nums) {
        // merge [left, mid) and [mid, right)
        int i = left; // current index for the left array
        int j = mid; // current index for the right array
        // use temp to temporarily store sorted array
        List<Integer> temp = new ArrayList<Integer>(right - left);
        while (i < mid && j < right) {
            if (nums[indices[i]] <= nums[indices[j]]) {
                // j - mid numbers jump to the left side of indices[i]
                result[indices[i]] += j - mid;
                temp.add(indices[i]);
                i++;
            } else {
                temp.add(indices[j]);
                j++;
            }
        }
        // when one of the subarrays is empty
        while (i < mid) {
            // j - mid numbers jump to the left side of indices[i]
            result[indices[i]] += j - mid;
            temp.add(indices[i]);
            i++;
        }
        while (j < right) {
            temp.add(indices[j]);
            j++;
        }
        // restore from temp
        for (int k = left; k < right; k++) {
            indices[k] = temp.get(k - left);
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        n = len(nums)
        arr = [[v, i] for i, v in enumerate(nums)]  # record value and index
        result = [0] * n

        def merge_sort(arr, left, right):
            # merge sort [left, right) from small to large, in place
            if right - left <= 1:
                return
            mid = (left + right) // 2
            merge_sort(arr, left, mid)
            merge_sort(arr, mid, right)
            merge(arr, left, right, mid)

        def merge(arr, left, right, mid):
            # merge [left, mid) and [mid, right)
            i = left  # current index for the left array
            j = mid  # current index for the right array
            # use temp to temporarily store sorted array
            temp = []
            while i < mid and j < right:
                if arr[i][0] <= arr[j][0]:
                    # j - mid numbers jump to the left side of arr[i]
                    result[arr[i][1]] += j - mid
                    temp.append(arr[i])
                    i += 1
                else:
                    temp.append(arr[j])
                    j += 1
            # when one of the subarrays is empty
            while i < mid:
                # j - mid numbers jump to the left side of arr[i]
                result[arr[i][1]] += j - mid
                temp.append(arr[i])
                i += 1
            while j < right:
                temp.append(arr[j])
                j += 1
            # restore from temp
            for i in range(left, right):
                arr[i] = temp[i - left]

        merge_sort(arr, 0, n)

        return result
```

</details>
