const last = (arr: any[]) => arr[arr.length - 1];

class MinStack {
    private _stack: number[];
    private _minStack: Array<[number, number]>;

    constructor() {
        this._stack = [];
        this._minStack = [];
    }

    push(x: number): void {
        // We always put the number onto the main stack.
        this._stack.push(x);

        // If the min stack is empty, or this number is smaller than
        // the top of the min stack, put it on with a count of 1.
        if (!this._minStack.length || x < last(this._minStack)[0]) {
            this._minStack.push([x, 1]);
        }
        // Else if this number is equal to what's currently at the top
        // of the min stack, then increment the count at the top by 1.
        else if (x === last(this._minStack)[0]) {
            last(this._minStack)[1]++;
        }
    }

    pop(): void {
        // If the top of min stack is the same as the top of stack
        // then we need to decrement the count at the top by 1.
        if (last(this._minStack)[0] === last(this._stack)) {
            last(this._minStack)[1]--;
        }
        // If the count at the top of min stack is now 0, then remove
        // that value as we're done with it.
        if (last(this._minStack)[1] === 0) {
            this._minStack.pop();
        }
        // And like before, pop the top of the main stack.
        this._stack.pop();
    }

    top(): number {
        return last(this._stack);
    }

    getMin(): number {
        return last(this._minStack)[0];
    }
}
