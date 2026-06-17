# 599. Minimum Index Sum of Two Lists

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/minimum-index-sum-of-two-lists/)  
`Array` `Hash Table` `String`

**Problem Link:** [LeetCode 599 - Minimum Index Sum of Two Lists](https://leetcode.com/problems/minimum-index-sum-of-two-lists/)

## Problem

Given two arrays of strings list1 and list2, find the common strings with the least index sum.

A common string is a string that appeared in both list1 and list2.

A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] then i + j should be the minimum value among all the other common strings.

Return all the common strings with the least index sum. Return the answer in any order.

### Example 1

```text
Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
Output: ["Shogun"]
Explanation: The only common string is "Shogun".
```

### Example 2

```text
Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
Output: ["Shogun"]
Explanation: The common string with the least index sum is "Shogun" with index sum = (0 + 1) = 1.
```

### Example 3

```text
Input: list1 = ["happy","sad","good"], list2 = ["sad","happy","good"]
Output: ["sad","happy"]
Explanation: There are three common strings:
"happy" with index sum = (0 + 1) = 1.
"sad" with index sum = (1 + 0) = 1.
"good" with index sum = (2 + 2) = 4.
The strings with the least index sum are "sad" and "happy".
```

## Constraints

- 1 <= list1.length, list2.length <= 1000
- 1 <= list1[i].length, list2[i].length <= 30
- list1[i] and list2[i] consist of spaces ' ' and English letters.
- All the strings of list1 are unique.
- All the strings of list2 are unique.
- There is at least a common string between list1 and list2.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 599. Minimum Index Sum of Two Lists

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Using HashMap [Accepted] | Java |
| Approach #2 Without Using HashMap [Accepted] | Java |
| Approach #3 Using HashMap (linear) [Accepted] | Java |

## Approach #1 Using HashMap [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        HashMap < Integer, List < String >> map = new HashMap < > ();
        for (int i = 0; i < list1.length; i++) {
            for (int j = 0; j < list2.length; j++) {
                if (list1[i].equals(list2[j])) {
                    if (!map.containsKey(i + j))
                        map.put(i + j, new ArrayList < String > ());
                    map.get(i + j).add(list1[i]);
                }
            }
        }
        int min_index_sum = Integer.MAX_VALUE;
        for (int key: map.keySet())
            min_index_sum = Math.min(min_index_sum, key);
        String[] res = new String[map.get(min_index_sum).size()];
        return map.get(min_index_sum).toArray(res);
    }
}
```

</details>

<br>

## Approach #2 Without Using HashMap [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        List < String > res = new ArrayList < > ();
        for (int sum = 0; sum < list1.length + list2.length - 1; sum++) {
            for (int i = 0; i <= sum; i++) {
                if (i < list1.length && sum - i < list2.length && list1[i].equals(list2[sum - i]))
                    res.add(list1[i]);
            }
            if (res.size() > 0)
                break;
        }
        return res.toArray(new String[res.size()]);
    }
}
```

</details>

<br>

## Approach #3 Using HashMap (linear) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        HashMap < String, Integer > map = new HashMap < String, Integer > ();
        for (int i = 0; i < list1.length; i++)
            map.put(list1[i], i);
        List < String > res = new ArrayList < > ();
        int min_sum = Integer.MAX_VALUE, sum;
        for (int j = 0; j < list2.length && j <= min_sum; j++) {
            if (map.containsKey(list2[j])) {
                sum = j + map.get(list2[j]);
                if (sum < min_sum) {
                    res.clear();
                    res.add(list2[j]);
                    min_sum = sum;
                } else if (sum == min_sum)
                    res.add(list2[j]);
            }
        }
        return res.toArray(new String[res.size()]);
    }
}
```

</details>
