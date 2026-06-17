# 1209. Remove All Adjacent Duplicates in String II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)  
`String` `Stack`

**Problem Link:** [LeetCode 1209 - Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)

## Problem

You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

### Example 1

```text
Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
```

### Example 2

```text
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation:
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
```

### Example 3

```text
Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
```

## Constraints

- 1 <= s.length <= 105
- 2 <= k <= 104
- s only contains lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Replace Non-Coprime Numbers in Array](https://leetcode.com/problems/replace-non-coprime-numbers-in-array/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimize String Length](https://leetcode.com/problems/minimize-string-length/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1209. Remove All Adjacent Duplicates in String II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java |
| Memoise Count | C++, Java |
| Stack | C++, Java |
| Stack with Reconstruction | C++, Java |
| Two Pointers | C++, Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
string removeDuplicates(string s, int k) {
    int length = -1;
    while (length != s.size()) {
        length = s.size();
        for (int i = 0, count = 1; i < s.size(); ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                count = 1;
            } else if (++count == k) {
                s.erase(i - k + 1, k);
                break;
            }
        }
    }
    return s;
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public String removeDuplicates(String s, int k) {
    StringBuilder sb = new StringBuilder(s);
    int length = -1;
    while (length != sb.length()) {
        length = sb.length();
        for (int i = 0, count = 1; i < sb.length(); ++i) {
            if (i == 0 || sb.charAt(i) != sb.charAt(i - 1)) {
                count = 1;
            } else if (++count == k) {
                sb.delete(i - k + 1, i + 1);
                break;
            }
        }
    }
    return sb.toString();
}
```

</details>

<br>

## Approach 2: Memoise Count

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
string removeDuplicates(string s, int k) {
    vector<int> count(s.size());
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            count[i] = 1;
        } else {
            count[i] = count[i - 1] + 1;
            if (count[i] == k) {
                s.erase(i - k + 1, k);
                i = i - k;
            }
        };
    }
    return s;
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public String removeDuplicates(String s, int k) {
    StringBuilder sb = new StringBuilder(s);
    int count[] = new int[sb.length()];
    for (int i = 0; i < sb.length(); ++i) {
        if (i == 0 || sb.charAt(i) != sb.charAt(i - 1)) {
            count[i] = 1;
        } else {
            count[i] = count[i - 1] + 1;
            if (count[i] == k) {
                sb.delete(i - k + 1, i + 1);
                i = i - k;
            }
        }
    }
    return sb.toString();
}
```

</details>

<br>

## Approach 3: Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
string removeDuplicates(string s, int k) {
    stack<int> counts;
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            counts.push(1);
        } else if (++counts.top() == k) {
            counts.pop();
            s.erase(i - k + 1, k);
            i = i - k;
        }
    }
    return s;
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public String removeDuplicates(String s, int k) {
    StringBuilder sb = new StringBuilder(s);
    Stack<Integer> counts = new Stack<>();
    for (int i = 0; i < sb.length(); ++i) {
        if (i == 0 || sb.charAt(i) != sb.charAt(i - 1)) {
            counts.push(1);
        } else {
            int incremented = counts.pop() + 1;
            if (incremented == k) {
                sb.delete(i - k + 1, i + 1);
                i = i - k;
            } else {
                counts.push(incremented);
            }
        }
    }
    return sb.toString();
}
```

</details>

<br>

## Approach 4: Stack with Reconstruction

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
string removeDuplicates(string s, int k) {
    vector<pair<int, char>> counts;
    for (int i = 0; i < s.size(); ++i) {
        if (counts.empty() || s[i] != counts.back().second) {
            counts.push_back({ 1, s[i] });
        } else if (++counts.back().first == k) {
            counts.pop_back();
        }
    }
    s = "";
    for (auto &p : counts) {
        s += string(p.first, p.second);
    }
    return s;
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Pair {
    int cnt;
    char ch;
    public Pair(int cnt, char ch) {
        this.ch = ch;
        this.cnt = cnt;
    }
}
public String removeDuplicates(String s, int k) {
    Stack<Pair> counts = new Stack<>();
    for (int i = 0; i < s.length(); ++i) {
        if (counts.empty() || s.charAt(i) != counts.peek().ch) {
            counts.push(new Pair(1, s.charAt(i)));
        } else {
            if (++counts.peek().cnt == k) {
                counts.pop();
            }
        }
    }
    StringBuilder b = new StringBuilder();
    while (!counts.empty()) {
        Pair p = counts.pop();
        for (int i = 0; i < p.cnt; i++) {
            b.append(p.ch);
        }
    }
    return b.reverse().toString();
}
```

</details>

<br>

## Approach 5: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
string removeDuplicates(string s, int k) {
    auto j = 0;
    stack<int> counts;
    for (auto i = 0; i < s.size(); ++i, ++j) {
        s[j] = s[i];
        if (j == 0 || s[j] != s[j - 1]) {
            counts.push(1);
        } else if (++counts.top() == k) {
            counts.pop();
            j -= k;
        }
    }
    return s.substr(0, j);
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public String removeDuplicates(String s, int k) {
    Stack<Integer> counts = new Stack<>();
    char[] sa = s.toCharArray();
    int j = 0;
    for (int i = 0; i < s.length(); ++i, ++j) {
        sa[j] = sa[i];
        if (j == 0 || sa[j] != sa[j - 1]) {
            counts.push(1);
        } else {
            int incremented = counts.pop() + 1;
            if (incremented == k) {
                j = j - k;
            } else {
                counts.push(incremented);
            }
        }
    }
    return new String(sa, 0, j);
}
```

</details>
