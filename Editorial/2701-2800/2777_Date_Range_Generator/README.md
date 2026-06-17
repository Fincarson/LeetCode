# 2777. Date Range Generator

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/date-range-generator/)  

**Problem Link:** [LeetCode 2777 - Date Range Generator](https://leetcode.com/problems/date-range-generator/)

## Problem

Given a start date start, an end date end, and a positive integer step, return a generator object that yields dates in the range from start to end inclusive.

The value of step indicates the number of days between consecutive yielded values.

All yielded dates must be in the string format YYYY-MM-DD.

### Example 1

```text
Input: start = "2023-04-01", end = "2023-04-04", step = 1
Output: ["2023-04-01","2023-04-02","2023-04-03","2023-04-04"]
Explanation:
const g = dateRangeGenerator(start, end, step);
g.next().value // '2023-04-01'
g.next().value // '2023-04-02'
g.next().value // '2023-04-03'
g.next().value // '2023-04-04'
```

### Example 2

```text
Input: start = "2023-04-10", end = "2023-04-20", step = 3
Output: ["2023-04-10","2023-04-13","2023-04-16","2023-04-19"]
Explanation:
const g = dateRangeGenerator(start, end, step);
g.next().value // '2023-04-10'
g.next().value // '2023-04-13'
g.next().value // '2023-04-16'
g.next().value // '2023-04-19'
```

### Example 3

```text
Input: start = "2023-04-10", end = "2023-04-10", step = 1
Output: ["2023-04-10"]
Explanation:
const g = dateRangeGenerator(start, end, step);
g.next().value // '2023-04-10'
```

## Constraints

- new Date(start) <= new Date(end)
- start and end dates are in the string format YYYY-MM-DD
- 0 <= The difference in days between the start date and the end date <= 1500
- 1 <= step <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2777. Date Range Generator

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | JavaScript, TypeScript |
| Using the `yield` keyword | JavaScript, TypeScript |
| Using the `ISOString` and `yield` keyword | JavaScript, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {string} start
 * @param {string} end
 * @param {number} step
 * @yields {string}
 */
var dateRangeGenerator = function(start, end, step) {
    const startDate = new Date(start);
    const endDate = new Date(end);
    const datesList = [];

    while (startDate <= endDate) {
        datesList.push(formatDate(startDate));
        startDate.setDate(startDate.getDate() + step);
    }

    return datesList;
}

// Helper function to format the date
function formatDate(date) {
    const year = date.getFullYear();
    const month = String(date.getMonth() + 1).padStart(2, '0');
    const day = String(date.getDate()).padStart(2, '0');
    return `${year}-${month}-${day}`;
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function dateRangeGenerator(start: string, end: string, step: number): string[] {
    const startDate = new Date(start);
    const endDate = new Date(end);
    const datesList: string[] = [];

    while (startDate <= endDate) {
        datesList.push(formatDate(startDate));
        startDate.setDate(startDate.getDate() + step);
    }

    return datesList;
}

// Helper function to format the date
function formatDate(date: Date): string {
    const year = date.getFullYear();
    const month = String(date.getMonth() + 1).padStart(2, '0');
    const day = String(date.getDate()).padStart(2, '0');
    return `${year}-${month}-${day}`;
}
```

</details>

<br>

## Approach 2: Using the `yield` keyword

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {string} start
 * @param {string} end
 * @param {number} step
 * @yields {string}
 */
var dateRangeGenerator = function*(start, end, step) {
    const startDate = new Date(start);
    const endDate = new Date(end).getTime();

    while (startDate.getTime() <= endDate) {
        const date = String(startDate.getDate()).padStart(2, '0');
        const month = String(startDate.getMonth() + 1).padStart(2, '0');
        const year = String(startDate.getFullYear()).padStart(2, '0');
        yield `${year}-${month}-${date}`;

        const next = startDate.getDate() + step;
        startDate.setDate(next);
    }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function* dateRangeGenerator(start: string, end: string, step: number): Generator<string> {
    const startDate = new Date(start);
    const endDate = new Date(end).getTime();

    while (startDate.getTime() <= endDate) {
        const date = String(startDate.getDate()).padStart(2, '0');
        const month = String(startDate.getMonth() + 1).padStart(2, '0');
        const year = String(startDate.getFullYear()).padStart(2, '0');
        yield `${year}-${month}-${date}`;

        const next = startDate.getDate() + step;
        startDate.setDate(next);
    }
};
```

</details>

<br>

## Approach 3: Using the `ISOString` and `yield` keyword

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {string} start
 * @param {string} end
 * @param {number} step
 * @yields {string}
 */
var dateRangeGenerator = function* (start, end, step) {
    const startDate = new Date(start);
    const endDate = new Date(end);

    while (startDate <= endDate) {
        yield startDate.toISOString().split('T')[0].trim();
        startDate.setDate(startDate.getDate() + step);
    }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function* dateRangeGenerator(start: string, end: string, step: number) : Generator<string> {
    const startDate = new Date(start);
    const endDate = new Date(end);

    while(startDate<=endDate){
        yield startDate.toISOString().split('T')[0].trim();
        startDate.setDate(startDate.getDate()+step);
    }
};
```

</details>
