Array.prototype.forEach = function(callback, context) {
    //To maintain a reference to the original array when inside the inner function
    const self = this;
    function forEachRecursive(index) {
        if (index === self.length) {
            return;
        }
        callback.call(context, self[index], index, self);
        forEachRecursive(index + 1);
    }

    forEachRecursive(0);
};
