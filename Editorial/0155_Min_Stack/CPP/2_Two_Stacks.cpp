class MinStack {
private:
    stack<int> stack, minStack;  // declaring the two stacks

public:
    MinStack() {}  // constructor

    void push(int x) {
        stack.push(x);  // pushing element to stack
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);  // pushing the minimum element so far to minStack
    }

    void pop() {
        if (stack.top() == minStack.top())
            minStack.pop();  // removing the top element of minStack if it's
                             // equal to the top of stack
        stack.pop();         // removing the top element of stack
    }

    int top() {
        return stack.top();  // returns the top element of stack
    }

    int getMin() {
        return minStack.top();  // returns the top element of minStack i.e.,
                                // minimum element up to now
    }
};
