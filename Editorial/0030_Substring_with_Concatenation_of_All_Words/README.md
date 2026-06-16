# 30. Substring with Concatenation of All Words

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)  
`Hash Table` `String` `Sliding Window`

**Problem Link:** [LeetCode 30 - Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)

## Problem

You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

- For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.

Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= s.length <= 104
- 1 <= words.length <= 5000
- 1 <= words[i].length <= 30
- s and words[i] consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 30. Substring with Concatenation of All Words

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Check All Indices Using a Hash Table | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Sliding Window | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Check All Indices Using a Hash Table

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    char* key;          // key (string)
    int value;          // value (count)
    UT_hash_handle hh;  // makes this structure hashable
} HashTable;

// Function to add or update a word count in the hash table
void add_word_count(HashTable** table, char* word) {
    HashTable* s;
    HASH_FIND_STR(*table, word, s);
    if (s == NULL) {
        s = (HashTable*)malloc(sizeof(HashTable));
        s->key = strdup(word);
        s->value = 1;
        HASH_ADD_KEYPTR(hh, *table, s->key, strlen(s->key), s);
    } else {
        s->value++;
    }
}

// Function to deep copy a hash table
HashTable* hash_table_deep_copy(HashTable* original) {
    HashTable *new_table = NULL, *element, *tmp;
    HASH_ITER(hh, original, element, tmp) {
        HashTable* s = malloc(sizeof(HashTable));
        s->key = strdup(element->key);
        s->value = element->value;
        HASH_ADD_KEYPTR(hh, new_table, s->key, strlen(s->key), s);
    }
    return new_table;
}

// Function to decrement the count in the hash table
int decrement_hash_count(HashTable* table, char* word) {
    HashTable* element;
    HASH_FIND_STR(table, word, element);
    if (element && element->value > 0) {
        element->value--;
        return 1;  // Successfully decremented
    }
    return 0;  // Not found or zero count
}

// Function to free the hash table
void free_hash_table(HashTable* table) {
    HashTable *current, *tmp;
    HASH_ITER(hh, table, current, tmp) {
        HASH_DEL(table, current);
        free(current->key);
        free(current);
    }
}

// Check if substring starting at index i can form a valid concatenation
int check(int i, char* s, int wordLength, int substringSize,
          HashTable* wordCount, int k) {
    HashTable* remaining = hash_table_deep_copy(wordCount);
    int wordsUsed = 0;
    char* sub = (char*)malloc(wordLength + 1);

    for (int j = i; j < i + substringSize; j += wordLength) {
        strncpy(sub, s + j, wordLength);
        sub[wordLength] = '\0';
        if (decrement_hash_count(remaining, sub)) {
            wordsUsed++;
        } else {
            free(sub);
            free_hash_table(remaining);
            return 0;
        }
    }

    free(sub);
    free_hash_table(remaining);
    return wordsUsed == k;
}

// Main function to find substrings
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int n = strlen(s);
    int wordLength = strlen(words[0]);
    int substringSize = wordLength * wordsSize;
    int* results = malloc(sizeof(int) * (n - substringSize + 1));
    *returnSize = 0;

    HashTable* wordCount = NULL;
    for (int i = 0; i < wordsSize; i++) {
        add_word_count(&wordCount, words[i]);
    }

    for (int i = 0; i <= n - substringSize; i++) {
        if (check(i, s, wordLength, substringSize, wordCount, wordsSize)) {
            results[(*returnSize)++] = i;
        }
    }

    free_hash_table(wordCount);
    return results;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    unordered_map<string, int> wordCount;
    int wordLength;
    int substringSize;
    int k;
    bool check(int i, string s) {
        // Copy the original dictionary to use for this index
        unordered_map<string, int> remaining = wordCount;
        int wordsUsed = 0;
        // Each iteration will check for a match in words
        for (int j = i; j < i + substringSize; j += wordLength) {
            string sub = s.substr(j, wordLength);
            if (remaining[sub] != 0) {
                remaining[sub]--;
                wordsUsed++;
            } else {
                break;
            }
        }
        return wordsUsed == k;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        k = words.size();
        wordLength = words[0].size();
        substringSize = wordLength * k;
        for (string word : words) {
            if (wordCount.find(word) == wordCount.end()) {
                wordCount[word] = 1;
            } else {
                wordCount[word] += 1;
            }
        }
        vector<int> answer;
        for (int i = 0; i < n - substringSize + 1; i++) {
            if (check(i, s)) {
                answer.push_back(i);
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private Dictionary<string, int> wordCount = new Dictionary<string, int>();
    private int wordLength;
    private int substringSize;
    private int k;

    private bool Check(int i, string s) {
        // Copy the original dictionary to use for this index
        var remaining = new Dictionary<string, int>(wordCount);
        int wordsUsed = 0;
        // Each iteration will check for a match in words
        for (int j = i; j < i + substringSize; j += wordLength) {
            string sub = s.Substring(j, wordLength);
            if (remaining.ContainsKey(sub) && remaining[sub] != 0) {
                remaining[sub] = remaining[sub] - 1;
                wordsUsed++;
            } else {
                break;
            }
        }

        return wordsUsed == k;
    }

    public IList<int> FindSubstring(string s, string[] words) {
        int n = s.Length;
        k = words.Length;
        wordLength = words[0].Length;
        substringSize = wordLength * k;
        foreach (var word in words)
            wordCount[word] =
                wordCount.ContainsKey(word) ? wordCount[word] + 1 : 1;
        IList<int> answer = new List<int>();
        for (int i = 0; i < n - substringSize + 1; i++) {
            if (Check(i, s)) {
                answer.Add(i);
            }
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findSubstring(s string, words []string) []int {
    n := len(s)
    k := len(words)
    wordLength := len(words[0])
    substringSize := wordLength * k
    wordCount := make(map[string]int)
    for _, word := range words {
        wordCount[word]++
    }
    check := func(i int) bool {
        remaining := make(map[string]int)
        wordsUsed := 0
        for k := range wordCount {
            remaining[k] = wordCount[k]
        }
        for j := i; j < i+substringSize; j += wordLength {
            sub := s[j : j+wordLength]
            if remaining[sub] > 0 {
                remaining[sub]--
                wordsUsed++
            } else {
                break
            }
        }
        return wordsUsed == k
    }
    var answer []int
    for i := 0; i < n-substringSize+1; i++ {
        if check(i) {
            answer = append(answer, i)
        }
    }
    return answer
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private HashMap<String, Integer> wordCount = new HashMap<String, Integer>();
    private int wordLength;
    private int substringSize;
    private int k;

    private boolean check(int i, String s) {
        // Copy the original dictionary to use for this index
        HashMap<String, Integer> remaining = new HashMap<>(wordCount);
        int wordsUsed = 0;

        // Each iteration will check for a match in words
        for (int j = i; j < i + substringSize; j += wordLength) {
            String sub = s.substring(j, j + wordLength);
            if (remaining.getOrDefault(sub, 0) != 0) {
                remaining.put(sub, remaining.get(sub) - 1);
                wordsUsed++;
            } else {
                break;
            }
        }

        return wordsUsed == k;
    }

    public List<Integer> findSubstring(String s, String[] words) {
        int n = s.length();
        k = words.length;
        wordLength = words[0].length();
        substringSize = wordLength * k;

        for (String word : words) {
            wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
        }

        List<Integer> answer = new ArrayList<>();
        for (int i = 0; i < n - substringSize + 1; i++) {
            if (check(i, s)) {
                answer.add(i);
            }
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findSubstring = function (s, words) {
    const n = s.length;
    const k = words.length;
    const wordLength = words[0].length;
    const substringSize = wordLength * k;
    const wordCount = {};
    words.forEach((word) => {
        wordCount[word] = (wordCount[word] || 0) + 1;
    });
    const check = (i) => {
        const remaining = Object.assign({}, wordCount);
        let wordsUsed = 0;
        for (let j = i; j < i + substringSize; j += wordLength) {
            const sub = s.slice(j, j + wordLength);
            if (remaining[sub]) {
                remaining[sub]--;
                wordsUsed++;
            } else {
                break;
            }
        }
        return wordsUsed === k;
    };
    const answer = [];
    for (let i = 0; i < n - substringSize + 1; i++) {
        if (check(i)) {
            answer.push(i);
        }
    }
    return answer;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n = len(s)
        k = len(words)
        word_length = len(words[0])
        substring_size = word_length * k
        word_count = collections.Counter(words)

        def check(i):
            # Copy the original dictionary to use for this index
            remaining = word_count.copy()
            words_used = 0

            # Each iteration will check for a match in words
            for j in range(i, i + substring_size, word_length):
                sub = s[j : j + word_length]
                if remaining[sub] > 0:
                    remaining[sub] -= 1
                    words_used += 1
                else:
                    break

            # Valid if we used all the words
            return words_used == k

        answer = []
        for i in range(n - substring_size + 1):
            if check(i):
                answer.append(i)

        return answer
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findSubstring(s: string, words: string[]): number[] {
    const n = s.length;
    const k = words.length;
    const wordLength = words[0].length;
    const substringSize = wordLength * k;
    const wordCount: Record<string, number> = {};
    words.forEach((word) => {
        wordCount[word] = (wordCount[word] || 0) + 1;
    });
    const check = (i: number): boolean => {
        const remaining: Record<string, number> = { ...wordCount };
        let wordsUsed = 0;
        for (let j = i; j < i + substringSize; j += wordLength) {
            const sub = s.slice(j, j + wordLength);
            if (remaining[sub]) {
                remaining[sub]--;
                wordsUsed++;
            } else {
                break;
            }
        }
        return wordsUsed === k;
    };
    const answer: number[] = [];
    for (let i = 0; i < n - substringSize + 1; i++) {
        if (check(i)) {
            answer.push(i);
        }
    }
    return answer;
}
```

</details>

<br>

## Approach 2: Sliding Window

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct hash {
    char key[1024];
    int val;
    UT_hash_handle hh;
};
void change_hash(struct hash **myhash, char *key, int change) {
    struct hash *s;
    HASH_FIND_STR(*myhash, key, s); /* id already in the hash? */
    s->val += change;
}
void add_hash(struct hash **myhash, char *key, int val) {
    struct hash *s;
    HASH_FIND_STR(*myhash, key, s); /* id already in the hash? */
    if (s == NULL) {
        s = (struct hash *)malloc(sizeof(struct hash));
        strncpy(s->key, key, strlen(key) + 1); /* copy id to new struct */
        HASH_ADD_STR(*myhash, key, s);         /* id: name of key field */
    }
    s->val = val; /* store it */
}
bool exists_in_hash(struct hash *myhash, char *key) {
    struct hash *s;
    HASH_FIND_STR(myhash, key, s); /* id already in the hash? */
    if (s) {
        return true;
    }
    return false;
}
int find_in_hash(struct hash *myhash, char *key) {
    struct hash *s;
    HASH_FIND_STR(myhash, key, s); /* id already in the hash? */
    if (s) {
        return s->val;
    }
    return 0;
}
void reset_hash(struct hash **myhash) {
    struct hash *s, *tmp;
    HASH_ITER(hh, *myhash, s, tmp) {
        HASH_DEL(*myhash, s);
        free(s);
    }
    *myhash = NULL;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findSubstring(char *s, char **words, int wordsSize, int *returnSize) {
    int n = strlen(s);
    int k = wordsSize;
    int word_length = strlen(words[0]);
    int substring_size = word_length * k;
    struct hash *word_count = NULL;
    for (int i = 0; i < wordsSize; ++i) {
        add_hash(&word_count, words[i], find_in_hash(word_count, words[i]) + 1);
    }
    int *answer = (int *)malloc(sizeof(int) * 0);
    int answerSize = 0;
    for (int i = 0; i < word_length; i++) {
        struct hash *words_found = NULL;
        int words_used = 0;
        bool excess_word = false;
        char *sub = (char *)malloc(word_length + 1);
        sub[word_length] = '\0';
        int left = i;
        for (int right = i; right < n; right += word_length) {
            if (right + word_length > n) break;
            strncpy(sub, &s[right], word_length);
            if (!exists_in_hash(word_count, sub)) {
                reset_hash(&words_found);
                words_used = 0;
                excess_word = false;
                left = right + word_length;
            } else {
                char *leftmost_word = (char *)malloc(word_length + 1);
                leftmost_word[word_length] = '\0';
                while (right - left == substring_size || excess_word) {
                    strncpy(leftmost_word, &s[left], word_length);
                    left += word_length;
                    change_hash(&words_found, leftmost_word, -1);
                    if (find_in_hash(words_found, leftmost_word) ==
                        find_in_hash(word_count, leftmost_word)) {
                        excess_word = false;
                    } else {
                        words_used -= 1;
                    }
                }
                add_hash(&words_found, sub, find_in_hash(words_found, sub) + 1);
                if (find_in_hash(words_found, sub) <=
                    find_in_hash(word_count, sub)) {
                    words_used += 1;
                } else {
                    excess_word = true;
                }
                if (words_used == k && !excess_word) {
                    answer =
                        (int *)realloc(answer, sizeof(int) * (++answerSize));
                    answer[answerSize - 1] = left;
                }
            }
        }
    }
    *returnSize = answerSize;
    return answer;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    unordered_map<string, int> wordCount;
    int n;
    int wordLength;
    int substringSize;
    int k;
    void slidingWindow(int left, string &s, vector<int> &answer) {
        unordered_map<string, int> wordsFound;
        int wordsUsed = 0;
        bool excessWord = false;
        for (int right = left; right <= n - wordLength; right += wordLength) {
            string sub = s.substr(right, wordLength);
            if (!wordCount.count(sub)) {
                // Mismatched word - reset the window
                wordsFound.clear();
                wordsUsed = 0;
                excessWord = false;
                left = right + wordLength;
            } else {
                // If we reached max window size or have an excess word
                while (right - left == substringSize || excessWord) {
                    string leftmostWord = s.substr(left, wordLength);
                    left += wordLength;
                    wordsFound[leftmostWord]--;
                    if (wordsFound[leftmostWord] >= wordCount[leftmostWord]) {
                        // This word was an excess word
                        excessWord = false;
                    } else {
                        // Otherwise we actually needed it
                        wordsUsed--;
                    }
                }
                // Keep track of how many times this word occurs in the window
                wordsFound[sub]++;
                if (wordsFound[sub] <= wordCount[sub]) {
                    wordsUsed++;
                } else {
                    // Found too many instances already
                    excessWord = true;
                }
                if (wordsUsed == k && !excessWord) {
                    // Found a valid substring
                    answer.push_back(left);
                }
            }
        }
    }

public:
    vector<int> findSubstring(string s, vector<string> &words) {
        n = s.length();
        k = words.size();
        wordLength = words[0].length();
        substringSize = wordLength * k;
        for (string &word : words) {
            wordCount[word]++;
        }
        vector<int> answer;
        for (int i = 0; i < wordLength; i++) {
            slidingWindow(i, s, answer);
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    Dictionary<string, int> wordCount = new Dictionary<string, int>();
    int n;
    int wordLength;
    int substringSize;
    int k;

    void slidingWindow(int left, string s, List<int> answer) {
        Dictionary<string, int> wordsFound = new Dictionary<string, int>();
        int wordsUsed = 0;
        bool excessWord = false;
        for (int right = left; right <= n - wordLength; right += wordLength) {
            string sub = s.Substring(right, wordLength);
            if (!wordCount.ContainsKey(sub)) {
                // Mismatched word - reset the window
                wordsFound.Clear();
                wordsUsed = 0;
                excessWord = false;
                left = right + wordLength;
            } else {
                // If we reached max window size or have an excess word
                while (right - left == substringSize || excessWord) {
                    string leftmostWord = s.Substring(left, wordLength);
                    left += wordLength;
                    wordsFound[leftmostWord]--;
                    if (wordsFound[leftmostWord] >= wordCount[leftmostWord]) {
                        // This word was an excess word
                        excessWord = false;
                    } else {
                        // Otherwise we actually needed it
                        wordsUsed--;
                    }
                }

                // Keep track of how many times this word occurs in the window
                if (!wordsFound.ContainsKey(sub)) {
                    wordsFound[sub] = 0;
                }

                wordsFound[sub]++;
                if (wordsFound[sub] <= wordCount[sub]) {
                    wordsUsed++;
                } else {
                    // Found too many instances already
                    excessWord = true;
                }

                if (wordsUsed == k && !excessWord) {
                    // Found a valid substring
                    answer.Add(left);
                }
            }
        }
    }

    public IList<int> FindSubstring(string s, string[] words) {
        n = s.Length;
        k = words.Length;
        wordLength = words[0].Length;
        substringSize = wordLength * k;
        foreach (string word in words) {
            if (!wordCount.ContainsKey(word))
                wordCount[word] = 0;
            wordCount[word]++;
        }

        List<int> answer = new List<int>();
        for (int i = 0; i < wordLength; i++) {
            slidingWindow(i, s, answer);
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// To be precise, Go’s map is like a mix of dictionary and hash table in Python, even though Go's documentation called it a "Hash Table".
// Mutating a map or reading from it is not thread-safe.
// Like the usage in C, Go and C support threads to operate the map themselves, while using the concurrent map thread-safely.
func slidingWindow(left int, s string, wordCount map[string]int,
    k int, wordLength int, substringSize int, n int, result []int,
) []int {
    wordsFound := make(map[string]int)
    wordsUsed := 0
    excessWord := false
    for right := left; right <= n-wordLength; right += wordLength {
        sub := s[right : right+wordLength]
        _, ok := wordCount[sub]
        if !ok {
            wordsFound = make(map[string]int)
            wordsUsed = 0
            excessWord = false
            left = right + wordLength
        } else {
            for right-left == substringSize || excessWord {
                leftmostWord := s[left : left+wordLength]
                left += wordLength
                wordsFound[leftmostWord]--
                // map[key] - retrieve value; if key does not exist, you get zero value for the type of the items e.g., 0 for int, "" for string, nil for any type of pointers, functions, interfaces, slices, channels.
                if wordsFound[leftmostWord] >= wordCount[leftmostWord] {
                    excessWord = false
                } else {
                    wordsUsed--
                }
            }
            wordsFound[sub]++
            if wordsFound[sub] <= wordCount[sub] {
                wordsUsed++
            } else {
                excessWord = true
            }
            if wordsUsed == k && !excessWord {
                result = append(result, left)
            }
        }
    }
    return result
}

func findSubstring(s string, words []string) []int {
    wordCount := make(map[string]int)
    for _, word := range words {
        wordCount[word]++
    }
    wordLength := len(words[0])
    k := len(words)
    n := len(s)
    substringSize := wordLength * k
    result := make([]int, 0)
    for i := 0; i < wordLength; i++ {
        result = slidingWindow(
            i,
            s,
            wordCount,
            k,
            wordLength,
            substringSize,
            n,
            result,
        )
    }
    return result
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private HashMap<String, Integer> wordCount = new HashMap<String, Integer>();
    private int n;
    private int wordLength;
    private int substringSize;
    private int k;

    private void slidingWindow(int left, String s, List<Integer> answer) {
        HashMap<String, Integer> wordsFound = new HashMap<>();
        int wordsUsed = 0;
        boolean excessWord = false;

        // Do the same iteration pattern as the previous approach - iterate
        // word_length at a time, and at each iteration we focus on one word
        for (int right = left; right <= n - wordLength; right += wordLength) {
            String sub = s.substring(right, right + wordLength);
            if (!wordCount.containsKey(sub)) {
                // Mismatched word - reset the window
                wordsFound.clear();
                wordsUsed = 0;
                excessWord = false;
                left = right + wordLength;
            } else {
                // If we reached max window size or have an excess word
                while (right - left == substringSize || excessWord) {
                    String leftmostWord = s.substring(left, left + wordLength);
                    left += wordLength;
                    wordsFound.put(
                        leftmostWord,
                        wordsFound.get(leftmostWord) - 1
                    );

                    if (
                        wordsFound.get(leftmostWord) >=
                        wordCount.get(leftmostWord)
                    ) {
                        // This word was an excess word
                        excessWord = false;
                    } else {
                        // Otherwise we actually needed it
                        wordsUsed--;
                    }
                }

                // Keep track of how many times this word occurs in the window
                wordsFound.put(sub, wordsFound.getOrDefault(sub, 0) + 1);
                if (wordsFound.get(sub) <= wordCount.get(sub)) {
                    wordsUsed++;
                } else {
                    // Found too many instances already
                    excessWord = true;
                }

                if (wordsUsed == k && !excessWord) {
                    // Found a valid substring
                    answer.add(left);
                }
            }
        }
    }

    public List<Integer> findSubstring(String s, String[] words) {
        n = s.length();
        k = words.length;
        wordLength = words[0].length();
        substringSize = wordLength * k;

        for (String word : words) {
            wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
        }

        List<Integer> answer = new ArrayList<>();
        for (int i = 0; i < wordLength; i++) {
            slidingWindow(i, s, answer);
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findSubstring = function (s, words) {
    if (words.length === 0) return [];
    const wordCount = new Map();
    const wordLength = words[0].length;
    const substringSize = words.length * wordLength;
    const n = s.length;
    const result = [];
    for (let word of words) {
        wordCount.set(word, (wordCount.get(word) || 0) + 1);
    }
    const slidingWindow = function (left) {
        const wordsFound = new Map();
        let wordsUsed = 0;
        let excessWord = false;
        for (let right = left; right <= n - wordLength; right += wordLength) {
            const sub = s.substring(right, right + wordLength);
            if (!wordCount.has(sub)) {
                wordsFound.clear();
                wordsUsed = 0;
                excessWord = false;
                left = right + wordLength;
            } else {
                while (right - left === substringSize || excessWord) {
                    const leftmostWord = s.substring(left, left + wordLength);
                    left += wordLength;
                    wordsFound.set(
                        leftmostWord,
                        wordsFound.get(leftmostWord) - 1,
                    );
                    if (
                        wordsFound.get(leftmostWord) >=
                        wordCount.get(leftmostWord)
                    ) {
                        excessWord = false;
                    } else {
                        wordsUsed--;
                    }
                }
                wordsFound.set(sub, (wordsFound.get(sub) || 0) + 1);
                if (wordsFound.get(sub) <= wordCount.get(sub)) {
                    wordsUsed++;
                } else {
                    excessWord = true;
                }
                if (wordsUsed === words.length && !excessWord) {
                    result.push(left);
                }
            }
        }
    };
    for (let i = 0; i < wordLength; i++) {
        slidingWindow(i);
    }
    return result;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n = len(s)
        k = len(words)
        word_length = len(words[0])
        substring_size = word_length * k
        word_count = collections.Counter(words)

        def sliding_window(left):
            words_found = collections.defaultdict(int)
            words_used = 0
            excess_word = False

            # Do the same iteration pattern as the previous approach - iterate
            # word_length at a time, and at each iteration we focus on one word
            for right in range(left, n, word_length):
                if right + word_length > n:
                    break

                sub = s[right : right + word_length]
                if sub not in word_count:
                    # Mismatched word - reset the window
                    words_found = collections.defaultdict(int)
                    words_used = 0
                    excess_word = False
                    left = right + word_length  # Retry at the next index
                else:
                    # If we reached max window size or have an excess word
                    while right - left == substring_size or excess_word:
                        # Move the left bound over continously
                        leftmost_word = s[left : left + word_length]
                        left += word_length
                        words_found[leftmost_word] -= 1

                        if (
                            words_found[leftmost_word]
                            == word_count[leftmost_word]
                        ):
                            # This word was the excess word
                            excess_word = False
                        else:
                            # Otherwise we actually needed it
                            words_used -= 1

                    # Keep track of how many times this word occurs in the window
                    words_found[sub] += 1
                    if words_found[sub] <= word_count[sub]:
                        words_used += 1
                    else:
                        # Found too many instances already
                        excess_word = True

                    if words_used == k and not excess_word:
                        # Found a valid substring
                        answer.append(left)

        answer = []
        for i in range(word_length):
            sliding_window(i)

        return answer
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findSubstring(s: string, words: string[]): number[] {
    let wordCount = new Map<string, number>(),
        wordLength = words[0].length,
        substringSize = words.length * wordLength,
        n = s.length,
        result: number[] = [];
    words.forEach((word) => {
        wordCount.set(word, (wordCount.get(word) || 0) + 1);
    });
    const slidingWindow = (left: number) => {
        let wordsFound = new Map<string, number>(),
            wordsUsed = 0,
            excessWord = false;
        for (let right = left; right <= n - wordLength; right += wordLength) {
            let sub = s.substring(right, right + wordLength);
            if (!wordCount.has(sub)) {
                wordsFound.clear();
                wordsUsed = 0;
                excessWord = false;
                left = right + wordLength;
            } else {
                while (right - left === substringSize || excessWord) {
                    let leftmostWord = s.substring(left, left + wordLength);
                    left += wordLength;
                    wordsFound.set(
                        leftmostWord,
                        wordsFound.get(leftmostWord) - 1,
                    );
                    if (
                        wordsFound.get(leftmostWord) >=
                        wordCount.get(leftmostWord)
                    ) {
                        excessWord = false;
                    } else {
                        wordsUsed--;
                    }
                }
                wordsFound.set(sub, (wordsFound.get(sub) || 0) + 1);
                if (wordsFound.get(sub) <= wordCount.get(sub)) {
                    wordsUsed++;
                } else {
                    excessWord = true;
                }
                if (wordsUsed === words.length && !excessWord) {
                    result.push(left);
                }
            }
        }
    };
    for (let i = 0; i < wordLength; i++) {
        slidingWindow(i);
    }
    return result;
}
```

</details>
