# 2126. Destroying Asteroids

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/destroying-asteroids/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 2126 - Destroying Asteroids](https://leetcode.com/problems/destroying-asteroids/)

## Problem

You are given an integer mass, which represents the original mass of a planet. You are further given an integer array asteroids, where asteroids[i] is the mass of the ith asteroid.

You can arrange for the planet to collide with the asteroids in any arbitrary order. If the mass of the planet is greater than or equal to the mass of the asteroid, the asteroid is destroyed and the planet gains the mass of the asteroid. Otherwise, the planet is destroyed.

Return true if all asteroids can be destroyed. Otherwise, return false.

### Example 1

```text
Input: mass = 10, asteroids = [3,9,19,5,21]
Output: true
Explanation: One way to order the asteroids is [9,19,5,3,21]:
- The planet collides with the asteroid with a mass of 9. New planet mass: 10 + 9 = 19
- The planet collides with the asteroid with a mass of 19. New planet mass: 19 + 19 = 38
- The planet collides with the asteroid with a mass of 5. New planet mass: 38 + 5 = 43
- The planet collides with the asteroid with a mass of 3. New planet mass: 43 + 3 = 46
- The planet collides with the asteroid with a mass of 21. New planet mass: 46 + 21 = 67
All asteroids are destroyed.
```

### Example 2

```text
Input: mass = 5, asteroids = [4,9,23,4]
Output: false
Explanation:
The planet cannot ever gain enough mass to destroy the asteroid with a mass of 23.
After the planet destroys the other asteroids, it will have a mass of 5 + 4 + 9 + 4 = 22.
This is less than 23, so a collision would not destroy the last asteroid.
```

## Constraints

- 1 <= mass <= 105
- 1 <= asteroids.length <= 105
- 1 <= asteroids[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Asteroid Collision](https://leetcode.com/problems/asteroid-collision/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2126. Destroying Asteroids

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Comparison function for sorting
int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize) {
    qsort(asteroids, asteroidsSize, sizeof(int),
          cmp);                    // Sort by mass in ascending order
    long long currentMass = mass;  // Preventing integer overflow
    for (int i = 0; i < asteroidsSize; i++) {
        // Traverse the asteroids in order, attempt to destroy and update mass
        // or return the result
        if (currentMass < asteroids[i]) {
            return false;
        }
        currentMass += asteroids[i];
    }
    return true;  // Successfully destroy all asteroids
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),
             asteroids.end());  // Sort by mass in ascending order
        long long mass1 = mass;
        for (const int asteroid : asteroids) {
            // Traverse the asteroids in order, attempt to destroy and update
            // mass or return the result
            if (mass1 < asteroid) {
                return false;
            }
            mass1 += asteroid;
        }
        return true;  // Successfully destroy all asteroids
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool AsteroidsDestroyed(int mass, int[] asteroids) {
        Array.Sort(asteroids);    // Sort by mass in ascending order
        long currentMass = mass;  // Preventing integer overflow
        foreach (int asteroid in asteroids) {
            // Traverse the asteroids in order, attempt to destroy and update
            // mass or return the result
            if (currentMass < asteroid) {
                return false;
            }
            currentMass += asteroid;
        }
        return true;  // Successfully destroy all asteroids
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func asteroidsDestroyed(mass int, asteroids []int) bool {
	sort.Ints(asteroids)       // Sort by mass in ascending order
	currentMass := int64(mass) // Preventing integer overflow
	for _, asteroid := range asteroids {
		// Traverse the asteroids in order, attempt to destroy and update mass
		// or return the result
		if currentMass < int64(asteroid) {
			return false
		}
		currentMass += int64(asteroid)
	}
	return true // Successfully destroy all asteroids
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids); // Sort by mass in ascending order
        long currentMass = mass; // Preventing integer overflow
        for (int asteroid : asteroids) {
            // Traverse the asteroids in order, attempt to destroy and update mass or return the result
            if (currentMass < asteroid) {
                return false;
            }
            currentMass += asteroid;
        }
        return true; // Successfully destroy all asteroids
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var asteroidsDestroyed = function (mass, asteroids) {
    asteroids.sort((a, b) => a - b); // Sort by mass in ascending order
    let currentMass = mass; // JavaScript numbers can safely handle large integers
    for (const asteroid of asteroids) {
        // Traverse the asteroids in order, attempt to destroy and update mass or return the result
        if (currentMass < asteroid) {
            return false;
        }
        currentMass += asteroid;
    }
    return true; // Successfully destroy all asteroids
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()  # Sort by mass in ascending order
        for asteroid in asteroids:
            # Traverse the asteroids in order, attempt to destroy and update mass or return the result
            if mass < asteroid:
                return False
            mass += asteroid
        return True  # Successfully destroy all asteroids
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function asteroidsDestroyed(mass: number, asteroids: number[]): boolean {
    asteroids.sort((a, b) => a - b); // Sort by mass in ascending order
    let currentMass: number = mass; // TypeScript numbers can safely handle large integers
    for (const asteroid of asteroids) {
        // Traverse the asteroids in order, attempt to destroy and update mass or return the result
        if (currentMass < asteroid) {
            return false;
        }
        currentMass += asteroid;
    }
    return true; // Successfully destroy all asteroids
}
```

</details>
