declare global {
    interface Array<T> {
        last(): T | -1;
    }
}

Array.prototype.last = function(): number { 
    if (this.length === 0) {
        return -1;
    }

    return this[this.length - 1];
}
