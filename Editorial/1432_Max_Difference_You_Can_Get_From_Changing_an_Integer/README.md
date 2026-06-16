# 1432. Max Difference You Can Get From Changing an Integer

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/)  
`Math` `Greedy`

**Problem Link:** [LeetCode 1432 - Max Difference You Can Get From Changing an Integer](https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/)

## Problem

You are given an integer num. You will apply the following steps to num two separate times:

- Pick a digit x (0 <= x <= 9).
- Pick another digit y (0 <= y <= 9). Note y can be equal to x.
- Replace all the occurrences of x in the decimal representation of num by y.

Let a and b be the two results from applying the operation to num independently.

Return the max difference between a and b.

Note that neither a nor b may have any leading zeros, and must not be 0.

### Example 1

```text
Input: num = 555
Output: 888
Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
The second time pick x = 5 and y = 1 and store the new integer in b.
We have now a = 999 and b = 111 and max difference = 888
```

### Example 2

```text
Input: num = 9
Output: 8
Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
The second time pick x = 9 and y = 1 and store the new integer in b.
We have now a = 9 and b = 1 and max difference = 8
```

## Constraints

- 1 <= num <= 108

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1432. Max Difference You Can Get From Changing an Integer

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxDiff(int num) {
    char numStr[20];
    sprintf(numStr, "%d", num);
    int minNum = num;
    int maxNum = num;

    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            char res[20];
            strcpy(res, numStr);
            for (int i = 0; res[i]; ++i) {
                if (res[i] - '0' == x) {
                    res[i] = '0' + y;
                }
            }
            // Check if there are leading zeros
            if (res[0] != '0') {
                int res_i = atoi(res);
                if (res_i < minNum) {
                    minNum = res_i;
                }
                if (res_i > maxNum) {
                    maxNum = res_i;
                }
            }
        }
    }

    return maxNum - minNum;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxDiff(int num) {
        auto change = [&](int x, int y) {
            string num_s = to_string(num);
            for (char& digit : num_s) {
                if (digit - '0' == x) {
                    digit = '0' + y;
                }
            }
            return num_s;
        };

        int min_num = num;
        int max_num = num;
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                string res = change(x, y);
                // Check if there are leading zeros
                if (res[0] != '0') {
                    int res_i = stoi(res);
                    min_num = min(min_num, res_i);
                    max_num = max(max_num, res_i);
                }
            }
        }

        return max_num - min_num;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxDiff(int num) {
        Func<int, int, string> change = (x, y) => {
            var numStr = num.ToString();
            return new string(numStr
                                  .Select(digit => (digit - '0') == x
                                                       ? (char)('0' + y)
                                                       : digit)
                                  .ToArray());
        };

        int minNum = num;
        int maxNum = num;
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                string res = change(x, y);
                // Check if there are leading zeros
                if (res[0] != '0') {
                    int res_i = int.Parse(res);
                    minNum = Math.Min(minNum, res_i);
                    maxNum = Math.Max(maxNum, res_i);
                }
            }
        }
        return maxNum - minNum;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxDiff(num int) int {
	// Define a function "change", to replace x with y in a number.
	change := func(x, y int) string {
		numStr := strconv.Itoa(num)
		var res strings.Builder
		for _, digit := range numStr {
			if int(digit-'0') == x {
				res.WriteByte(byte('0' + y))
			} else {
				res.WriteRune(digit)
			}
		}
		return res.String()
	}

	minNum := num
	maxNum := num
	// Traverse all possible replacement combinations
	for x := 0; x < 10; x++ {
		for y := 0; y < 10; y++ {
			res := change(x, y)
			// Check if there are leading zeros
			if res[0] != '0' {
				res_i, _ := strconv.Atoi(res)
				minNum = min(minNum, res_i)
				maxNum = max(maxNum, res_i)
			}
		}
	}

	return maxNum - minNum
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxDiff(int num) {
        int min_num = num;
        int max_num = num;
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                String res = change(num, x, y);
                // Check if there are leading zeros
                if (res.charAt(0) != '0') {
                    int res_i = Integer.parseInt(res);
                    min_num = Math.min(min_num, res_i);
                    max_num = Math.max(max_num, res_i);
                }
            }
        }

        return max_num - min_num;
    }

    public String change(int num, int x, int y) {
        StringBuffer num_s = new StringBuffer(String.valueOf(num));
        int length = num_s.length();
        for (int i = 0; i < length; i++) {
            char digit = num_s.charAt(i);
            if (digit - '0' == x) {
                num_s.setCharAt(i, (char) ('0' + y));
            }
        }
        return num_s.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxDiff = function (num) {
    const change = (x, y) => {
        let numStr = num.toString();
        let res = "";
        for (let digit of numStr) {
            if (parseInt(digit) === x) {
                res += y.toString();
            } else {
                res += digit;
            }
        }
        return res;
    };

    let minNum = num;
    let maxNum = num;
    for (let x = 0; x < 10; ++x) {
        for (let y = 0; y < 10; ++y) {
            let res = change(x, y);
            // Check if there are leading zeros
            if (res[0] !== "0") {
                let resI = parseInt(res);
                minNum = Math.min(minNum, resI);
                maxNum = Math.max(maxNum, resI);
            }
        }
    }

    return maxNum - minNum;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxDiff(self, num: int) -> int:
        def change(x, y):
            return str(num).replace(str(x), str(y))

        min_num = max_num = num
        for x in range(10):
            for y in range(10):
                res = change(x, y)
                # Check if there are leading zeros
                if res[0] != "0":
                    res_i = int(res)
                    min_num = min(min_num, res_i)
                    max_num = max(max_num, res_i)

        return max_num - min_num
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxDiff(num: number): number {
    const change = (x: number, y: number): string => {
        let numStr = num.toString();
        let res = "";
        for (let digit of numStr) {
            if (parseInt(digit) === x) {
                res += y.toString();
            } else {
                res += digit;
            }
        }
        return res;
    };

    let minNum = num;
    let maxNum = num;
    for (let x = 0; x < 10; ++x) {
        for (let y = 0; y < 10; ++y) {
            let res = change(x, y);
            // Check if there are leading zeros
            if (res[0] !== "0") {
                let resI = parseInt(res);
                minNum = Math.min(minNum, resI);
                maxNum = Math.max(maxNum, resI);
            }
        }
    }

    return maxNum - minNum;
}
```

</details>

<br>

## Approach 2: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void replace(char* s, char x, char y) {
    for (int i = 0; s[i]; ++i) {
        if (s[i] == x) {
            s[i] = y;
        }
    }
}

int maxDiff(int num) {
    char minNum[20], maxNum[20];
    sprintf(minNum, "%d", num);
    sprintf(maxNum, "%d", num);
    // Find a high position and replace it with 9.
    for (int i = 0; maxNum[i]; ++i) {
        if (maxNum[i] != '9') {
            replace(maxNum, maxNum[i], '9');
            break;
        }
    }
    // Replace the most significant bit with 1
    // Or find a high-order digit that is not equal to the highest digit and
    // replace it with 0.
    for (int i = 0; minNum[i]; ++i) {
        char digit = minNum[i];
        if (i == 0) {
            if (digit != '1') {
                replace(minNum, digit, '1');
                break;
            }
        } else {
            if (digit != '0' && digit != minNum[0]) {
                replace(minNum, digit, '0');
                break;
            }
        }
    }

    return atoi(maxNum) - atoi(minNum);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxDiff(int num) {
        auto replace = [](string& s, char x, char y) {
            for (char& digit : s) {
                if (digit == x) {
                    digit = y;
                }
            }
        };

        string min_num = to_string(num);
        string max_num = to_string(num);
        // Find a high position and replace it with 9.
        for (char digit : max_num) {
            if (digit != '9') {
                replace(max_num, digit, '9');
                break;
            }
        }

        // Replace the most significant bit with 1
        // Or find a high-order digit that is not equal to the highest digit and
        // replace it with 0.
        for (int i = 0; i < min_num.size(); ++i) {
            char digit = min_num[i];
            if (i == 0) {
                if (digit != '1') {
                    replace(min_num, digit, '1');
                    break;
                }
            } else {
                if (digit != '0' && digit != min_num[0]) {
                    replace(min_num, digit, '0');
                    break;
                }
            }
        }

        return stoi(max_num) - stoi(min_num);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxDiff(int num) {
        // Replace characters in the string.
        void Replace(ref string s, char x, char y) {
            s = s.Replace(x, y);
        }
        string minNum = num.ToString();
        string maxNum = num.ToString();
        // Find a high position and replace it with 9.
        foreach (char digit in maxNum) {
            if (digit != '9') {
                Replace(ref maxNum, digit, '9');
                break;
            }
        }
        // Replace the most significant bit with 1
        // Or find a high-order digit that is not equal to the highest digit and
        // replace it with 0.
        for (int i = 0; i < minNum.Length; ++i) {
            char digit = minNum[i];
            if (i == 0) {
                if (digit != '1') {
                    Replace(ref minNum, digit, '1');
                    break;
                }
            } else {
                if (digit != '0' && digit != minNum[0]) {
                    Replace(ref minNum, digit, '0');
                    break;
                }
            }
        }
        return int.Parse(maxNum) - int.Parse(minNum);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxDiff(num int) int {
	// Replace characters in the string.
	replace := func(s string, x, y byte) string {
		return strings.ReplaceAll(s, string(x), string(y))
	}
	minNum := strconv.Itoa(num)
	maxNum := strconv.Itoa(num)
	// Find a high position and replace it with 9.
	for _, digit := range maxNum {
		if digit != '9' {
			maxNum = replace(maxNum, byte(digit), '9')
			break
		}
	}
	// Replace the most significant bit with 1
	// Or find a high-order digit that is not equal to the highest digit and
	// replace it with 0.
	for i := 0; i < len(minNum); i++ {
		digit := minNum[i]
		if i == 0 {
			if digit != '1' {
				minNum = replace(minNum, digit, '1')
				break
			}
		} else {
			if digit != '0' && digit != minNum[0] {
				minNum = replace(minNum, digit, '0')
				break
			}
		}
	}

	max, _ := strconv.Atoi(maxNum)
	min, _ := strconv.Atoi(minNum)
	return max - min
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxDiff(int num) {
        StringBuffer min_num = new StringBuffer(String.valueOf(num));
        StringBuffer max_num = new StringBuffer(String.valueOf(num));

        // Find a high position and replace it with 9.
        int max_length = max_num.length();
        for (int i = 0; i < max_length; ++i) {
            char digit = max_num.charAt(i);
            if (digit != '9') {
                replace(max_num, digit, '9');
                break;
            }
        }

        // Replace the most significant bit with 1
        // Or find a high-order digit that is not equal to the highest digit and replace it with 0.
        int min_length = min_num.length();
        for (int i = 0; i < min_length; ++i) {
            char digit = min_num.charAt(i);
            if (i == 0) {
                if (digit != '1') {
                    replace(min_num, digit, '1');
                    break;
                }
            } else {
                if (digit != '0' && digit != min_num.charAt(0)) {
                    replace(min_num, digit, '0');
                    break;
                }
            }
        }

        return (
            Integer.parseInt(max_num.toString()) -
            Integer.parseInt(min_num.toString())
        );
    }

    public void replace(StringBuffer s, char x, char y) {
        int length = s.length();
        for (int i = 0; i < length; ++i) {
            if (s.charAt(i) == x) {
                s.setCharAt(i, y);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxDiff = function (num) {
    // Replace characters in the string.
    const replace = (s, x, y) => s.split(x).join(y);
    let minNum = num.toString();
    let maxNum = num.toString();
    // Find a high position and replace it with 9.
    for (let digit of maxNum) {
        if (digit !== "9") {
            maxNum = replace(maxNum, digit, "9");
            break;
        }
    }

    // Replace the most significant bit with 1
    // Or find a high-order digit that is not equal to the highest digit and replace it with 0.
    for (let i = 0; i < minNum.length; ++i) {
        let digit = minNum[i];
        if (i === 0) {
            if (digit !== "1") {
                minNum = replace(minNum, digit, "1");
                break;
            }
        } else {
            if (digit !== "0" && digit !== minNum[0]) {
                minNum = replace(minNum, digit, "0");
                break;
            }
        }
    }

    return parseInt(maxNum) - parseInt(minNum);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxDiff(self, num: int) -> int:
        min_num, max_num = str(num), str(num)

        # Find a high position and replace it with 9.
        for digit in max_num:
            if digit != "9":
                max_num = max_num.replace(digit, "9")
                break

        # Replace the most significant bit with 1
        # Or find a high-order digit that is not equal to the highest digit and replace it with 0.
        for i, digit in enumerate(min_num):
            if i == 0:
                if digit != "1":
                    min_num = min_num.replace(digit, "1")
                    break
            else:
                if digit != "0" and digit != min_num[0]:
                    min_num = min_num.replace(digit, "0")
                    break

        return int(max_num) - int(min_num)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxDiff(num: number): number {
    // Replace characters in the string.
    const replace = (s: string, x: string, y: string): string =>
        s.split(x).join(y);
    let minNum: string = num.toString();
    let maxNum: string = num.toString();
    // Find a high position and replace it with 9.
    for (let digit of maxNum) {
        if (digit !== "9") {
            maxNum = replace(maxNum, digit, "9");
            break;
        }
    }
    // Replace the most significant bit with 1
    // Or find a high-order digit that is not equal to the highest digit and replace it with 0.
    for (let i = 0; i < minNum.length; ++i) {
        let digit = minNum[i];
        if (i === 0) {
            if (digit !== "1") {
                minNum = replace(minNum, digit, "1");
                break;
            }
        } else {
            if (digit !== "0" && digit !== minNum[0]) {
                minNum = replace(minNum, digit, "0");
                break;
            }
        }
    }

    return parseInt(maxNum) - parseInt(minNum);
}
```

</details>
