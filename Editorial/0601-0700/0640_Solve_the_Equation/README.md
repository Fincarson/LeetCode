# 640. Solve the Equation

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/solve-the-equation/)  
`Math` `String` `Simulation`

**Problem Link:** [LeetCode 640 - Solve the Equation](https://leetcode.com/problems/solve-the-equation/)

## Problem

Solve a given equation and return the value of 'x' in the form of a string "x=#value". The equation contains only '+', '-' operation, the variable 'x' and its coefficient. You should return "No solution" if there is no solution for the equation, or "Infinite solutions" if there are infinite solutions for the equation.

If there is exactly one solution for the equation, we ensure that the value of 'x' is an integer.

### Example 1

```text
Input: equation = "x+5-3+x=6+x-2"
Output: "x=2"
```

### Example 2

```text
Input: equation = "x=x"
Output: "Infinite solutions"
```

### Example 3

```text
Input: equation = "2x=x"
Output: "x=0"
```

## Constraints

- 3 <= equation.length <= 1000
- equation has exactly one '='.
- equation consists of integers with an absolute value in the range [0, 100] without any leading zeros, and the variable 'x'.
- The input is generated that if there is a single solution, it will be an integer.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Fraction Addition and Subtraction](https://leetcode.com/problems/fraction-addition-and-subtraction/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimize Result by Adding Parentheses to Expression](https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 640. Solve the Equation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Partioning Coefficients [Accepted] | Java |
| Approach #2 Using regex for spliting [Accepted] | Java |

## Approach #1 Partioning Coefficients [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {
    public String coeff(String x) {
        if (x.length() > 1 && x.charAt(x.length() - 2) >= '0' && x.charAt(x.length() - 2) <= '9')
            return x.replace("x", "");
        return x.replace("x", "1");
    }
    public String solveEquation(String equation) {
        String[] lr = equation.split("=");
        int lhs = 0, rhs = 0;
        for (String x: breakIt(lr[0])) {
            if (x.indexOf("x") >= 0) {
                lhs += Integer.parseInt(coeff(x));
            } else
                rhs -= Integer.parseInt(x);
        }
        for (String x: breakIt(lr[1])) {
            if (x.indexOf("x") >= 0)
                lhs -= Integer.parseInt(coeff(x));
            else
                rhs += Integer.parseInt(x);
        }
        if (lhs == 0) {
            if (rhs == 0)
                return "Infinite solutions";
            else
                return "No solution";
        }
        return "x=" + rhs / lhs;
    }
    public List < String > breakIt(String s) {
        List < String > res = new ArrayList < > ();
        String r = "";
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '+' || s.charAt(i) == '-') {
                if (r.length() > 0)
                    res.add(r);
                r = "" + s.charAt(i);
            } else
                r += s.charAt(i);
        }
        res.add(r);
        return res;
    }
}
```

</details>

<br>

## Approach #2 Using regex for spliting [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {
    public String coeff(String x) {
        if (x.length() > 1 && x.charAt(x.length() - 2) >= '0' && x.charAt(x.length() - 2) <= '9')
            return x.replace("x", "");
        return x.replace("x", "1");
    }
    public String solveEquation(String equation) {
        String[] lr = equation.split("=");
        int lhs = 0, rhs = 0;
        for (String x: lr[0].split("(?=\\+)|(?=-)")) {
            if (x.indexOf("x") >= 0) {

                lhs += Integer.parseInt(coeff(x));
            } else
                rhs -= Integer.parseInt(x);
        }
        for (String x: lr[1].split("(?=\\+)|(?=-)")) {
            if (x.indexOf("x") >= 0)
                lhs -= Integer.parseInt(coeff(x));
            else
                rhs += Integer.parseInt(x);
        }
        if (lhs == 0) {
            if (rhs == 0)
                return "Infinite solutions";
            else
                return "No solution";
        } else
            return "x=" + rhs / lhs;
    }
}
```

</details>
