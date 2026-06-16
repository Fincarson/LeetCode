Array.prototype.forEach = function(callback: Function, context: any): void {
    for (let i = 0; i < this.length; i++) {
        callback.call(context, this[i], i, this);
    }
};
