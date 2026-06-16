# 1700. Number of Students Unable to Eat Lunch

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/)  
`Array` `Stack` `Queue` `Simulation`

**Problem Link:** [LeetCode 1700 - Number of Students Unable to Eat Lunch](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/)

## Problem

The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

- If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
- Otherwise, they will leave it and go to the queue's end.

This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.

### Example 1

```text
Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
Output: 0
Explanation:
- Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
- Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
- Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
- Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
- Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
Hence all students are able to eat.
```

### Example 2

```text
Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
Output: 3
```

## Constraints

- 1 <= students.length, sandwiches.length <= 100
- students.length == sandwiches.length
- sandwiches[i] is 0 or 1.
- students[i] is 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Time Needed to Buy Tickets](https://leetcode.com/problems/time-needed-to-buy-tickets/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1700. Number of Students Unable to Eat Lunch

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation Using Queue and Stack | C++, Java, Python3 |
| Counting | C++, Java, Python3 |

## Approach 1: Simulation Using Queue and Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int len = students.size(); // Sandwiches will be the same length
        queue<int> studentQueue;
        stack<int> sandwichStack;

        // Add students and sandwiches to the queue and stack
        for (int i = 0; i < len; i++) {
            sandwichStack.push(sandwiches[len - i - 1]);
            studentQueue.push(students[i]);
        }

        // Simulate the lunch process by serving sandwiches
        // or sending students to the back of the queue.
        int lastServed = 0;
        while (!studentQueue.empty() && lastServed < studentQueue.size()) {
            if (sandwichStack.top() == studentQueue.front()) {
                sandwichStack.pop(); // Serve sandwich
                studentQueue.pop(); // Student leaves queue
                lastServed = 0;
            } else {
                // Student moves to back of queue
                studentQueue.push(studentQueue.front());
                studentQueue.pop(); // Remove from front
                lastServed++;
            }
        }

        // Remaining students in queue are unserved students
        return studentQueue.size();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int len = students.length; // Sandwiches will be the same length
        Queue<Integer> studentQueue = new LinkedList<>();
        Stack<Integer> sandwichStack = new Stack<>();
        
        // Add students and sandwiches to the queue and stack
        for (int i = 0; i < len; i++) {
            sandwichStack.push(sandwiches[len - i - 1]);
            studentQueue.offer(students[i]);
        }

        // Simulate the lunch process by serving sandwiches 
        // or sending students to the back of the queue.
        int lastServed = 0;
        while (studentQueue.size() > 0 && lastServed < studentQueue.size()) {
            if (sandwichStack.peek() == studentQueue.peek()) {
                sandwichStack.pop(); // Serve sandwich
                studentQueue.poll(); // Student leaves queue
                lastServed = 0;
            } else {
                // Student moves to back of queue
                studentQueue.offer(studentQueue.poll()); 
                lastServed++;
            }
        }

        // Remaining students in queue are unserved students
        return studentQueue.size();    
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        length = len(students) # Sandwiches will be the same length
        student_queue = deque()
        sandwich_stack = []

        # Add students and sandwiches to the queue and stack
        for i in range(length):
            sandwich_stack.append(sandwiches[length - i - 1])
            student_queue.append(students[i])

        # Simulate the lunch process by serving sandwiches
        # or sending students to the back of the queue.
        last_served = 0
        while len(student_queue) > 0 and last_served < len(student_queue):
            if sandwich_stack[-1] == student_queue[0]:
                sandwich_stack.pop()  # Serve sandwich
                student_queue.popleft()  # Student leaves queue
                last_served = 0
            else:
                # Student moves to back of queue
                student_queue.append(student_queue.popleft())  
                last_served += 1

        # Remaining students in queue are unserved students
        return len(student_queue)
```

</details>

<br>

## Approach 2: Counting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circleStudentCount = 0;
        int squareStudentCount = 0;

        // Count the number of students who want each type of sandwich
        for (int student : students) {
            if (student == 0) {
                circleStudentCount++;
            } else {
                squareStudentCount++;
            }
        }

        // Serve sandwiches to students
        for (int sandwich : sandwiches) {
            // No student wants the circle sandwich on top of the stack
            if (sandwich == 0 && circleStudentCount == 0) {
                return squareStudentCount;
            } 
            // No student wants the square sandwich on top of the stack
            if (sandwich == 1 && squareStudentCount == 0) {
                return circleStudentCount;
            }
            // Decrement the count of the served sandwich type
            if (sandwich == 0) {
                circleStudentCount--;
            } else {
                squareStudentCount--;
            }
        }
        // Every student received a sandwich
        return 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int circleStudentCount = 0;
        int squareStudentCount = 0;

        // Count the number of students who want each type of sandwich
        for (int student : students) {
            if (student == 0) {
                circleStudentCount++;
            } else {
                squareStudentCount++;
            }
        }

        // Serve sandwiches to students
        for (int sandwich : sandwiches) {
            // No student wants the circle sandwich on top of the stack
            if (sandwich == 0 && circleStudentCount == 0) {
                return squareStudentCount;
            }
            // No student wants the square sandwich on top of the stack
            if (sandwich == 1 && squareStudentCount == 0) {
                return circleStudentCount;
            }
            // Decrement the count of the served sandwich type
            if (sandwich == 0) {
                circleStudentCount--;
            } else {
                squareStudentCount--;
            }
        }
        // Every student received a sandwich
        return 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        circle_student_count = 0
        square_student_count = 0

        # Count the number of students who want each type of sandwich
        for student in students:
            if student == 0:
                circle_student_count += 1
            else:
                square_student_count += 1

        # Serve sandwiches to students
        for sandwich in sandwiches:

            # No student wants the circle sandwich on top of the stack
            if sandwich == 0 and circle_student_count == 0:
                return square_student_count

            # No student wants the square sandwich on top of the stack
            if sandwich == 1 and square_student_count == 0:
                return circle_student_count

            # Decrement the count of the served sandwich type
            if sandwich == 0:
                circle_student_count -= 1
            else:
                square_student_count -= 1

        # Every student received a sandwich
        return 0
```

</details>
