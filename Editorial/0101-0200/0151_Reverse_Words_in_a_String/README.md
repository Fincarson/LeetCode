# 151. Reverse Words in a String

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/reverse-words-in-a-string/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 151 - Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/)

## Problem

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

### Example 1

```text
Input: s = "the sky is blue"
Output: "blue is sky the"
```

### Example 2

```text
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

### Example 3

```text
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```

## Constraints

- 1 <= s.length <= 104
- s contains English letters (upper-case and lower-case), digits, and spaces ' '.
- There is at least one word in s.

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse Words in a String II](https://leetcode.com/problems/reverse-words-in-a-string-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 151. Reverse Words in a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Built-in Split + Reverse | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Reverse the Whole String and Then Reverse Each Word | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Deque of Words | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Built-in Split + Reverse

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char* reverseWords(char* s) {
    char *token, *last, *reversed;
    char space[2] = " ";
    char* new_s = malloc(10000 * sizeof(char));

    if (!new_s) return NULL;

    new_s[0] = '\0';

    // split by spaces and reverse
    token = strtok(s, space);
    while (token != NULL) {
        if (strlen(new_s) > 0) {
            last = strdup(new_s);
            strcpy(new_s, token);
            strcat(new_s, " ");
            strcat(new_s, last);
            free(last);
        } else {
            strcpy(new_s, token);
            strcat(new_s, " ");
        }
        token = strtok(NULL, space);
    }

    // remove trailing space
    new_s[strlen(new_s) - 1] = '\0';

    // return the reversed words
    reversed = strdup(new_s);

    free(new_s);

    return reversed;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string reverseWords(string s) {
        // remove leading and trailing spaces
        s.erase(0, s.find_first_not_of(' '));  // prefixing spaces
        s.erase(s.find_last_not_of(' ') + 1);  // suffixing spaces

        // split by spaces
        istringstream iss(s);
        vector<string> words;
        copy(istream_iterator<string>(iss), istream_iterator<string>(),
             back_inserter(words));

        // reverse and join
        reverse(words.begin(), words.end());
        ostringstream oss;
        copy(words.begin(), words.end() - 1,
             ostream_iterator<string>(oss, " "));
        oss << words[words.size() - 1];
        return oss.str();
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string ReverseWords(string s) {
        // remove leading and trailing spaces
        s = s.Trim();
        // split by spaces and reverse
        string[] words = s.Split(new char[] { ' ' },
            StringSplitOptions.RemoveEmptyEntries);
        Array.Reverse(words);
        // join the words with a space
        return String.Join(" ", words);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func reverseWords(s string) string {
    // split by spaces
    words := strings.Fields(s)
    // reverse
    for i := 0; i < len(words)/2; i++ {
        words[i], words[len(words)-i-1] = words[len(words)-i-1], words[i]
    }
    // join the words with a space
    return strings.Join(words, " ")
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String reverseWords(String s) {
        // remove leading spaces
        s = s.trim();
        // split by multiple spaces
        List<String> wordList = Arrays.asList(s.split("\\s+"));
        Collections.reverse(wordList);
        return String.join(" ", wordList);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var reverseWords = function (s) {
    // remove leading and trailing spaces
    s = s.trim();
    // split by spaces and reverse
    let words = s.split(/\s+/).reverse();
    // join the words with a space
    return words.join(" ");
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(reversed(s.split()))
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function reverseWords(s: string): string {
    // remove leading and trailing spaces
    s = s.trim();
    // split by spaces and reverse
    let words = s.split(/\s+/).reverse();
    // join the words with a space
    return words.join(" ");
}
```

</details>

<br>

## Approach 2: Reverse the Whole String and Then Reverse Each Word

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Translated C solution
struct Node {
    char word[1000];
    struct Node* next;
};

void reverse(char* begin, char* end) {
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

void add(struct Node** head_ref, char* new_word) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->word, new_word);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

char* reverseWords(char* s) {
    int i = 0, j = 0;
    char temp[1000];
    struct Node* words = NULL;

    while (1) {
        if (s[i] == ' ' || s[i] == '\0') {
            if (j != 0) {
                temp[j] = '\0';
                add(&words, temp);
                j = 0;
            }

            if (s[i] == '\0') break;
        } else {
            temp[j] = s[i];
            j++;
        }
        i++;
    }

    char* ans = (char*)malloc(10000 * sizeof(char));
    struct Node* temp_node = words;
    int k = 0;

    while (temp_node != NULL) {
        for (int m = 0; m < strlen(temp_node->word); m++)
            ans[k++] = temp_node->word[m];
        if (temp_node->next != NULL)
            ans[k++] = ' ';
        else
            ans[k++] = '\0';

        temp_node = temp_node->next;
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
  string reverseWords(string s) {
    // reverse the whole string
    reverse(s.begin(), s.end());

    int n = s.size();
    int idx = 0;
    for (int start = 0; start < n; ++start) {
      if (s[start] != ' ') {
        // go to the beginning of the word
        if (idx != 0) s[idx++] = ' ';

        // go to the end of the word
        int end = start;
        while (end < n && s[end] != ' ') s[idx++] = s[end++];

        // reverse the word
        reverse(s.begin() + idx - (end - start), s.begin() + idx);

        // move to the next word
        start = end;
      }
    }
    s.erase(s.begin() + idx, s.end());
    return s;
  }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// Translated C# solution

public class Solution {
    public string ReverseWords(string s) {
        StringBuilder sb = TrimSpaces(s);
        // reverse the whole string
        Reverse(sb, 0, sb.Length - 1);
        // reverse each word
        ReverseEachWord(sb);
        return sb.ToString();
    }

    private StringBuilder TrimSpaces(string s) {
        int left = 0, right = s.Length - 1;
        // remove leading spaces
        while (left <= right && s[left] == ' ') ++left;
        // remove trailing spaces
        while (left <= right && s[right] == ' ') --right;
        // reduce multiple spaces to single one
        StringBuilder sb = new StringBuilder();
        while (left <= right) {
            if (s[left] != ' ') sb.Append(s[left]);
            else if (sb[sb.Length - 1] != ' ') sb.Append(s[left]);
            ++left;
        }

        return sb;
    }

    private void ReverseEachWord(StringBuilder sb) {
        int n = sb.Length;
        int start = 0, end = 0;
        while (start < n) {
            // go to the end of the word
            while (end < n && sb[end] != ' ') ++end;
            // reverse the word
            Reverse(sb, start, end - 1);
            // move to the next word
            start = end + 1;
            ++end;
        }
    }

    private void Reverse(StringBuilder sb, int left, int right) {
        while (left < right) {
            char tmp = sb[left];
            sb[left++] = sb[right];
            sb[right--] = tmp;
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Translated Go solution
func reverseWords(s string) string {
    // convert string to char slice
    // and trim spaces at the same time
    arr := trimSpaces(s)

    // reverse the whole string
    reverse(arr, 0, len(arr)-1)

    // reverse each word
    reverseEachWord(arr)

    return strings.Join(arr, "")
}

func trimSpaces(s string) []string {
    left, right := 0, len(s)-1
    // remove leading spaces
    for left <= right && s[left] == ' ' {
        left++
    }

    // remove trailing spaces
    for left <= right && s[right] == ' ' {
        right--
    }

    // reduce multiple spaces to single one
    output := make([]string, 0)
    for left <= right {
        if s[left] != ' ' {
            output = append(output, string(s[left]))
        } else if output[len(output)-1] != " " {
            output = append(output, string(s[left]))
        }
        left++
    }
    return output
}

func reverseEachWord(c []string) {
    n := len(c)
    start, end := 0, 0

    for start < n {
        // go to the end of the word
        for end < n && c[end] != " " {
            end++
        }
        // reverse the word
        reverse(c, start, end-1)
        // move to the next word
        start = end + 1
        end++
    }
}

func reverse(c []string, start int, end int) {
    for start < end {
        c[start], c[end] = c[end], c[start]
        start++
        end--
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public StringBuilder trimSpaces(String s) {
        int left = 0, right = s.length() - 1;
        // remove leading spaces
        while (left <= right && s.charAt(left) == ' ') ++left;

        // remove trailing spaces
        while (left <= right && s.charAt(right) == ' ') --right;

        // reduce multiple spaces to single one
        StringBuilder sb = new StringBuilder();
        while (left <= right) {
            char c = s.charAt(left);

            if (c != ' ') sb.append(c);
            else if (sb.charAt(sb.length() - 1) != ' ') sb.append(c);

            ++left;
        }
        return sb;
    }

    public void reverse(StringBuilder sb, int left, int right) {
        while (left < right) {
            char tmp = sb.charAt(left);
            sb.setCharAt(left++, sb.charAt(right));
            sb.setCharAt(right--, tmp);
        }
    }

    public void reverseEachWord(StringBuilder sb) {
        int n = sb.length();
        int start = 0, end = 0;

        while (start < n) {
            // go to the end of the word
            while (end < n && sb.charAt(end) != ' ') ++end;
            // reverse the word
            reverse(sb, start, end - 1);
            // move to the next word
            start = end + 1;
            ++end;
        }
    }

    public String reverseWords(String s) {
        // converst string to string builder
        // and trim spaces at the same time
        StringBuilder sb = trimSpaces(s);

        // reverse the whole string
        reverse(sb, 0, sb.length() - 1);

        // reverse each word
        reverseEachWord(sb);

        return sb.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// Translated JavaScript solution
var reverseWords = function (s) {
    // convert string to char array
    // and trim spaces at the same time
    let arr = trimSpaces(s);

    // reverse the whole string
    reverse(arr, 0, arr.length - 1);

    // reverse each word
    reverseEachWord(arr);

    return arr.join("");
};

var trimSpaces = function (s) {
    let left = 0,
        right = s.length - 1;
    // remove leading spaces
    while (left <= right && s[left] === " ") ++left;
    // remove trailing spaces
    while (left <= right && s[right] === " ") --right;
    // reduce multiple spaces to single one
    let output = [];
    while (left <= right) {
        if (s[left] !== " ") output.push(s[left]);
        else if (output[output.length - 1] !== " ") output.push(s[left]);
        ++left;
    }
    return output;
};

var reverseEachWord = function (arr) {
    let n = arr.length;
    let start = 0,
        end = 0;
    while (start < n) {
        // go to the end of the word
        while (end < n && arr[end] !== " ") ++end;
        // reverse the word
        reverse(arr, start, end - 1);
        // move to the next word
        start = end + 1;
        ++end;
    }
};

var reverse = function (arr, start, end) {
    while (start < end) {
        const tmp = arr[start];
        arr[start++] = arr[end];
        arr[end--] = tmp;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def trim_spaces(self, s: str) -> list:
        left, right = 0, len(s) - 1
        # remove leading spaces
        while left <= right and s[left] == " ":
            left += 1

        # remove trailing spaces
        while left <= right and s[right] == " ":
            right -= 1

        # reduce multiple spaces to single one
        output = []
        while left <= right:
            if s[left] != " ":
                output.append(s[left])
            elif output[-1] != " ":
                output.append(s[left])
            left += 1

        return output

    def reverse(self, l: list, left: int, right: int) -> None:
        while left < right:
            l[left], l[right] = l[right], l[left]
            left, right = left + 1, right - 1

    def reverse_each_word(self, l: list) -> None:
        n = len(l)
        start = end = 0

        while start < n:
            # go to the end of the word
            while end < n and l[end] != " ":
                end += 1
            # reverse the word
            self.reverse(l, start, end - 1)
            # move to the next word
            start = end + 1
            end += 1

    def reverseWords(self, s: str) -> str:
        # converst string to char array
        # and trim spaces at the same time
        l = self.trim_spaces(s)

        # reverse the whole string
        self.reverse(l, 0, len(l) - 1)

        # reverse each word
        self.reverse_each_word(l)

        return "".join(l)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// Translated TypeScript solution
function reverseWords(s: string): string {
    // convert string to char array
    // and trim spaces at the same time
    let arr: string[] = trimSpaces(s);

    // reverse the whole string
    reverse(arr, 0, arr.length - 1);

    // reverse each word
    reverseEachWord(arr);

    return arr.join("");
}

function trimSpaces(s: string): string[] {
    let left = 0,
        right = s.length - 1;
    // remove leading spaces
    while (left <= right && s[left] === " ") ++left;
    // remove trailing spaces
    while (left <= right && s[right] === " ") --right;
    // reduce multiple spaces to single one
    let output: string[] = [];
    while (left <= right) {
        if (s[left] !== " ") output.push(s[left]);
        else if (output[output.length - 1] !== " ") output.push(s[left]);
        ++left;
    }
    return output;
}

function reverseEachWord(arr: string[]): void {
    let n = arr.length;
    let start = 0,
        end = 0;
    while (start < n) {
        // go to the end of the word
        while (end < n && arr[end] !== " ") ++end;
        // reverse the word
        reverse(arr, start, end - 1);
        // move to the next word
        start = end + 1;
        ++end;
    }
}

function reverse(arr: string[], start: number, end: number) {
    while (start < end) {
        const tmp = arr[start];
        arr[start++] = arr[end];
        arr[end--] = tmp;
    }
}
```

</details>

<br>

## Approach 3: Deque of Words

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void reverse(char* s, int start, int end) {
    while (start < end) {
        char tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        start++;
        end--;
    }
}

void removeSpaces(char* s) {
    int i, j;
    for (i = 0, j = 0; s[i]; ++i)
        if (s[i] != ' ' || (i > 0 && s[i - 1] != ' ')) s[j++] = s[i];
    if (j > 0 && s[j - 1] == ' ') j--;
    s[j] = '\0';
}

char* reverseWords(char* s) {
    removeSpaces(s);

    int n = strlen(s);

    for (int i = 0; i < n / 2; i++) {
        char tmp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = tmp;
    }

    int start = 0;
    for (int end = 0; end < n; end++) {
        if (s[end] == ' ') {
            reverse(s, start, end - 1);
            start = end + 1;
        }
    }

    reverse(s, start, n - 1);
    return s;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ') ++left;
        while (left <= right && s[right] == ' ') --right;

        deque<string> d;
        string word;

        while (left <= right) {
            if (s[left] == ' ' && !word.empty()) {
                d.push_front(word);
                word.clear();
            } else if (s[left] != ' ') {
                word += s[left];
            }
            ++left;
        }
        d.push_front(word);

        string result = "";
        while (!d.empty()) {
            result += d.front();
            d.pop_front();
            if (!d.empty()) {
                result += " ";
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string ReverseWords(string s) {
        int left = 0, right = s.Length - 1;
        while (left <= right && s[left] == ' ') ++left;
        while (left <= right && s[right] == ' ') --right;

        LinkedList<string> d = new LinkedList<string>();
        StringBuilder word = new StringBuilder();

        while (left <= right) {
            if ((word.Length != 0) && (s[left] == ' ')) {
                d.AddFirst(word.ToString());
                word.Clear();
            } else if (s[left] != ' ') {
                word.Append(s[left]);
            }

            ++left;
        }

        d.AddFirst(word.ToString());

        return string.Join(" ", d);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func reverseWords(s string) string {
    s = strings.TrimSpace(
        s,
    ) // Trim is done in the beginning to simplify the code
    words := strings.Fields(s)
    left := 0
    right := len(words) - 1
    for left < right {
        words[left], words[right] = words[right], words[left]
        left++
        right--
    }
    return strings.Join(words, " ")
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String reverseWords(String s) {
        int left = 0, right = s.length() - 1;
        // remove leading spaces
        while (left <= right && s.charAt(left) == ' ') ++left;

        // remove trailing spaces
        while (left <= right && s.charAt(right) == ' ') --right;

        Deque<String> d = new ArrayDeque();
        StringBuilder word = new StringBuilder();
        // push word by word in front of deque
        while (left <= right) {
            char c = s.charAt(left);

            if ((word.length() != 0) && (c == ' ')) {
                d.offerFirst(word.toString());
                word.setLength(0);
            } else if (c != ' ') {
                word.append(c);
            }
            ++left;
        }
        d.offerFirst(word.toString());

        return String.join(" ", d);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var reverseWords = function (s) {
    let left = 0,
        right = s.length - 1;
    while (left <= right && s.charAt(left) == " ") left++;
    while (left <= right && s.charAt(right) == " ") right--;

    let d = [];
    let word = "";

    while (left <= right) {
        if (word.length != 0 && s.charAt(left) == " ") {
            d.push(word);
            word = "";
        } else if (s.charAt(left) != " ") {
            word += s.charAt(left);
        }
        left++;
    }
    d.push(word);
    return d.reverse().join(" ");
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import deque


class Solution:
    def reverseWords(self, s: str) -> str:
        left, right = 0, len(s) - 1
        # remove leading spaces
        while left <= right and s[left] == " ":
            left += 1

        # remove trailing spaces
        while left <= right and s[right] == " ":
            right -= 1

        d, word = deque(), []
        # push word by word in front of deque
        while left <= right:
            if s[left] == " " and word:
                d.appendleft("".join(word))
                word = []
            elif s[left] != " ":
                word.append(s[left])
            left += 1
        d.appendleft("".join(word))

        return " ".join(d)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function reverseWords(s: string): string {
    let left = 0,
        right = s.length - 1;
    while (left <= right && s.charAt(left) == " ") ++left;
    while (left <= right && s.charAt(right) == " ") --right;

    let d: string[] = [];
    let word: string = "";

    while (left <= right) {
        if (word.length != 0 && s.charAt(left) == " ") {
            d.push(word);
            word = "";
        } else if (s.charAt(left) != " ") {
            word += s.charAt(left);
        }
        ++left;
    }
    d.push(word);
    return d.reverse().join(" ");
}
```

</details>
