# 1792. Maximum Average Pass Ratio

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-average-pass-ratio/)  
`Array` `Greedy` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1792 - Maximum Average Pass Ratio](https://leetcode.com/problems/maximum-average-pass-ratio/)

## Problem

There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

### Example 1

```text
Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
```

### Example 2

```text
Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485
```

## Constraints

- 1 <= classes.length <= 105
- classes[i].length == 2
- 1 <= passi <= totali <= 105
- 1 <= extraStudents <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1792. Maximum Average Pass Ratio

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force (Time Limit Exceeded Error) | C++, Java, Python3 |
| Priority Queue | C++, Java, Python3 |

## Approach 1: Brute Force (Time Limit Exceeded Error)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        vector<double> passRatios;

        // Calculate initial pass ratios
        for (int classIndex = 0; classIndex < classes.size(); classIndex++) {
            double initialRatio =
                classes[classIndex][0] / (double)classes[classIndex][1];
            passRatios.push_back(initialRatio);
        }

        while (extraStudents--) {
            vector<double> updatedRatios;

            // Calculate updated pass ratios if an extra student is added
            for (int classIndex = 0; classIndex < classes.size();
                 classIndex++) {
                double newRatio = (classes[classIndex][0] + 1) /
                                  (double)(classes[classIndex][1] + 1);
                updatedRatios.push_back(newRatio);
            }

            int bestClassIndex = 0;
            double maximumGain = 0;

            // Find the class that gains the most from an extra student
            for (int classIndex = 0; classIndex < updatedRatios.size();
                 classIndex++) {
                double gain =
                    updatedRatios[classIndex] - passRatios[classIndex];
                if (gain > maximumGain) {
                    bestClassIndex = classIndex;
                    maximumGain = gain;
                }
            }

            // Update the selected class
            passRatios[bestClassIndex] = updatedRatios[bestClassIndex];
            classes[bestClassIndex][0]++;
            classes[bestClassIndex][1]++;
        }

        // Calculate the total average pass ratio
        double totalPassRatio = 0;
        for (double passRatio : passRatios) {
            totalPassRatio += passRatio;
        }

        return totalPassRatio / classes.size();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public double maxAverageRatio(int[][] classes, int extraStudents) {
        List<Double> passRatios = new ArrayList<>();

        // Calculate initial pass ratios
        for (int classIndex = 0; classIndex < classes.length; classIndex++) {
            double initialRatio =
                (double) classes[classIndex][0] / classes[classIndex][1];
            passRatios.add(initialRatio);
        }

        while (extraStudents > 0) {
            List<Double> updatedRatios = new ArrayList<>();

            // Calculate updated pass ratios if an extra student is added
            for (
                int classIndex = 0;
                classIndex < classes.length;
                classIndex++
            ) {
                double newRatio =
                    (double) (classes[classIndex][0] + 1) /
                    (classes[classIndex][1] + 1);
                updatedRatios.add(newRatio);
            }

            int bestClassIndex = 0;
            double maximumGain = 0;

            // Find the class that gains the most from an extra student
            for (
                int classIndex = 0;
                classIndex < updatedRatios.size();
                classIndex++
            ) {
                double gain =
                    updatedRatios.get(classIndex) - passRatios.get(classIndex);
                if (gain > maximumGain) {
                    bestClassIndex = classIndex;
                    maximumGain = gain;
                }
            }

            // Update the selected class
            passRatios.set(bestClassIndex, updatedRatios.get(bestClassIndex));
            classes[bestClassIndex][0]++;
            classes[bestClassIndex][1]++;

            extraStudents--;
        }

        // Calculate the total average pass ratio
        double totalPassRatio = 0;
        for (double passRatio : passRatios) {
            totalPassRatio += passRatio;
        }

        return totalPassRatio / classes.length;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxAverageRatio(
        self, classes: List[List[int]], extraStudents: int
    ) -> float:
        pass_ratios = []

        # Calculate initial pass ratios
        for class_ in classes:
            initial_ratio = class_[0] / class_[1]
            pass_ratios.append(initial_ratio)

        while extraStudents > 0:
            updated_ratios = []

            # Calculate updated pass ratios if an extra student is added
            for class_ in classes:
                new_ratio = (class_[0] + 1) / (class_[1] + 1)
                updated_ratios.append(new_ratio)

            best_class_index = 0
            maximum_gain = 0

            # Find the class that gains the most from an extra student
            for i in range(len(updated_ratios)):
                gain = updated_ratios[i] - pass_ratios[i]
                if gain > maximum_gain:
                    best_class_index = i
                    maximum_gain = gain

            # Update the selected class
            pass_ratios[best_class_index] = updated_ratios[best_class_index]
            classes[best_class_index][0] += 1
            classes[best_class_index][1] += 1

            extraStudents -= 1

        # Calculate the total average pass ratio
        total_pass_ratio = sum(pass_ratios)
        return total_pass_ratio / len(classes)
```

</details>

<br>

## Approach 2: Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Lambda to calculate the gain of adding an extra student
        auto calculateGain = [](int passes, int totalStudents) {
            return (double)(passes + 1) / (totalStudents + 1) -
                   (double)passes / totalStudents;
        };

        // Max heap to store (-gain, passes, totalStudents)
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (const auto& singleClass : classes) {
            maxHeap.push({calculateGain(singleClass[0], singleClass[1]),
                          {singleClass[0], singleClass[1]}});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto [currentGain, classInfo] = maxHeap.top();
            maxHeap.pop();
            int passes = classInfo.first;
            int totalStudents = classInfo.second;
            maxHeap.push({calculateGain(passes + 1, totalStudents + 1),
                          {passes + 1, totalStudents + 1}});
        }

        // Calculate the final average pass ratio
        double totalPassRatio = 0;
        while (!maxHeap.empty()) {
            auto [_, classInfo] = maxHeap.top();
            maxHeap.pop();
            totalPassRatio += (double)classInfo.first / classInfo.second;
        }

        return totalPassRatio / classes.size();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public double maxAverageRatio(int[][] classes, int extraStudents) {
        // Lambda to calculate the gain of adding an extra student
        PriorityQueue<double[]> maxHeap = new PriorityQueue<>((a, b) ->
            Double.compare(b[0], a[0])
        );

        for (int[] singleClass : classes) {
            int passes = singleClass[0];
            int totalStudents = singleClass[1];
            double gain = calculateGain(passes, totalStudents);
            maxHeap.offer(new double[] { gain, passes, totalStudents });
        }

        // Distribute extra students
        while (extraStudents-- > 0) {
            double[] current = maxHeap.poll();
            double currentGain = current[0];
            int passes = (int) current[1];
            int totalStudents = (int) current[2];
            maxHeap.offer(
                new double[] {
                    calculateGain(passes + 1, totalStudents + 1),
                    passes + 1,
                    totalStudents + 1,
                }
            );
        }

        // Calculate the final average pass ratio
        double totalPassRatio = 0;
        while (!maxHeap.isEmpty()) {
            double[] current = maxHeap.poll();
            int passes = (int) current[1];
            int totalStudents = (int) current[2];
            totalPassRatio += (double) passes / totalStudents;
        }

        return totalPassRatio / classes.length;
    }

    private double calculateGain(int passes, int totalStudents) {
        return (
            (double) (passes + 1) / (totalStudents + 1) -
            (double) passes / totalStudents
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxAverageRatio(
        self, classes: List[List[int]], extraStudents: int
    ) -> float:
        # Lambda to calculate the gain of adding an extra student
        def _calculate_gain(passes, total_students):
            return (passes + 1) / (total_students + 1) - passes / total_students

        # Max heap to store (-gain, passes, total_students)
        max_heap = []
        for passes, total_students in classes:
            gain = _calculate_gain(passes, total_students)
            max_heap.append((-gain, passes, total_students))

        # Use heapify to transform the list into a valid heap in O(n)
        heapq.heapify(max_heap)

        # Distribute extra students
        for _ in range(extraStudents):
            current_gain, passes, total_students = heapq.heappop(max_heap)
            heapq.heappush(
                max_heap,
                (
                    -_calculate_gain(passes + 1, total_students + 1),
                    passes + 1,
                    total_students + 1,
                ),
            )

        # Calculate the final average pass ratio
        total_pass_ratio = sum(
            passes / total_students for _, passes, total_students in max_heap
        )
        return total_pass_ratio / len(classes)
```

</details>
