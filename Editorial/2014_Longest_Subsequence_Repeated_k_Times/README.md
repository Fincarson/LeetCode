# 2014. Longest Subsequence Repeated k Times

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/longest-subsequence-repeated-k-times/)  
`Hash Table` `Two Pointers` `String` `Backtracking` `Counting` `Enumeration`

**Problem Link:** [LeetCode 2014 - Longest Subsequence Repeated k Times](https://leetcode.com/problems/longest-subsequence-repeated-k-times/)

## Problem

You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.

- For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".

Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.

### Example 1

```text
Input: s = "letsleetcode", k = 2
Output: "let"
Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
"let" is the lexicographically largest one.
```

### Example 2

```text
Input: s = "bb", k = 2
Output: "b"
Explanation: The longest subsequence repeated 2 times is "b".
```

### Example 3

```text
Input: s = "ab", k = 2
Output: ""
Explanation: There is no subsequence repeated 2 times. Empty string is returned.
```

## Constraints

- n == s.length
- 2 <= k <= 2000
- 2 <= n < min(2001, k * 8)
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Substring with At Least K Repeating Characters](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2014. Longest Subsequence Repeated k Times

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Brute-force Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Brute-force Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    char* str;
    int len;
} QueueNode;

typedef struct {
    QueueNode* data;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (QueueNode*)malloc(capacity * sizeof(QueueNode));
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue* q, char* str, int len) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear].str = strdup(str);
    q->data[q->rear].len = len;
    q->size++;
}

QueueNode dequeue(Queue* q) {
    if (q->size == 0) {
        QueueNode empty = {NULL, 0};
        return empty;
    }
    QueueNode item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

bool isKRepeatedSubsequence(const char* s, const char* t, int k) {
    int pos = 0, matched = 0;
    int m = strlen(t);
    for (int i = 0; s[i]; i++) {
        if (s[i] == t[pos]) {
            pos++;
            if (pos == m) {
                pos = 0;
                matched++;
                if (matched == k) {
                    return true;
                }
            }
        }
    }
    return false;
}

char* longestSubsequenceRepeatedK(char* s, int k) {
    int freq[26] = {0};
    for (int i = 0; s[i]; i++) {
        freq[s[i] - 'a']++;
    }
    char candidate[26];
    int candidateSize = 0;
    for (int i = 25; i >= 0; i--) {
        if (freq[i] >= k) {
            candidate[candidateSize++] = 'a' + i;
        }
    }

    Queue* q = createQueue(10000);
    for (int i = 0; i < candidateSize; i++) {
        char str[2] = {candidate[i], '\0'};
        enqueue(q, str, 1);
    }
    char* ans = strdup("");
    while (q->size > 0) {
        QueueNode curr = dequeue(q);
        if (curr.len > strlen(ans)) {
            free(ans);
            ans = strdup(curr.str);
        }
        // generate the next candidate string
        for (int i = 0; i < candidateSize; i++) {
            char* next = (char*)malloc(curr.len + 2);
            strcpy(next, curr.str);
            next[curr.len] = candidate[i];
            next[curr.len + 1] = '\0';
            if (isKRepeatedSubsequence(s, next, k)) {
                enqueue(q, next, curr.len + 1);
            } else {
                free(next);
            }
        }
        free(curr.str);
    }

    free(q->data);
    free(q);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        vector<char> candidate;
        for (int i = 25; i >= 0; i--) {
            if (freq[i] >= k) {
                candidate.push_back('a' + i);
            }
        }
        queue<string> q;
        for (char ch : candidate) {
            q.push(string(1, ch));
        }

        string ans = "";
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            if (curr.size() > ans.size()) {
                ans = curr;
            }
            // generate the next candidate string
            for (char ch : candidate) {
                string next = curr + ch;
                if (isKRepeatedSubsequence(s, next, k)) {
                    q.push(next);
                }
            }
        }

        return ans;
    }

    bool isKRepeatedSubsequence(const string& s, const string& t, int k) {
        int pos = 0, matched = 0;
        int n = s.size(), m = t.size();
        for (char ch : s) {
            if (ch == t[pos]) {
                pos++;
                if (pos == m) {
                    pos = 0;
                    matched++;
                    if (matched == k) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string LongestSubsequenceRepeatedK(string s, int k) {
        int[] freq = new int[26];
        foreach (char ch in s) {
            freq[ch - 'a']++;
        }

        List<char> candidate = new List<char>();
        for (int i = 25; i >= 0; i--) {
            if (freq[i] >= k) {
                candidate.Add((char)('a' + i));
            }
        }

        Queue<string> q = new Queue<string>();
        foreach (char ch in candidate) {
            q.Enqueue(ch.ToString());
        }

        string ans = "";
        while (q.Count > 0) {
            string curr = q.Dequeue();
            if (curr.Length > ans.Length) {
                ans = curr;
            }
            // generate the next candidate string
            foreach (char ch in candidate) {
                string next = curr + ch;
                if (IsKRepeatedSubsequence(s, next, k)) {
                    q.Enqueue(next);
                }
            }
        }

        return ans;
    }

    private bool IsKRepeatedSubsequence(string s, string t, int k) {
        int pos = 0, matched = 0;
        int m = t.Length;
        foreach (char ch in s) {
            if (ch == t[pos]) {
                pos++;
                if (pos == m) {
                    pos = 0;
                    matched++;
                    if (matched == k) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func longestSubsequenceRepeatedK(s string, k int) string {
	freq := make([]int, 26)
	for _, ch := range s {
		freq[ch-'a']++
	}

	var candidate []byte
	for i := 25; i >= 0; i-- {
		if freq[i] >= k {
			candidate = append(candidate, byte('a'+i))
		}
	}
	q := []string{}
	for _, ch := range candidate {
		q = append(q, string(ch))
	}
	ans := ""
	for len(q) > 0 {
		curr := q[0]
		q = q[1:]
		if len(curr) > len(ans) {
			ans = curr
		}
		// generate the next candidate string
		for _, c := range candidate {
			next := curr + string(c)
			if isKRepeated(s, next, k) {
				q = append(q, next)
			}
		}
	}

	return ans
}

func isKRepeated(s, pattern string, k int) bool {
	i, matched := 0, 0
	for _, c := range s {
		if c == rune(pattern[i]) {
			i++
			if i == len(pattern) {
				i = 0
				matched++
				if matched == k {
					return true
				}
			}
		}
	}
	return false
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String longestSubsequenceRepeatedK(String s, int k) {
        int[] freq = new int[26];
        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }
        List<Character> candidate = new ArrayList<>();
        for (int i = 25; i >= 0; i--) {
            if (freq[i] >= k) {
                candidate.add((char) ('a' + i));
            }
        }

        Queue<String> q = new LinkedList<>();
        for (char ch : candidate) {
            q.add(String.valueOf(ch));
        }
        String ans = "";
        while (!q.isEmpty()) {
            String curr = q.poll();
            if (curr.length() > ans.length()) {
                ans = curr;
            }
            // generate the next candidate string
            for (char ch : candidate) {
                String next = curr + ch;
                if (isKRepeatedSubsequence(s, next, k)) {
                    q.add(next);
                }
            }
        }

        return ans;
    }

    private boolean isKRepeatedSubsequence(String s, String t, int k) {
        int pos = 0, matched = 0;
        int m = t.length();
        for (char ch : s.toCharArray()) {
            if (ch == t.charAt(pos)) {
                pos++;
                if (pos == m) {
                    pos = 0;
                    matched++;
                    if (matched == k) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestSubsequenceRepeatedK = function (s, k) {
    const freq = {};
    for (const c of s) {
        freq[c] = (freq[c] || 0) + 1;
    }
    const candidate = Object.keys(freq)
        .filter((c) => freq[c] >= k)
        .sort()
        .reverse();
    const q = [...candidate];
    let ans = "";
    while (q.length) {
        const curr = q.shift();
        if (curr.length > ans.length) {
            ans = curr;
        }
        // generate the next candidate string
        for (const c of candidate) {
            const next = curr + c;
            if (isKRepeated(s, next, k)) q.push(next);
        }
    }
    return ans;
};

function isKRepeated(s, pattern, k) {
    let i = 0,
        matched = 0;
    for (const c of s) {
        if (c === pattern[i]) {
            i++;
            if (i === pattern.length) {
                i = 0;
                matched++;
                if (matched === k) return true;
            }
        }
    }
    return false;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        ans = ""
        candidate = sorted(
            [c for c, w in Counter(s).items() if w >= k], reverse=True
        )
        q = deque(candidate)
        while q:
            curr = q.popleft()
            if len(curr) > len(ans):
                ans = curr
            # generate the next candidate string
            for ch in candidate:
                nxt = curr + ch
                it = iter(s)
                if all(ch in it for ch in nxt * k):
                    q.append(nxt)
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestSubsequenceRepeatedK(s: string, k: number): string {
    const freq: Record<string, number> = {};
    for (const c of s) freq[c] = (freq[c] || 0) + 1;

    const candidate = Object.keys(freq)
        .filter((c) => freq[c] >= k)
        .sort()
        .reverse();
    const q: string[] = [...candidate];
    let ans = "";
    while (q.length > 0) {
        const curr = q.shift()!;
        if (curr.length > ans.length) {
            ans = curr;
        }
        // generate the next candidate string
        for (const c of candidate) {
            const next = curr + c;
            if (isKRepeated(s, next, k)) q.push(next);
        }
    }

    return ans;
}

function isKRepeated(s: string, pattern: string, k: number): boolean {
    let i = 0,
        matched = 0;
    for (const c of s) {
        if (c === pattern[i]) {
            i++;
            if (i === pattern.length) {
                i = 0;
                matched++;
                if (matched === k) {
                    return true;
                }
            }
        }
    }

    return false;
}
```

</details>
