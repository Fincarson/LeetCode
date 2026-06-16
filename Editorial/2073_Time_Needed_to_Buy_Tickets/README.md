# 2073. Time Needed to Buy Tickets

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/time-needed-to-buy-tickets/)  
`Array` `Queue` `Simulation`

**Problem Link:** [LeetCode 2073 - Time Needed to Buy Tickets](https://leetcode.com/problems/time-needed-to-buy-tickets/)

## Problem

There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.

### Example 1

### Example 2

## Constraints

- n == tickets.length
- 1 <= n <= 100
- 1 <= tickets[i] <= 100
- 0 <= k < n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Students Unable to Eat Lunch](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2073. Time Needed to Buy Tickets

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation Using Queue | C++, Java, Python3 |
| Simulation Without Queue | C++, Java, Python3 |
| Using One Pass | C++, Java, Python3 |

## Approach 1: Simulation Using Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> queue;

        // Initialize the queue with ticket indices
        for (int i = 0; i < tickets.size(); i++) {
            queue.push(i);
        }

        int time = 0;

        // Loop until the queue is empty
        while (!queue.empty()) {
            // Increment the time counter for each iteration
            time++;

            // Get the front element of the queue
            int front = queue.front();
            queue.pop();

            // Buy a ticket for the front person
            tickets[front]--;

            // If person k bought all their tickets, return time
            if (k == front && tickets[front] == 0) {
                return time;
            }

           // Re-add the current index to the queue for the next iteration if there are still tickets
            if (tickets[front] != 0) {
                queue.push(front);
            }
        }

        return time;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        Queue<Integer> queue = new LinkedList<>();

        // Initialize the queue with ticket indices
        for (int i = 0; i < tickets.length; i++) {
            queue.add(i);
        }

        int time = 0;

        // Loop until the queue is empty
        while (!queue.isEmpty()) {
            // Increment the time counter for each iteration
            time++;

            // Get the front element of the queue
            int front = queue.poll();

            // Buy a ticket for the front person
            tickets[front]--;

            // If person k bought all their tickets, return time
            if (k == front && tickets[front] == 0) {
                return time;
            }

            // Re-add the current index to the queue for the next iteration
            if (tickets[front] != 0) {
                queue.add(front);
            }    
        }

        return time;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        queue = deque()

        # Initialize the queue with ticket indices
        for i in range(len(tickets)):
            queue.append(i)

        time = 0

        # Loop until the queue is empty
        while queue:
            # Increment the time counter for each iteration
            time += 1

            # Get the front element of the queue
            front = queue.popleft()

            # Buy a ticket for the front person
            tickets[front] -= 1

            # If person k bought all their tickets, return time
            if k == front and tickets[front] == 0:
                return time

            # Re-add the current index to the queue for the next iteration
            if tickets[front] != 0:
                queue.append(front)

        return time
```

</details>

<br>

## Approach 2: Simulation Without Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;

        // If person k only needs one ticket, return the time to buy it
        if (tickets[k] == 1)
            return k + 1;

        // Continue buying tickets until person k buys all their tickets
        while (tickets[k] > 0) {
            for (int i = 0; i < n; i++) {
                // Buy a ticket at index 'i' if available
                if (tickets[i] != 0) {
                    tickets[i]--;
                    time++;
                }

                // If person k bought all their tickets, return the time
                if (tickets[k] == 0)
                    return time;
            }
        }

        return time;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int n = tickets.length;
        int time = 0;

        // If person k only needs one ticket, return the time to buy it
        if (tickets[k] == 1)
            return k + 1;

        // Continue buying tickets until person k buys all their tickets
        while (tickets[k] > 0) {
            for (int i = 0; i < n; i++) {
                // Buy a ticket at index 'i' if available
                if (tickets[i] != 0) {
                    tickets[i]--;
                    time++;
                }
                
                // If person k bought all their rickets, return the time
                if (tickets[k] == 0)
                    return time;
            }
        }
        
        return time;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        n = len(tickets)
        time = 0

        # If person k only needs one ticket, return the time to buy it
        if tickets[k] == 1:
            return k + 1

        # Continue buying tickets until person k buys all their tickets
        while tickets[k] > 0:
            for i in range(n):
                # Buy a ticket at index 'i' if available
                if tickets[i] != 0:
                    tickets[i] -= 1
                    time += 1

                # If person k bought all their tickets, return the time
                if tickets[k] == 0:
                    return time;

        return time
```

</details>

<br>

## Approach 3: Using One Pass

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        
        for (int i = 0; i < tickets.size(); i++) {
            // If the current person is before or at the desired person 'k'
            if (i <= k) {
                // Buy the minimum of tickets available at person 'k' and the current person
                time += min(tickets[k], tickets[i]);
            } else {
                // If the current person is after 'k', buy the minimum of 
                // (tickets available at person 'k' - 1) and the current person
                time += min(tickets[k] - 1, tickets[i]);
            }
        }
        
        return time;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int time = 0;
        
        for (int i = 0; i < tickets.length; i++) {
            // If the current person is before or at the desired person 'k'
            if (i <= k) {
                // Buy the minimum of tickets available at person 'k' and the current person
                time += Math.min(tickets[k], tickets[i]);
            } else {
                // If the current person is after 'k', buy the minimum of 
                // (tickets available at person 'k' - 1) and the current person
                time += Math.min(tickets[k] - 1, tickets[i]);
            }
        }
        
        return time;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        time = 0
        
        for i in range(len(tickets)):
            # If the current person is before or at the desired person 'k'
            if i <= k:
                # Buy the minimum of tickets available at person 'k' and the current person
                time += min(tickets[k], tickets[i])
            else:
                # If the current person is after 'k', buy the minimum of 
                # (tickets available at person 'k' - 1) and the current person
                time += min(tickets[k] - 1, tickets[i])
        
        return time
```

</details>
