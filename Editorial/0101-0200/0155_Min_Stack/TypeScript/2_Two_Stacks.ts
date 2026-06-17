class MinStack {
    _stack: number[];
    _minStack: number[];

    constructor() {
        this._stack = [];
        this._minStack = [];
    }

    push(x: number): void {
        this._stack.push(x);
        if (
            this._minStack.length === 0 ||
            x <= this._minStack[this._minStack.length - 1]
        ) {
            this._minStack.push(x);
        }
    }

    pop(): void {
        if (
            this._minStack[this._minStack.length - 1] ===
            this._stack[this._stack.length - 1]
        ) {
            this._minStack.pop();
        }
        this._stack.pop();
    }

    top(): number {
        return this._stack[this._stack.length - 1];
    }

    getMin(): number {
        return this._minStack[this._minStack.length - 1];
    }
}
