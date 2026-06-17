# 185. Department Top Three Salaries

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/department-top-three-salaries/)  
`Database`

**Problem Link:** [LeetCode 185 - Department Top Three Salaries](https://leetcode.com/problems/department-top-three-salaries/)

## Problem

Table: Employee

```text
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| name         | varchar |
| salary       | int     |
| departmentId | int     |
+--------------+---------+
id is the primary key (column with unique values) for this table.
departmentId is a foreign key (reference column) of the ID from the Department table.
Each row of this table indicates the ID, name, and salary of an employee. It also contains the ID of their department.
```

Table: Department

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the ID of a department and its name.
```

A company's executives are interested in seeing who earns the most money in each of the company's departments. A high earner in a department is an employee who has a salary in the top three unique salaries for that department.

Write a solution to find the employees who are high earners in each of the departments.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Employee table:
+----+-------+--------+--------------+
| id | name  | salary | departmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 85000  | 1            |
| 2  | Henry | 80000  | 2            |
| 3  | Sam   | 60000  | 2            |
| 4  | Max   | 90000  | 1            |
| 5  | Janet | 69000  | 1            |
| 6  | Randy | 85000  | 1            |
| 7  | Will  | 70000  | 1            |
+----+-------+--------+--------------+
Department table:
+----+-------+
| id | name  |
+----+-------+
| 1  | IT    |
| 2  | Sales |
+----+-------+
Output:
+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| IT         | Joe      | 85000  |
| IT         | Randy    | 85000  |
| IT         | Will     | 70000  |
| Sales      | Henry    | 80000  |
| Sales      | Sam      | 60000  |
+------------+----------+--------+
Explanation:
In the IT department:
- Max earns the highest unique salary
- Both Randy and Joe earn the second-highest unique salary
- Will earns the third-highest unique salary

In the Sales department:
- Henry earns the highest salary
- Sam earns the second-highest salary
- There is no third-highest salary as there are only two employees
```

## Constraints

- There are no employees with the exact same name, salary and department.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 185. Department Top Three Salaries

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Return the First n Rows Using nlargest() | Pandas |
| Return the First n Rows Using rank() | Pandas |
| Return the First n Rows Using Correlated Subquery | SQL |
| Return the First n Rows Using DENSE_RANK() | SQL |

## Approach 1: Return the First n Rows Using nlargest()

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
Ã¢â‚¬â€¹
def top_three_salaries(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    
    Employee_Department = employee.merge(department, left_on='departmentId', right_on='id').rename(columns = {'name_y': 'Department'})

    Employee_Department = Employee_Department[['Department', 'departmentId', 'salary']].drop_duplicates()
    
    top_salary = Employee_Department.groupby(['Department', 'departmentId']).salary.nlargest(3).reset_index()
    
    df = top_salary.merge(employee, on=['departmentId', 'salary'])
    
    return df[['Department', 'name', 'salary']].rename(columns = {'name': 'Employee', 'salary': 'Salary'})
```

</details>

<br>

## Approach 2: Return the First n Rows Using rank()

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
Ã¢â‚¬â€¹
def top_three_salaries(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:

    top_salary = employee[employee.groupby('departmentId').salary.rank(method='dense', ascending=False) <= 3]

    employee_department = top_salary.merge(department, left_on='departmentId', right_on='id')[['name_y', 'name_x', 'salary']]

    return employee_department.rename(columns = {'name_y': 'Department', 'name_x': 'Employee', 'salary': 'Salary'})
```

</details>

<br>

## Approach 1: Return the First n Rows Using Correlated Subquery

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT d.name AS 'Department', 
       e1.name AS 'Employee', 
       e1.salary AS 'Salary' 
FROM Employee e1
JOIN Department d
ON e1.departmentId = d.id
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
(
    SELECT COUNT(DISTINCT e2.salary)
    FROM Employee e2
    WHERE e2.salary > e1.salary AND e1.departmentId = e2.departmentId
)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT d.name AS 'Department', 
       e1.name AS 'Employee', 
       e1.salary AS 'Salary' 
FROM Employee e1
JOIN Department d
ON e1.departmentId = d.id 
WHERE
    3 > (SELECT COUNT(DISTINCT e2.salary)
        FROM Employee e2
        WHERE e2.salary > e1.salary AND e1.departmentId = e2.departmentId);
```

</details>

<br>

## Approach 2: Return the First n Rows Using DENSE_RANK()

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH employee_department AS
    (
    SELECT d.id, 
        d.name AS Department, 
        salary AS Salary, 
        e.name AS Employee, 
        DENSE_RANK()OVER(PARTITION BY d.id ORDER BY salary DESC) AS rnk
    FROM Department d
    JOIN Employee e
    ON d.id = e.departmentId
    )
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT Department, Employee, Salary
FROM employee_department
WHERE rnk <= 3
```

</details>
