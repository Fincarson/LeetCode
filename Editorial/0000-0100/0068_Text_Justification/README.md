# 68. Text Justification

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/text-justification/)  
`Array` `String` `Simulation`

**Problem Link:** [LeetCode 68 - Text Justification](https://leetcode.com/problems/text-justification/)

## Problem

Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

- A word is defined as a character sequence consisting of non-space characters only.
- Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
- The input array words contains at least one word.

### Example 1

```text
Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
```

### Example 2

```text
Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
```

### Example 3

```text
Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
```

## Constraints

- 1 <= words.length <= 300
- 1 <= words[i].length <= 20
- words[i] consists of only English letters and symbols.
- 1 <= maxWidth <= 100
- words[i].length <= maxWidth

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rearrange Spaces Between Words](https://leetcode.com/problems/rearrange-spaces-between-words/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Divide a String Into Groups of Size k](https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Split Message Based on Limit](https://leetcode.com/problems/split-message-based-on-limit/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 68. Text Justification

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach:

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct answer {
    char** arr;
    int size;
};
struct answer getWords(int i, char** words, int wordsSize, int maxWidth) {
    struct answer currentLine;
    currentLine.arr = (char**)malloc(wordsSize * sizeof(char*));
    currentLine.size = 0;
    int currLength = 0;
    while (i < wordsSize && currLength + strlen(words[i]) <= maxWidth) {
        currentLine.arr[currentLine.size++] = words[i];
        currLength += strlen(words[i]) + 1;
        i++;
    }
    return currentLine;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
vector<string> getWords(int i, vector<string>& words, int maxWidth) {
    vector<string> currentLine;
    int currLength = 0;
    while (i < words.size() && currLength + words[i].size() <= maxWidth) {
        currentLine.push_back(words[i]);
        currLength += words[i].size() + 1;
        i++;
    }
    return currentLine;
}
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
private List<string> GetWords(int i, string[] words, int maxWidth) {
    var currentLine = new List<string>();
    int currLength = 0;
    while (i < words.Length && currLength + words[i].Length <= maxWidth) {
        currentLine.Add(words[i]);
        currLength += words[i].Length + 1;
        i++;
    }

    return currentLine;
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getWords(i int, words []string, maxWidth int) []string {
    currentLine := []string{}
    currLength := 0
    for i < len(words) && currLength+len(words[i]) <= maxWidth {
        currentLine = append(currentLine, words[i])
        currLength += len(words[i]) + 1
        i++
    }
    return currentLine
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
private List<String> getWords(int i, String[] words, int maxWidth) {
    List<String> currentLine = new ArrayList<>();
    int currLength = 0;

    while (i < words.length && currLength + words[i].length() <= maxWidth) {
        currentLine.add(words[i]);
        currLength += words[i].length() + 1;
        i++;
    }

    return currentLine;
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function getWords(i, words, maxWidth) {
    let currentLine = [];
    let currLength = 0;
    while (i < words.length && currLength + words[i].length <= maxWidth) {
        currentLine.push(words[i]);
        currLength += words[i].length + 1;
        i++;
    }
    return currentLine;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
def get_words(i):
    current_line = []
    curr_length = 0

    while i < len(words) and curr_length + len(words[i]) <= maxWidth:
        current_line.append(words[i])
        curr_length += len(words[i]) + 1
        i += 1

    return current_line
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getWords(i: number, words: string[], maxWidth: number) {
    let currentLine = [];
    let currLength = 0;
    while (i < words.length && currLength + words[i].length <= maxWidth) {
        currentLine.push(words[i]);
        currLength += words[i].length + 1;
        i++;
    }
    return currentLine;
}
```

</details>
