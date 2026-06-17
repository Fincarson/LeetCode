# 223. Rectangle Area

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/rectangle-area/)  
`Math` `Geometry`

**Problem Link:** [LeetCode 223 - Rectangle Area](https://leetcode.com/problems/rectangle-area/)

## Problem

Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.

The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).

The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).

### Example 1

```text
Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
Output: 45
```

### Example 2

```text
Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
Output: 16
```

## Constraints

- -104 <= ax1 <= ax2 <= 104
- -104 <= ay1 <= ay2 <= 104
- -104 <= bx1 <= bx2 <= 104
- -104 <= by1 <= by2 <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rectangle Overlap](https://leetcode.com/problems/rectangle-overlap/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find the Number of Ways to Place People II](https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Find the Number of Ways to Place People I](https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the Largest Area of Square Inside Two Rectangles](https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 223. Rectangle Area

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Math and Geometry | Java, JavaScript, Python3, TypeScript |

## Approach: Math and Geometry

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaOfA = (ay2 - ay1) * (ax2 - ax1);
        int areaOfB = (by2 - by1) * (bx2 - bx1);

        // calculate x overlap
        int left = Math.max(ax1, bx1);
        int right = Math.min(ax2, bx2);
        int xOverlap = right - left;

        // calculate y overlap
        int top = Math.min(ay2, by2);
        int bottom = Math.max(ay1, by1);
        int yOverlap = top - bottom;

        int areaOfOverlap = 0;
        // if the rectangles overlap each other, then calculate
        // the area of the overlap
        if (xOverlap > 0 && yOverlap > 0) {
            areaOfOverlap = xOverlap * yOverlap;
        }

        // areaOfOverlap is counted twice when in the summation of
        // areaOfA and areaOfB, so we need to subtract it from the
        // total, to get the toal area covered by both the rectangles
        int totalArea = areaOfA + areaOfB - areaOfOverlap;

        return totalArea;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) {
    const areaOfA = (ay2 - ay1) * (ax2 - ax1);
    const areaOfB = (by2 - by1) * (bx2 - bx1);

    // calculate x overlap
    const left = Math.max(ax1, bx1);
    const right = Math.min(ax2, bx2);
    const xOverlap = right - left;

    // calculate y overlap
    const top = Math.min(ay2, by2);
    const bottom = Math.max(ay1, by1);
    const yOverlap = top - bottom;

    let areaOfOverlap = 0;
    // if the rectangles overlap each other, then calculate
    // the area of the overlap
    if (xOverlap > 0 && yOverlap > 0) {
        areaOfOverlap = xOverlap * yOverlap;
    }

    // areaOfOverlap is counted twice when in the summation of
    // areaOfA and areaOfB, so we need to subtract it from the
    // total, to get the toal area covered by both the rectangles
    const totalArea = areaOfA + areaOfB - areaOfOverlap;

    return totalArea;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def computeArea(self,
                    ax1: int, ay1: int,
                    ax2: int, ay2: int,
                    bx1: int, by1: int,
                    bx2: int, by2: int) -> int:
        area_of_a = (ay2 - ay1) * (ax2 - ax1)
        area_of_b = (by2 - by1) * (bx2 - bx1)

        # calculate x overlap
        left = max(ax1, bx1)
        right = min(ax2, bx2)
        x_overlap = right - left

        # calculate y overlap
        top = min(ay2, by2)
        bottom = max(ay1, by1)
        y_overlap = top - bottom

        area_of_overlap = 0
        # if the rectangles overlap each other, then calculate
        # the area of the overlap
        if x_overlap > 0 and y_overlap > 0:
            area_of_overlap = x_overlap * y_overlap

        # area_of_overlap is counted twice when in the summation of
        # area_of_a and area_of_b, so we need to subtract it from the
        # total, to get the toal area covered by both the rectangles
        total_area = area_of_a + area_of_b - area_of_overlap

        return total_area
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function computeArea(
    ax1: number,
    ay1: number,
    ax2: number,
    ay2: number,
    bx1: number,
    by1: number,
    bx2: number,
    by2: number
): number {
    const areaOfA: number = (ay2 - ay1) * (ax2 - ax1);
    const areaOfB: number = (by2 - by1) * (bx2 - bx1);

    // calculate x overlap
    const left: number = Math.max(ax1, bx1);
    const right: number = Math.min(ax2, bx2);
    const xOverlap: number = right - left;

    // calculate y overlap
    const top: number = Math.min(ay2, by2);
    const bottom: number = Math.max(ay1, by1);
    const yOverlap: number = top - bottom;

    let areaOfOverlap: number = 0;
    // if the rectangles overlap each other, then calculate
    // the area of the overlap
    if (xOverlap > 0 && yOverlap > 0) {
        areaOfOverlap = xOverlap * yOverlap;
    }

    // areaOfOverlap is counted twice when in the summation of
    // areaOfA and areaOfB, so we need to subtract it from the
    // total, to get the toal area covered by both the rectangles
    const totalArea: number = areaOfA + areaOfB - areaOfOverlap;
    return totalArea;
}
```

</details>
