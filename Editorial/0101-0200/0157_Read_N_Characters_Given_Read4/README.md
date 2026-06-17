# 157. Read N Characters Given Read4

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/read-n-characters-given-read4/)  
`Array` `Simulation` `Interactive`

**Problem Link:** [LeetCode 157 - Read N Characters Given Read4](https://leetcode.com/problems/read-n-characters-given-read4/)

## Problem

Given a file and assume that you can only read the file using a given method read4, implement a method to read n characters.

Method read4:

The API read4 reads four consecutive characters from file, then writes those characters into the buffer array buf4.

The return value is the number of actual characters read.

Note that read4() has its own file pointer, much like FILE *fp in C.

Definition of read4:

```text
Parameter:  char[] buf4
    Returns:    int

buf4[] is a destination, not a source. The results from read4 will be copied to buf4[].
```

Below is a high-level example of how read4 works:

```text
File file("abcde"); // File is "abcde", initially file pointer (fp) points to 'a'
char[] buf4 = new char[4]; // Create buffer with enough space to store characters
read4(buf4); // read4 returns 4. Now buf4 = "abcd", fp points to 'e'
read4(buf4); // read4 returns 1. Now buf4 = "e", fp points to end of file
read4(buf4); // read4 returns 0. Now buf4 = "", fp points to end of file
```

Method read:

By using the read4 method, implement the method read that reads n characters from file and store it in the buffer array buf. Consider that you cannot manipulate file directly.

The return value is the number of actual characters read.

Definition of read:

```text
Parameters:	char[] buf, int n
    Returns:	int

buf[] is a destination, not a source. You will need to write the results to buf[].
```

Note:

- Consider that you cannot manipulate the file directly. The file is only accessible for read4 but not for read.
- The read function will only be called once for each test case.
- You may assume the destination buffer array, buf, is guaranteed to have enough space for storing n characters.

### Example 1

```text
Input: file = "abc", n = 4
Output: 3
Explanation: After calling your read method, buf should contain "abc". We read a total of 3 characters from the file, so return 3.
Note that "abc" is the file's content, not buf. buf is the destination buffer that you will have to write the results to.
```

### Example 2

```text
Input: file = "abcde", n = 5
Output: 5
Explanation: After calling your read method, buf should contain "abcde". We read a total of 5 characters from the file, so return 5.
```

### Example 3

```text
Input: file = "abcdABCD1234", n = 12
Output: 12
Explanation: After calling your read method, buf should contain "abcdABCD1234". We read a total of 12 characters from the file, so return 12.
```

## Constraints

- 1 <= file.length <= 500
- file consist of English letters and digits.
- 1 <= n <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Read N Characters Given read4 II - Call Multiple Times](https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 157. Read N Characters Given Read4

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Use Internal Buffer of 4 Characters | C++, C#, Java, Python3 |
| Speed Up: No Internal Buffer | C, C++, C#, Java, Python3 |

## Approach 1: Use Internal Buffer of 4 Characters

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int read(char *buf, int n) {
        int copiedChars = 0, readChars = 4;
        char buf4[4];

        while (copiedChars < n && readChars == 4) {
            readChars = read4(buf4);

            for (int i = 0; i < readChars; ++i) {
                if (copiedChars == n) return copiedChars;
                buf[copiedChars] = buf4[i];
                ++copiedChars;
            }
        }
        return copiedChars;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution : Reader4 {
    public int Read(char[] buf, int n) {
        int copiedChars = 0, readChars = 4;
        char[] buf4 = new char[4];

        while (copiedChars < n && readChars == 4) {
            readChars = Read4(buf4);

            for (int i = 0; i < readChars; i++) {
                if (copiedChars == n)
                    return copiedChars;
                buf[copiedChars] = buf4[i];
                copiedChars++;
            }
        }

        return copiedChars;
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution extends Reader4 {
    public int read(char[] buf, int n) {
        int copiedChars = 0, readChars = 4;
        char[] buf4 = new char[4];

        while (copiedChars < n && readChars == 4) {
            readChars = read4(buf4);

            for (int i = 0; i < readChars; ++i) {
                if (copiedChars == n) return copiedChars;
                buf[copiedChars] = buf4[i];
                ++copiedChars;
            }
        }
        return copiedChars;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def read(self, buf: List[str], n: int) -> int:
        copied_chars = 0
        read_chars = 4
        buf4 = [""] * 4

        while copied_chars < n and read_chars == 4:
            read_chars = read4(buf4)

            for i in range(read_chars):
                if copied_chars == n:
                    return copied_chars
                buf[copied_chars] = buf4[i]
                copied_chars += 1

        return copied_chars
```

</details>

<br>

## Approach 2: Speed Up: No Internal Buffer

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int _read(char* buf, int n) {
    int copiedChars = 0;
    int readChars = 4;
    int remainingChars = n;

    // While there are at least 4 characters remaining to be read and the last
    // call to readChars returned 4 characters, write directly to buf.
    while (remainingChars >= 4 && readChars == 4) {
        readChars = read4(buf + copiedChars);
        copiedChars += readChars;
    }

    // If there are between 1 and 3 characters that we still want to read and
    // readChars was not 0 last time we called read4, then create a buffer
    // for just this one call so we can ensure buf does not overflow.
    if (remainingChars && readChars) {
        char buf4[4];
        readChars = read4(buf4);
        readChars = remainingChars < readChars ? remainingChars : readChars;
        for (int i = 0; i < readChars; i++) {
            buf[copiedChars++] = buf4[i];
        }
    }

    return n < copiedChars ? n : copiedChars;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int read(char *buf, int n) {
        int copiedChars = 0;
        int readChars = 4;
        int remainingChars = n;

        // While there are at least 4 characters remaining to be read and the
        // last call to readChars returned 4 characters, write directly to buf.
        while (remainingChars >= 4 && readChars == 4) {
            readChars = read4(buf + copiedChars);
            copiedChars += readChars;
        }

        // If there are between 1 and 3 characters that we still want to read
        // and readChars was not 0 last time we called read4, then create a
        // buffer for just this one call so we can ensure buf does not overflow.
        if (remainingChars && readChars) {
            char buf4[4];
            readChars = read4(buf4);
            for (int i = 0; i < min(remainingChars, readChars); i++) {
                buf[copiedChars++] = buf4[i];
            }
        }

        return min(n, copiedChars);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution : Reader4 {
    public int Read(char[] buf, int n) {
        int copiedChars = 0;
        int readChars = 4;
        int remainingChars = n;

        // While there are at least 4 characters remaining to be read and the last
        // call to readChars returned 4 characters, write directly to buf.
        while (remainingChars >= 4 && readChars == 4) {
            char[] buf4 = new char[4];
            readChars = Read4(buf4);
            for (int i = 0; i < readChars; i++) {
                buf[copiedChars + i] = buf4[i];
            }

            copiedChars += readChars;
        }

        // If there are between 1 and 3 characters that we still want to read and
        // readChars was not 0 last time we called read4, then create a buffer
        // for just this one call so we can ensure buf does not overflow.
        if (remainingChars > 0 && readChars != 0) {
            char[] buf4 = new char[4];
            readChars = Read4(buf4);

            for (int i = 0; i < Math.Min(remainingChars, readChars); i++) {
                buf[copiedChars++] = buf4[i];
            }
        }

        return Math.Min(n, copiedChars);
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution extends Reader4 {
    public int read(char[] buf, int n) {
        int copiedChars = 0;
        int readChars = 4;
        int remainingChars = n;

        // While there are at least 4 characters remaining to be read and the last
        // call to readChars returned 4 characters, write directly to buf.
        while (remainingChars >= 4 && readChars == 4) {
            char[] tempBuf = new char[4];
            readChars = read4(tempBuf);
            for (int i = 0; i < readChars; i++) {
                buf[copiedChars + i] = tempBuf[i];
            }
            copiedChars += readChars;
        }

        // If there are between 1 and 3 characters that we still want to read and
        // readChars was not 0 last time we called read4, then create a buffer
        // for just this one call so we can ensure buf does not overflow.
        if (remainingChars > 0 && readChars != 0) {
            char[] tempBuf = new char[4];
            readChars = read4(tempBuf);

            for (int i = 0; i < Math.min(remainingChars, readChars); i++) {
                buf[copiedChars++] = tempBuf[i];
            }
        }

        return Math.min(n, copiedChars);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def read(self, buf, n):
        """
        :type buf: Destination buffer (List[str])
        :type n: Number of characters to read (int)
        :rtype: The number of actual characters read (int)
        """
        copiedChars = 0
        readChars = 4
        remainingChars = n

        # While there are at least 4 characters remaining to be read and the last
        # call to readChars returned 4 characters, write directly to buf.
        while remainingChars >= 4 and readChars == 4:
            buf4 = [""] * 4
            readChars = read4(buf4)
            for i in range(readChars):
                buf[copiedChars + i] = buf4[i]
            copiedChars += readChars

        # If there are between 1 and 3 characters that we still want to read and
        # readChars was not 0 last time we called read4, then create a buffer
        # for just this one call so we can ensure buf does not overflow.
        if remainingChars > 0 and readChars != 0:
            buf4 = [""] * 4
            readChars = read4(buf4)

            for i in range(min(remainingChars, readChars)):
                buf[copiedChars + i] = buf4[i]
            copiedChars += readChars

        return min(n, copiedChars)
```

</details>
