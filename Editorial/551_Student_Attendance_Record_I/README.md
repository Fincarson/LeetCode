# 551. Student Attendance Record I

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/student-attendance-record-i/)  
`String`

**Problem Link:** [LeetCode 551 - Student Attendance Record I](https://leetcode.com/problems/student-attendance-record-i/)

## Problem

You are given a string s representing an attendance record for a student where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

- 'A': Absent.
- 'L': Late.
- 'P': Present.

The student is eligible for an attendance award if they meet both of the following criteria:

- The student was absent ('A') for strictly fewer than 2 days total.
- The student was never late ('L') for 3 or more consecutive days.

Return true if the student is eligible for an attendance award, or false otherwise.

### Example 1

```text
Input: s = "PPALLP"
Output: true
Explanation: The student has fewer than 2 absences and was never late 3 or more consecutive days.
```

### Example 2

```text
Input: s = "PPALLL"
Output: false
Explanation: The student was late 3 consecutive days in the last 3 days, so is not eligible for the award.
```

## Constraints

- 1 <= s.length <= 1000
- s[i] is either 'A', 'L', or 'P'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Student Attendance Record II](https://leetcode.com/problems/student-attendance-record-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 551. Student Attendance Record I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Simple Solution [Accepted] | Java |
| Approach #2 Better Solution [Accepted] | Java |
| Approach #3 Single pass Solution (Without indexOf method) [Accepted] | Java |
| Approach #4 Using Regex [Accepted] | Java |

## Approach #1 Simple Solution [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {
    public boolean checkRecord(String s) {
        int count=0;
        for(int i=0;i<s.length();i++)
            if(s.charAt(i)=='A')
                count++;
        return count<2 && s.indexOf("LLL")<0;
    }
}
```

</details>

<br>

## Approach #2 Better Solution [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean checkRecord(String s) {
        int count=0;
        for(int i=0;i<s.length() && count<2 ;i++)
            if(s.charAt(i)=='A')
                count++;
        return count<2 && s.indexOf("LLL")<0;
    }
}
```

</details>

<br>

## Approach #3 Single pass Solution (Without indexOf method) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean checkRecord(String s) {
        int countA = 0;
        for (int i = 0; i < s.length() && countA < 2; i++) {
            if (s.charAt(i) == 'A')
                countA++;
            if (i <= s.length() - 3 && s.charAt(i) == 'L' && s.charAt(i + 1) == 'L' && s.charAt(i + 2) == 'L')
                return false;
        }
        return countA < 2;
    }
}
```

</details>

<br>

## Approach #4 Using Regex [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {
    public boolean checkRecord(String s) {
        return !s.matches(".*(A.*A|LLL).*");
    }
}
```

</details>
