# 2069. Walking Robot Simulation II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/walking-robot-simulation-ii/)  
`Design` `Simulation`

**Problem Link:** [LeetCode 2069 - Walking Robot Simulation II](https://leetcode.com/problems/walking-robot-simulation-ii/)

## Problem

A width x height grid is on an XY-plane with the bottom-left cell at (0, 0) and the top-right cell at (width - 1, height - 1). The grid is aligned with the four cardinal directions ("North", "East", "South", and "West"). A robot is initially at cell (0, 0) facing direction "East".

The robot can be instructed to move for a specific number of steps. For each step, it does the following.

After the robot finishes moving the number of steps required, it stops and awaits the next instruction.

Implement the Robot class:

- Robot(int width, int height) Initializes the width x height grid with the robot at (0, 0) facing "East".
- void step(int num) Instructs the robot to move forward num steps.
- int[] getPos() Returns the current cell the robot is at, as an array of length 2, [x, y].
- String getDir() Returns the current direction of the robot, "North", "East", "South", or "West".

### Example 1

```text
Input
["Robot", "step", "step", "getPos", "getDir", "step", "step", "step", "getPos", "getDir"]
[[6, 3], [2], [2], [], [], [2], [1], [4], [], []]
Output
[null, null, null, [4, 0], "East", null, null, null, [1, 2], "West"]

Explanation
Robot robot = new Robot(6, 3); // Initialize the grid and the robot at (0, 0) facing East.
robot.step(2);  // It moves two steps East to (2, 0), and faces East.
robot.step(2);  // It moves two steps East to (4, 0), and faces East.
robot.getPos(); // return [4, 0]
robot.getDir(); // return "East"
robot.step(2);  // It moves one step East to (5, 0), and faces East.
                // Moving the next step East would be out of bounds, so it turns and faces North.
                // Then, it moves one step North to (5, 1), and faces North.
robot.step(1);  // It moves one step North to (5, 2), and faces North (not West).
robot.step(4);  // Moving the next step North would be out of bounds, so it turns and faces West.
                // Then, it moves four steps West to (1, 2), and faces West.
robot.getPos(); // return [1, 2]
robot.getDir(); // return "West"
```

## Constraints

- 2 <= width, height <= 100
- 1 <= num <= 105
- At most 104 calls in total will be made to step, getPos, and getDir.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Walking Robot Simulation](https://leetcode.com/problems/walking-robot-simulation/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2069. Walking Robot Simulation II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Robot {
private:
    bool moved = false;
    int idx = 0;
    vector<pair<int, int>> pos;
    vector<int> dir;
    unordered_map<int, string> to_dir = {
        {0, "East"}, {1, "North"}, {2, "West"}, {3, "South"}};

public:
    Robot(int width, int height) {
        for (int i = 0; i < width; ++i) {
            pos.emplace_back(i, 0);
            dir.emplace_back(0);
        }
        for (int i = 1; i < height; ++i) {
            pos.emplace_back(width - 1, i);
            dir.emplace_back(1);
        }
        for (int i = width - 2; i >= 0; --i) {
            pos.emplace_back(i, height - 1);
            dir.emplace_back(2);
        }
        for (int i = height - 2; i > 0; --i) {
            pos.emplace_back(0, i);
            dir.emplace_back(3);
        }
        dir[0] = 3;
    }

    void step(int num) {
        moved = true;
        idx = (idx + num) % pos.size();
    }

    vector<int> getPos() { return {pos[idx].first, pos[idx].second}; }

    string getDir() {
        if (!moved) {
            return "East";
        }
        return to_dir[dir[idx]];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
using System;
using System.Collections.Generic;

public class Robot {
    private bool moved = false;
    private int idx = 0;
    private List<int[]> pos = new List<int[]>();
    private List<int> dir = new List<int>();
    private Dictionary<int, string> toDir = new Dictionary<int, string>();

    public Robot(int width, int height) {
        toDir[0] = "East";
        toDir[1] = "North";
        toDir[2] = "West";
        toDir[3] = "South";

        for (int i = 0; i < width; ++i) {
            pos.Add(new int[] { i, 0 });
            dir.Add(0);
        }
        for (int i = 1; i < height; ++i) {
            pos.Add(new int[] { width - 1, i });
            dir.Add(1);
        }
        for (int i = width - 2; i >= 0; --i) {
            pos.Add(new int[] { i, height - 1 });
            dir.Add(2);
        }
        for (int i = height - 2; i > 0; --i) {
            pos.Add(new int[] { 0, i });
            dir.Add(3);
        }
        dir[0] = 3;
    }

    public void Step(int num) {
        moved = true;
        idx = (idx + num) % pos.Count;
    }

    public int[] GetPos() {
        return pos[idx];
    }

    public string GetDir() {
        if (!moved) {
            return "East";
        }
        return toDir[dir[idx]];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type Robot struct {
	moved bool
	idx   int
	pos   [][2]int
	dir   []int
	toDir map[int]string
}

func Constructor(width int, height int) Robot {
	robot := Robot{
		toDir: map[int]string{
			0: "East",
			1: "North",
			2: "West",
			3: "South",
		},
	}

	for i := 0; i < width; i++ {
		robot.pos = append(robot.pos, [2]int{i, 0})
		robot.dir = append(robot.dir, 0)
	}
	for i := 1; i < height; i++ {
		robot.pos = append(robot.pos, [2]int{width - 1, i})
		robot.dir = append(robot.dir, 1)
	}
	for i := width - 2; i >= 0; i-- {
		robot.pos = append(robot.pos, [2]int{i, height - 1})
		robot.dir = append(robot.dir, 2)
	}
	for i := height - 2; i > 0; i-- {
		robot.pos = append(robot.pos, [2]int{0, i})
		robot.dir = append(robot.dir, 3)
	}
	robot.dir[0] = 3

	return robot
}

func (this *Robot) Step(num int) {
	this.moved = true
	this.idx = (this.idx + num) % len(this.pos)
}

func (this *Robot) GetPos() []int {
	return []int{this.pos[this.idx][0], this.pos[this.idx][1]}
}

func (this *Robot) GetDir() string {
	if !this.moved {
		return "East"
	}
	return this.toDir[this.dir[this.idx]]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Robot {

    private boolean moved = false;
    private int idx = 0;
    private List<int[]> pos = new ArrayList<>();
    private List<Integer> dir = new ArrayList<>();
    private Map<Integer, String> toDir = new HashMap<>();

    public Robot(int width, int height) {
        toDir.put(0, "East");
        toDir.put(1, "North");
        toDir.put(2, "West");
        toDir.put(3, "South");

        for (int i = 0; i < width; ++i) {
            pos.add(new int[] { i, 0 });
            dir.add(0);
        }
        for (int i = 1; i < height; ++i) {
            pos.add(new int[] { width - 1, i });
            dir.add(1);
        }
        for (int i = width - 2; i >= 0; --i) {
            pos.add(new int[] { i, height - 1 });
            dir.add(2);
        }
        for (int i = height - 2; i > 0; --i) {
            pos.add(new int[] { 0, i });
            dir.add(3);
        }
        dir.set(0, 3);
    }

    public void step(int num) {
        moved = true;
        idx = (idx + num) % pos.size();
    }

    public int[] getPos() {
        return pos.get(idx);
    }

    public String getDir() {
        if (!moved) {
            return "East";
        }
        return toDir.get(dir.get(idx));
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var Robot = function (width, height) {
    this.moved = false;
    this.idx = 0;
    this.pos = [];
    this.dir = [];
    this.toDir = {
        0: "East",
        1: "North",
        2: "West",
        3: "South",
    };

    for (let i = 0; i < width; ++i) {
        this.pos.push([i, 0]);
        this.dir.push(0);
    }
    for (let i = 1; i < height; ++i) {
        this.pos.push([width - 1, i]);
        this.dir.push(1);
    }
    for (let i = width - 2; i >= 0; --i) {
        this.pos.push([i, height - 1]);
        this.dir.push(2);
    }
    for (let i = height - 2; i > 0; --i) {
        this.pos.push([0, i]);
        this.dir.push(3);
    }
    this.dir[0] = 3;
};

Robot.prototype.step = function (num) {
    this.moved = true;
    this.idx = (this.idx + num) % this.pos.length;
};

Robot.prototype.getPos = function () {
    return this.pos[this.idx];
};

Robot.prototype.getDir = function () {
    if (!this.moved) {
        return "East";
    }
    return this.toDir[this.dir[this.idx]];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Robot:

    TO_DIR = {
        0: "East",
        1: "North",
        2: "West",
        3: "South",
    }

    def __init__(self, width: int, height: int):
        self.moved = False
        self.idx = 0
        self.pos = list()
        self.dirs = list()

        pos_, dirs_ = self.pos, self.dirs

        for i in range(width):
            pos_.append((i, 0))
            dirs_.append(0)
        for i in range(1, height):
            pos_.append((width - 1, i))
            dirs_.append(1)
        for i in range(width - 2, -1, -1):
            pos_.append((i, height - 1))
            dirs_.append(2)
        for i in range(height - 2, 0, -1):
            pos_.append((0, i))
            dirs_.append(3)

        dirs_[0] = 3

    def step(self, num: int) -> None:
        self.moved = True
        self.idx = (self.idx + num) % len(self.pos)

    def getPos(self) -> List[int]:
        return list(self.pos[self.idx])

    def getDir(self) -> str:
        if not self.moved:
            return "East"
        return Robot.TO_DIR[self.dirs[self.idx]]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class Robot {
    private moved: boolean = false;
    private idx: number = 0;
    private pos: number[][] = [];
    private dir: number[] = [];
    private toDir: Map<number, string> = new Map();

    constructor(width: number, height: number) {
        this.toDir.set(0, "East");
        this.toDir.set(1, "North");
        this.toDir.set(2, "West");
        this.toDir.set(3, "South");

        for (let i = 0; i < width; ++i) {
            this.pos.push([i, 0]);
            this.dir.push(0);
        }
        for (let i = 1; i < height; ++i) {
            this.pos.push([width - 1, i]);
            this.dir.push(1);
        }
        for (let i = width - 2; i >= 0; --i) {
            this.pos.push([i, height - 1]);
            this.dir.push(2);
        }
        for (let i = height - 2; i > 0; --i) {
            this.pos.push([0, i]);
            this.dir.push(3);
        }
        this.dir[0] = 3;
    }

    step(num: number): void {
        this.moved = true;
        this.idx = (this.idx + num) % this.pos.length;
    }

    getPos(): number[] {
        return this.pos[this.idx];
    }

    getDir(): string {
        if (!this.moved) {
            return "East";
        }
        return this.toDir.get(this.dir[this.idx])!;
    }
}
```

</details>
