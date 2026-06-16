# 1603. Design Parking System

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/design-parking-system/)  
`Design` `Simulation` `Counting`

**Problem Link:** [LeetCode 1603 - Design Parking System](https://leetcode.com/problems/design-parking-system/)

## Problem

Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.

Implement the ParkingSystem class:

- ParkingSystem(int big, int medium, int small) Initializes object of the ParkingSystem class. The number of slots for each parking space are given as part of the constructor.
- bool addCar(int carType) Checks whether there is a parking space of carType for the car that wants to get into the parking lot. carType can be of three kinds: big, medium, or small, which are represented by 1, 2, and 3 respectively. A car can only park in a parking space of its carType. If there is no space available, return false, else park the car in that size space and return true.

### Example 1

```text
Input
["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
[[1, 1, 0], [1], [2], [3], [1]]
Output
[null, true, true, false, false]

Explanation
ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);
parkingSystem.addCar(1); // return true because there is 1 available slot for a big car
parkingSystem.addCar(2); // return true because there is 1 available slot for a medium car
parkingSystem.addCar(3); // return false because there is no available slot for a small car
parkingSystem.addCar(1); // return false because there is no available slot for a big car. It is already occupied.
```

## Constraints

- 0 <= big, medium, small <= 1000
- carType is 1, 2, or 3
- At most 1000 calls will be made to addCar

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1603. Design Parking System

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Array for Parking Slots | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Array for Parking Slots

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    // Number of empty slots for each type of car
    int empty[3];
} ParkingSystem;

ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem* obj = (ParkingSystem*) malloc(sizeof(ParkingSystem));
    obj->empty[0] = big;
    obj->empty[1] = medium;
    obj->empty[2] = small;
    return obj;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {

    // If space is available, allocate and return True
    if (obj->empty[carType - 1] > 0) {
        obj->empty[carType - 1]--;
        return true;
    }

    // Else, return False
    return false;
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class ParkingSystem {
public:
    
    // Number of empty slots for each type of car
    vector<int> empty;

    ParkingSystem(int big, int medium, int small) {
        this->empty = vector<int>{big, medium, small};
    }

    bool addCar(int carType) {

        // If space is available, allocate and return True
        if (this->empty[carType - 1] > 0) {
            this->empty[carType - 1]--;
            return true;
        }

        // Else, return False
        return false;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class ParkingSystem {

    // Number of empty slots for each type of car
    int[] empty;

    public ParkingSystem(int big, int medium, int small) {
        this.empty = new int[]{big, medium, small};
    }

    public bool AddCar(int carType) {

        // If space is available, allocate and return True
        if (this.empty[carType - 1] > 0) {
            this.empty[carType - 1]--;
            return true;
        }

        // Else, return False
        return false;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type ParkingSystem struct {
    // Number of empty slots for each type of car
    empty []int
}

func Constructor(big int, medium int, small int) ParkingSystem {
    return ParkingSystem{empty: []int{big, medium, small}}
}

func (this *ParkingSystem) AddCar(carType int) bool {

    // If space is available, allocate and return True
    if this.empty[carType - 1] > 0 {
        this.empty[carType - 1]--
        return true
    }

    // Else, return False
    return false
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class ParkingSystem {

    // Number of empty slots for each type of car
    int[] empty;

    public ParkingSystem(int big, int medium, int small) {
        this.empty = new int[]{big, medium, small};
    }

    public boolean addCar(int carType) {

        // If space is available, allocate and return True
        if (this.empty[carType - 1] > 0) {
            this.empty[carType - 1]--;
            return true;
        }

        // Else, return False
        return false;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var ParkingSystem = function(big, medium, small) {
    // Number of empty slots for each type of car
    this.empty = [big, medium, small];
};

ParkingSystem.prototype.addCar = function(carType) {

    // If space is available, allocate and return True
    if (this.empty[carType - 1] > 0) {
        this.empty[carType - 1]--;
        return true;
    }

    // Else, return False
    return false;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):

        # Number of empty slots for each type of car
        self.empty = [big, medium, small]

    def addCar(self, carType: int) -> bool:

        # If space is available, allocate and return True
        if self.empty[carType - 1] > 0:
            self.empty[carType - 1] -= 1
            return True

        # Else, return False
        return False
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class ParkingSystem {

    // Number of empty slots for each type of car
    empty: number[];

    constructor(big: number, medium: number, small: number) {
        this.empty = [big, medium, small];
    }

    addCar(carType: number): boolean {

        // If space is available, allocate and return True
        if (this.empty[carType - 1] > 0) {
            this.empty[carType - 1]--;
            return true;
        }

        // Else, return False
        return false;
    }
}
```

</details>
