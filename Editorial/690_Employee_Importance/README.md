# 690. Employee Importance

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/employee-importance/)  
`Array` `Hash Table` `Tree` `Depth-First Search` `Breadth-First Search`

**Problem Link:** [LeetCode 690 - Employee Importance](https://leetcode.com/problems/employee-importance/)

## Problem

You have a data structure of employee information, including the employee's unique ID, importance value, and direct subordinates' IDs.

You are given an array of employees employees where:

- employees[i].id is the ID of the ith employee.
- employees[i].importance is the importance value of the ith employee.
- employees[i].subordinates is a list of the IDs of the direct subordinates of the ith employee.

Given an integer id that represents an employee's ID, return the total importance value of this employee and all their direct and indirect subordinates.

### Example 1

```text
Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
Output: 11
Explanation: Employee 1 has an importance value of 5 and has two direct subordinates: employee 2 and employee 3.
They both have an importance value of 3.
Thus, the total importance value of employee 1 is 5 + 3 + 3 = 11.
```

### Example 2

```text
Input: employees = [[1,2,[5]],[5,-3,[]]], id = 5
Output: -3
Explanation: Employee 5 has an importance value of -3 and has no direct subordinates.
Thus, the total importance value of employee 5 is -3.
```

## Constraints

- 1 <= employees.length <= 2000
- 1 <= employees[i].id <= 2000
- All employees[i].id are unique.
- -100 <= employees[i].importance <= 100
- One employee has at most one direct leader and may have several subordinates.
- The IDs in employees[i].subordinates are valid IDs.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Nested List Weight Sum](https://leetcode.com/problems/nested-list-weight-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 690. Employee Importance

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Depth-First Search [Accepted] | Java, Python |

## Approach #1: Depth-First Search [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Map<Integer, Employee> emap;
    public int getImportance(List<Employee> employees, int queryid) {
        emap = new HashMap();
        for (Employee e: employees) {
            emap.put(e.id, e);
        }
        return dfs(queryid);
    }
    public int dfs(int eid) {
        Employee employee = emap.get(eid);
        int ans = employee.importance;
        for (Integer subid: employee.subordinates) {
            ans += dfs(subid);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def getImportance(self, employees, query_id):
        emap = {e.id: e for e in employees}
        def dfs(eid):
            employee = emap[eid]
            return (employee.importance +
                    sum(dfs(eid) for eid in employee.subordinates))
        return dfs(query_id)
```

</details>
