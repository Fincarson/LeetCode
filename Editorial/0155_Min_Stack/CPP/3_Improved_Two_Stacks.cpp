class MinStack {
private:
    std::stack<int> stack;
    std::stack<std::pair<int, int>> minStack;

public:
    MinStack() {}

    void push(int x) {
        // We always put the number onto the main stack.
        stack.push(x);

        // If the min stack is empty, or this number is smaller than
        // the top of the min stack, put it on with a count of 1.
        if (minStack.empty() || x < minStack.top().first) {
            minStack.push({x, 1});
        }
        // Else if this number is equal to what's currently at the top
        // of the min stack, then increment the count at the top by 1.
        else if (x == minStack.top().first) {
            minStack.top().second++;
        }
    }

    void pop() {
        // If the top of min stack is the same as the top of stack
        // then we need to decrement the count at the top by 1.
        if (stack.top() == minStack.top().first) {
            minStack.top().second--;
        }

        // If the count at the top of min stack is now 0, then remove
        // that value as we're done with it.
        if (minStack.top().second == 0) {
            minStack.pop();
        }

        // And like before, pop the top of the main stack.
        stack.pop();
    }

    int top() { return stack.top(); }

    int getMin() { return minStack.top().first; }
};
