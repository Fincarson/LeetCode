# 1181. Before and After Puzzle

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/before-and-after-puzzle/)  
`Array` `Hash Table` `String` `Sorting`

**Problem Link:** [LeetCode 1181 - Before and After Puzzle](https://leetcode.com/problems/before-and-after-puzzle/)

## Problem

Given a list of phrases, generate a list of Before and After puzzles.

A phrase is a string that consists of lowercase English letters and spaces only. No space appears in the start or the end of a phrase. There are no consecutive spaces in a phrase.

Before and After puzzles are phrases that are formed by merging two phrases where the last word of the first phrase is the same as the first word of the second phrase. Note that only the last word of the first phrase and the first word of the second phrase are merged in this process.

Return the Before and After puzzles that can be formed by every two phrases phrases[i] and phrases[j] where i != j. Note that the order of matching two phrases matters, we want to consider both orders.

You should return a list of distinct strings sorted lexicographically, after removing all duplicate phrases in the generated Before and After puzzles.

### Example 1

### Example 2

### Example 3

### Example 4

## Constraints

- 1 <= phrases.length <= 100
- 1 <= phrases[i].length <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1181. Before and After Puzzle

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Hash Table + Sorting | C, C++, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Hash Table + Sorting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MAX_PHRASE_LEN 256

typedef struct {
    char key[MAX_PHRASE_LEN];
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, const char *key) {
    HashItem *pEntry = NULL;
    HASH_FIND_STR(*obj, key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, const char *key) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    strcpy(pEntry->key, key);
    HASH_ADD_STR(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

typedef struct {
    char first[MAX_PHRASE_LEN];
    char last[MAX_PHRASE_LEN];
} FirstLast;

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

char **beforeAndAfterPuzzles(char **phrases, int phrasesSize, int *returnSize) {
    FirstLast sp[phrasesSize];
    for (int i = 0; i < phrasesSize; i++) {
        char phrase[MAX_PHRASE_LEN];
        strcpy(phrase, phrases[i]);
        char *first = strtok(phrase, " ");
        char *last = first;
        char *token = NULL;
        while ((token = strtok(NULL, " ")) != NULL) {
            last = token;
        }
        strcpy(sp[i].first, first);
        strcpy(sp[i].last, last);
    }

    int combinedSize = 0;
    HashItem *set = NULL;
    for (int i = 0; i < phrasesSize; i++) {
        for (int j = 0; j < phrasesSize; j++) {
            if (i == j) continue;
            if (strcmp(sp[i].first, sp[j].last) == 0) {
                char combined[MAX_PHRASE_LEN];
                strcpy(combined, phrases[j]);
                strcat(combined, phrases[i] + strlen(sp[i].first));
                hashAddItem(&set, combined);
            }
        }
    }

    *returnSize = HASH_COUNT(set);
    char **result = (char **)malloc(sizeof(char *) * HASH_COUNT(set));
    int pos = 0;
    for (HashItem *pEntry = set; pEntry; pEntry = pEntry->hh.next) {
        result[pos++] = strdup(pEntry->key);
    }
    qsort(result, *returnSize, sizeof(char *), compare);
    hashFree(&set);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        int n = phrases.size();
        vector<pair<string, string>> sp;
        for (const string& phrase : phrases) {
            size_t lastSpace = phrase.rfind(' ');
            string first = phrase.substr(0, phrase.find(' '));
            string last = (lastSpace == string::npos)
                              ? phrase
                              : phrase.substr(lastSpace + 1);
            sp.push_back({first, last});
        }

        set<string> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (sp[i].first == sp[j].second) {
                    string combined =
                        phrases[j] + phrases[i].substr(sp[i].first.length());
                    m.emplace(combined);
                }
            }
        }

        vector<string> ret;
        for (const auto& entry : m) {
            ret.push_back(entry);
        }
        return ret;
    }
};
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func beforeAndAfterPuzzles(phrases []string) []string {
	n := len(phrases)
	sp := [][]string{}
	for i := 0; i < n; i++ {
		s := strings.Split(phrases[i], " ")
		sp = append(sp, []string{s[0], s[len(s)-1]})
	}
	m := map[string]bool{}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}
			if sp[i][0] == sp[j][1] {
				m[phrases[j]+phrases[i][len(sp[i][0]):]] = true
			}
		}
	}
	ret := make([]string, 0)
	for k := range m {
		ret = append(ret, k)
	}
	sort.Strings(ret)
	return ret
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> beforeAndAfterPuzzles(String[] phrases) {
        int n = phrases.length;
        String[][] sp = new String[n][2];
        for (int i = 0; i < n; i++) {
            String[] words = phrases[i].split(" ");
            sp[i][0] = words[0];
            sp[i][1] = words[words.length - 1];
        }

        Set<String> m = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (sp[i][0].equals(sp[j][1])) {
                    String combined =
                        phrases[j] + phrases[i].substring(sp[i][0].length());
                    m.add(combined);
                }
            }
        }

        List<String> ret = new ArrayList<>(m);
        Collections.sort(ret);
        return ret;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var beforeAndAfterPuzzles = function (phrases) {
    const n = phrases.length;
    const sp = phrases.map((phrase) => {
        const words = phrase.split(" ");
        return { first: words[0], last: words[words.length - 1] };
    });

    const m = new Set();
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (i === j) continue;
            if (sp[i].first === sp[j].last) {
                const combined =
                    phrases[j] + phrases[i].slice(sp[i].first.length);
                m.add(combined);
            }
        }
    }

    const ret = Array.from(m).sort();
    return ret;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def beforeAndAfterPuzzles(self, phrases: List[str]) -> List[str]:
        n = len(phrases)
        sp = []
        for phrase in phrases:
            words = phrase.split(" ")
            sp.append((words[0], words[-1]))

        m = set()
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                if sp[i][0] == sp[j][1]:
                    combined = phrases[j] + phrases[i][len(sp[i][0]) :]
                    m.add(combined)

        ret = sorted(list(m))
        return ret
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function beforeAndAfterPuzzles(phrases: string[]): string[] {
    const n = phrases.length;
    const sp: { first: string; last: string }[] = phrases.map((phrase) => {
        const words = phrase.split(" ");
        return { first: words[0], last: words[words.length - 1] };
    });

    const m = new Set<string>();
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (i === j) continue;
            if (sp[i].first === sp[j].last) {
                const combined =
                    phrases[j] + phrases[i].slice(sp[i].first.length);
                m.add(combined);
            }
        }
    }

    const ret = Array.from(m).sort();
    return ret;
}
```

</details>
