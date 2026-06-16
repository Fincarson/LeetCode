function last(arr) {
    return arr[arr.length - 1];
}

class MinStack {
    _stack = [];

    push(x) {
        // If the stack is empty, then the min value
        // must just be the first value we add
        if (this._stack.length === 0) {
            this._stack.push([x, x]);
            return;
        }

        const currentMin = last(this._stack)[1];
        this._stack.push([x, Math.min(currentMin, x)]);
    }

    pop() {
        this._stack.pop();
    }

    top() {
        return last(this._stack)[0];
    }

    getMin() {
        return last(this._stack)[1];
    }
}
