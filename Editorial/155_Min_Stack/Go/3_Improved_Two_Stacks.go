// minCount struct holds the minimum value and its count.
type minCount struct {
    min, count int
}

type MinStack struct {
    stackVal []int      // Main stack to store values
    stackMin []minCount // Stack to store min values with counts
}

// Constructor initializes a new MinStack with empty stacks.
func Constructor() MinStack {
    return MinStack{
        stackMin: make([]minCount, 0),
        stackVal: make([]int, 0),
    }
}

// Push adds a new element onto the stack.
func (this *MinStack) Push(val int)  {
    // If the min stack is empty or the new value is smaller than the current minimum,
    // push it onto the min stack with a count of 1.
    if len(this.stackMin) == 0 || val < this.stackMin[len(this.stackMin)-1].min {
        this.stackMin = append(this.stackMin, minCount{
            count: 1,
            min: val,
        })
    } else if val == this.stackMin[len(this.stackMin)-1].min {
        // If the new value equals the current minimum, increment its count.
        this.stackMin[len(this.stackMin)-1].count++
    }

    // Push the new value onto the main stack.
    this.stackVal = append(this.stackVal, val)
}

// Pop removes the top element from the stack.
func (this *MinStack) Pop()  {
    // If the top of the main stack equals the top of the min stack,
    // decrement the count of the minimum element.
    if this.stackVal[len(this.stackVal)-1] == this.stackMin[len(this.stackMin)-1].min {
        this.stackMin[len(this.stackMin)-1].count--

        // If the count of the minimum element reaches zero, remove it from the min stack.
        if this.stackMin[len(this.stackMin)-1].count == 0 {
            this.stackMin = this.stackMin[:len(this.stackMin)-1]
        }
    }

    // Remove the top element from the main stack.
    this.stackVal = this.stackVal[:len(this.stackVal)-1]
}

// Top returns the top element of the stack.
func (this *MinStack) Top() int {
    return this.stackVal[len(this.stackVal)-1]
}

// GetMin returns the minimum element from the min stack.
func (this *MinStack) GetMin() int {
    return this.stackMin[len(this.stackMin)-1].min
}
