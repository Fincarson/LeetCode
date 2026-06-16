# 1151. Minimum Swaps to Group All 1's Together

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/)  
`Array` `Sliding Window`

**Problem Link:** [LeetCode 1151 - Minimum Swaps to Group All 1's Together](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/)

## Problem

Given a binary array data, return the minimum number of swaps required to group all 1’s present in the array together in any place in the array.

### Example 1

```text
Input: data = [1,0,1,0,1]
Output: 1
Explanation: There are 3 ways to group all 1's together:
[1,1,1,0,0] using 1 swap.
[0,1,1,1,0] using 2 swaps.
[0,0,1,1,1] using 1 swap.
The minimum is 1.
```

### Example 2

```text
Input: data = [0,0,0,1,0]
Output: 0
Explanation: Since there is only one 1 in the array, no swaps are needed.
```

### Example 3

```text
Input: data = [1,0,1,0,1,0,0,1,1,0,1]
Output: 3
Explanation: One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].
```

## Constraints

- 1 <= data.length <= 105
- data[i] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Adjacent Swaps for K Consecutive Ones](https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Swaps to Group All 1's Together II](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Time Needed to Rearrange a Binary String](https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Moves to Pick K Ones](https://leetcode.com/problems/minimum-moves-to-pick-k-ones/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1151. Minimum Swaps to Group All 1's Together

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sliding Window with Two Pointers | C++, Java, Python3 |
| Sliding Window with Deque (Double-ended Queue) | C++, Java, Python3 |

## Approach 1: Sliding Window with Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = accumulate(data.begin(), data.end(), 0);
        int cntOne = 0, maxOne = 0;
        int left = 0, right = 0;

        while (right < data.size()) {
            // Updating the number of 1's by adding the new element
            cntOne += data[right++];
            // Maintain the length of the window to ones
            if (right - left > ones) {
                // Updating the number of 1's by removing the oldest element
                cntOne -= data[left++];
            }
            // Record the maximum number of 1's in the window
            maxOne = max(maxOne, cntOne);
        }
        return ones - maxOne;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minSwaps(int[] data) {
        int ones = Arrays.stream(data).sum();
        int cntOne = 0, maxOne = 0;
        int left = 0, right = 0;

        while (right < data.length) {
            // Updating the number of 1's by adding the new element
            cntOne += data[right++];
            // Maintain the length of the window to ones
            if (right - left > ones) {
                // Updating the number of 1's by removing the oldest element
                cntOne -= data[left++];
            }
            // Record the maximum number of 1's in the window
            maxOne = Math.max(maxOne, cntOne);
        }
        return ones - maxOne;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minSwaps(self, data: List[int]) -> int:
        ones = sum(data)
        cnt_one = max_one = 0
        left = right = 0
        while right < len(data):
            # updating the number of 1's by adding the new element
            cnt_one += data[right]
            right += 1
            # maintain the length of the window to ones
            if right - left > ones:
                # updating the number of 1's by removing the oldest element
                cnt_one -= data[left]
                left += 1
            # record the maximum number of 1's in the window
            max_one = max(max_one, cnt_one)
        return ones - max_one
```

</details>

<br>

## Approach 2: Sliding Window with Deque (Double-ended Queue)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = accumulate(data.begin(), data.end(), 0);
        int cntOne = 0, maxOne = 0;
        deque<int> dq;

        for (int i = 0; i < data.size(); i++) {
            // Add the new element into the deque
            dq.push_back(data[i]);
            cntOne += data[i];

            // When the deque size exceeds ones, remove the leftmost element
            if (dq.size() > ones) {
                cntOne -= dq.front();
                dq.pop_front();
            }
            maxOne = max(maxOne, cntOne);
        }
        return ones - maxOne;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minSwaps(int[] data) {
        int ones = Arrays.stream(data).sum();
        int cntOne = 0, maxOne = 0;
        // Maintain a deque with the size = ones
        Deque<Integer> deque = new ArrayDeque<>();

        for (int i = 0; i < data.length; i++) {
            // We would always add the new element into the deque
            deque.addLast(data[i]);
            cntOne += data[i];

            // When there are more than ones elements in the deque,
            // remove the leftmost one
            if (deque.size() > ones) {
                cntOne -= deque.removeFirst();
            }
            maxOne = Math.max(maxOne, cntOne);
        }
        return ones - maxOne;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minSwaps(self, data: List[int]) -> int:
        ones = sum(data)
        cnt_one = max_one = 0

        # maintain a deque with the size = ones
        deque = collections.deque()
        for i in range(len(data)):

            # we would always add the new element into the deque
            deque.append(data[i])
            cnt_one += data[i]

            # when there are more than ones elements in the deque,
            # remove the leftmost one
            if len(deque) > ones:
                cnt_one -= deque.popleft()
            max_one = max(max_one, cnt_one)
        return ones - max_one
```

</details>
