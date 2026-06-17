# 3272. Find the Count of Good Integers

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/find-the-count-of-good-integers/)  
`Hash Table` `Math` `Combinatorics` `Enumeration`

**Problem Link:** [LeetCode 3272 - Find the Count of Good Integers](https://leetcode.com/problems/find-the-count-of-good-integers/)

## Problem

You are given two positive integers n and k.

An integer x is called k-palindromic if:

- x is a palindrome.
- x is divisible by k.

An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.

Return the count of good integers containing n digits.

Note that any integer must not have leading zeros, neither before nor after rearrangement. For example, 1010 cannot be rearranged to form 101.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= n <= 10
- 1 <= k <= 9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find the Closest Palindrome](https://leetcode.com/problems/find-the-closest-palindrome/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3272. Find the Count of Good Integers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumeration + Permutations and Combinations | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Enumeration + Permutations and Combinations

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    char *key;
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
    pEntry->key = strdup(key);
    HASH_ADD_STR(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr->key);
        free(curr);
    }
}

int compare(const void *a, const void *b) { return (*(char *)a - *(char *)b); }

long long countGoodIntegers(int n, int k) {
    HashItem *dict = NULL;
    int base = (int)pow(10, (n - 1) / 2);
    int skip = n & 1;
    /* Enumerate the number of palindrome numbers of n digits */
    for (int i = base; i < base * 10; i++) {
        char s[16];
        sprintf(s, "%d", i);
        int len = strlen(s);
        for (int j = len - 1 - skip; j >= 0; j--) {
            s[len + (len - skip - 1 - j)] = s[j];
        }
        s[2 * len - skip] = '\0';
        long long palindromicInteger = atoll(s);
        /* If the current palindrome number is a k-palindromic integer */
        if (palindromicInteger % k == 0) {
            qsort(s, strlen(s), sizeof(char), compare);
            hashAddItem(&dict, s);
        }
    }

    long long *factorial = malloc((n + 1) * sizeof(long long));
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    long long ans = 0;
    for (HashItem *pEntry = dict; pEntry; pEntry = pEntry->hh.next) {
        int cnt[10] = {0};
        for (int j = 0; pEntry->key[j] != '\0'; j++) {
            cnt[pEntry->key[j] - '0']++;
        }
        /* Calculate permutations and combinations */
        long long tot = (n - cnt[0]) * factorial[n - 1];
        for (int j = 0; j < 10; j++) {
            tot /= factorial[cnt[j]];
        }
        ans += tot;
    }

    free(factorial);
    hashFree(&dict);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> dict;
        int base = pow(10, (n - 1) / 2);
        int skip = n & 1;
        /* Enumerate the number of palindrome numbers of n digits */
        for (int i = base; i < base * 10; i++) {
            string s = to_string(i);
            s += string(s.rbegin() + skip, s.rend());
            long long palindromicInteger = stoll(s);
            /* If the current palindrome number is a k-palindromic integer */
            if (palindromicInteger % k == 0) {
                sort(s.begin(), s.end());
                dict.emplace(s);
            }
        }

        vector<long long> factorial(n + 1, 1);
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        for (const string &s : dict) {
            vector<int> cnt(10);
            for (char c : s) {
                cnt[c - '0']++;
            }
            /* Calculate permutations and combinations */
            long long tot = (n - cnt[0]) * factorial[n - 1];
            for (int x : cnt) {
                tot /= factorial[x];
            }
            ans += tot;
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
    public long CountGoodIntegers(int n, int k) {
        var dict = new HashSet<string>();
        int baseVal = (int)Math.Pow(10, (n - 1) / 2);
        int skip = n & 1;
        /* Enumerate the number of palindrome numbers of n digits */
        for (int i = baseVal; i < baseVal * 10; i++) {
            string s = i.ToString();
            s += new string(s.Reverse().Skip(skip).ToArray());
            long palindromicInteger = long.Parse(s);
            /* If the current palindrome number is a k-palindromic integer */
            if (palindromicInteger % k == 0) {
                char[] chars = s.ToCharArray();
                Array.Sort(chars);
                dict.Add(new string(chars));
            }
        }

        long[] factorial = new long[n + 1];
        factorial[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        long ans = 0;
        foreach (string s in dict) {
            int[] cnt = new int[10];
            foreach (char c in s) {
                cnt[c - '0']++;
            }
            /* Calculate permutations and combinations */
            long tot = (n - cnt[0]) * factorial[n - 1];
            foreach (int x in cnt) {
                tot /= factorial[x];
            }
            ans += tot;
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countGoodIntegers(n int, k int) int64 {
	dict := make(map[string]bool)
	base := intPow(10, (n-1)/2)
	skip := n & 1
	/* Enumerate the number of palindrome numbers of n digits */
	for i := base; i < base*10; i++ {
		s := strconv.Itoa(i)
		rev := reverseString(s)
		s += rev[skip:]
		palindromicInteger, _ := strconv.ParseInt(s, 10, 64)
		/* If the current palindrome number is a k-palindromic integer */
		if palindromicInteger%int64(k) == 0 {
			chars := strings.Split(s, "")
			sort.Strings(chars)
			dict[strings.Join(chars, "")] = true
		}
	}

	factorial := make([]int64, n+1)
	factorial[0] = 1
	for i := 1; i <= n; i++ {
		factorial[i] = factorial[i-1] * int64(i)
	}

	var ans int64 = 0
	for s := range dict {
		cnt := make([]int, 10)
		for _, c := range s {
			cnt[c-'0']++
		}
		/* Calculate permutations and combinations */
		tot := int64(n-cnt[0]) * factorial[n-1]
		for _, x := range cnt {
			tot /= factorial[x]
		}
		ans += tot
	}

	return ans
}

func intPow(a, b int) int {
	result := 1
	for i := 0; i < b; i++ {
		result *= a
	}
	return result
}

func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long countGoodIntegers(int n, int k) {
        Set<String> dict = new HashSet<>();
        int base = (int) Math.pow(10, (n - 1) / 2);
        int skip = n & 1;
        /* Enumerate the number of palindrome numbers of n digits */
        for (int i = base; i < base * 10; i++) {
            String s = Integer.toString(i);
            s += new StringBuilder(s).reverse().substring(skip);
            long palindromicInteger = Long.parseLong(s);
            /* If the current palindrome number is a k-palindromic integer */
            if (palindromicInteger % k == 0) {
                char[] chars = s.toCharArray();
                Arrays.sort(chars);
                dict.add(new String(chars));
            }
        }

        long[] factorial = new long[n + 1];
        factorial[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        long ans = 0;
        for (String s : dict) {
            int[] cnt = new int[10];
            for (char c : s.toCharArray()) {
                cnt[c - '0']++;
            }
            /* Calculate permutations and combinations */
            long tot = (n - cnt[0]) * factorial[n - 1];
            for (int x : cnt) {
                tot /= factorial[x];
            }
            ans += tot;
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countGoodIntegers = function (n, k) {
    const dict = new Set();
    const base = Math.pow(10, Math.floor((n - 1) / 2));
    const skip = n & 1;
    /* Enumerate the number of palindrome numbers of n digits */
    for (let i = base; i < base * 10; i++) {
        let s = i.toString();
        s += s.split("").reverse().slice(skip).join("");
        const palindromicInteger = parseInt(s);
        /* If the current palindrome number is a k-palindromic integer */
        if (palindromicInteger % k === 0) {
            const sortedS = s.split("").sort().join("");
            dict.add(sortedS);
        }
    }

    const factorial = Array(n + 1).fill(1n);
    for (let i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * BigInt(i);
    }

    let ans = 0n;
    for (const s of dict) {
        const cnt = Array(10).fill(0);
        for (const c of s) {
            cnt[parseInt(c)]++;
        }
        /* Calculate permutations and combinations */
        let tot = BigInt(n - cnt[0]) * factorial[n - 1];
        for (const x of cnt) {
            tot /= factorial[x];
        }
        ans += tot;
    }
    return Number(ans);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        dictionary = set()
        base = 10 ** ((n - 1) // 2)
        skip = n & 1
        # Enumerate the number of palindrome numbers of n digits
        for i in range(base, base * 10):
            s = str(i)
            s += s[::-1][skip:]
            palindromicInteger = int(s)
            # If the current palindrome number is a k-palindromic integer
            if palindromicInteger % k == 0:
                sorted_s = "".join(sorted(s))
                dictionary.add(sorted_s)

        fac = [factorial(i) for i in range(n + 1)]
        ans = 0
        for s in dictionary:
            cnt = [0] * 10
            for c in s:
                cnt[int(c)] += 1
            # Calculate permutations and combinations
            tot = (n - cnt[0]) * fac[n - 1]
            for x in cnt:
                tot //= fac[x]
            ans += tot

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countGoodIntegers(n: number, k: number): number {
    const dict = new Set<string>();
    const base = Math.pow(10, Math.floor((n - 1) / 2));
    const skip = n & 1;
    /* Enumerate the number of palindrome numbers of n digits */
    for (let i = base; i < base * 10; i++) {
        let s = i.toString();
        s += s.split("").reverse().slice(skip).join("");
        const palindromicInteger = parseInt(s);
        /* If the current palindrome number is a k-palindromic integer */
        if (palindromicInteger % k === 0) {
            const sortedS = s.split("").sort().join("");
            dict.add(sortedS);
        }
    }

    const factorial: bigint[] = Array(n + 1).fill(1n);
    for (let i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * BigInt(i);
    }

    let ans = 0n;
    for (const s of dict) {
        const cnt = Array(10).fill(0);
        for (const c of s) {
            cnt[parseInt(c)]++;
        }
        /* Calculate permutations and combinations */
        let tot = BigInt(n - cnt[0]) * factorial[n - 1];
        for (const x of cnt) {
            tot /= factorial[x];
        }
        ans += tot;
    }

    return Number(ans);
}
```

</details>
