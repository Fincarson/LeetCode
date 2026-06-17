# 478. Generate Random Point in a Circle

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/generate-random-point-in-a-circle/)  
`Math` `Geometry` `Rejection Sampling` `Randomized`

**Problem Link:** [LeetCode 478 - Generate Random Point in a Circle](https://leetcode.com/problems/generate-random-point-in-a-circle/)

## Problem

Given the radius and the position of the center of a circle, implement the function randPoint which generates a uniform random point inside the circle.

Implement the Solution class:

- Solution(double radius, double x_center, double y_center) initializes the object with the radius of the circle radius and the position of the center (x_center, y_center).
- randPoint() returns a random point inside the circle. A point on the circumference of the circle is considered to be in the circle. The answer is returned as an array [x, y].

### Example 1

```text
Input
["Solution", "randPoint", "randPoint", "randPoint"]
[[1.0, 0.0, 0.0], [], [], []]
Output
[null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]

Explanation
Solution solution = new Solution(1.0, 0.0, 0.0);
solution.randPoint(); // return [-0.02493, -0.38077]
solution.randPoint(); // return [0.82314, 0.38945]
solution.randPoint(); // return [0.36572, 0.17248]
```

## Constraints

- 0 < radius <= 108
- -107 <= x_center, y_center <= 107
- At most 3 * 104 calls will be made to randPoint.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Random Point in Non-overlapping Rectangles](https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 478. Generate Random Point in a Circle

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Rejection Sampling | C++, Java |
| Inverse Transform Sampling (Math) | C++, Java |

## Approach 1: Rejection Sampling

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double rad, xc, yc;
    //c++11 random floating point number generation
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{0, 1};

    Solution(double radius, double x_center, double y_center) {
        rad = radius, xc = x_center, yc = y_center;
    }

    vector<double> randPoint() {
        double x0 = xc - rad;
        double y0 = yc - rad;

        while(true) {
            double xg = x0 + uni(rng) * 2 * rad;
            double yg = y0 + uni(rng) * 2 * rad;
            if (sqrt(pow((xg - xc), 2) + pow((yg - yc), 2)) <= rad)
                return {xg, yg};
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    double rad, xc, yc;
    public Solution(double radius, double x_center, double y_center) {
        rad = radius;
        xc = x_center;
        yc = y_center;
    }

    public double[] randPoint() {
        double x0 = xc - rad;
        double y0 = yc - rad;

        while(true) {
            double xg = x0 + Math.random() * rad * 2;
            double yg = y0 + Math.random() * rad * 2;
            if (Math.sqrt(Math.pow((xg - xc) , 2) + Math.pow((yg - yc), 2)) <= rad)
                return new double[]{xg, yg};
        }
    }
}
```

</details>

<br>

## Approach 2: Inverse Transform Sampling (Math)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double rad, xc, yc;
    //c++11 random floating point number generation
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{0, 1};

    Solution(double radius, double x_center, double y_center) {
        rad = radius, xc = x_center, yc = y_center;
    }

    vector<double> randPoint() {
        double d = rad * sqrt(uni(rng));
        double theta = uni(rng) * (2 * M_PI);
        return {d * cos(theta) + xc, d * sin(theta) + yc};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    double rad, xc, yc;
    public Solution(double radius, double x_center, double y_center) {
        rad = radius;
        xc = x_center;
        yc = y_center;
    }

    public double[] randPoint() {
        double d = rad * Math.sqrt(Math.random());
        double theta = Math.random() * 2 * Math.PI;
        return new double[]{d * Math.cos(theta) + xc, d * Math.sin(theta) + yc};
    }
}
```

</details>
