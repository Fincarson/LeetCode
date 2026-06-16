type MinStack struct {
    stack [][]int
}

func Constructor() MinStack {
    return MinStack{stack: make([][]int, 0)}
}

func (this *MinStack) Push(val int) {
    /* If the stack is empty, then the min value
     * must just be the first value we add. */
    if len(this.stack) == 0 {
        this.stack = append(this.stack, []int{val, val})
        return
    }

    currentMin := this.stack[len(this.stack)-1][1]
    this.stack = append(this.stack, []int{val, min(val, currentMin)})
}

func (this *MinStack) Pop() {
    this.stack = this.stack[:len(this.stack)-1]
}

func (this *MinStack) Top() int {
    return this.stack[len(this.stack)-1][0]
}

func (this *MinStack) GetMin() int {
    return this.stack[len(this.stack)-1][1]
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
