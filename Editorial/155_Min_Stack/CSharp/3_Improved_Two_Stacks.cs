public class MinStack {
    private Stack<int> stack = new Stack<int>();
    private Stack<int[]> minStack = new Stack<int[]>();

    public MinStack() {
    }

    public void Push(int x) {
        // We always put the number onto the main stack.
        stack.Push(x);

        // If the min stack is empty, or this number is smaller than
        // the top of the min stack, put it on with a count of 1.
        if (minStack.Count == 0 || x < minStack.Peek()[0]) {
            minStack.Push(new int[] { x, 1 });
        }
        // Else if this number is equal to what's currently at the top
        // of the min stack, then increment the count at the top by 1.
        else if (x == minStack.Peek()[0]) {
            minStack.Peek()[1]++;
        }
    }

    public void Pop() {
        // If the top of min stack is the same as the top of stack
        // then we need to decrement the count at the top by 1.
        if (stack.Peek() == minStack.Peek()[0]) {
            minStack.Peek()[1]--;
        }

        // If the count at the top of min stack is now 0, then remove
        // that value as we're done with it.
        if (minStack.Peek()[1] == 0) {
            minStack.Pop();
        }

        // And like before, pop the top of the main stack.
        stack.Pop();
    }

    public int Top() {
        return stack.Peek();
    }

    public int GetMin() {
        return minStack.Peek()[0];
    }
}
