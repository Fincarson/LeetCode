function last(arr) {
    return arr[arr.length - 1];
}

class MinStack {
    _stack = [];
    _minStack = [];

    push(x) {
        this._stack.push(x);
        if (this._minStack.length === 0 || x <= last(this._minStack)) {
            this._minStack.push(x);
        }
    }

    pop() {
        if (last(this._minStack) === last(this._stack)) {
            this._minStack.pop();
        }
        this._stack.pop();
    }

    top() {
        return last(this._stack);
    }

    getMin() {
        return last(this._minStack);
    }
}
