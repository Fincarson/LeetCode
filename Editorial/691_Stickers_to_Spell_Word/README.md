# 691. Stickers to Spell Word

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/stickers-to-spell-word/)  
`Array` `Hash Table` `String` `Dynamic Programming` `Backtracking` `Bit Manipulation` `Memoization` `Bitmask`

**Problem Link:** [LeetCode 691 - Stickers to Spell Word](https://leetcode.com/problems/stickers-to-spell-word/)

## Problem

We are given n different types of stickers. Each sticker has a lowercase English word on it.

You would like to spell out the given string target by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.

Return the minimum number of stickers that you need to spell out target. If the task is impossible, return -1.

Note: In all test cases, all words were chosen randomly from the 1000 most common US English words, and target was chosen as a concatenation of two random words.

### Example 1

```text
Input: stickers = ["with","example","science"], target = "thehat"
Output: 3
Explanation:
We can use 2 "with" stickers, and 1 "example" sticker.
After cutting and rearrange the letters of those stickers, we can form the target "thehat".
Also, this is the minimum number of stickers necessary to form the target string.
```

### Example 2

```text
Input: stickers = ["notice","possible"], target = "basicbasic"
Output: -1
Explanation:
We cannot form the target "basicbasic" from cutting letters from the given stickers.
```

## Constraints

- n == stickers.length
- 1 <= n <= 50
- 1 <= stickers[i].length <= 10
- 1 <= target.length <= 15
- stickers[i] and target consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Ransom Note](https://leetcode.com/problems/ransom-note/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 691. Stickers to Spell Word

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Optimized Exhaustive Search | Java, Python |
| Dynamic Programming | Java, Python |

## Approach 1: Optimized Exhaustive Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int best;
    int[][] stickersCount;
    int[] targetCount;

    public void search(int ans, int row) {
        if (ans >= best) return;
        if (row == stickersCount.length) {
            for (int c: targetCount) if (c > 0) return;
            best = ans;
            return;
        }

        int used = 0;
        for (int i = 0; i < stickersCount[row].length; i++) {
            if (targetCount[i] > 0 && stickersCount[row][i] > 0) {
                used = Math.max(used, (targetCount[i] - 1) / stickersCount[row][i] + 1);
            }
        }
        for (int i = 0; i < stickersCount[row].length; i++) {
            targetCount[i] -= used * stickersCount[row][i];
        }

        search(ans + used, row + 1);
        while (used > 0) {
            for (int i = 0; i < stickersCount[row].length; i++) {
                targetCount[i] += stickersCount[row][i];
            }
            used--;
            search(ans + used, row + 1);
        }
    }

    public int minStickers(String[] stickers, String target) {
        int[] targetNaiveCount = new int[26];
        for (char c: target.toCharArray()) targetNaiveCount[c - 'a']++;

        int[] index = new int[26];
        int t = 0;
        for (int i = 0; i < 26; i++) {
            if (targetNaiveCount[i] > 0) {
                index[i] = t++;
            } else {
                index[i] = -1;
            }
        }

        targetCount = new int[t];
        t = 0;
        for (int c: targetNaiveCount) if (c > 0) {
            targetCount[t++] = c;
        }

        stickersCount = new int[stickers.length][t];
        for (int i = 0; i < stickers.length; i++) {
            for (char c: stickers[i].toCharArray()) {
                int j = index[c - 'a'];
                if (j >= 0) stickersCount[i][j]++;
            }
        }

        int anchor = 0;
        for (int i = 0; i < stickers.length; i++) {
            for (int j = anchor; j < stickers.length; j++) if (j != i) {
                boolean dominated = true;
                for (int k = 0; k < t; k++) {
                    if (stickersCount[i][k] > stickersCount[j][k]) {
                        dominated = false;
                        break;
                    }
                }

                if (dominated) {
                    int[] tmp = stickersCount[i];
                    stickersCount[i] = stickersCount[anchor];
                    stickersCount[anchor++] = tmp;
                    break;
                }
            }
        }

        best = target.length() + 1;
        search(0, anchor);
        return best <= target.length() ? best : -1;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def minStickers(self, stickers, target):
        t_count = collections.Counter(target)
        A = [collections.Counter(sticker) & t_count
             for sticker in stickers]

        for i in range(len(A) - 1, -1, -1):
            if any(A[i] == A[i] & A[j] for j in range(len(A)) if i != j):
                A.pop(i)

        self.best = len(target) + 1
        def search(ans = 0):
            if ans >= self.best: return
            if not A:
                if all(t_count[letter] <= 0 for letter in t_count):
                    self.best = ans
                return

            sticker = A.pop()
            used = max((t_count[letter] - 1) // sticker[letter] + 1
                        for letter in sticker)
            used = max(used, 0)

            for c in sticker:
                t_count[c] -= used * sticker[c]

            search(ans + used)
            for i in range(used - 1, -1, -1):
                for letter in sticker:
                    t_count[letter] += sticker[letter]
                search(ans + i)

            A.append(sticker)

        search()
        return self.best if self.best <= len(target) else -1
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minStickers(String[] stickers, String target) {
        int N = target.length();
        int[] dp = new int[1 << N];
        for (int i = 1; i < 1 << N; i++) dp[i] = -1;

        for (int state = 0; state < 1 << N; state++) {
            if (dp[state] == -1) continue;
            for (String sticker: stickers) {
                int now = state;
                for (char letter: sticker.toCharArray()) {
                    for (int i = 0; i < N; i++) {
                        if (((now >> i) & 1) == 1) continue;
                        if (target.charAt(i) == letter) {
                            now |= 1 << i;
                            break;
                        }
                    }
                }
                if (dp[now] == -1 || dp[now] > dp[state] + 1) {
                    dp[now] = dp[state] + 1;
                }
            }
        }
        return dp[(1 << N) - 1];
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def minStickers(self, stickers, target):
        t_count = collections.Counter(target)
        A = [collections.Counter(sticker) & t_count
             for sticker in stickers]

        for i in range(len(A) - 1, -1, -1):
            if any(A[i] == A[i] & A[j] for j in range(len(A)) if i != j):
                A.pop(i)

        stickers = ["".join(s_count.elements()) for s_count in A]
        dp = [-1] * (1 << len(target))
        dp[0] = 0
        for state in xrange(1 << len(target)):
            if dp[state] == -1: continue
            for sticker in stickers:
                now = state
                for letter in sticker:
                    for i, c in enumerate(target):
                        if (now >> i) & 1: continue
                        if c == letter:
                            now |= 1 << i
                            break
                if dp[now] == -1 or dp[now] > dp[state] + 1:
                    dp[now] = dp[state] + 1

        return dp[-1]
```

</details>
