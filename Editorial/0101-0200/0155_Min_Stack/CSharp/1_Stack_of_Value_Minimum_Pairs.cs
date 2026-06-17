public class MinStack {
    private Stack<int[]> stack = new Stack<int[]>();

    public MinStack() {
    }

    public void Push(int x) {
        // If the Stack is empty then min value is the first value we add
        if (stack.Count == 0) {
            stack.Push(new int[] { x, x });
            return;
        }

        int current_min = stack.Peek()[1];
        stack.Push(new int[] { x, Math.Min(x, current_min) });
    }

    public void Pop() {
        stack.Pop();
    }

    public int Top() {
        return stack.Peek()[0];
    }

    public int GetMin() {
        return stack.Peek()[1];
    }
}
