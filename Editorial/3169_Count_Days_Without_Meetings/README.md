# 3169. Count Days Without Meetings

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-days-without-meetings/)  
`Array` `Sorting`

**Problem Link:** [LeetCode 3169 - Count Days Without Meetings](https://leetcode.com/problems/count-days-without-meetings/)

## Problem

You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= days <= 109
- 1 <= meetings.length <= 105
- meetings[i].length == 2
- 1 <= meetings[i][0] <= meetings[i][1] <= days

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3169. Count Days Without Meetings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Line Sweep | C++, Java, Python3 |
| Sorting | C++, Java, Python3 |

## Approach 1: Line Sweep

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> dayMap;
        int prefixSum = 0, freeDays = 0, previousDay = days;

        for (auto& meeting : meetings) {
            // Set first day of meetings
            previousDay = min(previousDay, meeting[0]);

            // Process start and end of meeting
            dayMap[meeting[0]]++;
            dayMap[meeting[1] + 1]--;
        }

        // Add all days before the first day of meetings
        freeDays += (previousDay - 1);
        for (auto& day : dayMap) {
            int currentDay = day.first;
            // Add current range of days without a meeting
            if (prefixSum == 0) {
                freeDays += currentDay - previousDay;
            }
            prefixSum += day.second;
            previousDay = currentDay;
        }

        // Add all days after the last day of meetings
        freeDays += days - previousDay + 1;
        return freeDays;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countDays(int days, int[][] meetings) {
        TreeMap<Integer, Integer> dayMap = new TreeMap<>();
        int prefixSum = 0, freeDays = 0, previousDay = days;

        for (int[] meeting : meetings) {
            // Set first day of meetings
            previousDay = Math.min(previousDay, meeting[0]);

            // Process start and end of meeting
            dayMap.put(meeting[0], dayMap.getOrDefault(meeting[0], 0) + 1);
            dayMap.put(
                meeting[1] + 1,
                dayMap.getOrDefault(meeting[1] + 1, 0) - 1
            );
        }

        // Add all days before the first day of meetings
        freeDays += (previousDay - 1);
        for (Map.Entry<Integer, Integer> day : dayMap.entrySet()) {
            int currentDay = day.getKey();

            // Add current range of days without a meeting
            if (prefixSum == 0) {
                freeDays += (currentDay - previousDay);
            }
            prefixSum += day.getValue();
            previousDay = currentDay;
        }

        // Add all days after the last day of meetings
        freeDays += days - previousDay + 1;
        return freeDays;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countDays(self, days: int, meetings: list[list[int]]) -> int:
        day_map = defaultdict(int)
        prefix_sum = 0
        free_days = 0
        previous_day = days

        for meeting in meetings:
            # Set first day of meetings
            previous_day = min(previous_day, meeting[0])

            # Process start and end of meeting
            day_map[meeting[0]] += 1
            day_map[meeting[1] + 1] -= 1

        # Add all days before the first day of meetings
        free_days += previous_day - 1
        for current_day in sorted(day_map.keys()):
            # Add current range of days without a meeting
            if prefix_sum == 0:
                free_days += current_day - previous_day
            prefix_sum += day_map[current_day]
            previous_day = current_day

        # Add all days after the last day of meetings
        free_days += days - previous_day + 1
        return free_days
```

</details>

<br>

## Approach 2: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int freeDays = 0, latestEnd = 0;

        // Sort meetings based on starting times
        sort(meetings.begin(), meetings.end());

        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            // Add current range of days without a meeting
            if (start > latestEnd + 1) {
                freeDays += start - latestEnd - 1;
            }

            // Update latest meeting end
            latestEnd = max(latestEnd, end);
        }

        // Add all days after the last day of meetings
        freeDays += days - latestEnd;

        return freeDays;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countDays(int days, int[][] meetings) {
        int freeDays = 0, latestEnd = 0;

        // Sort meetings based on starting times
        Arrays.sort(meetings, Comparator.comparingInt(a -> a[0]));

        for (int[] meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            // Add current range of days without a meeting
            if (start > latestEnd + 1) {
                freeDays += start - latestEnd - 1;
            }

            // Update latest meeting end
            latestEnd = Math.max(latestEnd, end);
        }

        // Add all days after the last day of meetings
        freeDays += days - latestEnd;

        return freeDays;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countDays(self, days: int, meetings: list[list[int]]) -> int:
        free_days = 0
        latest_end = 0

        # Sort meetings based on starting times
        meetings.sort()

        for start, end in meetings:
            # Add current range of days without a meeting
            if start > latest_end + 1:
                free_days += start - latest_end - 1

            # Update latest meeting end
            latest_end = max(latest_end, end)

        # Add all days after the last day of meetings
        free_days += days - latest_end

        return free_days
```

</details>
