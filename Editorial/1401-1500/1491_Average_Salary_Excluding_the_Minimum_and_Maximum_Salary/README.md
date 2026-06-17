# 1491. Average Salary Excluding the Minimum and Maximum Salary

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/)  
`Array` `Sorting`

**Problem Link:** [LeetCode 1491 - Average Salary Excluding the Minimum and Maximum Salary](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/)

## Problem

You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

### Example 1

```text
Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
```

### Example 2

```text
Input: salary = [1000,2000,3000]
Output: 2000.00000
Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
```

## Constraints

- 3 <= salary.length <= 100
- 1000 <= salary[i] <= 106
- All the integers of salary are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1491. Average Salary Excluding the Minimum and Maximum Salary

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: | C++, Java |

## Approach:

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double average(vector<int>& salaries) {
        int minSalary = INT_MAX;
        int maxSalary = INT_MIN;
        int sum = 0;
        
        for (int salary : salaries) {
            // Sum of all the salaries.
            sum += salary;
            // Update the minimum salary.
            minSalary = min(minSalary, salary);
            // Update the maximum salary.
            maxSalary = max(maxSalary, salary);
        }
        
        // Divide the sum by total size - 2, as we exclude minimum and maximum values.
        return (double)(sum - minSalary - maxSalary) / (double)(salaries.size() - 2);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public double average(int[] salaries) {
        int minSalary = Integer.MAX_VALUE;
        int maxSalary = Integer.MIN_VALUE;
        int sum = 0;

        for (int salary : salaries) {
            // Sum of all the salaries.
            sum += salary;
            // Update the minimum salary.
            minSalary = Math.min(minSalary, salary);
            // Update the maximum salary.
            maxSalary = Math.max(maxSalary, salary);
        }

        // Divide the sum by total size - 2, as we exclude minimum and maximum values.
        return (double)(sum - minSalary - maxSalary) / (double)(salaries.length - 2);
    }
}
```

</details>
