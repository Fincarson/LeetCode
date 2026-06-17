# 190. Reverse Bits

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/reverse-bits/)  
`Divide and Conquer` `Bit Manipulation`

**Problem Link:** [LeetCode 190 - Reverse Bits](https://leetcode.com/problems/reverse-bits/)

## Problem

Reverse bits of a given 32 bits signed integer.

### Example 1

### Example 2

## Constraints

- 0 <= n <= 231 - 2
- n is even.

Follow up: If this function is called many times, how would you optimize it?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse Integer](https://leetcode.com/problems/reverse-integer/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [A Number After a Double Reversal](https://leetcode.com/problems/a-number-after-a-double-reversal/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 190. Reverse Bits

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bit by Bit | C++, Go, Java, Python3 |
| Byte by Byte with Memoization | C++, Go, Java, Python3 |
| Mask and Shift | C++, Go, Java, Python3 |

## Approach 1: Bit by Bit

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
  public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0, power = 31;
    while (n != 0) {
      ret += (n & 1) << power;
      n = n >> 1;
      power -= 1;
    }
    return ret;
  }
};
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func reverseBits(num uint32) uint32 {
    ret := uint32(0)
    power := uint32(31)
    for num != 0 {
        ret += (num & 1) << power
        num = num >> 1
        power -= 1
    }
    return ret
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int ret = 0, power = 31;
        while (n != 0) {
            ret += (n & 1) << power;
            n = n >>> 1;
            power -= 1;
        }
        return ret;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverseBits(self, n: int) -> int:
        ret, power = 0, 31
        while n:
            ret += (n & 1) << power
            n = n >> 1
            power -= 1
        return ret
```

</details>

<br>

## Approach 2: Byte by Byte with Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    uint32_t reverseByte(uint32_t byte, map<uint32_t, uint32_t> cache) {
        if (cache.find(byte) != cache.end()) {
            return cache[byte];
        }
        uint32_t value = (byte * 0x0202020202 & 0x010884422010) % 1023;
        cache.emplace(byte, value);
        return value;
    }

    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0, power = 24;
        map<uint32_t, uint32_t> cache;
        while (n != 0) {
            ret += reverseByte(n & 0xff, cache) << power;
            n = n >> 8;
            power -= 8;
        }
        return ret;
    }
};
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func reverseByte(b uint32, cache map[uint32]uint64) uint64 {
    value, ok := cache[b]
    if ok {
        return value
    }
    value = (uint64(b) * 0x0202020202 & 0x010884422010) % 1023
    cache[b] = value
    return value
}

func reverseBits(num uint32) uint32 {
    ret := uint64(0)
    power := uint64(24)
    var cache = map[uint32]uint64{}

    for num != 0 {
        ret += reverseByte(num & 0xff, cache) << power
        num = num >> 8
        power -= 8
    }
    return uint32(ret)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int reverseByte(int byteVal, Map<Integer, Integer> cache) {
        if (cache.containsKey(byteVal)) {
            return cache.get(byteVal);
        }
        int value = (int)(((byteVal * 0x0202020202L) & 0x010884422010L) % 1023);
        cache.put(byteVal, value);
        return value;
    }

    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int ret = 0;
        int power = 24;
        Map<Integer, Integer> cache = new HashMap<>();
        while (n != 0) {
            ret += reverseByte(n & 0xff, cache) << power;
            n >>>= 8; // Use unsigned shift
            power -= 8;
        }
        return ret;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import functools


class Solution:
    def reverseBits(self, n: int) -> int:
        ret, power = 0, 24
        while n:
            ret += self.reverseByte(n & 0xFF) << power
            n = n >> 8
            power -= 8
        return ret

    # memoization with decorator
    @functools.lru_cache(maxsize=256)
    def reverseByte(self, byte):
        return (byte * 0x0202020202 & 0x010884422010) % 1023
```

</details>

<br>

## Approach 3: Mask and Shift

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func reverseBits(num uint32) uint32 {
    num = (num >> 16) | (num << 16)
    num = ((num & 0xff00ff00) >> 8) | ((num & 0x00ff00ff) << 8)
    num = ((num & 0xf0f0f0f0) >> 4) | ((num & 0x0f0f0f0f) << 4)
    num = ((num & 0xcccccccc) >> 2) | ((num & 0x33333333) << 2)
    num = ((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1)
    return num
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int reverseBits(int n) {
        n = (n >>> 16) | (n << 16);
        n = ((n & 0xff00ff00) >>> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >>> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >>> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >>> 1) | ((n & 0x55555555) << 1);
        return n;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverseBits(self, n: int) -> int:
        n = (n >> 16) | (n << 16)
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8)
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4)
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2)
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1)
        return n
```

</details>
