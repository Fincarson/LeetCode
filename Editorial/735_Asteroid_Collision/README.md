# 735. Asteroid Collision

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/asteroid-collision/)  
`Array` `Stack` `Simulation`

**Problem Link:** [LeetCode 735 - Asteroid Collision](https://leetcode.com/problems/asteroid-collision/)

## Problem

We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

### Example 1

```text
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
```

### Example 2

```text
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
```

### Example 3

```text
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
```

### Example 4

```text
Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
Output: [-6,2,4]
Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 makes the asteroid -1 explode and then continues going right, without reaching asteroid 4.
```

## Constraints

- 2 <= asteroids.length <= 104
- -1000 <= asteroids[i] <= 1000
- asteroids[i] != 0

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Can Place Flowers](https://leetcode.com/problems/can-place-flowers/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Destroying Asteroids](https://leetcode.com/problems/destroying-asteroids/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Collisions on a Road](https://leetcode.com/problems/count-collisions-on-a-road/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Robot Collisions](https://leetcode.com/problems/robot-collisions/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 735. Asteroid Collision

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Stack | C++, Java |

## Approach: Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int asteroid : asteroids) {
            int flag = 1;
            while (!st.empty() && (st.top() > 0 && asteroid < 0)) {
                // If the top asteroid in the stack is smaller, then it will explode.
                // Hence pop it from the stack, also continue with the next asteroid in the stack.
                if (abs(st.top()) < abs(asteroid)) {
                    st.pop();
                    continue;
                }
                // If both asteroids are the same size, then both asteroids will explode.
                // Pop the asteroid from the stack; also, we won't push the current asteroid to the stack.
                else if (abs(st.top()) == abs(asteroid)) {
                    st.pop();
                }

                // If we reach here, the current asteroid will be destroyed
                // Hence, we should not add it to the stack
                flag = 0;
                break;
            }
            
            if (flag) {
                st.push(asteroid);
            }
        }
        
        // Add the asteroids from the stack to the vector in the reverse order.
        vector<int> remainingAsteroids (st.size());
        for (int i = remainingAsteroids.size() - 1; i >= 0; i--){
            remainingAsteroids[i] = st.top();
            st.pop();
        }
        
        return remainingAsteroids;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st = new Stack<Integer>();

        for (int asteroid : asteroids) {
            boolean flag = true;
            while (!st.isEmpty() && (st.peek() > 0 && asteroid < 0)) {
                // If the top asteroid in the stack is smaller, then it will explode.
                // Hence pop it from the stack, also continue with the next asteroid in the stack.
                if (Math.abs(st.peek()) < Math.abs(asteroid)) {
                    st.pop();
                    continue;
                }
                // If both asteroids have the same size, then both asteroids will explode.
                // Pop the asteroid from the stack; also, we won't push the current asteroid to the stack.
                else if (Math.abs(st.peek()) == Math.abs(asteroid)) {
                    st.pop();
                }

                // If we reach here, the current asteroid will be destroyed
                // Hence, we should not add it to the stack
                flag = false;
                break;
            }

            if (flag) {
                st.push(asteroid);
            }
        }

        // Add the asteroids from the stack to the vector in the reverse order.
        int[] remainingAsteroids = new int[st.size()];
        for (int i = remainingAsteroids.length - 1; i >= 0; i--) {
            remainingAsteroids[i] = st.peek();
            st.pop();
        }

        return remainingAsteroids;
    }
}
```

</details>
