# 661. Image Smoother

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/image-smoother/)  
`Array` `Matrix`

**Problem Link:** [LeetCode 661 - Image Smoother](https://leetcode.com/problems/image-smoother/)

## Problem

An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).

Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.

### Example 1

```text
Input: img = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[0,0,0],[0,0,0],[0,0,0]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
```

### Example 2

```text
Input: img = [[100,200,100],[200,50,200],[100,200,100]]
Output: [[137,141,137],[141,138,141],[137,141,137]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
For the points (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
For the point (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138
```

## Constraints

- m == img.length
- n == img[i].length
- 1 <= m, n <= 200
- 0 <= img[i][j] <= 255

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 661. Image Smoother

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Create a New Smoothened Image | C++, C#, Java, JavaScript, Python3 |
| Space-Optimized Smoothened Image | C++, C#, Java, JavaScript, Python3 |
| Constant Space Smoothened Image | C++, C#, Java, JavaScript, Python3 |
| Bit Manipulation | C++, C#, Java, JavaScript, Python3 |

## Approach 1: Create a New Smoothened Image

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Save the dimensions of the image.
        int m = img.size();
        int n = img[0].size();

        // Create a new image of the same dimension as the input image.
        vector<vector<int>> smoothImg(m, vector<int>(n));

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        // If the indices form valid neighbor
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }

                // Store the rounded down value in smoothImg[i][j].
                smoothImg[i][j] = sum / count;
            }
        }

        // Return the smooth image.
        return smoothImg;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[][] ImageSmoother(int[][] img) {
        // Save the dimensions of the image.
        int m = img.Length;
        int n = img[0].Length;

        // Create a new image of the same dimension as the input image.
        int[][] smoothImg = new int[m][];
        for (int i = 0; i < m; i++) {
            smoothImg[i] = new int[n];
        }

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        // If the indices form valid neighbor
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }

                // Store the rounded down value in smoothImg[i][j].
                smoothImg[i][j] = sum / count;
            }
        }

        // Return the smooth image.
        return smoothImg;
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] imageSmoother(int[][] img) {
        // Save the dimensions of the image.
        int m = img.length;
        int n = img[0].length;

        // Create a new image of the same dimension as the input image.
        int[][] smoothImg = new int[m][n];

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        // If the indices form valid neighbor
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }

                // Store the rounded down value in smoothImg[i][j].
                smoothImg[i][j] = sum / count;
            }
        }

        // Return the smooth image.
        return smoothImg;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {number[][]} img
 * @return {number[][]}
 */
var imageSmoother = function(img) {
    // Save the dimensions of the image.
    const m = img.length;
    const n = img[0].length;

    // Create a new image of the same dimension as the input image.
    const smoothImg = new Array(m).fill(0).map(() => new Array(n).fill(0));

    // Iterate over the cells of the image.
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            // Initialize the sum and count
            let sum = 0;
            let count = 0;

            // Iterate over all plausible nine indices.
            for (let x = i - 1; x <= i + 1; x++) {
                for (let y = j - 1; y <= j + 1; y++) {
                    // If the indices form valid neighbor
                    if (0 <= x && x < m && 0 <= y && y < n) {
                        sum += img[x][y];
                        count += 1;
                    }
                }
            }

            // Store the rounded down value in smoothImg[i][j].
            smoothImg[i][j] = Math.floor(sum / count);
        }
    }

    // Return the smooth image.
    return smoothImg;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        # Save the dimensions of the image.
        m = len(img)
        n = len(img[0])

        # Create a new image of the same dimension as the input image.
        smooth_img = [[0] * n for _ in range(m)]

        # Iterate over the cells of the image.
        for i in range(m):
            for j in range(n):
                # Initialize the sum and count
                sum = 0
                count = 0

                # Iterate over all plausible nine indices.
                for x in (i - 1, i, i + 1):
                    for y in (j - 1, j, j + 1):
                        # If the indices form valid neighbor
                        if 0 <= x < m and 0 <= y < n:
                            sum += img[x][y]
                            count += 1

                # Store the rounded down value in smooth_img[i][j].
                smooth_img[i][j] = sum // count

        # Return the smooth image.
        return smooth_img
```

</details>

<br>

## Approach 2: Space-Optimized Smoothened Image

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Save the dimensions of the image.
        int m = img.size();
        int n = img[0].size();

        // Create temp array of size n.
        vector<int> temp(n);
        int prevVal = 0;

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count
                int sum = 0;
                int count = 0;

                // Bottom neighbors
                if (i + 1 < m) {
                    if (j - 1 >= 0) {
                        sum += img[i + 1][j - 1];
                        count += 1;
                    }
                    sum += img[i + 1][j];
                    count += 1;
                    if (j + 1 < n) {
                        sum += img[i + 1][j + 1];
                        count += 1;
                    }
                }

                // Next neighbor
                if (j + 1 < n) {
                    sum += img[i][j + 1];
                    count += 1;
                }

                // This cell
                sum += img[i][j];
                count += 1;

                // Previous neighbor
                if (j - 1 >= 0) {
                    sum += temp[j - 1];
                    count += 1;
                }

                // Top neighbors
                if (i - 1 >= 0) {
                    // Left-top corner-sharing neighbor.
                    if (j - 1 >=  0) {
                        sum += prevVal;
                        count += 1;
                    }

                    // Top edge-sharing neighbor.
                    sum += temp[j];
                    count += 1;

                    // Right-top corner-sharing neighbor.
                    if (j + 1 < n) {
                        sum += temp[j + 1];
                        count += 1;
                    }
                }

                // Store the original value of temp[j], which represents
                // original value of img[i - 1][j].
                if (i - 1 >= 0) {
                    prevVal = temp[j];
                }

                // Save current value of img[i][j] in temp[j].
                temp[j] = img[i][j];

                // Overwrite with smoothed value.
                img[i][j] = sum / count;
            }
        }

        // Return the smooth image.
        return img;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[][] ImageSmoother(int[][] img) {
        // Save the dimensions of the image.
        int m = img.Length;
        int n = img[0].Length;

        // Create temp array of size n.
        int[] temp = new int[n];
        int prevVal = 0;

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count
                int sum = 0;
                int count = 0;

                // Bottom neighbors
                if (i + 1 < m) {
                    if (j - 1 >= 0) {
                        sum += img[i + 1][j - 1];
                        count += 1;
                    }
                    sum += img[i + 1][j];
                    count += 1;
                    if (j + 1 < n) {
                        sum += img[i + 1][j + 1];
                        count += 1;
                    }
                }

                // Next neighbor
                if (j + 1 < n) {
                    sum += img[i][j + 1];
                    count += 1;
                }

                // This cell
                sum += img[i][j];
                count += 1;

                // Previous neighbor
                if (j - 1 >= 0) {
                    sum += temp[j - 1];
                    count += 1;
                }

                // Top neighbors
                if (i - 1 >= 0) {
                    // Left-top corner-sharing neighbor.
                    if (j - 1 >=  0) {
                        sum += prevVal;
                        count += 1;
                    }

                    // Top edge-sharing neighbor.
                    sum += temp[j];
                    count += 1;

                    // Right-top corner-sharing neighbor.
                    if (j + 1 < n) {
                        sum += temp[j + 1];
                        count += 1;
                    }
                }

                // Store the original value of temp[j], which represents
                // original value of img[i - 1][j].
                if (i - 1 >= 0) {
                    prevVal = temp[j];
                }

                // Save current value of img[i][j] in temp[j].
                temp[j] = img[i][j];

                // Overwrite with smoothed value.
                img[i][j] = sum / count;
            }
        }

        // Return the smooth image.
        return img;
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] imageSmoother(int[][] img) {
        // Save the dimensions of the image.
        int m = img.length;
        int n = img[0].length;

        // Create temp array of size n.
        int[] temp = new int[n];
        int prevVal = 0;

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count
                int sum = 0;
                int count = 0;

                // Bottom neighbors
                if (i + 1 < m) {
                    if (j - 1 >= 0) {
                        sum += img[i + 1][j - 1];
                        count += 1;
                    }
                    sum += img[i + 1][j];
                    count += 1;
                    if (j + 1 < n) {
                        sum += img[i + 1][j + 1];
                        count += 1;
                    }
                }

                // Next neighbor
                if (j + 1 < n) {
                    sum += img[i][j + 1];
                    count += 1;
                }

                // This cell
                sum += img[i][j];
                count += 1;

                // Previous neighbor
                if (j - 1 >= 0) {
                    sum += temp[j - 1];
                    count += 1;
                }

                // Top neighbors
                if (i - 1 >= 0) {
                    // Left-top corner-sharing neighbor.
                    if (j - 1 >=  0) {
                        sum += prevVal;
                        count += 1;
                    }

                    // Top edge-sharing neighbor.
                    sum += temp[j];
                    count += 1;

                    // Right-top corner-sharing neighbor.
                    if (j + 1 < n) {
                        sum += temp[j + 1];
                        count += 1;
                    }
                }

                // Store the original value of temp[j], which represents
                // original value of img[i - 1][j].
                if (i - 1 >= 0) {
                    prevVal = temp[j];
                }

                // Save current value of img[i][j] in temp[j].
                temp[j] = img[i][j];

                // Overwrite with smoothed value.
                img[i][j] = sum / count;
            }
        }

        // Return the smooth image.
        return img;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {number[][]} img
 * @return {number[][]}
 */
var imageSmoother = function(img) {
    // Save the dimensions of the image.
    const m = img.length;
    const n = img[0].length;

    // Create temp array of size n.
    const temp = new Array(n);
    let prevVal = 0;

    // Iterate over the cells of the image.
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            // Initialize the sum and count
            let sum = 0;
            let count = 0;

            // Bottom neighbors
            if (i + 1 < m) {
                if (j - 1 >= 0) {
                    sum += img[i + 1][j - 1];
                    count += 1;
                }
                sum += img[i + 1][j];
                count += 1;
                if (j + 1 < n) {
                    sum += img[i + 1][j + 1];
                    count += 1;
                }
            }

            // Next neighbor
            if (j + 1 < n) {
                sum += img[i][j + 1];
                count += 1;
            }

            // This cell
            sum += img[i][j];
            count += 1;

            // Previous neighbor
            if (j - 1 >= 0) {
                sum += temp[j - 1];
                count += 1;
            }

            // Top neighbors
            if (i - 1 >= 0) {
                // Left-top corner-sharing neighbor.
                if (j - 1 >=  0) {
                    sum += prevVal;
                    count += 1;
                }

                // Top edge-sharing neighbor.
                sum += temp[j];
                count += 1;

                // Right-top corner-sharing neighbor.
                if (j + 1 < n) {
                    sum += temp[j + 1];
                    count += 1;
                }
            }

            // Store the original value of temp[j], which represents
            // original value of img[i - 1][j].
            if (i - 1 >= 0) {
                prevVal = temp[j];
            }

            // Save current value of img[i][j] in temp[j].
            temp[j] = img[i][j];

            // Overwrite with smoothed value.
            img[i][j] = Math.floor(sum / count);
        }
    }

    // Return the smooth image.
    return img;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        # Save the dimensions of the image.
        m = len(img)
        n = len(img[0])

        # Create a temp array of size n.
        temp = [0] * n

        prev_val = 0

        # Iterate over the cells of the image.
        for i in range(m):
            for j in range(n):
                # Initialize the sum and count
                sum = 0
                count = 0

                # Bottom neighbors
                if i + 1 < m:
                    if j - 1 >= 0:
                        sum += img[i + 1][j - 1]
                        count += 1
                    sum += img[i + 1][j]
                    count += 1
                    if j + 1 < n:
                        sum += img[i + 1][j + 1]
                        count += 1

                # Next neighbor
                if j + 1 < n:
                    sum += img[i][j + 1]
                    count += 1

                # This cell
                sum += img[i][j]
                count += 1

                # Previous neighbor
                if j - 1 >= 0:
                    sum += temp[j - 1]
                    count += 1

                # Top neighbors
                if i - 1 >= 0:
                    # Left-top corner-sharing neighbor.
                    if j - 1 >=  0:
                        sum += prev_val
                        count += 1

                    # Top edge-sharing neighbor.
                    sum += temp[j]
                    count += 1

                    # Right-top corner-sharing neighbor.
                    if j + 1 < n:
                        sum += temp[j + 1]
                        count += 1

                # Store the original value of temp[j], which represents
                # original value of img[i - 1][j].
                if i - 1 >= 0:
                    prev_val = temp[j]

                # Save current value of img[i][j] in temp[j].
                temp[j] = img[i][j]

                # Overwrite with smoothed value.
                img[i][j] = sum // count

        # Return the smooth image.
        return img
```

</details>

<br>

## Approach 3: Constant Space Smoothened Image

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Save the dimensions of the image.
        int m = img.size();
        int n = img[0].size();

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        // If the indices form valid neighbor
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            // Extract the original value of img[x][y].
                            sum += img[x][y] % 256;
                            count += 1;
                        }
                    }
                }

                // Encode the smoothed value in img[i][j].
                img[i][j] += (sum / count) * 256;
            }
        }

        // Extract the smoothed value from encoded img[i][j].
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                img[i][j] /= 256;
            }
        }

        // Return the smooth image.
        return img;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[][] ImageSmoother(int[][] img) {
        // Save the dimensions of the image.
        int m = img.Length;
        int n = img[0].Length;

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        // If the indices form valid neighbor
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            // Extract the original value of img[x][y].
                            sum += img[x][y] % 256;
                            count += 1;
                        }
                    }
                }

                // Encode the smoothed value in img[i][j].
                img[i][j] += (sum / count) * 256;
            }
        }

        // Extract the smoothed value from encoded img[i][j].
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                img[i][j] /= 256;
            }
        }

        // Return the smooth image.
        return img;
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] imageSmoother(int[][] img) {
        // Save the dimensions of the image.
        int m = img.length;
        int n = img[0].length;

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        // If the indices form valid neighbor
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            // Extract the original value of img[x][y].
                            sum += img[x][y] % 256;
                            count += 1;
                        }
                    }
                }

                // Encode the smoothed value in img[i][j].
                img[i][j] += (sum / count) * 256;
            }
        }

        // Extract the smoothed value from encoded img[i][j].
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                img[i][j] /= 256;
            }
        }

        // Return the smooth image.
        return img;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {number[][]} img
 * @return {number[][]}
 */
var imageSmoother = function(img) {
    // Save the dimensions of the image.
    const m = img.length;
    const n = img[0].length;

    // Iterate over the cells of the image.
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            // Initialize the sum and count
            let sum = 0;
            let count = 0;

            // Iterate over all plausible nine indices.
            for (let x = i - 1; x <= i + 1; x++) {
                for (let y = j - 1; y <= j + 1; y++) {
                    // If the indices form valid neighbor
                    if (0 <= x && x < m && 0 <= y && y < n) {
                        // Extract the original value of img[x][y].
                        sum += img[x][y] % 256;
                        count += 1;
                    }
                }
            }

            // Encode the smoothed value in img[i][j].
            img[i][j] += Math.floor(sum / count) * 256;
        }
    }

    // Extract the smoothed value from encoded img[i][j].
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            img[i][j] = Math.floor(img[i][j] / 256);
        }
    }

    // Return the smooth image.
    return img;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        # Save the dimensions of the image.
        m = len(img)
        n = len(img[0])

        # Iterate over the cells of the image.
        for i in range(m):
            for j in range(n):
                # Initialize the sum and count
                sum = 0
                count = 0

                # Iterate over all plausible nine indices.
                for x in (i - 1, i, i + 1):
                    for y in (j - 1, j, j + 1):
                        # If the indices form valid neighbor
                        if 0 <= x < m and 0 <= y < n:
                            # Extract the original value of img[x][y].
                            sum += img[x][y] % 256
                            count += 1

                # Encode the smoothed value in img[i][j].
                img[i][j] += (sum // count) * 256

        # Extract the smoothed value from encoded img[i][j].
        for i in range(m):
            for j in range(n):
                img[i][j] //= 256

        # Return the smooth image.
        return img
```

</details>

<br>

## Approach 4: Bit Manipulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Save the dimensions of the image.
        int m = img.size();
        int n = img[0].size();

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        // If the indices form valid neighbor
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            // Extract the original value of img[x][y].
                            sum += img[x][y] & 255;
                            count += 1;
                        }
                    }
                }

                // Encode the smoothed value in img[i][j].
                img[i][j] |= (sum / count) << 8;
            }
        }

        // Extract the smoothed value from encoded img[i][j].
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                img[i][j] >>= 8;
            }
        }

        // Return the smooth image.
        return img;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[][] ImageSmoother(int[][] img) {
        // Save the dimensions of the image.
        int m = img.Length;
        int n = img[0].Length;

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        // If the indices form valid neighbor
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            // Extract the original value of img[x][y].
                            sum += img[x][y] & 255;
                            count += 1;
                        }
                    }
                }

                // Encode the smoothed value in img[i][j].
                img[i][j] |= (sum / count) << 8;
            }
        }

        // Extract the smoothed value from encoded img[i][j].
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                img[i][j] >>= 8;
            }
        }

        // Return the smooth image.
        return img;
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] imageSmoother(int[][] img) {
        // Save the dimensions of the image.
        int m = img.length;
        int n = img[0].length;

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        // If the indices form valid neighbor
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            // Extract the original value of img[x][y].
                            sum += img[x][y] & 255;
                            count += 1;
                        }
                    }
                }

                // Encode the smoothed value in img[i][j].
                img[i][j] |= (sum / count) << 8;
            }
        }

        // Extract the smoothed value from encoded img[i][j].
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                img[i][j] >>= 8;
            }
        }

        // Return the smooth image.
        return img;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {number[][]} img
 * @return {number[][]}
 */
var imageSmoother = function(img) {
    // Save the dimensions of the image.
    const m = img.length;
    const n = img[0].length;

    // Iterate over the cells of the image.
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            // Initialize the sum and count
            let sum = 0;
            let count = 0;

            // Iterate over all plausible nine indices.
            for (let x = i - 1; x <= i + 1; x++) {
                for (let y = j - 1; y <= j + 1; y++) {
                    // If the indices form valid neighbor
                    if (0 <= x && x < m && 0 <= y && y < n) {
                        // Extract the original value of img[x][y].
                        sum += img[x][y] & 255;
                        count += 1;
                    }
                }
            }

            // Encode the smoothed value in img[i][j].
            img[i][j] |= Math.floor(sum / count) << 8;
        }
    }

    // Extract the smoothed value from encoded img[i][j].
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            img[i][j] >>= 8;
        }
    }

    // Return the smooth image.
    return img;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        # Save the dimensions of the image.
        m = len(img)
        n = len(img[0])

        # Iterate over the cells of the image.
        for i in range(m):
            for j in range(n):
                # Initialize the sum and count
                sum = 0
                count = 0

                # Iterate over all plausible nine indices.
                for x in (i - 1, i, i + 1):
                    for y in (j - 1, j, j + 1):
                        # If the indices form valid neighbor
                        if 0 <= x < m and 0 <= y < n:
                            # Extract the original value of img[x][y].
                            sum += img[x][y] & 255
                            count += 1

                # Encode the smoothed value in img[i][j].
                img[i][j] |= (sum // count) << 8

        # Extract the smoothed value from encoded img[i][j].
        for i in range(m):
            for j in range(n):
                img[i][j] >>= 8

        # Return the smooth image.
        return img
```

</details>
