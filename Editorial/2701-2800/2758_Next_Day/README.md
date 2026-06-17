# 2758. Next Day

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/next-day/)  

**Problem Link:** [LeetCode 2758 - Next Day](https://leetcode.com/problems/next-day/)

## Problem

Write code that enhances all date objects such that you can call the date.nextDay() method on any date object and it will return the next day in the format YYYY-MM-DD as a string.

### Example 1

```text
Input: date = "2014-06-20"
Output: "2014-06-21"
Explanation:
const date = new Date("2014-06-20");
date.nextDay(); // "2014-06-21"
```

### Example 2

```text
Input: date = "2017-10-31"
Output: "2017-11-01"
Explanation: The day after 2017-10-31 is 2017-11-01.
```

## Constraints

- new Date(date) is a valid date object

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2758. Next Day

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using timestamp | JavaScript, TypeScript |
| Date Manipulation Using Built-in Methods | JavaScript, TypeScript |
| Date Manipulation with Array | JavaScript, TypeScript |

## Approach 1: Using timestamp

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
Date.prototype.nextDay = function() {
    const next = this.getTime() + 24 * 60 * 60 * 1000;
    return new Date(next).toISOString().split("T")[0];
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
    interface Date {
        nextDay(): string;
    }
}

Date.prototype.nextDay = function() {
    const next = this.getTime() + 24 * 60 * 60 * 1000;
    return new Date(next).toISOString().split("T")[0];
};
```

</details>

<br>

## Approach 2: Date Manipulation Using Built-in Methods

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
Date.prototype.nextDay = function() {
  const currentDate = new Date(this.getTime());
  currentDate.setDate(currentDate.getDate() + 1);

  const year = currentDate.getFullYear();
  const month = String(currentDate.getMonth() + 1).padStart(2, '0');
  const day = String(currentDate.getDate()).padStart(2, '0');

  return `${year}-${month}-${day}`;
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
    interface Date {
        nextDay(): string;
    }
}

Date.prototype.nextDay = function() {
    const currentDate: Date = new Date(this.getTime());
    currentDate.setDate(currentDate.getDate() + 1);
    
    const year: number = currentDate.getFullYear();
    const month: string = String(currentDate.getMonth() + 1).padStart(2, '0');
    const day: string = String(currentDate.getDate()).padStart(2, '0');

    return `${year}-${month}-${day}`;
};
```

</details>

<br>

## Approach 3: Date Manipulation with Array

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
Date.prototype.nextDay = function() {
    const daysInMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    const year = this.getFullYear();
    const month = this.getMonth();    
    const day = this.getDate();      
    
    // If the current year is a leap year
    const isLeapYear = (year % 4 === 0 && year % 100 !== 0) || (year % 400 === 0);
    if (isLeapYear) {
        daysInMonth[1] = 29; // Feb days  
    }

    const maxDays = daysInMonth[month];
    
    let nextYear = year;
    let nextMonth = month;
    let nextDay = day + 1;

    // Check if the next day exceeds the maximum days in the current month
    if (nextDay > maxDays) {
        nextDay = 1;         
        nextMonth += 1;
        if (nextMonth > 11) {
            nextMonth = 0;
            nextYear += 1;
        }
    }

    // YYYY-MM-DD
    const formattedDate = `${nextYear}-${String(nextMonth + 1).padStart(2, '0')}-${String(nextDay).padStart(2, '0')}`;
    return formattedDate;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
    interface Date {
        nextDay(): string;
    }
}

Date.prototype.nextDay = function() {
    const daysInMonth: number[] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    const year: number = this.getFullYear();
    const month: number = this.getMonth();
    const day: number = this.getDate();

    // If the current year is a leap year
    const isLeapYear: boolean = (year % 4 === 0 && year % 100 !== 0) || (year % 400 === 0);
    if (isLeapYear) {
        daysInMonth[1] = 29;// Feb days  
    }

    const maxDays: number = daysInMonth[month];
    
    let nextYear: number = year;
    let nextMonth: number = month;
    let nextDay: number = day + 1;

    // Check if the next day exceeds the maximum days in the current month
    if (nextDay > maxDays) {
        nextDay = 1;
        nextMonth += 1;
        if (nextMonth > 11) {
            nextMonth = 0;
            nextYear += 1;
        }
    }

    // YYYY-MM-DD
    const formattedDate: string = `${nextYear}-${String(nextMonth + 1).padStart(2, '0')}-${String(nextDay).padStart(2, '0')}`;
    return formattedDate;
};
```

</details>
