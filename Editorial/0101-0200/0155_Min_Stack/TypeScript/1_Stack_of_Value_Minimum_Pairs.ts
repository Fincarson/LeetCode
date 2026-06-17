class MinStack {
    private _stack: [number, number][] = [];

    push(x: number): void {
        // If the stack is empty, then the min value must just be the first value we add
        if (this._stack.length === 0) {
            this._stack.push([x, x]);
            return;
        }
        const currentMin = this._stack[this._stack.length - 1][1];
        this._stack.push([x, Math.min(x, currentMin)]);
    }

    pop(): void {
        this._stack.pop();
    }

    top(): number {
        return this._stack[this._stack.length - 1][0];
    }

    getMin(): number {
        return this._stack[this._stack.length - 1][1];
    }
}
