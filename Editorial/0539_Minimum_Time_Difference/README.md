# 539. Minimum Time Difference

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-time-difference/)  
`Array` `Math` `String` `Sorting`

**Problem Link:** [LeetCode 539 - Minimum Time Difference](https://leetcode.com/problems/minimum-time-difference/)

## Problem

### Example 1

```text
Input: timePoints = ["23:59","00:00"]
Output: 1
```

### Example 2

```text
Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
```

## Constraints

- 2 <= timePoints.length <= 2 * 104
- timePoints[i] is in the format "HH:MM".

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Cost to Set Cooking Time](https://leetcode.com/problems/minimum-cost-to-set-cooking-time/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 539. Minimum Time Difference

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort | C++, Java, Python3 |
| Bucket Sort | C++, Java, Python3 |

## Approach 1: Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Convert input to minutes
        vector<int> minutes(timePoints.size());
        for (int i = 0; i < timePoints.size(); i++) {
            string time = timePoints[i];
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3));
            minutes[i] = h * 60 + m;
        }

        // Sort times in ascending order
        sort(minutes.begin(), minutes.end());

        // Find minimum difference across adjacent elements
        int ans = INT_MAX;
        for (int i = 0; i < minutes.size() - 1; i++) {
            ans = min(ans, minutes[i + 1] - minutes[i]);
        }

        // Consider difference between last and first element
        return min(ans, 24 * 60 - minutes[minutes.size() - 1] + minutes[0]);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findMinDifference(List<String> timePoints) {
        // convert input to minutes
        int[] minutes = new int[timePoints.size()];
        for (int i = 0; i < timePoints.size(); i++) {
            String time = timePoints.get(i);
            int h = Integer.parseInt(time.substring(0, 2));
            int m = Integer.parseInt(time.substring(3));
            minutes[i] = h * 60 + m;
        }

        // sort times in ascending order
        Arrays.sort(minutes);

        // find minimum difference across adjacent elements
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < minutes.length - 1; i++) {
            ans = Math.min(ans, minutes[i + 1] - minutes[i]);
        }

        // consider difference between last and first element
        return Math.min(
            ans,
            24 * 60 - minutes[minutes.length - 1] + minutes[0]
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        # convert input to minutes
        minutes = [int(time[:2]) * 60 + int(time[3:]) for time in timePoints]

        # sort times in ascending order
        minutes.sort()

        # find minimum difference across adjacent elements
        ans = min(minutes[i + 1] - minutes[i] for i in range(len(minutes) - 1))

        # consider difference between last and first element
        return min(ans, 24 * 60 - minutes[-1] + minutes[0])
```

</details>

<br>

## Approach 2: Bucket Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // create buckets array for the times converted to minutes
        vector<bool> minutes(24 * 60, false);
        for (string time : timePoints) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3));
            int min = h * 60 + m;
            if (minutes[min]) return 0;
            minutes[min] = true;
        }
        int prevIndex = INT_MAX;
        int firstIndex = INT_MAX;
        int lastIndex = INT_MAX;
        int ans = INT_MAX;

        // find differences between adjacent elements in sorted array
        for (int i = 0; i < 24 * 60; i++) {
            if (minutes[i]) {
                if (prevIndex != INT_MAX) {
                    ans = min(ans, i - prevIndex);
                }
                prevIndex = i;
                if (firstIndex == INT_MAX) {
                    firstIndex = i;
                }
                lastIndex = i;
            }
        }

        return min(ans, 24 * 60 - lastIndex + firstIndex);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findMinDifference(List<String> timePoints) {
        // create buckets array for the times converted to minutes
        boolean[] minutes = new boolean[24 * 60];
        for (String time : timePoints) {
            int min =
                Integer.parseInt(time.substring(0, 2)) * 60 +
                Integer.parseInt(time.substring(3));
            if (minutes[min]) return 0;
            minutes[min] = true;
        }
        int prevIndex = Integer.MAX_VALUE;
        int firstIndex = Integer.MAX_VALUE;
        int lastIndex = Integer.MAX_VALUE;
        int ans = Integer.MAX_VALUE;

        // find differences between adjacent elements in sorted array
        for (int i = 0; i < 24 * 60; i++) {
            if (minutes[i]) {
                if (prevIndex != Integer.MAX_VALUE) {
                    ans = Math.min(ans, i - prevIndex);
                }
                prevIndex = i;
                if (firstIndex == Integer.MAX_VALUE) {
                    firstIndex = i;
                }
                lastIndex = i;
            }
        }

        return Math.min(ans, 24 * 60 - lastIndex + firstIndex);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        # create buckets array for the times converted to minutes
        minutes = [False] * (24 * 60)
        for time in timePoints:
            h, m = map(int, time.split(":"))
            min_time = h * 60 + m
            if minutes[min_time]:
                return 0
            minutes[min_time] = True
        prevIndex = float("inf")
        firstIndex = float("inf")
        lastIndex = float("inf")
        ans = float("inf")

        # find differences between adjacent elements in sorted array
        for i in range(24 * 60):
            if minutes[i]:
                if prevIndex != float("inf"):
                    ans = min(ans, i - prevIndex)
                prevIndex = i
                if firstIndex == float("inf"):
                    firstIndex = i
                lastIndex = i

        return min(ans, 24 * 60 - lastIndex + firstIndex)
```

</details>
