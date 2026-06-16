# 1482. Minimum Number of Days to Make m Bouquets

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 1482 - Minimum Number of Days to Make m Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)

## Problem

You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

### Example 1

```text
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
```

### Example 2

```text
Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
```

### Example 3

```text
Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.
```

## Constraints

- bloomDay.length == n
- 1 <= n <= 105
- 1 <= bloomDay[i] <= 109
- 1 <= m <= 106
- 1 <= k <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximize the Confusion of an Exam](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Earliest Possible Day of Full Bloom](https://leetcode.com/problems/earliest-possible-day-of-full-bloom/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1482. Minimum Number of Days to Make m Bouquets

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Binary Search | C++, Java, Python3 |

## Approach: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Return the number of maximum bouquets that can be made on day mid.
    int getNumOfBouquets(vector<int>& bloomDay, int mid, int k) {
        int numOfBouquets = 0;

        int count = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            // If the flower is bloomed, add to the set. Else reset the count.
            if (bloomDay[i] <= mid) {
                count++;
            } else {
                count = 0;
            }

            if (count == k) {
                numOfBouquets++;
                count = 0;
            }
        }

        return numOfBouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 0;
        int end = 0;
        for (int day : bloomDay) {
            end = max(end, day);
        }

        int minDays = -1;
        while (start <= end) {
            int mid = (start + end) / 2;

            if (getNumOfBouquets(bloomDay, mid, k) >= m) {
                minDays = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return minDays;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Return the number of maximum bouquets that can be made on day mid.
    private int getNumOfBouquets(int[] bloomDay, int mid, int k) {
        int numOfBouquets = 0;
        int count = 0;

        for (int i = 0; i < bloomDay.length; i++) {
            // If the flower is bloomed, add to the set. Else reset the count.
            if (bloomDay[i] <= mid) {
                count++;
            } else {
                count = 0;
            }

            if (count == k) {
                numOfBouquets++;
                count = 0;
            }
        }

        return numOfBouquets;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        int start = 0;
        int end = 0;
        for (int day : bloomDay) {
            end = Math.max(end, day);
        }

        int minDays = -1;
        while (start <= end) {
            int mid = (start + end) / 2;

            if (getNumOfBouquets(bloomDay, mid, k) >= m) {
                minDays = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return minDays;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def get_num_of_bouquets(self, bloomDay, mid, k):
        num_of_bouquets = 0
        count = 0

        for day in bloomDay:
            # If the flower is bloomed, add to the set. Else reset the count.
            if day <= mid:
                count += 1
            else:
                count = 0

            if count == k:
                num_of_bouquets += 1
                count = 0

        return num_of_bouquets

    def minDays(self, bloomDay, m, k):
        if m * k > len(bloomDay):
            return -1

        start = 0
        end = max(bloomDay)
        minDays = -1

        while start <= end:
            mid = (start + end) // 2

            if self.get_num_of_bouquets(bloomDay, mid, k) >= m:
                minDays = mid
                end = mid - 1
            else:
                start = mid + 1

        return minDays
```

</details>
