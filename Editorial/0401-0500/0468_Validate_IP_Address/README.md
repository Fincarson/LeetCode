# 468. Validate IP Address

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/validate-ip-address/)  
`String`

**Problem Link:** [LeetCode 468 - Validate IP Address](https://leetcode.com/problems/validate-ip-address/)

## Problem

Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.

A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.

A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

- 1 <= xi.length <= 4
- xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
- Leading zeros are allowed in xi.

For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.

### Example 1

```text
Input: queryIP = "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".
```

### Example 2

```text
Input: queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".
```

### Example 3

```text
Input: queryIP = "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.
```

## Constraints

- queryIP consists only of English letters, digits and the characters '.' and ':'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [IP to CIDR](https://leetcode.com/problems/ip-to-cidr/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Strong Password Checker II](https://leetcode.com/problems/strong-password-checker-ii/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 468. Validate IP Address

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Regex | C++, Java, Python3 |
| Divide and Conquer | C++, Java, Python3 |

## Approach 1: Regex

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string validIPAddress(string IP) {
        const string chunkIPv4 =
            "([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])";
        regex patternIPv4("^(" + chunkIPv4 + "\\.){3}" + chunkIPv4 + "$");

        const string chunkIPv6 = "([0-9a-fA-F]{1,4})";
        regex patternIPv6("^(" + chunkIPv6 + "\\:){7}" + chunkIPv6 + "$");

        if (regex_match(IP, patternIPv4)) return "IPv4";
        return regex_match(IP, patternIPv6) ? "IPv6" : "Neither";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.regex.Pattern;

class Solution {

    String chunkIPv4 = "([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])";
    Pattern pattenIPv4 = Pattern.compile(
        "^(" + chunkIPv4 + "\\.){3}" + chunkIPv4 + "$"
    );

    String chunkIPv6 = "([0-9a-fA-F]{1,4})";
    Pattern pattenIPv6 = Pattern.compile(
        "^(" + chunkIPv6 + "\\:){7}" + chunkIPv6 + "$"
    );

    public String validIPAddress(String IP) {
        if (pattenIPv4.matcher(IP).matches()) return "IPv4";
        return (pattenIPv6.matcher(IP).matches()) ? "IPv6" : "Neither";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import re


class Solution:
    chunkIPv4 = "([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])"
    patternIPv4 = "^(" + chunkIPv4 + "\\.){3}" + chunkIPv4 + "$"

    chunkIPv6 = "([0-9a-fA-F]{1,4})"
    patternIPv6 = "^(" + chunkIPv6 + "\\:){7}" + chunkIPv6 + "$"

    def validIPAddress(self, IP: str) -> str:
        if re.fullmatch(self.patternIPv4, IP):
            return "IPv4"
        if re.fullmatch(self.patternIPv6, IP):
            return "IPv6"
        return "Neither"
```

</details>

<br>

## Approach 2: Divide and Conquer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string validateIPv4(string IP) {
        IP.push_back('.');  // add extra . at end to handle last group
        stringstream ss(IP);
        string block;
        int count = 0;
        while (getline(ss, block, '.')) {
            count++;
            // Validate integer in range (0, 255):
            // 1. length of chunk is between 1 and 3
            if (block.length() == 0 || block.length() > 3) return "Neither";
            // 2. no extra leading zeros
            if (block[0] == '0' && block.length() != 1) return "Neither";
            for (char ch : block) {
                // 3. only digits are allowed
                if (!isdigit(ch)) return "Neither";
            }
            // 4. less than or equal to 255
            if (stoi(block) > 255) return "Neither";
        }
        return (count == 4 && ss.eof()) ? "IPv4" : "Neither";
    }

    string validateIPv6(string IP) {
        IP.push_back(':');  // add extra : at end to handle last group
        stringstream ss(IP);
        string block;
        int count = 0;
        while (getline(ss, block, ':')) {
            count++;
            // Validate hexadecimal in range (0, 2**16):
            // 1. at least one and not more than 4 hexdigits in one chunk
            if (block.length() == 0 || block.length() > 4) return "Neither";
            for (char ch : block) {
                // 2. only hexdigits are allowed: 0-9, a-f, A-F
                if (!isxdigit(ch)) return "Neither";
            }
        }
        return (count == 8 && ss.eof()) ? "IPv6" : "Neither";
    }

    string validIPAddress(string IP) {
        return (count(begin(IP), end(IP), '.') == 3)
                   ? validateIPv4(IP)
                   : (count(begin(IP), end(IP), ':') == 7 ? validateIPv6(IP)
                                                          : "Neither");
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String validateIPv4(String IP) {
        String[] nums = IP.split("\\.", -1);
        for (String x : nums) {
            // Validate integer in range (0, 255):
            // 1. length of chunk is between 1 and 3
            if (x.length() == 0 || x.length() > 3) return "Neither";
            // 2. no extra leading zeros
            if (x.charAt(0) == '0' && x.length() != 1) return "Neither";
            // 3. only digits are allowed
            for (char ch : x.toCharArray()) {
                if (!Character.isDigit(ch)) return "Neither";
            }
            // 4. less than or equal to 255
            if (Integer.parseInt(x) > 255) return "Neither";
        }
        return "IPv4";
    }

    public String validateIPv6(String IP) {
        String[] nums = IP.split(":", -1);
        String hexdigits = "0123456789abcdefABCDEF";
        for (String x : nums) {
            // Validate hexadecimal in range (0, 2**16):
            // 1. at least one and not more than 4 hexdigits in one chunk
            if (x.length() == 0 || x.length() > 4) return "Neither";
            // 2. only hexdigits are allowed: 0-9, a-f, A-F
            for (Character ch : x.toCharArray()) {
                if (hexdigits.indexOf(ch) == -1) return "Neither";
            }
        }
        return "IPv6";
    }

    public String validIPAddress(String IP) {
        if (IP.chars().filter(ch -> ch == '.').count() == 3) {
            return validateIPv4(IP);
        } else if (IP.chars().filter(ch -> ch == ':').count() == 7) {
            return validateIPv6(IP);
        } else return "Neither";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def validateIPv4(self, IP):
        nums = IP.split(".")
        for x in nums:
            # Validate integer in range (0, 255):
            # 1. length of chunk is between 1 and 3
            if len(x) == 0 or len(x) > 3:
                return "Neither"
            # 2. no extra leading zeros
            if x[0] == "0" and len(x) != 1:
                return "Neither"
            # 3. only digits are allowed
            if not x.isdigit():
                return "Neither"
            # 4. less than or equal to 255
            if int(x) > 255:
                return "Neither"
        return "IPv4"

    def validateIPv6(self, IP):
        nums = IP.split(":")
        hexdigits = "0123456789abcdefABCDEF"
        for x in nums:
            # Validate hexadecimal in range (0, 2**16):
            # 1. at least one and not more than 4 hexsigits in one chunk
            if len(x) == 0 or len(x) > 4:
                return "Neither"
            # 2. only hexdigits are allowed: 0-9, a-f, A-F
            for ch in x:
                if ch not in hexdigits:
                    return "Neither"
        return "IPv6"

    def validIPAddress(self, IP):
        if IP.count(".") == 3:
            return self.validateIPv4(IP)
        elif IP.count(":") == 7:
            return self.validateIPv6(IP)
        else:
            return "Neither"
```

</details>
