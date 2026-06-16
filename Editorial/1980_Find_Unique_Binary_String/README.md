# 1980. Find Unique Binary String

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-unique-binary-string/)  
`Array` `Hash Table` `String` `Backtracking`

**Problem Link:** [LeetCode 1980 - Find Unique Binary String](https://leetcode.com/problems/find-unique-binary-string/)

## Problem

Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

### Example 1

```text
Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
```

### Example 2

```text
Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
```

### Example 3

```text
Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
```

## Constraints

- n == nums.length
- 1 <= n <= 16
- nums[i].length == n
- nums[i] is either '0' or '1'.
- All the strings of nums are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Missing Number](https://leetcode.com/problems/missing-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Random Pick with Blacklist](https://leetcode.com/problems/random-pick-with-blacklist/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1980. Find Unique Binary String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursively Generate All Strings | C++, Java, Python3 |
| Iterate Over Integer Equivalents | C++, Java, Python3 |
| Random | C++, Java, Python3 |
| Cantor's Diagonal Argument | C++, Java, Python3 |

## Approach 1: Recursively Generate All Strings

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int n;
    unordered_set<string> numsSet;
    
    string generate(string curr) {
        if (curr.size() == n) {
            if (numsSet.find(curr) == numsSet.end()) {
                return curr;
            }
            
            return "";
        }
        
        string addZero = generate(curr + "0");
        if (addZero.size() > 0) {
            return addZero;
        }
        
        return generate(curr + "1");
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        for (string s : nums) {
            numsSet.insert(s);
        }
        
        return generate("");
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int n;
    Set<String> numsSet = new HashSet();
    
    private String generate(String curr) {
        if (curr.length() == n) {
            if (!numsSet.contains(curr)) {
                return curr;
            }
            
            return "";
        }
        
        String addZero = generate(curr + "0");
        if (addZero.length() > 0) {
            return addZero;
        }
        
        return generate(curr + "1");
    }
    
    public String findDifferentBinaryString(String[] nums) {
        n = nums.length;
        for (String s : nums) {
            numsSet.add(s);
        }
        
        return generate("");
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        def generate(curr):
            if len(curr) == n:
                if curr not in nums:
                    return curr
                
                return ""
            
            add_zero = generate(curr + "0")
            if add_zero:
                return add_zero

            return generate(curr + "1")

        n = len(nums)
        nums = set(nums)
        return generate("")
```

</details>

<br>

## Approach 2: Iterate Over Integer Equivalents

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> integers;
        for (string num : nums) {
            integers.insert(stoi(num, 0, 2));
        }
        
        int n = nums.size();
        for (int num = 0; num <= n; num++) {
            if (integers.find(num) == integers.end()) {
                string ans = bitset<16>(num).to_string();
                return ans.substr(16 - n);
            }
        }
        
        return "";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String findDifferentBinaryString(String[] nums) {
        Set<Integer> integers = new HashSet();
        for (String num : nums) {
            integers.add(Integer.parseInt(num, 2));
        }
        
        int n = nums.length;
        for (int num = 0; num <= n; num++) {
            if (!integers.contains(num)) {
                String ans = Integer.toBinaryString(num);
                while (ans.length() < n) {
                    ans = "0" + ans;
                }
                
                return ans;
            }
        }
        
        return "";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        integers = set()
        for num in nums:
            integers.add(int(num, 2))

        n = len(nums)
        for num in range(n + 1):
            if num not in integers:
                ans = bin(num)[2:]
                return "0" * (n - len(ans)) + ans
            
        return ""
```

</details>

<br>

## Approach 3: Random

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> integers;
        for (string num : nums) {
            integers.insert(stoi(num, 0, 2));
        }
        
        int ans = stoi(nums[0], 0, 2);
        int n = nums.size();
        
        while (integers.find(ans) != integers.end()) {
            ans = rand() % (int) pow(2, n);
        }
        
        return bitset<16>(ans).to_string().substr(16 - n);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String findDifferentBinaryString(String[] nums) {
        Set<Integer> integers = new HashSet();
        for (String num : nums) {
            integers.add(Integer.parseInt(num, 2));
        }
        
        int ans = Integer.parseInt(nums[0], 2);
        int n = nums.length;
        Random rand = new Random();
        
        while (integers.contains(ans)) {
            ans = rand.nextInt((int) Math.pow(2, n));
        }

        String s = Integer.toBinaryString(ans);
        while (s.length() < n) {
            s = "0" + s;
        }
        
        return s;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        integers = set()
        for num in nums:
            integers.add(int(num, 2))

        ans = int(nums[0], 2)
        n = len(nums)

        while ans in integers:
            ans = random.randrange(0, 2 ** n)
        
        s = bin(ans)[2:]
        return "0" * (n - len(s)) + s
```

</details>

<br>

## Approach 4: Cantor's Diagonal Argument

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for (int i = 0; i < nums.size(); i++) {
            char curr = nums[i][i];
            ans += curr == '0' ? '1' : '0';
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String findDifferentBinaryString(String[] nums) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < nums.length; i++) {
            Character curr = nums[i].charAt(i);
            ans.append(curr == '0' ? '1' : '0');
        }
        
        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        ans = []
        for i in range(len(nums)):
            curr = nums[i][i]
            ans.append("1" if curr == "0" else "0")
        
        return "".join(ans)
```

</details>
