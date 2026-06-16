# 3170. Lexicographically Minimum String After Removing Stars

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/)  
`Hash Table` `String` `Stack` `Greedy` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 3170 - Lexicographically Minimum String After Removing Stars](https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/)

## Problem

You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

While there is a '*', do the following operation:

- Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.

Return the lexicographically smallest resulting string after removing all '*' characters.

### Example 1

### Example 2

## Constraints

- 1 <= s.length <= 105
- s consists only of lowercase English letters and '*'.
- The input is generated such that it is possible to delete all '*' characters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3170. Lexicographically Minimum String After Removing Stars

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int* data;
    int size;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->size = 0;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, int value) {
    if (stack->size < stack->capacity) {
        stack->data[stack->size++] = value;
    }
}

int pop(Stack* stack) {
    if (stack->size > 0) {
        return stack->data[--stack->size];
    }
    return -1;
}

int isEmpty(Stack* stack) { return stack->size == 0; }

void freeStack(Stack* stack) {
    free(stack->data);
    free(stack);
}

char* clearStars(char* s) {
    int n = strlen(s);
    Stack* cnt[26];
    for (int i = 0; i < 26; i++) {
        cnt[i] = createStack(n);
    }
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '*') {
            push(cnt[s[i] - 'a'], i);
        } else {
            for (int j = 0; j < 26; j++) {
                if (!isEmpty(cnt[j])) {
                    s[pop(cnt[j])] = '*';
                    break;
                }
            }
        }
    }

    char* ans = calloc(strlen(s) + 1, sizeof(char));
    for (int i = 0, j = 0; s[i] != '\0'; i++) {
        if (s[i] != '*') {
            ans[j++] = s[i];
        }
    }
    for (int i = 0; i < 26; i++) {
        freeStack(cnt[i]);
    }

    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> cnt(26);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                cnt[s[i] - 'a'].push(i);
            } else {
                for (int j = 0; j < 26; j++) {
                    if (!cnt[j].empty()) {
                        s[cnt[j].top()] = '*';
                        cnt[j].pop();
                        break;
                    }
                }
            }
        }

        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string ClearStars(string s) {
        Stack<int>[] cnt = new Stack<int>[26];
        for (int i = 0; i < 26; i++) {
            cnt[i] = new Stack<int>();
        }
        char[] arr = s.ToCharArray();
        for (int i = 0; i < arr.Length; i++) {
            if (arr[i] != '*') {
                cnt[arr[i] - 'a'].Push(i);
            } else {
                for (int j = 0; j < 26; j++) {
                    if (cnt[j].Count > 0) {
                        arr[cnt[j].Pop()] = '*';
                        break;
                    }
                }
            }
        }
        return new string(Array.FindAll(arr, c => c != '*'));
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func clearStars(s string) string {
	cnt := make([][]int, 26)
	for i := range cnt {
		cnt[i] = make([]int, 0)
	}
	arr := []rune(s)
	for i, c := range arr {
		if c != '*' {
			cnt[c-'a'] = append(cnt[c-'a'], i)
		} else {
			for j := 0; j < 26; j++ {
				if len(cnt[j]) > 0 {
					last := len(cnt[j]) - 1
					arr[cnt[j][last]] = '*'
					cnt[j] = cnt[j][:last]
					break
				}
			}
		}
	}
	var ans []rune
	for _, c := range arr {
		if c != '*' {
			ans = append(ans, c)
		}
	}
	return string(ans)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String clearStars(String s) {
        Deque<Integer>[] cnt = new Deque[26];
        for (int i = 0; i < 26; i++) {
            cnt[i] = new ArrayDeque<>();
        }
        char[] arr = s.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != '*') {
                cnt[arr[i] - 'a'].push(i);
            } else {
                for (int j = 0; j < 26; j++) {
                    if (!cnt[j].isEmpty()) {
                        arr[cnt[j].pop()] = '*';
                        break;
                    }
                }
            }
        }

        StringBuilder ans = new StringBuilder();
        for (char c : arr) {
            if (c != '*') {
                ans.append(c);
            }
        }
        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var clearStars = function (s) {
    const cnt = Array(26)
        .fill()
        .map(() => []);
    const arr = s.split("");
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] !== "*") {
            cnt[arr[i].charCodeAt(0) - "a".charCodeAt(0)].push(i);
        } else {
            for (let j = 0; j < 26; j++) {
                if (cnt[j].length > 0) {
                    arr[cnt[j].pop()] = "*";
                    break;
                }
            }
        }
    }
    return arr.filter((c) => c !== "*").join("");
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def clearStars(self, s: str) -> str:
        cnt = [[] for _ in range(26)]
        arr = list(s)
        for i, c in enumerate(arr):
            if c != "*":
                cnt[ord(c) - ord("a")].append(i)
            else:
                for j in range(26):
                    if cnt[j]:
                        arr[cnt[j].pop()] = "*"
                        break
        return "".join(c for c in arr if c != "*")
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function clearStars(s: string): string {
    const cnt: number[][] = Array(26)
        .fill([])
        .map(() => []);
    const arr = s.split("");
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] !== "*") {
            cnt[arr[i].charCodeAt(0) - "a".charCodeAt(0)].push(i);
        } else {
            for (let j = 0; j < 26; j++) {
                if (cnt[j].length > 0) {
                    arr[cnt[j].pop()!] = "*";
                    break;
                }
            }
        }
    }
    return arr.filter((c) => c !== "*").join("");
}
```

</details>
