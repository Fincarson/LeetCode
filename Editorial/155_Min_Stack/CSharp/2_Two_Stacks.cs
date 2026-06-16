public class MinStack {
    Stack<int> stack;
    Stack<int> minStack;

    public MinStack() {
        stack = new Stack<int>();
        minStack = new Stack<int>();
    }

    public void Push(int x) {
        stack.Push(x);
        if (minStack.Count == 0 || x <= minStack.Peek()) minStack.Push(x);
    }

    public void Pop() {
        if (stack.Peek() == minStack.Peek()) minStack.Pop();
        stack.Pop();
    }

    public int Top() {
        return stack.Peek();
    }

    public int GetMin() {
        return minStack.Peek();
    }
}
