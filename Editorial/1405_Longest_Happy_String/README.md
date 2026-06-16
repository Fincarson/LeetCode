# 1405. Longest Happy String

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-happy-string/)  
`String` `Greedy` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1405 - Longest Happy String](https://leetcode.com/problems/longest-happy-string/)

## Problem

A string s is called happy if it satisfies the following conditions:

- s only contains the letters 'a', 'b', and 'c'.
- s does not contain any of "aaa", "bbb", or "ccc" as a substring.
- s contains at most a occurrences of the letter 'a'.
- s contains at most b occurrences of the letter 'b'.
- s contains at most c occurrences of the letter 'c'.

Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

### Example 1

```text
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
```

### Example 2

```text
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.
```

## Constraints

- 0 <= a, b, c <= 100
- a + b + c > 0

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reorganize String](https://leetcode.com/problems/reorganize-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1405. Longest Happy String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Priority Queue | C++, Java, Python3 |
| Using Counters | C++, Java, Python3 |

## Approach 1: Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        // Add the counts of a, b and c in priority queue.
        if (a > 0) {
            pq.push({a, 'a'});
        }

        if (b > 0) {
            pq.push({b, 'b'});
        }

        if (c > 0) {
            pq.push({c, 'c'});
        }

        string ans = "";
        while (!pq.empty()) {
            pair<int, char> p = pq.top();
            pq.pop();
            int count = p.first;
            char character = p.second;
            // If three consecutive characters exist, pick the second most
            // frequent character.
            if (ans.length() >= 2 and ans[ans.length() - 1] == p.second and
                ans[ans.length() - 2] == p.second) {
                if (pq.empty()) break;

                pair<int, char> temp = pq.top();
                pq.pop();
                ans += temp.second;
                if (temp.first - 1 > 0) {
                    pq.push({temp.first - 1, temp.second});
                }
            } else {
                count--;
                ans = ans + character;
            }

            // If count is greater than zero, add it to priority queue.
            if (count > 0) {
                pq.push({count, character});
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String longestDiverseString(int a, int b, int c) {
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>((x, y) ->
            (y.count - x.count)
        );
        // Add the counts of a, b and c in priority queue.
        if (a > 0) {
            pq.add(new Pair(a, 'a'));
        }

        if (b > 0) {
            pq.add(new Pair(b, 'b'));
        }

        if (c > 0) {
            pq.add(new Pair(c, 'c'));
        }

        StringBuilder ans = new StringBuilder();
        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            int count = p.count;
            char character = p.character;
            // If three consecutive characters exists, pick the second most
            // frequent character.
            if (
                ans.length() >= 2 &&
                ans.charAt(ans.length() - 1) == p.character &&
                ans.charAt(ans.length() - 2) == p.character
            ) {
                if (pq.isEmpty()) break;

                Pair temp = pq.poll();
                ans.append(temp.character);
                if (temp.count - 1 > 0) {
                    pq.add(new Pair(temp.count - 1, temp.character));
                }
            } else {
                count--;
                ans.append(character);
            }

            // If count is greater than zero, add it to priority queue.
            if (count > 0) {
                pq.add(new Pair(count, character));
            }
        }
        return ans.toString();
    }

    class Pair {

        int count;
        char character;

        Pair(int count, char character) {
            this.count = count;
            this.character = character;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        pq = []
        if a > 0:
            heapq.heappush(pq, (-a, "a"))
        if b > 0:
            heapq.heappush(pq, (-b, "b"))
        if c > 0:
            heapq.heappush(pq, (-c, "c"))

        result = []
        while pq:
            count, character = heapq.heappop(pq)
            count = -count
            if (
                len(result) >= 2
                and result[-1] == character
                and result[-2] == character
            ):
                if not pq:
                    break
                tempCnt, tempChar = heapq.heappop(pq)
                result.append(tempChar)
                if (tempCnt + 1) < 0:
                    heapq.heappush(pq, (tempCnt + 1, tempChar))
                heapq.heappush(pq, (-count, character))
            else:
                count -= 1
                result.append(character)
                if count > 0:
                    heapq.heappush(pq, (-count, character))

        return "".join(result)
```

</details>

<br>

## Approach 2: Using Counters

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int curra = 0, currb = 0, currc = 0;
        // Maximum total iterations possible is given by the sum of a, b and c.
        int totalIterations = a + b + c;
        string ans = "";

        for (int i = 0; i < totalIterations; i++) {
            if ((a >= b and a >= c and curra != 2) or
                (a > 0 and (currb == 2 or currc == 2))) {
                // If 'a' is maximum and it's streak is less than 2, or if
                // streak of 'b' or 'c' is 2, then 'a' will be the next
                // character.
                ans += 'a';
                a--;
                curra++;
                currb = 0;
                currc = 0;
            } else if ((b >= a and b >= c and currb != 2) or
                       (b > 0 and (currc == 2 or curra == 2))) {
                // If 'b' is maximum and it's streak is less than 2, or if
                // streak of 'a' or 'c' is 2, then 'b' will be the next
                // character.
                ans += 'b';
                b--;
                currb++;
                curra = 0;
                currc = 0;
            } else if ((c >= a and c >= b and currc != 2) or
                       (c > 0 and (curra == 2 or currb == 2))) {
                // If 'c' is maximum and it's streak is less than 2, or if
                // streak of 'a' or 'b' is 2, then 'c' will be the next
                // character.
                ans += 'c';
                c--;
                currc++;
                curra = 0;
                currb = 0;
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String longestDiverseString(int a, int b, int c) {
        int curra = 0, currb = 0, currc = 0;
        // Maximum total iterations possible is given by the sum of a, b and c.
        int totalIterations = a + b + c;
        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < totalIterations; i++) {
            if (
                (a >= b && a >= c && curra != 2) ||
                (a > 0 && (currb == 2 || currc == 2))
            ) {
                // If 'a' is maximum and it's streak is less than 2, or if streak of 'b' or 'c' is 2, then 'a' will be the next character.
                ans.append('a');
                a--;
                curra++;
                currb = 0;
                currc = 0;
            } else if (
                (b >= a && b >= c && currb != 2) ||
                (b > 0 && (currc == 2 || curra == 2))
            ) {
                // If 'b' is maximum and it's streak is less than 2, or if streak of 'a' or 'c' is 2, then 'b' will be the next character.
                ans.append('b');
                b--;
                currb++;
                curra = 0;
                currc = 0;
            } else if (
                (c >= a && c >= b && currc != 2) ||
                (c > 0 && (curra == 2 || currb == 2))
            ) {
                // If 'c' is maximum and it's streak is less than 2, or if streak of 'a' or 'b' is 2, then 'c' will be the next character.
                ans.append('c');
                c--;
                currc++;
                curra = 0;
                currb = 0;
            }
        }
        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        curra, currb, currc = 0, 0, 0
        # Maximum total iterations possible is given by the sum of a, b, and c.
        total_iterations = a + b + c
        result = []

        for i in range(total_iterations):
            if (a >= b and a >= c and curra != 2) or (
                a > 0 and (currb == 2 or currc == 2)
            ):
                # If 'a' is maximum and its streak is less than 2, or if streak of 'b' or 'c' is 2, then 'a' will be the next character.
                result.append("a")
                a -= 1
                curra += 1
                currb = 0
                currc = 0
            elif (b >= a and b >= c and currb != 2) or (
                b > 0 and (currc == 2 or curra == 2)
            ):
                # If 'b' is maximum and its streak is less than 2, or if streak of 'a' or 'c' is 2, then 'b' will be the next character.
                result.append("b")
                b -= 1
                currb += 1
                curra = 0
                currc = 0
            elif (c >= a and c >= b and currc != 2) or (
                c > 0 and (curra == 2 or currb == 2)
            ):
                # If 'c' is maximum and its streak is less than 2, or if streak of 'a' or 'b' is 2, then 'c' will be the next character.
                result.append("c")
                c -= 1
                currc += 1
                curra = 0
                currb = 0

        return "".join(result)
```

</details>
