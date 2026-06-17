# 49. Group Anagrams

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/group-anagrams/)  
`Array` `Hash Table` `String` `Sorting`

**Problem Link:** [LeetCode 49 - Group Anagrams](https://leetcode.com/problems/group-anagrams/)

## Problem

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= strs.length <= 104
- 0 <= strs[i].length <= 100
- strs[i] consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Valid Anagram](https://leetcode.com/problems/valid-anagram/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Resultant Array After Removing Anagrams](https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count Anagrams](https://leetcode.com/problems/count-anagrams/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 49. Group Anagrams

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Categorize by Sorted String | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Categorize by Count | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Categorize by Sorted String

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Struct to hold key-value pairs
typedef struct {
    char* key;          // key (sorted string)
    char** values;      // list of original strings
    int size;           // number of elements
    int capacity;       // allocated capacity
    UT_hash_handle hh;  // makes this structure hashable
} AnagramGroup;

// Function to compare strings for qsort
int charcmp(const void* a, const void* b) {
    char ca = *(const char*)a;
    char cb = *(const char*)b;
    return (ca > cb) - (ca < cb);
}

// Function to add anagrams to the hash table
void add_anagram(AnagramGroup** groups, const char* key, const char* value) {
    AnagramGroup* s;

    HASH_FIND_STR(*groups, key, s);  // try to find group in hash table
    if (s == NULL) {
        s = malloc(sizeof(AnagramGroup));
        s->key = strdup(key);
        s->capacity = 10;
        s->size = 0;
        s->values = malloc(sizeof(char*) * s->capacity);
        HASH_ADD_KEYPTR(hh, *groups, s->key, strlen(s->key), s);
    }

    if (s->size >= s->capacity) {  // resize array if necessary
        s->capacity *= 2;
        s->values = realloc(s->values, sizeof(char*) * s->capacity);
    }
    s->values[s->size++] = strdup(value);  // add new value
}

// Main function to group anagrams
char*** groupAnagrams(char** strs, int strsSize, int* returnSize,
                      int** returnColumnSizes) {
    AnagramGroup *groups = NULL, *s, *tmp;
    char*** result;

    for (int i = 0; i < strsSize; i++) {
        char* key = strdup(strs[i]);
        qsort(key, strlen(key), sizeof(char), charcmp);  // sort the key
        add_anagram(&groups, key, strs[i]);              // add to hash table
        free(key);  // freeing the sorted key after use
    }

    *returnSize = HASH_COUNT(groups);
    result = malloc(sizeof(char**) * (*returnSize));
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));

    int i = 0;
    HASH_ITER(hh, groups, s, tmp) {
        result[i] = malloc(sizeof(char*) *
                           s->size);  // allocate memory for pointers to strings
        for (int j = 0; j < s->size; j++) {
            result[i][j] =
                s->values[j];  // copy the pointers to the result array
        }
        (*returnColumnSizes)[i] = s->size;
        i++;
    }

    // Freeing groups after copying the data
    HASH_ITER(hh, groups, s, tmp) {
        HASH_DEL(groups, s);  // delete the hash table entry
        free(s->key);         // free the key
        free(s->values);      // free the list of strings
        free(s);              // free the structure
    }

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create a map to store the anagrams, where the keys are the sorted
        // strings and the values are the lists of anagrams
        unordered_map<string, vector<string>> ans;
        for (auto& s : strs) {
            string key = s;
            // Sort the key
            sort(key.begin(), key.end());
            // If the string is an anagram of another string, they will have the
            // same key and thus be grouped together
            ans[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& p : ans) {
            result.push_back(p.second);
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
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        var dict = new Dictionary<string, List<string>>();
        foreach (var s in strs) {
            var ca = s.ToCharArray();
            Array.Sort(ca);
            var key = new String(ca);
            if (!dict.ContainsKey(key))
                dict[key] = new List<string>();
            dict[key].Add(s);
        }

        return new List<IList<string>>(dict.Values);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func groupAnagrams(strs []string) [][]string {
    // Create a map to store the anagrams, where the keys are the sorted strings and the values are the lists of anagrams
    ans := make(map[string][]string)
    for _, s := range strs {
        key := sortString(s)
        // If the string is an anagram of another string, they will have the same key and thus be grouped together
        ans[key] = append(ans[key], s)
    }

    // Build the result slice from the map entries
    var result [][]string
    for _, group := range ans {
        result = append(result, group)
    }
    return result
}

// sortString sorts the characters of a string and returns the sorted string
func sortString(s string) string {
    sorted := strings.Split(s, "")
    sort.Strings(sorted)
    return strings.Join(sorted, "")
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs.length == 0) return new ArrayList();
        Map<String, List> ans = new HashMap<String, List>();
        for (String s : strs) {
            char[] ca = s.toCharArray();
            Arrays.sort(ca);
            String key = String.valueOf(ca);
            if (!ans.containsKey(key)) ans.put(key, new ArrayList());
            ans.get(key).add(s);
        }
        return new ArrayList(ans.values());
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var groupAnagrams = function (strs) {
    // Create a map to store the anagrams, where the keys are the sorted strings and the values are the lists of anagrams
    let map = new Map();
    // Iterate over the given strings
    for (let str of strs) {
        // Convert the string to a char array and sort it
        let chars = Array.from(str);
        chars.sort();
        // Use the sorted string as a key
        // If the string is an anagram of another string, they will have the same key and thus be grouped together
        let key = chars.join("");
        // If the key is not already in the map, add it with a new list as its value
        if (!map.has(key)) map.set(key, []);
        // Add the original string to the list of its key
        map.get(key).push(str);
    }
    // Return the lists of anagrams
    return Array.from(map.values());
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = collections.defaultdict(list)
        for s in strs:
            ans[tuple(sorted(s))].append(s)
        return list(ans.values())
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function groupAnagrams(strs: string[]): string[][] {
    // Create a map to store the anagrams, where the keys are the sorted strings and the values are the lists of anagrams
    let map = new Map<string, string[]>();
    // Iterate over the given strings
    for (let str of strs) {
        // Convert the string to a char array and sort it
        let chars = Array.from(str);
        chars.sort();
        // Use the sorted string as a key
        // If the string is an anagram of another string, they will have the same key and thus be grouped together
        let key = chars.join("");
        // If the key is not already in the map, add it with a new list as its value
        if (!map.has(key)) map.set(key, []);
        // Add the original string to the list of its key
        map.get(key).push(str);
    }
    // Return the lists of anagrams
    return Array.from(map.values());
}
```

</details>

<br>

## Approach 2: Categorize by Count

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Node for the list of strings (anagrams)
typedef struct string_node {
    char *str;
    struct string_node *next;
} string_node;

// Hash table structure
typedef struct hash_table {
    char key[104];      // Key for anagram groups
    string_node *head;  // Head of linked list of anagrams
    int list_size;      // Number of anagrams in the list
    UT_hash_handle hh;  // Makes this structure hashable
} hash_table;

// Function to create new node for list of strings
string_node *new_string_node(char *s) {
    string_node *node = (string_node *)malloc(sizeof(string_node));
    node->str = strdup(s);
    node->next = NULL;
    return node;
}

// Function to insert a node into the hash table
void insert_node(hash_table **table, char *key, char *str) {
    hash_table *s;

    HASH_FIND_STR(*table, key, s);
    if (s == NULL) {
        s = (hash_table *)malloc(sizeof(hash_table));
        strcpy(s->key, key);
        s->head = new_string_node(str);
        s->list_size = 1;
        HASH_ADD_STR(*table, key, s);
    } else {
        // Append to the list of strings
        string_node *new_node = new_string_node(str);
        new_node->next = s->head;
        s->head = new_node;
        s->list_size++;
    }
}

// Function to generate a key from a string
void create_key(char *str, char *key) {
    int count[26] = {0};
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        count[str[i] - 'a']++;
    }
    key[0] = '\0';
    for (int i = 0; i < 26; i++) {
        char buffer[10];
        sprintf(buffer, "#%d", count[i]);
        strcat(key, buffer);
    }
}

// Updated groupAnagrams function
char ***groupAnagrams(char **strs, int strsSize, int *returnSize,
                      int **returnColumnSizes) {
    hash_table *table = NULL, *item, *tmp;
    char ***result;

    // Build the hash table
    for (int i = 0; i < strsSize; i++) {
        char key[104] = {0};
        create_key(strs[i], key);
        insert_node(&table, key, strs[i]);
    }

    *returnSize = HASH_COUNT(table);
    result = (char ***)malloc((*returnSize) * sizeof(char **));
    *returnColumnSizes = (int *)malloc((*returnSize) * sizeof(int));

    int idx = 0;
    HASH_ITER(hh, table, item, tmp) {
        result[idx] = (char **)malloc(item->list_size * sizeof(char *));
        (*returnColumnSizes)[idx] = item->list_size;
        int node_idx = 0;
        for (string_node *node = item->head; node != NULL; node = node->next) {
            result[idx][node_idx++] = node->str;
        }
        idx++;
    }

    // Free the hash table structure, not the strings, as they are returned
    HASH_ITER(hh, table, item, tmp) {
        HASH_DEL(table, item);
        string_node *current = item->head, *next;
        while (current != NULL) {
            next = current->next;
            free(current);  // Free the node, but not the string
            current = next;
        }
        free(item);
    }

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) return vector<vector<string>>();
        unordered_map<string, vector<string>> ans;
        int count[26];
        for (string s : strs) {
            fill(begin(count), end(count), 0);
            for (char c : s) count[c - 'a']++;
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += "#";
                key += to_string(count[i]);
            }
            if (ans.find(key) == ans.end()) ans[key] = vector<string>();
            ans[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto itr = ans.begin(); itr != ans.end(); ++itr)
            result.push_back(itr->second);
        return result;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        if (strs.Length == 0)
            return new List<IList<string>>();  // an empty string
        Dictionary<string, List<string>> ans =
            new Dictionary<string, List<string>>();
        int[] count = new int[26];
        foreach (string s in strs) {
            for (int i = 0; i < 26; ++i) {
                count[i] = 0;
            }

            // Increase the count as per char
            foreach (char c in s) count[c - 'a']++;
            StringBuilder sb = new StringBuilder("");
            for (int i = 0; i < 26; i++) {
                sb.Append('#');
                sb.Append(count[i]);
            }

            string key = sb.ToString();
            if (!ans.ContainsKey(key))
                ans[key] = new List<string>();
            ans[key].Add(s);
        }

        return new List<IList<string>>(ans.Values);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func groupAnagrams(strs []string) [][]string {
    if len(strs) == 0 {
        return [][]string{}
    }
    ans := make(map[string][]string)
    count := make([]int, 26)
    for _, s := range strs {
        for i := 0; i < 26; i++ {
            count[i] = 0
        }
        for _, c := range s {
            count[c-'a']++
        }
        key := ""
        for i := 0; i < 26; i++ {
            key += "#"
            key += strconv.Itoa(count[i])
        }
        if _, ok := ans[key]; !ok {
            ans[key] = []string{}
        }
        ans[key] = append(ans[key], s)
    }
    result := [][]string{}
    for _, v := range ans {
        result = append(result, v)
    }
    return result
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs.length == 0) return new ArrayList();
        Map<String, List> ans = new HashMap<String, List>();
        int[] count = new int[26];
        for (String s : strs) {
            Arrays.fill(count, 0);
            for (char c : s.toCharArray()) count[c - 'a']++;

            StringBuilder sb = new StringBuilder("");
            for (int i = 0; i < 26; i++) {
                sb.append('#');
                sb.append(count[i]);
            }
            String key = sb.toString();
            if (!ans.containsKey(key)) ans.put(key, new ArrayList());
            ans.get(key).add(s);
        }
        return new ArrayList(ans.values());
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var groupAnagrams = function (strs) {
    if (strs.length == 0) return [];
    let ans = {};
    for (let s of strs) {
        let count = Array(26).fill(0);
        for (let c of s) count[c.charCodeAt(0) - "a".charCodeAt(0)]++;
        let key = "";
        for (let i = 0; i < 26; i++) {
            key += "#";
            key += count[i];
        }
        if (!ans[key]) ans[key] = [];
        ans[key].push(s);
    }
    return Object.values(ans);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = collections.defaultdict(list)
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord("a")] += 1
            ans[tuple(count)].append(s)
        return list(ans.values())
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function groupAnagrams(strs: string[]): string[][] {
    if (strs.length === 0) return [];
    let ans: { [key: string]: string[] } = {};
    for (let s of strs) {
        let count: number[] = Array(26).fill(0);
        for (let c of s) count[c.charCodeAt(0) - "a".charCodeAt(0)]++;
        let key = "";
        for (let i = 0; i < 26; i++) {
            key += "#";
            key += count[i];
        }
        if (!ans[key]) ans[key] = [];
        ans[key].push(s);
    }
    return Object.values(ans);
}
```

</details>
