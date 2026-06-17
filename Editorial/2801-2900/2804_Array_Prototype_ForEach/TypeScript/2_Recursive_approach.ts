Array.prototype.forEach = function(callback: Function, context: any): void {
    //To maintain a reference to the original array when inside the inner function
    const self = this;
    function forEachRecursive(index: number): void {
        if (index === self.length) {
            return;
        }
        callback.call(context, self[index], index, self);
        forEachRecursive(index + 1);
    }

    forEachRecursive(0);
};
