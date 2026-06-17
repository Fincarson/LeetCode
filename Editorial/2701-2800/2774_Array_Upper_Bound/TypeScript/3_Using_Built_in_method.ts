declare global {
    interface Array<T> {
        upperBound(target: number): number;
    }
}

Array.prototype.upperBound = function(target: number): number {
    return this.lastIndexOf(target);
};
