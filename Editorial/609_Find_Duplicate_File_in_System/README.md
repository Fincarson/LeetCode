# 609. Find Duplicate File in System

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-duplicate-file-in-system/)  
`Array` `Hash Table` `String`

**Problem Link:** [LeetCode 609 - Find Duplicate File in System](https://leetcode.com/problems/find-duplicate-file-in-system/)

## Problem

Given a list paths of directory info, including the directory path, and all the files with contents in this directory, return all the duplicate files in the file system in terms of their paths. You may return the answer in any order.

A group of duplicate files consists of at least two files that have the same content.

A single directory info string in the input list has the following format:

- "root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"

It means there are n files (f1.txt, f2.txt ... fn.txt) with content (f1_content, f2_content ... fn_content) respectively in the directory "root/d1/d2/.../dm". Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The output is a list of groups of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:

- "directory_path/file_name.txt"

### Example 1

```text
Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
```

### Example 2

```text
Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt"],["root/a/1.txt","root/c/3.txt"]]
```

## Constraints

- 1 <= paths.length <= 2 * 104
- 1 <= paths[i].length <= 3000
- 1 <= sum(paths[i].length) <= 5 * 105
- paths[i] consist of English letters, digits, '/', '.', '(', ')', and ' '.
- You may assume no files or directories share the same name in the same directory.
- You may assume each given directory info represents a unique directory. A single blank space separates the directory path and file info.

Follow up:

- Imagine you are given a real file system, how will you search files? DFS or BFS?
- If the file content is very large (GB level), how will you modify your solution?
- If you can only read the file by 1kb each time, how will you modify your solution?
- What is the time complexity of your modified solution? What is the most time-consuming part and memory-consuming part of it? How to optimize?
- How to make sure the duplicated files you find are not false positive?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Delete Duplicate Folders in System](https://leetcode.com/problems/delete-duplicate-folders-in-system/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 609. Find Duplicate File in System

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Time Limit Exceeded] | Java |
| Approach #2 Using HashMap [Accepted] | Java |

## Approach #1 Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public List < List < String >> findDuplicate(String[] paths) {
        List < String[] > list = new ArrayList < > ();
        for (String path: paths) {
            String[] values = path.split(" ");
            for (int i = 1; i < values.length; i++) {
                String[] name_cont = values[i].split("\\(");
                name_cont[1] = name_cont[1].replace(")", "");
                list.add(new String[] {
                    values[0] + "/" + name_cont[0], name_cont[1]
                });
            }
        }
        boolean[] visited = new boolean[list.size()];
        List < List < String >> res = new ArrayList < > ();
        for (int i = 0; i < list.size() - 1; i++) {
            if (visited[i])
                continue;
            List < String > l = new ArrayList < > ();
            for (int j = i + 1; j < list.size(); j++) {
                if (list.get(i)[1].equals(list.get(j)[1])) {
                    l.add(list.get(j)[0]);
                    visited[j] = true;
                }
            }
            if (l.size() > 0) {
                l.add(list.get(i)[0]);
                res.add(l);
            }
        }
        return res;
    }
}
```

</details>

<br>

## Approach #2 Using HashMap [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {
    public List < List < String >> findDuplicate(String[] paths) {
        HashMap < String, List < String >> map = new HashMap < > ();
        for (String path: paths) {
            String[] values = path.split(" ");
            for (int i = 1; i < values.length; i++) {
                String[] name_cont = values[i].split("\\(");
                name_cont[1] = name_cont[1].replace(")", "");
                List < String > list = map.getOrDefault(name_cont[1], new ArrayList < String > ());
                list.add(values[0] + "/" + name_cont[0]);
                map.put(name_cont[1], list);
            }
        }
        List < List < String >> res = new ArrayList < > ();
        for (String key: map.keySet()) {
            if (map.get(key).size() > 1)
                res.add(map.get(key));
        }
        return res;
    }
}
```

</details>
